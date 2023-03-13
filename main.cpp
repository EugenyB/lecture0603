#include <iostream>
#include <fstream>
#include "mystruct.h"

using namespace std;

int createFileWithOneStruct() {
    ofstream fout("file.bin");
    if (!fout.is_open()) {
        cerr << "Error: Cannot open file\n";
        return 1;
    }

    Person p = {"John", 20, 1.75};

    //fout.write((char*)(&p), sizeof(Person));
    fout.write(reinterpret_cast<char*>(&p), sizeof(p));
    fout.close();
    return 0;
}

int readFileWithOneStruct() {
    ifstream fin("file.bin", ios::binary);
    if (!fin.is_open()) {
        cerr << "Error: Cannot open file\n";
        return 1;
    }
    Person p;
    fin.read((char*)(&p), sizeof(p));
    cout << p.name << "\n";
    cout << p.age << "\n";
    cout << p.height << "\n";

    fin.close();
    return 0;
}

int writeArrayOfStructToFile() {
    Person p1 = {"John", 20, 1.75};
    Person p2 = {"Jane", 19, 1.7};
    Person p3 = {"Piter", 22, 1.65};

    const int size = 3;

    Person people[] = {p1,p2,p3};

    ofstream fout("file.bin");
    if (!fout.is_open()) {
        cerr << "Error: Cannot open file\n";
        return 1;
    }

    fout.write((char *)(people), sizeof(Person)*size);

    fout.close();

    return 0;
}

int main() {
    ifstream fin("file.bin", ios::binary);
    if (!fin.is_open()) {
        cerr << "Error: Cannot open file\n";
        return 1;
    }

    const int size = 3;

    Person people[size];

    fin.read((char*)people, sizeof(Person)*size);

    for (int i = 0; i < size; i++) {
        cout << people[i].name << " " << people[i].age << " " << people[i].height << endl;
    }

    fin.close();
}
