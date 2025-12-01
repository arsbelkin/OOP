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

    std::string get_className() const override {return "староста";}
    static std::string get_classNameStatic() {return "староста";}

    std::string get_email() const {return this->email;}
    std::string get_phoneNumber() const {return this->phoneNumber;}

    void draw(QPainter *painter, const int &st_Xpoint, const int &st_Ypoint,
              const int &rWidth, const int &rHeight) const override;

    std::string get_info() const override;

    void fillFields(QLineEdit *id_edit,
                    QLineEdit *name_edit,
                    QLineEdit *surname_edit,
                    QLineEdit *age_edit,
                    QLineEdit *gender_edit,
                    QLabel *email_label, QLineEdit *email_edit,
                    QLabel *phone_label, QLineEdit *phone_edit) override;

    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& boost::serialization::base_object<Student>(*this);
        ar& email;
        ar& phoneNumber;
    }
};

BOOST_CLASS_EXPORT_KEY(GroupLeader)

#endif // GROUPLEADER_H
