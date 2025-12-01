#include <iostream>
#include "fstream"
#include "student.h"
#include <string>
#include <vector>


using namespace std;


int Student::current_studentId = 0;


int Student::get_id() const{
    return this->studentId;
}


int Student::get_age() const{
    return this->age;
}


std::string Student::get_name() const{
    return this->name;
}


std::string Student::get_surname() const{
    return this->surname;
}


bool Student::get_gender() const{
    return this->gender;
}


std::string Student::print_gender() const{
    return this->gender == 1 ? "М" : "Ж";
}


void Student::draw(QPainter *painter, const int &st_Xpoint, const int &st_Ypoint,
                   const int &rWidth, const int &rHeight) const{

    painter->drawRect(st_Xpoint, st_Ypoint, rWidth, rHeight);
    painter->drawText(st_Xpoint + 20, st_Ypoint + rHeight * 2 / 3,
                      QString::number(this->studentId));

    painter->drawRect(st_Xpoint + rWidth, st_Ypoint, rWidth, rHeight);
    painter->drawText(st_Xpoint + rWidth + 20, st_Ypoint + rHeight * 2 / 3,
                      QString::fromStdString(this->get_className()));

    painter->drawRect(st_Xpoint + 2 * rWidth, st_Ypoint, rWidth, rHeight);
    painter->drawText(st_Xpoint + 2 * rWidth + 20, st_Ypoint + rHeight * 2 / 3,
                      QString::fromStdString(this->get_name()));

    painter->drawRect(st_Xpoint + 3 * rWidth, st_Ypoint, rWidth, rHeight);
    painter->drawText(st_Xpoint + 3 * rWidth + 20, st_Ypoint + rHeight * 2 / 3,
                      QString::fromStdString(this->get_surname()));

    painter->drawRect(st_Xpoint + 4 * rWidth, st_Ypoint, rWidth, rHeight);
    painter->drawText(st_Xpoint + 4 * rWidth + 20, st_Ypoint + rHeight * 2 / 3,
                      QString::number(this->get_age()));

    painter->drawRect(st_Xpoint + 5 * rWidth, st_Ypoint, rWidth, rHeight);
    painter->drawText(st_Xpoint + 5 * rWidth + 20, st_Ypoint + rHeight * 2 / 3,
                      QString::fromStdString(this->print_gender()));

    painter->drawRect(st_Xpoint + 6 * rWidth, st_Ypoint, rWidth, rHeight);
    painter->drawText(st_Xpoint + 6 * rWidth + 20, st_Ypoint + rHeight * 2 / 3,
                      QString::fromStdString("------"));

    painter->drawRect(st_Xpoint + 7 * rWidth, st_Ypoint, rWidth, rHeight);
    painter->drawText(st_Xpoint + 7 * rWidth + 20, st_Ypoint + rHeight * 2 / 3,
                      QString::fromStdString("------"));
}


void Student::fillFields(QLineEdit *id_edit,
                         QLineEdit *name_edit,
                         QLineEdit *surname_edit,
                         QLineEdit *age_edit,
                         QLineEdit *gender_edit,
                         QLabel *email_label, QLineEdit *email_edit,
                         QLabel *phone_label, QLineEdit *phone_edit)
{
    id_edit->setText(QString::number(this->get_id()));
    name_edit->setText(QString::fromStdString(this->get_name()));
    surname_edit->setText(QString::fromStdString(this->get_surname()));
    age_edit->setText(QString::number(this->get_age()));
    gender_edit->setText(QString::fromStdString(this->print_gender()));

    email_label->setVisible(false);
    email_edit->setVisible(false);

    phone_label->setVisible(false);
    phone_edit->setVisible(false);
}

std::string Student::get_info() const{
    return this->get_name();
}

void Student::set_currentID(int &new_current_studentId){
    Student::current_studentId = new_current_studentId;
}
