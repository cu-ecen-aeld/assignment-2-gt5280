#!/bin/bash
#Nelson Rodriguez ECEN5713
writefile_argument=$1 #this is a comment
writestr_argument=$2 

if [ $# -eq 1 ] || [ $# -eq 0 ]
then
	echo "FAILED, missing arguments"
	exit 1
fi

FILE="$writefile_argument"

if [ ! -d "$(dirname $FILE)" ] #check if the path exists using dirname command to strip it for argument $1
then
mkdir -p "$(dirname $FILE)"
fi
	
if [ -f $writefile_argument ]
then	
	echo "$writestr_argument" > $writefile_argument	
else
	touch $writefile_argument | echo "$writestr_argument" > $writefile_argument	
fi

if [ -f $writefile_argument ]
then
	exit 0
else
	echo "FAILED, file could not be created"
	exit 1
fi
