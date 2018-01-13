#Dakota Ruhl, 2318-253, Assignment 2 Part 1 Program A
				.data
nameBuffer:			.space 41
intPrompt:			.asciiz "Enter integer: "

stringPrompt: 			.asciiz "\n Enter string, up to 40 characters: "
charPrompt: 			.asciiz "\n Enter a character: "
newline: 			.asciiz "\n"

				.text
				.globl main
main:
				####Integer#####
			
				#Print prompt
				li $v0, 4
				la $a0, intPrompt
				syscall
			
				#Read integer
			li $v0, 5
			syscall
			#Store integer in $t0
			move $t0, $v0 
			
			#Print user entered integer
			li $v0, 1
			move $a0, $t0
			syscall
			
			####String####
			
			#Print prompt
			li $v0, 4
			la $a0, stringPrompt
			syscall
			
			#Read string
			la $a0, nameBuffer
			li $a1, 41
			li $v0, 8
			syscall
		
			#Print user entered string
			li $v0, 4
			syscall
			
			####Character####
			
			#Print prompt
			la $a0, charPrompt
			syscall
			
			#Read character
			li $v0, 12
			syscall
			#Store char in $t0
			move $t0, $v0
			
			#new line
			li $v0, 4
			la $a0, newline
			syscall
			#Print user entered character
			li $v0, 11
			move $a0, $t0
			syscall
			
			li $v0, 10               # exit
                	syscall
			
			