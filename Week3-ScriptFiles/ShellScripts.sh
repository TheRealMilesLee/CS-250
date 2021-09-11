#! /bin/bash

#This shell scripts is to replaced with one that has all trailing spaces on
#each line removed.
#Hengyi Li


# If the file is an empty directory, then output quit the script
file_count=$(ls $directory | wc -w)
if [ $file_count -eq 0 ]
then
   echo "$directory is an empty directory"
   exit 0
fi


getFileFromDisk="cat $1"
$getFileFromDisk>$1.orig
