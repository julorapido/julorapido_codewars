#include <stdio.h>
#include <stdlib.h>

int solution(int number) {
    int n=number;
    int s=0;
    if(n<=2)return 0; if(n==2)return 1;
    for(int i=1; i<n; i++){
      if(i%3==0 || i%5==0) {
         s += i;
      }
    }
		//  <----  hajime!
   // return s == 1 ? 0 : s;
  return s;
}
