:'
The named file is assumed to be a csv file with fields delimited by tabs.

The purpose of the script is to calculate the sum of the values in that column and print it to
standard output.

You may assume that all the values, if each is a value, will be integers as opposed to floats.

Do not use either sed or awk in your solution.

Your script should do something intelligent if the named file does not exist, if the column does
not exist, or if any line in the column does not contain a value, and should have reasonable exit
codes.

In all cases, consider the column count to start at 0.
'

getFileFromDisk="cat $1"
$getFileFromDisk
columnNumber="$2"
$columnNumber
