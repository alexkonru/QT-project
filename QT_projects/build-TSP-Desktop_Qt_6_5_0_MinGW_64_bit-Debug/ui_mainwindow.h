/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *save;
    QAction *open;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLineEdit *cityNameLine;
    QLabel *label_2;
    QPushButton *solveButton;
    QPushButton *addRoadButton1;
    QLineEdit *roadLenghthLine1;
    QGraphicsView *graphicsView;
    QPushButton *addRoadButton2;
    QLabel *label_3;
    QPushButton *addCityButton;
    QLabel *label;
    QLineEdit *startingCityLine;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(953, 618);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"background-color:#2D333C\n"
"}"));
        save = new QAction(MainWindow);
        save->setObjectName("save");
        save->setCheckable(false);
        save->setEnabled(true);
        open = new QAction(MainWindow);
        open->setObjectName("open");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        cityNameLine = new QLineEdit(centralwidget);
        cityNameLine->setObjectName("cityNameLine");
        cityNameLine->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border: 2px solid black;\n"
"     border-radius: 5px;\n"
"}"));

        gridLayout->addWidget(cityNameLine, 1, 1, 1, 2);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        QFont font;
        font.setPointSize(10);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("QLable {\n"
"color: white;\n"
"}"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        solveButton = new QPushButton(centralwidget);
        solveButton->setObjectName("solveButton");
        solveButton->setMinimumSize(QSize(0, 30));
        solveButton->setStyleSheet(QString::fromUtf8("QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgba(60, 186, 162, 255), stop:1 rgba(98, 211, 162, 255))\n"
"}\n"
"QPushButton {\n"
"     background-color: #3cbaa2; border: 2px solid black;\n"
"     border-radius: 2px;\n"
"}\n"
""));
        solveButton->setCheckable(false);
        solveButton->setAutoExclusive(true);
        solveButton->setFlat(false);

        gridLayout->addWidget(solveButton, 5, 3, 1, 2);

        addRoadButton1 = new QPushButton(centralwidget);
        addRoadButton1->setObjectName("addRoadButton1");
        addRoadButton1->setMinimumSize(QSize(250, 30));
        addRoadButton1->setStyleSheet(QString::fromUtf8("QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgba(60, 186, 162, 255), stop:1 rgba(98, 211, 162, 255))\n"
"}\n"
"QPushButton {\n"
"     background-color: #3cbaa2; border: 2px solid black;\n"
"     border-radius: 2px;\n"
"}\n"
""));

        gridLayout->addWidget(addRoadButton1, 2, 3, 1, 1);

        roadLenghthLine1 = new QLineEdit(centralwidget);
        roadLenghthLine1->setObjectName("roadLenghthLine1");
        roadLenghthLine1->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border: 2px solid black;\n"
"     border-radius: 5px;\n"
"}"));

        gridLayout->addWidget(roadLenghthLine1, 2, 1, 1, 2);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Consolas")});
        graphicsView->setFont(font1);
        graphicsView->setStyleSheet(QString::fromUtf8("QGraphicsView {\n"
"	border: 2px solid black;\n"
"     border-radius: 5px;\n"
"}"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 5);

        addRoadButton2 = new QPushButton(centralwidget);
        addRoadButton2->setObjectName("addRoadButton2");
        addRoadButton2->setMinimumSize(QSize(250, 30));
        addRoadButton2->setStyleSheet(QString::fromUtf8("QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgba(60, 186, 162, 255), stop:1 rgba(98, 211, 162, 255))\n"
"}\n"
"QPushButton {\n"
"     background-color: #3cbaa2; border: 2px solid black;\n"
"     border-radius: 2px;\n"
"}\n"
""));

        gridLayout->addWidget(addRoadButton2, 2, 4, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("QLable {\n"
"color: white;\n"
"}"));

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        addCityButton = new QPushButton(centralwidget);
        addCityButton->setObjectName("addCityButton");
        addCityButton->setMinimumSize(QSize(0, 30));
        addCityButton->setStyleSheet(QString::fromUtf8("QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgba(60, 186, 162, 255), stop:1 rgba(98, 211, 162, 255))\n"
"}\n"
"QPushButton {\n"
"     background-color: #3cbaa2; border: 2px solid black;\n"
"     border-radius: 2px;\n"
"}\n"
""));

        gridLayout->addWidget(addCityButton, 1, 3, 1, 2);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLable {\n"
"color: white;\n"
"}"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        startingCityLine = new QLineEdit(centralwidget);
        startingCityLine->setObjectName("startingCityLine");
        startingCityLine->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border: 2px solid black;\n"
"     border-radius: 5px;\n"
"}"));

        gridLayout->addWidget(startingCityLine, 5, 1, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 953, 25));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(save);
        menu->addAction(open);

        retranslateUi(MainWindow);

        solveButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "TSP", nullptr));
        save->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        open->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\224\320\273\320\270\320\275\320\260 \320\264\320\276\321\200\320\276\320\263\320\270:", nullptr));
        solveButton->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\321\210\320\270\321\202\321\214", nullptr));
        addRoadButton1->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\276\320\264\320\275\320\276\321\201\321\202\320\276\321\200\320\276\320\275\320\275\321\216\321\216 \320\264\320\276\321\200\320\276\320\263\321\203", nullptr));
        addRoadButton2->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\264\320\262\321\203\321\201\321\202\320\276\321\200\320\276\320\275\320\275\321\216\321\216 \320\264\320\276\321\200\320\276\320\263\321\203", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\321\213\320\271 \320\263\320\276\321\200\320\276\320\264:", nullptr));
        addCityButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\263\320\276\321\200\320\276\320\264", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\263\320\276\321\200\320\276\320\264\320\260:", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
