#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

void MainMenu();
int menu1();
int menu2();
int input_number();
class Matrix
{
private:
    int size;
    int** matrix;
    friend void Show_matrix(Matrix&);
    friend void Input_matrix(Matrix&);
public:
    Matrix(int N);
    Matrix(Matrix&);
    ~Matrix();
    Matrix& operator=(const Matrix& mass) {
        if (this != &mass) {
            size = mass.size;
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++) {
                    matrix[i][j] = mass.matrix[i][j];
                }
        }
        return *this;
    }
    Matrix operator+(const Matrix& mass)
    {
        Matrix result(*this);
        size = mass.size;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                result.matrix[i][j] += mass.matrix[i][j];
        return result;
    }
    Matrix operator&(const Matrix& mass)
    {
        Matrix result(*this);
        size = mass.size;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.matrix[i][j] = 0;
                for (int k = 0; k < size; k++)
                    result.matrix[i][j] += mass.matrix[k][j] * matrix[i][k];
            }
        }
        return result;
    }
    friend istream &operator>> (istream & input, Matrix &mass)
    {
        for (int i = 0; i < mass.size; i++)
            for (int j = 0; j < mass.size; j++)
                input >> mass.matrix[i][j];
        return input; 
    }
    friend ostream &operator<< (ostream &output,const  Matrix &mass)
    {
        for (int i = 0; i < mass.size; i++)
        {
            for (int j = 0; j < mass.size; j++)
            {
                output << mass.matrix[i][j];
            }
            output << endl;
        }
        output << endl;
        return output; 
    }       
};

Matrix::Matrix(int N)
{
    size = N;
    matrix = new int* [size];
    for (int i = 0; i < size; i++)
        matrix[i] = new int[size];
}

Matrix::Matrix(Matrix& mass)
{
    size = mass.size;
    matrix = new int* [size];
    for (int i = 0; i < size; i++)
        matrix[i] = new int[size];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            matrix[i][j] = mass.matrix[i][j];
}

Matrix::~Matrix() {
    for (int i = 0; i < size; i++)
        delete matrix[i];
    delete[]matrix;
}

void Show_matrix(Matrix& mass)
{
    for (int i = 0; i < mass.size; i++) {
        for (int j = 0; j < mass.size; j++)
            cout << mass.matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void Input_matrix(Matrix& mass)
{
    int choice = menu1();
    	if (choice == 0)
    	{
    		int to, from;
            while (1) {
            cout << "Введите границы" << endl;
    		cout << "От: "; 
            from = input_number();
            cout << "До: ";
            to = input_number();
            if (to < from) {
                cout << "Неккоретный ввод! Введите еще раз!" << endl;
            }
            else break;
            }
    		for (int i = 0; i < mass.size; i++)
    			for (int j = 0; j < mass.size; j++)
                    mass.matrix[i][j] = from + rand() % (to - from + 1);
    	}
        else if (choice == 1)
        {
            cout << "Введите элементы матрицы: " << endl;
            for (int i = 0; i < mass.size; i++)
                for (int j = 0; j < mass.size; j++) {
                    cout << "Элемент матрицы[" << i + 1 << "][" << j + 1 << "]=";
                    cin >> mass.matrix[i][j];
                }
    	}
    	system("cls");
}

int main()
{
    setlocale(LC_ALL, "rus");
    MainMenu();
    system("pause");
    return 0;
}

void MainMenu() {
   int N, menu = 0;
    cout << "Введите размер матриц: ";
    N=input_number();
    Matrix m1(N);
    Input_matrix(m1);
    Matrix m2(N);
    Input_matrix(m2);
    Matrix sum(N);
    Matrix um(N);
    while (true) {
        menu = menu2();
        switch (menu) {
        case 0:
            cout << "Первая матрица: " << endl;
            Show_matrix(m1);
            cout << "Вторая матрица: " << endl;
            Show_matrix(m2);
            system("pause");
            break;
        case 1:
            cout << "Оператор +:" << endl;
            sum = m1 + m2;
            Show_matrix(sum);
            system("pause");
            break;
        case 2:
            cout << "Оператор &:" << endl;
            um = m1 & m2;
            Show_matrix(um);
            system("pause");
            break;
        case 3: return;
        }
    }
}

int menu1()
{
	int choiceButton = 0, button = 0;
	system("cls");
	while (true)
	{
		cout << "Выберите способ заполнения матрицы " << endl;
		choiceButton = (choiceButton + 2) % 2;

		if (choiceButton == 0) cout << "-> Заполнение массива случайными элементами" << endl;
		else cout << " Заполнение массива случайными элементами" << endl;

		if (choiceButton == 1) cout << "-> Заполнение массива с клавиатуры" << endl;
		else cout << " Заполнение массива с клавиатуры" << endl;

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

int menu2()
{
    int choiceButton = 0, button = 0;
    system("cls");
    while (true)
    {
        cout << "Выберите перегрузку оператора: " << endl;
        choiceButton = (choiceButton + 4) % 4;

        if (choiceButton == 0) cout << "-> Просмотр матриц" << endl;
        else cout << "Просмотр матриц" << endl;

        if (choiceButton == 1) cout << "-> Оператор +" << endl;
        else cout << " Оператор +" << endl;

        if (choiceButton == 2) cout << "-> Оператор &" << endl;
        else cout << " Оператор &" << endl;

        if (choiceButton == 3) cout << "-> Выход" << endl;
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

int input_number() {
    string number;
    while (true) {
        int key;
        key = _getch();
        if (key == 224) {
            key = _getch();
        }
        else
            if (key == 8) {
                if (number.length() != 0) {
                    cout << '\b' << " " << '\b';
                    number.erase(number.length() - 1);
                }
            }
            else
                if (key == 13) break;
                else
                    if (key >= '0' && key <= '9') {
                        number = number + (char)key;
                        cout << (char)key;
                    }
    }
    cout << endl;
    return stoi(number);
}