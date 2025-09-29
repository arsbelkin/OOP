#include <iostream>
#include "fstream"
#include "../header_files/student.h"
#include "../header_files/utils.h"
#include <string>

using namespace std;


int Student::current_studentId = 0;


Student::Student(std::istream &is){
    this->studentId = ++Student::current_studentId;
    cout << "id: " << this->studentId << endl;
    
    cout << "имя: ";
    getline(cin >> std::ws, this->name);
    
    cout << "фамилия: ";
    getline(cin >> std::ws, this->surname);
    
    cout << "возраст: ";
    this->age = valid_int(0, 1000);
    
    cout << "пол(0-Ж, 1-М): ";
    this->gender = valid_int(0, 1);
}


int Student::get_id() const{
    return this->studentId;
}


int Student::get_age() const{
    return this->age;
}


std::string Student::get_name() const{
    return this->name;
}


std::string Student::get_surname() const{
    return this->surname;
}


bool Student::get_gender() const{
    return this->gender;
}


std::string Student::print_gender() const{
    return this->gender == 1 ? "М" : "Ж";
}


void Student::writeToConsole() const {
      cout << "id: " << this->studentId << endl
        << "имя: " << this->name << endl
        << "фамилия: " << this->surname << endl
        << "возраст: " << this->age << endl
        << "пол: " << this->print_gender() << endl;
}


void Student::set_currentID(int &new_current_studentId){
    Student::current_studentId = new_current_studentId;
}
