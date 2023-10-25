#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *sort_children (char *str_out, const char *str_in)
{
// write to str_out and return it
  strcpy(str_out, str_in);
  int p = strlen(str_in);
  for(int i = 0 ;i < p - 1; i ++ ){
    for (int j = i + 1; j < p; j++){
     		if (tolower(str_out[i]) > tolower(str_out[j]) ){
       			char r = str_out[i];
       			str_out[i] = str_out[j]; str_out[j] = r;
     		}
        if (tolower(str_out[i]) == tolower(str_out[j]) ){
            if(str_out[i] > str_out[j]){
                char z = str_out[i];
       			    str_out[i] = str_out[j]; str_out[j] = z;
            }
        }
    }
  }
	return str_out;
}