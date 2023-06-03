/********************************************************************************
** Form generated from reading UI file 'solution.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOLUTION_H
#define UI_SOLUTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_solution
{
public:
    QGridLayout *gridLayout;
    QPushButton *saveSolutionButton;
    QLabel *label;
    QLabel *answerLable;
    QPushButton *closeButton;
    QTextBrowser *solutionBrowser;

    void setupUi(QDialog *solution)
    {
        if (solution->objectName().isEmpty())
            solution->setObjectName("solution");
        solution->resize(700, 627);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(solution->sizePolicy().hasHeightForWidth());
        solution->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(solution);
        gridLayout->setObjectName("gridLayout");
        saveSolutionButton = new QPushButton(solution);
        saveSolutionButton->setObjectName("saveSolutionButton");
        saveSolutionButton->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setPointSize(10);
        saveSolutionButton->setFont(font);
        saveSolutionButton->setStyleSheet(QString::fromUtf8("QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgba(60, 186, 162, 255), stop:1 rgba(98, 211, 162, 255))\n"
"}\n"
"QPushButton {\n"
"     background-color: #3cbaa2; border: 2px solid black;\n"
"     border-radius: 5px;\n"
"}\n"
""));

        gridLayout->addWidget(saveSolutionButton, 4, 0, 1, 1);

        label = new QLabel(solution);
        label->setObjectName("label");
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);

        gridLayout->addWidget(label, 2, 0, 1, 2);

        answerLable = new QLabel(solution);
        answerLable->setObjectName("answerLable");
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(answerLable->sizePolicy().hasHeightForWidth());
        answerLable->setSizePolicy(sizePolicy1);
        answerLable->setMaximumSize(QSize(100000, 1000000));
        QFont font2;
        font2.setPointSize(12);
        answerLable->setFont(font2);
        answerLable->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(answerLable, 0, 0, 1, 2);

        closeButton = new QPushButton(solution);
        closeButton->setObjectName("closeButton");
        closeButton->setMinimumSize(QSize(0, 30));
        closeButton->setFont(font);
        closeButton->setStyleSheet(QString::fromUtf8("QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgba(60, 186, 162, 255), stop:1 rgba(98, 211, 162, 255))\n"
"}\n"
"QPushButton {\n"
"     background-color: #3cbaa2; border: 2px solid black;\n"
"     border-radius: 5px;\n"
"}\n"
""));

        gridLayout->addWidget(closeButton, 4, 1, 1, 1);

        solutionBrowser = new QTextBrowser(solution);
        solutionBrowser->setObjectName("solutionBrowser");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Consolas")});
        font3.setPointSize(10);
        solutionBrowser->setFont(font3);
        solutionBrowser->setStyleSheet(QString::fromUtf8("QTextBrowser{\n"
"	border: 2px solid black;\n"
"     border-radius: 5px;\n"
"}"));

        gridLayout->addWidget(solutionBrowser, 3, 0, 1, 2);


        retranslateUi(solution);

        QMetaObject::connectSlotsByName(solution);
    } // setupUi

    void retranslateUi(QDialog *solution)
    {
        solution->setWindowTitle(QCoreApplication::translate("solution", "\320\236\321\202\320\262\320\265\321\202", nullptr));
        saveSolutionButton->setText(QCoreApplication::translate("solution", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\200\320\265\321\210\320\265\320\275\320\270\320\265", nullptr));
        label->setText(QCoreApplication::translate("solution", "\320\240\320\265\321\210\320\265\320\275\320\270\320\265:", nullptr));
        answerLable->setText(QCoreApplication::translate("solution", "\320\236\321\202\320\262\320\265\321\202:", nullptr));
        closeButton->setText(QCoreApplication::translate("solution", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class solution: public Ui_solution {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOLUTION_H
