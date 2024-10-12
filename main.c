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
    sq.x1 = (sq.x + sq.size / 2.0) * cos(sq.theta);
    sq.y1 = (sq.y + sq.size / 2.0) * sin(sq.theta);

    sq.x2 = (sq.x + sq.size / 2.0) * cos(sq.theta);
    sq.y2 = (sq.y - sq.size / 2.0) * sin(sq.theta);

    sq.x3 = (sq.x - sq.size / 2.0) * cos(sq.theta);
    sq.y3 = (sq.y + sq.size / 2.0) * sin(sq.theta);

    sq.x4 = (sq.x - sq.size / 2.0) * cos(sq.theta);
    sq.y4 = (sq.y - sq.size / 2.0) * sin(sq.theta);

    return sq;
}

int main() {
    sqere_t sqere;
    sqere.size = 1;
    sqere.x = 0;
    sqere.y = 0;
    sqere.theta = 0;

    sqere = sqere_calc(sqere);

    printf("A: (%.2f; %.2f)\n", sqere.x1, sqere.y1);
    printf("B: (%.2f; %.2f)\n", sqere.x2, sqere.y2);
    printf("C: (%.2f; %.2f)\n", sqere.x3, sqere.y3);
    printf("D: (%.2f; %.2f)\n", sqere.x4, sqere.y4);

    return 0;
}