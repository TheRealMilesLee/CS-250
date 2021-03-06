# Hengyi Li
# A program that implements two functions, merge and print_array,
# and calls those two functions to show that they operate correctly

  .data
array1:
  .word 1, 3, 4, 5, 8, 9
  .align 6
array2:
  .word 2, 6, 7, 8

  .text
  .globl main

main:
# $t0 is the current index of the array
# $t1 is the size of the array1
# $t2 is the size of the array2
# $s1 is the combination of array_size1 and array_size2
  addiu $sp, $sp, -4        # decrement stack pointer by 4
  sw    $ra, 0($sp)         # copy ra to stack pointer
  move  $t0, $zero          # Initialize the $t0 to 0
  move  $t1, $zero          # Initialize the $t1 to 0
  move  $t2, $zero          # Initialize the $t2 to 0
  move  $s1, $zero          # Initialize the $s1 to 0
# Now on stack we have $ra

# Count the lenth of the array 1
  la    $a0, array1         # load the address of array1 into $a0
array1_count:
  lw    $t0, 0($a0)         # Load first element of array 1 into t0
  beq   $t0, $zero, exit    # if it reaches to the end, exit
  addiu $t1, $t1, 1         # count increment
  addiu $a0, $a0, 4         # Move to next index
  j array1_count            # Jumping back to the top of the loop
exit:
  move  $t0, $zero          # Cleanup the $t0

  la    $a0, array2         # load the address of array2 into $a0
array2_count:
  lw    $t0, 0($a0)         # Load first element of array 2 into t0
  beq   $t0, $zero, finished# if it reaches to the end, exit
  addiu $t2, $t2, 1         # count increment
  addiu $a0, $a0, 4         # Move to next index
  j array2_count
finished:
  move  $t0, $zero          # cleanup the t0
  move  $a0, $zero          # Cleanup the a0

  addu  $s1, $t1, $t2       # Calculate the total size of the array
  addiu $sp, $sp, -4        # Decrement the stack pointer by 4
  sw    $s1, 0($sp)         # Save the total size on the stack
  # Now on stack we have $ra, $s1

  addiu $sp, $sp, -4        # decrement stack pointer by 4
  sw    $t1, 0($sp)         # Save the size of the array1 into stack
  # Now on stack we have $ra, $s1, $t1

  addiu $sp, $sp, -4        # decrement the stack pointer by 4
  sw    $t2, 0($sp)         # Save the size of array2 on the stack
  # Now on stack we have $ra, $s1, $t1, $t2

  # Starting print the array 1
  la    $a0, array1         # Load the address of the array 1 into the $a0
  move  $a1, $t1            # move the size of the array into the $a1
  jal   print_array         # function call print_array
  # Make a new line
  li    $a0, 10             # Load the address of newline into $a0
  li    $v0, 11             # Call the system print the newline character
  syscall

  lw    $t2, 0($sp)         # Load saved $t2 from stack
  addiu $sp, $sp, 4         # increment the stack pointer by 4
  # Now on stack we have $ra, $s1, $t1

  # Starting print the array 2
  la    $a0, array2         # load the address of the array2 into $a0
  move  $a1, $t2            # move the size of the array into the $a1
  jal   print_array         # function call print_array
  # Print finished

  li    $a0, 10             # Load the address of newline into $a0
  li    $v0, 11             # Call the system print the newline character
  syscall

  # Merge Preparation
  lw    $t1, 0($sp)         # Load the saved t1 from stack
  addiu $sp, $sp, 4         # increment the stack pointer by 4
  # Now on stack we have $ra, $s1

  la    $a0, array1         # Copy the address of the array 1 into $a0
  move  $a1, $t1            # copy the size of array 1 into $a1
  la    $a2, array2         # Copy the address of the array 2 into $a2
  move  $a3, $t2            # copy the size of the array 2 into $a3

  # Merge begin
  jal   merge

  # Final print Preparation
  lw    $s1, 0($sp)         # load the total size of the array back to s1
  addiu $sp, $sp, 4         # Increment the stack pointer by 4
  # Now on stack we have $ra

  la    $a0, array1         # Load the address of the array1 into a0
  move  $a1, $zero          # Cleanup the a1
  move  $a1, $s1            # Move the total size to $a1
  jal   print_array
  # Print finished

  # This is the end of the main
  lw    $ra 0($sp)          # restore the saved $ra
  addiu $sp, $sp, 4         # Increment the stack pointer by 4

  # Now the stack is empty
  li    $v0, 0x0a
  syscall
  .end main

#################################################
## This is the beginning of the print function ##
#################################################
print_array:
# $a0 is the address of the array
# $a1 is the size of the array
# $s0 is the current character
# $s1 is the pointer to the array
# $s2 is the array index

  addi  $sp, $sp, -4        # Decrement the stack pointer by 4
  sw    $s0, 0($sp)         # Save $s0 to the stack
  addi  $sp, $sp, -4        # Decrement the stack pointer by 4
  sw    $s1, 0($sp)         # Save $s1 to the stack
  addi  $sp, $sp, -4        # Decrement the stack pointer by 4
  sw    $s2, 0($sp)         # Save $s2 to the stack
  move  $s2, $zero          # Initialized the $s2 to 0
  move  $s1, $zero          # Initialized the $s1 to 0
  move  $s0, $zero          # Initialized the $s0 to 0
  # The stack for this portion now have $s0, $s1, $s2

loop:
  sll   $s1, $s2, 2         # $s2 = $t0 * 4
  addu  $s1, $s1, $a0       # $s2 = &array1[i]
  lw    $s0, 0($s1)         # load the character at current address
  beq   $s0, $zero, done    # If met the end of the array, exit

  # Backup the origional $a0
  addiu $sp, $sp, -4        # decrement the stack pointer by 4
  sw    $a0, 0($sp)         # save the $a0
  # The stack now has $s0, $s1, $s2, $a0

  # Start print the current character
  move  $a0, $s0            # move current character into a0
  li    $v0, 1              # display the current index
  syscall

  # Print finished, restore the origional $a0
  lw    $a0, 0($sp)         # load the saved $a0 from stack
  addiu $sp, $sp, 4         # increment the stack pointer by 4

  # Now on stack we have $s0
  addiu $s2, $s2, 1         # Move to next index
  j     loop                # Jump back to the beginning loop
done:
  lw    $s2, 0($sp)         # Release the saved s2
  addiu $sp, $sp, 4         # Increment the stack pointer by 4
  lw    $s1, 0($sp)         # Release the saved s1
  addiu $sp, $sp, 4         # Increment the stack pointer by 4
  lw    $s0, 0($sp)         # Release the saved s0
  addiu $sp, $sp, 4         # Increment the stack pointer by 4

  # Now the stack is back to what it was before the function call
  jr    $ra

#################################################
## This is the beginning of the merge function ##
#################################################
merge:
# $a0 is the address of array 1
# $a1 is the size of the array 1
# $a2 is the address of the array 2
# $a3 is the size of the array 2
#################################################
# $t0 is the array1 index
# $t1 is the array2 index
# $t2 is the result array index
# $t3 is the total size of the array1 + array2
# $t4 is the current address of the array1
# $t5 is the current address of the array2
# $t6 is the compare temp value for array1
# $t7 is the compare temp value for array2
# $t8 is the result array pointer
#################################################
# $s2 is the pointer to the array 1
# $s3 is the pointer to the array 2
#################################################
  addiu $sp, $sp, -4        # Decrement the stack pointer by 4
  sw    $a0, 0($sp)         # Save the $a0
  addiu $sp, $sp, -4        # Decrement the stack pointer by 4
  sw    $a1, 0($sp)         # Save the $a1
  addiu $sp, $sp, -4        # Decrement the stack pointer by 4
  sw    $a2, 0($sp)         # Save the $a2
  addiu $sp, $sp, -4        # Decrement the stack pointer by 4
  sw    $a3, 0($sp)         # Save the $a3
  addiu $sp, $sp, -4        # Decrement the stack pointer by 4
  sw    $t0, 0($sp)         # Save the $t0
  addiu $sp, $sp, -4        # Decrement the stack pointer by 4
  sw    $t1, 0($sp)         # Save the $t1
  addiu $sp, $sp, -4        # Decrement the stack pointer by 4
  sw    $t2, 0($sp)         # Save the $t2
  addiu $sp, $sp, -4        # Decrement the stack pointer by 4
  sw    $t3, 0($sp)         # Save the $t3
  addiu $sp, $sp, -4        # Decrement the stack pointer by 4
  sw    $t4, 0($sp)         # Save the $t4
  addiu $sp, $sp, -4        # Decrement the stack pointer by 4
  sw    $t5, 0($sp)         # Save the $t5
  addiu $sp, $sp, -4        # Decrement the stack pointer by 4
  sw    $t6, 0($sp)         # Save the $t6
  addiu $sp, $sp, -4        # Decrement the stack pointer by 4
  sw    $t7, 0($sp)         # Save the $t7
  addiu $sp, $sp, -4        # Decrement the stack pointer by 4
  sw    $t8, 0($sp)         # Save the $t8
  addiu $sp, $sp, -4        # Decrement the stack pointer by 4
  sw    $s2, 0($sp)         # Save the $s2
  addiu $sp, $sp, -4        # Decrement the stack pointer by 4
  sw    $s3, 0($sp)         # Save the $s3
  move  $t0, $zero          # Initialize the array1 index to 0
  move  $t1, $zero          # Initialize the array2 index to 0
  move  $t2, $zero          # Initialize the result array index to 0
  addu  $t3, $a1, $a3       # Calculate the array1+array2
  move  $t4, $zero          # Initialize the current address of array1 to 0
  move  $t5, $zero          # Initialize the current address of array2 to 0

begin:
  slt   $t6, $t0, $a1       # a_index < a_length ? 1 : 0
  slt   $t7, $t1, $a3       # b_index < b_length ? 1 : 0
  beq   $t6, $zero, end     # If a_index > a_length, goto exit
  beq   $t7, $zero, end     # If b_index > b_length, goto exit
enter:
  sll   $s2, $t0, 2         # $s2 = $t0 * 4
  addu  $s2, $s2, $a0       # $s2 = &array1[i]
  lw    $t4, 0($s2)         # Load array1 current index from current address
  sll   $s3, $t1, 2         # $s3 = $t1 * 4
  addu  $s3, $s3, $a2       # $s3 = &array2[i]
  lw    $t5, 0($s3)         # Load array2 current index from current address
  slt   $t6, $t4, $t5       # array1[index] < array2[index] ? 1 : 0
  beq   $t6, $zero, else    # If array1 is not less than array2, goto else
  # If array1 is less than array2, do the following

  move  $t8, $t4            # Save the current value of array1 to $t8
  addiu $sp, $sp, -4        # Decrement the stack pointer
  sw    $t8, 0($sp)         # Save the value on the stack
  addiu $t0, $t0, 1         # array1 index++
  addiu $t2, $t2, 1         # r_index++
  j     begin               # jump to the top of the loop
else:
  # If array1 is bigger than or equal to array2, do the following

  move  $t8, $t5            # Save the current value of array2 to $t8
  addiu $sp, $sp, -4        # Decrement the stack pointer
  sw    $t8, 0($sp)         # Save the value on the stack
  addiu $t1, $t1, 1         # array2 index++
  addiu $t2, $t2, 1         # r_index++
  j     begin               # jump to the top of the loop
end:

a_index_less_length:
  slt   $t6, $t0, $a1       # array1 index < array1 length ? 1 : 0
  beq   $t6, $zero, a_done  # If index is not less than length, exit
  sll   $s2, $t0, 2         # $s2 = $t0 * 4
  addu  $s2, $s2, $a0       # $s2 = &array1[i]
  lw    $t4, 0($s2)         # Load the current index from the current address
  addiu $sp, $sp, -4        # Decrement the stack pointer
  sw    $t4, 0($sp)         # Save it on the stack
  addiu $t0, $t0, 1         # array1 index++
  addiu $t2, $t2, 1         # r_index++
  j     a_index_less_length
a_done:
move    $s2, $zero          # Cleanup pointer to array1

b_index_less_length:
  slt   $t7, $t1, $a3       # array2 index < array2 length ? 1 : 0
  beq   $t7, $zero, b_done  # If it's greater than, goto terminated
  sll   $s3, $t1, 2         # $s3 = $t0 * 4
  addu  $s3, $s3, $a2       # $s3 = &array2[i]
  lw    $t5, 0($s2)         # Load the current index from the current address
  addiu $sp, $sp, -4        # Decrement the stack pointer
  sw    $t5, 0($sp)         # Save it on the stack
  addiu $t1, $t1, 1         # array2 index++
  addiu $t2, $t2, 1         # r_index++
  j     b_index_less_length
b_done:
  move  $t0, $t2 # Copy the length of the array1+array2 to $t0
  subu  $t0, $t0, 1 # Index = length - 1
  move  $t2, $zero   # reset the r_index to 0

cover_it_back:
  # Start from end of the array, and decrement till the beginning
  slt   $t6, $t2, $t3       # r_index < a_length + b_length ? 1 : 0
  beq   $t6, $zero, covered # If r_index is bigger than total, goto covered
  # Cover begin
  sll   $s2, $t0, 2         # $s2 = $t0 * 4
  addu  $s2, $s2, $a0       # $s2 = &array1[i]
  move  $s4, $s2
  lw    $t8, 0($sp)         # load the saved character into $t8
  addiu $sp, $sp, 4         # increment the stack pointer
  sw    $t8, 0($s2)         # Save it back to the memory
  subu  $t0, $t0, 1         # array1 index--
  addiu $t2, $t2, 1         # result index++
  j     cover_it_back
covered:

move    $a1, $t3            # Move $t3 to $a1
# Now Save the $ra before the print function call
addiu   $sp, $sp, -4        # Decrement the stack pointer by 4
sw      $ra, 0($sp)         # Save the $ra on the stack

# Function call here to print the current array
jal     print_array

# Print a newline
li      $a0, 10             # Load the address of newline into $a0
li      $v0, 11             # Call the system print the newline character
syscall

# Print finished, load the saved ra back
lw      $ra, 0($sp)         # Load the saved a0 to a0
addiu   $sp, $sp, 4         # Increment the stack pointer by 4

# Relase the stack
lw      $s3, 0($sp)         # Load the saved s3 to a0
addiu   $sp, $sp, 4         # Increment the stack pointer by 4
lw      $s2, 0($sp)         # Load the saved s2 to a0
addiu   $sp, $sp, 4         # Increment the stack pointer by 4
lw      $t8, 0($sp)         # Load the saved t8 to a0
addiu   $sp, $sp, 4         # Increment the stack pointer by 4
lw      $t7, 0($sp)         # Load the saved t7 to a0
addiu   $sp, $sp, 4         # Increment the stack pointer by 4
lw      $t6, 0($sp)         # Load the saved t6 to a0
addiu   $sp, $sp, 4         # Increment the stack pointer by 4
lw      $t5, 0($sp)         # Load the saved t5 to a0
addiu   $sp, $sp, 4         # Increment the stack pointer by 4
lw      $t4, 0($sp)         # Load the saved t4 to a0
addiu   $sp, $sp, 4         # Increment the stack pointer by 4
lw      $t3, 0($sp)         # Load the saved t3 to a0
addiu   $sp, $sp, 4         # Increment the stack pointer by 4
lw      $t2, 0($sp)         # Load the saved t2 to a0
addiu   $sp, $sp, 4         # Increment the stack pointer by 4
lw      $t1, 0($sp)         # Load the saved t1 to a0
addiu   $sp, $sp, 4         # Increment the stack pointer by 4
lw      $t0, 0($sp)         # Load the saved t0 to a0
addiu   $sp, $sp, 4         # Increment the stack pointer by 4
lw      $a3, 0($sp)         # Load the saved a3 to a0
addiu   $sp, $sp, 4         # Increment the stack pointer by 4
lw      $a2, 0($sp)         # Load the saved a2 to a0
addiu   $sp, $sp, 4         # Increment the stack pointer by 4
lw      $a1, 0($sp)         # Load the saved a1 to a0
addiu   $sp, $sp, 4         # Increment the stack pointer by 4
lw      $a0, 0($sp)         # Load the saved a0 to a0
addiu   $sp, $sp, 4         # Increment the stack pointer by 4
# Finished operation, return
jr      $ra
