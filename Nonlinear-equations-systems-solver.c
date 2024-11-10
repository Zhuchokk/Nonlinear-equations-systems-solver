#include<stdio.h>
#include<stdlib.h>
#include"tinyexpr.h"
#include"s21_matrix.h"
#include"eqparser.h"
#include"yakobi_matrix.h"

#define eps 0.00001

#pragma warning(disable:4996)

void find_Fx(te_expr** func, matrix_t fx, int size)
{
	// найти значения функций при конкретных значениях matrix_t x
	for (int i = 0; i < size; i++)
		fx.matrix[i][0] = te_eval(func[i]);
}

double absol(double n)
{
	// вывод абсолютного значения для типов double
    if (n < 0) return -n;
    return n;
}

double max_sub(matrix_t a, matrix_t b, int size)
{
	// вывод максимольной разности по модулю
	double* arr = (double*)calloc(size, sizeof(double));
    double max = -9999999999;
    for (int i = 0; i < size; i++)
    {
        arr[i] = absol(a.matrix[i][0] - b.matrix[i][0]);
        if (max < arr[i]) max = arr[i];
    }
    return max;
}

void copy(matrix_t a, matrix_t b, int size)
{
	for (int i = 0; i < size; i++)
		a.matrix[i][0] = b.matrix[i][0];
}

int check_answer(matrix_t x, double a, double b)
{
	// проверка на нахождение предполагаемого корня в конкретном отрезке
	int n = x.rows;
	for (int i = 0; i < n; i++)
		if (x.matrix[i][0] <= a || x.matrix[i][0] >= b) return 1;
	return 0;
}

int main()
{
	char file_name[100];
	int n;
	int err;

	//Для работы с функциями. Редактировать не желательно
	char** strings;
	te_variable* vars_x;
	te_expr** functions_x;

	//Структуры для работы над матрицами
	matrix_t x;
	matrix_t x_next;
	matrix_t yakobi;
	matrix_t Fx; // вектор-столбец значений функций
	matrix_t yakobi_obr;
	matrix_t matrix_mul;
	
	double a = 0.0, b = 0.0;
	short int flag_half_del = 0;

	printf("Enter the filename\n");
	scanf("%s", &file_name);
	printf("Enter the interval for the expected response\n(format: a b where a < b)\n");
	scanf("%lf %lf", &a, &b);
	if (a != b) flag_half_del = 1.0; // если пользователь ввел определяемый интервал предполагаемого корня

	n = get_n_from_file(file_name);
	strings = parse(file_name);

	//Инициализация матриц
	s21_create_matrix(n, 1, &x);
	s21_create_matrix(n, 1, &x_next);
	s21_create_matrix(n, n, &yakobi);
	s21_create_matrix(n, 1, &Fx);
	s21_create_matrix(n, n, &yakobi_obr);
	s21_create_matrix(n, 1, &matrix_mul);

	// начальное приближение и стартовое положение x2
	for(int i = 0; i < n; i++)
	{
		x.matrix[i][0] = 1;
		x_next.matrix[i][0] = 2;
	}

	//Инициализация массивов переменных, запись в них ссылок x и next_x. 
	vars_x = (te_variable*)malloc(n * sizeof(te_variable));
	for (int i = 0; i < n; i++) {
		char* buf = (char*)calloc(5, sizeof(char));
		snprintf(buf, sizeof(buf), "x%d", (i + 1));
		te_variable tv = {buf, &(x.matrix[i][0])};
		vars_x[i] = tv;
	}

	//Инициализация функций 
	functions_x = (te_expr**)malloc(n * sizeof(te_expr*));
	for (int i = 0; i < n; i++) {
		functions_x[i] = te_compile(strings[i], vars_x, n, &err);
	}

	while(max_sub(x_next, x, n) > eps)
	{
		copy(x, x_next, n);
		find_Fx(functions_x, Fx, n);

		if (!create_yakobi_matrix(functions_x, x, &yakobi)) {
			//Деление на ноль, выход за область определения функции, что-то надо сделать
			continue;
		}

		s21_inverse_matrix(&yakobi, &yakobi_obr);
		s21_mult_matrix(&yakobi_obr, &Fx, &matrix_mul);
		s21_sub_matrix(&x, &matrix_mul, &x_next);

		if (flag_half_del == 1)
		{
			while(check_answer(x_next, a, b))
				for(int i = 0; i < n; i++)
					x_next.matrix[i][0] = (x.matrix[i][0] + x_next.matrix[i][0]) / 2;
		}
	}

	printf("Answer:\n");
	for (int i = 0; i < n; i++)
		printf("%f\n", x_next.matrix[i][0]);

	scanf("%d");
}