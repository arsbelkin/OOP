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
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen(Qt::black, 2);
    painter.setPen(pen);

    double tWidth = (1200 - 220) / 8.;

    painter.drawLine(220, 10, 1200, 10);
    painter.drawLine(220, 70, 1200, 70);

    QFont font("Arial", 14, QFont::Bold);
    painter.setFont(font);

    vector<string> name_map = {"id", "роль", "имя", "фамилия", "возраст", "пол", "email", "телефон"};

    for (int i=0; i<9;++i){
        painter.drawLine(220 + i * tWidth, 10, 220 + i * tWidth, 70);
        painter.drawText(220 + tWidth / 3 + i * tWidth , 45, QString::fromStdString(name_map[i]));
    }
}


void Belkin::on_pushButton_load_clicked()
{
    const string filename = QFileDialog::getOpenFileName(this, "Выберите файл для загрузи", "/Users/arsbelkin/Desktop/РГУ(НИУ) нефти и газа им. Губкина/Пятый семестр/ООП/OOP/OOP/OOP/static", "").toStdString();

    if (this->group.loadStudents(filename)){
        QMessageBox::information(this, "загрузка", "обучающиеся загружены!");
        ui->label_total->setText("Всего: " + QString::number(this->group.get_students().size()));
    } else
        QMessageBox::warning(this, "загрузка", "не удалось открыть файл!");
}


void Belkin::on_pushButton_save_clicked()
{
    const string filename = QFileDialog::getSaveFileName(this, "Выберите файл для загрузи", "/Users/arsbelkin/Desktop/РГУ(НИУ) нефти и газа им. Губкина/Пятый семестр/ООП/OOP/OOP/OOP/static", "").toStdString();

    this->group.saveStudents(filename);
}


void Belkin::on_pushButton_del_clicked()
{
    this->group.deleteAllStudents();

    QMessageBox::information(this, "удаление", "все обучающиеся удалены!");

    ui->label_total->setText("Всего: 0");
}

