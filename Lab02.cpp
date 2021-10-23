#include "stdafx.h"

int between_rand()
{
    const int max_range = 1000, min_range = -1000, count = 1000;
    int guess_num = 0, guess_res = 0;

    srand(time(NULL));

    printf("Enter digit between %d and %d: ", min_range, max_range);
    if (scanf("%d", &guess_num) != 1) {
        printf("Invalid input!");
        return -1;
    }

    for (int i = 0; i < count;)
    {
        int num = rand();
        if (!(num > max_range || num < min_range)) {
            if (num > guess_num)
                ++guess_res;
            ++i;
        }
    }
    printf("There were %d number more then %d!", guess_res, guess_num);
    return 0;
}

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
    between_rand();
}

