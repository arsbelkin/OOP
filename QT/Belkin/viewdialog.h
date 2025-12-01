#ifndef VIEWDIALOG_H
#define VIEWDIALOG_H

#include <QDialog>
#include <QListWidgetItem>

#include "group.h"


namespace Ui {
class viewDialog;
}

class viewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit viewDialog(QWidget *parent = nullptr);
    ~viewDialog();

    void addStudents();

    void open_dialog(const Group &group);

    void setStudents(Group &group);
private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_deleteButton_clicked();
private:
    Ui::viewDialog *ui;

    int selectedRow = -1;

    std::vector<std::shared_ptr<Student>> students;

    void setFontLW();

    void clear_dialog();
    void clear_fields();
};

#endif // VIEWDIALOG_H
