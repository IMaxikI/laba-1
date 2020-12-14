#pragma once
#include "Menu.h"
using namespace std;
const string FileData = "Data.txt";

class FunctionBook {
public:
	virtual string getNameBook() = 0;
	virtual string getGenre() = 0;
	virtual int getPages() = 0;
	virtual string getAuthor() = 0;
	virtual string getPublisher() = 0;
	virtual int getYear() = 0;
	virtual string getCondition() = 0;
	virtual string getCover() = 0;
	virtual void changeNameBook(string) = 0;
	virtual void changeGenre(string) = 0;
	virtual void changePages(int) = 0;
	virtual void changeAuthor(string) = 0;
	virtual void changePublisher(string) = 0;
	virtual void changeYear(int) = 0;
	virtual void changeCondition(string) = 0;
	virtual void changeCover(string) = 0;
};

class Book :public FunctionBook {
protected:
	string nameBook;
	string genre;
	int pages;
public:
	Book() {
		pages = 0;
	}
	string getNameBook();
	string getGenre();
	int getPages();
	void changeNameBook(string);
	void changeGenre(string);
	void changePages(int);
	~Book() {}
};

class Publisher :public Book {
protected:
	string author;
	string publisher;
	int year;
public:
	Publisher() {
		year = 0;
	}
	string getAuthor();
	string getPublisher();
	int getYear();
	void changeAuthor(string);
	void changePublisher(string);
	void changeYear(int);
	~Publisher() {}
};

class Characteristics : public Publisher {
private:
	string condition;
	string cover;
public:
	Characteristics() {}
	string getCondition();
	string getCover();
	void changeCondition(string);
	void changeCover(string);
	~Characteristics() {}
	friend istream& operator>>(istream&, Characteristics&);
	friend ostream& operator<<(ostream&, Characteristics&);
	friend ifstream& operator>>(ifstream&, Characteristics&);
	friend ofstream& operator<<(ofstream&, Characteristics&);
};


void WorkData();


void addBook(Characteristics*&, int&);
bool dataView(Characteristics*, int);

void sort(Characteristics*& , int& );
void sortName(Characteristics*&, int&);
void sortPages(Characteristics*&, int&);

void search(Characteristics*, int);
void searchName(Characteristics*, int);
void searchPages(Characteristics* , int );



void updateData(Characteristics*&, int);
int menuUpdateData(Characteristics*, int&);

void writeFileData(Characteristics*, int);
void readFileData(Characteristics*, int&);
int getCountStructuresInFileData(string);

void deleteData(Characteristics*&, int&);

