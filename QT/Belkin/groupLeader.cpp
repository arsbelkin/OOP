#include <iostream>
#include "groupLeader.h"
#include <vector>

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


std::vector<std::string> GroupLeader::get_info() const {
    std::vector<std::string> res = Student::get_info();

    res[1] = this->get_className();
    res[5] = this->email;
    res[6] = this->phoneNumber;

    return res;
}
