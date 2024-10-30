//
// Created by User on 29.10.2024.
//

#ifndef VALIDATIONS_H
#define VALIDATIONS_H
#include <stdio.h>
#include <windows.h>

void setTextColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

static int validate_integer_value(const char *message)
{
    int value = 0;
    do
    {
        printf("%s\n", message);
        if (scanf("%d", &value) != 1)
        {
            setTextColor(12);
            printf("Invalid Input. Enter an integer value\n");
            setTextColor(7);
            fflush(stdin);
        }
        else
        {
            fflush(stdin);
            break;
        }
    }
    while(value != 1);
    return value;
}

static double validate_floating_value(const char *message)
{
    double value = 0;
    do
    {
        printf("%s\n", message);
        if (scanf("%lf", &value) != 1)
        {
            setTextColor(12);
            printf("Invalid Input. Enter a real number\n");
            setTextColor(7);
            fflush(stdin);
        }
        else
        {
            fflush(stdin);
            break;
        }
    }
    while(value != 1);
    return value;
}

static int validate_integer_accuracy(const char *message)
{
    int value = 0;
    printf("%s\n", message);
    do
    {
        if (scanf("%d", &value) != 1 || value <= 0)
        {
            setTextColor(12);
            printf("Invalid Input, enter an integer number greater than zero\n");
            fflush(stdin);
            setTextColor(7);
        }
        else
        {
            fflush(stdin);
            break;
        }
    }
    while(value != 1 || value <= 0);
    return value;
}

static double validate_floating_accuracy(const char *message1, const char *message2)
{
    double value = 0;
    printf("%s\n", message1);
    do
    {
        if (scanf("%lf", &value) != 1 || value <= 0)
        {
            setTextColor(12);
            printf("%s\n", message2);
            setTextColor(7);
            fflush(stdin);
        }
        else
        {
            fflush(stdin);
            break;
        }
    }
    while(value != 1 || value <= 0);
    return value;
}
#endif //VALIDATIONS_H
