#Dakota Ruhl, CS 2318-253, Assignment 2 Part 1 Program D.

#This program will allocate a global array with 
#space for 3 integers.It will then preform
#some array manipulations (swaps)
	
		.data
intArr:		.word 2,3,1,8
intArray:	#.space 12
		
		.text
		.globl main
		
main:		la $t0, intArr
		lw $t1, 0($t0)
		lw $t2, 4($t0)
		lw $t3, 8($t0)
		lw $t4, 12($t0)
	
		li $v0, 1
		move $a0, $t1
		syscall
		move $a0, $t2
		syscall 
		move $a0, $t3
		syscall
		move $a0, $t4
		syscall
		
		sw $t4, 0($t0)
		sw $t1, 12($t0)

		li $v0, 11
		li $a0, '\n'
		syscall
		
		li $v0, 1
		lw $a0, 0($t0)
		syscall
		move $a0, $t2
		syscall 
		move $a0, $t3
		syscall
		lw $a0, 12($t0)
		syscall
				
		li $v0, 10	
		syscall
		
		
		
