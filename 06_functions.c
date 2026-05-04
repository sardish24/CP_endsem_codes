/*
 * Module: Functions
 * Description: Demonstrates function declaration, definition, parameter passing 
 *              (pass-by-value), and return statements.
 */

#include <stdio.h>

/* 
 * Function Declaration (Prototype)
 * Informs the compiler about the function's name, return type, and parameters
 * before its actual definition. This allows calling it before it's defined.
 */
int addNumbers(int a, int b);
void printMessage(void); /* 'void' indicates no parameters and no return value */

int main() {
    int num1 = 10, num2 = 20;

    printMessage(); /* Function call */

    /* 
     * Pass by Value: 
     * The actual values of num1 and num2 are COPIED into the function parameters.
     * Modifying parameters inside the function does not affect num1 or num2.
     */
    int sum = addNumbers(num1, num2);
    
    printf("The sum of %d and %d is %d\n", num1, num2, sum);

    return 0;
}

/* 
 * Function Definition
 * Contains the actual code to be executed when the function is called.
 */
int addNumbers(int a, int b) {
    /* 
     * 'a' and 'b' are local variables created when the function is called,
     * and destroyed when it returns.
     */
    int result = a + b;
    
    /* 
     * return statement passes the result back to the caller.
     * The type of 'result' must match the declared return type 'int'.
     */
    return result;
}

void printMessage(void) {
    printf("--- Function Example ---\n");
    /* No return statement needed for void functions */
}
