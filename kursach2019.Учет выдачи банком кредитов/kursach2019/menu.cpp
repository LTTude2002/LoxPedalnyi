//
#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
#include <conio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <iostream>
#include <iomanip>
//#include <windows.h>
//#include <conio.h>
//#include <iomanip>
#include "functions.h"

FILE* f3;
FILE* f4;


void mainMenu() {
	int flag = 0;
	while (flag == 0) {
		system("cls");
		printf("*****ГЛАВНОЕ МЕНЮ*****\n");
		printf("0.Выход\n"
			"1.Вход под администратором\n"
			"2.Вход под пользователем\n");
		printf("ВАШ ВЫБОР:");
		switch (_getch())
		{
		case '0': { system("cls"); printf("Спасибо за внимание\n"); flag = 1; break; }
		case '1': { autorisationAdmin(); break; }
		case '2': { autorisationUser();  break; }
		default:  {system("cls");		 break; }
		}
	}
}

void menuUser() {
	int flag = 0;
	while (flag == 0) {
		system("cls");
		printf("*****МЕНЮ ПОЛЬЗОВАТЕЛЯ*****\n");
		printf("0.Выход в главное меню\n"
			"1.Просмотреть таблицу\n"
			"2.Поиск кредитов\n"
			"3.Сортировка кредитов\n"
			"4.Выполнение индивидуального задания\n");
		printf("Ваш выбор:");
		switch (_getch())
		{
		case '0': { system("cls"); flag = 1;      break; }
		case '1': { system("cls"); printCredit(); break; }
		case '2': {	system("cls"); menuSearch();  break; }
		case '3': { system("cls"); menuSort();    break; }
		case'4':  { system("cls"); task();        break; }
		default:  {	system("cls"); printf("Такого пункта меню нет.Повторите попытку\n");
			system("pause"); break; }
		}
	}
}


void menuAdmin() {
	int flag = 0;
	while (flag == 0) {
		system("cls");
		printf("0.Выход в главное меню\n"
			"1.Добавить запись\n"
			"2.Удалить запись\n"
			"3.Редактировать запись\n"
			"4.Просмотреть таблицу\n"
			"5.Различные процедуры поиска и фильтрации данных\n"
			"6.Сортировка кредитов\n"
			"7.Управление пользователями\n");
		printf("Ваш выбор:");
		switch (_getch())
		{
		case '0': {system("cls"); flag = 1;          break; }
		case '1': {system("cls"); addCredit();       break; }
		case '2': {system("cls"); deleteMenu();      break; }
		case '3': {system("cls"); redactMenu();      break;	}
		case '4': {system("cls"); printCredit();     break;	}
		case '5': {system("cls"); menuSearch();      break;	}
		case '6': {system("cls"); menuSort();        break;	}
		case '7': {system("cls"); manageUsers();    break; }
		default:  system("cls"); printf("Такого пункта меню нет!!!!\n");
			system("pause"); break;
		}
	}
}


void header(void) {
	printf("СПИСОК ИМЕЮЩИХСЯ КРЕДИТОВ\n");
	printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|  # |    Информация о кредите      |                      Информация о клиенте                         |      Информация о виде кредита                              |\n");
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|  № | ID |  Название  |    Сумма   | Код клиента |  Фамилия клиента  |    Адрес    |Фамилия поручителя |Код кредита| Название вида |Процентная ставка|Дата оформления|\n");
	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void manageUsers()
{
	int k = 0;
	while (k == 0) {
		system("cls");
		printf("0.Выйти в меню администратора\n"
			"1.Зарегистрировать пользователя\n"
			"2.Удалить пользователя\n"
			"3.Изменить пароль пользователя\n"
			"4.Показать всех пользователей\n");
		fflush(stdin);
		switch (_getch())
		{
		case '0': { system("cls"); k = 1; break; }
		case '1': { system("cls"); registrationUser(); break; }
		case '2': { system("cls"); deleteUsers(f4); break; }
		case '3': { system("cls"); redactPassUser(f4); break; }
		case '4': { system("cls"); showAllUsers(f4); break; }
		default: { system("cls");  break; }
		}
	}
}


void deleteMenu() {
	bool flag = true;
	if ((f3 = fopen("credit.txt", "r+")) == NULL) {
		system("cls");
		printf("Файл пустой!!!Необходимо добавить кредит\n");
		system("pause");
	}
	else
	{
		do
		{
			system("cls");
			printf("0. Выход\n"
				"1. Удалить одну запись\n"
				"2. Удалить все записи\n\n");
			switch (_getch())
			{
			case'0': { system("cls"); flag = false; system("pause");   break; }
			case'1': { system("cls"); deleteCredit();  system("pause");  break; }
			case'2': { system("cls"); deleteAll();  system("pause");  break; }
			default: { system("cls"); printf("Такой записи не существует\n"); system("pause"); break; }
			}
		} while (flag);
	}
}

