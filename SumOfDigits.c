#include <stdio.h>
#include <stdlib.h>

int digital_root(int n) {
  // .....
  if (n < 10){return n;}
  int num; int len = 0;
  char str[50];
  num= n;
   while (num != 0){
        len++;
        num /= 10;
  }

  int x = n; int res = 0;
  for (int i = 0; i <= len; i++){
      printf("x : %d \n", x % 10);
        res += x % 10;
      x = x / 10;
  }
  return digital_root(res);
}