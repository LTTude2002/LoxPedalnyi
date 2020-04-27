#pragma once

struct Date {
	int day;
	int month;
	int year;
	char date_format[30]; //формат даты XX.XX.XXXX
};
struct CreditType {
	int codeCredit;
	char typeOfCredit[30];
	int rate;
};
struct Client {
	int codeClient;
	char clientName[30];
	char address[20];
	char guarantorName[30];

};
struct Credit {
	int ID;
	char name[30];
	int cost;
	Date date;
	CreditType creditType;
	Client client;
};

struct Users {
	char loginUser[20];
	char passwordUser[20];
};

