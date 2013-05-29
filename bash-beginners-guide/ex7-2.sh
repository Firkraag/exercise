#! /bin/bash

# Use a case statement to print the number of days in this month, and give information about leap years if the current month is February.

LC_TIME=en_US.UTF-8
month=$(date +%B)
year=$(date +%Y)

case $(date +%m) in
01 | 03 | 05 | 07 |08|10|12)
	echo "Current month $month has 31 days."
	;;
04 | 06 | 09 | 11)
	echo "Current month $month has 30 days."
	;;
02)
	if (( ($year % 400) == 0 )) || (( ($year % 4 == 0) && ($year % 100 != 0) )); then
		echo "This is a leap year. Current month $month has 29 days."
	else
		echo "This is not a leap year. Current month $month has 28 days."
	fi
	;;
esac


