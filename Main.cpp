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
	string name;
	string gender;
public:
	Smeshariki() {};
	Smeshariki(string name1, string gender1) {
		name = name1;
		gender = gender1;

	}
	~Smeshariki() {};
	void See() {
		cout << "���: " << name << endl;
		cout << "���: " << gender << endl;
	}
};


class �hildren :virtual public Smeshariki {
protected:
	string character;
	string hobby;
public:
	�hildren() {};
	�hildren(string name1, string gender1, string character1, string hobby1) :Smeshariki(name1, gender1) {
		character = character1;
		hobby = hobby1;
	}
	~�hildren() {};
	void See() {
		cout << "�����������: " << character << endl;
		cout << "�����: " << hobby << endl;
	}
};

class Adults :virtual public Smeshariki {
protected:
    string work;
	string location;
public:
	Adults() {};
	Adults(string name1, string gender1, string work1, string location1) :Smeshariki(name1, gender1) {
		work = work1;
		location=location1;

	}
	~Adults() {};
	void See() {
		cout << "������:" << work << endl;
		cout << "����� ����������:" << location << endl;
	}
};

class Elderly :public �hildren,public Adults {
	string eat;
	double vision;
public:
	Elderly() {};
	Elderly(string name1, string gender1, string character1, string hobby1, string work1, string location1, string eat1, double vision1):�hildren(name1,gender1,character1, hobby1), Adults(name1,gender1,work1,location1), Smeshariki(name1,gender1){
		eat = eat1;
		vision = vision1;
	}
	~Elderly() {};
	void See() {
		Smeshariki::See();
		�hildren::See();
		Adults::See();
		cout << "���: " << eat << endl;
		cout << "������: " << vision << endl << endl;
	}

};

Elderly* EL(Elderly* p, int& n) {
	double vision;
	cout << "***�������***" << endl;
	cout << "������� ���: ";
	string name = writeWords();

	cout << "������� ���: ";
	string gender = writeWords();

	cout << "������� �����������: ";
	string character = writeWords();

	cout << "������� �����: ";
	string hobby = writeWords();

	cout << "������� ���������: ";
	string work = writeWords();

	cout << "������� ����� ����������: ";
	string location = writeWords();


	cout << "������� ���: ";
	string eat = writeWords();

	cout << "������� ������: ";
	vision = inputDouble();

	Elderly* ptr = new Elderly [n + 1];
	copy(p, p + n, ptr);
	Elderly obj(name, gender, character, hobby, work, location, eat, vision);
	ptr[n] = obj;
	n++;
	delete[]p;
	p = ptr;
	return p;
}

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n = 0;
	Elderly* arr = new Elderly[n];
	while (true) {
		switch (menu()) {
		case 0:
			arr = EL(arr, n);
			break;
		case 1:
			for (int i = 0; i < n; i++) {
	            arr[i].See();
             }
			break;
		case 2:


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
				if ((simvol >= '�' && simvol <= '�') || (simvol >= '�' && simvol <= '�') || simvol == ' ') {
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
		cout << "�������� ����� ����: " << endl;
		choiceButton = (choiceButton + 3) % 3;

		if (choiceButton == 0) cout << "-> ���� �������" << endl;
		else cout << " ���� �������" << endl;

		if (choiceButton == 1) cout << "-> �������� �������" << endl;
		else cout << " �������� �������" << endl;

		if (choiceButton == 2) cout << "-> �����" << endl;
		else cout << " �����" << endl;

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
