#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>

using namespace std;
int menu();


template <class T>
class Documentation {
	T str;
public:
	Documentation() {};
	Documentation(T st) {
		str = st;
	}
	void Show() {
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
		cout << "Объект удален!" << endl;
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
		cout << "Указатель удален!" << endl;
	}
	SmartDoc<T1>& operator=(const SmartDoc<T1>& p)
	{
		if (StatPtr) {
			StatPtr->Count--;
			if (StatPtr->Count <= 0) {
				delete StatPtr->RealPtr;
				delete StatPtr;
			}
		}
		StatPtr = p.StatPtr;
		if (StatPtr) StatPtr->Count++;
		return *this;
	}
};



void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SmartDoc<Documentation<string>> pt1(new Documentation<string>);
	SmartDoc<Documentation<string>> pt2(new Documentation<string>);
	SmartDoc<Documentation<string>> pt3 = pt1;
	SmartDoc<Documentation<string>> pt4 = pt2;
	string str;
	while (true) {
		switch (menu())
		{
		case 0:
			cout << "Введите текст:";
			cin >> str;
			pt3->Change(str);
			break;
		case 1:
			cout << "Введите текст:";
			cin >> str;
			pt4->Change(str);
			break;
		case 2:
			cout << "\t1 Документация" << endl;
			pt3->Show();
			cout << "\t2 Документация" << endl;
			pt4->Show();
			system("pause");
			break;
		case 3:
			cout << "Введите текст, который хотите добавить:";
			cin >> str;
			pt3->AddDoc(str);
			break;
		case 4:
			cout << "Введите текст, который хотите добавить:";
			cin >> str;
			pt4->AddDoc(str);
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

		if (choiceButton == 0) cout << " -> Изменение первой документации" << endl;
		else cout << " Изменение первой документации" << endl;

		if (choiceButton == 1) cout << " -> Изменение второй документации" << endl;
		else cout << " Изменение второй документации" << endl;

		if (choiceButton == 2) cout << " -> Просмотр всей документации" << endl;
		else cout << " Просмотр всей документации" << endl;

		if (choiceButton == 3) cout << " -> Добавить текст к 1 документации" << endl;
		else cout << " Добавить текст к 1 документации" << endl;

		if (choiceButton == 4) cout << " -> Добавить текст к 2 документации" << endl;
		else cout << " Добавить текст к 2 документации" << endl;

		if (choiceButton == 5) cout << " -> Сформировать документацию и выйти" << endl;
		else cout << " Сформировать документацию и выйти" << endl;

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
