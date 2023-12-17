#include <stdio.h>
#include <stdlib.h>

struct Exception {
  int type;
};

struct Exception* exception_info = NULL;

typedef void (*ExceptionHandler)(struct Exception*);

void handle_exception(struct Exception* exception) {
  printf("Exception caught: Type %d\n", exception->type);
  free(exception_info);
  exception_info == NULL;
  exit(1); // Finish before "core dumped" compiler message
}

// Insert the function into the function pointer
ExceptionHandler exception_handler = handle_exception; 

int found_exception() {
  return (exception_info == NULL) ? 0 : 1;
}

#define TRY \
  { \
    struct Exception exception; \
    if (found_exception() == 0) 

#define CATCH(exception_type) \
    else if (exception_info->type == exception_type)

#define END_TRY \
    free(exception_info); \
    exception_info = NULL; \
  }

#define THROW(exception_type) \
  do { \
    exception_info = (struct Exception*) malloc(sizeof(struct Exception)); \
    if (!exception_info) { \
      fprintf(stderr, "Failed to allocate memory for exception_info\n"); \
      exit(1); \
    } \
    exception_info->type = exception_type; \
    if (exception_handler != NULL) { \
      exception_handler(exception_info); \
    } \
  } while (0)

int main() {

  TRY {
    int divisor = 0;

    if (divisor == 0) {
      THROW(1);
    }

    int result = 10 / divisor;
    printf("Result: %d\n", result);
  }
  CATCH(1) {
    printf("Caught divide by zero exception\n");
  }
  END_TRY;

  return 0;
}
