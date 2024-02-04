#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Hand {
    int rank; // 0 to 7 
    int value;
}Hand;
typedef enum { Win, Loss, Tie } Result;

// return value will be freed
Hand* PokerHand (const char *cards) {
  Hand* h = malloc(sizeof (struct Hand));
  h->rank = 0;
  printf("CARDS = ");
  int count_v = 1, count_indx = 0;
  int sm_values[16] = {0}, sm_characters[5]={0};
  int straight_v = 0, straight_ref = 0;
  // assign values
  for(size_t i = 0; i < strlen(cards); i++){
    if(cards[i] != ' '){
      if(count_v == 1){
        int conv = (cards[i] >= 65 ?
          10 + (
           (cards[i] - 64) == 20 ? 0: 0 // T(en)
            + (cards[i] - 64) == 10 ? 1: 0 // J(ack)
            + (cards[i] - 64) == 11 ? 2: 0 // K(ueen)
            + (cards[i] - 64) == 18 ? 3: 0 // Q(ueen)
            + (cards[i] - 64) == 1 ? 4 : 0 // A 
          ) : 
          cards[i] - '0'
        );

        sm_values[conv]++;
        h->value += conv;
        
        if( (straight_ref == (int)((cards[i] - '0') - 1) )
           || straight_ref == 0
          ){
          straight_v++;
          straight_ref = (int)(cards[i] - '0');
        }
      }else { sm_characters[count_indx] = (int)(cards[i]); count_indx++;}
      
      count_v = count_v == 1 ? 0 : 1;
      printf("%c", cards[i]); 
    }else { printf(" ");}
  }
  

  printf("\n");
  int strght_ = 0, k_combo = 0, combo = 0, tw_pair = 0, most_straight = 0,
    s_suit = 0;

  // values loop
  for(size_t j = 0; j < 16; j ++)
  {  
    if(combo == 5) break; 
    if(sm_values[j] == 1) {
      strght_++;
      if(strght_ > most_straight) most_straight = strght_;
    }else { strght_ = 0;}
    
    if(j > 10 && sm_values[j] > k_combo) k_combo = sm_values[j];
    if(sm_values[j] > combo) combo = sm_values[j];
    if(sm_values[j] == 2) tw_pair++;   
  }
  
  // characters loop
  int chr = 0;
  for(size_t k = 0; k < 5; k++)
  {
    if(chr == 0 || sm_characters[k] != chr){
        chr = sm_characters[k];
        s_suit = 1;
    }else{ s_suit++; }
  }
  
  // printf("STARTIGH? %d \n", straight_v);
  if(most_straight == 5 && s_suit == 5){ h->rank = 9; printf("STRAIGHT FLUSH // 9\n"); return h;
  }else if(combo == 4) { h->rank = 8; printf("FOUR OF A KIND // 8 \n");return h;
  }else if (k_combo == 3 && tw_pair == 1){h->rank = 7; printf("FULL HOUSE // 7 \n"); return h;
  }else if (s_suit == 5){h->rank = 6;printf("FLUSH // 6\n");return h;
  }else if(straight_v >= 4){h->rank = 5;printf("STRAIGHT // 5\n"); return h;
  }else if (combo == 3){ h-> rank = 4;printf("THREE OF A KIND // 4\n"); return h;
  }else if (tw_pair == 2){ h-> rank = 3; printf("TWO PAIRS// 3\n"); return h;
  }else if (tw_pair == 1){  h->rank = 2; printf("PAIR// 2\n"); return h;
  }else{ h-> rank = 1; printf("High card	// 1\n"); return h; }
  
  printf("\n");
  return h;
}

Result compare (Hand* player, Hand* opponent) {
  printf("\nPLAYER=>%d|%d   VS   ENEMY=>%d|%d \n \n", player->rank, player->value, opponent->rank, opponent->value);
  Result res;
  if( player->rank  > opponent->rank )return Win;
  else if(player->rank == opponent->rank) {
    if(player-> value == opponent->value) return Tie;
    else if (player-> value > opponent->value) return Win;
    else if (player-> value < opponent->value) return Loss;
  }
  else { return Loss; }
  return res;
}

