#! /bin/bash
#This shell scripts is to replaced with one that has all trailing spaces on each line removed.
#Hengyi Li

# Read the file from disk.
getFileFromDisk="cat $1"
# Save the original content to a file with the original name with “.orig”
$getFileFromDisk>$1.orig
# Find the trailing spaces in the file
while read -r line;
do
    echo "$line" >> "$1"
done < "$1"