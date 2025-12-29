//
// Created by Арсений Белкин on 15.12.2025.
//

#include "GroupLeader.h"

GroupLeader::GroupLeader() : Student() {}

HelpStruct GroupLeader::get_StudentInfo() {
    HelpStruct result =  Student::get_StudentInfo();
    result.IsGroupLeader = true;
    result.Email = strdup(email.c_str());
    result.PhoneNumber = strdup(phoneNumber.c_str());
    return result;
}