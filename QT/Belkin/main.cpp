#include "belkin.h"
#include <boost/serialization/export.hpp>

#include <QApplication>


BOOST_CLASS_EXPORT_IMPLEMENT(Student)
BOOST_CLASS_EXPORT_IMPLEMENT(GroupLeader)


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Belkin w;
    w.setWindowTitle("Belkin AS-23-05");
    w.show();
    return a.exec();
}
