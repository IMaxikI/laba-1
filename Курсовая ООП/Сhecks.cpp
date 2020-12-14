#include "Сhecks.h"
#include "Account.h"

void setConsole() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}
void createFile(string File) {
	ifstream file;
	file.open(File);
	if (!file) {
		cout << "Файл с именем " << File << " создан" << endl;
		ofstream fout(File, ios::out); 
		fout.close();
	}
	file.close();
}

string inputString() {
	string word;
	int Knopka;
	char simvol;
	while (true) {
		Knopka = _getch();
		if (Knopka == 8) {
			if (word.length() != 0) {
				cout << '\b' << " " << '\b';
				word.erase(word.length() - 1);
			}
		}
		else
			if (Knopka == 13 && word.length() != 0) break;
			else {
				simvol = (char)Knopka;
				if ((simvol >= 'а' && simvol <= 'я') || (simvol >= 'А' && simvol <= 'Я') || simvol == ' ' || simvol == '.') {
					word = word + simvol;
					cout << simvol;
				}
			}
	}
	cout << endl;
	return word;
}
int inputPages() {
	string number;
	int i;
	char par;
	while (true)
	{

		i = _getch();
		if (i == 8) {
			if (number.length() != 0) {
				cout << '\b' << " " << '\b';
				number.erase(number.length() - 1);
			}
		}
		else
			if (i == 13 && number.length() != 0) break;
			else
			{
				par = (char)i;
				if (i >= '0' && i <= '9') {

					number = number + par;
					cout << par;
				}
			}
	}
	cout << endl;
	return stoi(number);
}
int inputNumber(int NumberBook) {
	string number;
	int i;
	char par;
	while (true)
	{

		i = _getch();
		if (i == 8) {
			if (number.length() != 0) {
				cout << '\b' << " " << '\b';
				number.erase(number.length() - 1);
			}
		}
		else
			if (i == 13 && number.length() != 0 && stoi(number) != 0 && stoi(number) <= NumberBook) break;
			else
			{
				par = (char)i;
				if (i >= '0' && i <= '9') {

					number = number + par;
					cout << par;
				}
			}
	}
	cout << endl;
	return stoi(number);
}
int inputYear() {
	string year;
	int key;
	char par;
	while (true)
	{
		
		key = _getch();
		if (key == 8) {
			if (year.length() != 0) {
				cout << '\b' << " " << '\b';
				year.erase(year.length() - 1);
			}
		}
		else
			if (key == 13 && year.length() == 4 && stoi(year)<=2020 ) break;
			else
			{
				par = (char)key;
				if (key >= '0' && key <= '9') {

					year = year + par;
					cout << par;
				}
			}
	}
	cout << endl;
	return stoi(year);
}

string inputLogin() {
	string login;
	int knopka;
	char simvol;
	while (true) {
		knopka = _getch();
		if (knopka == 8) {
			if (login.length() != 0) {
				cout << '\b' << " " << '\b';
				login.erase(login.length() - 1);
			}
		}
		else
			if (knopka == 13 && login.length() >= 4) break;
			else {
				simvol = (char)knopka;
				if ((simvol >= 'a' && simvol <= 'z') || (simvol >= 'A' && simvol <= 'Z') || (simvol >= '0' && simvol <= '9')) {
					login = login + simvol;
					cout << simvol;
				}
			}
	}
	cout << endl;
	return login;
}
string checkLogin(Account* accounts, int NumberAcc) {
	string login;
	int exit;
	while (1)
	{
		exit = 0;
		cout << "Введите логин(не менее 4-х символов): ";
		login = inputLogin();
		for (int i = 0; i < NumberAcc; i++) {
			if (accounts[i].getLogin() == login) {
				cout << "Аккаунт с таким логином уже существует, выберите другой" << endl;
				system("pause");
				system("cls");
				exit++;
				break;
			}

		}
		if (exit == 0) {
			return login;
		}
	}
}

string inputPassword() {
	string password;
	int i;
	char par;
	while (true)
	{

		i = _getch();
		if (i == 8) {
			if (password.length() != 0) {
				cout << '\b' << " " << '\b';
				password.erase(password.length() - 1);
			}
		}
		else
			if (i == 13 && password.length() >= 4) break;
			else
				if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9')) {
					par = (char)i;
					password = password + par;
					cout << "*";
				}
	}
	cout << endl;
	return password;
}
string encryptPass(string pass) {
	string encrypt;
	for (int i = 0; i < pass.length(); i++) {
		char c = pass[i];
		c = c + '*';
		encrypt.push_back(c);
	}
	return encrypt;
}
string deencryptPass(string encrypt) {
	string deencrypt;
	for (int i = 0; i < encrypt.length(); i++) {
		char c = encrypt[i];
		c = c - '*';
		deencrypt.push_back(c);
	}
	return deencrypt;
}