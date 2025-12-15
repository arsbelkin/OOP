//
// Created by Арсений Белкин on 15.12.2025.
//

#include "Student.h"


int Student::current_studentId = 0;


int Student::get_studentID() const {
    return this->studentId;
}

void Student::set_currentID(int &new_current_studentId){
    Student::current_studentId = new_current_studentId;
}
