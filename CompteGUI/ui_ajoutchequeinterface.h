/********************************************************************************
** Form generated from reading UI file 'ajoutchequeinterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTCHEQUEINTERFACE_H
#define UI_AJOUTCHEQUEINTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AjoutChequeInterfaceClass
{
public:
    QPushButton *pushButtonOK;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEditNoCompte;
    QLineEdit *lineEditTauxInteret;
    QLineEdit *lineEditSolde;
    QSpinBox *spinBoxNombreTransactions;
    QLineEdit *lineEditTauxInteretMinimum;
    QLineEdit *lineEditDescription;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelNoCompte;
    QLabel *labelTauxInteret;
    QLabel *labelSolde;
    QLabel *labelNombreTransactions;
    QLabel *labelTauxInteretMinimum;
    QLabel *labelDescription;

    void setupUi(QDialog *AjoutChequeInterfaceClass)
    {
        if (AjoutChequeInterfaceClass->objectName().isEmpty())
            AjoutChequeInterfaceClass->setObjectName(QString::fromUtf8("AjoutChequeInterfaceClass"));
        AjoutChequeInterfaceClass->resize(372, 341);
        pushButtonOK = new QPushButton(AjoutChequeInterfaceClass);
        pushButtonOK->setObjectName(QString::fromUtf8("pushButtonOK"));
        pushButtonOK->setGeometry(QRect(110, 280, 141, 41));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        pushButtonOK->setFont(font);
        layoutWidget = new QWidget(AjoutChequeInterfaceClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(180, 30, 171, 241));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEditNoCompte = new QLineEdit(layoutWidget);
        lineEditNoCompte->setObjectName(QString::fromUtf8("lineEditNoCompte"));

        verticalLayout->addWidget(lineEditNoCompte);

        lineEditTauxInteret = new QLineEdit(layoutWidget);
        lineEditTauxInteret->setObjectName(QString::fromUtf8("lineEditTauxInteret"));

        verticalLayout->addWidget(lineEditTauxInteret);

        lineEditSolde = new QLineEdit(layoutWidget);
        lineEditSolde->setObjectName(QString::fromUtf8("lineEditSolde"));

        verticalLayout->addWidget(lineEditSolde);

        spinBoxNombreTransactions = new QSpinBox(layoutWidget);
        spinBoxNombreTransactions->setObjectName(QString::fromUtf8("spinBoxNombreTransactions"));

        verticalLayout->addWidget(spinBoxNombreTransactions);

        lineEditTauxInteretMinimum = new QLineEdit(layoutWidget);
        lineEditTauxInteretMinimum->setObjectName(QString::fromUtf8("lineEditTauxInteretMinimum"));

        verticalLayout->addWidget(lineEditTauxInteretMinimum);

        lineEditDescription = new QLineEdit(layoutWidget);
        lineEditDescription->setObjectName(QString::fromUtf8("lineEditDescription"));

        verticalLayout->addWidget(lineEditDescription);

        layoutWidget1 = new QWidget(AjoutChequeInterfaceClass);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(28, 30, 144, 231));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelNoCompte = new QLabel(layoutWidget1);
        labelNoCompte->setObjectName(QString::fromUtf8("labelNoCompte"));

        verticalLayout_2->addWidget(labelNoCompte);

        labelTauxInteret = new QLabel(layoutWidget1);
        labelTauxInteret->setObjectName(QString::fromUtf8("labelTauxInteret"));

        verticalLayout_2->addWidget(labelTauxInteret);

        labelSolde = new QLabel(layoutWidget1);
        labelSolde->setObjectName(QString::fromUtf8("labelSolde"));

        verticalLayout_2->addWidget(labelSolde);

        labelNombreTransactions = new QLabel(layoutWidget1);
        labelNombreTransactions->setObjectName(QString::fromUtf8("labelNombreTransactions"));

        verticalLayout_2->addWidget(labelNombreTransactions);

        labelTauxInteretMinimum = new QLabel(layoutWidget1);
        labelTauxInteretMinimum->setObjectName(QString::fromUtf8("labelTauxInteretMinimum"));

        verticalLayout_2->addWidget(labelTauxInteretMinimum);

        labelDescription = new QLabel(layoutWidget1);
        labelDescription->setObjectName(QString::fromUtf8("labelDescription"));

        verticalLayout_2->addWidget(labelDescription);


        retranslateUi(AjoutChequeInterfaceClass);

        QMetaObject::connectSlotsByName(AjoutChequeInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *AjoutChequeInterfaceClass)
    {
        AjoutChequeInterfaceClass->setWindowTitle(QApplication::translate("AjoutChequeInterfaceClass", "Ajout d'un compte Ch\303\250que", 0, QApplication::UnicodeUTF8));
        pushButtonOK->setText(QApplication::translate("AjoutChequeInterfaceClass", "OK", 0, QApplication::UnicodeUTF8));
        lineEditNoCompte->setText(QString());
        labelNoCompte->setText(QApplication::translate("AjoutChequeInterfaceClass", "Num\303\251ro de Compte :", 0, QApplication::UnicodeUTF8));
        labelTauxInteret->setText(QApplication::translate("AjoutChequeInterfaceClass", "Taux d'int\303\251r\303\252t :", 0, QApplication::UnicodeUTF8));
        labelSolde->setText(QApplication::translate("AjoutChequeInterfaceClass", "Solde :", 0, QApplication::UnicodeUTF8));
        labelNombreTransactions->setText(QApplication::translate("AjoutChequeInterfaceClass", "Nombre de transactions :", 0, QApplication::UnicodeUTF8));
        labelTauxInteretMinimum->setText(QApplication::translate("AjoutChequeInterfaceClass", "Taux d'int\303\251r\303\252t minimum :", 0, QApplication::UnicodeUTF8));
        labelDescription->setText(QApplication::translate("AjoutChequeInterfaceClass", "Description :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AjoutChequeInterfaceClass: public Ui_AjoutChequeInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTCHEQUEINTERFACE_H
