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

    void printTableHead(QPainter *painter, const int &st_point, const int &fn_point);

private slots:
    void on_action_load_triggered();

    void on_action_save_triggered();

    void on_action_clear_triggered();

private:
    Ui::Belkin *ui;
    Group group = {"AS-23-05"};
};

#endif // BELKIN_H
