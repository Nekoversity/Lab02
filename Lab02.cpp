﻿#include "stdafx.h"

int dice_chance_compare()
{
    int max_count = 10000;
    int count = 0, succ_count = 0, prev_res = -1;
    srand(time(NULL));
    while (count++ < max_count)
    {
        int dice = rand() % 6 + 1;
        if (prev_res == dice)
            ++succ_count;
        prev_res = dice;
    }

    printf("Probability: %.4f%%\n", succ_count * 100.0 / count);
    return 0;
}

int triangle_square_solver()
{
    double a, b, c, S = 0.0;
    printf("Enter sides of triangle (a, b, c): ");
    int cn = scanf("%lf, %lf, %lf", &a, &b, &c);
    if (cn != 3) {
        printf("Invalid input");
        return -1;
    }

    if (a < b + c && b < a + c && c < a + b) {
        double p = (a + b + c) / 2;
        S = sqrt(p * (p - a) * (p - b) * (p - c));
        printf("Square is: %g\n", S);
    }
    else {
        printf("This triangle is not exist\n");
    }

    getchar();
    return 0;
}

int min_max_diff() 
{
    printf("Enter a number (not a number to finish)\n");
    int min, max, num, count = 0;
    while (scanf("%d", &num) == 1) {
        if (count == 0) {
            min = max = num;
        }
        else
        {
            if (num > max) 
                max = num;
            else if (num < min) 
                min = num;
        }
        ++count;
    }

    printf("Entered %d numbers\n", count);
    printf("Min: %d, Max: %d, Diff: %d;", min, max, max-min);

    return 0;
}

int main()
{
    return 0;
}

