#include <stdbool.h>
#include <stdio.h>
#include <string.h>
int search_substr(const char *full_text, const char *search_text, bool allow_overlap) {
    size_t l_ = strlen(full_text);
    unsigned long i_ = 0; int fnd = 0;
    const unsigned long x_ = strlen(search_text);
    bool skp_ = false;
    for(size_t i = 0; i < l_; i ++){
        skp_ = false;
        if(full_text[i] == search_text[i_]){
            i_++;
            skp_ = true;
            if(i_ == x_){
              fnd ++; i_ = 0;
              if(allow_overlap){i = i -  (strlen(search_text)/2) ;}
            }
        }else if (full_text[i] == search_text[0] && !skp_){
            i_= 1;
        }else{
            i_ = 0;
        }
    }
    //printf("%s => %s \n", search_text, full_text );
    return fnd;
}
