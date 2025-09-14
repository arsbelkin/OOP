#pragma once


class Student{
private:
    static int current_studentId;
    
    int studentId;
    std::string name;
    std::string surname;
    int age;
    bool gender;
public:
    Student();
    Student(std::ifstream &file);
    
    int get_id() const;
    int get_age() const;
    std::string get_name() const;
    std::string get_surname() const;
    bool get_gender() const;
    std::string print_gender() const;
    
    friend std::ostream& operator << (std::ostream &os, const Student &student);
    void save(std::ostream &file) const;
    
    static void set_currentID(int &new_current_studentId);
};
