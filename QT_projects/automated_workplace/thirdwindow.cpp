#include "thirdwindow.h"
#include "ui_thirdwindow.h"
#include "centralwindow.h"

ThirdWindow::ThirdWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThirdWindow)
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
    query->exec("CREATE TABLE Customers(ФИО TEXT, Телефон INT, Скидка INT)");
    model = new QSqlTableModel(this, db);
    model->setTable("Customers");
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    this->setFixedSize(1080,760);
}

ThirdWindow::~ThirdWindow()
{
    delete ui;
}

void ThirdWindow::on_pushButton_clicked()
{
    close();
    CentralWindow *window = new CentralWindow(this);
    window->show();
}


void ThirdWindow::on_pushButton_2_clicked()
{
    model->insertRow(model->rowCount());
}


void ThirdWindow::on_pushButton_3_clicked()
{
    model->removeRow(row);
}


void ThirdWindow::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}


void ThirdWindow::on_pushButton_4_clicked()
{
    if(ui->lineEdit->text()!=""){
        model->setQuery(QString("SELECT * FROM Customers WHERE Телефон='%1'").arg(ui->lineEdit->text()));
    }
    else{
        model->setQuery(QString("SELECT * FROM Customers").arg(ui->lineEdit->text()));
        ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
        ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    }
}

int ThirdWindow::sizeb(){ // Размер базы данных
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


