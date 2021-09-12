#! /bin/bash
#Hengyi Li
#This shell scripts is to replaced with one that has all trailing spaces on each line removed.

if [[ $# -ne 1 ]]
then
    echo "Useage: $0 filename"
    exit 1;
fi

if [[ -d "$1" && -r "$1" ]]
then
    filecount=$(ls "$1" | wc -l)
    echo "The number of files in $1 is $filecount"
    exit 0
fi

# Read the file from disk.
getFileFromDisk="cat $1"
# Save the original content to a file with the original name with “.orig”
$getFileFromDisk>$1.orig
# Read the file line by line and ignore the trailing spaces using read command
while read lines;
do
# Go through all the lines in the file.
    echo $lines
# Redirect the input from user arguments and Redirect the read result into new files
done < "$1" > "$1.txt"
# cover the origional file with new file.
rm $1
mv $1.txt $1

exit 0