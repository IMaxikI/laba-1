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
		cout << "�������� ����� ����" << endl;
		ViborPunkta = (ViborPunkta + 3) % 3;
		if (ViborPunkta == 0)	cout << "->�����������" << endl;
		else cout << " �����������" << endl;

		if (ViborPunkta == 1) cout << "->�����������" << endl;
		else cout << " �����������" << endl;

		if (ViborPunkta == 2) cout << "->������� ���������" << endl;
		else cout << " ������� ���������" << endl;

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
		cout << "���������� ����������" << endl;
		if (ViborPunkta == 0)
			cout << "->�������� ���������" << endl;
		else
			cout << " �������� ���������" << endl;

		if (ViborPunkta == 1)
			cout << "->����������� ��������" << endl;
		else
			cout << " ����������� ��������" << endl;

		if (ViborPunkta == 2)
			cout << "->�������������� ���������" << endl;
		else
			cout << " �������������� ���������" << endl;

		if (ViborPunkta == 3)
			cout << "->�������� ���������" << endl;
		else
			cout << " �������� ���������" << endl;

		if (ViborPunkta == 4)
			cout << "->�����" << endl;
		else
			cout << " �����" << endl;

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
		cout << "������������� �������� ��������" << endl;
		ViborPunkta = (ViborPunkta + 2) % 2;
		if (ViborPunkta == 0)	cout << "->�������" << endl;
		else cout << " �������" << endl;

		if (ViborPunkta == 1) cout << "->�� �������" << endl;
		else cout << " �� �������" << endl;

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
		cout << "�������� ������ � �������" << endl;
		ViborPunkta = (ViborPunkta + 2) % 2;
		if (ViborPunkta == 0)	cout << "->���������" << endl;
		else cout << " ���������" << endl;

		if (ViborPunkta == 1) cout << "->���������" << endl;
		else cout << " ���������" << endl;

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
		cout << "�������� ���� ����������������" << endl;
		ViborPunkta = (ViborPunkta + 2) % 2;
		if (ViborPunkta == 0)	cout << "->������������" << endl;
		else cout << " ������������" << endl;

		if (ViborPunkta == 1) cout << "->��������������" << endl;
		else cout << " ��������������" << endl;

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
		cout << "������ ��� ������ � �������" << endl;
		if (ViborPunkta == 0)
			cout << "->�������� ������" << endl;
		else
			cout << " �������� ������" << endl;

		if (ViborPunkta == 1)
			cout << "->���������� ����� ������" << endl;
		else
			cout << " ���������� ����� ������" << endl;

		if (ViborPunkta == 2)
			cout << "->�������������� ������" << endl;
		else
			cout << " �������������� ������" << endl;

		if (ViborPunkta == 3)
			cout << "->����� ������" << endl;
		else
			cout << " ����� ������" << endl;

		if (ViborPunkta == 4)
			cout << "->���������� ������" << endl;
		else
			cout << " ���������� ������" << endl;

		if (ViborPunkta == 5)
			cout << "->�������� ������" << endl;
		else
			cout << " �������� ������" << endl;

		if (ViborPunkta == 6)
			cout << "->�����" << endl;
		else
			cout << " �����" << endl;

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
		cout << "����� ������" << endl;
		if (ViborPunkta == 0)
			cout << "->����� �� �������� �����" << endl;
		else
			cout << " ����� �� �������� �����" << endl;

		if (ViborPunkta == 1)
			cout << "->����� �� ���������� �������" << endl;
		else
			cout << " ����� �� ���������� �������" << endl;

		if (ViborPunkta == 2)
			cout << "->�����" << endl;
		else
			cout << " �����" << endl;

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
		cout << "���������� ������" << endl;
		if (ViborPunkta == 0)
			cout << "->���������� �� �������� �����" << endl;
		else
			cout << " ���������� �� �������� �����" << endl;

		if (ViborPunkta == 1)
			cout << "->���������� �� ���������� �������" << endl;
		else
			cout << " ���������� �� ���������� �������" << endl;

		if (ViborPunkta == 2)
			cout << "->�����" << endl;
		else
			cout << " �����" << endl;

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
		cout << "������������� �������� ������" << endl;
		ViborPunkta = (ViborPunkta + 2) % 2;
		if (ViborPunkta == 0)	cout << "->�������" << endl;
		else cout << " �������" << endl;

		if (ViborPunkta == 1) cout << "->�� �������" << endl;
		else cout << " �� �������" << endl;

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