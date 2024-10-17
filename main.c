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
    char valid;
} square_t;

typedef unsigned long long int square_count_t;

// Определение вершин квадрата по центру, размеру и углу поворота
square_t square_calc(square_t sq)
{
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
void points_in_circle(square_t *square, square_count_t square_count)
{
    for (square_count_t i = 0; i < square_count; i++)
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

// Функция проверки, пересечения квадратов
char square_intersection(square_t square_1, square_t square_2)
{
    double square_2_points[] = {square_2.x1, square_2.y1,
                                square_2.x2, square_2.y2,
                                square_2.x3, square_2.y3,
                                square_2.x4, square_2.y4};

    for (char i = 0; i < 4; i++)
    {
        // Перемещение точки в систему координат, где квадрат центрирован в начале координат
        double x_translocated = square_2_points[i] - square_1.x;
        double y_translocated = square_2_points[i+1] - square_1.y;

        double radians = square_1.theta * (M_PI / 180.0);

        // Обратное вращение точки на угол квадрата
        double rotatedX = x_translocated * cos(-radians) - y_translocated * sin(-radians);
        double rotatedY = x_translocated * sin(-radians) + y_translocated * cos(-radians);

        // Проверка, находится ли точка внутри неповернутого квадрата
        double halfSide = square_1.size / 2.0;
        if (fabs(rotatedX) < halfSide && fabs(rotatedY) < halfSide) {
            return 1;
        }
    }
    return 0;
}

// Функция проверки, пересечения квадратов
void square_validation(square_t *square, square_count_t square_count)
{
    double diag = sqrt(2)*square[1].size;
    for (square_count_t i = 0; i < square_count; i++)
    {
        // Скип, если квадрат находится за кругом
        // if (!square[i].in_circle)
        // {
        //     continue;
        // }
        
        for (square_count_t j = 0; j < square_count; j++)
        {
            // Скип, если квадрат находится за кругом
            // if (!square[j].in_circle)
            // {
            //     continue;
            // }

            // Установлен ли квадрат j
            if (square[j].valid)
            {
                // Способны ли квадраты i и j пересечься
                if (sqrt(pow(square[i].x - square[j].x, 2) + pow(square[i].y - square[j].y, 2)) < diag)
                {
                    //Пересекаются ли они?
                    if (square_intersection(square[i], square[j]) || square_intersection(square[j], square[i]))
                    {
                        break;
                    }
                }
            }

            // Если сравнили со всеми и пересечений не было, то устанавливаем квадрат
            if (j == square_count-1)
            {
                square[i].valid = 1;
            }

        }
    }
}

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
 