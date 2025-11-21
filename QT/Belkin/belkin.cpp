#include "belkin.h"
#include "ui_belkin.h"
#include "QMessageBox"
#include "QFileDialog"
#include "string"
#include "QPainter"
#include <vector>
#include "QFont"

using namespace std;


Belkin::Belkin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Belkin)
{
    ui->setupUi(this);
}


Belkin::~Belkin()
{
    delete ui;
}


void Belkin::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen(Qt::black, 2);
    painter.setPen(pen);

    QFont font("Arial", 14, QFont::Bold);
    painter.setFont(font);

    this->printTableHead(&painter, 130, 1170);

    //this->group.showAllStudents(&painter, width(), height());
}


void Belkin::printTableHead(QPainter *painter, const int &st_point, const int &fn_point){
    std::vector<std::string> titles_map = {
        {"id", "роль", "имя", "фамилия", "возраст", "пол", "email", "телефон"}
    };

    size_t i = 0;

    const int tHeight = 30;
    const int tWidth = (fn_point - st_point) / 8.;

    painter->drawLine(st_point, 10, fn_point, 10);
    painter->drawLine(st_point, 10 + tHeight, fn_point, 10 + tHeight);

    std::for_each(titles_map.begin(), titles_map.end(),
                  [&painter, &tWidth, &tHeight, &i, &st_point, &fn_point](const std::string& title) {

                      painter->drawLine(st_point + i * tWidth, 10, st_point + i * tWidth, 10 + tHeight);
                      painter->drawText((st_point + i * tWidth) + 20,
                                       10 + tHeight * 2 / 3,
                                       QString::fromStdString(title));

                      ++i;
                  });

    painter->drawLine(st_point + i * tWidth, 10, st_point + i * tWidth, 10 + tHeight);
}


void Belkin::on_action_load_triggered()
{
    const string filename = QFileDialog::getOpenFileName(this, "Выберите файл для загрузи", "/Users/arsbelkin/Desktop/РГУ(НИУ) нефти и газа им. Губкина/Пятый семестр/ООП/OOP/OOP/OOP/static", "").toStdString();

    if (this->group.loadStudents(filename)){
        QMessageBox::information(this, "загрузка", "обучающиеся загружены!");
        ui->label_total->setText("Всего: " + QString::number(this->group.get_students().size()));
    } else
        QMessageBox::warning(this, "загрузка", "не удалось открыть файл!");
}


void Belkin::on_action_save_triggered()
{
    const string filename = QFileDialog::getSaveFileName(this, "Выберите файл для загрузи", "/Users/arsbelkin/Desktop/РГУ(НИУ) нефти и газа им. Губкина/Пятый семестр/ООП/OOP/OOP/OOP/static", "").toStdString();

    this->group.saveStudents(filename);
}


void Belkin::on_action_clear_triggered()
{
    this->group.deleteAllStudents();

    QMessageBox::information(this, "удаление", "все обучающиеся удалены!");

    ui->label_total->setText("Всего: 0");
}

