/********************************************************************************
** Form generated from reading UI file 'firstwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRSTWINDOW_H
#define UI_FIRSTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_FirstWindow
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit;
    QTableView *tableView;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QComboBox *comboBox;
    QPushButton *pushButton_6;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;

    void setupUi(QDialog *FirstWindow)
    {
        if (FirstWindow->objectName().isEmpty())
            FirstWindow->setObjectName("FirstWindow");
        FirstWindow->resize(609, 516);
        gridLayout = new QGridLayout(FirstWindow);
        gridLayout->setObjectName("gridLayout");
        pushButton_5 = new QPushButton(FirstWindow);
        pushButton_5->setObjectName("pushButton_5");

        gridLayout->addWidget(pushButton_5, 0, 4, 1, 1);

        lineEdit = new QLineEdit(FirstWindow);
        lineEdit->setObjectName("lineEdit");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        gridLayout->addWidget(lineEdit, 0, 3, 1, 1);

        tableView = new QTableView(FirstWindow);
        tableView->setObjectName("tableView");

        gridLayout->addWidget(tableView, 2, 2, 1, 3);

        pushButton = new QPushButton(FirstWindow);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 6, 2, 1, 3);

        pushButton_3 = new QPushButton(FirstWindow);
        pushButton_3->setObjectName("pushButton_3");

        gridLayout->addWidget(pushButton_3, 4, 2, 1, 1);

        comboBox = new QComboBox(FirstWindow);
        comboBox->setObjectName("comboBox");

        gridLayout->addWidget(comboBox, 0, 2, 1, 1);

        pushButton_6 = new QPushButton(FirstWindow);
        pushButton_6->setObjectName("pushButton_6");

        gridLayout->addWidget(pushButton_6, 3, 2, 1, 2);

        pushButton_4 = new QPushButton(FirstWindow);
        pushButton_4->setObjectName("pushButton_4");

        gridLayout->addWidget(pushButton_4, 3, 4, 1, 1);

        pushButton_2 = new QPushButton(FirstWindow);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 4, 3, 1, 2);


        retranslateUi(FirstWindow);

        QMetaObject::connectSlotsByName(FirstWindow);
    } // setupUi

    void retranslateUi(QDialog *FirstWindow)
    {
        FirstWindow->setWindowTitle(QCoreApplication::translate("FirstWindow", "bikes", nullptr));
        pushButton_5->setText(QCoreApplication::translate("FirstWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        pushButton->setText(QCoreApplication::translate("FirstWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        pushButton_3->setText(QCoreApplication::translate("FirstWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushButton_6->setText(QCoreApplication::translate("FirstWindow", "\320\236\320\261\321\212\320\265\320\264\320\270\320\275\320\270\321\202\321\214 \321\202\320\276\320\262\320\260\321\200\321\213", nullptr));
        pushButton_4->setText(QCoreApplication::translate("FirstWindow", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\272 \321\202\320\276\320\262\320\260\321\200\321\203", nullptr));
        pushButton_2->setText(QCoreApplication::translate("FirstWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FirstWindow: public Ui_FirstWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRSTWINDOW_H
