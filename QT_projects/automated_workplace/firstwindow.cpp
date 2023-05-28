#include "firstwindow.h"
#include "ui_firstwindow.h"
#include "centralwindow.h"
#include <windows.h>
#include <shellapi.h>

FirstWindow::FirstWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FirstWindow)
{
    ui->setupUi(this);
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
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    this->setFixedSize(1080,760);
    ui->comboBox->addItem("Тип");
    ui->comboBox->addItem("Марка");
    ui->comboBox->addItem("Модель");
}

FirstWindow::~FirstWindow()
{
    delete ui;
}


void FirstWindow::on_pushButton_clicked()
{
    close();
    CentralWindow *window = new CentralWindow(this);
    window->show();
}


void FirstWindow::on_pushButton_2_clicked()
{
    model->insertRow(model->rowCount());
}


void FirstWindow::on_pushButton_3_clicked()
{
    model->removeRow(row);
}


void FirstWindow::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
    column = index.column();
}


void FirstWindow::on_pushButton_4_clicked()
{
    QModelIndex ind = model->index(row, column, QModelIndex());
    link = model->data(ind, Qt::DisplayRole);
    l = link.toString();
    if (l!="")
    {
    ShellExecuteA(NULL, "open", l.toUtf8(), NULL, NULL, SW_SHOWNORMAL);
    }
}


void FirstWindow::on_pushButton_5_clicked() //поиск в бд
{
    if(ui->lineEdit->text()!=""){
        QString cur = ui->comboBox->currentText();
        if(cur=="Тип"){
            model->setQuery(QString("SELECT * FROM Bikes WHERE Тип='%1'").arg(ui->lineEdit->text()));}
        if(cur=="Марка"){
            model->setQuery(QString("SELECT * FROM Bikes WHERE Марка='%1'").arg(ui->lineEdit->text()));}
        if(cur=="Модель"){
            model->setQuery(QString("SELECT * FROM Bikes WHERE Модель='%1'").arg(ui->lineEdit->text()));}
    }
    else{
        model->setQuery(QString("SELECT * FROM Bikes").arg(ui->lineEdit->text()));
        ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
        ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
        ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
        ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    }
}

void FirstWindow::on_pushButton_6_clicked() // Объединение одинаковых строк в бд
{
    int n=sizeb();
    for (int j=0; j<n-1; j++){
    QModelIndex ind = model->index(j, 2, QModelIndex());
    QVariant data = model->data(ind, Qt::DisplayRole);
    QString d = data.toString();
    QModelIndex ind2 = model->index(j, 4, QModelIndex());
    QVariant data2 = model->data(ind2, Qt::DisplayRole);
    int kol1 = data2.toInt();
    for (int i=0; i<n-1; i++){
        if (i==j) break;
        QModelIndex ind = model->index(i, 2, QModelIndex());
        QVariant data = model->data(ind, Qt::DisplayRole);
        QString d2 = data.toString();
        if (d==d2){
            QModelIndex ind = model->index(i, 4, QModelIndex());
            QVariant data = model->data(ind, Qt::DisplayRole);
            int kol2 = data.toInt();
            int kol=kol1+kol2;
            model->removeRow(j);
            query->exec(QString("UPDATE Bikes SET Количество = %0 WHERE Модель = '%1';").arg(kol).arg(d2));
        }
    }
    }

}

int FirstWindow::sizeb(){ // Размер базы данных
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
