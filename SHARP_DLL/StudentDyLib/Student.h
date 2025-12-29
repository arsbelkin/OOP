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


extern "C" {
    struct HelpStruct {
        bool IsGroupLeader=false;
        int StudentId=-1;
        const char* Name=strdup("");
        const char* Surname=strdup("");
        int Age=-1;
        bool Gender=false;
        const char* Email=strdup("");
        const char* PhoneNumber=strdup("");
    };
}


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
    virtual ~Student() = default;

    Student(HelpStruct s);

    int get_studentID() const;
    std::string get_name() const {return name;}
    std::string get_surname() const {return surname;}
    int get_age() const {return age;}
    bool get_gender() const {return gender;}

    virtual std::string get_info() {return name;}

    virtual HelpStruct get_StudentInfo();

    static void set_currentID(const int &new_current_studentId);

    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& studentId;
        ar& name;
        ar& surname;
        ar& age;
        ar& gender;
    }
};

BOOST_CLASS_EXPORT_KEY(Student)

#endif //STUDENTDYLIB_STUDENT_H
