#include "belkin.h"
#include "ui_belkin.h"
#include "QMessageBox"
#include "QFileDialog"
#include "string"

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


void Belkin::on_pushButton_load_clicked()
{
    const string filename = QFileDialog::getOpenFileName(this, "Выберите файл для загрузи", "/Users/arsbelkin/Desktop/РГУ(НИУ) нефти и газа им. Губкина/Пятый семестр/ООП/OOP/OOP/OOP/static", "").toStdString();

    if (this->group.loadStudents(filename))
        QMessageBox::information(this, "загрузка", "обучающиеся загружены!");
    else
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
}

