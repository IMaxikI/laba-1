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
		��������,
		���������,
		��������,
		�����������
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
	cout << "������� ���������� ����������� �����������: ";
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
	cout << "������� �����: ";
	cin >> number;
	cout << "������� �����: ";
	cin >> oklad;
	cout << "������� ���� �����(����,�����,��� ����� ������): ";
	cin >> dt.day;
	cin >> dt.month;
	cin >> dt.year;
	cout << "�������� ������:\n 0.��������\n1.���������\n2.��������\n3.�����������\n";
	cin >> vibor;
	switch (vibor)
	{
	case(��������):
		status = "��������";
		break;
	case(���������):
		status = "���������";
		break;
	case(��������):
		status = "��������";
		break;
	case(�����������):
		status = "�����������";
		break;
	}
}
void employee::putemploy() {
	cout << "����� ����������: " << number << endl;
	cout<< "�����: " << oklad<<endl;
	cout << "���� ������: " << dt.day << "." << dt.month << "." << dt.year<<endl;
	cout << "������: " << status << endl;
}