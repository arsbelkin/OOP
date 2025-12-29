//
// Created by Арсений Белкин on 15.12.2025.
//

#include "Student.h"


int Student::current_studentId = 0;


int Student::get_studentID() const {
    return this->studentId;
}

HelpStruct Student::get_StudentInfo() {
    HelpStruct result{};
    result.IsGroupLeader = false;
    result.StudentId = get_studentID();
    result.Name = strdup(get_name().c_str());
    result.Surname = strdup(get_surname().c_str());
    result.Age = get_age();
    result.Gender = get_gender();
    result.Email = strdup("");
    result.PhoneNumber = strdup("");
    return result;
}

void Student::set_currentID(const int &new_current_studentId){
    Student::current_studentId = new_current_studentId;
}
