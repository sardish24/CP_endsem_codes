/*
 * Module: Dynamic Memory Allocation
 * Description: Demonstrates dynamic memory management using malloc, calloc, 
 *              realloc, and free, along with avoiding memory leaks.
 */

#include <stdio.h>
#include <stdlib.h> /* Required for memory allocation functions */

int main() {
    int n = 5;

    printf("--- malloc (Memory Allocation) ---\n");
    /* 
     * malloc allocates a single block of memory of the specified size.
     * It returns a void pointer (void*), which we cast to the desired type (int*).
     * The allocated memory contains garbage values.
     */
    int *malloc_ptr = (int *)malloc(n * sizeof(int));
    
    /* Edge Case: Memory allocation can fail if the heap is full */
    if (malloc_ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    /* Initialize and print */
    for (int i = 0; i < n; i++) {
        malloc_ptr[i] = i + 1;
        printf("%d ", malloc_ptr[i]);
    }
    printf("\n");

    printf("\n--- calloc (Contiguous Allocation) ---\n");
    /* 
     * calloc allocates memory for an array of elements.
     * Unlike malloc, calloc automatically initializes all allocated bytes to zero.
     */
    int *calloc_ptr = (int *)calloc(n, sizeof(int));
    if (calloc_ptr == NULL) {
        printf("Memory allocation failed!\n");
        free(malloc_ptr); /* Clean up previously allocated memory before exiting */
        return 1;
    }

    printf("calloc initializes memory to zero:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", calloc_ptr[i]);
    }
    printf("\n");

    printf("\n--- realloc (Re-allocation) ---\n");
    /* 
     * realloc resizes an existing dynamically allocated memory block.
     * If the new size is larger, it might move the block to a new location.
     * Existing data is preserved up to the lesser of the new and old sizes.
     */
    int new_n = 10;
    int *temp_ptr = (int *)realloc(malloc_ptr, new_n * sizeof(int));
    
    /* 
     * Pitfall: Always assign realloc to a temporary pointer first.
     * If realloc fails, it returns NULL, and assigning it directly to malloc_ptr
     * would overwrite the original pointer, causing a memory leak!
     */
    if (temp_ptr == NULL) {
        printf("Reallocation failed!\n");
        /* Original malloc_ptr is still valid, we should free it later */
    } else {
        malloc_ptr = temp_ptr; /* Safe to update the original pointer now */
        printf("Memory successfully reallocated to size %d.\n", new_n);
    }

    printf("\n--- free (Deallocation) ---\n");
    /* 
     * free() releases the dynamically allocated memory back to the heap.
     * Pitfall: Forgetting to free memory leads to 'Memory Leaks'.
     * Pitfall: Accessing a pointer after it has been freed leads to undefined behavior 
     * (Dangling Pointer).
     */
    free(malloc_ptr);
    free(calloc_ptr);
    
    /* Best practice: Set pointers to NULL after freeing to avoid dangling pointers */
    malloc_ptr = NULL;
    calloc_ptr = NULL;

    printf("Memory successfully freed.\n");

    return 0;
}
