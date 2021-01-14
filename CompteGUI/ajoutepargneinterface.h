#ifndef AJOUTEPARGNEINTERFACE_H
#define AJOUTEPARGNEINTERFACE_H

#include <QtGui/QDialog>
#include "ui_ajoutepargneinterface.h"
#include "Date.h"

class AjoutEpargneInterface : public QDialog
{
    Q_OBJECT

public:
	AjoutEpargneInterface(QWidget *parent = 0);
    ~AjoutEpargneInterface();
//    int reqNoCompte() const;
//    QString reqDescription() const;
//    double reqSolde() const;
//    double reqTauxInteret() const;

    QString reqNoCompte() const;
    QString reqDescription() const;
    QString reqSolde() const;
    QString reqTauxInteret() const;

public slots:
	void valideEnregistrement();

private:
    Ui::AjoutEpargneInterfaceClass ui;
    util::Date m_dateOuverture;
};

#endif // AJOUTEPARGNEINTERFACE_H
