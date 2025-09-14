#include <iostream>
#include "fstream"
#include "../header_files/student.h"
#include "../header_files/utils.h"
#include <string>

using namespace std;


int Student::current_studentId = 0;


Student::Student(){
    cout << "----add student----" << endl;
    
    this->studentId = ++Student::current_studentId;
    cout << "id: " << this->studentId << endl;
    
    cout << "name: ";
    getline(cin >> std::ws, this->name);
    
    cout << "surname: ";
    getline(cin >> std::ws, this->surname);
    
    cout << "age: ";
    this->age = valid_int(0, 1000);
    
    cout << "gender(0-W, 1-M): ";
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
    return this->gender == 1 ? "M" : "W";
}


ostream& operator << (ostream &os, const Student &student){
    os << "-----student " << student.get_id() << "-----" << endl
        << "id: " << student.get_id() << endl
        << "name: " << student.name << endl
        << "surname: " << student.surname << endl
        << "age: " << student.age << endl
        << "gender: " << student.print_gender() << endl
        << "--------------" << endl;

    return os;
}


void Student::save(std::ostream &file) const{
    file << "student" << endl;
    file << this->studentId << endl;
    file << this->name << endl;
    file << this->surname << endl;
    file << this->age << endl;
    file << this->gender << endl;
}


void Student::set_currentID(int &new_current_studentId){
    Student::current_studentId = new_current_studentId;
}
