#!/bin/bash

FILE=/tmp/ps

ps aux > $FILE

if grep init $FILE > /dev/null; then
	echo "the init daemon are running on your system."
fi

if grep httpd $FILE > /dev/null; then
	echo "This machine is running a web server."
fi

rm $FILE
