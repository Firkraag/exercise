#!/bin/bash

LOGFILE="/home/windheart/log/backupscript.log"
DIR="/home/windheart"
TAR="windheart.tar"
BZIP="$TAR.bz2"

localbackup() {
	DESTINATION="/media/backup/"
	
	if mount | grep backup; then
		echo "Starting localbackup for $(date)" >> "$LOGFILE"
		cd $DIR
		tar cf "$TAR" algorithm/ bash-beginners-guide/ bin/ C/ computer\ tech/ data\ structure/ Documents/ functions/ include/ lib/ python/ Scripts/ literature/ Music/ Pictures/ tmp/ Web/
		echo "Compressing $TAR..." >> "$LOGFILE"
		bzip2 "$TAR"
		echo "...done." >> "$LOGFILE"
		echo "Moving to another harddisk, may need root privilege..." >> "$LOGFILE"
		sudo mv "$BZIP" "$DESTINATION"
		echo "...done." >> "$LOGFILE"
	else
		echo "No backup harddisk. Backup is aborted" >> "$LOGFILE"
		exit 1
	fi

}

remotebackup() {
	SERVER="216.194.70.6"
	USER="windheart"	
	echo "Starting remotebackup for $(date)" >> "$LOGFILE"
	cd $DIR
	tar cf "$TAR" algorithm/ bash-beginners-guide/ bin/ C/ data\ structure/ Documents/ functions/ include/ lib/ python/ Scripts/
	echo "Compressing $TAR..." >> "$LOGFILE"
	bzip2 "$TAR"
	echo "...done." >> "$LOGFILE"
	echo "Copying to $SERVER..." >> "$LOGFILE"
	scp "$BZIP" "$USER@$SERVER:"
	rm "$BZIP"
}
localbackup	
