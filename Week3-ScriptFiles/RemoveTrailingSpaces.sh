#! /bin/bash

# Hengyi Li
# Program to remove the trailing spaces in the file.
# This script is to be called with one filename argument.
# If there is no argument, exit with error status.
# If the argument does not exist, exit with error status.
# File creates at Sep.10. Last modified at Sep.15 8:01 PM
# Copyright @Hengyi Li. All rights reserved.


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

IFS=''
while read lines
do
  : '
  ${} is group a variable
  %  is the pattern matches a trailing portion of the
  expanded value of parameter
  [![:space:]] Matches any character that is not whitespace
  ##* is delete the last string and the string on its left
  '
   echo ${lines%"${lines##*[![:space:]]}"}
# Use redirection as input and redirect the output to the temp
done < "$1" > "$1.txt"
# cover the origional file with new file.
rm $1
mv $1.txt $1
exit 0
