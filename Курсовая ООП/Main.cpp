#include "Menu.h"
#include "Account.h"
#include "Data.h"
#include "�hecks.h"
#include <Windows.h>


int main() {
	setConsole();
	createFile(FileAccounts);
	createFile(FileData);
	startScreen();
	return 0;
}
