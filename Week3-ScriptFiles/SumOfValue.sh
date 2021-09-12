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

sum=0
# cut the column we needed and store it into temp files for now

# loop through the temp file and do addition for the number inside
for number in `cut -c$2 $1`;
do
    # Add numbers in the temp.csv and store it in the sum variable
    sum=$(($sum + $number));
done;
# output the sum of the values in that column and print it to standard output
echo "Total is: $sum"
# Remove the temp file since we don't need it anymore


# Exit the program
exit 0
