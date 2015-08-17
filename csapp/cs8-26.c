/* $begin shellmain */
#include "csapp.h"
#define MAXARGS   128

pid_t foreground_pgid;
sigjmp_buf buf;

/* function prototypes */
void eval(char *cmdline);
int parseline(char *buf, char **argv);
int builtin_command(char **argv); 
void handler(int sig);
void foreground_handler(int sig);
void foreground_processing(pid_t);
void initjobs(void);
void addjob(pid_t);
void create_foreground_job(pid_t);
void fore2back(void);
pid_t deletejob(int, int);
pid_t jid2pid(int);
void listjobs(void);
void check_overflow(void);

int main() 
{
    char cmdline[MAXLINE]; /* Command line */


	if (signal(SIGCHLD, handler) == SIG_ERR)
		unix_error("signal error");
	if (signal(SIGINT, foreground_handler) == SIG_ERR)
		unix_error("signal error");
	if (signal(SIGTSTP, foreground_handler) == SIG_ERR)
		unix_error("signal error");
	
	initjobs();

    while (1) {
	/* Read */
	printf("> ");                   
	Fgets(cmdline, MAXLINE, stdin); 
	if (feof(stdin))
	    exit(0);

	/* Evaluate */
	eval(cmdline);
    } 
}
/* $end shellmain */
  
/* $begin eval */
/* eval - Evaluate a command line */
void eval(char *cmdline) 
{
    char *argv[MAXARGS]; /* Argument list execve() */
    char buf[MAXLINE];   /* Holds modified command line */
    int bg;              /* Should the job run in bg or fg? */
    pid_t pid;           /* Process id */
    
    strcpy(buf, cmdline);
    bg = parseline(buf, argv); 
//	printf("argv[0] is %s\n", argv[0]);
//	printf("argv[1] is %s\n", argv[1]);
    if (argv[0] == NULL)  
	return;   /* Ignore empty lines */

    if (!builtin_command(argv)) { 
		sigset_t mask;
		Sigemptyset(&mask);
		Sigaddset(&mask, SIGCHLD);
		Sigprocmask(SIG_BLOCK, &mask, NULL);

		if ((pid = Fork()) == 0) {   /* Child runs user job */
			/* Set the process group ID for the job to the PID of the child */
			setpgid(0, 0);
			if (execve(argv[0], argv, environ) < 0) {
				printf("%s: Command not found.\n", argv[0]);
				exit(0);
			}
		}
		if (bg)
			addjob(pid);
		else {
			foreground_pgid = pid;
			create_foreground_job(pid);
		}
		Sigprocmask(SIG_UNBLOCK, &mask, NULL);
	/* Parent waits for foreground job to terminate */
		if (!bg) {
			foreground_processing(pid);
		}
		else
			printf("%d %s", pid, cmdline);
    }
    return;
}

/* If first arg is a builtin command, run it and return true */
int builtin_command(char **argv) 
{
	printf("%s\n", argv[0]);
    if (!strcmp(argv[0], "quit")) /* quit command */
		exit(0);  
    if (!strcmp(argv[0], "jobs")) /* jobs command */
	{
		printf("jobs builtin\n");
		listjobs();
		return 1;
	}
    if (!strcmp(argv[0], "bg")) /* bg command */
	{
		pid_t pid;
		if (argv[1][0] == '%')
		{
			pid = jid2pid(atoi(++(argv[1])));
		}
		else
			pid = atoi(argv[1]);
		if (pid > 0)
			Kill(pid, SIGCONT);
		return 1;
	}
    if (!strcmp(argv[0], "fg")) /* fg command */
	{
		int option = (argv[1][0] == '%');
		/* If option == 1, use jid to delete job; otherwise, use pid */
		pid_t pid = deletejob(option ? atoi(++(argv[1])) : atoi(argv[1]), option);
		if (pid > 0)
		{
			create_foreground_job(pid);
			Kill(pid, SIGCONT);
			foreground_processing(pid);
		}
		return 1;
	}


	if (!strcmp(argv[0], "pwd"))
	{
		printf("%s\n", getenv("PWD"));
		return 1;
	}
    if (!strcmp(argv[0], "&")) {   /* Ignore singleton & */
	//	printf("&\n");
		return 1;
	}
	//printf("%s is not a builtin command\n", argv[0]);
    return 0;                     /* Not a builtin command */
}
/* $end eval */

/* $begin parseline */
/* parseline - Parse the command line and build the argv array */
int parseline(char *buf, char **argv) 
{
    char *delim;         /* Points to first space delimiter */
    int argc;            /* Number of args */
    int bg;              /* Background job? */

    buf[strlen(buf)-1] = ' ';  /* Replace trailing '\n' with space */
    while (*buf && (*buf == ' ')) /* Ignore leading spaces */
	buf++;

    /* Build the argv list */
    argc = 0;
    while ((delim = strchr(buf, ' '))) {
	argv[argc++] = buf;
	*delim = '\0';
	buf = delim + 1;
	while (*buf && (*buf == ' ')) /* Ignore spaces */
	       buf++;
    }
    argv[argc] = NULL;
    
    if (argc == 0)  /* Ignore blank line */
	return 1;

    /* Should the job run in the background? */
    if ((bg = (*argv[argc-1] == '&')) != 0)
	argv[--argc] = NULL;

    return bg;
}
/* $end parseline */

void handler(int sig)
{
	pid_t pid;

	printf("Now in handler\n");
	while ((pid = waitpid(-1, NULL, WNOHANG)) > 0) {
		printf("Handler reaped child %d\n", (int) pid);
		deletejob(pid, 0);
	}
	if (pid == -1)
		if (errno != ECHILD)
			unix_error("waitpid error");
	return;
}

void foreground_handler(int sig)
{
	kill(-1 * foreground_pgid, sig);
	if (sig == SIGTSTP)
	{
		fore2back();
		siglongjmp(buf, 1);
	}
	return;
}
void foreground_processing(pid_t pid) {
		int status;
		foreground_pgid = pid;
		if (!sigsetjmp(buf, 1))
			if (waitpid(pid, &status, 0) < 0)
				unix_error("waitfg: waitpid error");
		printf("Now awake\n");
}


// The size of the array of background jobs
int array_size;
typedef struct {
	pid_t pid;
	int jid;
	/* If exist = 1, the job exists; otherwise, the job does not exist */
	int exist;
} Job;
Job *array;
Job foreground_job;
int jid_cnt;
// The number of all background jobs, including terminated background jobs
int jobs_num;
void initjobs() {
	int i;
	
	jobs_num = 0;
	jid_cnt = 1;
	array_size = 100;
	array = (Job *) malloc(array_size * sizeof(Job));
	for (i = 0; i < array_size; i++)
		array[i].exist = 0;
}

void addjob(pid_t pid) {
	int job_pos = jobs_num++;
	array[job_pos].pid = pid;
	array[job_pos].jid = jid_cnt++;
	array[job_pos].exist = 1;

	check_overflow();
}
void create_foreground_job(pid_t pid) {
	foreground_job.jid = jid_cnt++;
	foreground_job.pid = pid;
	foreground_job.exist = 1;

}

pid_t deletejob(int id, int option)
{
	int i;

	if (id <= 0)
		return -1;
	if (option == 1)
		for (i = 0; i < jobs_num; i++)
		{
			if ((array[i].exist ==  1) && (array[i].jid == id))
			{
				array[i].exist = 0;
				return array[i].pid;
			}
		}
	else
		for (i = 0; i < jobs_num; i++)
		{
			if ((array[i].exist ==  1) && (array[i].pid == id))
			{
				array[i].exist = 0;
				return id;
			}
		}
	return -1;
}

void fore2back(void) {
	int job_pos = jobs_num++;
	array[job_pos].pid = foreground_job.pid;
	array[job_pos].jid = foreground_job.jid;
	array[job_pos].exist = 1;

	check_overflow();
}

pid_t jid2pid(int jid) {
	int i;

	if (jid <= 0)
		return -1;
	for (i = 0; i < jobs_num; i++)
	{
		if ((array[i].exist ==  1) && (array[i].jid == jid))
		{
			return array[i].pid;
		}
	}
	return -1;
}	

void listjobs(void) {
	int i;

	for (i = 0; i < jobs_num; i++)
	{
		if (array[i].exist == 1)
		{
			printf("[%d]  %d\n", array[i].jid, array[i].pid);
		}
	}
}
void check_overflow(void)
{
	if (jobs_num > array_size)
	{
		int i;
		array_size *= 2;
		Job *tmp =  (Job *) malloc(array_size * sizeof(Job));
		for (i = 0; i < array_size; i++)
			tmp[i].exist = 0;
		for (jobs_num = 0, i = 0; i < array_size / 2; i++)
		{
			if (array[i].exist == 1)
			{
				tmp[i].pid = array[i].pid;
				tmp[i].jid = array[i].jid;
				tmp[i].exist = 1;
				jobs_num++;
			}
		}
		free(array);
		array = tmp;
	}
}
