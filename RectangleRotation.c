#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define angle 45 
#define PI 3.14159265359 

typedef long long l_l;

struct Point{
    int x;
    int y;
}; typedef struct Point pnt;

// rect area from triangle method
float rectArea_wTriange(pnt A, pnt B, pnt C)
{
    float s = (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / 2;
    return fabs(s);
}
      
long long rectangle_rotation(int a, int b)
{
    // initial rectangle
    pnt A, B, C, D;
    A.x = -a / 2; A.y = b / 2;   B.x = a / 2; B.y = b / 2;
    C.x = a / 2; C.y = -b / 2;   D.x = -a / 2; D.y = -b / 2;
    
    printf("%d %d \n", a, b);
    pnt rect[4] = {A, B, C, D};
    double rad = angle * PI / 180;
  
    pnt rotated_rect[4];
    for(int i = 0; i < 4; i ++)
    {
        pnt r;
        r.x = (rect[i].x * rad - rect[i].y * rad);
        r.y = (rect[i].x * rad + rect[i].y * rad);
        rotated_rect[i] = r;
    }
    int xA, yB, xC, yD;
    xA = rotated_rect[0].x; yB = rotated_rect[1].y;
    xC = rotated_rect[2].x; yD = rotated_rect[3].y;
    
    int c = 0;
    for (float xx = round(xA); xx <  round(xC) + 1; xx += 0.1f)
    {
        for (float yy = round(yD); yy < round(yB) + 1; yy += 0.1f)
        {
            pnt aa; aa.x = xx; aa.y = yy;
            float area1 = rectArea_wTriange(rotated_rect[0], rotated_rect[1], aa); 
            float area2 = rectArea_wTriange(rotated_rect[1], rotated_rect[2], aa);
            float area3 = rectArea_wTriange(rotated_rect[2], rotated_rect[3], aa); 
            float area4 = rectArea_wTriange(rotated_rect[3], rotated_rect[0], aa);
            
            if ((fabs(area1 + area2 + area3 + area4) - (a * b) ) < 1e-10 )
            {c ++;}
                
        }
    }
    printf("%d", c);
    return c; // Do your magic!
}
