#!/bin/bash

if [ $# -ne 0 ]; then
	echo "Usage: $0"
	exit 1
fi

file=/home/$USER
destination=/media/backup

# the size of file to be backuped is $require, the size of free space is $free. If $free is great than $require, there is no enough free space to hold thebackup.

require=$(du -s $file | awk '{print $1}')
free=$(df $destination | awk 'NR==2 {print $4}')

if [ $require -ge $free ]; then
	echo "No enough free space to hold the backup."
	exit 1
fi

echo "Start the backup. It may take a while. Please be patient."
tar cvp $file.tar $file
echo "Done backup."

echo "The size of the compressed backup is $(du -h $file.tar | awk '{print $1}')"
