#Dakota Ruhl, CS 2318-253, Assignment 2 Part 1 Program D.

#This program will prompt the user for 3 exams, and 
#by using a provided formula, it will find and display the average score.			
			.data
e1:			.asciiz "Enter First Exam Score: "
e2:			.asciiz "Enter Second Exam Score: "
fE:			.asciiz "Enter Final Exam Score: "
avg:			.asciiz "Your average score is: " 
			.text
			.globl main
			

main:			la $a0, e1	#Prompt for Exam 1
			li $v0, 4
			syscall
			
			li $v0, 5	#UserInput
			syscall
			
			move $t0, $v0	#Move input to $t0
			
			la $a0, e2	#Prompt for Exam 2
			li $v0, 4
			syscall
			
			li $v0, 5	#UserInput
			syscall
			
			move $t1, $v0	#Move into $t1
			
			la $a0, fE	#Final exam prompt
			li $v0, 4
			syscall 
			
			li $v0, 5	#UserInput
			syscall
			
			move $t2,$v0	#Move final to $t2
			
			li $t3, 205		#load 205
			mul $t7, $t0, $t3	# Exam1*205 stores into temp 7 
			srl $t7, $t7, 10	# temp 1 / 1024
			
			sll $t8, $t1, 8		# Exam2 * 256 = temp 8
			li $t4, 854		# temp 4 = 854
			div $t8, $t8, $t4	# temp 8 / 854
			
			srl $t9, $t2, 1		# FinalExam / 2 = avg
			add $t9, $t9, $t7 	# temp 7 + avg = avg
			add $t9, $t9, $t8	# temp 8 + avg = avg
			
			la $a0, avg
			li $v0, 4
			syscall
			
			li $v0, 1
			move $a0, $t9
			syscall
			
			li $v0, 10 
			syscall 
