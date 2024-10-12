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

double degreesToRadians(double degrees) {
    return degrees * M_PI / 180;
}

sqere_t sqere_calc(sqere_t sq) {
    double cos_theta = cos(sq.theta * M_PI / 180);
    double sin_theta = sin(sq.theta * M_PI / 180);
    double diag = sq.size / 2;
   
    sq.x1 = sq.x + diag * cos_theta - diag * sin_theta;
    sq.y1 = sq.y + diag * sin_theta + diag * cos_theta;
    
    sq.x2 = sq.x - diag * cos_theta - diag * sin_theta;
    sq.y2 = sq.y - diag * sin_theta + diag * cos_theta;
    
    sq.x3 = sq.x - diag * cos_theta + diag * sin_theta;
    sq.y3 = sq.y - diag * sin_theta - diag * cos_theta;
    
    sq.x4 = sq.x + diag * cos_theta + diag * sin_theta;
    sq.y4 = sq.y + diag * sin_theta - diag * cos_theta;

    return sq;
}

int main(void) {
    sqere_t sqere;
    sqere.size = 1;
    sqere.x = 0;
    sqere.y = 0;
    sqere.theta = 45;

    sqere = sqere_calc(sqere);

    printf("(%.4f, %.4f)\n", sqere.x1, sqere.y1);
    printf("(%.4f, %.4f)\n", sqere.x2, sqere.y2);
    printf("(%.4f, %.4f)\n", sqere.x3, sqere.y3);
    printf("(%.4f, %.4f)\n", sqere.x4, sqere.y4);

    return 0;
}