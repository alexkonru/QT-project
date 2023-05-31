/********************************************************************************
** Form generated from reading UI file 'sale.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALE_H
#define UI_SALE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_sale
{
public:
    QGridLayout *gridLayout;
    QLabel *label_5;
    QPushButton *pushButton;
    QLabel *label_3;
    QLabel *image;
    QLineEdit *lineEdit;
    QLabel *label_6;
    QLabel *label_4;
    QPushButton *pushButton_3;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_2;
    QLabel *label_8;
    QComboBox *comboBox;
    QLabel *label_7;
    QLabel *label_10;
    QLabel *label;
    QLabel *label_9;
    QPushButton *pushButton_2;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEdit_3;

    void setupUi(QDialog *sale)
    {
        if (sale->objectName().isEmpty())
            sale->setObjectName("sale");
        sale->resize(840, 726);
        gridLayout = new QGridLayout(sale);
        gridLayout->setObjectName("gridLayout");
        label_5 = new QLabel(sale);
        label_5->setObjectName("label_5");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        pushButton = new QPushButton(sale);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 22, 0, 1, 4);

        label_3 = new QLabel(sale);
        label_3->setObjectName("label_3");
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_3, 15, 0, 1, 4);

        image = new QLabel(sale);
        image->setObjectName("image");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(image->sizePolicy().hasHeightForWidth());
        image->setSizePolicy(sizePolicy1);
        image->setPixmap(QPixmap(QString::fromUtf8("img/sale.png")));

        gridLayout->addWidget(image, 1, 0, 1, 4, Qt::AlignHCenter);

        lineEdit = new QLineEdit(sale);
        lineEdit->setObjectName("lineEdit");
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(lineEdit, 3, 0, 1, 3);

        label_6 = new QLabel(sale);
        label_6->setObjectName("label_6");
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_6, 6, 0, 1, 1);

        label_4 = new QLabel(sale);
        label_4->setObjectName("label_4");
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_4, 12, 0, 1, 4);

        pushButton_3 = new QPushButton(sale);
        pushButton_3->setObjectName("pushButton_3");
        sizePolicy2.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pushButton_3, 21, 0, 1, 4);

        label_2 = new QLabel(sale);
        label_2->setObjectName("label_2");
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_2, 14, 0, 1, 4);

        verticalSpacer = new QSpacerItem(20, 120, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 18, 0, 1, 4);

        pushButton_4 = new QPushButton(sale);
        pushButton_4->setObjectName("pushButton_4");

        gridLayout->addWidget(pushButton_4, 8, 3, 1, 1);

        lineEdit_2 = new QLineEdit(sale);
        lineEdit_2->setObjectName("lineEdit_2");
        sizePolicy2.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(lineEdit_2, 8, 2, 1, 1);

        label_8 = new QLabel(sale);
        label_8->setObjectName("label_8");
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_8, 7, 0, 1, 4);

        comboBox = new QComboBox(sale);
        comboBox->setObjectName("comboBox");

        gridLayout->addWidget(comboBox, 2, 0, 1, 4);

        label_7 = new QLabel(sale);
        label_7->setObjectName("label_7");
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_7, 5, 0, 1, 4);

        label_10 = new QLabel(sale);
        label_10->setObjectName("label_10");

        gridLayout->addWidget(label_10, 17, 0, 1, 4);

        label = new QLabel(sale);
        label->setObjectName("label");
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label, 10, 0, 1, 4);

        label_9 = new QLabel(sale);
        label_9->setObjectName("label_9");

        gridLayout->addWidget(label_9, 16, 0, 1, 4);

        pushButton_2 = new QPushButton(sale);
        pushButton_2->setObjectName("pushButton_2");
        sizePolicy2.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pushButton_2, 3, 3, 1, 1);

        label_11 = new QLabel(sale);
        label_11->setObjectName("label_11");

        gridLayout->addWidget(label_11, 8, 0, 1, 2);

        label_12 = new QLabel(sale);
        label_12->setObjectName("label_12");

        gridLayout->addWidget(label_12, 13, 0, 1, 1);

        lineEdit_3 = new QLineEdit(sale);
        lineEdit_3->setObjectName("lineEdit_3");

        gridLayout->addWidget(lineEdit_3, 13, 1, 1, 1);


        retranslateUi(sale);

        QMetaObject::connectSlotsByName(sale);
    } // setupUi

    void retranslateUi(QDialog *sale)
    {
        sale->setWindowTitle(QCoreApplication::translate("sale", "Dialog", nullptr));
        label_5->setText(QCoreApplication::translate("sale", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">\320\232\320\273\320\270\320\265\320\275\321\202:</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("sale", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        label_3->setText(QCoreApplication::translate("sale", "0 \321\200\321\203\320\261.", nullptr));
        image->setText(QString());
        label_6->setText(QCoreApplication::translate("sale", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">\320\241\320\272\320\270\320\264\320\272\320\260:</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("sale", "-", nullptr));
        pushButton_3->setText(QCoreApplication::translate("sale", "\320\237\321\200\320\276\320\264\320\260\321\202\321\214 \321\202\320\276\320\262\320\260\321\200", nullptr));
        label_2->setText(QCoreApplication::translate("sale", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">\320\246\320\265\320\275\320\260:</span></p></body></html>", nullptr));
        pushButton_4->setText(QCoreApplication::translate("sale", "OK", nullptr));
        label_8->setText(QCoreApplication::translate("sale", "<html><head/><body><p>0 %</p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("sale", "<html><head/><body><p>\320\255\321\202\320\276\320\263\320\276 \320\272\320\273\320\270\320\265\320\275\321\202\320\260 \320\275\320\265\321\202 \320\262 \320\261\320\260\320\267\320\265 \320\264\320\260\320\275\320\275\321\213\321\205!</p></body></html>", nullptr));
        label_10->setText(QCoreApplication::translate("sale", "0 \321\200\321\203\320\261.", nullptr));
        label->setText(QCoreApplication::translate("sale", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">\320\242\320\276\320\262\320\260\321\200:</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("sale", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">\320\230\321\202\320\276\320\263\320\276:</span></p></body></html>", nullptr));
        pushButton_2->setText(QCoreApplication::translate("sale", "\320\237\320\276\320\270\321\201\320\272 \320\272\320\273\320\270\320\265\320\275\321\202\320\260 \320\277\320\276 \320\275\320\276\320\274\320\265\321\200\321\203 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260", nullptr));
        label_11->setText(QCoreApplication::translate("sale", "<html><head/><body><p align=\"right\"><span style=\" font-size:12pt;\">\320\235\320\276\320\274\320\265\321\200 \321\202\320\276\320\262\320\260\321\200\320\260:</span></p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("sale", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276:</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sale: public Ui_sale {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALE_H
