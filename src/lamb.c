#include <stdio.h>

// Macro create a function pointer
#define DEFINE_FUNCTION(returnType, name, parameters, expression) \
	returnType name parameters { return expression; } \

DEFINE_FUNCTION(int, square, (int x), (x * x));

// Define a macro to apply a function to each element in the array
#define FOR_EACH(array, size, function) \
	for (size_t i = 0; i < size; ++i) { \
		printf("%d\n", function(array[i])); \
	}

int main(int argc, char** argv) {

	int numbers[] = {1,2,3,4,5};
	int size = sizeof(numbers) / sizeof(numbers[0]);
	FOR_EACH(numbers, size, square);
	return 0;
}