#include <stdio.h>
#include <stdbool.h>

#define false 0
#define true 1

#define ELEMENT_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

#define foreach(item, array) \
  for (int i = 0, found = false; i < ELEMENT_SIZE(array) && !found; i++) \
    for (item = array[i], found = true; found; found = false)
      // It stops iterating when a condition (such as !found) becomes true

int main() {
  
  // Sum reaches untill 3
  int number_list[] = {1, 2, 3, 4, 5};
  int size = sizeof(number_list) / sizeof(number_list[0]);

  int sum = 0;
  int num;

  foreach(num, number_list) {
    sum += num;
    if (num == 3) {
      printf("Found 3, breaking the loop\n");
      break;
    } 
  }

  printf("Sum of numbers: %d\n", sum);

  return 0;
}
