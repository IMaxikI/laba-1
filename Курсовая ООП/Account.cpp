#include "Account.h"
#include "Data.h"
#include "Menu.h"
#include "�hecks.h"

string Account::getLogin()
{
	return login;
}
string Account::getPassword()
{
	return password;
}
int Account::getRole()
{
	return role;
}
int Account::getAccess()
{
	return access;
}
void Account::changeLogin(string log)
{
	login = log;
}
void Account::changePassword(string pass)
{
	password = pass;
}
void Account::changeRole(int rol)
{
	role = rol;
}
void Account::changeAccess(int acces)
{
	access = acces;
}
istream& operator>>(istream& in, Account& acc)
{
	cout << "������� �����: ";
	acc.login= inputLogin();
	cout << "������� ������: ";
	acc.password = inputPassword(); 
	cout << "������� ����(1-�����, 0-������������): ";
	in >> acc.role;
	cout << "������� ������ � ������� (1-����, 0-���): ";
	in >> acc.access;
	return in;
}
ostream& operator<<(ostream& out, Account& acc)
{
	out << "�����: " << acc.login << endl;
	out << "������: " << acc.password << endl;
	if (acc.access == 0) out << "������ � �������: ���" << endl << endl;
	else  out << "������ � �������: ���� " << endl << endl; 
	return out;
}
ifstream& operator>>(ifstream& ifs, Account& acc)
{
	getline(ifs, acc.login);
	string pass;
	getline(ifs, pass);
	acc.password = deencryptPass(pass);
	string rol;
	getline(ifs, rol);
	acc.role = stoi(rol);
	string access;
	getline(ifs, access);
	acc.access = stoi(access);
	return ifs;
}
ofstream& operator<<(ofstream& fout, Account& acc)
{
	fout << acc.login << endl;
	fout << encryptPass(acc.password) << endl;
	fout << acc.role << endl;
	fout << acc.access << endl;
	return fout;
}


void startScreen()
{
	int NumberAcc = getCountStructuresInFileAccounts(FileAccounts);
	Account* accounts = new Account[NumberAcc];
	readFileAccounts(accounts, NumberAcc);
	Interface <int>Menu;
	while (true) {
		switch (Menu.startMenu()) {
		case 0:
			authorization(accounts, NumberAcc);
			break;
		case 1:
			registration(accounts, NumberAcc);
			break;
		case 2:
			return;
		}
	}
	delete[]accounts;
}

void authorization(Account*& accounts, int& NumberAcc) {


	if (NumberAcc == 0) {
		cout << "��������� ���!\n��������������� �������� ��������������!" << endl;
		addMainAdminAccount(accounts, NumberAcc);
		system("cls");
		cout << "\n�� ������� ���������������� � ����� � ������� ��� ������� �������������:" << accounts[0].getLogin() << endl;
		system("pause");
		system("cls");
		mainAdminMode(accounts, NumberAcc);
	}
	else {
		accountLogin(accounts, NumberAcc);
	}
}
void accountLogin(Account*& accounts, int& NumberAcc) {
	string log, pass;
	int exit, access;
	while (true) {
		exit = 0;
		access = 0;
		cout << "�����������" << endl;
		cout << "�����: ";
		log = inputLogin();
		cout << "������: ";
		pass = inputPassword();
		for (int i = 0; i < NumberAcc; i++) {
			if (log == accounts[i].getLogin() && pass == accounts[i].getPassword()) {
				if (accounts[i].getAccess() == 1)
				{
					if (accounts[i].getRole() == 2) {
						exit++;
						system("cls");
						cout << "\n�� ����� � ������� ��� ������� �������������: " << accounts[i].getLogin() << "!!\n\n";
						system("pause");
						system("cls");
						mainAdminMode(accounts, NumberAcc);
						return;
					}
					else if (accounts[i].getRole() == 1) {
						exit++;
						system("cls");
						cout << "\n�� ����� � ������� ��� �������������: " << accounts[i].getLogin() << "!!\n\n";
						system("pause");
						system("cls");
						adminMode(accounts, NumberAcc);
						return;
					}
					else if (accounts[i].getRole() == 0) {
						exit++;
						system("cls");
						cout << "\n�� ����� � ������� ��� ������������: " << accounts[i].getLogin() << "!!\n\n";
						system("pause");
						system("cls");
						WorkData();
						return;
					}

				}
				else {
					access++;
					break;
				}
			}
		}
		if (access != 0) {
			cout << "��� ������� �� ����� ������� � �������, ����� ���������!!!\n";
			system("pause");
			system("cls");
			break;
		}
		else  if (exit == 0) {
			cout << "�������� ����� ��� ������, ���������� ������!!!\n";
			system("pause");
			system("cls");
			break;
		}
		else break;
	}
}
void addMainAdminAccount(Account*& accounts, int& NumberAcc) {
	string password, login;
	cout << "����������� �������� ��������������" << endl;
	cout << "������� �����(�� �����  4-� ��������): ";
	login = inputLogin();
	cout << "������� ������(�� �����  4-� ��������): ";
	password = inputPassword();
	NumberAcc++;
	Account* ptr = new Account[NumberAcc];
	copy(accounts, accounts + NumberAcc - 1, ptr);
	accounts = ptr;
	ptr = NULL;
	delete[]ptr;
	accounts[NumberAcc - 1].changeLogin(login);
	accounts[NumberAcc - 1].changePassword(password);
	accounts[NumberAcc - 1].changeRole(2);
	accounts[NumberAcc - 1].changeAccess(1);
	writeFileAccounts(accounts, NumberAcc);
}
void registration(Account*& accounts, int& NumberAcc) {

	if (NumberAcc == 0) {
		cout << "��������� ���!\n��������������� �������� ��������������!" << endl;
		system("pause");
		system("cls");
		addMainAdminAccount(accounts, NumberAcc);
		cout << "\n�� ������� ���������������� � ����� � ������� ��� ������� �������������:" << accounts[0].getLogin() << endl;
		system("pause");
		system("cls");
		mainAdminMode(accounts, NumberAcc);
		return;
	}
	else {
		string login, password;
		cout << "�����������" << endl;
		login = checkLogin(accounts,NumberAcc);
		cout << "������� ������(�� �����  4-� ��������): ";
		password = inputPassword();
		NumberAcc++;
		Account* ptr = new Account[NumberAcc];
		copy(accounts, accounts + NumberAcc - 1, ptr);
		accounts = ptr;
		ptr = NULL;
		delete[]ptr;
		accounts[NumberAcc - 1].changeLogin(login);
		accounts[NumberAcc - 1].changePassword(password);
		accounts[NumberAcc - 1].changeRole(0);
		accounts[NumberAcc - 1].changeAccess(0);
		writeFileAccounts(accounts, NumberAcc);
		system("cls");
		cout << "����������� ������ �������!\n����� ��������� �������!" << endl;
		system("pause");
		system("cls");
	}
}

//----------------------

void adminMode(Account*& accounts, int& NumberAcc) {
	while (true) { 
		switch (menuAdmins(accounts))
		{
		case 0:
			workAccounts(accounts, NumberAcc);
			break;
		case 1:
			WorkData();
			break;
		case 2:
			return;
		}
	}
}
int menuAdmins(Account* acc)
{
	int ViborPunkta = 0, strelka = 0;
	while (true) {
		ViborPunkta = (ViborPunkta + 3) % 3;
		if(acc[0].getRole()==2)  cout << "������ �������� ��������������" << endl;
		else cout << "������ ��������������" << endl;

		if (ViborPunkta == 0)
			cout << "->���������� ����������" << endl;
		else
			cout << " ���������� ����������" << endl;

		if (ViborPunkta == 1)
			cout << "->������ � �������" << endl;
		else
			cout << " ������ � �������" << endl;

		if (ViborPunkta == 2)
			cout << "->����� �� ��������" << endl;
		else
			cout << " ����� �� ��������" << endl;

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
void workAccounts(Account*& accounts, int& NumberAcc) {
	Interface <int>Menu;
	while (true) {
		switch (Menu.menuWorkAccounts())
		{
		case 0:
			if (!viewingAccounts(accounts, NumberAcc)) {
				cout << "��������� ���!" << endl;
			}
			break;
		case 1:
			addAccount(accounts, NumberAcc);
			break;
		case 2:
			updateAcconts(accounts, NumberAcc);
			break;
		case 3:
			deleteAccounts(accounts,NumberAcc);
			break;
		case 4:
			return;
		}
		system("pause");
		system("cls");
	}
}
bool viewingAccounts(Account* accounts, int NumberAcc)
{
	bool number=false;
	int N=0;
	for (int i = 0; i < NumberAcc; i++)
	{
		if (accounts[i].getRole() == 0) {
			number = true;
			N++;
			cout << "������������ �" << N << endl;
			cout << accounts[i];
		}
	}
	return number;
}
void addAccount(Account*& accounts, int& NumberAcc) {
	string login, password;
	int access;
	Interface <int>Menu;
	cout << "����������� ������������" << endl;
	login = checkLogin(accounts, NumberAcc);
	cout << "������� ������(�� �����  4-� ��������): ";
	password = inputPassword(); 
	//cout << "������� ������: ";
	system("cls");
	access = Menu.menuAccess();
	NumberAcc++;
	Account* ptr = new Account[NumberAcc];
	copy(accounts, accounts + NumberAcc - 1, ptr);
	accounts = ptr;
	ptr = NULL;
	delete[]ptr;
	accounts[NumberAcc - 1].changeLogin(login);
	accounts[NumberAcc - 1].changePassword(password);
	accounts[NumberAcc - 1].changeRole(0);
	accounts[NumberAcc - 1].changeAccess(access);
	system("cls");
	cout << "������� � ������� " << login << " ��������!" << endl;
	writeFileAccounts(accounts, NumberAcc);
}
void updateAcconts(Account*& accounts, int NumberAcc) {
	int number, access,exit=0;
	string login, password;
	Interface <int>Menu;
	if (!viewingAccounts(accounts, NumberAcc)) {
		cout << "��������� ���!" << endl;
		return;
	}
	cout << "������� ����� ��������, ��� �������������� ��� ������: ";
	login = inputLogin();
	for (int i = 0; i < NumberAcc; i++)
	{
		if (login == accounts[i].getLogin() && accounts[i].getRole()==0) {
			exit++;
			number = i;
			break;
		}
	}
	if (exit == 0) {
		system("cls");
		cout << "�������� � ������� " << login << " ���!" << endl;
		return;
	}
	system("cls");
	switch (menuUpdateAccounts(accounts, number))
	{
	case 0:
		cout << "������� ����� ����� " << endl;
		login = checkLogin(accounts,NumberAcc);
		accounts[number].changeLogin(login);
		system("cls");
		cout << "����� ������ �� " << login << endl;
		break;
	case 1:
		cout << "������� ����� ������(�� �����  4-� ��������): ";
		password = inputPassword();
		accounts[number].changePassword(password);
		system("cls");
		cout << "������ ������!" << endl;
		break;
	case 2:
		access = Menu.menuAccess();
		accounts[number].changeAccess(access);
		system("cls");
		cout << "������ ������!" << endl;
		break;
	case 3:
		return;
	}
	writeFileAccounts(accounts, NumberAcc);
}
int menuUpdateAccounts(Account* accounts, int number)
{
	int ViborPunkta = 0, strelka = 0;
	while (true) {
		ViborPunkta = (ViborPunkta + 4) % 4;
		cout << "�������� ��� ��������" << endl;
		if (ViborPunkta == 0)
			cout << "->�����: " << accounts[number].getLogin() << endl;
		else
			cout << " �����: " << accounts[number].getLogin() << endl;

		if (ViborPunkta == 1)
			cout << "->������: " << accounts[number].getPassword() << endl;
		else
			cout << " ������: " << accounts[number].getPassword() << endl;

		if (ViborPunkta == 2) {
			if (accounts[number].getAccess() == 0) cout << "->������ � �������: ���" << endl;
			else cout << "->������ � �������: ���� " << endl;
		}
		else {
			if (accounts[number].getAccess() == 0) cout << " ������ � �������: ���" << endl;
			else cout << " ������ � �������: ���� " << endl;
		}

		if (ViborPunkta == 3)
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
void deleteAccounts(Account*& accounts, int& NumberAcc) {
	string login;
	Interface <int>Menu;
	int number, potverdit,exit=0;
	if (!viewingAccounts(accounts, NumberAcc)) {
		cout << "��������� ���!" << endl;
		return;
	}
	cout << "������� ����� ������������, �������� ������ �������: ";
	login = inputLogin();
	for (int i = 0; i < NumberAcc; i++)
	{
		if (login == accounts[i].getLogin() && accounts[i].getRole() == 0) {
			exit++;
			number = i;
			break;
		}
	}
	if (exit == 0) {
		system("cls");
		cout << "������������� � ������� " << login << " ���!" << endl;
		return;
	}
	system("cls");
	potverdit = Menu.menuDel();
	if (potverdit == 0) {
		for (int i = number; i < NumberAcc - 1; i++)
		{
		  accounts[i] = accounts[i + 1];
		}
		NumberAcc--;
		cout << "������� � ������� " << login << " ������!" << endl;
		writeFileAccounts(accounts, NumberAcc);
	}
	else return;
}

//-------------------------

void mainAdminMode(Account*& accounts, int& NumberAcc) {
	while (true) {
		switch (menuAdmins(accounts))
		{
		case 0:
			workAccountsMainAdmin(accounts, NumberAcc);
			break;
		case 1:
			WorkData();
			break;
		case 2:
			return;
		}
	}
}
void workAccountsMainAdmin(Account*& accounts, int& NumberAcc) {
	Interface <int>Menu;
	while (true) {
		switch (Menu.menuWorkAccounts())
		{
		case 0:
			if (!viewingAccountsMainAdmin(accounts, NumberAcc)) {
				cout << "��������� ���!" << endl;
			}
			break;
		case 1:
			addAccountMainAdmin(accounts, NumberAcc);
			break;
		case 2:
			updateAccountsMainAdmin(accounts, NumberAcc);
			break;
		case 3:
			deleteAccountsMainAdmin(accounts, NumberAcc);
			break;
		case 4:
			return;
		}
		system("pause");
		system("cls");
	}
}
bool viewingAccountsMainAdmin(Account* accounts, int NumberAcc)
{
	bool number = false;
	int N = 0, Nadmin = 0;
	for (int i = 0; i < NumberAcc; i++)
	{
		if (accounts[i].getRole() == 0) {
			number = true;
			N++;
			cout << "������������ �" << N << endl;
			cout << accounts[i];
		}
		if (accounts[i].getRole() == 1) {
			number = true;
			Nadmin++;
			cout << "������������� �"<< Nadmin << endl;
			cout << accounts[i];
		}
	}
	return number;
}
bool viewingMainAdmin(Account* accounts, int NumberAcc)
{
	bool number = false;
	cout << "������� �������������" << endl;
	cout << accounts[0];
	return number;
}
void addAccountMainAdmin(Account*& accounts, int& NumberAcc) {
	string login, password;
	int access, role;
	Interface <int>Menu;
	role = Menu.menuRole();
	cout << "����������� ��������" << endl;
	login = checkLogin(accounts, NumberAcc);
	cout << "������� ������(�� �����  4-� ��������): ";
	password = inputPassword();
	system("cls");
	access = Menu.menuAccess();
	NumberAcc++;
	Account* ptr = new Account[NumberAcc];
	copy(accounts, accounts + NumberAcc - 1, ptr);
	accounts = ptr;
	ptr = NULL;
	delete[]ptr;
	accounts[NumberAcc - 1].changeLogin(login);
	accounts[NumberAcc - 1].changePassword(password);
	accounts[NumberAcc - 1].changeRole(role);
	accounts[NumberAcc - 1].changeAccess(access);
	system("cls");
	cout << "������� � ������� " << login << " ��������!" << endl;
	writeFileAccounts(accounts, NumberAcc);
}
void updateAccountsMainAdmin(Account*& accounts, int NumberAcc) {
	int number, access, exit = 0;
	string login, password;
	Interface <int>Menu;
	if (!(viewingMainAdmin(accounts,NumberAcc)) && !viewingAccountsMainAdmin(accounts, NumberAcc)) {
		cout << "��������� ���!" << endl;
		return;
	}
	cout << "������� ����� ��������, ��� �������������� ��� ������: ";
	login = inputLogin();
	for (int i = 0; i < NumberAcc; i++)
	{
		if (login == accounts[i].getLogin()) {
			exit++;
			number = i;
			break;
		}
	}
	if (exit == 0) {
		system("cls");
		cout << "��������� � ������� " << login << " ���!" << endl;
		return;
	}
	system("cls");
	int menu;
	if (accounts[number].getRole() == 2)  menu = menuUpdateMainAdmin(accounts, number);
	else menu= menuUpdateAccounts(accounts, number);
	switch (menu)
	{
	case 0:
		cout << "������� ����� ����� " << endl;
		login = checkLogin(accounts,NumberAcc);
		accounts[number].changeLogin(login);
		system("cls");
		cout << "����� ������ �� " << login << endl;
		break;
	case 1:
		cout << "������� ����� ������(�� ����� 4-� ��������): ";
		password = inputPassword();
		accounts[number].changePassword(password);
		system("cls");
		cout << "������ ������!" << endl;
		break;
	case 2:
		access = Menu.menuAccess();
		accounts[number].changeAccess(access);
		system("cls");
		cout << "������ ������!" << endl;
		break;
	case 3:
		return;
	}
	writeFileAccounts(accounts, NumberAcc);
}
int menuUpdateMainAdmin(Account* accounts, int number)
{
	int ViborPunkta = 0, strelka = 0;
	while (true) {
		ViborPunkta = (ViborPunkta + 3) % 3;
		cout << "�������� ��� ��������" << endl;
		if (ViborPunkta == 0)
			cout << "->�����: " << accounts[number].getLogin() << endl;
		else
			cout << " �����: " << accounts[number].getLogin() << endl;

		if (ViborPunkta == 1)
			cout << "->������: " << accounts[number].getPassword() << endl;
		else
			cout << " ������: " << accounts[number].getPassword() << endl;

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
			if (ViborPunkta == 2) return 3;
			else return ViborPunkta;
		}
		system("cls");
	}

}
void deleteAccountsMainAdmin(Account*& accounts, int& NumberAcc) {
	string login;
	int number, potverdit, exit = 0;
	Interface <int>Menu;
	if (!viewingAccountsMainAdmin(accounts, NumberAcc)) {
		cout << "��������� ���!" << endl;
		return;
	}
	cout << "������� ����� ��������, �������� ������ �������: ";
	login = inputLogin();
	for (int i = 0; i < NumberAcc; i++)
	{
		if (login == accounts[i].getLogin() && (accounts[i].getRole() == 0 || accounts[i].getRole() == 1)) {
			exit++;
			number = i;
			break;
		}
	}
	if (exit == 0) {
		system("cls");
		cout << "��������� � ������� " << login << " ���!" << endl;
		return;
	}
	system("cls");
	potverdit = Menu.menuDel();
	if (potverdit == 0) {
		for (int i = number; i < NumberAcc - 1; i++)
		{
			accounts[i] = accounts[i + 1];
		}
		NumberAcc--;
		system("cls");
		cout << "������� � ������� " << login << " ������!" << endl;
		writeFileAccounts(accounts, NumberAcc);
	}
	else return;
}

//-----------------------

void writeFileAccounts(Account* accounts, int NumberAcc) {
	ofstream fout(FileAccounts, ios::out);
	for (int i = 0; i < NumberAcc; i++)
	{
		fout << accounts[i];
	}
	fout.close();
}
void readFileAccounts(Account* accounts, int& NumberAcc) {
	ifstream fin;
	fin.open(FileAccounts);
	int i = 0;
	while (fin.peek() != EOF)
	{
		fin >> accounts[i];
		i++;
	}
	NumberAcc = i;
	fin.close();
}
int getCountStructuresInFileAccounts(string FILE)
{
	int colvo_struct = 0;
	ifstream file(FILE, ios::in);
	if (file.is_open())
	{
		string tmp;
		while (getline(file, tmp))
			colvo_struct++;
	}
	file.close();
	return colvo_struct / 4;
}
