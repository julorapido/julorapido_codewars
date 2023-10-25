
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
bool alphanumeric(const char* strin) {
    size_t l = strlen(strin); bool r_ = true;
    //printf("%s => \n", strin);
    if(strcmp(&strin[0], "") == 0){return false;}
    for(size_t i = 0; i < l; i ++){
        char ch = strin[i];
        if(ch == '\0' ) break;
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')|| (ch >= '0' && ch <= '9')){
        }else{
          r_ = false;
          break;
        }
    }
    // <----hajime!
  return r_;
}
