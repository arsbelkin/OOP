#include <iostream>
#include <fstream>
#include "group.h"
#include <algorithm>
#include <QFontMetrics>

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


void Group::showAllStudents(QPainter *painter, const int &st_Xpoint, const int &st_Ypoint,
                            const int &rWidth, const int &rHeight) const{
    int i = 1;

    for_each(this->students.begin(), this->students.end(),
             [&painter, &i, &st_Xpoint, &st_Ypoint, &rWidth, &rHeight](const std::shared_ptr<Student> &stdnt){
        stdnt->draw(painter, st_Xpoint, st_Ypoint + i * rHeight, rWidth, rHeight);
        ++i;
    });
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


    for_each(this->students.begin(), this->students.end(),
             [&max_id](const auto &student){
        max_id = max(max_id, student->get_id());
    });

    Student::set_currentID(max_id);
}


Group::~Group(){
    this->deleteAllStudents();
}
