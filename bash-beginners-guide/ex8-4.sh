#!/bin/bash

if [ $# -ne 1 ]; then
	echo "Usage: $0 username"
	exit 1
fi

# Check /etc/passwd and decide on the first free user ID
ID=$(cut -d":" -f3 /etc/passwd | sort -n)
previous=0


for i in $ID; do
	if (($previous >= 999)) && (($i - $previous > 1)); then
		break
	fi
	
	previous=$i
done

echo "the first free user ID is $[$previous + 1]"

echo "Now gather information of the new user"
echo -n "add a comment describing this user: "
read comment

echo "Available shell:"
cat << ALL
/bin/bash
/bin/sh
ALL

echo -n "Select a shell from the list:"
read shell

echo -n "Enter the expiration date for this account. The date is specified inthe format YYYY-MM-DD:"
read expiration
echo  "Enter extra groups of which new user should be a member. Each group is seperated from the next by a comma, with no intervening whitespace."
read group

useradd -m -u $[$previous+1] -c "$comment" -d /tmp/$1 -s $shell -e $expiration -G $group $1
echo "The password for this user is 123456. Please change it yourself later."

passwd $1 << DONE
123456
123456
DONE
