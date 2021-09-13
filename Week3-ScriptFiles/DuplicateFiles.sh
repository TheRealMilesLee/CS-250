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

for file in $("$directory/")
do
   if [ -f "$directory/$file" ]
   then
      md5sum $file
      
   fi
done
exit 0



if(file.md5 = file.next.md5)
{
  print(file.nex)
}
else {
  continue looping
}