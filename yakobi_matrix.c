#include "yakobi_matrix.h"
#include "s21_matrix.h"
#include "tinyexpr.h"

#define delta 0.000001 //������ �� �����

//��� ������, ���������� � ���������� matrix_t ��� � ������� matrix_t*.
matrix_t create_yakobi_matrix(te_expr** funcs, matrix_t x) {
	int n = x.rows;
	matrix_t Jacobi;
	s21_create_matrix(n, n, &Jacobi);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			x.matrix[j][0] = x.matrix[j][0] + delta;
			float y1 = te_eval(funcs[i]);
			
			x.matrix[j][0] = x.matrix[j][0] - 2 * delta;
			float y2 = te_eval(funcs[i]);

			Jacobi.matrix[i][j] = (y1 - y2) / (2 * delta);
			
		}
	}
	return Jacobi;
}



