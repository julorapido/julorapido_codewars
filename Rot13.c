#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char *rot13(const char *src)
{
    printf("%s %lu ", src, strlen(src));
    char r[strlen(src)];
    for(unsigned long i = 0; i < strlen(src); i ++)
    {
      if(isalpha(src[i]) != 0)
      {
        int s = isupper(src[i]) == 0 ? 97 : 65; 
        int c = ( (int)src[i] + 13) >= (s + 26) ? 
          s + (( (int)src[i] + 13) - (s + 26)) : ( (int)src[i] + 13)
        ;    
        r[i] = (char)(c);
      }else
      { r[i] = src[i]; }
    }
    char* p = (char*) calloc(strlen(src), sizeof(char*));
    for(unsigned long a = 0; a < strlen(src); a ++)
        p[a] = r[a];

    printf("%s  \n", p);
    return p;
}
