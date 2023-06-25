/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QTableWidget *algResultTableWidget;
    QTableWidget *tableResultTableWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *algPValOneDigit;
    QLabel *algPValTwoDigit;
    QLabel *algPValThreeDigit;
    QLabel *tablePValOneDigit;
    QLabel *tablePValTwoDigit;
    QLabel *tablePValThreeDigit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *infoLabel_1;
    QPushButton *generateButton;
    QLabel *infoLabel_2;
    QPushButton *handTestingButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1007, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        algResultTableWidget = new QTableWidget(centralwidget);
        algResultTableWidget->setObjectName(QString::fromUtf8("algResultTableWidget"));
        algResultTableWidget->setLineWidth(2);

        horizontalLayout->addWidget(algResultTableWidget);

        tableResultTableWidget = new QTableWidget(centralwidget);
        tableResultTableWidget->setObjectName(QString::fromUtf8("tableResultTableWidget"));
        tableResultTableWidget->setLineWidth(2);

        horizontalLayout->addWidget(tableResultTableWidget);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetMinimumSize);
        algPValOneDigit = new QLabel(centralwidget);
        algPValOneDigit->setObjectName(QString::fromUtf8("algPValOneDigit"));

        horizontalLayout_4->addWidget(algPValOneDigit);

        algPValTwoDigit = new QLabel(centralwidget);
        algPValTwoDigit->setObjectName(QString::fromUtf8("algPValTwoDigit"));

        horizontalLayout_4->addWidget(algPValTwoDigit);

        algPValThreeDigit = new QLabel(centralwidget);
        algPValThreeDigit->setObjectName(QString::fromUtf8("algPValThreeDigit"));

        horizontalLayout_4->addWidget(algPValThreeDigit);

        tablePValOneDigit = new QLabel(centralwidget);
        tablePValOneDigit->setObjectName(QString::fromUtf8("tablePValOneDigit"));

        horizontalLayout_4->addWidget(tablePValOneDigit);

        tablePValTwoDigit = new QLabel(centralwidget);
        tablePValTwoDigit->setObjectName(QString::fromUtf8("tablePValTwoDigit"));

        horizontalLayout_4->addWidget(tablePValTwoDigit);

        tablePValThreeDigit = new QLabel(centralwidget);
        tablePValThreeDigit->setObjectName(QString::fromUtf8("tablePValThreeDigit"));

        horizontalLayout_4->addWidget(tablePValThreeDigit);


        gridLayout_2->addLayout(horizontalLayout_4, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        infoLabel_1 = new QLabel(centralwidget);
        infoLabel_1->setObjectName(QString::fromUtf8("infoLabel_1"));

        horizontalLayout_3->addWidget(infoLabel_1);

        generateButton = new QPushButton(centralwidget);
        generateButton->setObjectName(QString::fromUtf8("generateButton"));

        horizontalLayout_3->addWidget(generateButton);

        infoLabel_2 = new QLabel(centralwidget);
        infoLabel_2->setObjectName(QString::fromUtf8("infoLabel_2"));
        infoLabel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(infoLabel_2);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        handTestingButton = new QPushButton(centralwidget);
        handTestingButton->setObjectName(QString::fromUtf8("handTestingButton"));

        gridLayout->addWidget(handTestingButton, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1007, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        algPValOneDigit->setText(QString());
        algPValTwoDigit->setText(QString());
        algPValThreeDigit->setText(QString());
        tablePValOneDigit->setText(QString());
        tablePValTwoDigit->setText(QString());
        tablePValThreeDigit->setText(QString());
        infoLabel_1->setText(QApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \320\274\320\265\321\202\320\276\320\264", nullptr));
        generateButton->setText(QApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\201\320\273\321\203\321\207\320\260\320\271\320\275\321\213\320\265 \321\207\320\270\321\201\320\273\320\260 \320\270 \321\200\320\260\321\201\321\207\320\270\321\202\320\260\321\202\321\214 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\265\320\275\320\275\321\213\320\271 \320\272\321\200\320\270\321\202\320\265\321\200\320\270\320\271 \320\276\321\206\320\265\320\275\320\272\320\270 \321\201\320\273\321\203\321\207\320\260\320\271\320\275\320\276\321\201\321\202\320\270", nullptr));
        infoLabel_2->setText(QApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\207\320\275\321\213\320\271 \320\274\320\265\321\202\320\276\320\264", nullptr));
        handTestingButton->setText(QApplication::translate("MainWindow", "\320\240\321\203\321\207\320\275\320\276\320\265 \321\202\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
