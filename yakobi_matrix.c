#include "yakobi_matrix.h"
#include "s21_matrix.h"
#include "tinyexpr.h"

#define delta 0.000001 //Дельту на выбор

//тут вопрос, передавать и возвращать matrix_t или с ссылкой matrix_t*.
int create_yakobi_matrix(te_expr** funcs, matrix_t x, matrix_t* Yacobi) {
	int status = 1;
	int n = x.rows;
	matrix_t Jacobi;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			x.matrix[j][0] = x.matrix[j][0] + delta;
			float y1 = te_eval(funcs[i]);
			
			x.matrix[j][0] = x.matrix[j][0] - 2 * delta;
			float y2 = te_eval(funcs[i]);

			Yacobi->matrix[i][j] = (y1 - y2) / (2 * delta);
			
		}
	}
	return status;
}



