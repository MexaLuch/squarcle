#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"

void disp_sq(square_t square){
    printf("x: %3.1f; y:%3.1f\n", square.x, square.y);
    printf("Crl: %d; Val:%d\n", square.in_circle, square.valid);
}

int main(void) {
    
    //TEST 1
    square_count_t sq_count = 3;
    square_count_t sq_in_circlr = 3;
    square_count_t sq_valid = 3;

    square_t *square_test_1;
    square_test_1 = malloc(sizeof(square_t)*sq_count);

    square_test_1[0].size   = 0.1;
    square_test_1[0].x      = -0.1;
    square_test_1[0].y      = 0.1;
    square_test_1[0].theta  = 0;
    square_test_1[0] = square_calc(square_test_1[0]);
    square_test_1[0].valid = 0;

    square_test_1[1].size   = 0.1;
    square_test_1[1].x      = 0.1;
    square_test_1[1].y      = 0;
    square_test_1[1].theta  = 0;
    square_test_1[1] = square_calc(square_test_1[1]);
    square_test_1[1].valid = 0;

    square_test_1[2].size   = 0.1;
    square_test_1[2].x      = 0;
    square_test_1[2].y      = 0.5;
    square_test_1[2].theta  = 0;
    square_test_1[2] = square_calc(square_test_1[2]);
    square_test_1[2].valid  = 0;

    points_in_circle(square_test_1, sq_count);
    square_validation(square_test_1, sq_count);

    square_count_t in_c_squers = 0;
    square_count_t valid_squers = 0;

    for (square_count_t i = 0; i < sq_count; i++)
    {
        if (1 == square_test_1[i].in_circle)
        {
            in_c_squers++;
        }

        if (1 == square_test_1[i].valid)
        {
            valid_squers++;
        }

    }

    if ((in_c_squers == sq_in_circlr) && (valid_squers == sq_valid))
    {
        printf("TEST 1: PASS\n");
    }
    else
    {
        printf("TEST 1: FAILD (%d,%d)\n",in_c_squers,valid_squers);
        disp_sq(square_test_1[1]);
    }
    
    free(square_test_1);

    return 0;
}

 