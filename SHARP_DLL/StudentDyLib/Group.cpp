//
// Created by Арсений Белкин on 15.12.2025.
//

#include "Group.h"
#include <fstream>

using namespace std;


bool Group::loadStudentsFromFile(const std::string &pathToFile) {
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


void Group::set_current_studentID() const{
    int max_id = 0;

    for (const auto &student : this->students){
        max_id = max(max_id, student->get_studentID());
    }

    Student::set_currentID(max_id);
}
