#!/bin/bash

echo -n "What's your age, $USER:"
read age

if [ $age -ge 16 ]; then
	echo "You are allowed to drink alcohol."
else 
	echo "You have to wait $[16 - $age] years before legally allowed to drink" 
fi
