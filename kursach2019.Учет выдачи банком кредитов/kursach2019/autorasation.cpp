#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <iomanip>
#include "functions.h"


int autorisationAdmin() {
	system("cls");
	printf("*****���� ��� ���������������*****\n");
	char passwordAdmin[20], filePasswordAdmin[20];
	int i = 0;
	int count = 0;
	printf("\n��� ����� ������ � ��� ���� ��������� �������.\n");
	FILE *F1 = fopen("adminPassword.txt", "r");
	printf("������� ������: ");
	fscanf(F1, "%s", filePasswordAdmin);
	decrypt(filePasswordAdmin);
	for (count = 0; count < 5; count++) {
		for (i = 0; (passwordAdmin[i] = _getch()) != '\r' && i < 19;) {
			if (passwordAdmin[i] == '\b' && i != 0) {
				printf("%s", "\b \b");
				i--;
			}
			else if (passwordAdmin[i] != '\b') {
				printf("%c", '*');
				i++;
			}
		}
		passwordAdmin[i] = '\0';

		if (strcmp(passwordAdmin, filePasswordAdmin)) {
			if (count == 4) {
				printf("\n������ ������ �������!���� � ������� ��������\n");
				_getch();
				return 0;
			}
			else
				printf("\n������ ������ �������. � ��� ���� ��� %d �������.\n��������� ������: ", 4 - count);

		}
		else
			break;
	}
	fclose(F1);
	system("pause");
	menuAdmin();
	return 0;
	//cls;
}


int autorisationUser() {
	system("cls");
	int count1 = 0;
	char loginUser[20], fileLoginUser[20];
	char passwordUser[20], filePasswordUser[20];
	int count2 = 0;
	int i = 0;
	FILE *F2 = fopen("userLogPass.txt", "r+");
	fscanf(F2, "%s", fileLoginUser);
	if (feof(F2)) {
		printf("\n��� ��������� �������������.�������� ������������.");
		system("pause");
		fclose(F2);
		return 0;
	}

	printf("*****���� ��� �������������*****\n\n");

	printf("\n��� ����� ������ � ������ � ��� ���� 3 �������.\n");
	do {
		printf("������� �����: ");
		scanf("%25s", loginUser);
		fflush(stdin);
		printf("\n������� ������:\n ");
		for (i = 0; (passwordUser[i] = _getch()) != '\r' && i < 19;) {
			if (passwordUser[i] == '\b' && i != 0) {
				printf("%s", "\b \b");
				i--;
			}
			else if (passwordUser[i] != '\b') {
				printf("%c", '*');
				i++;
			}
		}
		passwordUser[i] = '\0';
		encrypt(passwordUser);
		count2 = 0;
		rewind(F2);
		do {
			fscanf(F2, "%s%s", fileLoginUser, filePasswordUser);
			if (feof(F2)) {
				break;
			}
			if (!strcmp(loginUser, fileLoginUser)) {                    //������ ����� �� �����, ��� ���, ��� ���� ������������
				count2 = 1;
				break;
			}
		} while (1);
		if (count2 == 0) {
			count1++;
			if (count1 == 3) {
				printf("\n������� �����������.");
				_getch();
				return 0;
			}
			printf("\n������ \"%s\" ���. � ��� �������� %d �������.��������� ����.\n", loginUser, 3 - count1);
		}
		else break;
	} while (1);
	fclose(F2);
	count1 = 0;

	do {
		if (strcmp(passwordUser, filePasswordUser)) {    //���� ������, ��������� �������������, �� ��������� � ������ �������                          
			count1++;
			if (count1 == 3) {
				printf("\n������� �����������.");
				_getch();
				return 0;
			}
			printf("\n�������� ������. � ��� �������� %d �������.\n��������� ������: ", 3 - count1);
		}
		else {
			break;
		}
		for (i = 0; (passwordUser[i] = _getch()) != '\r' && i < 19;) {
			if (passwordUser[i] == '\b' && i != 0) {
				printf("%s", "\b \b");
				i--;
			}
			else if (passwordUser[i] != '\b') {
				printf("%c", '*');
				i++;
			}
		}
		passwordUser[i] = '\0';
		encrypt(passwordUser);
	} while (1);
	//cls;
	menuUser();
	return 1;
}