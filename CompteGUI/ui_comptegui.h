/********************************************************************************
** Form generated from reading UI file 'comptegui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPTEGUI_H
#define UI_COMPTEGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CompteGUIClass
{
public:
    QAction *actionSuppressionCompte;
    QAction *actionAjoutCheque;
    QAction *actionAjoutEpargne;
    QAction *actionQuitter;
    QWidget *centralwidget;
    QTableWidget *tableWidgetCompte;
    QMenuBar *menubar;
    QMenu *menu_dition;
    QMenu *menuAjouter_Compte;
    QMenu *menuFichier;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CompteGUIClass)
    {
        if (CompteGUIClass->objectName().isEmpty())
            CompteGUIClass->setObjectName(QString::fromUtf8("CompteGUIClass"));
        CompteGUIClass->resize(750, 421);
        actionSuppressionCompte = new QAction(CompteGUIClass);
        actionSuppressionCompte->setObjectName(QString::fromUtf8("actionSuppressionCompte"));
        actionAjoutCheque = new QAction(CompteGUIClass);
        actionAjoutCheque->setObjectName(QString::fromUtf8("actionAjoutCheque"));
        actionAjoutEpargne = new QAction(CompteGUIClass);
        actionAjoutEpargne->setObjectName(QString::fromUtf8("actionAjoutEpargne"));
        actionQuitter = new QAction(CompteGUIClass);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        centralwidget = new QWidget(CompteGUIClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidgetCompte = new QTableWidget(centralwidget);
        if (tableWidgetCompte->columnCount() < 7)
            tableWidgetCompte->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        tableWidgetCompte->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetCompte->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        tableWidgetCompte->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidgetCompte->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetCompte->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetCompte->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetCompte->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidgetCompte->setObjectName(QString::fromUtf8("tableWidgetCompte"));
        tableWidgetCompte->setGeometry(QRect(10, 10, 731, 361));
        CompteGUIClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CompteGUIClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 750, 27));
        menu_dition = new QMenu(menubar);
        menu_dition->setObjectName(QString::fromUtf8("menu_dition"));
        menuAjouter_Compte = new QMenu(menu_dition);
        menuAjouter_Compte->setObjectName(QString::fromUtf8("menuAjouter_Compte"));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        CompteGUIClass->setMenuBar(menubar);
        statusbar = new QStatusBar(CompteGUIClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CompteGUIClass->setStatusBar(statusbar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menu_dition->menuAction());
        menu_dition->addAction(menuAjouter_Compte->menuAction());
        menu_dition->addAction(actionSuppressionCompte);
        menuAjouter_Compte->addAction(actionAjoutCheque);
        menuAjouter_Compte->addAction(actionAjoutEpargne);
        menuFichier->addAction(actionQuitter);

        retranslateUi(CompteGUIClass);
        QObject::connect(actionQuitter, SIGNAL(triggered(bool)), CompteGUIClass, SLOT(close()));

        QMetaObject::connectSlotsByName(CompteGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *CompteGUIClass)
    {
        CompteGUIClass->setWindowTitle(QApplication::translate("CompteGUIClass", "Outil de gestion de comptes", 0, QApplication::UnicodeUTF8));
        actionSuppressionCompte->setText(QApplication::translate("CompteGUIClass", "Supprimer Compte", 0, QApplication::UnicodeUTF8));
        actionAjoutCheque->setText(QApplication::translate("CompteGUIClass", "Ch\303\250que", 0, QApplication::UnicodeUTF8));
        actionAjoutEpargne->setText(QApplication::translate("CompteGUIClass", "\303\211pargne", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("CompteGUIClass", "Quitter", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetCompte->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CompteGUIClass", "Num\303\251ro", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetCompte->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CompteGUIClass", "Type", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetCompte->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("CompteGUIClass", "Description", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetCompte->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("CompteGUIClass", "Solde", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetCompte->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("CompteGUIClass", "Taux d'int\303\251r\303\252t", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetCompte->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("CompteGUIClass", "Taux d'int\303\251r\303\252t minimum", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetCompte->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("CompteGUIClass", "Transactions", 0, QApplication::UnicodeUTF8));
        menu_dition->setTitle(QApplication::translate("CompteGUIClass", "\303\211dition", 0, QApplication::UnicodeUTF8));
        menuAjouter_Compte->setTitle(QApplication::translate("CompteGUIClass", "Ajouter Compte", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("CompteGUIClass", "Fichier", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CompteGUIClass: public Ui_CompteGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPTEGUI_H
