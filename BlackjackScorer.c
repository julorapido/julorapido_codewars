#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int score_hand(size_t n, const char cards[n]) {
    //  <----  hajime!
    int r = 0, asses = 0;
    for(size_t i = 0; i < n; i ++){
        if(cards[i] == 'J' || cards[i] == 'K' || cards[i] == 'Q' || cards[i] == 'T'){
            r+= 10;
        }else{
          if(cards[i] == 'A') asses++;
          else r += cards[i] - '0'; 
        }
    }
    for(size_t j = 0; j < (size_t)asses; j ++)
      r += ( r <= 10 ? ( (asses > 1) && (r+11 == 21) ? 1 : 11) : 1);

    return r;
}


