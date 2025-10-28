#include "belkin.h"
#include "ui_belkin.h"

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
