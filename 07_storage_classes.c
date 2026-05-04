/*
 * Module: Scope and Storage Classes
 * Description: Demonstrates the visibility (scope) and lifetime (storage class)
 *              of variables using auto, static, extern, and register.
 */

#include <stdio.h>

/* 
 * Global Variable (External Scope)
 * Accessible throughout the entire program (and across files if 'extern' is used).
 * Initialized to 0 by default.
 */
int global_var = 100;

/* 
 * Function prototype
 */
void demonstrateStorageClasses(void);

int main() {
    printf("--- Storage Classes Example ---\n");
    printf("Global variable: %d\n\n", global_var);

    /* Calling the function multiple times to observe 'static' behavior */
    for (int i = 0; i < 3; i++) {
        demonstrateStorageClasses();
    }

    return 0;
}

void demonstrateStorageClasses(void) {
    /* 
     * 1. auto (Automatic Storage Class)
     * Default for local variables. Created when the block is entered, 
     * destroyed when exited. Contains garbage value if not initialized.
     */
    auto int auto_var = 10; 
    /* The 'auto' keyword is optional and rarely used explicitly. */

    /* 
     * 2. static (Static Storage Class)
     * Initialized only ONCE. Retains its value across multiple function calls.
     * Visibility is limited to this function, but lifetime is the entire program duration.
     * Edge case: Initialized to 0 by default if no explicit value is given.
     */
    static int static_var = 10;

    /* 
     * 3. register (Register Storage Class)
     * Hints the compiler to store the variable in a CPU register for faster access.
     * Pitfall: We cannot use the address-of operator (&) on a register variable 
     * because it may not be stored in RAM.
     */
    register int register_var = 10;

    printf("Call:\n");
    printf("  auto_var     = %d (destroyed after this call)\n", auto_var);
    printf("  static_var   = %d (retained for next call)\n", static_var);
    printf("  register_var = %d\n\n", register_var);

    /* Modify the variables */
    auto_var++;
    static_var++;
    register_var++;
}
