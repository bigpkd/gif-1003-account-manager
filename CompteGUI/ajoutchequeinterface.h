#ifndef AJOUTCHEQUEINTERFACE_H
#define AJOUTCHEQUEINTERFACE_H

#include <QtGui/QDialog>
#include "ui_ajoutchequeinterface.h"
#include "Date.h"

class AjoutChequeInterface : public QDialog
{
    Q_OBJECT

public:
	AjoutChequeInterface(QWidget *parent = 0);
    ~AjoutChequeInterface();
//    int reqNoCompte() const;
//    QString reqDescription() const;
//    double reqSolde() const;
//    double reqTauxInteret() const;
//    double reqTauxInteretMinimum() const;
//    int reqTransactions() const;

    QString reqNoCompte() const;
    QString reqDescription() const;
    QString reqSolde() const;
    QString reqTauxInteret() const;
    QString reqTauxInteretMinimum() const;
    QString reqTransactions() const;

public slots:
	void valideEnregistrement();

private:
    Ui::AjoutChequeInterfaceClass ui;
    util::Date m_dateOuverture;
};

#endif // AJOUTCHEQUE_H
