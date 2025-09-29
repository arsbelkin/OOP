#pragma once
#include <iostream>
#include "./student.h"
#include "./groupLeader.h"
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>


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
    
    void showAllStudents() const;
    void deleteAllStudents();
    
    void saveStudents(std::ostream &file);
    void loadStudents();
    
    void set_current_studentID();
};
