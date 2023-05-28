#include "fourthwindow.h"
#include "ui_fourthwindow.h"
#include "centralwindow.h"

FourthWindow::FourthWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FourthWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1080,760);
}

FourthWindow::~FourthWindow()
{
    delete ui;
}

void FourthWindow::on_pushButton_clicked()
{
    close();
    CentralWindow *window = new CentralWindow(this);
    window->show();
}
