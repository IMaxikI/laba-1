#include "Account.h"
#include "Data.h"
#include "Menu.h"
#include "Сhecks.h"

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
	cout << "Введите логин: ";
	acc.login= inputLogin();
	cout << "Введите пароль: ";
	acc.password = inputPassword(); 
	cout << "Введите роль(1-админ, 0-пользователь): ";
	in >> acc.role;
	cout << "Введите доступ к системе (1-есть, 0-нет): ";
	in >> acc.access;
	return in;
}
ostream& operator<<(ostream& out, Account& acc)
{
	out << "Логин: " << acc.login << endl;
	out << "Пароль: " << acc.password << endl;
	if (acc.access == 0) out << "Доступ к системе: нет" << endl << endl;
	else  out << "Доступ к системе: есть " << endl << endl; 
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
		cout << "Аккаунтов нет!\nЗарегистрируйте главного администратора!" << endl;
		addMainAdminAccount(accounts, NumberAcc);
		system("cls");
		cout << "\nВы успешно зарегестрированы и вошли в систему как главный администратор:" << accounts[0].getLogin() << endl;
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
		cout << "АВТОРИЗАЦИЯ" << endl;
		cout << "Логин: ";
		log = inputLogin();
		cout << "Пароль: ";
		pass = inputPassword();
		for (int i = 0; i < NumberAcc; i++) {
			if (log == accounts[i].getLogin() && pass == accounts[i].getPassword()) {
				if (accounts[i].getAccess() == 1)
				{
					if (accounts[i].getRole() == 2) {
						exit++;
						system("cls");
						cout << "\nВы вошли в систему как главный администратор: " << accounts[i].getLogin() << "!!\n\n";
						system("pause");
						system("cls");
						mainAdminMode(accounts, NumberAcc);
						return;
					}
					else if (accounts[i].getRole() == 1) {
						exit++;
						system("cls");
						cout << "\nВы вошли в систему как администратор: " << accounts[i].getLogin() << "!!\n\n";
						system("pause");
						system("cls");
						adminMode(accounts, NumberAcc);
						return;
					}
					else if (accounts[i].getRole() == 0) {
						exit++;
						system("cls");
						cout << "\nВы вошли в систему как пользователь: " << accounts[i].getLogin() << "!!\n\n";
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
			cout << "Ваш аккаунт не имеет доступа к системе, ждите активации!!!\n";
			system("pause");
			system("cls");
			break;
		}
		else  if (exit == 0) {
			cout << "Неверный логин или пароль, попробуйте заново!!!\n";
			system("pause");
			system("cls");
			break;
		}
		else break;
	}
}
void addMainAdminAccount(Account*& accounts, int& NumberAcc) {
	string password, login;
	cout << "РЕГИСТРАЦИЯ ГЛАВНОГО АДМИНИСТРАТОРА" << endl;
	cout << "Введите логин(не менее  4-х символов): ";
	login = inputLogin();
	cout << "Введите пароль(не менее  4-х символов): ";
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
		cout << "Аккаунтов нет!\nЗарегистрируйте главного администратора!" << endl;
		system("pause");
		system("cls");
		addMainAdminAccount(accounts, NumberAcc);
		cout << "\nВы успешно зарегистрированы и вошли в систему как главный администратор:" << accounts[0].getLogin() << endl;
		system("pause");
		system("cls");
		mainAdminMode(accounts, NumberAcc);
		return;
	}
	else {
		string login, password;
		cout << "РЕГИСТРАЦИЯ" << endl;
		login = checkLogin(accounts,NumberAcc);
		cout << "Введите пароль(не менее  4-х символов): ";
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
		cout << "Регистрация прошла успешно!\nЖдите получение доступа!" << endl;
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
		if(acc[0].getRole()==2)  cout << "МОДУЛЬ ГЛАВНОГО АДМИНИСТРАТОРА" << endl;
		else cout << "МОДУЛЬ АДМИНИСТРАТОРА" << endl;

		if (ViborPunkta == 0)
			cout << "->Управление аккаунтами" << endl;
		else
			cout << " Управление аккаунтами" << endl;

		if (ViborPunkta == 1)
			cout << "->Работа с данными" << endl;
		else
			cout << " Работа с данными" << endl;

		if (ViborPunkta == 2)
			cout << "->Выход из аккаунта" << endl;
		else
			cout << " Выход из аккаунта" << endl;

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
				cout << "Аккаунтов нет!" << endl;
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
			cout << "Пользователь №" << N << endl;
			cout << accounts[i];
		}
	}
	return number;
}
void addAccount(Account*& accounts, int& NumberAcc) {
	string login, password;
	int access;
	Interface <int>Menu;
	cout << "Регистрация пользователя" << endl;
	login = checkLogin(accounts, NumberAcc);
	cout << "Введите пароль(не менее  4-х символов): ";
	password = inputPassword(); 
	//cout << "Введите доступ: ";
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
	cout << "Аккаунт с логином " << login << " добавлен!" << endl;
	writeFileAccounts(accounts, NumberAcc);
}
void updateAcconts(Account*& accounts, int NumberAcc) {
	int number, access,exit=0;
	string login, password;
	Interface <int>Menu;
	if (!viewingAccounts(accounts, NumberAcc)) {
		cout << "Аккаунтов нет!" << endl;
		return;
	}
	cout << "Введите логин аккаунта, для редактирования его данных: ";
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
		cout << "Аккаунта с логином " << login << " нет!" << endl;
		return;
	}
	system("cls");
	switch (menuUpdateAccounts(accounts, number))
	{
	case 0:
		cout << "Введите новый логин " << endl;
		login = checkLogin(accounts,NumberAcc);
		accounts[number].changeLogin(login);
		system("cls");
		cout << "Логин изменён на " << login << endl;
		break;
	case 1:
		cout << "Введите новый пароль(не менее  4-х символов): ";
		password = inputPassword();
		accounts[number].changePassword(password);
		system("cls");
		cout << "Пароль изменён!" << endl;
		break;
	case 2:
		access = Menu.menuAccess();
		accounts[number].changeAccess(access);
		system("cls");
		cout << "Доступ изменён!" << endl;
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
		cout << "ВЫБЕРИТЕ ЧТО ИЗМЕНИТЬ" << endl;
		if (ViborPunkta == 0)
			cout << "->Логин: " << accounts[number].getLogin() << endl;
		else
			cout << " Логин: " << accounts[number].getLogin() << endl;

		if (ViborPunkta == 1)
			cout << "->Пароль: " << accounts[number].getPassword() << endl;
		else
			cout << " Пароль: " << accounts[number].getPassword() << endl;

		if (ViborPunkta == 2) {
			if (accounts[number].getAccess() == 0) cout << "->Доступ к системе: нет" << endl;
			else cout << "->Доступ к системе: есть " << endl;
		}
		else {
			if (accounts[number].getAccess() == 0) cout << " Доступ к системе: нет" << endl;
			else cout << " Доступ к системе: есть " << endl;
		}

		if (ViborPunkta == 3)
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
void deleteAccounts(Account*& accounts, int& NumberAcc) {
	string login;
	Interface <int>Menu;
	int number, potverdit,exit=0;
	if (!viewingAccounts(accounts, NumberAcc)) {
		cout << "Аккаунтов нет!" << endl;
		return;
	}
	cout << "Введите логин пользователя, которого хотите удалить: ";
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
		cout << "Пользователей с логином " << login << " нет!" << endl;
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
		cout << "Аккаунт с логином " << login << " удален!" << endl;
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
				cout << "Аккаунтов нет!" << endl;
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
			cout << "Пользователь №" << N << endl;
			cout << accounts[i];
		}
		if (accounts[i].getRole() == 1) {
			number = true;
			Nadmin++;
			cout << "Администратор №"<< Nadmin << endl;
			cout << accounts[i];
		}
	}
	return number;
}
bool viewingMainAdmin(Account* accounts, int NumberAcc)
{
	bool number = false;
	cout << "Главный администратор" << endl;
	cout << accounts[0];
	return number;
}
void addAccountMainAdmin(Account*& accounts, int& NumberAcc) {
	string login, password;
	int access, role;
	Interface <int>Menu;
	role = Menu.menuRole();
	cout << "РЕГИСТРАЦИЯ АККАУНТА" << endl;
	login = checkLogin(accounts, NumberAcc);
	cout << "Введите пароль(не менее  4-х символов): ";
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
	cout << "Аккаунт с логином " << login << " добавлен!" << endl;
	writeFileAccounts(accounts, NumberAcc);
}
void updateAccountsMainAdmin(Account*& accounts, int NumberAcc) {
	int number, access, exit = 0;
	string login, password;
	Interface <int>Menu;
	if (!(viewingMainAdmin(accounts,NumberAcc)) && !viewingAccountsMainAdmin(accounts, NumberAcc)) {
		cout << "Аккаунтов нет!" << endl;
		return;
	}
	cout << "Введите логин аккаунта, для редактирования его данных: ";
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
		cout << "Аккаунтов с логином " << login << " нет!" << endl;
		return;
	}
	system("cls");
	int menu;
	if (accounts[number].getRole() == 2)  menu = menuUpdateMainAdmin(accounts, number);
	else menu= menuUpdateAccounts(accounts, number);
	switch (menu)
	{
	case 0:
		cout << "Введите новый логин " << endl;
		login = checkLogin(accounts,NumberAcc);
		accounts[number].changeLogin(login);
		system("cls");
		cout << "Логин изменён на " << login << endl;
		break;
	case 1:
		cout << "Введите новый пароль(не менее 4-х символов): ";
		password = inputPassword();
		accounts[number].changePassword(password);
		system("cls");
		cout << "Пароль изменён!" << endl;
		break;
	case 2:
		access = Menu.menuAccess();
		accounts[number].changeAccess(access);
		system("cls");
		cout << "Доступ изменён!" << endl;
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
		cout << "ВЫБЕРИТЕ ЧТО ИЗМЕНИТЬ" << endl;
		if (ViborPunkta == 0)
			cout << "->Логин: " << accounts[number].getLogin() << endl;
		else
			cout << " Логин: " << accounts[number].getLogin() << endl;

		if (ViborPunkta == 1)
			cout << "->Пароль: " << accounts[number].getPassword() << endl;
		else
			cout << " Пароль: " << accounts[number].getPassword() << endl;

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
		cout << "Аккаунтов нет!" << endl;
		return;
	}
	cout << "Введите логин аккаунта, которого хотите удалить: ";
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
		cout << "Аккаунтов с логином " << login << " нет!" << endl;
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
		cout << "Аккаунт с логином " << login << " удален!" << endl;
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
