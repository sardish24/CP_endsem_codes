/*
 * Module: Recursion
 * Description: Demonstrates recursive functions, understanding base cases,
 *              call stacks, and potential pitfalls like stack overflow.
 */

#include <stdio.h>

/* 
 * Recursive function to calculate Factorial
 * n! = n * (n-1)!
 */
unsigned long long factorial(int n) {
    /* 
     * Base Case: The condition that stops the recursion.
     * Without a base case, the function calls itself infinitely,
     * leading to a "Stack Overflow" error.
     */
    if (n == 0 || n == 1) {
        return 1;
    }
    
    /* Recursive Step */
    return n * factorial(n - 1);
}

/* 
 * Recursive function to find the nth Fibonacci number
 * fib(n) = fib(n-1) + fib(n-2)
 * Pitfall: Naive recursive Fibonacci is highly inefficient O(2^n) 
 * because it recalculates the same values multiple times.
 */
int fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int num = 5;

    printf("--- Recursion: Factorial ---\n");
    /* 
     * Edge Case: Factorials grow extremely fast. 
     * Even 'unsigned long long' overflows relatively quickly (around 20!).
     */
    printf("Factorial of %d is %llu\n", num, factorial(num));

    printf("\n--- Recursion: Fibonacci ---\n");
    printf("First 10 Fibonacci numbers:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}
