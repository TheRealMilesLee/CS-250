: '
# The purpose of the script is to calculate the sum of the values in that column and print it to
# standard output.

Your script should do something intelligent if the column does not exist, or if any line in the column does not contain a value, and should have reasonable exit codes.
'
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

for Check in $(cut -c $2 $1)
do
	  if [[ $( -z $Check) ]]
  	then
    	echo "The colum is empty"
    	exit 2
  	fi
done

sum=0
#Check if column does not exit
# Cut the line, if the line is empty, that means non-exist
# cut the column we needed and add the cut numbers by using loop
for number in $(cut -c $2 $1)
do
# Handling when column does not contain a value
    # Add numbers  and store it in the sum variable
    sum=$(( $sum+$number ))
done
# output the sum of the values in that column and print it to standard output
echo "Total is: $sum"
# Exit the program
exit 0
