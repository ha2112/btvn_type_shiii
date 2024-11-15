.data
buffer1: .space 100                    			# Reserve 10 bytes for first input string
buffer2: .space 100                     		# Reserve 10 bytes for second input string
message_equal: .asciz "Strings are equal"       	# Message if strings are equal
message_not_equal: .asciz "Strings are not equal"  	# Message if strings are not equal

.text
main:
    # Prompt user to input first string
	li a7, 8                           # Set a7 to 8 for sys_read syscall
	li a1, 10                          # Set max input length to 10 bytes
	la a0, buffer1                     # Load address of buffer1 (input 1) into a0
	ecall                              # Call system to read input
	la t0, buffer1                     # Store address of buffer1 in t0 to process it

    # Prompt user to input second string
	la a0, buffer2                     # Load address of buffer2 (input 2) into a0
	ecall                              # Call system to read input
	la t1, buffer2                     # Store address of buffer2 in t1 to process it

    # Initialize ASCII range for lowercase and conversion offset
	li t2, 'a'                         # ASCII value of 'a' in t2
	li t3, 'z'                         # ASCII value of 'z' in t3
	li t4, 32                          # Difference between lowercase and uppercase letters (32)

loop:
	lb a0, 0(t0)                       # Load byte from first string at address t0 into a0
	lb a1, 0(t1)                       # Load byte from second string at address t1 into a1
	beqz a0, end_check                 # If a0 is null (end of string), go to end_check
	beqz a1, not_equal                 # If a1 is null but a0 is not, strings are not equal

    # Check and convert lowercase to uppercase for first string character
	blt a0, t2, upper_handle1          # If a0 is less than 'a', skip conversion for this character
	bgt a0, t3, upper_handle1          # If a0 is greater than 'z', skip conversion for this character
	sub a0, a0, t4                     # Convert lowercase a0 to uppercase by subtracting 32

upper_handle1:
    # Check and convert lowercase to uppercase for second string character
	blt a1, t2, upper_handle2          # If a1 is less than 'a', skip conversion for this character
	bgt a1, t3, upper_handle2          # If a1 is greater than 'z', skip conversion for this character
	sub a1, a1, t4                     # Convert lowercase a1 to uppercase by subtracting 32

upper_handle2:
	bne a1, a0, not_equal              # If characters differ, strings are not equal
	addi t0, t0, 1                     # Move to the next character in first string
	addi t1, t1, 1                     # Move to the next character in second string
	j loop                             # Repeat loop for the next characters

end_check:
    # Check if second string also ended at the same time as the first
	beqz a1, equal                     # If both strings ended, they are equal
	j not_equal                        # Else, they are not equal

equal:
	li a7, 4                           # Syscall to print message
	la a0, message_equal               # Load address of "Strings are equal" message
	ecall                              # Print the message
	j exit                             # Exit program

not_equal: 
	li a7, 4                           # Syscall to print message
	la a0, message_not_equal           # Load address of "Strings are not equal" message
	ecall                              # Print the message
	j exit                             # Exit program

exit: 
	li a7, 10                          # Syscall to exit program
	ecall                              # Call system to exit
