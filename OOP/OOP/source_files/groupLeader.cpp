#include <iostream>
#include "../header_files/groupLeader.h"

using namespace std;


GroupLeader::GroupLeader() : Student() {};


GroupLeader::GroupLeader(std::istream &is) : Student(is) {
    cout << "email: ";
    getline(cin >> std::ws, this->email);
    cout << "номер телефона: ";
    getline(cin >> std::ws, this->phoneNumber);
}


void GroupLeader::writeToConsole() const {
    Student::writeToConsole();
    cout << "email: " << this->email << endl;
    cout << "номер телефона: " << this->phoneNumber << endl;
}

