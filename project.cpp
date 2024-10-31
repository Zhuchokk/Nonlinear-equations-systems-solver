#include <stdio.h>
#include <s21_matrix.h>
#include <tinyexpr.h>
void Jacobi(char* strings, double* X) {
    int rows = n, columns = n;
    int s21_create_matrix(int rows, int columns, matrix_J * result);

    //��������� ������ ����� ���� char, ��������������� � ��� te_expr
    //��, �������� ��
    te_expr functions(n);
    for (int i = 0; i < n; i++) {
        int err;
        te_expr* functions[i] = te_compile(strings[i], vars, 2, &err);
    }

    //� - ������-������� ������� (������ �� n ��-���)
    //...������� ��� ���� ��������� ���-��, ����� �����
    double* X = calloc(n, sizeof(double));
    
    //���� �� ����� ���� ����� �?
    double delta = 0.5;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix_J[i][j] = (functions[i](X[j] + delta) - functions[i](X[j] + delta)) / (2 * delta);
        }
    }

    return matrix_J**;
}

//��������� ������ te_expr functions;
//��������� ������-������� ������� (��� ���������? ���������?)
//������ � (���� �����?)
//����������� �������� ������ ��� ������� ����� �������� n*n
//J[i][j] = (functions[i][0](x[j] + �) - functions[i][0](x[j] + �)) / (2*�)


int main()
{
    //�������; ������� ������, ����� �� ���-�� �������� ��� ���
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