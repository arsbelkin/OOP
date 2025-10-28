#include "belkin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Belkin w;
    w.setWindowTitle("Belkin AS-23-05");
    w.show();
    return a.exec();
}
