# Hengyi Li
# This program is to determine whether a stings contains a character.

  .data
promopte_string:
  .asciiz "Please enter a string: \n"
promote_contain:
	.asciiz " contains "
promote_not_contain:
	.asciiz " does not contain "

character:
  .asciiz "Please enter a character: \n"

string:
	.space 10

newline:
  .asciiz "\n"

  .text
  .globl main
main:
  la	$a0, promopte_string 	# load the address of string into the $a0
  li	$v0, 0x04			# print the string system call
  syscall

	la $a0, string
  li $v0, 8		#Accept the stings input
  syscall
	move 		$t0, $v0		# $t0 = $v0

  la $a0, newline
  la	$a0, character 		# load the address of character into $a0
  li	$v0, 0x04							# print the character system call
  syscall

	li $v0, 12	# Accept the character input
	syscall
  move 		$t1, $v0		# save it into t1

condition:
	bne strcontainsi, 1, else
	la	$a0, promopte_string 	# load the address of string into the $a0
  li	$v0, 0x04			# print the string system call
  syscall

	la $a0, promote_not_contain	#Print the string is contain character
	li $v0, 0x04	# print the system call
	syscall

	la $a0, stings	#Print the character that string contains
	li $v0, 0x04	#syscall to print
	syscall
else:
	la	$a0, promopte_string 	# load the address of string into the $a0
  li	$v0, 0x04			# print the string system call
  syscall

	la $a0, promote_not_contain	# Print out the string is not contain the character
	li $v0, 0x04	#print the system call
	syscall


  li $v0, 0x0a  # Exit the system call
  li $v1, 0x0a  # Exit the system call
  syscall
  .end main

strcontainsi:
	

toupper:
  # a0: the character parameter
  # v0: the return value

  addu  $v0, $a0, $zero	# copy a0 to v0
  blt	$v0, 0x61, tu_end	# 0x61 = 'a'; ignore chars less than
  bgt	$v0, 0x7a, tu_end	# 0x7a = 'z'; ignore chars greater than
  subu  $v0, $v0, 0x20	# 0x20 = 'a' - 'A'

tu_end:
  jr	$ra