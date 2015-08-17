#include <stdio.h>
#include <ctype.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day & year, if day or month exceed the range, the function returns -1 */
int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	if (month <=0 || month > 12 || day <= 0 || day > daytab[leap][month] )
		return -1;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}
/* month_day converts the day of the year into the month and day. Assign the month to *pmonth, and day to *pday. */
void month_day(int year, int yearday, int *pmonth, int *pday) {
	int i, leap;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	if ((leap == 1 && yearday > 366) || (leap == 0 && yearday > 365)) {
		*pmonth = -1;
		*pday = -1;
		return;
	}
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday = yearday - daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}
main(int argc, char *argv[]) {
	int pmonth, pday;

	month_day(2012, 367, &pmonth, &pday);
	printf("%d, %d, %d\n", day_of_year(atoi(argv[1]), atoi(argv[2]), atoi(argv[3])), pmonth, pday);
}
