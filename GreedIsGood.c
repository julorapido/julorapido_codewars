#include <stdio.h>
#include <stdlib.h>

int score(const int dice[5]) {
    const int l_ = sizeof(*dice);
    int c_ = 0; int n_; int pts = 0;
    for (size_t i = 0; i < l_; i ++){
        printf("%d ", dice[i]);
        if( !(n_ == dice[i]) ){
            if(n_ == 1 || n_ == 5){pts += (n_ == 1 ? 100 * c_: 50 * c_);}
            n_ = dice[i];
            c_ = 1;
        }else{ c_ ++; if(c_ == 3){
            pts += (n_ == 1 ? 1000 : n_ * 100);
        }}
    }
    //  <----  hajime!
    printf(" \n %d ", pts);
    return pts;
}
