#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double size;
    double x;
    double y;
    double theta;
    double x1;
    double y1;
    double x2;
    double y2;
    double x3;
    double y3;
    double x4;
    double y4;
} sqere_t;

sqere_t sqere_calc(sqere_t sq) {
    double degree2rad = M_PI / 180;
    double halfsize = sq.size / 2;
    double mul_halfsize_cos = halfsize * cos(sq.theta * degree2rad);
    double mul_halfsize_sin = halfsize * sin(sq.theta * degree2rad);
   
    sq.x1 = sq.x + mul_halfsize_cos - mul_halfsize_sin;
    sq.y1 = sq.y + mul_halfsize_sin + mul_halfsize_cos;
    
    sq.x2 = sq.x - mul_halfsize_cos - mul_halfsize_sin;
    sq.y2 = sq.y - mul_halfsize_sin + mul_halfsize_cos;
    
    sq.x3 = sq.x - mul_halfsize_cos + mul_halfsize_sin;
    sq.y3 = sq.y - mul_halfsize_sin - mul_halfsize_cos;
    
    sq.x4 = sq.x + mul_halfsize_cos + mul_halfsize_sin;
    sq.y4 = sq.y + mul_halfsize_sin - mul_halfsize_cos;

    return sq;
}

int main(void) {
    sqere_t sqere;
    sqere.size = 1;
    sqere.x = 0;
    sqere.y = 0;
    sqere.theta = 0;

    sqere = sqere_calc(sqere);

    printf("(%.4f, %.4f)\n", sqere.x1, sqere.y1);
    printf("(%.4f, %.4f)\n", sqere.x2, sqere.y2);
    printf("(%.4f, %.4f)\n", sqere.x3, sqere.y3);
    printf("(%.4f, %.4f)\n", sqere.x4, sqere.y4);

    return 0;
}