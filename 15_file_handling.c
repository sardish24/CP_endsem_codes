/*
 * Module: File Handling
 * Description: Demonstrates opening, reading, writing, and seeking operations 
 *              on a file, including proper error handling and resource cleanup.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    /* File Pointer Declaration */
    FILE *file_ptr;
    char filename[] = "data.txt";

    printf("--- File Writing (Mode: 'w') ---\n");
    /* 
     * fopen opens a file.
     * Mode "w" (Write): Creates a new file or truncates an existing one to zero length.
     */
    file_ptr = fopen(filename, "w");
    
    /* 
     * Edge Case: Always check if the file opened successfully.
     * It might fail due to insufficient permissions or invalid paths.
     */
    if (file_ptr == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }

    /* Write data to the file using fprintf (works like printf but for files) */
    fprintf(file_ptr, "Hello, File Handling in C!\n");
    fprintf(file_ptr, "Score: %d\n", 95);
    
    /* Always close the file to flush the buffer and release the system resource */
    fclose(file_ptr);
    printf("Data successfully written to %s.\n", filename);

    printf("\n--- File Reading (Mode: 'r') ---\n");
    /* 
     * Mode "r" (Read): Opens a file for reading. File must exist.
     */
    file_ptr = fopen(filename, "r");
    if (file_ptr == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    /* 
     * Reading data back using fscanf or fgets.
     * fgets reads a line up to a newline character or EOF.
     */
    char buffer[100];
    printf("Contents of %s:\n", filename);
    
    while (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {
        printf("%s", buffer);
    }

    /* 
     * File Positioning (Seeking)
     * fseek moves the file pointer to a specific location.
     * SEEK_SET (Beginning), SEEK_CUR (Current position), SEEK_END (End of file)
     */
    printf("\n--- File Seeking ---\n");
    fseek(file_ptr, 0, SEEK_END); /* Move pointer to the end of the file */
    
    /* ftell returns the current file pointer position (gives file size here) */
    long file_size = ftell(file_ptr);
    printf("Size of the file: %ld bytes\n", file_size);

    /* Clean up */
    fclose(file_ptr);

    /* 
     * Pitfall: Forgetting to close files causes memory leaks at the OS level
     * and might prevent other programs from modifying the file.
     */

    return 0;
}
