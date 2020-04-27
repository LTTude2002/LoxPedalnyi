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
		printf("*****������� ����*****\n");
		printf("0.�����\n"
			"1.���� ��� ���������������\n"
			"2.���� ��� �������������\n");
		printf("��� �����:");
		switch (_getch())
		{
		case '0': { system("cls"); printf("������� �� ��������\n"); flag = 1; break; }
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
		printf("*****���� ������������*****\n");
		printf("0.����� � ������� ����\n"
			"1.����������� �������\n"
			"2.����� ��������\n"
			"3.���������� ��������\n"
			"4.���������� ��������������� �������\n");
		printf("��� �����:");
		switch (_getch())
		{
		case '0': { system("cls"); flag = 1;      break; }
		case '1': { system("cls"); printCredit(); break; }
		case '2': {	system("cls"); menuSearch();  break; }
		case '3': { system("cls"); menuSort();    break; }
		case'4':  { system("cls"); task();        break; }
		default:  {	system("cls"); printf("������ ������ ���� ���.��������� �������\n");
			system("pause"); break; }
		}
	}
}


void menuAdmin() {
	int flag = 0;
	while (flag == 0) {
		system("cls");
		printf("0.����� � ������� ����\n"
			"1.�������� ������\n"
			"2.������� ������\n"
			"3.������������� ������\n"
			"4.����������� �������\n"
			"5.��������� ��������� ������ � ���������� ������\n"
			"6.���������� ��������\n"
			"7.���������� ��������������\n");
		printf("��� �����:");
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
		default:  system("cls"); printf("������ ������ ���� ���!!!!\n");
			system("pause"); break;
		}
	}
}


void header(void) {
	printf("������ ��������� ��������\n");
	printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|  # |    ���������� � �������      |                      ���������� � �������                         |      ���������� � ���� �������                              |\n");
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|  � | ID |  ��������  |    �����   | ��� ������� |  ������� �������  |    �����    |������� ���������� |��� �������| �������� ���� |���������� ������|���� ����������|\n");
	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void manageUsers()
{
	int k = 0;
	while (k == 0) {
		system("cls");
		printf("0.����� � ���� ��������������\n"
			"1.���������������� ������������\n"
			"2.������� ������������\n"
			"3.�������� ������ ������������\n"
			"4.�������� ���� �������������\n");
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
		printf("���� ������!!!���������� �������� ������\n");
		system("pause");
	}
	else
	{
		do
		{
			system("cls");
			printf("0. �����\n"
				"1. ������� ���� ������\n"
				"2. ������� ��� ������\n\n");
			switch (_getch())
			{
			case'0': { system("cls"); flag = false; system("pause");   break; }
			case'1': { system("cls"); deleteCredit();  system("pause");  break; }
			case'2': { system("cls"); deleteAll();  system("pause");  break; }
			default: { system("cls"); printf("����� ������ �� ����������\n"); system("pause"); break; }
			}
		} while (flag);
	}
}

