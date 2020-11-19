#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>

using namespace std;

double inputDouble();
string writeWords();
int menu();
int MenuChoice();


class Smeshariki {
protected:
	char* name;
	char* gender;
public:
	Smeshariki(char* name1, char* gender1) {
		name = new char[strlen(name1) + 1];
		strcpy_s(name, strlen(name1) + 1, name1);
		gender = new char[strlen(gender1) + 1];
		strcpy_s(gender, strlen(gender1) + 1, gender1);
	}
	virtual ~Smeshariki() = 0;
	virtual void See() = 0;
	virtual string getGrupp() = 0;
};

Smeshariki::~Smeshariki() {
	delete[]name;
	delete[]gender;
}

class Сhildren :virtual public Smeshariki {
protected:
	char* character;
	char* hobby;
public:
	Сhildren(char* name1, char* gender1, char* character1, char* hobby1) :Smeshariki(name1, gender1) {
		character = new char[strlen(character1) + 1];
		strcpy_s(character, strlen(character1) + 1, character1);
		hobby = new char[strlen(hobby1) + 1];
		strcpy_s(hobby, strlen(hobby1) + 1, hobby1);
	}
	~Сhildren() {
		delete[]character;
		delete[]hobby;
	}
	void See() {
		//system("cls");
		cout << "Имя: " << name << endl;
		cout << "Пол: " << gender << endl;
		cout << "Темпераметр: " << character << endl;
		cout << "Хобби: " << hobby << endl<<endl;
	}
	string getGrupp() {
		return "Дети";
	}

};

class Adults :virtual public Smeshariki {
protected:
	char* work;
	char* location;
public:
	Adults(char* name1, char* gender1, char* work1, char* location1) :Smeshariki(name1, gender1) {
		work = new char[strlen(work1) + 1];
		strcpy_s(work, strlen(work1) + 1, work1);
		location = new char[strlen(location1) + 1];
		strcpy_s(location, strlen(location1) + 1, location1);
	}
	~Adults() {
		delete[] work;
		delete[] location;
	}
	void See() {
	//	system("cls");
		cout << "Имя: " << name << endl;
		cout << "Пол: " << gender << endl;
		cout << "Работа:" << work << endl;
		cout << "Место проживания:" << location << endl << endl;
	}
	string getGrupp() {
		return "Взрослые";
	}
};

class Elderly :public Сhildren,public Adults {
	char* eat;
	double vision;
public:
	Elderly(char* name1, char* gender1,char* character1, char* hobby1, char* work1, char* location1,char* eat1, double vision1):Сhildren(name1,gender1,character1, hobby1), Adults(name1,gender1,work1,location1), Smeshariki(name1,gender1){
		eat = new char[strlen(eat1) + 1];
		strcpy_s(eat, strlen(eat1) + 1, eat1);
		vision = vision1;
	}
	~Elderly() {
		delete[] eat;
	}
	void See() {
		//system("cls");
		cout << "Имя: " << name << endl;
		cout << "Пол: " << gender << endl;
		cout << "Темпераметр: " << character << endl;
		cout << "Хобби: " << hobby << endl;
		cout << "Работа: " <<work<< endl;
		cout << "Место проживания: " <<location << endl;
		cout << "Еда: " << eat << endl;
		cout << "Зрение: " << vision << endl << endl;
	}
	string getGrupp() {
		return "Пожилые";
	}
};

Smeshariki** CH(Smeshariki** p, int& n) {
	char name[80],gender[80], character[80], hobby[80];
	cout << "***Дети***" << endl;
	cout << "Введите имя: ";
	string name1 = writeWords();
	strcpy_s(name, name1.c_str());

	cout << "Введите пол: ";
	string gender1 = writeWords();
	strcpy_s(gender, gender1.c_str());

	cout << "Введите темпераметр: ";
	string character1 = writeWords();
	strcpy_s(character, character1.c_str());

	cout << "Введите хобби: ";
	string hobby1 = writeWords();
	strcpy_s(hobby, hobby1.c_str());

	Smeshariki** ptr = new Smeshariki * [n + 1];
	copy(p, p + n, ptr);
	ptr[n] = new Сhildren(name,gender, character, hobby);
	n++;
	delete[]p;
	p = ptr;
	return p;
}
Smeshariki** AD(Smeshariki** p, int& n) {
	char name[80],gender[80], work[80], location[80];
	cout << "***Взрослые***" << endl;
	cout << "Введите имя: ";
	string name1 = writeWords();
	strcpy_s(name, name1.c_str());

	cout << "Введите пол: ";
	string gender1 = writeWords();
	strcpy_s(gender, gender1.c_str());

	cout << "Введите профессию: ";
	string work1 = writeWords();
	strcpy_s(work, work1.c_str());
	
	cout << "Введите место проживания: ";
	string location1 = writeWords();
	strcpy_s(location, location1.c_str());

	Smeshariki** ptr = new Smeshariki * [n + 1];
	copy(p, p + n, ptr);
	ptr[n] = new Adults(name,gender,work,location);
	n++;
	delete[]p;
	p = ptr;
	return p;
}
Smeshariki** EL(Smeshariki** p, int& n) {
	char name[80],gender[80], character[80],hobby[80], work[80], location[80],eat[80];
	double vision;
	cout << "***Пожилые***" << endl;
	cout << "Введите имя: ";
	string name1 = writeWords();
	strcpy_s(name, name1.c_str());

	cout << "Введите пол: ";
	string gender1 = writeWords();
	strcpy_s(gender, gender1.c_str());

	cout << "Введите темпераметр: ";
	string character1 = writeWords();
	strcpy_s(character, character1.c_str());

	cout << "Введите хобби: ";
	string hobby1 = writeWords();
	strcpy_s(hobby, hobby1.c_str());

	cout << "Введите профессию: ";
	string work1 = writeWords();
	strcpy_s(work, work1.c_str());

	cout << "Введите место проживания: ";
	string location1 = writeWords();
	strcpy_s(location, location1.c_str());

	cout << "Введите еду: ";
	string eat1 = writeWords();
	strcpy_s(eat, eat1.c_str());

	cout << "Введите зрение: ";
	vision = inputDouble();

	Smeshariki** ptr = new Smeshariki * [n + 1];
	copy(p, p + n, ptr);
	ptr[n] = new Elderly(name,gender, character, hobby,work, location, eat,vision);
	n++;
	delete[]p;
	p = ptr;
	return p;
}

void Choice(Smeshariki** arr, int n) {
	int check;
	while (true) {
		check = 0;
		switch (MenuChoice()) {
		case 0:
			cout << "----Дети----" << endl;
			for (int i = 0; i < n; i++) {
				if (arr[i]->getGrupp() == "Дети") {
					arr[i]->See();
					check++;
				}
			}
			if (check == 0) {
				cout << "Записей Нет!" << endl;
			}
			break;
		case 1:
			cout << "----Взрослые----" << endl;
			for (int i = 0; i < n; i++) {
				if (arr[i]->getGrupp() == "Взрослые") {
					arr[i]->See();
					check++;
				}
			}
			if (check == 0) {
				cout << "Записей Нет!" << endl;
			}
			break;
		case 2:
			cout << "----Пожилые----" << endl;
			for (int i = 0; i < n; i++) {
				if (arr[i]->getGrupp() == "Пожилые") {
					arr[i]->See();
					check++;
				}
			}
			if (check == 0) {
				cout << "Записей Нет!" << endl;
			}
			break;
		case 3:
			return;
		}
		system("pause");
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n = 0;
	Smeshariki** arr = new Smeshariki * [n];
	while (true) {
		switch (menu()) {
		case 0:
			arr = CH(arr, n);
			break;
		case 1:
			arr = AD(arr, n);
			break;
		case 2:
			arr = EL(arr, n);
			break;
		case 3:
			for (int i = 0; i < n; i++) {
				arr[i]->See();
			}
			break;
		case 4:		
			Choice(arr,n);
			break;
		case 5:
			delete[]arr;
			return 0;
		}
		system("pause");
		system("cls");
	}
	return 0;
}

string writeWords() {
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
				if ((simvol >= 'а' && simvol <= 'я') || (simvol >= 'А' && simvol <= 'Я') || simvol == ' ') {
					word = word + simvol;
					cout << simvol;
				}
			}
	}
	cout << endl;
	return word;
}

double inputDouble() {
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
				if ((i >= '0' && i <= '9') || i == ',' || i == '-') {
					number = number + par;
					cout << par;
				}
			}
	}
	cout << endl;
	return stof(number);
}

int menu()
{
	int choiceButton = 0, button = 0;
	system("cls");
	while (true)
	{
		cout << "Выберите пункт меню: " << endl;
		choiceButton = (choiceButton + 6) % 6;

		if (choiceButton == 0) cout << "-> Ввод детей" << endl;
		else cout << " Ввод детей" << endl;

		if (choiceButton == 1) cout << "-> Ввод взрослых" << endl;
		else cout << " Ввод взрослых" << endl;

		if (choiceButton == 2) cout << "-> Ввод пожилые" << endl;
		else cout << " Ввод пожилые" << endl;

		if (choiceButton == 3) cout << "-> Просмотр записей" << endl;
		else cout << " Просмотр записей" << endl;

		if (choiceButton == 4) cout << "-> Просмотр определенных записей" << endl;
		else cout << " Просмотр определенных записей" << endl;

		if (choiceButton == 5) cout << "-> Выход" << endl;
		else cout << " Выход" << endl;

		button = _getch();
		if (button == 224)
		{
			button = _getch();
			if (button == 72) choiceButton--;
			if (button == 80) choiceButton++;
		}
		if (button == 13) { system("cls"); return choiceButton; }
		system("cls");
	}
}

int MenuChoice()
{
	int choiceButton = 0, button = 0;
	system("cls");
	while (true)
	{
		cout << "Выберите какую информацию просмотреть: " << endl;
		choiceButton = (choiceButton + 4) % 4;

		if (choiceButton == 0) cout << "-> Дети" << endl;
		else cout << " Дети" << endl;

		if (choiceButton == 1) cout << "-> Взрослые" << endl;
		else cout << " Взрослые" << endl;

		if (choiceButton == 2) cout << "-> Пожилые" << endl;
		else cout << " Пожилые" << endl;

		if (choiceButton == 3) cout << "-> Выход" << endl;
		else cout << " Выход" << endl;

		button = _getch();
		if (button == 224)
		{
			button = _getch();
			if (button == 72) choiceButton--;
			if (button == 80) choiceButton++;
		}
		if (button == 13) { system("cls"); return choiceButton; }
		system("cls");
	}
}