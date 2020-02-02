#!/bin/bash
if test $# -ne 2
then
	echo "script $0 prototype"
	echo "bash commit.sh <message> <branch>"
	exit 1
fi
sudo git commit -m "$1"
sudo git push origin "$2"
