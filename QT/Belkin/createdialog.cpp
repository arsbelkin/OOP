#include "createdialog.h"
#include "ui_createdialog.h"

#include "QMessageBox"

CreateDialog::CreateDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateDialog)
{
    ui->setupUi(this);
}


CreateDialog::~CreateDialog()
{
    delete ui;
}


void CreateDialog::on_checkBox_clicked(bool checked)
{
    this->isChecked = checked;

    this->ui->email_label->setVisible(checked);
    this->ui->email_edit->setVisible(checked);

    this->ui->phone_label->setVisible(checked);
    this->ui->phone_edit->setVisible(checked);
}


void CreateDialog::set_student(std::shared_ptr<Student> newStudent){
    this->student = newStudent;
}



std::shared_ptr<Student> CreateDialog::open_for_new_student()
{
    this->resetStudent();
    this->clearFields();

    this->ui->id_edit->setText(QString::number(Student::get_currentID()+1));

    this->exec();

    return (this->saved && this->student) ? this->student : nullptr;
}


void CreateDialog::clearFields()
{
    ui->id_edit->clear();
    ui->name_edit->clear();
    ui->surname_edit->clear();
    ui->age_edit->clear();
    ui->gender_edit->clear();
    ui->email_edit->clear();
    ui->phone_edit->clear();

    ui->checkBox->setChecked(false);
    on_checkBox_clicked(false);
}


std::shared_ptr<Student> CreateDialog::open_for_edit_student(std::shared_ptr<Student> editStudent){
    this->clearFields();

    this->student = editStudent;

    this->student->fillFields(this);

    this->on_checkBox_clicked(this->ui->checkBox->checkState());

    this->exec();

    return this->student;
}


bool CreateDialog::validator(){
    if (this->ui->age_edit->text().toInt() < 0 || this->ui->age_edit->text().toInt() > 150)
        return false;

    if (this->ui->gender_edit->text().toStdString() != "М" &&
            this->ui->gender_edit->text().toStdString() != "Ж")
        return false;

    return true;
}


void CreateDialog::on_saveButton_clicked()
{
    if (!this->validator()){
        QMessageBox::warning(this, "ошибка", "не верные данные!");
        return;
    }

    if (this->isChecked)
        this->student = std::make_shared<GroupLeader>();
    else
        this->student = std::make_shared<Student>();

    this->student->setParams(this);

    this->saved = true;

    this->accept();
}


void CreateDialog::resetStudent()
{
    this->student.reset();
    this->saved = false;
    this->isChecked = false;
}
