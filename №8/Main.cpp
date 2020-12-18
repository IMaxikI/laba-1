#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>

using namespace std;
int menu();
string writeWords();

template <class T>
class Documentation {
	T str;
public:
	Documentation() {};
	Documentation(T st) {
		str = st;
	}
	void Show() {
		cout << "������������" << endl;
		cout << str << endl;
	}
	void Change(T st) {
		str = st;
	}
	void AddDoc(T st) {
		str += st;
	}
	~Documentation()
	{
		cout << "������ ������!" << endl;
	}
};




template <class T1>
struct Status {
	T1* RealPtr;
	int Count;
};

template<class T1>
class SmartDoc {
	Status<T1>* StatPtr;
public:
	T1* operator->()const {
		if (StatPtr) return StatPtr->RealPtr;
		else return NULL;
	}
	SmartDoc(T1* ptr = 0) {
		if (!ptr) StatPtr = NULL;
		else {
			StatPtr = new Status<T1>;
			StatPtr->RealPtr = ptr;
			StatPtr->Count = 1;
		}
	}
	SmartDoc(const SmartDoc<T1>& p) :StatPtr(p.StatPtr) {
		if (StatPtr) StatPtr->Count++;
	}
	~SmartDoc() {
		if (StatPtr) {
			StatPtr->Count--;
			if (StatPtr->Count <= 0) {
				delete StatPtr->RealPtr;
				delete StatPtr;
			}
		}
		cout << "��������� ������" << endl;
	}
};



void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SmartDoc<Documentation<string>> pt1(new Documentation<string>);
	SmartDoc<Documentation<string>> pt2(new Documentation<string>);
	string str;
	while (true) {
		switch (menu())
		{
		case 0:
			cout << "������� �����:";
			str = writeWords();
			pt1->Change(str);
			break;
		case 1:
			cout << "������� �����:";
			str = writeWords();
			pt2->Change(str);
			break;
		case 2:
			cout << "\t1 ������������" << endl;
			pt1->Show();
			cout << "\t2 ������������" << endl;
			pt2->Show();
			system("pause");
			break;
		case 3:
			cout << "������� �����, ������� ������ ��������:";
			str = writeWords();
			pt1->AddDoc(str);
			break;
		case 4:
			cout << "������� �����, ������� ������ ��������:";
			str = writeWords();
			pt2->AddDoc(str);
			break;
		case 5:
			return;
		}
	}
}


int menu()
{
	int choiceButton = 0, button = 0;
	system("cls");
	while (true)
	{
		choiceButton = (choiceButton + 6) % 6;

		if (choiceButton == 0) cout << " -> ��������� ������ ������������" << endl;
		else cout << " ��������� ������ ������������" << endl;

		if (choiceButton == 1) cout << " -> ��������� ������ ������������" << endl;
		else cout << " ��������� ������ ������������" << endl;

		if (choiceButton == 2) cout << " -> �������� ���� ������������" << endl;
		else cout << " �������� ���� ������������" << endl;

		if (choiceButton == 3) cout << " -> �������� ����� � 1 ������������" << endl;
		else cout << " �������� ����� � 1 ������������" << endl;

		if (choiceButton == 4) cout << " -> �������� ����� � 2 ������������" << endl;
		else cout << " �������� ����� � 2 ������������" << endl;

		if (choiceButton == 5) cout << " -> ������������ ������������ � �����" << endl;
		else cout << " ������������ ������������ � �����" << endl;

		button = _getch();
		if (button == 224)
		{
			button = _getch();
			if (button == 72) choiceButton--;
			if (button == 80) choiceButton++;
		}
		if (button == 13) {
			system("cls");
			return choiceButton;
		}
		system("cls");
	}
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