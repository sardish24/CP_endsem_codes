/*
 * Module: Data Types and Variables
 * Description: Demonstrates standard C data types, type modifiers, sizes, 
 *              typecasting, and common edge cases like integer overflow.
 */

#include <stdio.h>
#include <limits.h> /* Contains macros for integer limits (e.g., INT_MAX) */
#include <float.h>  /* Contains macros for floating-point limits */

int main() {
    /* 
     * --- Basic Data Types ---
     * char: typically 1 byte. Can store characters (ASCII values).
     * int: typically 4 bytes. Stores whole numbers.
     * float: typically 4 bytes. Stores single-precision decimal numbers.
     * double: typically 8 bytes. Stores double-precision decimal numbers.
     */
    char letter = 'A';
    int number = 42;
    float pi_approx = 3.14159f; /* The 'f' suffix specifies a float literal */
    double precise_pi = 3.141592653589793;

    printf("--- Basic Types ---\n");
    printf("char:   %c (Size: %zu bytes)\n", letter, sizeof(char));
    printf("int:    %d (Size: %zu bytes)\n", number, sizeof(int));
    /* %f defaults to 6 decimal places. Use %.2f to specify precision */
    printf("float:  %.5f (Size: %zu bytes)\n", pi_approx, sizeof(float));
    printf("double: %.15lf (Size: %zu bytes)\n\n", precise_pi, sizeof(double));

    /* 
     * --- Type Modifiers ---
     * Modifiers change the size or range of basic types.
     * unsigned: Allows only non-negative values, doubling the positive upper limit.
     * long / short: Increases or decreases memory allocation.
     */
    unsigned int positive_only = 4000000000U; 
    long long huge_number = 9223372036854775807LL;

    printf("--- Type Modifiers ---\n");
    printf("unsigned int: %u\n", positive_only);
    printf("long long:    %lld\n\n", huge_number);

    /* 
     * --- Edge Case: Integer Overflow ---
     * When a variable exceeds its maximum limit, it "wraps around" 
     * to the minimum value (due to two's complement representation).
     * Pitfall: Overflow leads to silent logic bugs; always check bounds.
     */
    int max_int = INT_MAX;
    printf("--- Overflow Edge Case ---\n");
    printf("INT_MAX = %d\n", max_int);
    
    int overflowed_int = max_int + 1;
    printf("INT_MAX + 1 = %d (Notice the wrap-around to negative!)\n\n", overflowed_int);

    /* 
     * --- Type Casting ---
     * Converting a variable from one data type to another.
     * Explicit casting is done using (type) operator.
     * Implicit casting happens automatically (e.g., int to float during arithmetic).
     */
    int a = 5, b = 2;
    float implicit_cast = a / b; /* Integer division happens first: 5/2 = 2. Then cast to 2.0 */
    float explicit_cast = (float)a / b; /* 'a' cast to float first: 5.0/2 = 2.5 */

    printf("--- Type Casting ---\n");
    printf("Implicit (a/b): %f\n", implicit_cast);
    printf("Explicit ((float)a/b): %f\n", explicit_cast);

    return 0;
}
