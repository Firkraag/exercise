#!/bin/bash

echo "The name of the script being executed is $0"
echo "The first, third argument given to the script is $1 and $3"
echo "The total number of arguments passwd to the script is $#"
shift 3
echo $1 $#
