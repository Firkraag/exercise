#! /usr/bin/python3

# AUTHOR: WangQiang
# CREATE DATE:   20140527
# LAST UPDATE DATE: 20140527
# EMAIL:  cntqrxj@gmail.com

import os

f = open('/home/windheart/bin/ftp.py')
while True:
	line = f.readline()
	if len(line) == 0:
		break
	print(line)
f.close()
f = open('/home/windheart/bin/ftp.py')
f.read(1)
f.close()
