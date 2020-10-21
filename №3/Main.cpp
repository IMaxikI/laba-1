#include <iostream>
#include <conio.h>

using namespace std;

int menu1();
int menu2();
class Matrix
{
private:
    int size;
    int** matrix;
    friend void Show(Matrix&);
    friend void Input(Matrix&);
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
    Matrix operator+(const Matrix& Obj)
    {
        Matrix result(*this);
        size = Obj.size;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                result.matrix[i][j] += Obj.matrix[i][j];
        return result;
    }
    Matrix operator&(const Matrix& Obj)
    {
        Matrix result(*this);
        size = Obj.size;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.matrix[i][j] = 0;
                for (int k = 0; k < size; k++)
                    result.matrix[i][j] += Obj.matrix[k][j] * matrix[i][k];
            }
        }
        return result;
    }
};

Matrix::Matrix(int N)
{
    size = N;
    matrix = new int* [size];
    for (int i = 0; i < size; i++)
        matrix[i] = new int[size];
}

Matrix::Matrix(Matrix& obj)
{
    size = obj.size;
    matrix = new int* [size];
    for (int i = 0; i < size; i++)
        matrix[i] = new int[size];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            matrix[i][j] = obj.matrix[i][j];
}

Matrix::~Matrix() {
    for (int i = 0; i < size; i++)
        delete matrix[i];
    delete[]matrix;
}

void Show(Matrix& Obj)
{
    for (int i = 0; i < Obj.size; i++) {
        for (int j = 0; j < Obj.size; j++)
            cout << Obj.matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void Input(Matrix& Obj)
{
    int choice = menu1();
    	if (choice == 0)
    	{
    		int to, from;
    		cout << "Введите границы" << endl;
    		cout << "От: ";
    		cin >> from;
    		cout << "До: ";
    		cin >> to;
    		for (int i = 0; i < Obj.size; i++)
    			for (int j = 0; j < Obj.size; j++)
                    Obj.matrix[i][j] = from + rand() % (to - from + 1);
    	}
        else if (choice == 1)
        {
            cout << "Введите элементы матрицы: " << endl;
            for (int i = 0; i < Obj.size; i++)
                for (int j = 0; j < Obj.size; j++) {
                    cout << "Элемент матрицы[" << i + 1 << "][" << j + 1 << "]=";
                    cin >> Obj.matrix[i][j];
                }
    	}
    	system("cls");
}

int main()
{
    setlocale(LC_ALL, "rus");
    int N,menu=0;
    cout << "Введите размер матриц: ";
    cin >> N;
    Matrix m1(N);
    Input(m1);
    Matrix m2(N);
    Input(m2);
    Matrix sum(N);
    Matrix um(N);
    while (true) {
        menu = menu2();
        switch (menu) {
        case 0:    
            cout << "Первая матрица: " << endl;
            Show(m1);
            cout << "Вторая матрица: " << endl;
            Show(m2);
            system("pause");
            break;
        case 1:
            cout << "Оператор +:" << endl;
            sum = m1 + m2;
           Show(sum);
            system("pause");
            break;
        case 2:
            cout << "Оператор &:" << endl;
            um = m1 & m2;
           Show(um);
            system("pause");
            break;
        case 3: return 0;
        }
    }
    system("pause");
    return 0;
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