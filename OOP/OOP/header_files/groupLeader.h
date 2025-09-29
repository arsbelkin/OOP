#pragma once
#include "./student.h"


class GroupLeader : public Student{
private:
    std::string email;
    std::string phoneNumber;
public:
    GroupLeader();
    GroupLeader(std::istream &is);
    
    std::string get_className() const override {return "староста";};
    static std::string get_classNameStatic() {return "староста";};
    
    void writeToConsole() const override;
    
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& boost::serialization::base_object<Student>(*this);
        ar& email;
        ar& phoneNumber;
    }
};

BOOST_CLASS_EXPORT_KEY(GroupLeader)
