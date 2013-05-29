#!/bin/bash

# This script implements a simple web browser(in text mode), using wget and links -dump to display HTML pages to the user. The user has 4 choices: entera URL, enter b for back, enter f for forward, and q to quit.
index=0
cd /tmp
while true; do
	echo "Enter a URL, enter b for back, enter f for forward and q to quit:"
	read URL

	if [ $URL == q ]; then
		echo "Exiting the web browser"
		break
	elif [ $URL == b ]; then
		index=$[$index-1]
		cp index.html.$index index.html
		links2 -dump index.html
	elif [ $URL == f ]; then
		index=$[$index+1]
		cp index.html.$index index.html
		links2 -dump index.html
	else
		echo
		echo 
		# The URL is saved as index.html and if download succeeds, it is also saved as index.html.$index and output to stdout.
		wget $URL -O index.html > /dev/null 2>&1  &&  index=$[$index+1]; cp index.html index.html.$index; links2 -dump index.html; echo; echo 
	fi
done

rm index.html*
