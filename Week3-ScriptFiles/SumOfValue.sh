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
    exit 1
fi

# TODO: Stuck in the the detecting column is empty or not.

cutLines=`cut -c $2 $1`
if [[ -z $cutLines]]
then
    echo "Column is empty"
    exit 1
fi

# Handling when column does not contain a value
sum=0
# cut the column we needed and add the cut numbers by using loop
for number in $cutLines;
do
    # Add numbers  and store it in the sum variable
    sum=$(($sum + $number));
done;
# output the sum of the values in that column and print it to standard output
echo "Total is: $sum"
# Exit the program
exit 0
