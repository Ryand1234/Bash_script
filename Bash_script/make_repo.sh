#!/bin/bash
reponame=$1
if test $# -lt 2
then
	echo "Enter repository and user name"
	exit 1
	if test $# -lt 1
	then
		echo "Enter Username"
		exit 1
	fi
fi
mkdir ./$reponame
cd $reponame
echo "Enter Readme " > README.md
git add README.md
git commit -m "Starting new repository"
git remote add origin  https://github.com/$2/$1.git
git push -u origin master
