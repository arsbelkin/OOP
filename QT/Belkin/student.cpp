#include <iostream>
#include "fstream"
#include "student.h"
#include <string>
#include <vector>

#include "viewdialog.h"
#include "ui_viewdialog.h"
#include "createdialog.h"
#include "ui_createdialog.h".h"

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


void Student::fillFields(viewDialog *dialog)
{
    dialog->ui->id_edit->setText(QString::number(this->get_id()));
    dialog->ui->name_edit->setText(QString::fromStdString(this->get_name()));
    dialog->ui->surname_edit->setText(QString::fromStdString(this->get_surname()));
    dialog->ui->age_edit->setText(QString::number(this->get_age()));
    dialog->ui->gender_edit->setText(QString::fromStdString(this->print_gender()));

    dialog->ui->email_label->setVisible(false);
    dialog->ui->email_edit->setVisible(false);

    dialog->ui->phone_label->setVisible(false);
    dialog->ui->phone_edit->setVisible(false);
}


void Student::fillFields(CreateDialog *dialog)
{
    dialog->ui->id_edit->setText(QString::number(this->get_id()));
    dialog->ui->name_edit->setText(QString::fromStdString(this->get_name()));
    dialog->ui->surname_edit->setText(QString::fromStdString(this->get_surname()));
    dialog->ui->age_edit->setText(QString::number(this->get_age()));
    dialog->ui->gender_edit->setText(QString::fromStdString(this->print_gender()));

    dialog->ui->email_label->setVisible(false);
    dialog->ui->email_edit->setVisible(false);

    dialog->ui->phone_label->setVisible(false);
    dialog->ui->phone_edit->setVisible(false);

    dialog->ui->checkBox->setChecked(false);
}


bool Student::convert_gender(std::string gndr){
    return gndr == "М";
}


void Student::setParams(CreateDialog *dialog)
{
    this->studentId = dialog->ui->id_edit->text().toInt();
    this->name = dialog->ui->name_edit->text().toStdString();
    this->surname = dialog->ui->surname_edit->text().toStdString();
    this->age = dialog->ui->age_edit->text().toInt();
    this->gender = this->convert_gender(dialog->ui->gender_edit->text().toStdString());
}


std::string Student::get_info() const{
    return this->get_name();
}

void Student::set_currentID(const int &new_current_studentId){
    Student::current_studentId = new_current_studentId;
}
