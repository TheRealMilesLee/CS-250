#! /bin/bash
#Hengyi Li
# Program to calculate the sum of values cutted in the csv file
# This script is to be called with two filename argument.
# If there is no argument, exit with error status.
# If the argument does not exist, exit with error status.
# Check if file is exists
if [[ ! -e $1 ]]
then
    echo "The files $1 does not exist at all!"
    exit 1
fi

#Check if file is empty
if [[ ! -s $1 ]]
then
    echo "The file $1 is empty!"
    exit 2
fi
# Handling when column does not contain a value
	if [[ -z $(cut -f $(($2+1)) $1) ]]
	then
		echo "The colum is empty"
		exit 2
	fi
# Cut the line, pipe it to number, Ad
for number in $(cut -f $(($2+1)) $1)
do
	# Add numbers  and store it in the sum variable
		sum=$(( $sum+$number ))
done
# output the sum of the values in that column and print it to standard output
echo "Total is: $sum"
# Exit the program
exit 0
