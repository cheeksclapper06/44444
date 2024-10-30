//
// Created by User on 24.10.2024.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <math.h>
#include <conio.h>
#include "validations.h"


static int dx_val(const int x1, const int x2)
{
    int dx = 0;
    do
    {
        dx = validate_floating_value("Enter dx (step):");
        if (x1 != x2 && dx == 0)
        {
            setTextColor(12);
            printf("The step can't be equal to 0 when x1 != x2\n");
            setTextColor(7);
            fflush(stdin);
        }
        else if (x1 < x2 && dx < 0)
        {
            setTextColor(12);
            printf("The step can't be less than 0 when x1 < x2\n");
            setTextColor(7);
            fflush(stdin);
        }
        else if (x1 > x2 && dx > 0)
        {
            setTextColor(12);
            printf("The step can't be greater than 0 when x1 > x2\n");
            setTextColor(7);
            fflush(stdin);
        }
    }
    while ((x1 != x2 && dx == 0) || (x1 < x2 && dx < 0) || (x1 > x2 && dx > 0));
    return dx;
}

static double get_accuracy()
{
    int accuracy = 0;
    double e = 0;
    do
    {
        printf("Choose the type to enter accuracy (e):\n");
        printf("If the option doesn't lay in one of three categories the section will restart\n");
        printf("1. Decimal places\n");
        printf("2. Real number\n");
        printf("3. Exponential form\n");

        accuracy = getch();
        while (getchar() != '\n' && getchar() != EOF);

        switch (accuracy)
        {
            case 49:
                int decimal = 0;
                decimal = validate_integer_accuracy("Enter the number of decimal places:");
                e = pow(10, -decimal);
                printf("\nIn exponential form the accuracy is %e\n", e);
                break;

            case 50:
                e = validate_floating_accuracy("Enter accuracy as a real number (e.g. 0.001):", "Invalid Input, enter an exponential number greater than zero");
                printf("In exponential form the accuracy is %e\n", e);
                break;

            case 51:
                e = validate_floating_accuracy("Enter accuracy as an exponential number (e.g. 1e-3):", "Invalid Input, enter a real number greater than zero");
                printf("Enter accuracy as an exponential number (e.g. 1e-3):\n");
                printf("The accuracy is %e\n", e);
                break;

            default:
                setTextColor(12);
                printf("Invalid option, please enter a given number (1 - 3)\n");
                setTextColor(7);
            }
        }
    while (accuracy < 49 || accuracy > 51);
    return e;
}

double degrees_to_radians(double x)
{
    double radians = 0;
    radians = x * (M_PI / 180.0);
    return radians;
}


#endif //FUNCTIONS_H
