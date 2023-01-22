#!/bin/bash
filesdir=$1
searchstr=$2

if [ $# -eq 1 ] || [ $# -eq 0 ]
then
	echo "FAILED, missing arguments"
	exit 1
elif [ -d $filesdir ]
then	

	filescount=$(ls $filesdir | wc -l)
	linematch=$(grep -rw "$searchstr" $filesdir | wc -l)

	echo "The number of files are $filescount and the number of matching lines are $linematch"
else
	echo "FAILED, argument is not a directory"	
fi