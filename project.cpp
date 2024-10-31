#include <stdio.h>
#include <s21_matrix.h>
#include <tinyexpr.h>
void Jacobi(char* strings, double* X) {
    int rows = n, columns = n;
    int s21_create_matrix(int rows, int columns, matrix_J * result);

    //принимает массив строк типа char, преобразовывает в тип te_expr
    //хз, работает ли
    te_expr functions(n);
    for (int i = 0; i < n; i++) {
        int err;
        te_expr* functions[i] = te_compile(strings[i], vars, 2, &err);
    }

    //Х - вектор-столбец решения (массив из n эл-тов)
    //...который еще надо заполнить чем-то, кроме нулей
    double* X = calloc(n, sizeof(double));
    
    //чему на самом деле равно д?
    double delta = 0.5;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix_J[i][j] = (functions[i](X[j] + delta) - functions[i](X[j] + delta)) / (2 * delta);
        }
    }

    return matrix_J**;
}

//принимаем массив te_expr functions;
//принимаем вектор-столбец ответов (чем заполнить? Единицами?)
//задаем д (чему равна?)
//динамически выделяем память под матрицу Якоби размером n*n
//J[i][j] = (functions[i][0](x[j] + д) - functions[i][0](x[j] + д)) / (2*д)


int main()
{
    //костыль; попытка понять, будет ли что-то работать или нет
    int n;
    scanf("%d", &n);
    scanf("%c", &strings);
    Jacobi(strings, X);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix_J[i][j]);
        }
        printf("\n");
    }

    return 0;
}