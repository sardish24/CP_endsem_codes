/*
 * Module: Arrays in C
 * Description: Demonstrates 1D and 2D arrays, initialization, traversal, 
 *              and passing arrays to functions.
 */

#include <stdio.h>

/* 
 * Arrays decay to pointers when passed to functions.
 * Thus, the size of the array is lost. We must explicitly pass the size.
 */
void printArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    printf("--- 1D Array ---\n");
    /* 
     * Array Declaration and Initialization
     * An array is a contiguous block of memory. 
     * The compiler deduces the size if elements are provided during initialization.
     */
    int numbers[] = {10, 20, 30, 40, 50};
    
    /* Calculate size dynamically */
    int size = sizeof(numbers) / sizeof(numbers[0]);
    printArray(numbers, size);

    /* 
     * Pitfall: Array Out of Bounds
     * C does not perform bounds checking. Accessing elements past the end 
     * of the array leads to undefined behavior (reading/writing garbage data or crashing).
     * Example (Uncommenting this is dangerous!): 
     * printf("%d\n", numbers[10]); 
     */

    printf("\n--- 2D Array ---\n");
    /* 
     * 2D Arrays (Matrix)
     * Initialized as an array of arrays. 
     */
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    /* Traversal of 2D array requires nested loops */
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 3; col++) {
            printf("matrix[%d][%d] = %d\n", row, col, matrix[row][col]);
        }
    }

    /* 
     * Edge Case: Partial Initialization
     * If an array is partially initialized, the remaining elements are set to 0.
     */
    int partial_array[5] = {1, 2}; /* Result: {1, 2, 0, 0, 0} */
    printf("\nPartial Array Initialization: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", partial_array[i]);
    }
    printf("\n");

    return 0;
}
