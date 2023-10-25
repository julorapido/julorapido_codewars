#include <stdlib.h>

// Returned array must be freeable.
//
// *count is an in/out parameter. It contains the size of arr on input,
// and should be set to the lenght of returned array upon return.
//
// When input is invalid, the function should return NULL and set *count to 0.

int *up_array(const int *arr, unsigned *count)
{
    int r = 0; int p[*count];
    for (int i = 0; i < *count; i++){
      printf("%d", arr[i]);
      if (arr[i] < 0 || arr[i] > 9){return NULL;}
      r = r *10 + arr[i];
    }
    r = r + 1;
    printf("\n %d", r);
    int w = *count;
    for (int x = 0; x < *count; x++){
      p[x] = r % 10;
      r /= 10;
    }
    
    return p;
}