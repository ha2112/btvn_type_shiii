.data
endl: .asciz "\n"          # Define newline character string

.text
main:
    li t1, 0               # Initialize iterator t1 to 0
    li t0, 10              # Set the array length (10) in t0
    li t2, 0               # Initialize t2 to store the sum of even numbers
    li t3, 0               # Initialize t3 to store the sum of odd numbers
    li t6, 2               # Load 2 into t6 for modulus check (to identify even numbers)

loop:
    bge t1, t0, endloop    # If t1 >= t0, exit the loop (end of array)
    rem t4, t1, t6         # Compute t1 % 2; remainder is stored in t4
    beqz t4, input_even    # If t1 is even (remainder 0), jump to input_even
    j input_odd            # Otherwise, jump to input_odd (for odd numbers)

input_even:
    li a7, 5               # Syscall to read an integer
    ecall                  # Read integer input into a0
    add t2, t2, a0         # Add input to t2 (even sum)
    addi t1, t1, 1         # Increment iterator t1
    j loop                 # Jump back to start of loop

input_odd:
    li a7, 5               # Syscall to read an integer
    ecall                  # Read integer input into a0
    add t3, t3, a0         # Add input to t3 (odd sum)
    addi t1, t1, 1         # Increment iterator t1
    j loop                 # Jump back to start of loop

endloop:
    li a7, 1               # Syscall to print integer
    addi a0, t2, 0         # Move even sum (t2) to a0 for printing
    ecall                  # Print even sum
    li a7, 4               # Syscall to print string
    la a0, endl            # Load address of newline character
    ecall                  # Print newline
    li a7, 1               # Syscall to print integer
    addi a0, t3, 0         # Move odd sum (t3) to a0 for printing
    ecall                  # Print odd sum
    li a7, 10              # Syscall to exit program
    ecall                  # Exit
