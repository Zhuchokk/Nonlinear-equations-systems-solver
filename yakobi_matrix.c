#include"yakobi_matrix.h"
#include"s21_matrix.h"
#include"tinyexpr.h"

#define delta 0.000001 //������ �� �����

matrix_t create_yakobi_matrix(te_expr* funcs, matrix_t x); // ��� ������ ���������� � ���������� matrix_t ��� � ������� matrix_t*. 