# Hengyi Li
# This program is to determine whether a stings contains a character.

  .data
message_string:
  .asciiz "Please enter a string: "
message_enter_a_character:
  .asciiz "Please enter a character: "

  .text
  .globl main
main:
  la    $a0, message_string # load the message into the $a0
  li    $v0, 4              #Allocated the spaces and call the return function
  syscall


  li    $v0,8               #take in input
  la    $a0, buffer         #load byte space into address
  li    $a1, 20             # allot the byte space for string
  move $t0,$a0              #save string to t0
  syscall

  li $v0, 0x0a #Exit the program
  syscall

  .end main

toupper:
  # a0: the character parameter
  # v0: the return value

  addu  $v0, $a0, $zero     # copy a0 to v0
  blt   $v0, 0x61, tu_end   # 0x61 = 'a'; ignore chars less than
  bgt   $v0, 0x7a, tu_end   # 0x7a = 'z'; ignore chars greater than
  subu  $v0, $v0, 0x20      # 0x20 = 'a' - 'A'

tu_end:
  jr    $ra