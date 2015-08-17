#include <stdio.h>

int array1[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int array2[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int *daytab[2] = {array1, array2};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)	{
	int i, leap;

	leap = (year%4 == 0 && year%100 != 0 || year%400 == 0);
	if (day > *(*(daytab + leap) + month))
//	if (day > daytab[leap][month])
	{
		printf("Out of bounds\n");
		return -1;
	}
	for (i = 1; i < month; i++)
		day += *(*(daytab + leap) + i);
//		day += daytab[leap][i];
	return day;
}
void month_day(int year, int yearday, int *pmonth, int *pday) {
	int i, leap;
	int c;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	if ((leap == 1 && yearday > 366) || (leap == 0 && yearday > 365)) {
		*pmonth = -1;
		*pday = -1;
		return;
	}
	for (i = 1; yearday > (c = *(*(daytab + leap) + i)); i++)
	//for (i = 1; yearday > daytab[leap][i]; i++)
		yearday = yearday - c;
		//yearday = yearday - daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}
main() {
	int pmonth, pday;

	month_day(2014, 191, &pmonth, &pday);
	printf("%d, %d, %d\n", day_of_year(2014, 7, 24), pmonth, pday);
}
