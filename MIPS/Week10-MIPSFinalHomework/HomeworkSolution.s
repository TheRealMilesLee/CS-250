# Hengyi Li
# A program that implements two functions, merge and print_array,
# and calls those two functions to show that they operate correctly

  .data
array1:
  .word 1, 3, 4, 5, 8, 9
space_between_array:
  .space 1
newline:
  .asciiz "\n"
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

  la $a0, array1           # load the address of array1 into $a0
  syscall
  move $t1, $zero       # Initialize the $t1 to 0
while:
  lw $t0, 0($a0)          # Load first element of array 1 into t0
  beq $t0, $zero, exit   # if it reaches to the end, exit
  addiu $t1, $t1, 1         # count increment
  addiu $a0, $a0, 4      # Move to next index
  j while
exit:

  la $a0, array2           # load the address of array1 into $a0
  syscall
  move $t2, $zero       # Initialize the $t2 to 0
array2_while:
  lw $t0, 0($a0)          # Load first element of array 2 into t0
  beq $t0, $zero, finished   # if it reaches to the end, exit
  addiu $t2, $t2, 1         # count increment
  addiu $a0, $a0, 4      # Move to next index
  j array2_while
finished:

  addiu $sp, $sp, -4  #decrement the stack pointer by 4
  sw $t2, 0($sp)    # Save the size of array2 on the stack

  la $a0, array1    # Load the address of the array 1 into the $a0
  move $a1, $t1   # move the size of the array into the $a1
  jal print_array   # function call print_array

  #Make a new line
  la    $a0, newline        # Load the address of newline into $a0
  li    $v0, 0x04           # Call the system print the newline character
  syscall

  lw $t2, 0($sp)        # Copy the saved t2 into $t2
  addiu $sp, $sp, 4   # increment the stack pointer by 4

  la $a0, array2          # load the address of the array2 into $a0
  move $a1, $t2       # move the size of the array into the $a1
  jal print_array   # function call print_array

# This is the end of the main
  li $v0, 0x0a
  syscall
  .end main

print_array:
# $a0 is the address of the array
# $a1 is the size of the array
# $t3 is the current character

loop:
  lw $t3, 0($a0)              # load the character at current address
  beq $t3, $zero, done  # If met the end of the array, exit
  addiu $sp, $sp, -4  #decrement the stack pointer by 4
  sw $a0, 0($sp)      # save the $a0
  move $a0, $t3       # move current character into a0
  li $v0, 1                  # display the current index
  syscall
  lw $a0, 0($sp)        # load the saved $a0 from stack
  addiu $sp, $sp, 4   #increment the stack pointer by 4
  addiu $a0, $a0, 4      # Move to next index
  j loop
done:
  jr $ra                    # return nothing
