/*
 * Module: The C Pre-processor
 * Description: Demonstrates preprocessor directives, macros, macro parameters, 
 *              and conditional compilation.
 */

#include <stdio.h>

/* 
 * 1. Object-like Macros
 * Before compilation, the preprocessor replaces all instances of 'PI' with '3.14159'.
 * It does NOT allocate memory or have a data type.
 */
#define PI 3.14159
#define MAX_BUFFER 1024

/* 
 * 2. Function-like Macros
 * Takes arguments. 
 * Pitfall: Always wrap macro arguments in parentheses to avoid operator precedence issues.
 */
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

/* 
 * 3. Conditional Compilation
 * Used to compile different blocks of code based on specific conditions 
 * (useful for cross-platform support or debug logs).
 */
#define DEBUG_MODE 1

int main() {
    printf("--- Object-like Macros ---\n");
    printf("Value of PI: %f\n", PI);
    printf("Max Buffer Size: %d\n", MAX_BUFFER);

    printf("\n--- Function-like Macros ---\n");
    int num = 5;
    printf("Square of %d is %d\n", num, SQUARE(num));

    /* 
     * Pitfall: Macro Side Effects
     * Because macros use text substitution, SQUARE(++num) expands to ((++num) * (++num)).
     * This evaluates '++num' twice, causing undefined or unexpected behavior!
     * Never pass expressions with side effects (like i++) to macros.
     */
    int val1 = 10, val2 = 20;
    printf("Max of %d and %d is %d\n", val1, val2, MAX(val1, val2));

    printf("\n--- Conditional Compilation ---\n");

#if DEBUG_MODE == 1
    /* This block is compiled only if DEBUG_MODE is 1 */
    printf("[DEBUG] Application initialized successfully.\n");
#else
    /* This block is skipped entirely by the compiler if DEBUG_MODE is 1 */
    printf("Application running in production mode.\n");
#endif

    return 0;
}
