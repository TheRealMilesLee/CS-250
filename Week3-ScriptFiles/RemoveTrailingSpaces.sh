#! /bin/bash
# Hengyi Li
# Program to remove the trailing spaces in the file.
# This script is to be called with one filename argument.
# If there is no argument, exit with error status.
# If the argument does not exist, exit with error status.

# Check if we have arguments
if [[ $# -ne 1 ]]
then
    echo "Useage: $0 filename"
    exit 1
fi

# Check if file is empty
if [[ ! -s $1 ]]
then
    echo "The files $1 is empty"
    exit 2
fi

# Check file is exist or not
if [[ ! -e $1 ]]
then
    echo "File does not exist at all"
    exit 2
fi


# Read the file from disk.
getFileFromDisk="cat $1"
# Save the original content to a file with the original name with .orig
$getFileFromDisk>$1.orig
# Read the file line by line and ignore the trailing spaces using read
# command


cat "$1.orig" | while read line # read each line, preserving spaces
do
  while echo "$line" | grep -q " $"  # loop if there is trailing space
  do
    $line >> $1.txt
  done
done
# cover the origional file with new file.
exit 0
