#include <stddef.h>

void move_zeros(size_t len, int arr[len])
{
  for (int i = 0; i < len; i ++){
      if (arr[i] == 0){
          int sw = 0;
          for (int p = i; p < i + (len - i); p++){
            if (arr[p] != 0){sw = p;break;}
          } 
          if (sw > 0){
            int value = arr[sw];
            arr[i] = value; arr[sw] = 0;
          }
      }
  }
    // mutate arr in place
}