#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char *human_readable_time (unsigned seconds, char *time_string)
{
  char s[] = "00:00:00";
  for(int i = 3; i >= 1; i--)
  {
      int j = (int) (seconds / (pow(60, i - 1) ) ) ;
      if(j > 0 && 
         ( j < 60 && (i == 2 || i == 1)
                    ||
           j < 99 && (i == 3)
         )
      )
      {
        char bfr[3];
        sprintf(bfr, "%d", j);
        s[8 - ((i * 2) + i < 3 ? i : 0) ] = j < 10 ? '0' :bfr[1];
        s[8 - ((i * 2)) ] =  bfr[0];   
      }
    
      seconds -= j * (pow(60, i - 1));
  }
  strcpy(time_string, s);
	return time_string; // return it
}



