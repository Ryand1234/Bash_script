#!/bin/bash
i=1
for i in $*;
do
	sudo git add $i
done
