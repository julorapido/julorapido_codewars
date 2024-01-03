// oof
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *add(const char *a, const char *b) {
    bool w = strlen(a) > strlen(b) ? true : false;
    size_t bfr_len =  w ? strlen(a) : strlen(b), j_len = w ? strlen(b) : strlen(a);
    char *ref = (char*) malloc(bfr_len*sizeof(char));
    for(size_t b = 0; b < bfr_len; b++)
        ref[b] = '0';
      
    ref[bfr_len] = '\0';
    printf("a=%s  b=%s \n", a, b);
    // printf("buffer: %s bfr_len: %zu \n", ref, bfr_len);
    //  <----  hajime!
    int next_ = 0;
    for(int i = bfr_len > 1 ? bfr_len - 1 : 1, 
        j = bfr_len > 1 ? (j_len - 1) : 1; i > -1; i--, j--)
    {
      int o;
      if(j < 0) // default placement
      { 
        int x = (w ? a[i] : b[i]) - 48;
        int c = x + next_;
        ref[i] = (c>9 ? c-10 : c) +'0';
        printf("[] %d + %d = %d  \n", x, next_, c);   
        next_ = c / 10;
        o = c;
      } else {
        int i_ = bfr_len > 1 ? i : 0; 
        
        int d =  w ? (a[i_] - 48) + (b[bfr_len > 1 ? j : 0] - 48) :
          (b[i_] - 48) + (a[bfr_len > 1 ? j : 0] - 48);
        int c = d + next_;
        printf("%d + %d + %d = %d \n",
           w ? a[i_]-48 : a[j]-48, 
           w ? b[j]-48 : b[i_]-48, next_, c
        );  
        next_ = d > 9 ? d/10 : 0;
        printf("next? %d %d \n", next_, d);
        if(c == 10) next_ = 1;
        // assign
        ref[i_] = (c>9 ? c-10 : c) +'0';
        o = d;
      }
      // handle overflow 
      if(i == 0 && o > 9)
      {
        char *temp = (char*) malloc(bfr_len*sizeof(char));
        strcpy(temp, ref);
        ref = (char*) realloc( ref, (bfr_len + 1)*sizeof(char));
        for(size_t z = 0; z < bfr_len; z++){
            ref[z + 1] = temp[z];
        }
        ref[0] = '1';
      }
    }

   printf("%s \n \n", ref);
   return ref;
}
