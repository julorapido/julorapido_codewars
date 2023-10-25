//  return the character with longest consecutive repetition
//  if the string is empty, return a null terminator: '\0'
//  assign the count of repetitions to the provided pointer *n

#include <stddef.h>
#include <stdio.h>
#include <string.h>
char longest_repetition(const char *s, size_t *n) {
  char l; int c = 0;
  struct a {int m; char l; }; struct a s1;
  s1.m = 0;
  for (size_t i = 0; i < strlen(s);i++){
    if(l != s[i]){l = s[i];c = 1;}else{
        c++;
    }
    if (c > s1.m){s1.m = c; s1.l = s[i];}
  }
  *n = s1.m;
  return (strlen(s) == 0 ? '\0' : s1.l);
}