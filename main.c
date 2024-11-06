#include <stdio.h>
#include <conio.h>
#include "function.h"
#include "calculation.h"
#include "validation.h"

int main()
{
    int x1 = 0, x2 = 0, dx = 0;
    int count = 0;
    double x = 0, e = 0;
    const char*  header1 = 0;
    const char*  header2 = 0;
    const char*  header3 = 0;
    const char*  header4 = 0;
    do
    {
        printf("This program calculates taylor series of sine/cosine, it's table value by standard functions, and their difference\n");
        count = 0;
        header1 = NULL;
        header2 = NULL;
        header3 = NULL;
        header4 = NULL;

        bool InvalidInput;
        do
        {

            x1 = validate_integer_limits_value("Enter x1 (degrees in range [-360, 360]):");
            x2 = validate_integer_limits_value("Enter x2 (degrees in range [-360, 360]):");
            InvalidInput = x1 == x2
                    ? (setTextColor(12), printf("The values can't be equal. Otherwise the program will break\n"), setTextColor(7), fflush(stdin), true)
                    : false;
        }
        while(InvalidInput);
            x1 > x2
                    ? (printf("The step can't be higher than: "), setTextColor(2), printf("%d\n", x1 - x2), setTextColor(7))
                        : (printf("The step can't be higher than: "), setTextColor(2), printf("%d\n", x2 - x1), setTextColor(7));

        dx = dx_val(x1, x2);

        const int size = (x2 - x1) / dx + 1;
        double x_values[size], taylor_values[size], table_value[size], differences[size];

        e = get_accuracy();

        int choice;
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

        header1 = "x (degrees)";
        header4 = "Difference";

        x = x1;
        do
        {
            double taylor_series = 0, functions_result = 0;
            const double radians = degrees_to_radians(x);
            if (choice == 49)
            {
                header2 = "Taylor series cosine";
                header3 = "Table cosine";
                functions_result = cos(radians);
                taylor_series = Taylor_cos(radians, e);
            }
            else
                if (choice == 50)
            {
                header2 = "Taylor series sine";
                header3 = "Table sine";
                functions_result = sin(radians);
                taylor_series = Taylor_sin(radians, e);
            }
            x_values[count] = x;
            taylor_values[count] = taylor_series;
            table_value[count] = functions_result;
            differences[count] = functions_result - taylor_series;
            count++;
            x += (double)dx;
        }
        while (dx > 0 && x <= x2 || dx < 0 && x >= x2 && count < size);
        printf("\n|   %-15s   |   %-20s   |   %-20s   |   %-20s|\n", header1, header2, header3, header4);
        printf("-----------------------------------------------------------------------------------------------------\n");


        for (int i = 0; i < count; i++)
        {
            printf("|   %-15.2f   |   %-20e   |   %-20e   |   %-20e|\n",
                   x_values[i], taylor_values[i], table_value[i], differences[i]);
        }
        setTextColor(2);
        printf("To restart the program press ENTER, otherwise press any key to exit\n");
        setTextColor(7);
        while (getchar() != '\n');
    }
    while(getch() == 13);
    return 0;
}
