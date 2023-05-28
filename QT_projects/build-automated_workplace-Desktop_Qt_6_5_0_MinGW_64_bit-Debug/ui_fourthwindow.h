/********************************************************************************
** Form generated from reading UI file 'fourthwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOURTHWINDOW_H
#define UI_FOURTHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FourthWindow
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;

    void setupUi(QDialog *FourthWindow)
    {
        if (FourthWindow->objectName().isEmpty())
            FourthWindow->setObjectName("FourthWindow");
        FourthWindow->resize(727, 486);
        verticalLayout = new QVBoxLayout(FourthWindow);
        verticalLayout->setObjectName("verticalLayout");
        pushButton = new QPushButton(FourthWindow);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);


        retranslateUi(FourthWindow);

        QMetaObject::connectSlotsByName(FourthWindow);
    } // setupUi

    void retranslateUi(QDialog *FourthWindow)
    {
        FourthWindow->setWindowTitle(QCoreApplication::translate("FourthWindow", "analytics", nullptr));
        pushButton->setText(QCoreApplication::translate("FourthWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FourthWindow: public Ui_FourthWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOURTHWINDOW_H
