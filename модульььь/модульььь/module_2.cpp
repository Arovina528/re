#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "module_2.h"

using namespace std;

struct Toy {
    string name;
    int price;
    int age_from;
    int age_to;
};

void find() {
    ifstream fin("Assort.txt");
    ofstream fout("intermediate.txt");

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
