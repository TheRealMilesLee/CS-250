# Hengyi Li
# A program that implements two functions, merge and print_array,
# and calls those two functions to show that they operate correctly

  .data
array1:
  .word 1, 3, 4, 5, 8, 9
array2:
  .word 2, 6, 7, 8

  .text
  .globl main

main:
# $s0 is the address of the array1
# $s1 is the length of the array1
# $s2 is the length of the array2
  la $a0, array1
  syscall
  move  $s0, $a0		# $s0 =$a0
  sll   $t0, $s4, 2               # $t0 = 1 * 4
  addu $t1, $t0,             # t1 = &B[i]
  lw $t2, 4($t1)                # $t2 = B[i + 1]
  addu $t3, $t0, $s6            # $t3 = &A[i]
  sw $t0, - 4($t3)              # A[i - 1] = B[i + 1]







  li $v0, 0x0a
  syscall
  .end main