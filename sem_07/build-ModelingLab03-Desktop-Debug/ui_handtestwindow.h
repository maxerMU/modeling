/********************************************************************************
** Form generated from reading UI file 'handtestwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANDTESTWINDOW_H
#define UI_HANDTESTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_handTestWindow
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QTableWidget *randomValuesTableWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *doTestButton;
    QLabel *answerLabel;

    void setupUi(QDialog *handTestWindow)
    {
        if (handTestWindow->objectName().isEmpty())
            handTestWindow->setObjectName(QString::fromUtf8("handTestWindow"));
        handTestWindow->resize(501, 409);
        gridLayout = new QGridLayout(handTestWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        randomValuesTableWidget = new QTableWidget(handTestWindow);
        randomValuesTableWidget->setObjectName(QString::fromUtf8("randomValuesTableWidget"));

        horizontalLayout->addWidget(randomValuesTableWidget);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        doTestButton = new QPushButton(handTestWindow);
        doTestButton->setObjectName(QString::fromUtf8("doTestButton"));

        verticalLayout->addWidget(doTestButton);

        answerLabel = new QLabel(handTestWindow);
        answerLabel->setObjectName(QString::fromUtf8("answerLabel"));
        answerLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(answerLabel);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);


        retranslateUi(handTestWindow);

        QMetaObject::connectSlotsByName(handTestWindow);
    } // setupUi

    void retranslateUi(QDialog *handTestWindow)
    {
        handTestWindow->setWindowTitle(QApplication::translate("handTestWindow", "Dialog", nullptr));
        doTestButton->setText(QApplication::translate("handTestWindow", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214 P-value", nullptr));
        answerLabel->setText(QApplication::translate("handTestWindow", "P-value: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class handTestWindow: public Ui_handTestWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANDTESTWINDOW_H
