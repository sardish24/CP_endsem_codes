# C Programming Practice Codes

Welcome to the **C Programming Practice Codes** repository! This folder serves as a comprehensive, well-documented resource for mastering the C programming language.

## What Do These Codes Do?

This collection of C source files is designed to systematically walk you through the core concepts, syntax rules, and algorithms of C programming. Each file is a standalone, compilable program that isolates a specific topic. 

Instead of just showing "how" to write the code, these programs focus heavily on the "why". Every file is meticulously commented line-by-line to explain:
- **Standard Implementations**: The correct, modern way to use C features.
- **Under the Hood**: How memory is allocated, managed, and released.
- **Edge Cases & Pitfalls**: Common bugs, vulnerabilities (like buffer overflows or memory leaks), and how to avoid them safely.

## Why Should You Use This Folder?

1. **Self-Contained Learning**: You don't need to jump between a textbook and an IDE. The explanations are built right into the code.
2. **Sequential Progression**: The files are numbered logically. If you read them from `01` to `18`, you will naturally progress from basic syntax to advanced data structures and performance analysis.
3. **Reference Material**: Encountered a bug with pointers or forgot how `realloc()` works? Jump directly to the specific file for a quick refresher and safe usage patterns.
4. **Interview & Exam Prep**: By heavily focusing on edge cases, storage classes, and bounds checking, these files serve as excellent preparation for technical interviews and computer science exams.

---

## Index of Topics Covered

Below is the directory of all topics covered, corresponding to the files in this folder:

| File Name | Topic / Module | Key Concepts Covered |
| :--- | :--- | :--- |
| `01_basic_structure.c` | **Basic Execution** | `main()`, compilation, `printf`, `scanf`, standard I/O |
| `02_number_system_bitwise.c` | **Bitwise Operations** | `&`, `\|`, `^`, `~`, `<<`, `>>`, binary representation |
| `03_data_types_variables.c` | **Data Types & Variables**| Modifiers, memory limits, integer overflow, type casting |
| `04_branching.c` | **Control Flow (Branching)**| `if`, `else if`, `switch-case`, floating-point equality pitfalls |
| `05_looping.c` | **Control Flow (Looping)**| `for`, `while`, `do-while`, `break`, `continue` |
| `06_functions.c` | **Functions** | Declaration, definition, pass-by-value |
| `07_storage_classes.c` | **Storage Classes** | `auto`, `static`, `register`, `extern`, variable lifetime |
| `08_arrays.c` | **Arrays** | 1D/2D arrays, initialization, traversal, bounds checking |
| `09_structures.c` | **Structures & Unions** | Structs, nested structs, arrays of structs, unions |
| `10_pointers.c` | **Pointers** | Address-of (`&`), dereference (`*`), arithmetic, pass-by-reference |
| `11_dynamic_memory.c` | **Dynamic Memory** | `malloc`, `calloc`, `realloc`, `free`, preventing memory leaks |
| `12_singly_linked_list.c` | **Singly Linked Lists** | Node creation, insertion, traversal, memory cleanup |
| `13_doubly_linked_list.c` | **Doubly Linked Lists** | Prev/next pointers, bidirectional traversal |
| `14_string_operations.c` | **String Operations** | Char arrays, `string.h` (`strlen`, `strcmp`, `strcpy`, `strcat`), buffer overflows |
| `15_file_handling.c` | **File Handling** | `fopen`, `fclose`, `fprintf`, `fscanf`, `fseek`, `ftell` |
| `16_recursion.c` | **Recursion** | Factorial, Fibonacci, base cases, stack overflow considerations |
| `17_preprocessor.c` | **C Preprocessor** | `#define` macros, conditional compilation, macro side-effects |
| `18_performance.c` | **Performance Efficiency**| Measuring execution time with `clock()`, `O(N)` vs `O(1)` comparisons |

## How to Run

To run any of these files, you need a standard C compiler (like GCC). Open your terminal in this directory and run:

```bash
gcc 01_basic_structure.c -o program
./program
```
*(On Windows, the executable will be `program.exe`)*
