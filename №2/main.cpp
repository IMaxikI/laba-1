#include <iostream>
using namespace std;

class employee{
private:
	int number;
	float oklad;
	string status;
public:
	enum etype {
		/*laboratory_assistant,
		secretary,
		manager,
		programmer*/
		Лаборант,
		Секретарь,
		Менеджер,
		Программист
	};
	void getemploy();
	void putemploy();
	class date {
	public:
		int day, month, year;
	}dt;
	
};

int main() {
	setlocale(LC_ALL, "rus");
	int colvo;
	cout << "Введите количество добавляемых сотрудников: ";
	cin >> colvo;
	employee* workers=new employee[colvo];
	for (int i = 0; i < colvo; i++) {
		
		workers[i].getemploy();
	
	}
	for (int i = 0; i < colvo; i++) {
		workers[i].putemploy();
	}
	delete[]workers;
	return 0;
}

void employee::getemploy() {
	int vibor;
	cout << "Введите номер: ";
	cin >> number;
	cout << "Введите оклад: ";
	cin >> oklad;
	cout << "Введите дату приёма(день,месяц,год через пробел): ";
	cin >> dt.day;
	cin >> dt.month;
	cin >> dt.year;
	cout << "Выберите статус:\n 0.Лаборант\n1.Секретарь\n2.Менеджер\n3.Программист\n";
	cin >> vibor;
	switch (vibor)
	{
	case(Лаборант):
		status = "Лаборант";
		break;
	case(Секретарь):
		status = "Секретарь";
		break;
	case(Менеджер):
		status = "Менеджер";
		break;
	case(Программист):
		status = "Программист";
		break;
	}
}
void employee::putemploy() {
	cout << "Номер сотрудника: " << number << endl;
	cout<< "Оклад: " << oklad<<endl;
	cout << "Дата приема: " << dt.day << "." << dt.month << "." << dt.year<<endl;
	cout << "Статус: " << status << endl;
}