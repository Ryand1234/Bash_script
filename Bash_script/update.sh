#!/bin/bash

git fetch upstream

git checkout master

git rebase upstream/master

sudo git push -u origin master
