#ifndef CREATEDIALOG_H
#define CREATEDIALOG_H

#include <QDialog>

#include "group.h"


namespace Ui {
class CreateDialog;
}

class CreateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateDialog(QWidget *parent = nullptr);
    ~CreateDialog();

    std::shared_ptr<Student> open_for_new_student();
    std::shared_ptr<Student> open_for_edit_student(std::shared_ptr<Student> newStudent);

    void resetStudent();

    bool validator();

    void clearFields();
private slots:
    void on_checkBox_clicked(bool checked);

    void on_saveButton_clicked();

private:
    Ui::CreateDialog *ui;

    void set_student(std::shared_ptr<Student> newStudent);

    std::shared_ptr<Student> student;

    bool saved = false;

    bool isChecked;

    friend class Student;
    friend class GroupLeader;
};

#endif // CREATEDIALOG_H
