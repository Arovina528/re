#include <iostream>
#include <fstream>
#include <string>
#include "module_1.h"

using namespace std;

struct Toy {
    string name;
    int price;
    int age_from;
    int age_to;
};

void enter() {
    ofstream fout("Assort.txt");
    int n;
    cout << "������� ���������� �������: ";
    cin >> n;
    Toy* arr = new Toy[n];

    for (int i = 0; i < n; ++i) {
        cout << "\n������� #" << i + 1 << endl;
        cout << " ��������: ";
        cin >> arr[i].name;
        cout << " ����: ";
        cin >> arr[i].price;
        cout << " ������� ��: ";
        cin >> arr[i].age_from;
        cout << " ������� ��: ";
        cin >> arr[i].age_to;

        fout << arr[i].name << " " << arr[i].price << " " << arr[i].age_from << " " << arr[i].age_to << endl;
    }

    fout.close();
    delete[] arr;
}
