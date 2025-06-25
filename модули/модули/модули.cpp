// модули.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

// Структура данных об игрушке
struct Toy {
    string name;     // Название игрушки
    int price;       // Стоимость
    int age_from;    // Возраст от
    int age_to;      // Возраст до
};

// === Ввод данных ===
void enter() {
    ofstream fout("Assort.txt");
    int n;
    cout << "Введите количество игрушек: ";
    cin >> n;

    Toy* arr = new Toy[n];

    for (int i = 0; i < n; ++i) {
        cout << "\nИгрушка #" << i + 1 << endl;
        cout << " Название: ";
        cin >> arr[i].name;
        cout << " Цена: ";
        cin >> arr[i].price;
        cout << " Возраст от: ";
        cin >> arr[i].age_from;
        cout << " Возраст до: ";
        cin >> arr[i].age_to;

        fout << arr[i].name << " " << arr[i].price << " "
            << arr[i].age_from << " " << arr[i].age_to << endl;
    }

    fout.close();
    delete[] arr;

    cout << "Данные записаны в Assort.txt\n";
}

// === Поиск по условию ===
void find() {
    ifstream fin("Assort.txt");
    ofstream fout("intermediate.txt");

    if (!fin) {
        cout << "Файл Assort.txt не найден!\n";
        return;
    }

    vector<Toy> toys;
    Toy temp;

    while (fin >> temp.name >> temp.price >> temp.age_from >> temp.age_to) {
        toys.push_back(temp);
    }

    cout << "\nИгрушки, подходящие детям 4 и 10 лет:\n";
    fout << "Игрушки, подходящие детям 4 и 10 лет:\n";

    for (const auto& t : toys) {
        if (t.age_from <= 4 && t.age_to >= 4 && t.age_from <= 10 && t.age_to >= 10) {
            cout << " " << t.name << endl;
            fout << t.name << endl;
        }
    }

    fin.close();
    fout.close();
}

// === Сохранение результата ===
void save() {
    ifstream fin("intermediate.txt");
    ofstream fout("result.txt");

    if (!fin) {
        cout << "Файл intermediate.txt не найден!\n";
        return;
    }

    string buffer;
    while (getline(fin, buffer)) {
        fout << buffer << endl;
    }

    fin.close();
    fout.close();

    cout << "Результат сохранён в файл: result.txt\n";
}

// === Главное меню ===
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    setlocale(0, "");
    int choice = 0;

    while (choice != 4) {
        cout << "\nМеню:\n";
        cout << "1 - Ввод данных\n";
        cout << "2 - Поиск по условию\n";
        cout << "3 - Сохранение результата\n";
        cout << "4 - Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            enter();
            break;
        case 2:
            find();
            break;
        case 3:
            save();
            break;
        case 4:
            cout << "Завершение программы...\n";
            break;
        default:
            cout << "Неверный выбор. Повторите.\n";
        }
    }

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
