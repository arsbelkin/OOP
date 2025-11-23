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

    this->printTableHead(&painter);

    this->group.showAllStudents(&painter, this->st_Xpoint, this->st_Ypoint,
                                this->tWidth, this->tHeight);
}


void Belkin::printTableHead(QPainter *painter){
    std::vector<std::string> titles_map = {
        {"id", "роль", "имя", "фамилия", "возраст", "пол", "email", "телефон"}
    };

    size_t i = 0;

    painter->drawLine(this->st_Xpoint, this->st_Ypoint,
                      this->fn_Xpoint, this->st_Ypoint);

    painter->drawLine(this->st_Xpoint, this->st_Ypoint + this->tHeight,
                      this->fn_Xpoint, this->st_Ypoint + this->tHeight);

    std::for_each(titles_map.begin(), titles_map.end(),
                  [this, &painter, &i](const std::string& title) {

                      painter->drawLine(this->st_Xpoint + i * this->tWidth, this->st_Ypoint,
                          this->st_Xpoint + i * this->tWidth, this->st_Ypoint + this->tHeight);

                      painter->drawText((this->st_Xpoint + i * this->tWidth) + 20,
                                       this->st_Ypoint + this->tHeight * 2 / 3,
                                       QString::fromStdString(title));

                      ++i;
                  });

    painter->drawLine(this->st_Xpoint + i * this->tWidth, this->st_Ypoint,
                      this->st_Xpoint + i * this->tWidth, this->st_Ypoint + this->tHeight);
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

