//
// Created by User on 24.10.2024.
//

#ifndef CALCULATIONS_H
#define CALCULATIONS_H
#include <math.h>

static double Taylor_sin(double radians, const double e)
{
    double delta = radians, sin = delta;
    int n = 1;
    do
    {
        delta *= -pow(radians, 2.0) / ((double)(n + 1) * (double)(n + 2));
        sin += delta;
        n += 2;
    }
    while (fabs(delta) > e);
    return sin;
}

static double Taylor_cos(double radians, const double e)
{
    double delta = 1.0, cos = delta;
    int n = 1;
    do
    {
        delta *= -pow(radians, 2.0) / (2.0 * (double)n * (2.0 * (double)n - 1.0));
        cos += delta;
        n++;
    }
    while (fabs(delta) > e);
    return cos;
}

#endif //CALCULATIONS_H
