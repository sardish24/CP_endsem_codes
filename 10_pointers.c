/*
 * Module: Pointers in C
 * Description: Demonstrates pointer declaration, memory addresses, dereferencing, 
 *              pointer arithmetic, passing by reference, and pointers to pointers.
 */

#include <stdio.h>

/* 
 * Pass by Reference (using Pointers)
 * Instead of passing copies of values, we pass memory addresses.
 * This allows the function to modify the original variables.
 */
void swap(int *a, int *b) {
    int temp = *a; /* Dereference a to get the value */
    *a = *b;       /* Dereference b and assign it to location pointed by a */
    *b = temp;     /* Assign temp to location pointed by b */
}

int main() {
    int num = 10;
    
    /* 
     * Pointer Declaration and Initialization
     * 'ptr' is a pointer to an integer. It stores the address of 'num'.
     * '&' is the Address-of operator.
     */
    int *ptr = &num;

    printf("--- Pointer Basics ---\n");
    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", (void*)&num);
    printf("Value stored in ptr: %p\n", (void*)ptr);
    
    /* 
     * Dereferencing
     * '*' is the Dereference operator. It accesses the value at the pointer's address.
     */
    printf("Value pointed to by ptr (*ptr): %d\n", *ptr);
    
    /* Modifying value via pointer */
    *ptr = 20;
    printf("New value of num after *ptr = 20: %d\n", num);

    printf("\n--- Pass by Reference (Swap) ---\n");
    int x = 5, y = 15;
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y); /* Pass memory addresses */
    printf("After swap: x = %d, y = %d\n", x, y);

    printf("\n--- Pointer Arithmetic ---\n");
    /* 
     * Pointers are incremented by the size of the data type they point to.
     * If an int is 4 bytes, ptr++ increments the address by 4 bytes.
     */
    int arr[] = {100, 200, 300};
    int *arr_ptr = arr; /* Array name 'arr' acts as a pointer to its first element */

    printf("arr_ptr pointing to: %d\n", *arr_ptr);
    arr_ptr++; /* Moves to the next integer in the array */
    printf("arr_ptr after increment: %d\n", *arr_ptr);

    printf("\n--- Pointer to Pointer ---\n");
    /* 
     * A pointer can store the address of another pointer.
     */
    int **double_ptr = &ptr;
    printf("Value of num using double_ptr (**double_ptr): %d\n", **double_ptr);

    /* 
     * Pitfall: Uninitialized (Wild) Pointers
     * Declaring a pointer without initializing it causes it to point to a random memory location.
     * Dereferencing it will cause a segmentation fault.
     * Always initialize to NULL if not assigning an immediate address.
     */
    int *safe_ptr = NULL; 
    if (safe_ptr != NULL) {
        printf("%d\n", *safe_ptr);
    } else {
        printf("safe_ptr is securely checked for NULL.\n");
    }

    return 0;
}
