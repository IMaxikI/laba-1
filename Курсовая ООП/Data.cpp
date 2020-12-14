#include "Data.h"
#include "Menu.h"
#include "Сhecks.h"

string Book::getNameBook()
{
	return nameBook;
}

string Book::getGenre()
{
	return genre;
}

int Book::getPages()
{
	return pages;
}

void Book::changeNameBook(string nameB)
{
	nameBook = nameB;
}

void Book::changeGenre(string genreB)
{
	genre = genreB;
}

void Book::changePages(int pagesB)
{
	pages = pagesB;
}


string Publisher::getAuthor()
{
	return author;
}

string Publisher::getPublisher()
{
	return publisher;
}

int Publisher::getYear()
{
	return year;
}

void Publisher::changeAuthor(string authorB)
{
	author = authorB;
}

void Publisher::changePublisher(string publicherB)
{
	publisher = publicherB;
}

void Publisher::changeYear(int yearB)
{
	year = yearB;
}


string Characteristics::getCondition()
{
	return condition;
}

string Characteristics::getCover()
{
	return cover;
}

void Characteristics::changeCondition(string cond)
{
	condition = cond;
}

void Characteristics::changeCover(string cov)
{
	cover = cov;
}

istream& operator>>(istream& input, Characteristics& Obj)
{
	cout << "Введите название книги: ";
	Obj.nameBook = inputString();
	cout << "Введите жанр: ";
	Obj.genre = inputString();
	cout << "Введите количество страниц: ";
	Obj.pages = inputPages();
	cout << "Введите автора книги: ";
	Obj.author = inputString();
	cout << "Введите издательство: ";
	Obj.publisher = inputString();
	cout << "Введите год издания: ";
	Obj.year = inputYear();
	cout << "Введите состояние книги: ";
	Obj.condition = inputString();
	cout << "Введите тип обложки: ";
	Obj.cover = inputString();
	return input;
}

ostream& operator<<(ostream& out, Characteristics& Obj)
{
	out << "Название книги: " << Obj.nameBook << endl;
	out << "Жанр:" << Obj.genre << endl;
	out << "Количество страниц: " << Obj.pages << endl;
	out << "Автор: " << Obj.author << endl;
	out << "Издательство: " << Obj.publisher << endl;
	out << "Год издания: " << Obj.year << endl;
	out << "Состояние: " << Obj.condition << endl;
	out << "Тип обложки: " << Obj.cover << endl;
	return out;
}

ifstream& operator>>(ifstream& ifs, Characteristics& Obj)
{
	getline(ifs, Obj.nameBook);
	getline(ifs, Obj.genre);
	string pag;
	getline(ifs, pag);
	Obj.pages = stoi(pag);
	getline(ifs, Obj.author);
	getline(ifs, Obj.publisher);
	string year1;
	getline(ifs, year1);
	Obj.year = stoi(year1);
	getline(ifs, Obj.condition);
	getline(ifs, Obj.cover);
	return ifs;
}

ofstream& operator<<(ofstream& fout, Characteristics& Obj)
{
	fout << Obj.nameBook << endl;
	fout << Obj.genre << endl;
	fout << Obj.pages << endl;
	fout << Obj.author << endl;
	fout << Obj.publisher << endl;
	fout << Obj.year << endl;
	fout << Obj.condition << endl;
	fout << Obj.cover << endl;
	return fout;
}

void addBook(Characteristics*& Books, int& NumberBook)
{
	Characteristics book;
	cin >> book;
	NumberBook++;
	Characteristics* tmp = new Characteristics[NumberBook];
	copy(Books, Books + NumberBook - 1, tmp);
	Books = tmp;
	tmp = NULL;
	delete[]tmp;
	Books[NumberBook - 1] = book;
	writeFileData(Books, NumberBook);
}


bool dataView(Characteristics* Books, int NumberBook)
{
	bool flag = false;
	if (NumberBook > 0)
	{
		for (int i = 0; i < NumberBook; i++)
		{
			flag = true;
			cout << "\tЗапись №" << i + 1 << endl;
			cout << Books[i] << endl;
		}
	}
	else return flag;
	return flag;
}

void sort(Characteristics*& Books, int& NumberBook) {
	Interface <int>Menu;
	if (NumberBook != 0) {
		while (true) {
			switch (Menu.menuDataSort())
			{
			case 0:
				sortName(Books, NumberBook);
				break;
			case 1:
				sortPages(Books, NumberBook);
				break;
			case 2:
				return;
			}
			system("pause");
			system("cls");
		}
	}
	else cout << "Записей нет!" << endl;
}
void sortName(Characteristics*& Books, int& NumberBook)
{
	Characteristics temp;
	for (int i = 0; i < NumberBook - 1; i++)
	{
		for (int j = i + 1; j < NumberBook; j++)
		{
			if (Books[i].getNameBook()[0] > Books[j].getNameBook()[0])
			{
				temp = Books[i];
				Books[i] = Books[j];
				Books[j] = temp;
			}
		}
	}
	cout << "Данные отсортированны по названию книги!" << endl;
	//DataView(arr_of_book, number_of_book);
	writeFileData(Books, NumberBook);
}
void sortPages(Characteristics*& Books, int& NumberBook)
{
	Characteristics temp;
	for (int i = 0; i < NumberBook - 1; i++)
	{
		for (int j = i + 1; j < NumberBook; j++)
		{
			if (Books[i].getPages() > Books[j].getPages())
			{
				temp = Books[i];
				Books[i] = Books[j];
				Books[j] = temp;
			}
		}
	}
	cout << "Данные отсортированны по количеству страниц!" << endl;
	//DataView(arr_of_book, number_of_book);
	writeFileData(Books, NumberBook);
}

void search(Characteristics* Books, int NumberBook) {
	Interface <int>Menu;
	if (NumberBook != 0) {
		while (true)
		{
			switch (Menu.menuDataSearch()) {
			case 0:
				searchName(Books, NumberBook);
				break;
			case 1:
				searchPages(Books, NumberBook);
				break;
			case 2:
				return;
			}
			system("pause");
			system("cls");
		}
	}
	else cout << "Записей нет!" << endl;
}

void searchName(Characteristics* Books, int NumberBook)
{
	string name;
	bool flag = false;
	cout << "\nВведите название книги: ";
	name = inputString();
	cout << endl;
	for (int i = 0; i < NumberBook; i++)
	{
		int kolvo = 0;
		if (name.length() <= Books[i].getNameBook().length())
		{
			for (int j = 0; j < name.length(); j++) {
				if (name[j] != Books[i].getNameBook()[j]) kolvo++;
			}
		}
		if (kolvo==0)
		{
			cout << "Запись №" << i + 1 << endl;
			cout << Books[i];
			flag = true;
		}
	}
	if (flag)
		cout << "Книг с названием " << name << " нет!\n";
}
void searchPages(Characteristics* Books, int NumberBook)
{
	int pages;
	int number = 0;
	cout << "\nВведите количество страниц: ";
	pages = inputPages();
	cout << endl;
	for (int i = 0; i < NumberBook; i++)
	{
		if (Books[i].getPages() == pages)
		{
			number++;
			cout << "Запись №" << i + 1 << endl;
			cout << Books[i];
		}
	}
	if (number == 0)
		cout << "Книг с количеством страниц " << pages << " нет!\n";
}

void updateData(Characteristics*& Books, int NumberBook) {
	if (!dataView(Books, NumberBook)) {
		cout << "Записей нет!" << endl;
		return;
	}
	int number;
	cout << "Введите номер записи, информацию которой хотите изменить: ";
	number = inputNumber(NumberBook);
	system("cls");
	string name, genre, author, publisher, condition, cover;
	int pages, year;
	switch (menuUpdateData(Books, number))
	{
	case 0:
		cout << "Введите новое название книги: ";
		name = inputString();
		Books[number - 1].changeNameBook(name);
		system("cls");
		cout << "Название изменено!" << endl;
		break;
	case 1:
		cout << "Введите новый жанр: ";
		genre = inputString();
		Books[number - 1].changeGenre(genre);
		system("cls");
		cout << "Жанр изменен!" << endl;
		break;
	case 2:
		cout << "Введите новое количество страниц: ";
		pages = inputPages();
		Books[number - 1].changePages(pages);
		system("cls");
		cout << "Количество страниц изменено!" << endl;
		break;
	case 3:
		cout << "Введите нового автора: ";
		author = inputString();
		Books[number - 1].changeAuthor(author);
		system("cls");
		cout << "Автор изменен!" << endl;
		break;
	case 4:
		cout << "Введите нового издателя: ";
		publisher = inputString();
		Books[number - 1].changePublisher(publisher);
		system("cls");
		cout << "Издатель изменен!" << endl;
		break;
	case 5:
		cout << "Введите новое состояние книги: ";
		condition = inputString();
		Books[number - 1].changeCondition(condition);
		system("cls");
		cout << "Состояние изменено!" << endl;
		break;
	case 6:
		cout << "Введите новой тип обложки: ";
		cover = inputString();
		Books[number - 1].changeCover(cover);
		system("cls");
		cout << "Тип обложки изменен!" << endl;
		break;
	case 7:
		cout << "Введите новый год издания: ";
		year = inputYear();
		Books[number - 1].changeYear(year);
		system("cls");
		cout << "Год издания изменен!" << endl;
		break;
	case 8: return;
	}
	writeFileData(Books, NumberBook);
}
int menuUpdateData(Characteristics* Books, int& number)
{
	int ViborPunkta = 0, strelka = 0;
	while (true) {
		ViborPunkta = (ViborPunkta + 9) % 9;
		cout << "ВЫБЕРИТЕ ЧТО ИЗМЕНИТЬ" << endl;
		if (ViborPunkta == 0)
			cout << "->Название книги: " << Books[number - 1].getNameBook() << endl;
		else
			cout << " Название книги: " << Books[number - 1].getNameBook() << endl;

		if (ViborPunkta == 1)
			cout << "->Жанр: " << Books[number - 1].getGenre() << endl;
		else
			cout << " Жанр: " << Books[number-1].getGenre() << endl;

		if (ViborPunkta == 2)
			cout << "->Количество страниц: " << Books[number - 1].getPages() << endl;
		else
			cout << " Количество страниц: "<< Books[number-1].getPages() << endl;

		if (ViborPunkta == 3)
			cout << "->Автора: " << Books[number - 1].getAuthor() << endl;
		else
			cout << " Автора: " << Books[number - 1].getAuthor() << endl;

		if (ViborPunkta == 4)
			cout << "->Издательство: " << Books[number-1].getPublisher() << endl;
		else
			cout << " Издательство: " << Books[number - 1].getPublisher() << endl;

		if (ViborPunkta == 5)
			cout << "->Состояние книги: " << Books[number-1].getCondition() << endl;
		else
			cout << " Состояние книги: " << Books[number - 1].getCondition() << endl;

		if (ViborPunkta == 6)
			cout << "->Тип обложки: " << Books[number-1].getCover() << endl;
		else
			cout << " Тип обложки: " << Books[number - 1].getCover() << endl;

		if (ViborPunkta == 7)
			cout << "->Год издания: " << Books[number - 1].getYear() << endl;
		else
			cout << " Год издания: " << Books[number-1].getYear() << endl;

		if (ViborPunkta == 8)
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

void deleteData(Characteristics*& Books, int& NumberBook)
{
	Interface <int>Menu;
	if (!dataView(Books, NumberBook)) {
		cout << "Записей нет!" << endl;
		return;
	}
	int number, potverdit;
	cout << "Введите номер удаляемой записи: ";
	number = inputNumber(NumberBook);
	system("cls");
	potverdit = Menu.menuDelData();
	if (potverdit == 0) {
		number--; 
		if (NumberBook > 0)
		{
			for (int i = number; i < NumberBook - 1; i++)
			{

				Books[i] = Books[i + 1];
			}
			NumberBook--;
			cout << "Запись удалена!" << endl;
			writeFileData(Books, NumberBook);
		}
		else cout << "Записей нет!" << endl;
	}
	else return;
}

void writeFileData(Characteristics* Books, int NumberBook) {
	ofstream fout(FileData, ios::out);
	for (int i = 0; i < NumberBook; i++)
	{
		fout << Books[i];
	}
	fout.close();
}
void readFileData(Characteristics* Books, int& NumberBook) {
	ifstream fin;
	fin.open(FileData);
	int i = 0;
	while (fin.peek() != EOF)
	{
		fin >> Books[i];
		i++;
	}
	NumberBook = i;
	fin.close();
}
int getCountStructuresInFileData(string FILE)
{
	int number_of_structures = 0;
	ifstream file(FILE, ios::in);
	if (file.is_open())
	{
		string tmp;
		while (getline(file, tmp))
			number_of_structures++;
	}
	file.close();
	return number_of_structures / 8;
}

void WorkData() {
	system("cls");
	Interface <int>Menu;
	int NumberBook = getCountStructuresInFileData(FileData);
	Characteristics* Books = new Characteristics[NumberBook];
	readFileData(Books, NumberBook);
	while (true) {
		switch (Menu.menuDataMode()) {
		case 0:
			if(!dataView(Books, NumberBook)) {
				cout << "Записей нет!" << endl;
			}
			break;
		case 1:
			addBook(Books, NumberBook);
			break;
		case 2:
			updateData(Books, NumberBook);
			break;
		case 3:
			search(Books, NumberBook);
			break;
		case 4:
			sort(Books, NumberBook);
			break;
		case 5:
			deleteData(Books,NumberBook);
			break;
		case 6:
			return;
		}
		system("pause");
		system("cls");
	}
	delete[]Books;
}