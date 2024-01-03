#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef long long int int_l;
char *multiply (const char *a, const char *b){
    bool a_b = strlen(a) >= strlen(b) ? true : false;
    const char* selected = a_b ? a : b;
    const char* n_selected = a_b ? b : a;
    size_t bfr_len = a_b ? strlen(a) : strlen(b);
    size_t j_len = a_b ? strlen(b) : strlen(a);
    char* ref = (char*) calloc( (int) (2 * bfr_len), sizeof(char));
    int_l rest_, sum = 0;
    printf("a:%s b:%s \n", a,b);
    // loop smallest
    for(int i = j_len- 1, c = 0; i > -1; i--, c++)
    {
      char* bfr = (char*) calloc( (int) (bfr_len + c), sizeof(char));
      int n = (int)(bfr_len - 1);
      // fill end with 0 [FROM (bfr_len + c) TO n]
      if(c > 0){
        for(int z = n; z <= (bfr_len + c )- 1; z++)
          bfr[z] = '0';
      }
      // loop inside biggest
      for(int j = bfr_len - 1; j >= 0; j--, n--)
      {
        int m = ((n_selected[i] - 48) * ((selected[j] - 48))) + rest_;
        printf("%c x (%c+%d) = %d \n", n_selected[i] , selected[j], rest_, m);
        rest_ = (int)m/10;  
        bfr[n] = (m%10) + '0';
        // realloc
        if(j == 0 && rest_ > 0){
          char * temp = (char *) malloc( strlen(bfr) );
          strcpy( temp, bfr );
          bfr = (char *) realloc( bfr, (bfr_len + c + 1) * sizeof(char) );
          bfr[0] = rest_ + '0';
          for(int w = 0; w < strlen(temp); w ++){
            bfr[w + 1] = temp[w];
          }
          printf("realloc %s ==> %s \n", temp, bfr);
        }
      }
      sum += atoll(bfr);
      // ref[i] = (r>9 ? r-(m/10) : r) +'0';
      printf("=> %d \n", atoi(bfr));
      printf("--------------- \n");
    }
    printf("??? %d \n ", sum);
    return ref;
}

