#include <iostream>
#include "groupLeader.h"
#include <vector>

using namespace std;


GroupLeader::GroupLeader() : Student() {};


GroupLeader::GroupLeader(std::istream &is) : Student(is) {
    cout << "email: ";
    getline(cin >> std::ws, this->email);
    cout << "номер телефона: ";
    getline(cin >> std::ws, this->phoneNumber);
}


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
