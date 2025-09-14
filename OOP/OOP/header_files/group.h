#pragma once
#include "./student.h"


class Group{
private:
    std::string title;
    std::vector<Student*> students;
public:
    Group(const std::string &title);
    ~Group();
    
    std::string get_title() const;
    
    int addStudent();
    int addStudent(std::ifstream &file);
    void showAllStudents() const;
    void deleteAllStudents();
    
    void saveStudents(std::ostream &file) const;
    void loadStudents();
    
    void set_current_studentID();
};
