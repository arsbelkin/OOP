#pragma once
#include <boost/serialization/access.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/base_object.hpp>


class Student{
private:
    static int current_studentId;
    
    int studentId;
    std::string name;
    std::string surname;
    int age;
    bool gender;
public:
    Student() : studentId(0), name(""), surname(""), age(0), gender(0) { };
    Student(std::istream &is);
    
    virtual void writeToConsole() const;
    
    virtual std::string get_className() const {return "студент";};
    static std::string get_classNameStatic() {return "студент";};
    
    int get_id() const;
    int get_age() const;
    std::string get_name() const;
    std::string get_surname() const;
    bool get_gender() const;
    std::string print_gender() const;
    
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

BOOST_CLASS_EXPORT_KEY(Student)
