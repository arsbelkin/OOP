#ifndef GROUP_H
#define GROUP_H


#include <iostream>
#include "student.h"
#include "groupLeader.h"
#include <vector>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include "QPainter"


class Group{
private:
    std::string title;
    std::vector<std::shared_ptr<Student>> students;

    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& students;
    }
public:
    Group(const std::string &title);
    ~Group();

    template<typename T>
    void addStudent(){
        std::cout << "-----создание " << T::get_classNameStatic() << "-----" << std::endl;

        std::shared_ptr<T> newObj = std::make_shared<T>(std::cin);
        this->students.push_back(newObj);

        std::cout << "-------------" << std::endl;
    };

    std::string get_title() const;

    std::vector<std::shared_ptr<Student>> get_students() const;

    void showAllStudents(QPainter *painter, double wdth, double hgth) const;
    void deleteAllStudents();

    bool saveStudents(const std::string& filename);
    bool loadStudents(const std::string& filename);

    void set_current_studentID();

    std::vector<std::vector<std::string>> getData() const;

    std::vector<double> calcWidth(std::vector<std::vector<std::string>> &allData, QPainter *painter) const;

    void draw(QPainter *painter,
              std::vector<std::string> &elem,
              std::vector<double> dWdth,
              double &sum, double wdth, double tHeight, int &k) const;
};


#endif // GROUP_H
