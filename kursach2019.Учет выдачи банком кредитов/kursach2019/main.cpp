#include <conio.h>
#include <iomanip>
#include <windows.h>
#include "functions.h"
#define KEY_SIZE 2


int checkDate(char* str)
{
	if (strlen(str) != 10) {
		printf("Неверный формат ввода. Повторите ввод\n");
		return 0;
	}
	for (int i = 0; i < 10; i++) {
		if (((i == 2 || i == 5) && str[i] != '.') || (i != 2 && i != 5 && (str[i] < '0' || str[i]>'9'))) {
			printf("Неверный формат ввода. Повторите ввод\n");
			return 0;
		}
	}
	char day[3];
	char month[3];
	char year[5];
	for (int i = 0; i < 2; i++) {
		day[i] = str[i];
	}
	day[2] = '\0';
	if (atoi(day) < 0 || atoi(day) > 31) {
		printf("Дата введена некорректно. Повторите ввод\n");
		return 0;
	}
	else {
		for (int j = 0, i = 3; i < 5; i++, j++) {
			month[j] = str[i];
		}
		month[2] = '\0';
		if (atoi(month) < 0 || atoi(month) > 12) {
			printf("Дата введена некорректно. Повторите ввод\n");
			return 0;
		}
		else if (atoi(month) == 2 && atoi(day) > 28) {//, atoi(month)==4 || atoi(month) == 6 || atoi(month) == 9 || atoi(month) == 11 && atoi(day) > 30) {
			printf("Дата введена некорректно.В данном месяце не может быть столько дней. Повторите ввод\n");
			return 0;
		}
		else  if (atoi(month) == 4 || atoi(month) == 6 || atoi(month) == 9 || atoi(month) == 11 && atoi(day) > 30) {
			printf("Дата введена некорректно.В данном месяце не может быть столько дней. Повторите ввод\n");
			return 0;
		}
		else {
			for (int j = 0, i = 6; i < (int)strlen(str) + 1; i++, j++) {
				year[j] = str[i];
			}
			year[4] = '\0';
			if (atoi(year) < 2000 || atoi(year) > 2100) {
				printf("Дата введена некорректно. Повторите ввод\n");
				return 0;
			}
			else
				return 1;
		}
	}
}

int checkForNumbers()
{
	char mas[9];
	int count = 0, i = 0;
	while (1) {
		//cls;
		for (i = 0; (mas[i] = getchar()) != '\n' && i < 8; i++);
		mas[i] = '\0';
		fflush(stdin);

		for (count = 0, i = 0; mas[i] != '\0'; i++)
			if (!(mas[i] >= '0' && mas[i] <= '9')) {
				count++;
				break;
			}
		if (mas[0] == '\0')
			count++;
		if (mas[i] == '\t')
			count++;
		if (count == 0)
			break;
		else
			printf("\nНеверный формат ввода! Попробуйте ещё раз!\n");
	}
	return atoi(mas);
}



void encrypt(char* s)
{
	for (int i = 0; i < strlen(s); i++)
	{
		s[i] += KEY_SIZE;
	}
}

void decrypt(char* s)
{
	for (int i = 0; i < strlen(s); i++) {
		s[i] -= KEY_SIZE;
	}
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	mainMenu();
	/*FILE *F1 = fopen("adminPassword.txt", "w");
	char s[] = "qwerty123";
	encrypt(s);
	fputs(s, F1);*/
	_getch();
	return 0;
}