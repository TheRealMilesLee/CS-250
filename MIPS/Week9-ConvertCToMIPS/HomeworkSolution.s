# Hengyi Li
# This program is to determine whether a stings contains a character.

  .data
string:
  .asciiz "Please enter a string: \n"

character:
  .asciiz "Please enter a character: \n"

newline:
  .asciiz "\n"

  .text
  .globl main
main:
  la	$a0, string 	# load the address of string into the $a0
  li	$v0, 0x04			# print the string system call
  syscall

  li $v0, 8	#Accept the stings input
  syscall
  move 		$t0, $v0		# save it into the t0

  la $a0, newline
  la	$a0, character 		# load the address of character into $a0
  li	$v0, 0x04							# print the character system call
  syscall

	li $v0, 8	# Accept the character input
	syscall
  move 		$t1, $v0		# save it into t1


  li $v0, 0x0a  # Exit the system call
  li $v1, 0x0a  # Exit the system call
  syscall
  .end main

toupper:
  # a0: the character parameter
  # v0: the return value

  addu  $v0, $a0, $zero	# copy a0 to v0
  blt	$v0, 0x61, tu_end	# 0x61 = 'a'; ignore chars less than
  bgt	$v0, 0x7a, tu_end	# 0x7a = 'z'; ignore chars greater than
  subu  $v0, $v0, 0x20	# 0x20 = 'a' - 'A'

tu_end:
  jr	$ra