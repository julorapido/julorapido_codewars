#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>


int seconds_parser(int s, int dvd_, bool mult_){
    int calculated_dividor =  (pow(60, dvd_ > 2 ? 2 : dvd_) 
    * (dvd_ >= 3 ? 24: 1)  * (dvd_ == 4 ? 365 : 1) );
    return (
      (!mult_) ?
      (int) ( s / calculated_dividor)
        :
      (int) (s * calculated_dividor)
    );
}

char *formatDuration (int n) {
  printf("//  SECONDS %d   // \n", n);
  char* rr = calloc(60, sizeof(char));
  if(n == 0){ strcpy(rr, "now"); return rr;}

  int c = 0;
  for(int i = 4; i >= 0; i --){
    int j = seconds_parser(n, i, false);
    //int j = (int) (n / (pow(60, i > 2 ? 2 : i) * (i >= 3 ? 24: 1)  * (i == 4 ? 365 : 1) ));
    if(j > 0){
      char p[4];
      char *e = malloc(16 * sizeof(char));
      switch(i){
          case 0: e = "second"; break; case 1: e = "minute"; break;
          case 2: e = "hour"; break; case 3: e = "day"; break;
          case 4: e = "year"; break; 
      }
      sprintf(p ,"%d", j);
    	char dest[strlen(e) + strlen(p)];
      dest[0] = '\0'; // empty string
      strcat(dest, p); strcat(dest, " "); strcat(dest, e);
      if(j > 1) strcat(dest,"s");
      
      if(c > 0){ strcat(rr, " ");}
      strcat(rr, dest);
      c++;
      
       n -= seconds_parser(j, i, true);
      // n -= j * pow(60, i);
      
      if(n > 0 ){ //rest
         int z = n, ecart = 0;
         for(int k = i - 1; k >= 0; k --){
            int r_ = (int) (z / pow(60, k) );
            if(r_ > 0) ecart++;
            z -= r_ * pow(60, k);
         }
         if(ecart > 0) strcat(rr, ecart > 1 ? "," : " and");
      }
    }
  }

  return rr;
}


