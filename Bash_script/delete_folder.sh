#!/bin/bash
if test $# -ne 3
then
	echo "script $0 prototype"
	echo "delete_folder <folder_name> <message> <branch>"
	exit 1
fi
sudo git rm -r $1
bash ~/github/Bash_script/Bash_script/commit.sh $2 $3
