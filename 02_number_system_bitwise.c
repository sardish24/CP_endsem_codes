/*
 * Module: Number System and Bitwise Operations
 * Description: Demonstrates how numbers are manipulated at the bit level 
 *              using bitwise operators and exploring memory representations.
 */

#include <stdio.h>

/* Function to print binary representation of an 8-bit integer */
void printBinary(unsigned char num) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main() {
    /*
     * We use unsigned char (8 bits) for simplicity in demonstrating bit operations.
     * A = 12 (binary: 00001100)
     * B = 25 (binary: 00011001)
     */
    unsigned char A = 12; 
    unsigned char B = 25;

    printf("A = %u (Binary: ", A);
    printBinary(A);
    printf("B = %u (Binary: ", B);
    printBinary(B);

    printf("\n--- Bitwise Operations ---\n");

    /* 
     * Bitwise AND (&)
     * Compares each bit; results in 1 only if both corresponding bits are 1.
     * Pitfall: Do not confuse bitwise AND (&) with logical AND (&&).
     */
    unsigned char and_result = A & B;
    printf("A & B  = %u (Binary: ", and_result);
    printBinary(and_result);

    /* 
     * Bitwise OR (|)
     * Compares each bit; results in 1 if at least one corresponding bit is 1.
     */
    unsigned char or_result = A | B;
    printf("A | B  = %u (Binary: ", or_result);
    printBinary(or_result);

    /* 
     * Bitwise XOR (^)
     * Compares each bit; results in 1 if corresponding bits are different.
     * Frequently used in cryptography and parity checks.
     */
    unsigned char xor_result = A ^ B;
    printf("A ^ B  = %u (Binary: ", xor_result);
    printBinary(xor_result);

    /* 
     * Bitwise NOT (~)
     * Inverts all bits (1s become 0s, 0s become 1s).
     */
    unsigned char not_A = ~A;
    printf("~A     = %u (Binary: ", not_A);
    printBinary(not_A);

    /* 
     * Left Shift (<<)
     * Shifts bits to the left by the specified number of positions.
     * Effectively multiplies the number by 2^n.
     * Edge Case: Bits shifted off the left end are discarded; 0s are added on the right.
     */
    unsigned char left_shift = A << 2;
    printf("A << 2 = %u (Binary: ", left_shift);
    printBinary(left_shift);

    /* 
     * Right Shift (>>)
     * Shifts bits to the right. 
     * Effectively divides the number by 2^n.
     */
    unsigned char right_shift = B >> 1;
    printf("B >> 1 = %u (Binary: ", right_shift);
    printBinary(right_shift);

    return 0;
}
