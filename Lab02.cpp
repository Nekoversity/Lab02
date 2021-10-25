#include "stdafx.h"

int circles_entry()
{
    // Ми маємо два кола, нехай A і B. Ми знаємо координати їх центрів (cx, cy) та радіус (r), що в обох випадках дорівнює 1
    double r_A  =  1.0, r_B  = 1.0;
    double cx_A =  0.0, cy_A = 0.0;
    double cx_B = -1.0, cy_B = 0.0;

    // Отримаємо координати точки М
    double x_M, y_M;
    printf("Enter M coordinates (x, y): ");
    if (scanf("%lf, %lf", &x_M, &y_M) != 2)
    {
        printf("Invalid input\n");
        return -1;
    }
    
    // Перевіримо точку на входження до кожного кола, якщо точка належить обом колам, тоді вона належить і перетину даних кіл
    bool entry_A, entry_B = false;

    // Перевіряємо на входження до кіл за допомогою рівняння кола (x - a)^2 + (y - b)^2 = R^2, де a і b є координатами центру кола, а 
    // x, y координатами точки. В нашому випадку точка буде входити до кола за таким рівнянням (x - a)^2 + (y - b)^2 <= R^2
    entry_A = pow((x_M - cx_A), 2) + pow((y_M - cy_A), 2) <= pow(r_A, 2);
    entry_B = pow((x_M - cx_B), 2) + pow((y_M - cy_B), 2) <= pow(r_B, 2);

    if (entry_A && entry_B)
    {
        printf("Point M(%.1f, %.1f) is included in the intersection of circles\n\n", x_M, y_M);
        return 0;
    }

    printf("Point M(%.1f, %.1f) is not included in the intersection of circles\n\n", x_M, y_M);
    return 0;
}

int triple_min_max()
{
    int a, b, c;
    printf("Enter 3 numbers (a b c): ");
    if (scanf("%d %d %d", &a, &b, &c) != 3)
    {
        printf("Invalid input\n");
        return -1;
    }

    int min = a < b ? (a < c ? a : c) : (b < c ? b : c);
    int max = a > b ? (a > c ? a : c) : (b > c ? b : c);

    printf("Given (a=%d, b=%d, c=%d); Min: %d; Max: %d\n\n", a, b, c, min, max);
    return 0;
}

int prime_sheet()
{
    int num;
    printf("Enter number: ");
    if (scanf("%d", &num) != 1)
    {
        printf("Invalid input\n\n");
        return -1;
    }

    if (num < 2)
    {
        printf("Wrong num (less than first primary)\n\n");
        return -1;
    }

    if (num == 2) {
        printf("Number %d is primary\n\n", num);
        return 0;
    }

    int step = 2;
    bool step_decided = false;
    int next_step = 2;
    bool num_exist = true;
    for (int i = 2; i <= num; i++) {
        for (int j = step; j <= num; j++)
        {
            if ((j % step != 0) && !step_decided)
            {
                next_step = j;
                step_decided = true;
            }
            
            if (j % step == 0 && j != step)
            {
                num_exist = !(j == num);
            }
        }
        step_decided = false;
        step = next_step;
        if (!num_exist) break;
    }

    if (num_exist) {
        printf("Number %d is primary\n\n", num);
        return 0;
    }

    printf("Number %d is not primary\n\n", num);
    return 0;
}

// Check domino values
bool is_domino(int a, int b)
{
    return ((a <= 6) && (a >= 0)) && ((b <= 6) && (b >= 0));
}

int domino_dice()
{
    int d1_a, d1_b, d2_a, d2_b;
    printf("Enter values of two dominos (a1 b1, a2 b2): ");
    if (scanf("%d %d, %d %d", &d1_a, &d1_b, &d2_a, &d2_b) != 4)
    {
        printf("Invalid input\n");
        return -1;
    }

    if (!(is_domino(d1_a, d1_b) && is_domino(d2_a, d2_b)))
    {
        printf("Invalid domino values\n\n");
        return -1;
    }

    bool lining_possible = d1_a == d2_a ? true : (d1_a == d2_b ? true : (d1_b == d2_a ? true : (d1_b == d2_b ? true : false)));
    
    if (lining_possible) 
        printf("Given dominos can be joined!\n\n");
    else 
        printf("Given dominos can`t be joined.\n\n");

    return 0;
}

int find_nsd()
{
    int a, b;
    printf("Enter numbers (a b): ");
    if (scanf("%d %d", &a, &b) != 2)
    {
        printf("Invalid input\n");
        return -1;
    }

    int nsd = 1;
    for (int i = a; i > 0; i--)
    {
        if ((a % i == 0) && (b % i == 0))
        {
            nsd = i;
            break;
        }
    }

    printf("NSD equals %d\n\n", nsd);
    return 0;
}

int triangle_types()
{
    // Правильне відображення українських літер
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a, b, c;
    printf("Введіть сторони трикутника (a b c): ");
    if (scanf("%d %d %d", &a, &b, &c) != 3)
    {
        printf("Сторони не вірні\n\n");
        return -1;
    }

    if (a == b == c)
        printf("Сторони належать рівносторонньому трикутнику\n\n");
    else if (a == b || a == c || b == c) 
        printf("Сторони належать рівнобедренному трикутнику\n\n");
    else 
        printf("Сторони належать різносторонньому трикутнику\n\n");

    return 0;
}

double triangle_area(int a_x, int a_y, int b_x, int b_y, int c_x, int c_y)
{
    return 0.5 * abs((b_x - a_x) * (c_y - a_y) - (c_x - a_x) * (b_y - a_y));
}

int point_in_triangle()
{
    int a_x, a_y, b_x, b_y, c_x, c_y, p_x, p_y;
    int a_input, b_input, c_input, p_input;

    printf("Enter A coodinates (x y): ");
    a_input = scanf("%d %d", &a_x, &a_y);
    
    printf("Enter B coodinates (x y): ");
    b_input = scanf("%d %d", &b_x, &b_y);

    printf("Enter C coodinates (x y): ");
    c_input = scanf("%d %d", &c_x, &c_y);

    printf("Enter M coodinates (x y): ");
    p_input = scanf("%d %d", &p_x, &p_y);

    if (!(a_input == 2 && b_input == 2 && c_input == 2 && p_input == 2))
    {
        printf("Invalid input\n\n");
        return -1;
    }

    // Створимо нові трикутники, що складатимуться с 2-х вершин та точки. Якщо площі трьох таких 
    // підтрикутників будуть в сумі дорівнювати площі початкового трикутника, то точка знаходиться всередині
    double abc, abp, acp, bcp;
    abc = triangle_area(a_x, a_y, b_x, b_y, c_x, c_y);
    abp = triangle_area(a_x, a_y, b_x, b_y, p_x, p_y);
    acp = triangle_area(a_x, a_y, c_x, c_y, p_x, p_y);
    bcp = triangle_area(b_x, b_y, c_x, c_y, p_x, p_y);

    if (abc != (abp + acp + bcp)) 
        printf("Point M(%d, %d) placed ouside of ABC triangle\n\n", p_x, p_y);
    else
        printf("Point M(%d, %d) placed inside ABC triangle\n\n", p_x, p_y);
    
    return 0;
}

int main()
{
    point_in_triangle();
    point_in_triangle();
    point_in_triangle();
    point_in_triangle();
}
