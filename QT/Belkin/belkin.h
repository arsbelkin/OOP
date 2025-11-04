#ifndef BELKIN_H
#define BELKIN_H

#include <QMainWindow>
#include "group.h"
#include "QPainter"

QT_BEGIN_NAMESPACE
namespace Ui {
class Belkin;
}
QT_END_NAMESPACE

class Belkin : public QMainWindow
{
    Q_OBJECT

public:
    Belkin(QWidget *parent = nullptr);
    ~Belkin();

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void on_pushButton_load_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_del_clicked();

private:
    Ui::Belkin *ui;
    Group group = {"AS-23-05"};
};

#endif // BELKIN_H
