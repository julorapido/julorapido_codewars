#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef long long lg_;
lg_ numPlaces (lg_ n) {
    lg_ r = 1;
    if (n < 0) n = -n;
    while (n > 9) {
        n /= 10;
        r++;
    }
    return r;
}

long long next_bigger_number(long long n) {
    lg_ ln = numPlaces(n); lg_ alr[(int) (pow(ln, 2)) ];  
    
    // ref arr
    lg_ rf[ln];
    //for (lg_ o=0;o<ln;o++){
    //  rf[o] = n / (int)(pow(10, ln-o));
    //}

    char temp[ln];
    sprintf((char*)temp,"%lld",n);
    for(int i =0; i<ln; i++)
        rf[i] = temp[i];
        //printf("%c",temp[i]);
    
    // swap by indx [i] => [j]
    int v = 0; // valids nmbrs
    for (lg_ i = 0; i < ln; i ++){
       lg_ p_a[ln];
       for (lg_ j = i; j < ln; j ++){
          lg_ k = 0; //swap on k=z
          for (lg_ z = 0; z < ln; z ++){
              if(z == k){p_a[z] = rf[i]; p_a[z + 1] = rf[z];
                z++;
              }else{
                p_a[z] = rf[z];
              }
          }
          k++;
       }
        for(lg_ x = 0; x < ln; x ++){
          printf("%lld", p_a[x]);
        }
        printf("\n");
       for(lg_ k = 0; k < (int) (pow(ln, 2)); k++){
         //if(alr[k] == p_a){break;}
       }
       //alr[v] = p_a;
       v++;
    }
    return 21; //insert code here
}
