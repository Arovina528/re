#include <iostream>
#include <fstream>
#include <string>
#include "module_3.h"

using namespace std;

void save() {
    ifstream fin("intermediate.txt");
    ofstream fout("result.txt");

    string buffer;
    while (getline(fin, buffer)) {
        fout << buffer << endl;
    }

    fin.close();
    fout.close();

    cout << "Результат сохранён в файл: result.txt\n";
}
