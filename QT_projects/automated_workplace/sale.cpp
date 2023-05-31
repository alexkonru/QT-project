#include "sale.h"
#include "ui_sale.h"
#include "centralwindow.h"
#include "firstwindow.h"
#include "secondwindow.h"
#include "thirdwindow.h"
#include <fstream>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
using namespace std;

sale::sale(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sale)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./customers.db");
    if(db.open())
    {
        qDebug("open");
    }
    else
    {
        qDebug("no open");
    }
    query = new QSqlQuery(db);
    query->exec("SELECT TABLE Customers(ФИО TEXT, Телефон INT, Скидка INT)");
    model = new QSqlTableModel(this, db);
    model->setTable("Customers");
    model->select();
    QPixmap pix(":/img/img/sale.png");
    ui->image->setPixmap(pix.scaled(100, 93, Qt::KeepAspectRatio));
    this->setFixedSize(1080,760);
    ui->comboBox->addItem("Велосипеды");
    ui->comboBox->addItem("Аксессуары");

    ifstream t("t.txt");
    t>>sum_begin;
    t>>sum_end;
    t.close();
}

sale::~sale()
{
    ofstream t1("t.txt");
    t1<<sum_begin<<endl;
    t1<<sum_end<<endl;
    delete ui;
}

void sale::on_pushButton_clicked()
{
    close();
    CentralWindow *window = new CentralWindow(this);
    window->show();
}


void sale::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text()!=""){
        int n  = sizeb(0);
        for (int i=0; i<n-1; i++){
            QModelIndex ind = model->index(i, 1, QModelIndex());
            QVariant data = model->data(ind, Qt::DisplayRole);
            QString d = data.toString();
            if(d==ui->lineEdit->text()){
                ind = model->index(i, 0, QModelIndex());
                data = model->data(ind, Qt::DisplayRole);
                QString d1 = data.toString();
                ind = model->index(i, 2, QModelIndex());
                data = model->data(ind, Qt::DisplayRole);
                QString d2 = data.toString();
                s = data.toInt();
                ui->label_7->setText(d1);
                ui->label_8->setText(d2 + " %");
                break;
            }
            else{
                ui->label_7->setText("Этого клиента нет в базе данных!");
                ui->label_8->setText("0 %");
            }
        }
    }
    else{
        ui->label_7->setText("Этого клиента нет в базе данных!");
        ui->label_8->setText("0 %");
    }
}

int sale::sizeb(int m){ // Размер базы данных
    int k = 0;
    if (m==0){
        for(int i=1; i<1000; i++){
            QModelIndex ind = model->index(i, 0, QModelIndex());
            QVariant data = model->data(ind, Qt::DisplayRole);
            QString d = data.toString();
            k++;
            if(d=="") break;
        }
    }
    if (m==1){
        for(int i=1; i<1000; i++){
            QModelIndex ind = model1->index(i, 0, QModelIndex());
            QVariant data = model1->data(ind, Qt::DisplayRole);
            QString d = data.toString();
            k++;
            if(d=="") break;
        }
    }
    if (m==2){
        for(int i=1; i<1000; i++){
            QModelIndex ind = model2->index(i, 0, QModelIndex());
            QVariant data = model2->data(ind, Qt::DisplayRole);
            QString d = data.toString();
            k++;
            if(d=="") break;
        }
    }
    return k;
}


void sale::on_pushButton_4_clicked()//товар, цена, итог
{
    QString cur = ui->comboBox->currentText();
    if (cur=="Велосипеды"){
        if(ui->lineEdit_2->text()!=""){
            db1 = QSqlDatabase::addDatabase("QSQLITE");
            db1.setDatabaseName("./bikes.db");
            if(db1.open())
            {
                qDebug("open");
            }
            else
            {
                qDebug("no open");
            }
            query1 = new QSqlQuery(db1);
            query1->exec("SELECT TABLE Bikes(Тип TEXT, Марка TEXT, Модель TEXT, Ссылка TEXT, Количество INT, Цена INT)");
            model1 = new QSqlTableModel(this, db1);
            model1->setTable("Bikes");
            model1->select();

            int n  = sizeb(1);
            int number = ui->lineEdit_2->text().toInt();
            QModelIndex ind = model1->index(number - 1, 4, QModelIndex());
            QVariant data = model1->data(ind, Qt::DisplayRole);
            kol = data.toInt();
            if(number<=n && kol>0){
                list = cur;
                ind = model1->index(number - 1, 1, QModelIndex());
                data = model1->data(ind, Qt::DisplayRole);
                QString d1 = data.toString();
                ind = model1->index(number - 1, 2, QModelIndex());
                data = model1->data(ind, Qt::DisplayRole);
                QString d2 = data.toString();
                line_t = d2;
                ind = model1->index(number - 1, 5, QModelIndex());
                data = model1->data(ind, Qt::DisplayRole);
                int d3_ = data.toInt();
                sum_begin += d3_ * ui->lineEdit_3->text().toInt();
                d3_ = d3_ * 1.1 * ui->lineEdit_3->text().toInt();
                QString d3 = QString::number(d3_);
                ui->label_4->setText(d1 + " " + d2);
                ui->label_3->setText(d3 + "руб.");
                if (s>0) {itog = d3_ * (s/100);}
                else {itog = data.toInt();}
                sum_end += itog;
                QString i = QString::number(itog);
                ui->label_10->setText(i + " руб.");
                db1.close();
            }
        }
        else{
            ui->label_4->setText("-");
            ui->label_3->setText("0 руб.");
            ui->label_10->setText("0 руб.");
        }
    }
    if (cur=="Аксессуары"){
        if(ui->lineEdit_2->text()!=""){
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

            int n  = sizeb(2);
            int number = ui->lineEdit_2->text().toInt();
            QModelIndex ind = model1->index(number - 1, 2, QModelIndex());
            QVariant data = model1->data(ind, Qt::DisplayRole);
            kol = data.toInt();
            if(number<=n && kol>0){
                list = cur;
                ind = model2->index(number - 1, 0, QModelIndex());
                data = model2->data(ind, Qt::DisplayRole);
                QString d1 = data.toString();
                line_t = d1;
                ind = model2->index(number - 1, 1, QModelIndex());
                data = model2->data(ind, Qt::DisplayRole);
                QString d2 = data.toString();
                ind = model2->index(number - 1, 3, QModelIndex());
                data = model2->data(ind, Qt::DisplayRole);
                int d3_ = data.toInt();
                sum_begin += d3_ * ui->lineEdit_3->text().toInt();
                d3_ = d3_ * 1.1 * ui->lineEdit_3->text().toInt();
                QString d3 = QString::number(d3_);
                ui->label_4->setText(d1 + " " + d2);
                ui->label_3->setText(d3 + "руб.");
                if (s>0) {itog = d3_ * (s/100);}
                else {itog = data.toInt();}
                QString i = QString::number(itog);
                ui->label_10->setText(i + " руб.");
                db2.close();
            }
            else{
                ui->label_4->setText("-");
                ui->label_3->setText("0 руб.");
                ui->label_10->setText("0 руб.");
            }
        }
    }
}


void sale::on_pushButton_3_clicked()//продажа товара, уменьшение количества товаров
{
    if(list=="Велосипеды"){
        db1 = QSqlDatabase::addDatabase("QSQLITE");
        db1.setDatabaseName("./bikes.db");
        if(db1.open())
        {
            qDebug("open");
        }
        else
        {
            qDebug("no open");
        }
        query1 = new QSqlQuery(db1);
        query1->exec("SELECT TABLE Bikes(Тип TEXT, Марка TEXT, Модель TEXT, Ссылка TEXT, Количество INT, Цена INT)");
        query1->exec(QString("UPDATE Bikes SET Количество = %0 WHERE Модель = '%1';").arg(kol-ui->lineEdit_3->text().toInt()).arg(line_t));
    }
    if(list=="Аксессуары"){
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
        query2->exec(QString("UPDATE Accessories SET Количество = %0 WHERE Наименование = '%1';").arg(kol-ui->lineEdit_3->text().toInt()).arg(line_t));
    }
    ui->label_7->setText("Этого клиента нет в базе данных!");
    ui->label_8->setText("0 %");
    ui->label_4->setText("-");
    ui->label_3->setText("0 руб.");
    ui->label_10->setText("0 руб.");
}

