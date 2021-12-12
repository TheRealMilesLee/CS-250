# Hengyi Li
# A program that implements two functions, merge and print_array,
# and calls those two functions to show that they operate correctly

  .data
array1:
  .word 1, 3, 4, 5, 8, 9
space_between_array:
  .space 1
array2:
  .word 2, 6, 7, 8

  .text
  .globl main

main:
# $t0 is the index of the array
# $t1 is the size of the array1
# $t2 is the size of the array2

  addiu $sp, $sp, -4        # decrement stack pointer by 4
  sw    $ra, 0($sp)         # copy ra to stack pointer

  move $t1, $zero       # Initialize the $t1 to 0
  move $t2, $zero       # Initialize the $t2 to 0

  la $a0, array1           # load the address of array1 into $a0
while:
  lw $t0, 0($a0)          # Load first element of array 1 into t0
  beq $t0, $zero, exit   # if it reaches to the end, exit
  addiu $t1, $t1, 1         # count increment
  addiu $a0, $a0, 4      # Move to next index
  j while
exit:
  addiu $sp, $sp, -4   # decrement stack pointer by 4
  sw $t1, 0($sp)          # Save the size of the array into stack
  move $t0, $zero       # Cleanup the $t0

  la $a0, array2           # load the address of array1 into $a0
array2_while:
  lw $t0, 0($a0)          # Load first element of array 2 into t0
  beq $t0, $zero, finished   # if it reaches to the end, exit
  addiu $t2, $t2, 1         # count increment
  addiu $a0, $a0, 4      # Move to next index
  j array2_while
finished:

  lw $t1, 0($sp)   # load t1 back from stack
  addiu $sp, $sp, 4 # increment the stack pointer by 4
  la $a0, array1    # Load the address of the array 1 into the $a0
  move $a1, $t1   # move the size of the array into the $a1

  addiu $sp, $sp, -4   # decrement stack pointer by 4
  sw $t1, 0($sp)          # Save the size of the array1 into stack
  addiu $sp, $sp, -4  # decrement the stack pointer by 4
  sw $t2, 0($sp)    # Save the size of array2 on the stack

  jal print_array   # function call print_array

  #Make a new line
  li    $a0, 10        # Load the address of newline into $a0
  li    $v0, 11           # Call the system print the newline character
  syscall

  lw $t2, 0($sp)        # Copy the saved t2 into $t2
  addiu $sp, $sp, 4   # increment the stack pointer by 4
  la $a0, array2          # load the address of the array2 into $a0
  move $a1, $t2       # move the size of the array into the $a1
  jal print_array   # function call print_array

  lw $a0, array1    # Copy the address of the array 1 into $a0
  lw $t1, 0($sp)          # Load the saved t1 from stack
  addiu $sp, $sp, 4   # increment the stack pointer by 4
  move $a1, $t1     # copy the size of array 1 into $a1
  lw $a2, array2    # Copy the address of the array 2 into $a2
  move $a3, $t2   # copy the size of the array 2 into $a3
  jal merge

# This is the end of the main
  lw $ra 0($sp)   #restore the saved $ra
  addiu $sp, $sp, 4 # Increment the stack pointer by 4
  li $v0, 0x0a
  syscall
  .end main

print_array:
# $a0 is the address of the array
# $a1 is the size of the array
# $s0 is the current character
  addi $sp, $sp, -4         # Decrement the stack pointer by 4
  sw $s0, 0($sp)            # Save $s0 to the stack
loop:
  lw $s0, 0($a0)              # load the character at current address
  beq $s0, $zero, done  # If met the end of the array, exit
  addiu $sp, $sp, -4      # decrement the stack pointer by 4
  sw $a0, 0($sp)            # save the $a0
  move $a0, $s0             # move current character into a0
  li $v0, 1                          # display the current index
  syscall
  lw $a0, 0($sp)        # load the saved $a0 from stack
  addiu $sp, $sp, 4   #increment the stack pointer by 4
  addiu $a0, $a0, 4      # Move to next index
  j loop
done:
  lw $s0, 0($sp)     # Release the saved s0
  addiu $sp, $sp, 4  # Increment the stack pointer by 4
  jr $ra                    # return nothing

merge:
# $a0 is the address of array 1
# $a1 is the size of the array 1
# $a2 is the address of the array 2
# $a3 is the size of the array 2
# $t0 is the array1 index
# $t1 is the array2 index
# $t2 is the result array index
# $t3 is array1 size + array2 size
# $t4 is the current address of the array1
# $t5 is the current address of the array2
# $t6 is the compare temp value
# $t7 is also the compare temp value
move $t0, $zero   # Initialize the array1 index to 0
move $t1, $zero   # Initialize the array2 index to 0
move $t2, $zero  # Initialize the result array index to 0
addu $t3, $a1, $a3  # Calculate the array1+array2 size and store it into $t3
move $t4, $zero   # Initialize the current address of the array1 to 0
move $t5, $zero   # Initialize the current address of the array2 to 0
