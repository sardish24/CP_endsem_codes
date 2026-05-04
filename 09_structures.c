/*
 * Module: Structures and Unions
 * Description: Demonstrates defining and using structures to group related data, 
 *              array of structs, and unions for memory sharing.
 */

#include <stdio.h>
#include <string.h>

/* 
 * struct Definition
 * A struct groups variables of different data types under a single name.
 */
struct Student {
    int roll_no;
    char name[50];
    float marks;
};

/* 
 * typedef can be used to create an alias for the struct,
 * making it unnecessary to write 'struct' every time.
 */
typedef struct {
    int id;
    char title[100];
} Book;

/* 
 * union Definition
 * Unlike structs where each member has its own memory location,
 * a union allocates a single shared memory block for all its members.
 * The size of the union is the size of its largest member.
 */
union Data {
    int int_val;
    float float_val;
    char char_val[20];
};

int main() {
    printf("--- Structures ---\n");
    /* Structure initialization */
    struct Student s1 = {101, "Alice", 92.5};
    
    printf("Student %d: %s, Marks: %.2f\n", s1.roll_no, s1.name, s1.marks);

    /* Array of Structures */
    Book library[2];
    library[0].id = 1;
    strcpy(library[0].title, "C Programming Language");
    
    library[1].id = 2;
    strcpy(library[1].title, "Data Structures");

    printf("\n--- Array of Structs ---\n");
    for (int i = 0; i < 2; i++) {
        printf("Book %d: %s\n", library[i].id, library[i].title);
    }

    printf("\n--- Unions ---\n");
    union Data data;
    
    /* 
     * Pitfall: Accessing Union Members
     * You can only reliably access the member that was most recently written to,
     * because all members share the same memory location.
     */
    data.int_val = 42;
    printf("data.int_val: %d\n", data.int_val);
    
    data.float_val = 3.14; /* Overwrites the memory block */
    printf("data.float_val: %f\n", data.float_val);
    
    /* The integer value is now corrupted because memory was overwritten by the float */
    printf("data.int_val (corrupted): %d\n", data.int_val);

    return 0;
}
