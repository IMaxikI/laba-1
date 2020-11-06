#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>

using namespace std;

double inputDouble();
string writeWords();
int menu();

class Smeshariki {
protected:
	char* color;
	char* gender;
public:
	Smeshariki(char* str1, char* str2) {
		gender = new char[strlen(str1) + 1];
		strcpy_s(gender, strlen(str1) + 1, str1);
		color = new char[strlen(str2) + 1];
		strcpy_s(color, strlen(str2) + 1, str2);
	}
	virtual ~Smeshariki() = 0;
	virtual void See() = 0;
	
};

Smeshariki::~Smeshariki() {
	delete[]color;
	delete[]gender;
}

class Krosh :public Smeshariki {
	char* eat;
	char* hobby;
public:
	Krosh(char* str1, char* str2, char* str3, char* str4) :Smeshariki(str1,str2){
		eat = new char[strlen(str3) + 1];
		strcpy_s(eat, strlen(str3) + 1, str3);
		hobby = new char[strlen(str4) + 1];
		strcpy_s(hobby, strlen(str4) + 1, str4);
	}
	~Krosh() {
		delete[]eat;
		delete[]hobby;
	}
	void See() {
		system("cls");
		cout << "\t-Крош-" << endl;
		cout << "Пол: " << gender << endl;
		cout << "Цвет: " << color << endl;
		cout << "Хобби: " << hobby << endl;
		cout << "Любимая еда: " << eat << endl;
	}
};
class Ezhik :public Smeshariki {
	char* character;
	double vision;
public:
	Ezhik(char* str1, char* str2, char* str3, double zr):Smeshariki(str1, str2) {
		character = new char[strlen(str3) + 1];
		strcpy_s(character, strlen(str3) + 1, str3);
		vision = zr;
	}
	~Ezhik() {
		delete[] character;
	}
	void See() {
		system("cls");
		cout << "\t-Ежик-" << endl;
		cout << "Пол: " << gender << endl;
		cout << "Цвет: " << color << endl;
		cout << "Темпераметр: " << character << endl;
		cout << "Зрение: " << vision << endl;
	}
};
class Sovunya :public Smeshariki {
	char* work;
	char* location;
public:
	Sovunya(char* str1, char* str2, char* str3, char* str4):Smeshariki(str1, str2) {
		work = new char[strlen(str3) + 1];
		strcpy_s(work, strlen(str3) + 1, str3);
		location = new char[strlen(str4) + 1];
		strcpy_s(location, strlen(str4) + 1, str4);
	}
	~Sovunya() {
		delete[] work;
		delete[] location;
	}
	void See() {
		system("cls");
		cout << "\t-Совунья-" << endl;
		cout << "Пол: " << gender << endl;
		cout << "Цвет: " << color << endl;
		cout << "Работа: " << work << endl;
		cout << "Место проживания: " << location << endl;
	}
};

Smeshariki** KR(Smeshariki** p, int& n) {
	char gender[80], color[80], eat[80], hobby[80];
	cout << "Введите пол Кроша: ";
	string gender1 = writeWords();
	strcpy_s(gender, gender1.c_str());
	cout << "Введите цвет Кроша: ";
	string color1 = writeWords();
	strcpy_s(color, color1.c_str());
	cout << "Введите любимую еду Кроша: ";
	string eat1 = writeWords();
	strcpy_s(eat, eat1.c_str());
	cout << "Введите хобби Кроша: ";
	string hobby1 = writeWords();
	strcpy_s(hobby, hobby1.c_str());

	Smeshariki** ptr = new Smeshariki * [n+1];
	copy(p, p + n, ptr);
	ptr[n] = new Krosh(gender, color, eat, hobby);
	n++;
	delete[]p;
	p = ptr;
	return p;
}
Smeshariki** EZ(Smeshariki** p, int& n) {
	char gender[80], color[80], character[80];
	double vision;
	cout << "Введите пол Ёжика: ";
	string gender1 = writeWords();
	strcpy_s(gender, gender1.c_str());
	cout << "Введите цвет Ёжика: ";
	string color1 = writeWords();
	strcpy_s(color, color1.c_str());
	cout << "Введите темпераметр Ёжика: ";
	string character1 = writeWords();
	strcpy_s(character, character1.c_str());
	cout << "Введите зрение Ёжика: ";
	vision = inputDouble();

	Smeshariki** ptr = new Smeshariki * [n + 1];
	copy(p, p + n, ptr);
	ptr[n] = new Ezhik(gender, color, character, vision);
	n++;
	delete[]p;
	p = ptr;
	return p;
}
Smeshariki** SV(Smeshariki** p, int& n) {
	char gender[80], color[80], work[80], location[80];
	cout << "Введите пол Совуньи: ";
	string gender1 = writeWords();
	strcpy_s(gender, gender1.c_str());
	cout << "Введите цвет Совуньи: ";
	string color1 = writeWords();
	strcpy_s(color, color1.c_str());
	cout << "Введите профессию Совуньи: ";
	string work1 = writeWords();
	strcpy_s(work, work1.c_str());
	cout << "Введите место проживания Совуньи: ";
	string location1 = writeWords();
	strcpy_s(location, location1.c_str());

	Smeshariki** ptr = new Smeshariki * [n + 1];
	copy(p, p + n, ptr);
	ptr[n] = new Sovunya(gender, color, work, location);
	n++;
	delete[]p;
	p = ptr;
	return p;
}

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n=0;
	Smeshariki** arr= new Smeshariki* [n];
	while (true) {
		switch (menu()) {
		case 0: 
			arr=KR(arr, n);
			break;
		case 1:
			arr=EZ(arr,n);
			break;
		case 2:
			arr=SV(arr,n);
			break;
		case 3:
			for (int i = 0; i < n; i++) {
				arr[i]->See();
				system("pause");
			}
			break;
		case 4:
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
				if ((simvol >= 'а' && simvol <= 'я') || (simvol >= 'А' && simvol <= 'Я')) {
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
		cout << "Выберите смешарика: " << endl;
		choiceButton = (choiceButton + 5) % 5;

		if (choiceButton == 0) cout << "-> Крош" << endl;
		else cout << " Крош" << endl;

		if (choiceButton == 1) cout << "-> Ёжик" << endl;
		else cout << " Ёжик" << endl;

		if (choiceButton == 2) cout << "-> Совунья" << endl;
		else cout << " Совунья" << endl;

		if (choiceButton == 3) cout << "-> Просмотр записей" << endl;
		else cout << " Просмотр записей" << endl;

		if (choiceButton == 4) cout << "-> Выход" << endl;
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