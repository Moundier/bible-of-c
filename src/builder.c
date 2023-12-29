#include <stdio.h>
#include <ctype.h>

// Define a function type that takes a string as an argument
typedef void (*StringFunction)(const char*);

// Define a struct that includes a string and two function pointers
typedef struct {
    const char* data;
    StringFunction func1;
    StringFunction func2;
} MyStruct;

// Example functions that can be used with the struct
void printString(const char* str) {
    printf("Printing: %s\n", str);
}

void uppercaseString(const char* str) {
    printf("Uppercase: ");
    while (*str) {
        putchar(toupper(*str));
        str++;
    }
    putchar('\n');
}

void lowercaseString(const char* str) {
    printf("Lowercase: ");
    while (*str) {
        putchar(tolower(*str));
        str++;
    }
    putchar('\n');
}

MyStruct MyStructBuilder(const char* data, StringFunction func1, StringFunction func2) {
    
    MyStruct myInstance = {
        .data = data,
        .func1 = func1,
        .func2 = func2
    };

    myInstance.func1(myInstance.data); // Call the functions directly within the struct initialization
    myInstance.func2(myInstance.data);

    return myInstance;
}

int main() {
    
    MyStruct myInstance = MyStructBuilder(
        "Hello, World!", 
        printString, // pointer to function
        uppercaseString // pointer to function
    );

    return 0;
}
