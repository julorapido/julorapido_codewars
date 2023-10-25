#include <math.h>
#include <stdio.h>

// Returns number of complete beeramid levels
int beeramid(double bonus, double price) {
    int b_ = bonus - price;
    int r_ = 2;
    if(bonus < price){return 0;}
    while(b_ > price){
      int prc_ = (int)(pow(r_, 2)) * (int)(price);
      if( (b_ - prc_) >= 0 ){
        b_ -= prc_;
        r_ ++;
      }else{break;}
    };
    return r_ - 1;
}
