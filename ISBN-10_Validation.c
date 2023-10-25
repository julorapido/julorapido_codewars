#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>  // <cstdlib> en C++

bool is_valid_ISBN_10 (const char *ISBN)
{
  int r = 0; size_t l = 10;
  if (strlen(ISBN) != l){return false;}
  for (size_t n = 0; n < strlen(ISBN); n++){
    if ( (!isdigit(ISBN[n]) && (strcmp(&ISBN[n], "X") != 0 ||  n != strlen(ISBN) - 1) )){return false;}
    int p = n + 1;int x = ISBN[n] - '0';
    r +=( strcmp(&ISBN[n], "X") == 0 ? 100 : x * p );
  }
  return (r % 11) == 0 ? true : false;
}