#ifndef FUNCTIONS_H
#define FUNCTIONS_H

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

square_t square_calc(square_t sq);
void points_in_circle(square_t *square, square_count_t square_count);
char square_intersection(square_t square_1, square_t square_2);
void square_validation(square_t *square, square_count_t square_count);

#endif //FUNCTIONS_H