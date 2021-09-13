#! /bin/bash

# Hengyi Li
# Program to print the duplicates file.
# This script is to be called with one file path argument.
# If there is no argument, exit with error status.
# If the argument does not exist, the working directory is
# the current working directory

# Check the working directory, if it's none, the working directory is the
# current directory
if [ $# -eq 0 ]
then
   directory='.'
else
   directory="$1"
fi

# If the file is an empty directory, then output quit the script
file_count=$(ls $directory | wc -w)
if [ $file_count -eq 0 ]
then
   echo "$directory is an empty directory"
   exit 0
fi

# TODO: Write a shell script that accepts a directory pathname as its argument that prints the names of all files that are duplicates within that directory.

for fileIndex in $(ls $1)
do
  for fileNextIndex in $(ls $1)
  do
    md5CheckFileIndx=$(md5sum $fileIndex)
		md5CheckFileNextIndx=$(md5sum $fileNextIndex)
		if [[ $md5CheckFileIndx = $md5CheckFileNextIndx ]]
		then
			echo "Found Duplicate at $fileIndex"
		fi
  done
done