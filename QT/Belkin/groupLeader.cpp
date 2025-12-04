#include <iostream>
#include "groupLeader.h"
#include <vector>

#include "viewdialog.h"
#include "ui_viewdialog.h"
#include "createdialog.h"
#include "ui_createdialog.h".h"

using namespace std;


GroupLeader::GroupLeader() : Student() {}


void GroupLeader::draw(QPainter *painter, const int &st_Xpoint, const int &st_Ypoint,
                       const int &rWidth, const int &rHeight) const{

    painter->drawRect(st_Xpoint, st_Ypoint, rWidth, rHeight);
    painter->fillRect(st_Xpoint, st_Ypoint, rWidth, rHeight, QColor(255, 0, 0, 128));
    painter->drawText(st_Xpoint + 20, st_Ypoint + rHeight * 2 / 3,
                      QString::number(this->get_id()));

    painter->drawRect(st_Xpoint + rWidth, st_Ypoint, rWidth, rHeight);
    painter->fillRect(st_Xpoint + rWidth, st_Ypoint, rWidth, rHeight, QColor(255, 0, 0, 128));
    painter->drawText(st_Xpoint + rWidth + 20, st_Ypoint + rHeight * 2 / 3,
                      QString::fromStdString(this->get_className()));

    painter->drawRect(st_Xpoint + 2 * rWidth, st_Ypoint, rWidth, rHeight);
    painter->fillRect(st_Xpoint + 2 * rWidth, st_Ypoint, rWidth, rHeight, QColor(255, 0, 0, 128));
    painter->drawText(st_Xpoint + 2 * rWidth + 20, st_Ypoint + rHeight * 2 / 3,
                      QString::fromStdString(this->get_name()));

    painter->drawRect(st_Xpoint + 3 * rWidth, st_Ypoint, rWidth, rHeight);
    painter->fillRect(st_Xpoint + 3 * rWidth, st_Ypoint, rWidth, rHeight, QColor(255, 0, 0, 128));
    painter->drawText(st_Xpoint + 3 * rWidth + 20, st_Ypoint + rHeight * 2 / 3,
                      QString::fromStdString(this->get_surname()));

    painter->drawRect(st_Xpoint + 4 * rWidth, st_Ypoint, rWidth, rHeight);
    painter->fillRect(st_Xpoint + 4 * rWidth, st_Ypoint, rWidth, rHeight, QColor(255, 0, 0, 128));
    painter->drawText(st_Xpoint + 4 * rWidth + 20, st_Ypoint + rHeight * 2 / 3,
                      QString::number(this->get_age()));

    painter->drawRect(st_Xpoint + 5 * rWidth, st_Ypoint, rWidth, rHeight);
    painter->fillRect(st_Xpoint + 5 * rWidth, st_Ypoint, rWidth, rHeight, QColor(255, 0, 0, 128));
    painter->drawText(st_Xpoint + 5 * rWidth + 20, st_Ypoint + rHeight * 2 / 3,
                      QString::fromStdString(this->print_gender()));

    painter->drawRect(st_Xpoint + 6 * rWidth, st_Ypoint, rWidth, rHeight);
    painter->fillRect(st_Xpoint + 6 * rWidth, st_Ypoint, rWidth, rHeight, QColor(255, 0, 0, 128));
    painter->drawText(st_Xpoint + 6 * rWidth + 20, st_Ypoint + rHeight * 2 / 3,
                      QString::fromStdString(this->email));

    painter->drawRect(st_Xpoint + 7 * rWidth, st_Ypoint, rWidth, rHeight);
    painter->fillRect(st_Xpoint + 7 * rWidth, st_Ypoint, rWidth, rHeight, QColor(255, 0, 0, 128));
    painter->drawText(st_Xpoint + 7 * rWidth + 20, st_Ypoint + rHeight * 2 / 3,
                      QString::fromStdString(this->phoneNumber));
}


void GroupLeader::fillFields(viewDialog *dialog)
{
    Student::fillFields(dialog);

    dialog->ui->email_label->setVisible(true);
    dialog->ui->email_edit->setVisible(true);
    dialog->ui->email_edit->setText(QString::fromStdString(this->get_email()));

    dialog->ui->phone_label->setVisible(true);
    dialog->ui->phone_edit->setVisible(true);
    dialog->ui->phone_edit->setText(QString::fromStdString(this->get_phoneNumber()));
}


void GroupLeader::fillFields(CreateDialog *dialog)
{
    Student::fillFields(dialog);

    dialog->ui->email_label->setVisible(true);
    dialog->ui->email_edit->setVisible(true);
    dialog->ui->email_edit->setText(QString::fromStdString(this->get_email()));

    dialog->ui->phone_label->setVisible(true);
    dialog->ui->phone_edit->setVisible(true);
    dialog->ui->phone_edit->setText(QString::fromStdString(this->get_phoneNumber()));

    dialog->ui->checkBox->setChecked(true);
}


void GroupLeader::setParams(CreateDialog *dialog)
{
    Student::setParams(dialog);

    this->email = dialog->ui->email_edit->text().toStdString();
    this->phoneNumber = dialog->ui->phone_edit->text().toStdString();
}


std::string GroupLeader::get_info() const{
    return this->get_name() + " (староста)";
}
