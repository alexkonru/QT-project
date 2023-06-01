#ifndef SALE_H
#define SALE_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDebug>

namespace Ui {
class sale;
}

class sale : public QDialog
{
    Q_OBJECT

public:
    explicit sale(QWidget *parent = nullptr);
    ~sale();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::sale *ui;
    QSqlDatabase db, db1, db2;
    QSqlQuery *query, *query1, *query2;
    QSqlTableModel *model, *model1, *model2;
    int row;
    int sizeb(int);
    double s = 0;
    int itog;
    int kol;
    int sum_begin;
    int sum_end;
    QString line_t;
    QString list;
};

#endif // SALE_H
