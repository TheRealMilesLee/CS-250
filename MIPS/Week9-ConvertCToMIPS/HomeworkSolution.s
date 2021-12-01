# Hengyi Li
# This program is to determine whether a stings contains a character.

  .data
message_enter_a_string:
  .asciiz "Please enter a string: "
message_enter_a_character:
  .asciiz "Please enter a character: "

  .text
  .globl main
main:
  la $a0, message_enter_a_string
  li $v0, 4
  syscall
  