#! /bin/bash

#This shell scripts is to replaced with one that has all trailing spaces on each line removed.
#Hengyi Li

# If the file is an empty directory, then output quit the script
file_count=$(ls $directory | wc -w)
if [ $file_count -eq 0 ]
then
   echo "$directory is an empty directory"
   exit 0
fi

#Read the file from disk.
getFileFromDisk="cat $1"
#Save the original content to a file with the original name with “.orig”
$getFileFromDisk>$1.orig

#Read the file line by line
while read line;
do
  echo $line
#read each line and redirect it to the output
done <$1>$1

exit 0