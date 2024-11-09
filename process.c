#include <stdio.h>
#include "s21_matrix.h"

double absol(double n)
{
    if (n < 0) return -n;
    return n;
}

double max_sub(matrix_t a, matrix_t b)
{
    double arr[5];
    double max = -9999999999;
    for (int i = 0; i < 5; i++)
    {
        arr[i] = absol(a.matrix[i][0] - b.matrix[i][0]);
        if (max < arr[i]) max = arr[i];
    }
    return max;
}



int main() {
    for (int i = 1; i <= 10; ++i) {
        char buf[5];
        snprintf(buf, sizeof(buf), "x%d", i);
        printf("%s\n", buf);
    }
    scanf("%d");
    return 0;
}