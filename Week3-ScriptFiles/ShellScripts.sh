#! /bin/bash
#This shell scripts is to replaced with one that has all trailing spaces on each line removed.
#Hengyi Li

#Read the file from disk.
getFileFromDisk="cat $1"
#Save the original content to a file with the original name with “.orig”
$getFileFromDisk>$1.orig

while read line
do
    echo $line
done < $1 > $1
exit 0
