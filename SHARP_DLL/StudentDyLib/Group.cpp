//
// Created by Арсений Белкин on 15.12.2025.
//

#include "Group.h"
#include <fstream>

using namespace std;


Group::Group(const std::string &titleGroup) {
    this->title = titleGroup;
}


bool Group::loadStudentsFromFile(const char* pathToFile) {
    ifstream file(pathToFile);

    if (file.is_open()){
        boost::archive::binary_iarchive ifile(file);
        ifile >> this->students;
        this->set_current_studentID();
        return true;
    } else {
        return false;
    }
}


std::vector<std::string> Group::get_studentNamesWithInfo() const {
    std::vector<std::string> studentNames;
    for (const auto& student : this->students) {
        studentNames.push_back(student->get_info());
    }
    return studentNames;
}

HelpStruct Group::get_studentInfo(int index) {
    if (index < this->students.size()) {
        return this->students[index]->get_StudentInfo();
    }
    else {
        return {};
    }
}


void Group::set_current_studentID() const{
    int max_id = 0;

    for (const auto &student : this->students){
        max_id = max(max_id, student->get_studentID());
    }

    Student::set_currentID(max_id);
}
