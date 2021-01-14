/********************************************************************************
** Form generated from reading UI file 'ajoutepargneinterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTEPARGNEINTERFACE_H
#define UI_AJOUTEPARGNEINTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AjoutEpargneInterfaceClass
{
public:
    QPushButton *pushButtonOK;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelNoCompte;
    QLabel *labelTauxInteret;
    QLabel *labelSolde;
    QLabel *labelDescription;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEditNoCompte;
    QLineEdit *lineEditTauxInteret;
    QLineEdit *lineEditSolde;
    QLineEdit *lineEditDescription;

    void setupUi(QDialog *AjoutEpargneInterfaceClass)
    {
        if (AjoutEpargneInterfaceClass->objectName().isEmpty())
            AjoutEpargneInterfaceClass->setObjectName(QString::fromUtf8("AjoutEpargneInterfaceClass"));
        AjoutEpargneInterfaceClass->resize(400, 269);
        pushButtonOK = new QPushButton(AjoutEpargneInterfaceClass);
        pushButtonOK->setObjectName(QString::fromUtf8("pushButtonOK"));
        pushButtonOK->setGeometry(QRect(130, 210, 141, 41));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        pushButtonOK->setFont(font);
        layoutWidget = new QWidget(AjoutEpargneInterfaceClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 40, 151, 151));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelNoCompte = new QLabel(layoutWidget);
        labelNoCompte->setObjectName(QString::fromUtf8("labelNoCompte"));

        verticalLayout->addWidget(labelNoCompte);

        labelTauxInteret = new QLabel(layoutWidget);
        labelTauxInteret->setObjectName(QString::fromUtf8("labelTauxInteret"));

        verticalLayout->addWidget(labelTauxInteret);

        labelSolde = new QLabel(layoutWidget);
        labelSolde->setObjectName(QString::fromUtf8("labelSolde"));

        verticalLayout->addWidget(labelSolde);

        labelDescription = new QLabel(layoutWidget);
        labelDescription->setObjectName(QString::fromUtf8("labelDescription"));

        verticalLayout->addWidget(labelDescription);

        layoutWidget1 = new QWidget(AjoutEpargneInterfaceClass);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(190, 40, 191, 151));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEditNoCompte = new QLineEdit(layoutWidget1);
        lineEditNoCompte->setObjectName(QString::fromUtf8("lineEditNoCompte"));

        verticalLayout_2->addWidget(lineEditNoCompte);

        lineEditTauxInteret = new QLineEdit(layoutWidget1);
        lineEditTauxInteret->setObjectName(QString::fromUtf8("lineEditTauxInteret"));

        verticalLayout_2->addWidget(lineEditTauxInteret);

        lineEditSolde = new QLineEdit(layoutWidget1);
        lineEditSolde->setObjectName(QString::fromUtf8("lineEditSolde"));

        verticalLayout_2->addWidget(lineEditSolde);

        lineEditDescription = new QLineEdit(layoutWidget1);
        lineEditDescription->setObjectName(QString::fromUtf8("lineEditDescription"));

        verticalLayout_2->addWidget(lineEditDescription);


        retranslateUi(AjoutEpargneInterfaceClass);

        QMetaObject::connectSlotsByName(AjoutEpargneInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *AjoutEpargneInterfaceClass)
    {
        AjoutEpargneInterfaceClass->setWindowTitle(QApplication::translate("AjoutEpargneInterfaceClass", "Ajoutd'un compte \303\211pargne", 0, QApplication::UnicodeUTF8));
        pushButtonOK->setText(QApplication::translate("AjoutEpargneInterfaceClass", "OK", 0, QApplication::UnicodeUTF8));
        labelNoCompte->setText(QApplication::translate("AjoutEpargneInterfaceClass", "Num\303\251ro de Compte :", 0, QApplication::UnicodeUTF8));
        labelTauxInteret->setText(QApplication::translate("AjoutEpargneInterfaceClass", "Taux d'int\303\251r\303\252t :", 0, QApplication::UnicodeUTF8));
        labelSolde->setText(QApplication::translate("AjoutEpargneInterfaceClass", "Solde :", 0, QApplication::UnicodeUTF8));
        labelDescription->setText(QApplication::translate("AjoutEpargneInterfaceClass", "Description :", 0, QApplication::UnicodeUTF8));
        lineEditNoCompte->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AjoutEpargneInterfaceClass: public Ui_AjoutEpargneInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTEPARGNEINTERFACE_H
