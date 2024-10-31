#include"yakobi_matrix.h"
#include"s21_matrix.h"
#include"tinyexpr.h"

#define delta 0.000001 //Дельту на выбор

matrix_t create_yakobi_matrix(te_expr* funcs, matrix_t x); // тут вопрос передавать и возвращать matrix_t или с ссылкой matrix_t*. 