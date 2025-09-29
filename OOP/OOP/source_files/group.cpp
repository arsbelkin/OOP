#include <iostream>
#include <fstream>
#include "../header_files/group.h"

using namespace std;


Group::Group(const std::string &title){
    this->title = title;
}


std::string Group::get_title() const{
    return this->title;
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
    cout << "все обучающиеся удалены!" << endl;
}


void Group::saveStudents(std::ostream &file){
    boost::archive::binary_oarchive ofile(file);
    ofile << *this;
    
    cout << "все обучающиеся сохранены!" << endl;
}


void Group::loadStudents(){
    string file_name;
    
    cout << "файл для загрузки: ";
    getline(cin>>std::ws, file_name);
    
    ifstream file("./static/" + file_name);
    
    if (file.is_open()){
        boost::archive::binary_iarchive ifile(file);
        ifile >> *this;
        this->set_current_studentID();
    } else {
        cout << "файл не открыт!" << endl;
    }
    
    cout << this->students.size() << " обучающихся было загружено" << endl;
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
