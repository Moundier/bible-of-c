#include <stdio.h>

#define system_out_print printf
#define EXIT_SUCCESS 0

#define array_foreach(element, array) \
    unsigned int size = sizeof(array) / sizeof(array[0]); \
    for (unsigned int index = 0; index < size && (element = array[index], 1); index++)

#define string_foreach(element, collection) \
    for (element = collection; *element != '\0'; element++)

int main(int argc, char** argv) {

    unsigned int numbers[] = {1, 2, 3, 4, 5}, num = 0;

    array_foreach(num, numbers) {
      system_out_print("%d ", num);
    }

    system_out_print("\n");
    char* str = "Hello, World!", *ptr;

    string_foreach(ptr, str) {
      system_out_print("%c ", *ptr);
    }

    system_out_print("\n");

    return EXIT_SUCCESS;
}