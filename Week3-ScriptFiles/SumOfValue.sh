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

#Check if column does not exit
for ColumnCheck in $(cut -c $2 $1);
do
  if [[ -n "$ColumnCheck" ]]
  then
    echo "The column you looking for is not exist"
    exit 1
  fi
done

# cut the column we needed and add the cut numbers by using loop
for number in $(cut -c $2 $1);
do
# Handling when column does not contain a value
  if [[ !"$number" ]]
  then
    echo "The colum is empty"
    exit 1
  fi
    # Add numbers  and store it in the sum variable
    sum=$(($sum + $number));
done;
# output the sum of the values in that column and print it to standard output
echo "Total is: $sum"
# Exit the program
exit 0
