#include <stdio.h>

/* Passing by value, or passing by address */

void f(int* i) {
	printf("Pointer address: %p\n", i);
	printf("Size of pointer: %zu\n", sizeof(i));
}

void g(int i) {
	printf("Pointer address: %p\n", i);
	printf("Size of pointer: %zu\n", sizeof(i));
}

int main(int argc, char** argv) {

	int i;

	f(i); // Value
	g(&i); // Address

	return 0;
}
