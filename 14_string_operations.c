/*
 * Module: String Operations
 * Description: Demonstrates strings as character arrays, null termination, 
 *              and standard string library functions (strlen, strcpy, strcat, strcmp).
 */

#include <stdio.h>
#include <string.h> /* Required for standard string functions */

int main() {
    /* 
     * Strings in C are arrays of characters terminated by a null character '\0'.
     * The compiler automatically appends '\0' when using string literals.
     */
    char str1[50] = "Hello";
    char str2[] = "World";
    
    printf("--- String Basics ---\n");
    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);

    /* 
     * 1. strlen (String Length)
     * Returns the length of the string, EXCLUDING the null terminator.
     * Pitfall: Do not confuse strlen() with sizeof(). sizeof(str1) is 50.
     */
    printf("\n--- strlen ---\n");
    printf("Length of str1: %zu\n", strlen(str1));
    printf("Size of str1 array in memory: %zu bytes\n", sizeof(str1));

    /* 
     * 2. strcat (String Concatenation)
     * Appends the source string to the destination string.
     * Edge Case: The destination array must be large enough to hold the combined 
     * string plus the null terminator. If not, it causes a buffer overflow.
     */
    printf("\n--- strcat ---\n");
    strcat(str1, " "); /* Append a space */
    strcat(str1, str2); /* Append str2 */
    printf("Concatenated String (str1): %s\n", str1);

    /* 
     * 3. strcpy (String Copy)
     * Copies the source string to the destination.
     * Overwrites whatever was previously in the destination.
     */
    printf("\n--- strcpy ---\n");
    char destination[50];
    strcpy(destination, str1);
    printf("Copied String (destination): %s\n", destination);

    /* 
     * 4. strcmp (String Comparison)
     * Compares two strings character by character (case-sensitive).
     * Returns 0 if identical, <0 if strA comes before strB, >0 otherwise.
     */
    printf("\n--- strcmp ---\n");
    char apple[] = "apple";
    char banana[] = "banana";
    char apple2[] = "apple";

    printf("strcmp('apple', 'banana'): %d\n", strcmp(apple, banana));
    printf("strcmp('apple', 'apple'): %d\n", strcmp(apple, apple2));

    /* 
     * Pitfall: Buffer Overflow with unsafe functions
     * Functions like strcpy and strcat are unsafe because they don't check bounds.
     * Consider using strncpy and strncat in production environments.
     */

    return 0;
}
