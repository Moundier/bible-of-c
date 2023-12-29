#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

enum DataType {
	TYPE_INTEGER = 1,
	TYPE_FLOAT = 2,
	TYPE_STRING = 3,
};

typedef struct Object {
	enum DataType type;
} Object;

typedef struct {
	struct Object base;  // Inherit from the Object blueprint
	int data;            // Integer data
} Integer;

typedef struct {
	struct Object base;  // Inherit from the Object blueprint
	float data;          // Float data
} Float;

typedef struct {
	struct Object base;  // Inherit from the Object blueprint
	char* data;          // String data
} String;

Integer* initializeInteger(int initialValue) {
	Integer* obj = (Integer*)malloc(sizeof(Integer));
	if (obj != NULL) {
		obj->base.type = TYPE_INTEGER;
		obj->data = initialValue;
	}
	return obj;
}

Float* initializeFloat(float initialValue) {
	Float* obj = (Float*)malloc(sizeof(Float));
	if (obj != NULL) {
		obj->base.type = TYPE_FLOAT;
		obj->data = initialValue;
	}
	return obj;
}

String* initializeString(const char* initialValue) {
	String* obj = (String*)malloc(sizeof(String));
	if (obj != NULL) {
		obj->base.type = TYPE_STRING;
		obj->data = strdup(initialValue); // string duplicate
	}
	return obj;
}

bool compare(Object* o1, Object* o2) {
	return (o1->type == o2->type);
}

int main() {

	Integer* integer = initializeInteger(42);
	Float* a_decimal = initializeFloat(3.14f);
	Float* b_decimal = initializeFloat(2.23f);
	String* string = initializeString("Hello, World!");

	if (compare((Object*)integer, (Object*)a_decimal)) {
		printf("Ojects are of the same type.\n");
	}

	if (compare((Object*)a_decimal, (Object*)b_decimal)) {
		printf("Objects are of the same type.\n");
	}

	// Create a heap for efficient memory deallocation.
	// Array of pointers, to be released, in single call.
	free(integer);
	free(a_decimal);
	free(b_decimal);
	free(string->data);
	free(string);

	return 0;
}
