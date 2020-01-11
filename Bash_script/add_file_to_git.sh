#!/bin/bash
file=$#
i=1
until test $i -le $file
do
	git add $i
done
