/*
 * Module: Performance Efficiency of a C Program
 * Description: Demonstrates how to measure code execution time, code optimization 
 *              techniques, and understanding algorithm efficiency.
 */

#include <stdio.h>
#include <time.h> /* Required for clock() and CLOCKS_PER_SEC */

/* Inefficient function: computes sum in O(N) time */
long long sum_iterative(long long n) {
    long long sum = 0;
    for (long long i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

/* Efficient function: computes sum in O(1) time using mathematical formula */
long long sum_formula(long long n) {
    return (n * (n + 1)) / 2;
}

int main() {
    long long n = 100000000; /* 100 Million */
    long long result;
    
    /* clock_t is a data type used to store processor time */
    clock_t start_time, end_time;
    double time_taken;

    printf("--- Performance Measurement ---\n");
    printf("Calculating sum of first %lld numbers...\n\n", n);

    /* 1. Measure Iterative Approach O(N) */
    start_time = clock(); /* Record start time */
    result = sum_iterative(n);
    end_time = clock(); /* Record end time */

    /* Calculate time in seconds */
    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("[Iterative O(N)] Result: %lld\n", result);
    printf("Time taken: %f seconds\n\n", time_taken);

    /* 2. Measure Mathematical Approach O(1) */
    start_time = clock();
    result = sum_formula(n);
    end_time = clock();

    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("[Formula O(1)]   Result: %lld\n", result);
    printf("Time taken: %f seconds\n", time_taken);

    /* 
     * Observations:
     * - The O(1) formula executes almost instantaneously regardless of the size of 'n'.
     * - The O(N) loop takes time proportional to 'n'.
     * 
     * Edge Case / Pitfall: 
     * In sum_formula, computing (n * (n+1)) can cause integer overflow if 'n' is very large.
     * Using appropriate data types (like long long) is crucial when dealing with 
     * large numbers, even in efficient algorithms.
     */

    return 0;
}
