#!/bin/bash
reponame=$1
if test $# -lt 2
then
	echo "script "$0" prototype"
	echo "bash make_repo.sh <repository_name> <user_name>"
	echo "Enter repository and user name"
	exit 1
fi
mkdir ./$reponame
cd $reponame
user=$2
echo "Enter Readme " > README.md
git init
git add README.md
git commit -m "Starting new repository"
git remote add origin  https://github.com/$user/$reponame.git
git push -u origin master
