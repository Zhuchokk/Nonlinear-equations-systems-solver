#include "yakobi_matrix.h"
#include "s21_matrix.h"
#include "tinyexpr.h"
#include<math.h>

#define delta 0.000001 

int create_yakobi_matrix(te_expr** funcs, matrix_t x, matrix_t* Yacobi) {
	int status = 1;
	int n = x.rows;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			x.matrix[j][0] = x.matrix[j][0] + delta;
			double y1 = te_eval(funcs[i]);
			
			x.matrix[j][0] = x.matrix[j][0] - 2 * delta;
			double y2 = te_eval(funcs[i]);

			if (isnan(y1) || isinf(y1) || isnan(y2) || isinf(y2)) {
				return 0;
			}
			Yacobi->matrix[i][j] = (y1 - y2) / (2 * delta);
			
		}
	}
	return status;
}



