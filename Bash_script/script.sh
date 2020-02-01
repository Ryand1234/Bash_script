#!/bin/bash
echo "#include<stdio.h>" >> $1.c
if test "$#" -eq 2
then
	echo "void $2()" >> $1.c
	echo "{" >> $1.c
	echo " " >> $1.c
	echo "}" >> $1.c
fi
echo "int main()" >> $1.c
echo "{" >> $1.c
echo "	return 0; " >> $1.c
echo "}" >> $1.c
