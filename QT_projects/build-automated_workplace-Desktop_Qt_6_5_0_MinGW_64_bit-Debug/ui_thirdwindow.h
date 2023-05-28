/********************************************************************************
** Form generated from reading UI file 'thirdwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THIRDWINDOW_H
#define UI_THIRDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_ThirdWindow
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_4;
    QTableView *tableView;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *ThirdWindow)
    {
        if (ThirdWindow->objectName().isEmpty())
            ThirdWindow->setObjectName("ThirdWindow");
        ThirdWindow->resize(614, 502);
        gridLayout = new QGridLayout(ThirdWindow);
        gridLayout->setObjectName("gridLayout");
        pushButton_4 = new QPushButton(ThirdWindow);
        pushButton_4->setObjectName("pushButton_4");

        gridLayout->addWidget(pushButton_4, 0, 1, 1, 1);

        tableView = new QTableView(ThirdWindow);
        tableView->setObjectName("tableView");

        gridLayout->addWidget(tableView, 1, 0, 1, 2);

        pushButton_3 = new QPushButton(ThirdWindow);
        pushButton_3->setObjectName("pushButton_3");

        gridLayout->addWidget(pushButton_3, 2, 1, 1, 1);

        pushButton_2 = new QPushButton(ThirdWindow);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 2, 0, 1, 1);

        lineEdit = new QLineEdit(ThirdWindow);
        lineEdit->setObjectName("lineEdit");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        pushButton = new QPushButton(ThirdWindow);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 4, 0, 1, 2);


        retranslateUi(ThirdWindow);

        QMetaObject::connectSlotsByName(ThirdWindow);
    } // setupUi

    void retranslateUi(QDialog *ThirdWindow)
    {
        ThirdWindow->setWindowTitle(QCoreApplication::translate("ThirdWindow", "customers", nullptr));
        pushButton_4->setText(QCoreApplication::translate("ThirdWindow", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \320\275\320\276\320\274\320\265\321\200\321\203 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ThirdWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ThirdWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton->setText(QCoreApplication::translate("ThirdWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThirdWindow: public Ui_ThirdWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THIRDWINDOW_H
