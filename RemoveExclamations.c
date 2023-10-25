// Write resulting string into buffer pointed by str_out
#include <stdio.h>
#include <string.h>

void remove_exclamation_marks(const char *str_in, char *str_out) {
  char src[] = "";
  for (int i = 0; i < strlen(str_in); i++){
    char c = &str_in[i] + "0";
      if (strncmp(c, "!", 1) != 0){
        strcat(src, str_in[i]);
      }
  }
  str_out = src;
}