#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>     

typedef unsigned un;
void spiralize (unsigned n, int spiral[n][n])
{
  // mutate the spiral[][] 2D-array
  int t, b, r ,l; 
  t = r = n; 
  b = l = 0;
  printf("%d \n", n);
  bool f = false;
  for (un y = 0; y < n * 5; y++){
    //if((i + 1)* 4 > n){break;}
    // lft 
    //if(b >= n/2 + 1){break;}
    for (int i = l; i < r; i ++){
      if(spiral[b + 1][i + 1] == 1){f = true; break;}
      spiral[b][i] = 1;
    }
    if(f){break;}
    if (y > 0){l += 2;}

    // top -> bot 
    for (int j = b; j < t; j ++){ spiral[j][r - 1] = 1;}
    
    // right -> left
    if((r - 1) - l < 2){break;}
    printf("%d/%d | ",l, r - 1);
    for (int k = r - 1; k > l - 1; k --){spiral[t - 1][k] = 1;}
    
    b+= 2;
    // bot -> top
    for (int v = t - 1; v > b - 1; v --){
       spiral[v][l] = 1;
    }
    r -= 2;
    t -=2;
  }
  //printf("b%d t%d // r%d l%d \n", b, t ,r ,l);
  for (un z = 0; z < n; z ++){ for(un s = 0; s < n; s ++){if(spiral[z][s] != 1){spiral[z][s] = 0;}}}
  if( n > 10){
    //for (un e = 0; e < n; e ++){if (spiral[n/2][e + 1] == 1){spiral[n/2][e] = 0;}}
  }
}