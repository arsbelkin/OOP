#include "viewdialog.h"
#include "ui_viewdialog.h"
#include "algorithm"

#include "QFont"


viewDialog::viewDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::viewDialog)
{
    ui->setupUi(this);

    this->setFontLW();

    this->setWindowTitle("edit dialog");

    connect(this->ui->listWidget, &QListWidget::itemClicked,
            this, &viewDialog::on_listWidget_itemClicked);
}


viewDialog::~viewDialog()
{
    delete ui;
}


void viewDialog::setFontLW(){
    QFont font;
    font.setFamily("Arial");
    font.setPointSize(16);

    ui->listWidget->setFont(font);
}


void viewDialog::open_dialog(const Group &group){
    this->clear_dialog();

    this->ui->email_label->setVisible(true);
    this->ui->email_edit->setVisible(true);

    this->ui->phone_label->setVisible(true);
    this->ui->phone_edit->setVisible(true);

    this->show();

    this->students = group.get_students();
    this->addStudents();

    this->update();
}


void viewDialog::setStudents(Group &group){
    group.set_students(this->students);
}


void viewDialog::addStudents(){
    for_each(this->students.begin(), this->students.end(),
             [this](const auto &student){
                 ui->listWidget->addItem(QString::fromStdString(student->get_info()));
             });
}


void viewDialog::clear_dialog(){
    this->selectedRow = -1;

    this->ui->listWidget->clear();

    this->clear_fields();
}


void viewDialog::clear_fields(){
    this->ui->id_edit->clear();
    this->ui->name_edit->clear();
    this->ui->surname_edit->clear();
    this->ui->age_edit->clear();
    this->ui->gender_edit->clear();
    this->ui->email_edit->clear();
    this->ui->phone_edit->clear();
}


void viewDialog::on_listWidget_itemClicked(QListWidgetItem *item)
{
    if (!item){
        this->selectedRow = -1;
        return;
    }

    this->selectedRow = ui->listWidget->row(item);
    const auto &student = this->students[this->selectedRow];

    student->fillFields(this);
}


void viewDialog::on_deleteButton_clicked()
{
    if (this->selectedRow < 0)
        return;

    this->students.erase(this->students.begin() + this->selectedRow);

    delete this->ui->listWidget->takeItem(this->selectedRow);

    this->selectedRow = std::min(static_cast<int>(this->students.size())-1, this->selectedRow);

    if (this->selectedRow >= 0){
        this->ui->listWidget->setCurrentRow(this->selectedRow);
        this->on_listWidget_itemClicked(this->ui->listWidget->item(this->selectedRow));
    } else {
        this->clear_fields();
    }
}


void viewDialog::addStudent(std::shared_ptr<Student> newStudent){
    if (newStudent)
        this->students.push_back(newStudent);
}


void viewDialog::on_addButton_clicked()
{
    this->setEnabled(false);

    auto newStudent = this->CD.open_for_new_student();

    if (newStudent){
        this->students.push_back(newStudent);

        this->ui->listWidget->addItem(
                QString::fromStdString(newStudent->get_info())
            );

        this->selectedRow = ui->listWidget->count() - 1;

        this->ui->listWidget->setCurrentRow(this->selectedRow);

        QListWidgetItem* item = this->ui->listWidget->item(this->selectedRow);
        if (item) {
            on_listWidget_itemClicked(item);
        }
    }

    this->setEnabled(true);
}


void viewDialog::on_changeButton_clicked()
{
    if (this->selectedRow < 0)
        return;

    this->setEnabled(false);

    this->students[this->selectedRow] = this->CD.open_for_edit_student(
                                                this->students[this->selectedRow]
                                        );

    QListWidgetItem* item = this->ui->listWidget->item(this->selectedRow);
    if (item) {
        item->setText(
            QString::fromStdString(this->students[this->selectedRow]->get_info())
            );
    }

    this->ui->listWidget->setCurrentRow(this->selectedRow);

    if (item) {
        on_listWidget_itemClicked(item);
    }

    this->setEnabled(true);
    this->activateWindow();
}

