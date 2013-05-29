#!/bin/bash

# This script gives information about a file.

echo "Please enter a file name, I will show file property if it exists:"

read FILENAME

if [ -f $FILENAME ]; then
	echo "Properties for $FILENAME:"
	echo "Size is $(ls -lh $FILENAME | awk '{print $5}')"
	echo "Type is $(file $FILENAME | cut -d":" -f2 -)"
	echo "Inode number is $(ls -i $FILENAME | cut -d" " -f1 -)"
else
	echo "File does not exist."
fi
