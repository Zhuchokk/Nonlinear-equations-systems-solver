#include<eqparser.h>
#include<stdio.h>

#pragma warning(disable:4996)

//������ ���� � ������ file_name � ���������� ������ �����(char**), ���������� �������(� ��� ���������� = � �������)
char** parse(char* file_name) {
	FILE* fp;
	int n;
	char ch;
	char** strings;
	


	fp = fopen(file_name, "r");
	n = atoi(fgetc(fp));
	fgetc(fp); //���������� ������� ������

	strings = malloc(n * sizeof(char*));
	for (int i = 0; i < n; i++) {
		strings[i] = malloc((n * 5 + 3) * sizeof(char)); //���� ��������� ������� ������� ����� ����� ���� �������� ������
	}
	

	while ((ch = fgetc(fp)) != EOF) {
		static int i = 0, j = 0;
		if (ch == '\n') {
			i++;
			j = 0;
		}
		else {
			strings[i][j] = ch;
			j++;
		}
	}
	fclose(fp);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 5 + 3; j++) {
			int f = 0;
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
		}
	}
	return strings;

}
