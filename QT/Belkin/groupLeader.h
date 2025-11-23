#ifndef GROUPLEADER_H
#define GROUPLEADER_H


#include "student.h"


class GroupLeader : public Student{
private:
    std::string email;
    std::string phoneNumber;

    friend class boost::serialization::access;
public:
    GroupLeader();
    GroupLeader(std::istream &is);

    std::string get_className() const override {return "староста";};
    static std::string get_classNameStatic() {return "староста";};

    void draw(QPainter *painter, const int &st_Xpoint, const int &st_Ypoint,
              const int &rWidth, const int &rHeight) const override;

    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& boost::serialization::base_object<Student>(*this);
        ar& email;
        ar& phoneNumber;
    }
};

BOOST_CLASS_EXPORT_KEY(GroupLeader)

#endif // GROUPLEADER_H
