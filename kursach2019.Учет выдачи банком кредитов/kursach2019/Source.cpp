#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "structs.h"
#include "functions.h"
#define KEY_SIZE 2

using namespace std;


FILE* f1;
FILE* f2;

const int N = 50;
Credit massiv[N];



void addCredit()
{
	FILE* fadd;
	Credit mas_id[N];
	char str[1] = { '\0' };
	int i = 0, j = 0, g = 0;
	char choice;
	do {
		choice = '0';
		f1 = fopen("credit.txt", "a+");//��� ������ � ����������,���� �� ���,�� ���������
		fclose(f1);
		fadd = fopen("credit.txt", "r+");//��� ������ � ������(���� ������ ���)
		for (j = 0; (fread(&mas_id[j], sizeof(struct Credit), 1, fadd)) != 0; j++);
		fclose(fadd);
		int id;
		int flag1 = 0;
		int flag2 = 0;
		while (flag1 == 0)
		{
			flag2 = 0;
			printf("������� ID �������:\n");
			id = checkForNumbers();
			for (int t = 0; t < j - 1; t++)
			{
				if (id == mas_id[t].ID) {
					flag2 = 1;
					break;
				}
			}
			if (flag2 == 1) {
				printf("����� ID ��� ����������!!!������� ������ ���:\n");
				flag1 = 0;
			}
			else
			{
				massiv[i].ID = id;
				flag1 = 1;
			}

		}

		while (g == 0) {
			fflush(stdin);
			printf("������� �������� �������:\n");
			gets_s(massiv[i].name);
			if (strcmp(massiv[i].name, str) != 0)
				g = 1;
		}
		g = 0;
		fflush(stdin);
		printf("������� ����� ������� (� ���.������):\n");
		massiv[i].cost = checkForNumbers();
		fflush(stdin);


		printf("\n***������� ���������� � �������,������� ����� ������***\n\n");
		int fl1 = 0;
		int fl2 = 0;
		while (fl1 == 0)
		{
			printf("������� ��� ������� :\n");
			id = checkForNumbers();
			massiv[i].client.codeClient = id;
			fl1 = 1;
		}
		while (g == 0) {
			fflush(stdin);
			//system("cls");
			printf("������� ������� �������:\n");
			gets_s(massiv[i].client.clientName);
			if (strcmp(massiv[i].client.clientName, str) != 0)
				g = 1;
		}
		g = 0;
		while (g == 0) {
			fflush(stdin);
			//system("cls");
			printf("������� ����� �������:\n");
			gets_s(massiv[i].client.address);
			if (strcmp(massiv[i].client.address, str) != 0)
				g = 1;
		}
		g = 0;
		while (g == 0) {
			fflush(stdin);
			//system("cls");
			printf("������� ������� ����������:\n");
			gets_s(massiv[i].client.guarantorName);
			if (strcmp(massiv[i].client.guarantorName, str) != 0)
				g = 1;
		}
		g = 0;

		printf("\n***������� ���������� � ���� �������,������� ����� ������***\n\n");
		//char id1[3];
		int flg1 = 0;
		int flg2 = 0;
		while (flg1 == 0)
		{
			printf("������� ��� ���� �������:(�������� �� 10 �� 40)\n");
			id = checkForNumbers();
			if (id < 10 || id > 40) {
				printf("��� ���� ������ �����������. ��������� ����\n");
				//return 0;
			}
			else {
				massiv[i].creditType.codeCredit = id;
				flg1 = 1;
			}
			
		}
		while (g == 0) {
			fflush(stdin);
			//system("cls");
			printf("������� ��� �������:\n");
			gets_s(massiv[i].creditType.typeOfCredit);
			if (strcmp(massiv[i].creditType.typeOfCredit, str) != 0)
				g = 1;
		}
		g = 0;

		fflush(stdin);
		printf("������� ���������� ������:\n");
		massiv[i].creditType.rate = checkForNumbers();
		//fflush(stdin);

		bool flag3 = true;
		while (flag3)
		{
			printf("������� ���� ���������� ������� (**.**.****):\n");
			char check[30];
			//fflush(stdin);
			//scanf_s("%s",10,check);
			cin >> check;
			if (checkDate(check)) {
				flag3 = 1;
				strcpy(massiv[i].date.date_format, check);
				int d = 0;
				char dd[3], mm[3], yyyy[5];
				for (; d < 2; d++)
					dd[d] = check[d];
				dd[2] = '\0';
				massiv[i].date.day = atoi(dd);

				for (int j = 0, d = 3; d < 5; d++, j++) {
					mm[j] = check[d];
				}
				mm[2] = '\0';
				massiv[i].date.month = atoi(mm);
				for (int j = 0, d = 6; d < (int)strlen(check) + 1; d++, j++) {
					yyyy[j] = check[d];
				}
				yyyy[4] = '\0';
				massiv[i].date.year = atoi(yyyy);
				flag3 = false;
			}
		}
		fadd = fopen("credit.txt", "a+");
		fwrite(&massiv[i], sizeof(struct Credit), 1, fadd);
		fclose(fadd);
		printf("\n���� ������ �������� ��� ���� ������,������� 1.���� ���,������� ����� �������\n");
		choice = _getch();
		if (choice == '1') {
			i++;
			system("cls");
		}
	} while (choice == '1');
}


void printCredit()
{
	int i = 0, a;
	if ((f1 = fopen("credit.txt", "r+")) == NULL) {
		system("cls");
		printf("���� ������.�������� ������!\n");
	}
	else {
		f1 = fopen("credit.txt", "r+");
		header();

		for (i = 0, a = 1; (fread(&massiv[i], sizeof(struct Credit), 1, f1)) != 0; i++, a++) {
			printf("|%4d|%4d|%12s|%12d|%13d|%19s|%13s|%19s|%11d|%15s|%17d|%15s|\n", a, massiv[i].ID, massiv[i].name, massiv[i].cost, massiv[i].client.codeClient, massiv[i].client.clientName, massiv[i].client.address, massiv[i].client.guarantorName, massiv[i].creditType.codeCredit, massiv[i].creditType.typeOfCredit, massiv[i].creditType.rate, massiv[i].date.date_format);
			printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

		}
		fclose(f1);
	}
	system("pause");
}

void printOne(int n)
{
	int i = 0;
	f1 = fopen("credit.txt", "r+");
	while (!feof(f1))
	{
		fread(&massiv[i], sizeof(struct Credit), 1, f1);
		i++;
	}
	fclose(f1);
	//header();
	printf("|%4d|%4d|%12s|%12d|%13d|%19s|%13s|%19s|%11d|%15s|%17d|%15s|\n\n", n + 1, massiv[n].ID, massiv[n].name, massiv[n].cost, massiv[n].client.codeClient, massiv[n].client.clientName, massiv[n].client.address, massiv[n].client.guarantorName, massiv[n].creditType.codeCredit, massiv[n].creditType.typeOfCredit, massiv[n].creditType.rate, massiv[n].date.date_format);
	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}


void deleteAll()
{
	f1 = fopen("credit.txt", "w+");
	remove("credit.txt");
	fclose(f1);
}

void deleteCredit()//�������� ������
{
	int i = 0, flag = -1, t;
	int num;
	f1 = fopen("credit.txt", "r+");
	while (!feof(f1))
	{
		fread(&massiv[i], sizeof(struct Credit), 1, f1);
		flag = i;
		i++;
	}
	fclose(f1);
	if (flag == -1)
		printf("������ ����!�������� ������\n");
	else
	{
		printCredit();
		printf("������� ����� ������,������� ������ �������\n");
		num = checkForNumbers();
		//fflush(stdin);
		t = num - 1;
		if (flag == 0 && num == 1) {
			system("cls");
			deleteAll();
			printf("������ # %d �������!\n", num);
		}
		else if (flag < num || num <= 0) {
			system("cls");
			printf("������ # %d �� ����������!\n", num);
		}
		else
		{
			system("cls");
			printf("������ # %d ������� �������!\n", t + 1);
			header();
			printf("|%4d|%4d|%12s|%12d|%13d|%19s|%13s|%19s|%11d|%15s|%17d|%15s|\n\n", t + 1, massiv[t].ID, massiv[t].name, massiv[t].cost, massiv[t].client.codeClient, massiv[t].client.clientName, massiv[t].client.address, massiv[t].client.guarantorName, massiv[t].creditType.codeCredit, massiv[t].creditType.typeOfCredit, massiv[t].creditType.rate, massiv[t].date.date_format);
			f1 = fopen("credit.txt", "w+");
			i = 0;
			while (i < num - 1) {
				fwrite(&massiv[i], sizeof(struct Credit), 1, f1);
				i++;
			}
			i++;
			for (; i < flag; i++)
				fwrite(&massiv[i], sizeof(struct Credit), 1, f1);
			fclose(f1);
		}
	}
	system("pause");
}

void redactMenu()
{
	int  a, num, i = 0, flag = 1;
	//	char c;
	if (!(f1 = fopen("credit.txt", "r"))) {
		system("cls");
		printf("���� ����!�������� ������\n");
		system("pause");
	}
	else {
		//f1 = fopen("credit.txt", "r+");
		while (!feof(f1)) {
			fread(&massiv[i], sizeof(struct Credit), 1, f1);
			a = i;
			i++;
		}
		fclose(f1);
		printCredit();
		printf("������� ����� ������,������� ������ ���������������\n");
		num = checkForNumbers();
		//fflush(stdin);
		if ((a < num) || (num <= 0)) {
			system("cls");
			printf("������ # %d �� ����������!\n", num);
			system("pause");
		}
		else {
			do {
				system("cls");
				printf("0. �����\n"
					"1. ������������� ������ ���������\n");
				switch (_getch())
				{
				case '1': { system("cls"); redactOneCreditAll(num); system("pause"); break; }
				case '0': { system("cls"); flag = false; break; }
				default: { system("cls"); printf("������ ������ �� ����������\n");
					system("pause"); break; }
				}
			} while (flag);
		}
	}
}

void redactOneCreditAll(int& num)
{
	int g = 0;
	char str[1] = { '\0' };
	int change = 0, i = 0;
	Credit redact;
	f1 = fopen("credit.txt", "r+");
	while ((fread(&massiv[i], sizeof(struct Credit), 1, f1)) != 0)
	{
		i++;
		change = i;
	}

	//int id = 0;
	int id;
	int flag1 = 0, flag2;
	while (flag1 != 1) {
		header();
		printOne(num - 1);
		flag2 = 0;
		printf("������� ID �������\n");
		//fflush(stdin);
		id = checkForNumbers();
		for (int t = 0; t < change; t++)
		{
			if (id == massiv[t].ID) {
				flag2 = 1;
				break;
			}
		}
		if (flag2 == 1) {
			printf("����� ID ��� ����������!!!!������� ������!\n");
			flag1 = 0;
		}
		else
		{
			redact.ID = id;
			flag1 = 1;
		}

	}
	fflush(stdin);
	while (g == 0) {
		//fflush(stdin);
		system("cls");
		printf("������� �������� �������\n");
		gets_s(redact.name);
		if (strcmp(redact.name, str) != 0)
			g = 1;
	}
	g = 0;
	//fflush(stdin);
	printf("������� ����� �������(� ���.���):\n");
	redact.cost = checkForNumbers();
	//fflush(stdin);
	printf("������� ���������� � �������,������� ����� ������\n");

	int fl1 = 0, fl2 = 1;
	while (fl2) {
		fl2 = 0;
		printf("������� ��� �������\n");
		//fflush(stdin);
		id = checkForNumbers();
		redact.client.codeClient = id;
	}
	fflush(stdin);
	while (g == 0) {
		fflush(stdin);
		system("cls");
		printf("������� ������� �������\n");
		gets_s(redact.client.clientName);
		if (strcmp(redact.client.clientName, str) != 0)
			g = 1;
	}
	g = 0;
	fflush(stdin);
	while (g == 0) {
		fflush(stdin);
		system("cls");
		printf("������� ����� �������\n");
		gets_s(redact.client.address);
		if (strcmp(redact.client.address, str) != 0)
			g = 1;
	}
	g = 0;
	fflush(stdin);
	while (g == 0) {
		fflush(stdin);
		system("cls");
		printf("������� ������� ����������\n");
		gets_s(redact.client.guarantorName);
		if (strcmp(redact.client.guarantorName, str) != 0)
			g = 1;
	}
	g = 0;
	fflush(stdin);

	printf("������� ���������� � ���� �������\n");
	int flg1 = 0, flg2;
	while (flg1 != 1) {
		flg2 = 0;
		printf("������� ��� ���� �������:(�������� �� 10 �� 40)\n");
		fflush(stdin);
		id = checkForNumbers();
		if (id < 10 || id > 40) {
			printf("��� ���� ������ �������. ��������� ����\n");
		}
		else {
			redact.creditType.codeCredit = id;
			flg1 = 1;
		}
	}

	fflush(stdin);
	while (g == 0) {
		fflush(stdin);;
		system("cls");
		printf("������� �������� ���� �������\n");
		gets_s(redact.creditType.typeOfCredit);
		if (strcmp(redact.creditType.typeOfCredit, str) != 0)
			g = 1;
	}
	g = 0;
	fflush(stdin);
	printf("������� ���������� ������\n");
	redact.creditType.rate = checkForNumbers();
	fflush(stdin);
	bool flag3 = true;
	while (flag3)
	{
		printf("������� ���� ���������� ������� (������ ����� : ��.��.����) :\n");
		char check[30];
		fflush(stdin);
		cin >> check;
		if (checkDate(check)) {
			flag3 = false;
			strcpy(redact.date.date_format, check);
			int d = 0;
			char dd[3], mm[3], yyyy[5];

			for (; d < 2; d++)
				dd[d] = check[d];
			dd[2] = '\0';
			redact.date.day = atoi(dd);

			for (int j = 0, d = 3; d < 5; d++, j++) {
				mm[j] = check[d];
			}
			mm[2] = '\0';
			redact.date.month = atoi(mm);
			for (int j = 0, d = 6; d < (int)strlen(check) + 1; d++, j++) {
				yyyy[j] = check[d];
			}
			yyyy[4] = '\0';
			redact.date.year = atoi(yyyy);

		}
	}
	massiv[num - 1] = redact;
	fclose(f1);
	f1 = fopen("credit.txt", "w+");
	for (i = 0; i < change; i++)
		fwrite(&massiv[i], sizeof(struct Credit), 1, f1);
	fclose(f1);
	system("cls");
	printf("������ # %d ������� ���������������\n", num);
}

void menuSearch()
{
	int g = 0;
	char o[1] = { '\0' };
	int  i = 0, srch;
	float begin = -1, end = -1;
	bool flag1 = false, flag2 = true;
	char str[30], k = '0';
	if (!fopen("credit.txt", "r+")) {
		system("cls");
		printf("����������� �������� ���. ���������� �������� ������\n");
		system("pause");
	}
	else {
		f1 = fopen("credit.txt", "r+");
		while (!feof(f1)) {
			fread(&massiv[i], sizeof(struct Credit), 1, f1);
			srch = i;
			i++;
		}
		fclose(f1);

		while (flag2) {
			system("cls");
			printCredit();
			printf("0.�����\n"
				"1.����� �� ������� �������\n"
				"2.����� �� �������� �������\n"
				"3.����� �� ����� �������\n");

			switch (_getch())
			{
			case '0': { system("cls"); flag2 = false; break; }
			case '1': {
				do {
					k = '0';
					flag1 = false;
					//	cls;

					while (g == 0) {
						fflush(stdin);
						//cls;
						printf("\n������� ������� �������:\n\n");
						gets_s(str);
						if (strcmp(str, o) != 0)
							g = 1;
					}
					g = 0;
					//cin >> str; // �������� �� ����
					fflush(stdin);
					system("cls");
					header();
					for (i = 0; i < srch; i++) {
						if (!(strcmp(str, massiv[i].client.clientName))) {
							flag1 = true;

							//	cout << "������ ���� #" << i + 1 << endl;
							printOne(i);
						}
					}
					if (flag1 != true) {
						system("cls");
						printf("������ ������� ���!\n");
						printf("������� 1,���� ������ ���������� �����. ���� ���,������� ����� �������\n\n");
						k = _getch();
					}
				} while (k == '1');
				system("pause");
				break;
			}
			case '2': {
				do {
					k = '0';
					flag1 = false;
					//cls;

					while (g == 0) {
						fflush(stdin);
						//cls;
						printf("\n������� �������� �������\n\n");
						gets_s(str);
						if (strcmp(str, o) != 0)
							g = 1;
					}
					g = 0;
					fflush(stdin);
					system("cls");
					header();
					for (i = 0; i < srch; i++) {
						if (!(strcmp(str, massiv[i].name))) {
							flag1 = true;
							printOne(i);
						}
					}
					if (flag1 != true) {
						system("cls");
						printf("������� � ����� ��������� ���!\n");
						printf("������� 1,���� ������ ��������� �����.���� ���,������� ����� �������\n\n");
						k = _getch();
					}
				} while (k == '1');
				system("pause");
				break;
			}
			case '3': {
				do {
					//cls;
					k = '0';
					flag1 = false;
					//cls;
					printf("\n����� �� ����� �������\n\n");
					printf("��:\n");
					cin >> begin;
					printf("��:\n");
					cin >> end;//�������� �� ����
					system("cls");
					header();
					for (i = 0; i < srch; i++) {
						if ((begin <= massiv[i].cost) && (massiv[i].cost <= end)) {
							flag1 = true;
							//cls;
							//	cout << "������ ���� #" << i + 1 << endl;
							printOne(i);
						}
					}
					if (flag1 != true) {
						system("cls");
						printf("�������� � ����� ���������� ����� ���!!!\n");
						printf("������� 1 ,���� ������ ��������� ����� . ���� ���,������� ����� �������.\n\n");
						k = _getch();
					}
				} while (k == '1');
				system("pause");
				break;
			}
			default: { system("cls"); printf("����� �������� ���!!!\n");
				system("pause"); break; }
			}
		}
	}
}
/*������� fread ��������� ������ �������� � struct credit ���������, 
������ �� ������� ����� ������ 1 ����, �� ������, � ��������� ��� � ����� ������, �� ������� ��������� tmp[i] .*/
/*������� fwrite ���������� ������ �������� � struct credit ���������, 
������ �� ������� ����� ������ 1 ����, � ���� ������, �� ������� ��������� tmp[i]  � ������� ������� � ������.*/

void menuSort()// ���������� �������
{
	struct Credit tmp[N], temp;
	int  size, flag = 1, i = 0, j = 0;
	if (!fopen("credit.txt", "r+")) {
		system("cls");
		printf("���� ����!!!�������� ������\n");
		system("pause");
	}
	else {
		f1 = fopen("credit.txt", "r+");
		while ((fread(&tmp[i], sizeof(struct Credit), 1, f1))) {
			i++;
		}
		fclose(f1);
		size = i;

		while (flag) {
			system("cls");
			printCredit();
			printf("0.�����\n"
				"1.���������� �� �������� ���� �������\n"
				"2.���������� �� ������� ����������\n"
				"3.���������� �� ���������� ������\n");

			switch (_getch())
			{
			case '1': {
				system("cls");
				for (i = 0; i < size - 1; i++) {
					for (j = i + 1; j < size; j++) {
						if (strcmp(tmp[i].creditType.typeOfCredit, tmp[j].creditType.typeOfCredit) > 0) {
							temp = tmp[i];
							tmp[i] = tmp[j];
							tmp[j] = temp;
						}
					}
				}
				printSortedCredit(size, tmp);
				break;
			}
			case '2': {
				system("cls");
				for (i = 0; i < size - 1; i++) {
					for (j = i + 1; j < size; j++) {
						if (strcmp(tmp[i].client.guarantorName, tmp[j].client.guarantorName) > 0) {
							temp = tmp[i];
							tmp[i] = tmp[j];
							tmp[j] = temp;
						}
					}
				}
				printSortedCredit(size, tmp);
				break;
			}
			case '3': {
				system("cls");
				for (i = 0; i < size - 1; i++) {
					for (j = i + 1; j < size; j++) {
						if (tmp[i].creditType.rate > tmp[j].creditType.rate) {
							temp = tmp[i];
							tmp[i] = tmp[j];
							tmp[j] = temp;
						}
					}
				}
				printSortedCredit(size, tmp);
				break;
			}
			case '0': { system("cls"); flag = 0; break; }
			default: { system("cls"); printf("����� �������� ���!!!\n");
				system("pause"); break; }
			}
		}
	}
}

void task() {
	struct Credit tmp[N], temp;
	int  size, flag = 1, i = 0, j = 0;
	if (!fopen("credit.txt", "r+")) {
		system("cls");
		printf("���� ����!!!�������� ������\n");
		system("pause");
	}
	else {
		f1 = fopen("credit.txt", "r+");
		while ((fread(&tmp[i], sizeof(struct Credit), 1, f1))) {
			i++;
		}
		fclose(f1);
		size = i;

		system("cls");
		printCredit();
		printf("%% ����� ���������� ������ �� ���� �������\n");
		system("cls");
		int k = 0, n = 0;
		int **arr = (int**)malloc(size * sizeof(int**));
		for (int i = 0; i < size; i++) {
			arr[i] = (int*)malloc(2 * sizeof(int));
			arr[i][0] = arr[i][1] = 0;
		}
		for (int i = 0; i < size; i++) {

			int j = tmp[i].creditType.codeCredit - 10;
			arr[j][0] = j;
			n += 1;
			arr[j][1]++;
		}
		for (int i = 0; i < size; i++) {
			for (int j = i + 1; j < size; j++) {
				if (arr[i][1] < arr[j][1]) {
					int * temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
		int count = 0;
		for (; count < size && count < 3 && arr[count][1] != 0; count++);
		if (count == 0) {
			printf("������ � ����� ����� ������� ���\n");
			free(arr);
			return;
		}
		else if (count == 1) {
			printf("������ ���� ������ �� ������ ���� ������� ���� ���������\n");
		}
		else if (count != 3) {
			printf("���� ��������� ������ %d ������", count);
		}
		else {
			printf("*****3 ����� ���������� ���� �������*****\n");
		}
		printf("�������������������������������������������������������������������\n"
			"|  �|�������� ���� �������|     ��� ���� �������|    ����������|\n"
			"�������������������������������������������������������������������\n");
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < size; j++) {
				k = arr[i][0] + 10;
				if (k == tmp[j].creditType.codeCredit) {
					printf("|%3d|%21s|%21d|%14d|\n", i + 1, tmp[j].creditType.typeOfCredit, tmp[j].creditType.codeCredit,arr[i][1]);
					printf("������������������������������������������������������������������� \n");
					break;
				}
			}
		}
		free(arr);
		system("pause");
		//break;
	}
}

void printSortedCredit(int srt, Credit* mas) {
	int num, i;
	header();
	for (i = 0, num = 1; i < srt; i++, num++) {
		printf("|%4d|%4d|%12s|%12d|%13d|%19s|%13s|%19s|%11d|%15s|%17d|%15s|\n\n", num, mas[i].ID, mas[i].name, mas[i].cost, mas[i].client.codeClient, mas[i].client.clientName, mas[i].client.address, mas[i].client.guarantorName, mas[i].creditType.codeCredit, mas[i].creditType.typeOfCredit, mas[i].creditType.rate, mas[i].date.date_format);
		printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	}
	system("pause");
}



void showAllUsers(FILE *F2)
{
	char file_login[20];
	char file_password[20];
	F2 = fopen("userLogPass.txt", "r+");
	if ("userLogPass.txt" != 0)
	{
		fscanf(F2, "%s", file_login);
		if (feof(F2)) {
			printf("�� ���� ������������ �� ������!\n");
			_getch();
			fclose(F2);
			return;
		}
		rewind(F2);
		printf("*****��� ������������������ ������������*****\n");
		printf("*****\n");
		do {
			fscanf(F2, "%s%s", file_login, file_password);
			if (feof(F2))
				break;
			printf("    %s\n", file_login);
		} while (1);
		printf("*****\n");
		fclose(F2);
	}
	else {
		printf("�� ���� ������������ �� ������.\n");
		fclose(F2);
	}
	system("pause");
	system("cls");
}//�������� ���� �������������

void deleteUsers(FILE *F2)
{
	system("cls");
	int sch = 0;
	int i = 0;
	char login[20], file_login[20];
	char file_password[20];
	FILE *temp = NULL;
	F2 = fopen("userLogPass.txt", "r+");
	fscanf(F2, "%s", file_login);
	if (feof(F2)) {
		printf("�� ���� ������������ �� ������.\n");
		_getch();
		fclose(F2);
		return;
	}
	rewind(F2);
	printf("*****�������� ������������*****\n\n");
	showAllUsers(F2);
	printf("������� ����� ������������, �������� ������ �������\n\n ");
	do {
		rewind(F2);
		scanf("%19s", login);
		fflush(stdin);
		sch = 0;
		do {
			fscanf(F2, "%s%s", file_login, file_password);
			if (feof(F2)) {
				break;
			}
			if (!strcmp(login, file_login)) {                    //������ ����� �� �����, ��� ��� ��� ���� ������������
				sch = 1;
				break;
			}
		} while (1);

		if (sch == 0)
			printf("������ \"%s\" � ������ ���. ��������� ����\n", login);
		else
			break;
	} while (1);

	rewind(F2);
	temp = fopen("TEMP.txt", "w+t");
	do {
		fscanf(F2, "%s%s", file_login, file_password);
		if (feof(F2)) {
			break;
		}
		if (strcmp(login, file_login)) {           //���� ������ �� ���������
			fprintf(temp, "%s %s\n", file_login, file_password);
		}
	} while (1);

	fclose(F2);
	F2 = fopen("userLogPass.txt", "w+t");// ���������� �������� ��� ��������
	rewind(temp);

	do {
		fscanf(temp, "%s%s", file_login, file_password);
		if (feof(temp)) {
			break;
		}
		fprintf(F2, "%s %s\n", file_login, file_password);
	} while (1);

	fclose(temp);
	remove("TEMP.txt");
	rewind(F2);

	system("cls");
	printf("������������ \"%s\" ������.\n", login);
	printf("���������� ������ �������������:\n");
	printf("*********\n");
	do {
		fscanf(F2, "%s%s", file_login, file_password);
		if (feof(F2)) {
			break;
		}
		printf("    %s\n", file_login);
	} while (1);
	printf("*********");
	fclose(F2);

	printf("������� ����� �������.");
	_getch();
}

void redactPassUser(FILE *F2)
{
	int sch = 0;
	int i = 0;
	char login[20], file_login[20];
	char password_1[20], password_2[20], file_password[20];
	FILE *temp = NULL;
	F2 = fopen("userLogPass.txt", "r+t");
	fscanf(F2, "%s", file_login);
	if (feof(F2)) {
		printf("�� ���� ������������ �� ������.\n");
		_getch();
		fclose(F2);
		return;
	}
	printf("*****��������� ������ ������������*****\n");
	rewind(F2);
	showAllUsers(F2);
	printf("������� ����� ������������, ������ �������� �� ������ ��������\n");
	do {
		rewind(F2);
		scanf("%19s", login);
		fflush(stdin);
		sch = 0;
		do {
			fscanf(F2, "%s%s", file_login, file_password);
			if (feof(F2)) {
				break;
			}
			if (!strcmp(login, file_login)) {                    //������ ����� �� �����, ��� ��� ��� ���� ������������
				sch = 1;
				break;
			}
		} while (1);
		if (sch == 0)
			printf("������ \"%s\" � ������ ���. ��������� ����\n", login);
		else
			break;
	} while (1);

	printf("������� ����� ������ ��� ������������ \"%s\":\n", login);
	do {
		printf("������� ������: ");
		for (i = 0; (password_1[i] = _getch()) != '\r' && i < 19;) {
			if (password_1[i] == '\b' && i != 0) {
				printf("%s", "\b \b");
				i--;
			}
			else if (password_1[i] != '\b') {
				printf("%c", '*');
				i++;
			}
		}
		password_1[i] = '\0';
		encrypt(password_1);
		printf("");

		printf("\n��������� ������: ");
		for (i = 0; (password_2[i] = _getch()) != '\r' && i < 19;) {
			if (password_2[i] == '\b' && i != 0) {
				printf("%s", "\b \b");
				i--;
			}
			else if (password_2[i] != '\b') {
				printf("%c", '*');
				i++;
			}
		}
		password_2[i] = '\0';
		encrypt(password_2);
		printf("");

		sch = 0;
		if (!strcmp(password_1, password_2)) {                    //������ ���������
			sch = 1;
			break;
		}
		if (sch == 0)
			printf("\n������ �� ���������. ��������� ����\n");
		else
			break;
	} while (1);

	rewind(F2);
	temp = fopen("temp.txt", "w+");
	do {
		fscanf(F2, "%s%s", file_login, file_password);
		if (feof(F2))
			break;
		if (strcmp(login, file_login))
			fprintf(temp, "%s %s\n", file_login, file_password);
		else
			fprintf(temp, "%s %s\n", login, password_1);
	} while (1);

	fclose(F2);
	F2 = fopen("userLogPass.txt", "w+");
	rewind(temp);//������������� ��������� � ������ �����

	do {
		fscanf(temp, "%s%s", file_login, file_password);
		if (feof(temp))
			break;
		fprintf(F2, "%s %s\n", file_login, file_password);
	} while (1);

	fclose(temp);
	remove("temp.txt");
	fclose(F2);

	printf("\n������ �������.\n");
	_getch();
}

void registrationUser()
{
	int i = 0, sch = 0;
	char login[20], file_login[20];
	char password_1[20], password_2[20], file_password[20];
	printf("*****���������� ������ ������������*****\n\n");
	printf("������� ����� ������ ������������: ");
	FILE *F2 = fopen("userLogPass.txt", "a+");
	do {
		rewind(F2);
		scanf("%19s", login);
		fflush(stdin);
		sch = 0;
		do {
			fscanf(F2, "%s%s", file_login, file_password);
			if (feof(F2)) {
				break;
			}
			if (!strcmp(login, file_login)) {          //������ ����� �� �����, ��� ��� ��� ���� ������������
				sch = 1;
				break;
			}
		} while (1);

		if (sch == 1)
			printf("����� \"%s\" ��� ����������. ������� ����� �����\n", login);
		else {
			printf("");
			break;
		}
	} while (1);

	printf("������� ������ ��� ������������ \"%s\":\n", login);
	do {
		printf("������� ������: ");
		for (i = 0; (password_1[i] = _getch()) != '\r' && i < 19;) {
			if (password_1[i] == '\b' && i != 0) {
				printf("%s", "\b \b");
				i--;
			}
			else if (password_1[i] != '\b') {
				printf("*");
				i++;
			}
		}
		password_1[i] = '\0';
		encrypt(password_1);
		printf("");

		printf("\n��������� ������: ");
		for (i = 0; (password_2[i] = _getch()) != '\r' && i < 19;) {
			if (password_2[i] == '\b' && i != 0) {
				printf("%s", "\b \b");
				i--;
			}
			else if (password_2[i] != '\b') {
				printf("*");
				i++;
			}
		}
		password_2[i] = '\0';
		encrypt(password_2);
		printf("");

		if (strcmp(password_1, password_2))                   //������ �� ���������                              
			printf("������ �� ���������. ��������� ����\n");
		else {
			printf("");
			break;
		}
	} while (1);
	fseek(F2, 0, SEEK_END);
	fprintf(F2, "%s %s\n", login, password_1);
	fclose(F2);
	printf("\n����� ������������ ������.\n");

	printf("������� ����� �������, ����� ��������� �����.");
	_getch();
}