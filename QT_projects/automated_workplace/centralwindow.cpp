#include "centralwindow.h"
#include "ui_centralwindow.h"
#include "mainwindow.h"

CentralWindow::CentralWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CentralWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1080,760);
}

CentralWindow::~CentralWindow()
{
    delete ui;
}

void CentralWindow::on_button1_clicked()
{
    close();
    if (!f1){
    window1 = new FirstWindow(this);
    window1->show();
    f1=true;
    }
}


void CentralWindow::on_button2_clicked()
{
    close();
    if (!f2){
    window2 = new SecondWindow(this);
    window2->show();
    f2=true;
    }
}


void CentralWindow::on_button3_clicked()
{
    close();
    if (!f3){
    window3 = new ThirdWindow(this);
    window3->show();
    f3=true;
    }
}


void CentralWindow::on_pushButton_clicked()
{
    close();
    if (!f4){
    MainWindow *window4 = new MainWindow(this);
    window4->show();
    f4 = true;
    }
}


void CentralWindow::on_pushButton_2_clicked()
{
    close();
    if (!f5){
    window5 = new FourthWindow(this);
    window5->show();
    f5=true;
    }
}

