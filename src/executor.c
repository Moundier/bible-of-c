#include <stdlib.h>
#include <stdio.h>

#define STATUS_SUCCESSFUL 0

void ensureCompiled(int compileStatus) {
  if (compileStatus == 0) {
    printf("Compilation successful.\n");
  } else {
    printf("Compilation failed with exit code %d.\n", compileStatus);
  }
}

void ensureExecuted(int executeStatus) {
  if (executeStatus == 0) {
    printf("Execution successful.\n");
  } else {
    printf("Execution failed with exit code %d.\n", executeStatus);
  }
}

int main() {
  const char *compiler = "gcc -o foreach foreach.c";  // Compile file2.c
  const char *executor = "./foreach";  // Execute the compiled file2

  // Compile file2.c
  int compileStatus = system(compiler);
  int executeStatus;

  ensureCompiled(compileStatus);  // Ensure Compilation

  if (compileStatus == STATUS_SUCCESSFUL) {
    executeStatus = system(executor);
  }

  if (executeStatus == STATUS_SUCCESSFUL) {
    ensureExecuted(executeStatus);  // Ensure Execution
  }

  return 0;
}
