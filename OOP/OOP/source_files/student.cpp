#include <iostream>
#include "../header_files/student.h"
#include <string>

using namespace std;


int Student::get_id() const{
    return this->id;
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
