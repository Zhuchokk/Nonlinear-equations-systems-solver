#include<stdio.h>
#include<stdlib.h>
#include"tinyexpr.h"
#include"s21_matrix.h"
#include"eqparser.h"
#include"yakobi_matrix.h"

#pragma warning(disable:4996)



int main()
{
	char file_name[100];
	int n;
	int err;

	//Для работы с функциями. Редактировать не желательно
	char** strings;
	te_variable* vars_x;
	te_variable* vars_x_next;
	te_expr** functions_x;
	te_expr** functions_x_next;

	//Структуры для работы над матрицами
	matrix_t x; 
	matrix_t x_next;
	


	scanf("%s", &file_name);
	n = get_n_from_file(file_name);
	strings = parse(file_name);

	//Инициализация матриц
	s21_create_matrix(n, 1, &x);
	s21_create_matrix(n, 1, &x_next);

	//Инициализация массивов переменных, запись в них ссылок x и next_x. 
	vars_x = (te_variable*)malloc(n * sizeof(te_variable));
	for (int i = 0; i < n; i++) {
		te_variable tv = { 'x' + ('0' + i + 1) + "\0", &(x.matrix[i][0])};
		vars_x[i] = tv;

	}
	vars_x_next = (te_variable*)malloc(n * sizeof(te_variable));
	for (int i = 0; i < n; i++) {
		te_variable tv = { 'x' + ('0' + i + 1) + '\0', &(x_next.matrix[i][0])};
		vars_x_next[i] = tv;
	}

	//Инициализация функций
	functions_x = (te_expr**)malloc(n * sizeof(te_expr*));
	for (int i = 0; i < n; i++) {
		functions_x[i] = te_compile(strings[i], vars_x, n, &err);
	}

	functions_x_next = (te_expr**)malloc(n * sizeof(te_expr*));
	for (int i = 0; i < n; i++) {
		functions_x_next[i] = te_compile(strings[i], vars_x, n, &err);
	}
	
}
