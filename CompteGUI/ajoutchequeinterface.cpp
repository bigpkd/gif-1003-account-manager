#include <ajoutchequeinterface.h>
#include <qmessagebox.h>
#include <sstream>
//#include <stdlib.h>

using namespace std;

AjoutChequeInterface::AjoutChequeInterface(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.pushButtonOK, SIGNAL(clicked()), this, SLOT(valideEnregistrement()));
}

AjoutChequeInterface::~AjoutChequeInterface()
{

}

QString AjoutChequeInterface::reqNoCompte() const{
	return ui.lineEditNoCompte->text();
}
QString AjoutChequeInterface::reqDescription() const{
	return ui.lineEditDescription->text();
}
QString AjoutChequeInterface::reqSolde() const{
	return ui.lineEditSolde->text();
}
QString AjoutChequeInterface::reqTauxInteret() const{
	return ui.lineEditTauxInteret->text();
}
QString AjoutChequeInterface::reqTauxInteretMinimum() const{
	return ui.lineEditTauxInteretMinimum->text();
}
QString AjoutChequeInterface::reqTransactions() const{
	return ui.spinBoxNombreTransactions->text();
}

void AjoutChequeInterface::valideEnregistrement(){
	if (ui.lineEditNoCompte->text().isEmpty()){
		QString message("La section numero de compte ne doit pas etre vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if (ui.lineEditTauxInteret->text().isEmpty()){
		QString message("Veuillez entrer un taux d'interet\t");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if (ui.lineEditSolde->text().isEmpty()){
		QString message("Veuillez entrer un solde");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if (ui.lineEditTauxInteretMinimum->text().isEmpty()){
		QString message("La section taux d'interet minimum ne doit pas etre vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if (ui.lineEditTauxInteret->text().toDouble() < ui.lineEditTauxInteretMinimum->text().toDouble()){
		QString message("Le taux d'interet minimum doit etre inferieur au taux d'interet");
		QMessageBox::information(this, "ERREUR", message);
		return;
	} else {
		accept();
	}
}
