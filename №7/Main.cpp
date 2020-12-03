#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

int menu();
int inputInt();
int input1or2();

template <class T> class Set
{
private:
    int length;
    T* data;
public:
    Set()
    {
        length = 0;
        data = nullptr;
    }
    Set(int len)
    {
        data = new T[len];
        length = len;
    }
    ~Set()
    {
        delete[] data;
    }
    void Delete()
    {
        delete[] data;
        data = nullptr;
        length = 0;
    }
    T& operator[](int index)
    {
        if (index < 0 && index >= length) index = 0;
        return data[index];
    }
    T* operator+=(const T t) {
        length++;
        T* tmp = new T[length];
        copy(data, data + length - 1, tmp);
        data = tmp;
        tmp = NULL;
        delete[]tmp;
        data[length - 1] = t;
        cout << endl;
        return data;
    }
    void operator*(Set<T>&);
    void check(T);
    void show();
    int getLength();
    void DelElem(T);
};
template <class T> void Set<T>::DelElem(T sim) {
    int count = 0, number=0;
    for (int i = 0; i < length; i++)
    {
        if (data[i] == sim) {
            count++;
            number = i;
            break;
        }
    }
    for (int j = number; j < length - 1; j++)
    {
        data[j] = data[j + 1];
    }
    length--;
    if (count != 0) {    
        
        cout << "������� " << sim << " ������ �� ���������!" << endl;
    }
    else {
        cout << "�������� "<< sim << " ��� �� ���������!"<< endl;
    }
}

template <class T> void Set<T>::show() {
    for (int i = 0; i < length; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

template <class T> void Set<T>::check(T sim) {
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (data[i] == sim) {
            count++;
            break;
        }
    }
    if (count != 0)  cout << "������� " << sim << " ������ � ���������!" << endl;
    else cout << "������� " << sim << " �� ������ � ���������!" << endl;
    cout << endl;
}

template <class T> void Set<T>::operator*(Set<T>& massiv1) {
    Set<T> mass(length);
    int k = 0, count=0;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < massiv1.length; j++) {
            count = 0;
            if (data[i] == massiv1.data[j]) {
                for (int g = 0; g < k; g++) {
                    if (data[i] == mass[g]) {
                        count++;
                        break;
                    }
                }
                if (count == 0) {
                    mass[k] = data[i];
                    k++;
                }
            }
        }
    }
    cout << "�����������: ";
    for (int i = 0; i < k; i++) {
        cout << mass[i] << " ";
    }
    cout << endl;
}

template <class T> int Set<T>::getLength() {
    return length;
}

int main() {
    setlocale(0, "rus");
    int len, len2;
    cout << "������� ������ 1-�� ���������: ";
    len = inputInt();
    cout << "������� ������ 2-�� ���������: ";
    len2= inputInt();
    Set<int> intmas(len);
    Set<int> intmas2(len2);
    cout << "������� 1 ���������" << endl;
    for (int i = 0; i < intmas.getLength(); i++) {
        intmas[i] = inputInt();
    }
    cout << "������� 2 ���������" << endl;
    for (int i = 0; i < intmas2.getLength(); i++) {
        intmas2[i] = inputInt();
    }
    system("cls");
    int add, choice, elem;
    while (true) {
        switch (menu()) {
        case 0:
            cout << "1 ���������: ";
            intmas.show();
            cout << "2 ���������: ";
            intmas2.show();
            break;
        case 1:
            cout << "������� ����������� �������: ";
            add = inputInt();
            cout << "�������� � ������ ��������� �������� �������(1 ��� 2): ";
            choice = input1or2();
            if (choice == 1) intmas += add;
            else intmas2 += add;
            cout << "������� " << add << " �������� �� " << choice << " ���������" << endl;
            break;
        case 2:
            cout << "1 ���������: ";
            intmas.show();
            cout << "2 ���������: ";
            intmas2.show();
            intmas * intmas2;
            break;
        case 3: 
            cout << "������� �������, ������� ������ ���������: ";
            elem = inputInt();
            cout << "�������� � ����� ��������e ��������� �������(1 ��� 2): ";
            choice = input1or2();
            if (choice == 1) intmas.check(elem);
            else intmas2.check(elem);
            break;
        case 4:
            cout << "������� �������, ������� ������ �������: ";
            elem = inputInt();
            cout << "�������� � ����� ��������e ������� �������(1 ��� 2): ";
            choice = input1or2();
            if (choice == 1) intmas.DelElem(elem);
            else intmas2.DelElem(elem);
            break;
        case 5:
            intmas.Delete();
            intmas2.Delete();
            return 0;
        }
        system("pause");
        system("cls");
    }
    return 0;
}

int menu()
{
    int choiceButton = 0, button = 0;
    system("cls");
    while (true)
    {
        cout << "�������� ����� ����: " << endl;
        choiceButton = (choiceButton + 6) % 6;

        if (choiceButton == 0) cout << "->�������� ��������" << endl;
        else cout << " �������� ��������" << endl;

        if (choiceButton == 1) cout << "->�������� �������" << endl;
        else cout << " �������� �������" << endl;

        if (choiceButton == 2) cout << "->����������� ��������" << endl;
        else cout << " ����������� ��������" << endl;

        if (choiceButton == 3) cout << "->�������� �� ��������� �������� �� ���������" << endl;
        else cout << " �������� �� ��������� �������� �� ���������" << endl;

        if (choiceButton == 4) cout << "->�������� �������� �� ���������" << endl;
        else cout << " �������� �������� �� ���������" << endl;

        if (choiceButton == 5) cout << "->������� ��������� � �����" << endl;
        else cout << " ������� ��������� � �����" << endl;

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
int inputInt() {
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
                if (i >= '0' && i <= '9') {
                    number = number + par;
                    cout << par;
                }
            }
    }
    cout << endl;
    return stoi(number);
}
int input1or2() {
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
                if (i >= '1' && i <= '2') {
                    number = number + par;
                    cout << par;
                }
            }
    }
    cout << endl;
    return stoi(number);
}