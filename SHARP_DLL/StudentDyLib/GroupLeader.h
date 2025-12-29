//
// Created by Арсений Белкин on 15.12.2025.
//

#ifndef STUDENTDYLIB_GROUPLEADER_H
#define STUDENTDYLIB_GROUPLEADER_H

#include "Student.h"


class GroupLeader : public Student{
    std::string email;
    std::string phoneNumber;

    friend class boost::serialization::access;

public:
    GroupLeader();

    std::string get_info() override {return get_name() + " (староста)";}

    HelpStruct get_StudentInfo() override;

    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& boost::serialization::base_object<Student>(*this);
        ar& email;
        ar& phoneNumber;
    }
};

BOOST_CLASS_EXPORT_KEY(GroupLeader)

#endif //STUDENTDYLIB_GROUPLEADER_H