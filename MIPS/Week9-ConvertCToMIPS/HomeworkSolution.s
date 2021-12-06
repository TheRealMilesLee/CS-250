# Hengyi Li
# This program is to determine whether a stings contains a character.

  .data
prompt_string:
  .asciiz "Please enter a string: "
prompt_character:
  .asciiz "Please enter a character: "
contain:
  .asciiz " contains "
not_contain:
  .asciiz " does not contain "
newline:
  .asciiz "\n"

string:
  .space 11
character:
  .space 11

  .text
  .globl main

main:
#Get String input
  la    $a0, prompt_string            # load the address of promote into the $a0
  li    $v0, 0x04                                # print the string system call
  syscall
  la $a0, string                              # load the address of string into $a0
  li $v0, 0x08                                # Accept the stings input
  li $a1, 11                                     # Allocated the max chars
  syscall
  move 		$s0,  $a0		                    # save a copy of string into $s0

#Make a new line
  la $a0, newline                     # Load the address of newline into $a0
  li $v0, 0x04                          # Call the system print the newline character
  syscall

# Get char input
  la  $a0, prompt_character       # load the address of promote into $a0
  li  $v0, 0x04                               # print the character system call
  syscall
  li $v0, 12                                    # Accept the character input
  syscall
  move $s1, $v0                           # Save the $v0 result into $s1

  move $a0, $s0                      # load the string to $a0
  move $a1, $s1                       # load the char to $a1

# Function Call: strcontainsi
  jal strcontainsi                        # Call the function strcontainsi
  move $t0, $v0                       # Save result into t0

#Condition: if contains and if not contains
condition:
  # Contain, continue, not contain, goto else
  bne $t0, 1, else                      # If not found, goto else

#Make a new line
  la $a0, newline                     # Load the address of newline into $a0
  li $v0, 0x04                          # Call the system print the newline character
  syscall

  # Print the origional string
  la  $a0, string                          # load the address of string into the $a0
  li  $v0, 0x04                            # print the string system call
  syscall

  #Print the "contains"
  la $a0, contain   # Load the address of contain into $a0
  li $v0, 0x04                        # syscall, print the promote
  syscall

  # Print the character
  move $a0, $s1                   # Load the character into $a0
  li $v0, 11                            # call the print character
  syscall

  # Finished operation, jump to end of the if-statement
  j Finished                          #Finished operation, jump to Finished

else:
# Make a new line
  la $a0, newline                 # Load the address of newline into $a0
  li $v0, 0x04                      # call the print string to print the newline
  syscall

  # Print the origional string
  la  $a0,string                   # Load the address of origional string into $a0
  li  $v0, 0x04                    # print string system call
  syscall

  #Print "does not contains"
  la $a0, not_contain        # Load the address of not_contain into $a0
  li $v0, 0x04                    # Print string system call
  syscall

  # Print the character
  move $a0, $s1           # Load the character into $a0
  li $v0, 11                     # call the print character
  syscall

Finished:
  # This is the end of the main
  li $v0, 0x0a                             # Exit the system call
  syscall
  .end main

# TO-DO: Finshed the function call
strcontainsi:
# $a0 is the string to find
# $a1 is the character
# $t1 is the value of found
# $t2 is the value of done
# $t3 is the index
# $t4 is the address of the current index
# $t5 is the current character
# $t6 is the string character converted to uppercase
  addiu $t1, $t1, 0                # Initialize the found value as 0
  addiu $t2, $t2, 0              # Initialize the boolean done as 0
  addiu $t3, $t3, 0              # Initialize the index as 0
loop:
  bne $t2, 0, exit                # If done is not equal to 0, goto exit
  addu  $t4, $t3, $a0         # t4 = &str[index]
  lbu   $t5, 0($t4)               # t5 = str[index]
enter:
    bne $t5, $zero, else_if # if (str[i] != '\0'), goto else_if
    addiu $t2, $t2, 1           # done = 1
    bne $t2, 0, Done                # If done is not equal to 0, goto Done
else_if:
    move $a0, $t5       # Copy the current character into $a0
    addiu $sp, $sp, -4  # decrement stack pointer by 4
    sw $ra, 0($sp)        # copy ra to stack pointer
    jal toupper               # call function to upper
    move $t6, $v0        # Save the character into $t6
    move $a0, $a1        # Copy the compare character into $a0
    jal toupper               # convert it to uppercase
    bne $t6, $v0, increment  # if str[i] != ch, goto else
    addiu $t1, $t1, 1       # found = 1
    addiu $t2, $t2, 1     # done = 1
    bne $t2, 0, Done                # If done is not equal to 0, goto exit
    j loop
increment:
    addiu $t3, 1              # increment the index
Done:
    j exit

#Finished Execution, return the value
exit:
  lw $ra, 0($sp)            # copy *sp into register
  addiu $sp, $sp, 4      # Increment stack pointer by 4
  move  $v0, $t1            # return value: the value of the found
  jr    $ra                         # return
  j loop

toupper:
  # a0: the character parameter
  # v0: the return value

  addu  $v0, $a0, $zero       # copy a0 to v0
  blt $v0, 0x61, tu_end        # 0x61 = 'a'; ignore chars less than
  bgt $v0, 0x7a, tu_end       # 0x7a = 'z'; ignore chars greater than
  subu  $v0, $v0, 0x20        # 0x20 = 'a' - 'A'

tu_end:
  jr  $ra
