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


int Group::addStudent(){
    Student* newStudent = new Student();
    this->students.push_back(newStudent);
    return newStudent->get_id();
}


int Group::addStudent(std::ifstream &file){
    Student* newStudent = new Student(file);
    this->students.push_back(newStudent);
    return newStudent->get_id();
}


void Group::showAllStudents() const{
    if (!this->students.size()){
        cout << "Нет студентов в группе!" << endl;
        return;
    }
        
    for (Student* student : this->students)
        cout << *student << endl;
}


void Group::deleteAllStudents(){
    for (Student* student : this->students)
        delete student;
    
    this->students.clear();
    cout << "все студенты удалены!" << endl;
}


void Group::saveStudents(std::ostream &file) const{
    for (Student* student : this->students)
        student->save(file);
    
    cout << "все студенты сохранены!" << endl;
}


void Group::loadStudents(){
    string file_name;
    int counter = 0;
    
    cout << "файл для загрузки: ";
    getline(cin>>std::ws, file_name);
    
    ifstream file("./static/" + file_name);
    
    if (file.is_open()){
        this->deleteAllStudents();
        
        string line;
        
        while (file >> line){
            if (line == "студент"){
                this->addStudent(file);
                ++counter;
            }
        }
        
        file.close();
        this->set_current_studentID();
    } else {
        cout << "файл не открыт!" << endl;
    }
    
    cout << counter << " студентов было загружено" << endl;
}


void Group::set_current_studentID(){
    int max_id = 0;
    
    for (Student* student : this->students){
        max_id = max(max_id, student->get_id());
    }
    
    Student::set_currentID(max_id);
}


Group::~Group(){
    this->deleteAllStudents();
}
