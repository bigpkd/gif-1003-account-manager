/********************************************************************************
** Form generated from reading UI file 'suppressioncompteinterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRESSIONCOMPTEINTERFACE_H
#define UI_SUPPRESSIONCOMPTEINTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SuppressionCompteInterfaceClass
{
public:
    QPushButton *pushButtonOK;
    QLabel *labelEntrezNoCompte;
    QLineEdit *lineEditNoCompte;

    void setupUi(QDialog *SuppressionCompteInterfaceClass)
    {
        if (SuppressionCompteInterfaceClass->objectName().isEmpty())
            SuppressionCompteInterfaceClass->setObjectName(QString::fromUtf8("SuppressionCompteInterfaceClass"));
        SuppressionCompteInterfaceClass->resize(361, 171);
        pushButtonOK = new QPushButton(SuppressionCompteInterfaceClass);
        pushButtonOK->setObjectName(QString::fromUtf8("pushButtonOK"));
        pushButtonOK->setGeometry(QRect(110, 110, 141, 41));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        pushButtonOK->setFont(font);
        labelEntrezNoCompte = new QLabel(SuppressionCompteInterfaceClass);
        labelEntrezNoCompte->setObjectName(QString::fromUtf8("labelEntrezNoCompte"));
        labelEntrezNoCompte->setGeometry(QRect(40, 10, 291, 41));
        QFont font1;
        font1.setPointSize(11);
        labelEntrezNoCompte->setFont(font1);
        lineEditNoCompte = new QLineEdit(SuppressionCompteInterfaceClass);
        lineEditNoCompte->setObjectName(QString::fromUtf8("lineEditNoCompte"));
        lineEditNoCompte->setGeometry(QRect(100, 60, 161, 41));

        retranslateUi(SuppressionCompteInterfaceClass);

        QMetaObject::connectSlotsByName(SuppressionCompteInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *SuppressionCompteInterfaceClass)
    {
        SuppressionCompteInterfaceClass->setWindowTitle(QApplication::translate("SuppressionCompteInterfaceClass", "Suppression de Compte", 0, QApplication::UnicodeUTF8));
        pushButtonOK->setText(QApplication::translate("SuppressionCompteInterfaceClass", "OK", 0, QApplication::UnicodeUTF8));
        labelEntrezNoCompte->setText(QApplication::translate("SuppressionCompteInterfaceClass", "Entrez le numero du compte a supprimer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SuppressionCompteInterfaceClass: public Ui_SuppressionCompteInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRESSIONCOMPTEINTERFACE_H
