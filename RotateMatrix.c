#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

enum direction {CLOCKWISE, COUNTER_CLOCKWISE};

void rotate (size_t rows, size_t cols, const int matrix[rows][cols], enum direction direction, int rotated[cols][rows])
{
  // fill the rotated[][] matrix
	if (rows && cols)

    if(direction == CLOCKWISE)
    {
      // rotated[rows/2][cols/2] = matrix[1][1];
      for(int t = 0; t <= 2; t += 2){
        for(int i = 0; i < 2; i ++){
          for(int j = 0; j <= 2; j ++)
          {
            if(i == 0)
              rotated[t < 1 ? 0 : 2][(t<1) ? j: (2-j)] = matrix[(t<1)? (2-j):j][(t<1)?0:2];
            else
              rotated[t<1 ? j : 2-j][t<1 ? 2 :0] = matrix[t<1 ? 0:2][t<1 ? j : 2-j];
          }
        }
      }
    }
      rotated[1][1] = matrix[1][1];

}



