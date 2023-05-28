#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "centralwindow.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./accessories.db");
    if(db.open())
    {
        qDebug("open");
    }
    else
    {
        qDebug("no open");
    }
    query = new QSqlQuery(db);
    query->exec("CREATE TABLE Accessories(Наименование TEXT, Модель TEXT, Количество INT, Цена INT)");
    model = new QSqlTableModel(this, db);
    model->setTable("Accessories");
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    this->setFixedSize(1080,760);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_pushButton_clicked()
{
    close();
    CentralWindow *window = new CentralWindow(this);
    window->show();
}


void SecondWindow::on_pushButton_2_clicked()
{
    model->insertRow(model->rowCount());
}


void SecondWindow::on_pushButton_3_clicked()
{
    model->removeRow(row);
}


void SecondWindow::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}


void SecondWindow::on_pushButton_4_clicked()
{
    if(ui->lineEdit->text()!=""){
        model->setQuery(QString("SELECT * FROM Accessories WHERE Наименование='%1'").arg(ui->lineEdit->text()));
    }
    else{
        model->setQuery(QString("SELECT * FROM Accessories").arg(ui->lineEdit->text()));
        ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
        ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    }
}

int SecondWindow::sizeb(){ // Размер базы данных
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


void SecondWindow::on_pushButton_5_clicked()
{
    int n=sizeb();
    for (int j=0; j<n-1; j++){
    QModelIndex ind = model->index(j, 0, QModelIndex());
    QVariant data = model->data(ind, Qt::DisplayRole);
    QString d = data.toString();
    QModelIndex ind2 = model->index(j, 2, QModelIndex());
    QVariant data2 = model->data(ind2, Qt::DisplayRole);
    int kol1 = data2.toInt();
    for (int i=0; i<n-1; i++){
        if (i==j) break;
        QModelIndex ind = model->index(i, 0, QModelIndex());
        QVariant data = model->data(ind, Qt::DisplayRole);
        QString d2 = data.toString();
        if (d==d2){
            QModelIndex ind = model->index(i, 2, QModelIndex());
            QVariant data = model->data(ind, Qt::DisplayRole);
            int kol2 = data.toInt();
            int kol=kol1+kol2;
            model->removeRow(j);
            query->exec(QString("UPDATE Accessories SET Количество = %0 WHERE Наименование = '%1';").arg(kol).arg(d2));
        }
    }
    }
}

