#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    while (1) {
        // Compile and execute file2.c on each iteration
        system("gcc -o file2 file2.c");
        system("./file2");

       // Wait for some time (simulating a delay between reloads)
       // Adjust the duration based on your needs
       sleep(2);
   }

   return 0;
}
