/*
 * Module: Control Flow - Looping
 * Description: Demonstrates repetitive execution using for, while, and do-while loops,
 *              along with loop control statements break and continue.
 */

#include <stdio.h>

int main() {
    printf("--- For Loop ---\n");
    /* 
     * for loop is ideal when the number of iterations is known.
     * Structure: for (initialization; condition; increment/decrement)
     */
    for (int i = 1; i <= 5; i++) {
        printf("Iteration: %d\n", i);
    }

    printf("\n--- While Loop ---\n");
    /* 
     * while loop evaluates the condition before executing the block.
     * Ideal when the number of iterations is unknown and depends on runtime logic.
     * Pitfall: Forgetting to update the loop variable inside the body causes infinite loops.
     */
    int counter = 5;
    while (counter > 0) {
        printf("Countdown: %d\n", counter);
        counter--; /* Update condition to prevent infinite loop */
    }

    printf("\n--- Do-While Loop ---\n");
    /* 
     * do-while loop guarantees the body will execute AT LEAST ONCE,
     * because the condition is checked AFTER the loop body executes.
     */
    int input = 0;
    do {
        /* We simulate user input here instead of using scanf to keep the program non-blocking */
        printf("Executing do-while body (simulated input: %d)\n", input);
        input = 1; /* Simulate getting a value that will break the loop */
    } while (input != 1); 

    printf("\n--- Break and Continue ---\n");
    /* 
     * break: Instantly terminates the nearest enclosing loop.
     * continue: Skips the remaining code in the current iteration and jumps to the next evaluation.
     */
    for (int j = 1; j <= 5; j++) {
        if (j == 3) {
            printf("Skipping iteration %d using 'continue'\n", j);
            continue; /* Jumps to the increment step (j++) immediately */
        }
        if (j == 5) {
            printf("Terminating loop at %d using 'break'\n", j);
            break; /* Exits the for loop entirely */
        }
        printf("Processing iteration: %d\n", j);
    }

    return 0;
}
