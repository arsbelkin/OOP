#include <iostream>
#include <fstream>
#include "group.h"

using namespace std;


Group::Group(const std::string &title){
    this->title = title;
}


std::string Group::get_title() const{
    return this->title;
}


std::vector<std::shared_ptr<Student>> Group::get_students() const{
    return this->students;
}


void Group::showAllStudents() const{
    if (!this->students.size()){
        cout << "Нет обучающихся в группе!" << endl;
        return;
    }

    for (const auto& student : this->students){
        cout << "-----" << student->get_className() << " " << student->get_id() << "-----" << endl;
        student->writeToConsole();
        cout << "--------------" << endl;
    }

}


void Group::deleteAllStudents(){
    this->students.clear();
}


bool Group::saveStudents(const string& filename){
    ofstream file(filename);

    if (file.is_open()){
        boost::archive::binary_oarchive ofile(file);
        ofile << this->students;
        return true;
    } else {
        return false;
    }
}


bool Group::loadStudents(const string& filename){
    ifstream file(filename);

    if (file.is_open()){
        boost::archive::binary_iarchive ifile(file);
        ifile >> this->students;
        this->set_current_studentID();
        return true;
    } else {
        return false;
    }
}


void Group::set_current_studentID(){
    int max_id = 0;

    for (const auto &student : this->students){
        max_id = max(max_id, student->get_id());
    }

    Student::set_currentID(max_id);
}


Group::~Group(){
    this->deleteAllStudents();
}
