#ifndef BELKIN_H
#define BELKIN_H

#include <QMainWindow>

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

private:
    Ui::Belkin *ui;
};
#endif // BELKIN_H
