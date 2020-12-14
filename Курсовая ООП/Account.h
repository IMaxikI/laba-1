#pragma once
#include "Menu.h"
using namespace std;
const string FileAccounts = "Accounts.txt";



class Account {
private:
	string login;
	string password;
	int role;
	int access;
public:
	Account() {
		role = 0;
		access = 0;
	}
	Account(const Account& acc) {
		login = acc.login;
		password = acc.password;
		role = acc.role;
		access = acc.access;
	}
	string getLogin();
	string getPassword();
	int getRole();
	int getAccess();
	void changeLogin(string);
	void changePassword(string);
	void changeRole(int);
	void changeAccess(int);
	~Account() {}
	friend istream& operator>>(istream&, Account&);
	friend ostream& operator<<(ostream&, Account&);
	friend ifstream& operator>>(ifstream&, Account&);
	friend ofstream& operator<<(ofstream&, Account&);
};

void startScreen();
void authorization(Account*&, int&);
void registration(Account*&, int&);
void accountLogin(Account*&, int&);
void addMainAdminAccount(Account*&, int&);
//-------
void adminMode(Account*&, int&);
int menuAdmins(Account* acc);
void workAccounts(Account*&, int&);
bool viewingAccounts(Account*, int);
void addAccount(Account*&, int&);
void updateAcconts(Account*&, int);
int menuUpdateAccounts(Account*, int);
void deleteAccounts(Account*&, int&);
//-------
void mainAdminMode(Account*& , int& );
void workAccountsMainAdmin(Account*& , int& );
bool viewingAccountsMainAdmin(Account* , int );
bool viewingMainAdmin(Account* accounts, int NumberAcc);
void addAccountMainAdmin(Account*& accounts, int& NumberAcc);
void updateAccountsMainAdmin(Account*& accounts, int NumberAcc);
int menuUpdateMainAdmin(Account* accounts, int number);
void deleteAccountsMainAdmin(Account*& accounts, int& NumberAcc);

void writeFileAccounts(Account*, int);
void readFileAccounts(Account*, int&);

int getCountStructuresInFileAccounts(string);
