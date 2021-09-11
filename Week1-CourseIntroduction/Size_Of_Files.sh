#! /bin/bash

# report the size of all regular files in the argument directory
# Hengyi Li

# If the argument passed to the bash script is equal to 0, then the directory is the script file directory
if [ $# -eq 0 ]
then
   directory='.'
elif [ $# -ne 1 ] || [ ! -d "$1" ] #If the argument passed to bash script is more than one, break the program
then
   echo "Useage: $0 [directory name]"
   exit 1
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

sum=0
#ls -1 "$directory" |
for file in $(ls -1 "$directory/") # note: -1 is a digit one
do

   if [ -f "$directory/$file" ]
   then
      set -- $(ls -l "$directory/$file") # note: -l is lowercase letter L
      sum=$(($sum + $5)) # the file size is the fifth column
   fi

   if [ "$file_count" -gt 1 ]
   then
      let file_count--
   else
      if [ "$directory" = "." ]
      then directory="current working directory"
      fi
      echo "Sum of sizes of ordinary files in $directory is $sum bytes."
   fi
done
exit 0