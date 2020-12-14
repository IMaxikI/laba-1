#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include "Account.h"

using namespace std;


template <class T> class Interface {
public:
	int startMenu();
	int menuWorkAccounts();
	int menuDel();
	int menuAccess();
	int menuRole();
	int menuDataMode();
	int menuDataSearch();
	int menuDataSort();
	int menuDelData();
};

template <class T> int Interface<T>::startMenu()
{
	int ViborPunkta = 0, strelka = 0;
	while (true) {
		cout << "ВЫБЕРИТЕ ПУНКТ МЕНЮ" << endl;
		ViborPunkta = (ViborPunkta + 3) % 3;
		if (ViborPunkta == 0)	cout << "->Авторизация" << endl;
		else cout << " Авторизация" << endl;

		if (ViborPunkta == 1) cout << "->Регистрация" << endl;
		else cout << " Регистрация" << endl;

		if (ViborPunkta == 2) cout << "->Закрыть программу" << endl;
		else cout << " Закрыть программу" << endl;

		strelka = _getch();
		if (strelka == 224)
		{
			strelka = _getch();
			if (strelka == 72) ViborPunkta--;
			if (strelka == 80) ViborPunkta++;
		}
		if (strelka == 13)
		{
			system("cls");
			return ViborPunkta;
		}
		system("cls");
	}
}
template <class T> int Interface<T>::menuWorkAccounts()
{
	int ViborPunkta = 0, strelka = 0;
	while (true) {
		ViborPunkta = (ViborPunkta + 5) % 5;
		cout << "УПРАВЛЕНИЕ АККАУНТАМИ" << endl;
		if (ViborPunkta == 0)
			cout << "->Просмотр аккаунтов" << endl;
		else
			cout << " Просмотр аккаунтов" << endl;

		if (ViborPunkta == 1)
			cout << "->Регистрация аккаунта" << endl;
		else
			cout << " Регистрация аккаунта" << endl;

		if (ViborPunkta == 2)
			cout << "->Редактирование аккаунтов" << endl;
		else
			cout << " Редактирование аккаунтов" << endl;

		if (ViborPunkta == 3)
			cout << "->Удаление аккаунтов" << endl;
		else
			cout << " Удаление аккаунтов" << endl;

		if (ViborPunkta == 4)
			cout << "->Выход" << endl;
		else
			cout << " Выход" << endl;

		strelka = _getch();
		if (strelka == 224)
		{
			strelka = _getch();
			if (strelka == 72) ViborPunkta--;
			if (strelka == 80) ViborPunkta++;
		}
		if (strelka == 13)
		{
			system("cls");
			return ViborPunkta;
		}
		system("cls");
	}
}
template <class T> int Interface<T>::menuDel()
{
	int ViborPunkta = 0, strelka = 0;
	while (true) {
		cout << "ПОДТВЕРЖДЕНИЕ УДАЛЕНИЯ АККАУНТА" << endl;
		ViborPunkta = (ViborPunkta + 2) % 2;
		if (ViborPunkta == 0)	cout << "->Удалить" << endl;
		else cout << " Удалить" << endl;

		if (ViborPunkta == 1) cout << "->Не удалять" << endl;
		else cout << " Не удалять" << endl;

		strelka = _getch();
		if (strelka == 224)
		{
			strelka = _getch();
			if (strelka == 72) ViborPunkta--;
			if (strelka == 80) ViborPunkta++;
		}
		if (strelka == 13)
		{
			system("cls");
			return ViborPunkta;
		}
		system("cls");
	}
}
template <class T> int Interface<T>::menuAccess()
{
	int ViborPunkta = 0, strelka = 0;
	while (true) {
		cout << "Выберите доступ к системе" << endl;
		ViborPunkta = (ViborPunkta + 2) % 2;
		if (ViborPunkta == 0)	cout << "->Запретить" << endl;
		else cout << " Запретить" << endl;

		if (ViborPunkta == 1) cout << "->Разрешить" << endl;
		else cout << " Разрешить" << endl;

		strelka = _getch();
		if (strelka == 224)
		{
			strelka = _getch();
			if (strelka == 72) ViborPunkta--;
			if (strelka == 80) ViborPunkta++;
		}
		if (strelka == 13)
		{
			system("cls");
			return ViborPunkta;
		}
		system("cls");
	}
}
template <class T> int Interface<T>::menuRole()
{
	int ViborPunkta = 0, strelka = 0;
	while (true) {
		cout << "Выберите кого зарегистрировать" << endl;
		ViborPunkta = (ViborPunkta + 2) % 2;
		if (ViborPunkta == 0)	cout << "->Пользователя" << endl;
		else cout << " Пользователя" << endl;

		if (ViborPunkta == 1) cout << "->Администратора" << endl;
		else cout << " Администратора" << endl;

		strelka = _getch();
		if (strelka == 224)
		{
			strelka = _getch();
			if (strelka == 72) ViborPunkta--;
			if (strelka == 80) ViborPunkta++;
		}
		if (strelka == 13)
		{
			system("cls");
			return ViborPunkta;
		}
		system("cls");
	}
}
template <class T> int Interface<T>::menuDataMode()
{
	int ViborPunkta = 0, strelka = 0;
	while (true) {
		ViborPunkta = (ViborPunkta + 7) % 7;
		cout << "МОДУЛЬ ДЛЯ РАБОТЫ С ДАННЫМИ" << endl;
		if (ViborPunkta == 0)
			cout << "->Просмотр данных" << endl;
		else
			cout << " Просмотр данных" << endl;

		if (ViborPunkta == 1)
			cout << "->Добавление новой записи" << endl;
		else
			cout << " Добавление новой записи" << endl;

		if (ViborPunkta == 2)
			cout << "->Редактирование записи" << endl;
		else
			cout << " Редактирование записи" << endl;

		if (ViborPunkta == 3)
			cout << "->Поиск данных" << endl;
		else
			cout << " Поиск данных" << endl;

		if (ViborPunkta == 4)
			cout << "->Сортировка данных" << endl;
		else
			cout << " Сортировка данных" << endl;

		if (ViborPunkta == 5)
			cout << "->Удаление записи" << endl;
		else
			cout << " Удаление записи" << endl;

		if (ViborPunkta == 6)
			cout << "->Выход" << endl;
		else
			cout << " Выход" << endl;

		strelka = _getch();
		if (strelka == 224)
		{
			strelka = _getch();
			if (strelka == 72) ViborPunkta--;
			if (strelka == 80) ViborPunkta++;
		}
		if (strelka == 13)
		{
			system("cls");
			return ViborPunkta;
		}
		system("cls");
	}

}
template <class T> int Interface<T>::menuDataSearch()
{
	int ViborPunkta = 0, strelka = 0;
	while (true) {
		ViborPunkta = (ViborPunkta + 3) % 3;
		cout << "ПОИСК ДАННЫХ" << endl;
		if (ViborPunkta == 0)
			cout << "->Поиск по названию книги" << endl;
		else
			cout << " Поиск по названию книги" << endl;

		if (ViborPunkta == 1)
			cout << "->Поиск по количеству страниц" << endl;
		else
			cout << " Поиск по количеству страниц" << endl;

		if (ViborPunkta == 2)
			cout << "->Выход" << endl;
		else
			cout << " Выход" << endl;

		strelka = _getch();
		if (strelka == 224)
		{
			strelka = _getch();
			if (strelka == 72) ViborPunkta--;
			if (strelka == 80) ViborPunkta++;
		}
		if (strelka == 13)
		{
			system("cls");
			return ViborPunkta;
		}
		system("cls");
	}

}
template <class T> int Interface<T>::menuDataSort()
{
	int ViborPunkta = 0, strelka = 0;
	while (true) {
		ViborPunkta = (ViborPunkta + 3) % 3;
		cout << "СОРТИРОВКА ДАННЫХ" << endl;
		if (ViborPunkta == 0)
			cout << "->Сортировка по названию книги" << endl;
		else
			cout << " Сортировка по названию книги" << endl;

		if (ViborPunkta == 1)
			cout << "->Сортировка по количеству страниц" << endl;
		else
			cout << " Сортировка по количеству страниц" << endl;

		if (ViborPunkta == 2)
			cout << "->Выход" << endl;
		else
			cout << " Выход" << endl;

		strelka = _getch();
		if (strelka == 224)
		{
			strelka = _getch();
			if (strelka == 72) ViborPunkta--;
			if (strelka == 80) ViborPunkta++;
		}
		if (strelka == 13)
		{
			system("cls");
			return ViborPunkta;
		}
		system("cls");
	}

}
template <class T> int Interface<T>::menuDelData()
{
	int ViborPunkta = 0, strelka = 0;
	while (true) {
		cout << "ПОДТВЕРЖДЕНИЕ УДАЛЕНИЯ ЗАПИСИ" << endl;
		ViborPunkta = (ViborPunkta + 2) % 2;
		if (ViborPunkta == 0)	cout << "->Удалить" << endl;
		else cout << " Удалить" << endl;

		if (ViborPunkta == 1) cout << "->Не удалять" << endl;
		else cout << " Не удалять" << endl;

		strelka = _getch();
		if (strelka == 224)
		{
			strelka = _getch();
			if (strelka == 72) ViborPunkta--;
			if (strelka == 80) ViborPunkta++;
		}
		if (strelka == 13)
		{
			system("cls");
			return ViborPunkta;
		}
		system("cls");
	}
}