#pragma once

#include <stdio.h>
#include  "structs.h"



void mainMenu();  //первое главное меню(выбор под кем входить в систему)
void menuAdmin();//меню администратора
int autorisationAdmin();  //вход под администратором
int autorisationUser(); //вход под пользователем
void menuUser(); //меню пользователя
void addCredit(); //меня добвления
int checkDate(char*); // проверка даты
void header(void); // таблица
void printCredit();// вывод таблицы 
void printOne(int);// вывод таблицы для одного кредита
void deleteMenu(); // меню удаления
void deleteAll(); // удалить все записи
void deleteCredit(); // удалить одну запись
void redactMenu();//меню редактирования
void redactOneCreditAll(int&);//редактирование одной записи полностью
void menuSearch(); // меню поиска
void menuSort();//меню сортировки
void printSortedCredit(int, Credit*);//вывод отсортированных кредитов
void manageUsers(); //меню управления пользователями
void showAllUsers(FILE *);//показать пользователей
void deleteUsers(FILE *);//удалить пользователя
void redactPassUser(FILE *);//изменить пароль пользователя
void registrationUser();//регистрация пользователя 
int checkForNumbers();
void decrypt(char * s);//расшифровать пароль
void encrypt(char* s);//зашифровать пароль
void task();