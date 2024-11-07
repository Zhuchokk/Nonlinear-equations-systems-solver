#include"s21_matrix.h"
#include"tinyexpr.h"
#ifndef YAKOBI_H_INCLUDED
#define YAKOBI_H_INCLUDED

int create_yakobi_matrix(te_expr* funcs, matrix_t x, matrix_t* Yacobi);

#endif