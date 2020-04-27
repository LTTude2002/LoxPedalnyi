#pragma once

#include <stdio.h>
#include  "structs.h"



void mainMenu();  //������ ������� ����(����� ��� ��� ������� � �������)
void menuAdmin();//���� ��������������
int autorisationAdmin();  //���� ��� ���������������
int autorisationUser(); //���� ��� �������������
void menuUser(); //���� ������������
void addCredit(); //���� ���������
int checkDate(char*); // �������� ����
void header(void); // �������
void printCredit();// ����� ������� 
void printOne(int);// ����� ������� ��� ������ �������
void deleteMenu(); // ���� ��������
void deleteAll(); // ������� ��� ������
void deleteCredit(); // ������� ���� ������
void redactMenu();//���� ��������������
void redactOneCreditAll(int&);//�������������� ����� ������ ���������
void menuSearch(); // ���� ������
void menuSort();//���� ����������
void printSortedCredit(int, Credit*);//����� ��������������� ��������
void manageUsers(); //���� ���������� ��������������
void showAllUsers(FILE *);//�������� �������������
void deleteUsers(FILE *);//������� ������������
void redactPassUser(FILE *);//�������� ������ ������������
void registrationUser();//����������� ������������ 
int checkForNumbers();
void decrypt(char * s);//������������ ������
void encrypt(char* s);//����������� ������
void task();