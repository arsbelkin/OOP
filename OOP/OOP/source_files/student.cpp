#include <iostream>
#include "fstream"
#include "../header_files/student.h"
#include "../header_files/utils.h"
#include <string>

using namespace std;


int Student::current_studentId = 0;


Student::Student(){
    cout << "----создание студента----" << endl;
    
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
    
    cout << "----------" << endl;
}


Student::Student(std::ifstream &file){
    file >> this->studentId;
    file.ignore(10000, '\n');
    getline(file>>std::ws, this->name);
    getline(file>>std::ws, this->surname);
    file >> this->age;
    file >> this->gender;
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


ostream& operator << (ostream &os, const Student &student){
    os << "-----студент " << student.get_id() << "-----" << endl
        << "id: " << student.get_id() << endl
        << "имя: " << student.name << endl
        << "фамилия: " << student.surname << endl
        << "возраст: " << student.age << endl
        << "пол: " << student.print_gender() << endl
        << "--------------" << endl;

    return os;
}


void Student::save(std::ostream &file) const{
    file << "студент" << endl;
    file << this->studentId << endl;
    file << this->name << endl;
    file << this->surname << endl;
    file << this->age << endl;
    file << this->gender << endl;
}


void Student::set_currentID(int &new_current_studentId){
    Student::current_studentId = new_current_studentId;
}
