// ConsoleApplication62.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct data//структоур дата - год месяц день
{
	int year;
	int month;
	int day;
};
struct vremya//структура время - час минута
{
	int hour;
	int minute;
};

struct zvonok//структура звонок
{
	char ot_kogo[100];//от кого
	char ot_kogotel[100];//от кого номер
	char  komu[100];//кому
	char  komutel[100];//кому  номер
	data date;//дата
	vremya vr;//время
	int dlitelnost;//длительность
};


void scitivaniye(zvonok a[1000], int &kol)//считывание с файла
{
	ifstream file("memory.txt");//открыли файл
	string str;
	kol = 0;
	while (std::getline(file, str))//считали строку
	{
		char c[300];
		strcpy(c, str.c_str());//разделяем строку на поля и заносим в массив
		try
		{
			char *str1 = strtok(c, "|");
			strcpy(a[kol].ot_kogo, str1);
			str1 = strtok(NULL, "|");
			strcpy(a[kol].ot_kogotel, str1);
			str1 = strtok(NULL, "|");
			strcpy(a[kol].komu, str1);
			str1 = strtok(NULL, "|");
			strcpy(a[kol].komutel, str1);
			str1 = strtok(NULL, "|");
			a[kol].date.year = atoi(str1);
			str1 = strtok(NULL, "|");
			a[kol].date.month = atoi(str1);
			str1 = strtok(NULL, "|");
			a[kol].date.day = atoi(str1);
			str1 = strtok(NULL, "|");
			a[kol].vr.hour = atoi(str1);
			str1 = strtok(NULL, "|");
			a[kol].vr.minute = atoi(str1);
			str1 = strtok(NULL, "|");
			a[kol].dlitelnost = atoi(str1);
			kol = kol + 1;
		}
		catch (int a)
		{

		}
	}
}

void zapis(zvonok a[1000], int &kol)//запись в файл при закрытии
{
	fstream file("memory.txt");
	string str;
	for (int i = 0; i<kol; i++)//идем в цикле
	{
		file << a[i].ot_kogo << "|" << a[i].ot_kogotel << "|" << a[i].komu << "|" << a[i].komutel << "|" << a[i].date.year << "|" << a[i].date.month << "|" << a[i].date.day << "|" << a[i].vr.hour << "|" << a[i].vr.minute << "|" << a[i].dlitelnost << endl;
	}
	file.close();//закрываем файл
}

void vivod(zvonok a[1000], int kol)//вывод
{
	for (int i = 0; i<kol; i++)//идем в цикле и выводим все поля
	{
		cout << (i + 1) << ") " << a[i].ot_kogo << " " << a[i].ot_kogotel << " " << a[i].komu << " " << a[i].komutel << " " << a[i].date.year << ":" << a[i].date.month << ":" << a[i].date.day << " " << a[i].vr.hour << ":" << a[i].vr.minute << " " << a[i].dlitelnost << endl;
	}
}
void dobavit(zvonok a[1000], int &kol)//добавление - вводим все поля и заносим в массив
{
	cout << "Vvedite ot kogo zvonok: ";
	cin >> a[kol].ot_kogo;
	cout << "Vvedite ot kogo zvonok(nomer): ";
	cin >> a[kol].ot_kogotel;
	cout << "Vvedite komu zvonok: ";
	cin >> a[kol].komu;
	cout << "Vvedite komu zvonok(nomer): ";
	cin >> a[kol].komutel;

	cout << "Vvedite god : ";
	cin >> a[kol].date.year;
	cout << "Vvedite mesyac : ";
	cin >> a[kol].date.month;
	cout << "Vvedite den : ";
	cin >> a[kol].date.day;

	cout << "Vvedite chas : ";
	cin >> a[kol].vr.hour;
	cout << "Vvedite minutu : ";
	cin >> a[kol].vr.minute;

	cout << "Vvedite dlitelnost : ";
	cin >> a[kol].dlitelnost;
	kol++;
}
void udalit(zvonok a[1000], int &kol)//удаление - вводим номер записи и смещаем массив после нее влево
{
	int num;
	cout << "Vvedite nomer zapisi: ";
	cin >> num;
	num = num - 1;
	for (int i = num; i<kol; i++)
	{
		a[i] = a[i + 1];
	}
	kol--;

}
void datetodate(zvonok a[1000], int kol, int year1, int month1, int day1, int year2, int month2, int day2)//вывод с даты по дату
{
	for (int i = 0; i<kol; i++)
	{
		if (a[i].date.day >= year1&&a[i].date.day <= year2)
		{

			cout << a[i].ot_kogo << " " << a[i].ot_kogotel << " " << a[i].komu[100] << " " << a[i].komutel << endl;//
		}
	}
}
void sort1(zvonok a[1000], int kol)//сортировка пузырьком по длительности
{
	for (int i = 0; i < kol - 1; i++)
	{
		for (int j = 0; j < kol - i - 1; j++)
		{
			if (a[j].dlitelnost > a[j + 1].dlitelnost)
			{
				zvonok temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void sortdate(zvonok a[1000], int kol)//сортировка пузырьком по дате
{
	for (int i = 0; i < kol - 1; i++)
	{
		for (int j = 0; j < kol - i - 1; j++)
		{
			if (a[j].date.year > a[j + 1].date.year || a[j].date.year == a[j + 1].date.year&&a[j].date.month > a[j + 1].date.month || a[j].date.year == a[j + 1].date.year&&a[j].date.month == a[j + 1].date.month
				&&a[j].date.day > a[j + 1].date.day)
			{
				zvonok temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void vivodto(zvonok a[1000], int kol)//вывод только звонков от опеределенному человеку
{
	char ot_kogo[100];
	cout << "Vvedite ot kogo zvonok: ";
	cin >> ot_kogo;
	for (int i = 0; i<kol; i++)
	{
		if (strcmp(a[i].ot_kogo, ot_kogo) == 0)
		{
			cout << (i + 1) << ") " << a[i].ot_kogo << " " << a[i].ot_kogotel << " " << a[i].komu << " " << a[i].komutel << " " << a[i].date.year << ":" << a[i].date.month << ":" << a[i].date.day << " " << a[i].vr.hour << ":" << a[i].vr.minute << " " << a[i].dlitelnost << endl;
		}
	}
}

void vivodot(zvonok a[1000], int kol)//вывод только звонков от опеределенного человека
{
	char komu[100];
	cout << "Vvedite ot kogo zvonok: ";
	cin >> komu;
	for (int i = 0; i<kol; i++)
	{
		if (strcmp(a[i].komu, komu) == 0)
		{
			cout << (i + 1) << ") " << a[i].ot_kogo << " " << a[i].ot_kogotel << " " << a[i].komu << " " << a[i].komutel << " " << a[i].date.year << ":" << a[i].date.month << ":" << a[i].date.day << " " << a[i].vr.hour << ":" << a[i].vr.minute << " " << a[i].dlitelnost << endl;
		}
	}
}


int main()//мейн
{
	zvonok a[100];//массив
	int kol = 0;//кол-во
	scitivaniye(a, kol);//считывание
	while (true)//цикл
	{
		int num;//выводим меню
		cout << "1)Vivod\n";
		cout << "2)Dobavit\n";
		cout << "3)Udalit\n";
		cout << "4)Vivod s dati po datu\n";
		cout << "5)Sortirovka po dlitelnosti\n";
		cout << "6)Sortirovka po davnosti\n";
		cout << "7)Vivod ot konkretnogo cheloveka\n";
		cout << "8)Vivod k konkretnomu cheloveku\n";
		cout << "9)Vihod\n";
		cin >> num;
		if (num == 1)//если выбрали 1 - вызываем вывод
		{
			vivod(a, kol);
		}
		if (num == 2)//если выбрали 2 - вызываем добавление
		{
			dobavit(a, kol);
		}
		if (num == 3)//если выбрали 3 - вызываем удаление
		{
			udalit(a, kol);//
		}
		if (num == 4)//если выбрали 4 - вызываем вывод с даты по дату
		{
			try
			{
				int year1;
				int month1;
				int day1;
				int year2;
				int month2;
				int day2;
				cout << "Vvedite god : ";
				cin >> year1;
				cout << "Vvedite mesyac : ";
				cin >> month1;
				cout << "Vvedite den : ";
				cin >> day1;
				cout << "Vvedite god : ";
				cin >> year2;
				cout << "Vvedite mesyac : ";
				cin >> month2;
				cout << "Vvedite den : ";
				cin >> day2;
				datetodate(a, kol, year1, month1, day1, year2, month2, day2);
			}
			catch (int aa)
			{

			}
		}
		if (num == 5)//если выбрали 5 - соритруем по длителности и  выводим
		{
			sort1(a, kol);
			vivod(a, kol);
		}
		if (num == 6)//если выбрали 6 - соритруем по давности и выводим
		{
			sortdate(a, kol);
			vivod(a, kol);
		}
		if (num == 7)//вывод звонков опеределенному человеку
		{
			vivodto(a, kol);
		}
		if (num == 8)//вывод звонков от опеределенного человека
		{
			vivodot(a, kol);
		}
		if (num == 9)//выход
		{
			break;
		}
	}
	zapis(a, kol);//запись
	system("pause");//
	return 0;//
}