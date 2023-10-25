#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>     

typedef struct { unsigned *pixels; unsigned width, height; } Image;
typedef struct { unsigned *values; unsigned size; } unsigned_array;

unsigned_array central_pixels(Image image, unsigned colour)
{
    // size_t p = sizeof(image.pixels);
    unsigned top, l, bot, r;
    top = l = bot = r = 0;
  
    for(size_t w = 0 ; w < image.width; w ++)
    {
      if(image.pixels[w] == colour)
      {top++;}
      if(image.pixels[ (image.width * (image.height - 1)) + w] == colour)
      {bot++;}

      if(w == 0 || w == (image.width - 1) )
      {
        for(size_t h = 0; h < image.height; h ++)
        {
          if( image.pixels[ (image.width * h) + w]  == colour)
          {
              if(w == 0) l ++;
              else r ++;
          }
        } 
      }
    }
    // printf("top:%d lft:%d bot:%d rght:%d \n", top, l, bot, r);
    
    unsigned zone_wdth = l>=r ? l:r;  unsigned zone_height = top>=bot ? top:bot;
  
    unsigned x = l >= r ? (l/2) - 1 : (r/2) - 1;
    unsigned y = top >= bot ? top/2 : bot/2;
    // int c =  (x) + (image.width * y);
    // printf("x:%d y:%d => %d \n", x, y, c);

    const int precision = 2;
    int max_depth = 0;
  
    //points buffer
    unsigned points_buffer[precision * 4];
    int new_assign = 0;
    for(int yy = y - precision; yy <= (int)y + precision; yy ++)
    {  
      // printf("\n y%d \n", yy);
      for(int xx = x - precision; xx <= (int)x + precision; xx ++)
      {
        int max_xDepth, max_yDepth;
        max_xDepth = max_yDepth = INT_MAX;
        int x_indx, y_indx;
        
        // printf("x%d ", xx);
        // x depth
        for(int d_x = 0; d_x < (int)zone_wdth/2 + 1; d_x ++)
        {    
            //+x 
            unsigned x_plus = image.pixels[( image.width * yy) + (xx + d_x)] ;
            //-x
            unsigned x_minus = image.pixels[(image.width * yy) + (xx - d_x)] ;
          
            // +x step on another color (or +-x step outside)
            if((x_plus != colour) || (x_minus != colour)
                || (xx - d_x) < 0  || (xx + d_x >= (int)image.width ) )
            { 
              if(d_x < max_xDepth) max_xDepth = d_x; 
              
              //save x indexes
              if((xx - d_x) < 0 ) x_indx =  (image.width * yy);
              if(xx + d_x >= (int)image.width ) x_indx = (int)image.width;
              if(x_plus != colour || x_minus != colour) x_indx = (image.width * yy) + (xx);
            }
           
        }
        // printf("|x->%d ", max_xDepth);
        
        
        // y depth
        for(int d_y = 0; d_y < (int)zone_height/2 +1 ; d_y ++)
        {    
            //y_down
            unsigned y_down = image.pixels[( image.width * (yy + d_y) ) + xx];
            //y_up
            unsigned y_up = (yy-d_y < 0) ? colour : image.pixels[( image.width * (yy - d_y) ) + xx] ;
          
    
            // +y step on another color (or +-y step outside)
            if(  (yy - d_y) < 0 || (yy + d_y) > image.height ||
              (y_up != colour) || (y_down != colour)
              ){ 
              if(d_y < max_yDepth) max_yDepth = d_y;
              
              //save y indexes
              if(y_up != colour || y_down != colour) y_indx = ( image.width * (yy) ) + xx;
              if((yy - d_y) < 0) y_indx =  xx; // top 
              if((yy - d_y) < 0) y_indx = (image.width * image.height) + xx; // bot 
            }
           
        }
        
        
        // printf(" |y->%d ", max_yDepth);
        
        int final_depth = max_xDepth < max_yDepth ? max_xDepth : max_yDepth;
        int final_point = max_xDepth < max_yDepth ? x_indx : y_indx;

        // new max depth point assignation
        if(final_depth > max_depth)
        {
          for(int b = 0; b < precision * 3; b ++){ points_buffer[b] = 0;}
          points_buffer[0] = final_point;
          new_assign = 1;
          max_depth = final_depth;
        }
        // push point assignation
        else if (final_depth == max_depth)
        {
          points_buffer[new_assign] = final_point;
          new_assign++;
        }
        
        // printf("finalDepth %d \n", final_depth);
        
        
      }
    }
    printf("points%d index%d ", new_assign, points_buffer[0]);
    unsigned_array a;
    a.size = new_assign;
    a.values = points_buffer;
    printf("%d", a.values[0]);
    return a;
}
