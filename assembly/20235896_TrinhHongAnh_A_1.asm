.data
space: .asciz " "

.text
main: 
	li a7, 5 		#load immediate in a7 to read 1 integer N
	ecall
	addi t0, a0, 0        	# save N into t0
	li t1, 0              	# initialize iterator in t1
    	la a0, space          	# load address of space character (not used in this case)
    	li t3, 3              	# load 3 into t3 (for mod 3 check)
    	li t5, 5              	# load 5 into t5 (for mod 5 check)
loop:
	bge t1, t0, endloop   	# if iterator >= N, end loop
	rem t2, t1, t3      	# save remainder of t1 (iterator) when divided by 3 in t2
	beqz t2, print_if_3	# navigate to print the iterator if remainder = 0
	rem t2, t1, t5     	# save remainder of t1 (iterator) when divided by 5 in t2	
	beqz t2, print_if_5	# navigate to print the iterator if remainder = 0
	addi t1, t1, 1   	#increment iterator  
	j loop			#jump to loop
print_if_3:
	li a7, 1              # syscall to print integer
   	addi a0, t1, 0        # move iterator value to a0 for printing
  	ecall
    	la a0, space          # load address of space character
    	li a7, 4              # syscall to print string
    	ecall
    	addi t1, t1, 1        # increment iterator
    	j loop                # jump back to loop start
print_if_5:
	li a7, 1              # syscall to print integer
   	addi a0, t1, 0        # move iterator value to a0 for printing
  	ecall
    	la a0, space          # load address of space character
    	li a7, 4              # syscall to print string
    	ecall
    	addi t1, t1, 1        # increment iterator
    	j loop                # jump back to loop start
endloop:
	li a7, 10
	ecall