#include<stdio.h>
#include<tinyexpr.h>
#include<s21_matrix.h>
#include<eqparser.h>
#include<yakobi_matrix.h>

#pragma warning(disable:4996)



int main()
{
	char** strings;
	char file_name[100];
	int n;


	scanf("%s", &file_name);
	n = get_n_from_file(file_name);
	strings = parse(file_name);


}
