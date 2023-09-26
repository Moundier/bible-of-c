# bible-of-c

### Abstract
Just a collection of code, bundled together.

### Objectives

- [ ] Item 1: A program that retrieves object entries (but now identified with unique id)
- [x] Item 2: foreach loop
- [ ] Item 3 (checked)
- [ ] Item 4

```c
#include <stdio.h>

// Define a structure to associate a name with a pointer and an ID
typedef struct {
    const char* name;
    int* pointer;
    int id;
} VarInfo;

int main() {
    int var1 = 42;
    int var2 = 123;

    // Create an array of VarInfo to associate names, pointers, and IDs
    VariableInfo variables[] = {
        {"var1", &var1, 1},
        {"var2", &var2, 2}
    };

    // Access variable values by name or ID through the array
    for (int i = 0; i < sizeof(variables) / sizeof(variables[0]); i++) {
        printf(
            "Name: %s, ID: %d, Value: %d\n", 
            variables[i].name, variables[i].id, *(variables[i].pointer));
    }

    return 0;
}
```

### Made with
* The C Programming language
* The GCC Compiler

### In memory of
- Terry Davis
