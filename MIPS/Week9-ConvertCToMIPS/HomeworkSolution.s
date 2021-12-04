# Hengyi Li
# This program is to determine whether a stings contains a character.

  .data
promopte_string:
  .asciiz "Please enter a string: \n"
promote_contain:
  .asciiz " contains "
promote_not_contain:
  .asciiz " does not contain "
promote_character:
  .asciiz "Please enter a character: \n"
string:
  .space 10
character:
  .space 4
newline:
  .asciiz "\n"
done:
  .word 0
found:
  .word 0
i:
  .word 0

  .text
  .globl main

main:
#Get String input
  la  $a0, promopte_string            # load the address of string into the $a0
  li  $v0, 0x04                                # print the string system call
  syscall
  la $a0, string                              # load the MAX CHARS into a0
  li $v0, 0x08                                # Accept the stings input
  syscall

# Get char input
  la  $a0, promote_character       # load the address of character into $a0
  li  $v0, 0x04                               # print the character system call
  syscall
  li $v0, 12                                    # Accept the character input
  sw $v0, character                     # Save it into character
  syscall

  jal strcontainsi  #Call the function strcontainsi
  sw $v0, found  #save the function call result into $s0
  move $t0, $v0 #save result into t0
condition:
  la $a0, newline
  li $v0, 0x04
  syscall
  bne $t0, 1, else                        # If not contain, goto else
  la  $a0, string                           # load the address of string into the $a0
  li  $v0, 0x04                            # print the string system call
  syscall
  la $a0, promote_contain         # string contains character
  li $v0, 0x04                             # print the system call
  syscall
  la $a0, character              #Print the character
  li $v0, 11                            #syscall to print
  syscall
  li $v0, 0x0a  # Exit the system call
  syscall
  j Finished                                      #Finished operation, jump to exit
else:
  la $a0, newline
  li $v0, 0x04
  syscall
  la  $a0,string
  li  $v0, 0x04     # print the string system call
  syscall
  la $a0, promote_not_contain # Print out the string is not contain the character
  li $v0, 0x04  #print the system call
  syscall
  la $a0, character               #Print the character
  li $v0, 11                            #syscall to print
  syscall
  li $v0, 0x0a  # Exit the system call
  syscall
Finished:
  .end main

# TO-DO: Finshed the function call
strcontainsi:
  # a0 base address of string
  # t1 string index
  # t2 the current character
  # t3 the address of the current character
  # $s0 the value of character
  # $s1 the value of done
  # $s2 the value of found
  lw $s2, found
  addu $s2, $s2, 1
  move  $v0, $s2            # return value: the value of the found
  jr    $ra                         # return


toupper:
  # a0: the character parameter
  # v0: the return value

  addu  $v0, $a0, $zero # copy a0 to v0
  blt $v0, 0x61, tu_end # 0x61 = 'a'; ignore chars less than
  bgt $v0, 0x7a, tu_end # 0x7a = 'z'; ignore chars greater than
  subu  $v0, $v0, 0x20  # 0x20 = 'a' - 'A'

tu_end:
  jr  $ra
