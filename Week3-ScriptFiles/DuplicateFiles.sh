#! /bin/bash

# Hengyi Li
# Program to print the duplicates file.
# This script is to be called with one file path argument.
# If there is no argument, exit with error status.
# If the argument does not exist, the working directory is
# the current working directory
# File creates at Sep.10. Last modified at Sep.15 3:40 PM
# Copyright @Hengyi Li. All rights reserved.


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

#Looping through the files, find the duplicate and output the name of file.
for fileIndex in $(ls $directory)
do
booleanFlag="0"
  for fileNextIndex in $(ls $directory)
  do
      # MD5 value calculate
      fileIndexMD5=$(md5sum "$directory/$fileIndex" | cut -f1 -d" ")
      fileNextIndexMD5=$(md5sum "$directory/$fileNextIndex" | cut -f1 -d" ")
      # Check if the filename is the same
      if [[ "$directory/$fileIndex" != "$directory/$fileNextIndex" ]]
      then
      # If they're equal, that means the file is the same
          if [[ "$fileNextIndexMD5" = "$fileIndexMD5" \
          && $booleanFlag = "0" ]]
        then
          echo "Find the duplicate file, the name of file is $fileIndex"
          booleanFlag="1"
        fi
      fi
  done
done
exit 0
