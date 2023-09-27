#include <stdio.h>

// Define a custom type for an array of strings
typedef const char** Array_of_string;
typedef const char* String;

int main() {
  // Create an array of strings using the custom type
  Array_of_string strings = (const char*[]) {
    "Hello, World!",
    "This is a test.",
    "Goodbye, C programming!",
    NULL // Sentinel for the end of array
  };

  // Access and print the strings in the array
  for (int i = 0; strings[i] != NULL; i++) {
    printf("String 1.%d: %s\n", i + 1, strings[i]);
  }

  // Now with different semantics
  // Create an array of strings using the custom type
  const char* stringArray[] = {
    "Hello, World!",
    "This is a test.",
    "Goodbye, C programming!",
    NULL // Sentinel for the end of the array
  };

  // Assign the array to the custom type
  Array_of_string string_list = stringArray;

  // Access and print the strings in the array
  for (int i = 0; string_list[i] != NULL; i++) {
    printf("String 2.%d: %s\n", i + 1, string_list[i]);
  }

  // Third semantical String typedef
  String luff = "Luff";
  String zoro = "Zoro";
  String nami = "Nami";

  Array_of_string mugiwara_pirates = (const char*[]) {
    luff,
    zoro,
    nami,
    NULL // Sentinel for the end of the array
  };

  // Access and print the strings in the array
  for (int i = 0; mugiwara_pirates[i] != NULL; i++) {
    printf("String 3.%d: %s\n", i + 1, mugiwara_pirates[i]);
  }

  // So we can conver a char pointer array to a char pointer pointer
  // But we cannot do the opposite operation
  // Its like we can convert a char to type of any
  // But we cannot convert the type any to char

  return 0;
}
