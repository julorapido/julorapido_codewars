#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef uint64_t u_64;

u_64 onePowr(u_64 n, char bin[])
{
    u_64 s = 0, r = n;
    int one = 0;

    int max = strlen(bin);
    for (int i = 0; i < max; i++)
    {
        if (bin[i] == '1')
        {
            one++;
            r = r - pow(2, max - i - 1);
            s = s + pow(2, (max - 1) - i - 1) * (max - i - 1) + r;
        }
    }
    return s + one;
}

uint64_t countOnes ( uint64_t left, uint64_t right )
{
  printf("%lu %lu \n", left, right);
  char p[2][20];
  int s[2];
  for(int i = 0; i < 2; i ++)
  {
      u_64 b = (i == 0 ? left : right);
      u_64 a = 0;
      while(b >= 1)
      {
        strcpy(&p[i][a], (b % 2 == 1 ? "1" : "0"));
        b /= 2;
        a++;
      }
      p[i][a] = '\0';
      int x = 0; char ref[20];
      strcpy(ref, p[i]);
      for (int j = a - 1; j >= 0; j--)
      {
        memcpy(&p[i][x], &ref[j], 1);
        x++;
      }

      s[i] = onePowr(
        (i == 0 ? (left - 1) : right)
        ,p[i]
      ); 
  }
  printf("%d", s[0]);
  printf(" %d", s[1]);
  u_64 m = s[1] - s[0];
  printf(" %d ", m); 
	return m + 1;
}


