//
// Created by User on 24.10.2024.
//

#ifndef FUNCTION_H
#define FUNCTION_H
#include <math.h>
#include <conio.h>
#include <stdbool.h>
#include "validation.h"


static int dx_val(const int x1, const int x2)
{
    bool InvalidInput;
    int dx = 0;
    do
    {
        dx = validate_integer_step_value("Enter dx (step):");
        if (x1 != x2 && dx == 0)
        {
            setTextColor(12);
            printf("The step can't be equal to 0 when x1 is not equal to x2\n");
            setTextColor(7);
            fflush(stdin);
            InvalidInput = true;
        }
        else
            if (x1 < x2 && (dx <= 0 || dx > x2 - x1))
            {
                setTextColor(12);
                printf("The step can't be less than 0 or equal to it when x1 < x2\nOtherwise please write the step according to a given limit");
                setTextColor(7);
                fflush(stdin);
                InvalidInput = true;
            }
        else
            if (x1 > x2 && (dx >= 0 || dx > x1 - x2))
            {
                setTextColor(12);
                printf("The step can't be greater than 0 or equal to it when x1 > x2\nOtherwise please write the step according to a given limit\n");
                setTextColor(7);
                fflush(stdin);
                InvalidInput = true;
            }
        else
        {
            fflush(stdin);
            InvalidInput = false;
        }
    }
    while (InvalidInput);
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
        while (getchar() != '\n');

        switch (accuracy)
        {
            case 49:
                e = pow(10, -validate_integer_accuracy("Enter the number of decimal places:\n"
                                                    "The input range is [1 - 15]\n"));
                printf("In exponential form the accuracy is: ");
                setTextColor(2);
                printf("%e\n", e);
                setTextColor(7);
                break;

            case 50:
                e = validate_floating_accuracy("Enter accuracy as a real number (e.g. 0.001)\n"
                                               "The input range is [0.000000000000001 - 0.1]", "Invalid input, pLease enter a real value in given range");
                printf("In exponential form the accuracy is: ");
                setTextColor(2);
                printf("%e\n", e);
                setTextColor(7);
                break;

            case 51:
                e = validate_floating_accuracy("Enter accuracy as an exponential number (e.g. 1e-3):\n"
                                               "The input range is [1e-5 - 1e-1]", "Invalid input, pLease enter an exponential value in given range");
                printf("The accuracy is: ");
                setTextColor(2);
                printf("%e\n", e);
                setTextColor(7);
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

static double degrees_to_radians(double x)
{
    double radians = 0;
    radians = x * (M_PI / 180.0);
    return radians;
}


#endif //FUNCTION_H
