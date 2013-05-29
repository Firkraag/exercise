#!/bin/bash
# This script converts all file names containing upper case characters into file# names containin

LIST="$(ls)"

for name in $LIST; do
	if [[ "$name" != *[[:upper:]]* ]]; then
		continue
	fi
	ORIG="$name"
	NEW=`echo $name | tr 'A-Z' 'a-z'`
	if [ -e "$NEW" ]; then
		continue
	fi
	mv "$ORIG" "$NEW"
	echo "new name for $ORIG is $NEW"
done
