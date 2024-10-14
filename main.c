#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double size;    // Длина ребра
    double x, y;    // координаты центра
    double theta;   // угол поворота
    double x1, y1;  // координаты вершин
    double x2, y2;
    double x3, y3;
    double x4, y4;
    char in_circle;
} square_t;

// Определение вершин квадрата по центру, размеру и углу поворота
square_t square_calc(square_t sq) {
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

// Функция проверки, попадания вершины в круг
void points_in_circle(square_t *square, int square_count) {
    for (long int i = 0; i < square_count; i++)
    {
        double r1 = sqrt((square[i].x1 * square[i].x1) + (square[i].y1 * square[i].y1));
        double r2 = sqrt((square[i].x2 * square[i].x2) + (square[i].y2 * square[i].y2));
        double r3 = sqrt((square[i].x3 * square[i].x3) + (square[i].y3 * square[i].y3));
        double r4 = sqrt((square[i].x4 * square[i].x4) + (square[i].y4 * square[i].y4));
        
        if ((r1 <= 1) && (r2 <= 1) && (r3 <= 1) && (r4 <= 1))
        {
            square[i].in_circle = 1;
        }
        else
        {
            square[i].in_circle = 0;
        }
    }
}

int main(void) {
    //srand(11);       //TODO: ДОПИЛИТЬ ВРЕМЯ

    double square_size = 0.0025;
    long int square_count = (int) (((1*1) / (square_size*square_size) ) * 1000);  // замостить квадрат 1x1 1000 раз квадратами размером size*size

    printf("All:%d\n",square_count);

    square_t *square;
    square = malloc(sizeof(square_t)*square_count);
    for (long int i = 0; i < square_count; i++)
    {
        // генерация
        square[i].size   = square_size;
        square[i].x      = (rand() / (double)RAND_MAX) * 2.0 - 1.0;  //-1 - +1
        square[i].y      = (rand() / (double)RAND_MAX) * 2.0 - 1.0;  //-1 - +1
        square[i].theta  = (rand() / (double)RAND_MAX) * 0.5 * M_PI; //0  - PI/2

        square[i] = square_calc(square[i]);
    }

    points_in_circle(square, square_count);

    long int in_circle_count = 0;
    for (long int i = 0; i < square_count; i++)
    {
        if (1 == square[i].in_circle)
        {
            in_circle_count++;
        } 
    }


    printf("in_circle:%d\n",in_circle_count);
    printf("PI:%f\n", 4.0 * in_circle_count / square_count);


    free(square);
    return 0;
}
 