#include <stdio.h>
#include <conio.h>
#include "functions.h"
#include "calculations.h"
#include "validations.h"

#define MAX_SIZE 100

int main()
{
    int x1 = 0, x2 = 0, dx = 0;
    double e = 0, x = 0;
    double x_values[MAX_SIZE], taylor_values[MAX_SIZE], functions_values[MAX_SIZE], differences[MAX_SIZE];
    int count = 0;
    const char*  header1 = 0;
    const char*  header2 = 0;
    do
    {
        setTextColor(2);
        printf("This program calculates taylor series of sine/cosine, it's table value by standard functions, and their difference\n");
        setTextColor(7);
        count = 0;
        header1 = NULL;
        header2 = NULL;

        x1 = validate_integer_value("Enter x1 (degrees):");
        x2 = validate_integer_value("Enter x2 (degrees):");

        dx = dx_val(x1, x2);
        e = get_accuracy();

        int choice = 0;
        do
        {
            printf("What do you want to calculate?\n");
            printf("1. Cosine\n");
            printf("2. Sine\n");
            choice = getch();
            if (choice != 49 && choice != 50)
            {
                printf("You can only choose between numbers 1 and 2\n");
                fflush(stdin);
            }
        }
        while (choice != 49 && choice != 50);

        for (x = (double)x1; x <= (double)x2 && count < MAX_SIZE; x += (double)dx)
        {
            double taylor_series = 0, functions_result = 0;
            const double radians = degrees_to_radians(x);
            if (choice == 49)
            {
                header1 = "Taylor series cosine";
                header2 = "Functions cosine";
                functions_result = cos(radians);
                taylor_series = Taylor_cos(radians, e);
            }
            else if (choice == 50)
            {
                header1 = "Taylor series sine";
                header2 = "Functions sine";
                functions_result = sin(radians);
                taylor_series = Taylor_sin(radians, e);
            }
            x_values[count] = x;
            taylor_values[count] = taylor_series;
            functions_values[count] = functions_result;
            differences[count] = functions_result - taylor_series;
            count++;
        }
        printf("\n|   x (degrees)   |   %s   |   %s   |   Difference   |\n", header1, header2);
        printf("-------------------------------------------------------------------------------------\n");

        for (int i = 0; i < count; i++)
        {
            printf("| %e | %e | %e | %e |\n",
                   x_values[i], taylor_values[i], functions_values[i], differences[i]);
        }
        setTextColor(2);
        printf("To restart the program press ENTER, otherwise press any key to exit\n");
        setTextColor(7);
    }
    while(getch() == 13);
    return 0;
}
