/*
 * Module: Basic C Program & its Execution
 * Description: Demonstrates the fundamental structure of a C program,
 *              standard input/output functions, and basic compilation concepts.
 */

/* 
 * The #include directive tells the C preprocessor to include the contents 
 * of the standard input/output library (stdio.h) before compiling. 
 * This is necessary for printf() and scanf() functions.
 */
#include <stdio.h>

/*
 * main() is the entry point of any C program. 
 * The 'int' return type indicates that the program will return an integer value 
 * to the operating system upon completion.
 */
int main() {
    /* 
     * Variable declaration:
     * We declare an integer variable named 'age' to store user input.
     * It's good practice to initialize variables to avoid garbage values,
     * though here it gets overwritten immediately by scanf.
     */
    int age = 0;

    /* 
     * printf() is used to print formatted output to the standard output (screen).
     * The string literal is enclosed in double quotes. 
     */
    printf("Welcome to C Programming!\n");
    printf("Please enter your age: ");

    /* 
     * scanf() is used to read formatted input from the standard input (keyboard).
     * '%d' is the format specifier for integers.
     * '&age' provides the memory address of the variable 'age' so scanf can 
     * store the input value directly into that memory location.
     * Pitfall: Forgetting the '&' before the variable name in scanf leads to 
     * undefined behavior or a segmentation fault.
     */
    if (scanf("%d", &age) != 1) {
        /* Edge case handling: If scanf fails to read an integer */
        printf("Invalid input. Please enter a valid integer.\n");
        return 1; /* Return a non-zero value to indicate an error */
    }

    /* 
     * Printing the variable using printf with a format specifier. 
     * '\n' is an escape sequence for a newline character.
     */
    printf("You entered: %d\n", age);

    /* 
     * return 0; indicates successful termination of the program.
     */
    return 0;
}
