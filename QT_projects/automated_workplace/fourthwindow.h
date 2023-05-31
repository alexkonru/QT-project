#ifndef FOURTHWINDOW_H
#define FOURTHWINDOW_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDebug>

namespace Ui {
class FourthWindow;
}

class FourthWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FourthWindow(QWidget *parent = nullptr);
    ~FourthWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::FourthWindow *ui;
    QSqlDatabase db, db2;
    QSqlQuery *query, *query2;
    QSqlTableModel *model, *model2;
    int sizeb();
    int sum_begin;
    int sum_end;
    int sum_all_out = 0;
    int sum_all_in = 0;
};

#endif // FOURTHWINDOW_H
