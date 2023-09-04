#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_LEN 7

int main(void) {
  int myArr[ARR_LEN] = {8, 2, 9, 6, 4, 5, 9};

  for (int i = 0; i < ARR_LEN; i++) {
    for (int j = 0; j < ARR_LEN - 1 - i; j++) {
      if (myArr[j] > myArr[j + 1]) {
        int itemToSwap = myArr[j];
        myArr[j] = myArr[j + 1];
        myArr[j + 1] = itemToSwap;
      }
    }
  }
  for (int i = 0; i < ARR_LEN; i++) {
    printf("%d ", myArr[i]);
  }
  return 0;
}