#!/bin/bash
read -p "Do you want to know name/download the video name?(N/D) " x
if test $x = "N" -o $x = "n"
then
	youtube-dl -e $1
else
	echo "Your video will start dowloading shortly"
	youtube-dl $1
	echo "Video Downloaded"
fi
