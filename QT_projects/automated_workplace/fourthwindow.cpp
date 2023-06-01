#include "fourthwindow.h"
#include "ui_fourthwindow.h"
#include "centralwindow.h"
#include <fstream>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
using namespace std;

FourthWindow::FourthWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FourthWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1080,760);

    ifstream t("t.txt");
    t>>sum_begin;
    t>>sum_end;
    t.close();

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./bikes.db");
    if(db.open())
    {
        qDebug("open");
    }
    else
    {
        qDebug("no open");
    }
    query = new QSqlQuery(db);
    query->exec("CREATE TABLE Bikes(Тип TEXT, Марка TEXT, Модель TEXT, Ссылка TEXT, Количество INT, Цена INT)");
    model = new QSqlTableModel(this, db);
    model->setTable("Bikes");
    model->select();
    int n = sizeb();
    for (int i=0; i<n-1; i++){
        QModelIndex ind = model->index(i, 5, QModelIndex());
        QVariant data = model->data(ind, Qt::DisplayRole);
        int d1 = data.toInt();
        ind = model->index(i, 4, QModelIndex());
        data = model->data(ind, Qt::DisplayRole);
        int d2 = data.toInt();
        sum_all_out += (d1 * d2);
    }
    db.close();

    db2 = QSqlDatabase::addDatabase("QSQLITE");
    db2.setDatabaseName("./accessories.db");
    if(db2.open())
    {
        qDebug("open");
    }
    else
    {
        qDebug("no open");
    }
    query2 = new QSqlQuery(db2);
    query2->exec("SELECT TABLE Accessories(Наименование TEXT, Модель TEXT, Количество INT, Цена INT)");
    model2 = new QSqlTableModel(this, db2);
    model2->setTable("Accessories");
    model2->select();
    n = sizeb();
    for (int i=0; i<n-1; i++){
        QModelIndex ind = model->index(i, 3, QModelIndex());
        QVariant data = model->data(ind, Qt::DisplayRole);
        int d1 = data.toInt();
        ind = model->index(i, 3, QModelIndex());
        data = model->data(ind, Qt::DisplayRole);
        int d2 = data.toInt();
        sum_all_out += (d1 * d2);
    }
    QString cur = QString::number(sum_all_out);
    ui->label_4->setText(cur + " руб.");
    db2.close();

    cur = QString::number((int)((sum_end - sum_begin)*0.05));
    ui->label_8->setText(cur + " руб.");

    cur = QString::number(sum_end);
    ui->label_5->setText(cur + " руб.");

    int v = (int)((sum_end - sum_begin)*0.95);
    cur = QString::number(v);
    ui->label_6->setText(cur + " руб.");

    cur = QString::number(sum_end - sum_all_out);
    ui->label_10->setText(cur + " руб.");
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

int FourthWindow::sizeb(){ // Размер базы данных
    int k = 0;
    for(int i=1; i<1000; i++){
        QModelIndex ind = model->index(i, 0, QModelIndex());
        QVariant data = model->data(ind, Qt::DisplayRole);
        QString d = data.toString();
        k++;
        if(d=="") break;
    }
    return k;
}
