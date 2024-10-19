#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"


int main(void) {
    //srand(11);       //TODO: ДОПИЛИТЬ ВРЕМЯ

    double square_size = 0.1;
    square_count_t square_count = (int) (((1*1) / (square_size*square_size) ) * 1000);  // замостить квадрат 1x1 1000 раз квадратами размером size*size

    printf("All:%d\n",square_count);

    square_t *square;
    square = malloc(sizeof(square_t)*square_count);
    for (square_count_t i = 0; i < square_count; i++)
    {
        // генерация
        square[i].size   = square_size;
        square[i].x      = (rand() / (double)RAND_MAX) * 2.0 - 1.0;  //-1 - +1
        square[i].y      = (rand() / (double)RAND_MAX) * 2.0 - 1.0;  //-1 - +1
        square[i].theta  = (rand() / (double)RAND_MAX) * 0.5 * M_PI; //0  - PI/2

        square[i] = square_calc(square[i]);
        square[i].valid = 0;
    }

    points_in_circle(square, square_count);

    square_count_t in_circle_count = 0;
    for (square_count_t i = 0; i < square_count; i++)
    {
        if (1 == square[i].in_circle)
        {
            in_circle_count++;
        } 
    }

    printf("in_circle:%d\n",in_circle_count);
    printf("PI:%f\n\n", 4.0 * in_circle_count / square_count);

    square_validation(square, square_count);

    square_count_t valid_squers = 0;
    square_count_t valid_in_circle_squers = 0;
    for (square_count_t i = 0; i < square_count; i++)
    {
        if (1 == square[i].valid)
        {
            valid_squers++;
        }

        if ((1 == square[i].valid) && (1 == square[i].in_circle))
        {
            valid_in_circle_squers++;
        }

    }

    printf("valid_squers:%d\n", valid_in_circle_squers);
    printf("S:%f\n", (double)valid_in_circle_squers * (square_size*square_size));


    free(square);
    return 0;
}
 