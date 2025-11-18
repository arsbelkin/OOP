#include <iostream>
#include <fstream>
#include "group.h"
#include <algorithm>
#include <QFontMetrics>

using namespace std;


Group::Group(const std::string &title){
    this->title = title;
}


std::string Group::get_title() const{
    return this->title;
}


std::vector<std::shared_ptr<Student>> Group::get_students() const{
    return this->students;
}

void Group::showAllStudents(QPainter *painter, double wdth, double hgth) const{
    double tHeight = hgth * 0.08;
    int k = 0;


    std::vector<std::vector<std::string>> allData = this->getData();

    std::vector<double> dWdth = calcWidth(allData, painter);
    double sum = std::accumulate(dWdth.begin(), dWdth.end(), 0.0);


    auto drawFunc = std::bind(&Group::draw,
                              this,
                              painter,
                              std::placeholders::_1,
                              dWdth,
                              std::ref(sum),
                              wdth,
                              tHeight,
                              std::ref(k));

    for_each(allData.begin(), allData.end(), drawFunc);
}


void Group::draw(QPainter *painter,
                 std::vector<std::string> &elem,
                 std::vector<double> dWdth,
                 double &sum, double wdth, double tHeight, int &k) const
{
    double tWidth = 220;
    size_t i = 0;

    std::for_each(elem.begin(), elem.end(),
                  [painter, &dWdth, &sum, wdth, tHeight, &k, &tWidth, &i](const std::string& cell) {
                      double dx = (sum > wdth - 250) ? dWdth[i] : (wdth - 250) / 8.;

                      painter->drawLine(220, 10 + tHeight * k, wdth-30, 10 + tHeight * k);
                      painter->drawLine(220, 10 + tHeight * (k + 1), wdth-30, 10 + tHeight * (k + 1));

                      painter->drawLine(tWidth, 10, tWidth, 10 + tHeight * (k + 1));
                      painter->drawText(tWidth + wdth * 0.01,
                                        10 + k * tHeight + tHeight * 2 / 3,
                                        QString::fromStdString(cell));

                      tWidth += dx;
                      ++i;
                  });

    painter->drawLine(tWidth, 10, tWidth, 10 + tHeight * (k + 1));
    ++k;
}


void Group::deleteAllStudents(){
    this->students.clear();
}


bool Group::saveStudents(const string& filename){
    ofstream file(filename);

    if (file.is_open()){
        boost::archive::binary_oarchive ofile(file);
        ofile << this->students;
        return true;
    } else {
        return false;
    }
}


bool Group::loadStudents(const string& filename){
    ifstream file(filename);

    if (file.is_open()){
        boost::archive::binary_iarchive ifile(file);
        ifile >> this->students;
        this->set_current_studentID();
        return true;
    } else {
        return false;
    }
}


void Group::set_current_studentID(){
    int max_id = 0;


    for_each(this->students.begin(), this->students.end(),
             [&max_id](const auto &student){
        max_id = max(max_id, student->get_id());
    });

    Student::set_currentID(max_id);
}


Group::~Group(){
    this->deleteAllStudents();
}


std::vector<std::vector<std::string>> Group::getData() const{
    std::vector<std::vector<std::string>> res = {
        {"id", "роль", "имя", "фамилия", "возраст", "пол", "email", "телефон"}
    };

    for_each(this->students.begin(), this->students.end(),
             [&res](const auto &student) {
                 res.push_back(student->get_info());
    });

    return res;
}


 std::vector<double> Group::calcWidth(std::vector<std::vector<std::string>> &allData, QPainter *painter) const{
    std::vector<double> widths(8, 0.0);
    QFontMetrics metrics(painter->font());

    for (const auto& row : allData) {
        for (size_t i = 0; i < row.size() && i < 8; ++i) {
            QString text = QString::fromStdString(row[i]);
            double textWidth = metrics.horizontalAdvance(text);
            widths[i] = std::max(widths[i], textWidth);
        }
    }

    for (double& width : widths) {
        width += 20.0;
    }

    return widths;
}
