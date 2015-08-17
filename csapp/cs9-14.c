#include "csapp.h"


int main(int argc, char **argv)
{
    int fd;
    struct stat sb;
    char *mapped;

	if (argc != 2) {
		printf("Usage: %s file_name\n", argv[0]);
		return 0;
	}
    /* 打开文件 */
    fd = Open(argv[1], O_RDWR, 0); 

    /* 获取文件的属性 */
    if ((fstat(fd, &sb)) == -1) {
        perror("fstat");
    }

    /* 将文件映射至进程的地址空间 */
    if ((mapped = (char *)mmap(NULL, sb.st_size, PROT_READ | 
                    PROT_WRITE, MAP_SHARED, fd, 0)) == (void *)-1) {
        perror("mmap");
    }

    /* 映射完后, 关闭文件也可以操纵内存 */
    close(fd);

    printf("%s", mapped);

    /* 修改一个字符,同步到磁盘文件 */
    mapped[0] = 'J';

    /* 释放存储映射区 */
    if ((munmap((void *)mapped, sb.st_size)) == -1) {
        perror("munmap");
    }

    return 0;
}

