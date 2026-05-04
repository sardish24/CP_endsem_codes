/*
 * Module: Control Flow - Branching
 * Description: Demonstrates conditional execution using if, else if, else, 
 *              and switch statements.
 */

#include <stdio.h>

int main() {
    int score = 85;

    printf("--- if, else if, else Statement ---\n");
    /* 
     * The if-else ladder allows evaluating multiple mutually exclusive conditions.
     * Execution jumps to the first block where the condition evaluates to true (non-zero).
     */
    if (score >= 90) {
        printf("Score %d: Grade A\n", score);
    } else if (score >= 80) {
        printf("Score %d: Grade B\n", score);
    } else if (score >= 70) {
        printf("Score %d: Grade C\n", score);
    } else {
        printf("Score %d: Fail\n", score);
    }

    /* 
     * --- Switch Statement ---
     * switch is used for matching a variable against a series of integer or char constants.
     * It is generally faster and more readable than multiple if-else blocks for equality checks.
     */
    char grade = 'B';
    printf("\n--- Switch Statement ---\n");

    switch (grade) {
        case 'A':
            printf("Excellent performance!\n");
            break; /* break prevents 'fall-through' to the next case */
        case 'B':
        case 'C':
            /* 
             * Edge Case / Feature: Fall-through
             * By omitting the break statement, case 'B' flows directly into case 'C'.
             * This allows grouping logic for multiple matching cases.
             */
            printf("Good performance. (Handles both B and C)\n");
            break;
        case 'D':
            printf("Needs improvement.\n");
            break;
        default:
            /* 
             * default executes if no cases match. 
             * It's a best practice to always include a default case to handle unexpected values.
             */
            printf("Invalid grade.\n");
    }

    /* 
     * Pitfall: Floating Point Equality
     * Never compare floating point numbers directly using '==' because of precision issues.
     */
    float val = 0.1f;
    float sum = 0.0f;
    for(int i=0; i<10; i++) sum += val;
    
    printf("\n--- Pitfall: Float Equality ---\n");
    /* sum should theoretically be 1.0, but might be 1.0000001 depending on precision */
    if (sum == 1.0f) {
        printf("sum is exactly 1.0\n");
    } else {
        printf("sum is not exactly 1.0 (it is %f)\n", sum);
    }

    return 0;
}
