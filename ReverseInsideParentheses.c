#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define t 0

char * reverse_in_parens(const char *text)
{
  char *m = (char *) malloc(
      strlen(text) * sizeof(char) 
  );
  int b[2];
  int e = 0, c = 1;
  memcpy(m, text, strlen(text) );
  printf("%s len:%d \n", text, strlen(text));
  for(size_t i = 0; i < strlen(text); i ++)
  {   
    if( ((int) text[i] ) == 40 && e == 0) // "("
    {  b[0] = i; e++; } 
    if( ( (int) text[i] ) == 41) b[1] = i; // ")" 
  }
  
  // printf("Strt %d End %d bfrSize %d\n", b[0], b[1], (b[1] - b[0]) + 1);
  char bfr[ (b[1] - b[0]) + 1];
  e = 0;
  for(int j = b[0] + 1; j < b[1]; j ++) // boundaries
  {   
    printf("%d ", c);
    if( ( (int)text[(b[1] - (c + 1)) + 1] ) == 41 // )
      && e == 0)
    {
      size_t p_s = 0; int cc = 0;
      for(size_t k = 0; k < strlen(text)/2; k++)
      {
        if( (int)text[((b[1] - (c + 1)) + 1) - k] == 40){ // (
          p_s = k - 1;
          break;
        }
      }
      for(size_t l = p_s ; l <= (b[1] - (c + 1)) + 1; l++)
      {
        bfr[c + cc] = text[l];
        cc++;
      }
      j +=cc;
    }
    else { 
      bfr[c] = text[(b[1] - (c + 1)) + 1];
      c++;
    }
  }
  bfr[0] = '(';  bfr[(b[1] - b[0])] = ')';
  bfr[ ((b[1] - b[0])) + 2] = '\0';
  printf("reversed buffer %s \n", bfr);
  for(size_t z = 0; z < strlen(bfr); z ++)
  {
      *(m + (z + b[0]) ) = bfr[z];
  }
  printf("%s len:%d \n \n", m, strlen(m));
  text = m;
  if(e == 0 && 1 == 0) return reverse_in_parens(m);
  return m;
}


