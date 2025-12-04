#ifndef STUDENT_H
#define STUDENT_H


#include <boost/serialization/access.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/base_object.hpp>
#include <string>
#include "QPainter"


class viewDialog;
class CreateDialog;


class Student{
private:
    static int current_studentId;

    int studentId;
    std::string name;
    std::string surname;
    int age;
    bool gender;

    friend class boost::serialization::access;
public:
    Student() : studentId(current_studentId++), name(""), surname(""), age(0), gender(0) { }

    virtual void draw(QPainter *painter, const int &st_Xpoint, const int &st_Ypoint,
                      const int &rWidth, const int &rHeight) const;

    virtual std::string get_className() const {return "студент";}
    static std::string get_classNameStatic() {return "студент";}

    virtual std::string get_info() const;

    virtual void fillFields(viewDialog *dialog);

    virtual void fillFields(CreateDialog *dialog);

    virtual void setParams(CreateDialog *dialog);

    int get_id() const;
    int get_age() const;
    std::string get_name() const;
    std::string get_surname() const;
    bool get_gender() const;
    std::string print_gender() const;

    bool convert_gender(std::string gndr);

    static void set_currentID(const int &new_current_studentId);
    static int get_currentID() {return current_studentId;}

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

#endif // STUDENT_H
