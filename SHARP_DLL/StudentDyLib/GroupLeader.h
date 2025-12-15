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

    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& boost::serialization::base_object<Student>(*this);
        ar& email;
        ar& phoneNumber;
    }
};


#endif //STUDENTDYLIB_GROUPLEADER_H