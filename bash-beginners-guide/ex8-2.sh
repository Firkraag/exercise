#!/bin/bash
# takes one file as an argument. Use a here document that presents the user with a couple of choices for compressing the file.

if [ $# -ne 1 ]; then
	echo "Usage: $0 file"
	exit 1
fi

echo "These are available compress commands:"
cat << HERE
gzip
bzip2
zip
HERE

echo
echo -n "Choose a compress command from above: "
read compress

case $compress in
gzip|bzip2)
	$compress $1
	;;
zip)
	$compress $1.zip  $1
	;;
esac
