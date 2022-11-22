# Hengyi Li
   .data
message:
   .asciiz "Hello Word! \n"

   .text
   .globl main
main:
   la $a0, message
   li $v0, 4
   syscall

   li $v0, 0x0a
   syscall

   .end main
