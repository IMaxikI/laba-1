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
        
        cout << "Элемент " << sim << " удален из множества!" << endl;
    }
    else {
        cout << "Элемента "<< sim << " нет во множестве!"<< endl;
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
    if (count != 0)  cout << "Элемент " << sim << " входит в множество!" << endl;
    else cout << "Элемент " << sim << " не входит в множество!" << endl;
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
    cout << "Пересечение: ";
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
    cout << "Введите размер 1-го множества: ";
    len = inputInt();
    cout << "Введите размер 2-го множества: ";
    len2= inputInt();
    Set<int> intmas(len);
    Set<int> intmas2(len2);
    cout << "Введите 1 множество" << endl;
    for (int i = 0; i < intmas.getLength(); i++) {
        intmas[i] = inputInt();
    }
    cout << "Введите 2 множество" << endl;
    for (int i = 0; i < intmas2.getLength(); i++) {
        intmas2[i] = inputInt();
    }
    system("cls");
    int add, choice, elem;
    while (true) {
        switch (menu()) {
        case 0:
            cout << "1 множество: ";
            intmas.show();
            cout << "2 множество: ";
            intmas2.show();
            break;
        case 1:
            cout << "Введите добавляемый элемент: ";
            add = inputInt();
            cout << "Выберите к какому множеству добавить элемент(1 или 2): ";
            choice = input1or2();
            if (choice == 1) intmas += add;
            else intmas2 += add;
            cout << "Элемент " << add << " добавлен во " << choice << " множество" << endl;
            break;
        case 2:
            cout << "1 множество: ";
            intmas.show();
            cout << "2 множество: ";
            intmas2.show();
            intmas * intmas2;
            break;
        case 3: 
            cout << "Введите элемент, который хотите проверить: ";
            elem = inputInt();
            cout << "Выберите в каком множествe проверить элемент(1 или 2): ";
            choice = input1or2();
            if (choice == 1) intmas.check(elem);
            else intmas2.check(elem);
            break;
        case 4:
            cout << "Введите элемент, который хотите удалить: ";
            elem = inputInt();
            cout << "Выберите в каком множествe удалить элемент(1 или 2): ";
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
        cout << "Выберите пункт меню: " << endl;
        choiceButton = (choiceButton + 6) % 6;

        if (choiceButton == 0) cout << "->Просмотр множеств" << endl;
        else cout << " Просмотр множеств" << endl;

        if (choiceButton == 1) cout << "->Добавить элемент" << endl;
        else cout << " Добавить элемент" << endl;

        if (choiceButton == 2) cout << "->Пересечение множеств" << endl;
        else cout << " Пересечение множеств" << endl;

        if (choiceButton == 3) cout << "->Проверка на включение элемента во множестве" << endl;
        else cout << " Проверка на включение элемента во множестве" << endl;

        if (choiceButton == 4) cout << "->Удаление элемента из множества" << endl;
        else cout << " Удаление элемента из множества" << endl;

        if (choiceButton == 5) cout << "->Удалить множества и выйти" << endl;
        else cout << " Удалить множества и выйти" << endl;

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