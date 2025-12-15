//
// Created by Арсений Белкин on 15.12.2025.
//

#ifndef STUDENTDYLIB_STUDENT_H
#define STUDENTDYLIB_STUDENT_H

#include <string>
#include <boost/serialization/access.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/base_object.hpp>


class Student {
    static int current_studentId;

    int studentId;
    std::string name;
    std::string surname;
    int age;
    bool gender;

    friend class boost::serialization::access;
public:
    Student() : studentId(0), name(""), surname(""), age(0), gender(0) { };

    int get_studentID() const;

    static void set_currentID(int &new_current_studentId);

    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& studentId;
        ar& name;
        ar& surname;
        ar& age;
        ar& gender;
    }
};


#endif //STUDENTDYLIB_STUDENT_H
