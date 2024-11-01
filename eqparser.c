#include "eqparser.h"
#include<stdio.h>

#pragma warning(disable:4996)

//������ ���� � ������ file_name � ���������� ������ �����(char**), ���������� �������(� ��� ���������� = � �������)
char** parse(char* file_name) {
	FILE* fp;
	int n;
	int space_per_symbol = 8;
	char ch;
	char** strings;
	char* number = (char*)malloc(100 * sizeof(char));


	fp = fopen(file_name, "r");
	while ((ch = fgetc(fp)) != '\n') {
		static int i = 0;
		number[i] = ch;
		i++;
		number[i] = '\0';
	}
	n = atoi(number);

	strings = (char**)malloc(n * sizeof(char*));
	for (int i = 0; i < n; i++) {
		strings[i] = (char*)malloc((n * space_per_symbol + 3) * sizeof(char)); //���� ��������� ������� ������� ����� ����� ���� �������� ������
	}

	while ((ch = fgetc(fp))) {
		static int i = 0, j = 0;
		if (ch == '\n') {
			for (; j < n * space_per_symbol + 3; j++) {
				strings[i][j] = ' ';
			}
			i++;
			j = 0;
		}
		else if (ch == EOF) {
			for (; j < n * space_per_symbol + 3; j++) {
				strings[i][j] = ' ';
			}
			break;
		}
		else {
			strings[i][j] = ch;
			j++;
		}
	}

	fclose(fp);

	for (int i = 0; i < n; i++) {
		int f = 0;
		for (int j = 0; j < n * space_per_symbol + 3; j++) {
			if (strings[i][j] == '=') {
				f = 1;
				strings[i][j] = ' ';
			}
			if (strings[i][j] == '+' && f) {
				strings[i][j] = '-';
			}
			else if (strings[i][j] == '-' && f) {
				strings[i][j] = '+';
			}
			else if (strings[i][j] == 'x' && f && strings[i][j - 1] == ' ') {
				strings[i][j - 1] = '-';
			}
			else if ('0' <= strings[i][j] && strings[i][j] <= '9' && f && strings[i][j - 1] == ' ') {
				strings[i][j - 1] = '-';
			}
		}
	}
	return strings;

}
int get_n_from_file(char* file_name) {
	FILE* fp;
	int n;
	char ch;
	char** strings;
	char* number = (char*)malloc(100 * sizeof(char));

	fp = fopen(file_name, "r");
	while ((ch = fgetc(fp)) != '\n') {
		static int i = 0;
		number[i] = ch; //error of access
		i++;
		number[i] = '\0';
	}
	n = atoi(number);
	fclose(fp);
	return n;
}