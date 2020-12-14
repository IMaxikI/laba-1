#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <Windows.h>
#include "Account.h"
using namespace std;

void setConsole();
void createFile(string );
string inputString();
int inputPages();
int inputNumber(int NumberAcc);
string checkLogin(Account* accounts, int NumberAcc);
string inputLogin();
int inputYear();
string inputPassword();
string encryptPass(string );
string deencryptPass(string );