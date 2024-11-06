//
// Created by User on 29.10.2024.
//

#ifndef VALIDATION_H
#define VALIDATION_H
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

void setTextColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

static int validate_integer_limits_value(const char *message)
{
    bool InvalidInput;
    int value = 0;
    do
    {
        printf("%s\n", message);
        fflush(stdin);
        if (scanf("%d", &value) != 1 || value < -360 || value > 360)
        {
            setTextColor(12);
            printf("Invalid Input. Enter an integer value in given range\n");
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
    while(InvalidInput);
    return value;
}
static int validate_integer_step_value(const char *message)
{
    bool InvalidInput;
    int value = 0;
    do
    {
        printf("%s\n", message);
        fflush(stdin);
        if (scanf("%d", &value) != 1)
        {
            setTextColor(12);
            printf("Invalid Input. Enter an integer value\n");
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
    while(InvalidInput);
    return value;
}

static int validate_integer_accuracy(const char *message)
{
    bool InvalidInput;
    int value = 0;
    printf("%s", message);
    fflush(stdin);
    do
    {
        if (scanf("%d", &value) != 1 || value <= 0 || value > 15)
        {
            setTextColor(12);
            printf("Invalid Input, please enter an integer number in given range\n");
            fflush(stdin);
            setTextColor(7);
            InvalidInput = true;
        }
        else
        {
            fflush(stdin);
            InvalidInput = false;
        }
    }
    while(InvalidInput);
    return value;
}

static double validate_floating_accuracy(const char *message1, const char *message2)
{
    bool InvalidInput;
    double value = 0;
    printf("%s\n", message1);
    fflush(stdin);
    do
    {
        if (scanf("%lf", &value) != 1 || value <= 0 || value < 1e-15 || value > 1e-1)
        {
            setTextColor(12);
            printf("%s\n", message2);
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
    while(InvalidInput);
    return value;
}
#endif //VALIDATION_H
