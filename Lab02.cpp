#include <iostream>

int main()
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

