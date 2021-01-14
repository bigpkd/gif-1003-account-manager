#include "ajoutepargneinterface.h"
#include <qmessagebox.h>
#include <sstream>

using namespace std;

AjoutEpargneInterface::AjoutEpargneInterface(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.pushButtonOK, SIGNAL(clicked()), this, SLOT(valideEnregistrement()));

}

AjoutEpargneInterface::~AjoutEpargneInterface()
{

}

QString AjoutEpargneInterface::reqNoCompte() const{
	return ui.lineEditNoCompte->text();
}
QString AjoutEpargneInterface::reqDescription() const{
	return ui.lineEditDescription->text();
}
QString AjoutEpargneInterface::reqSolde() const{
	return ui.lineEditSolde->text();
}
QString AjoutEpargneInterface::reqTauxInteret() const{
	return ui.lineEditTauxInteret->text();
}

void AjoutEpargneInterface::valideEnregistrement(){
	if (ui.lineEditNoCompte->text().isEmpty()){
		QString message("Veuillez entrer un numero de compte non vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if (ui.lineEditTauxInteret->text().isEmpty()){
		QString message("Veuillez entrer un taux d'interet non vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	double tauxInteret = ui.lineEditTauxInteret->text().toDouble();
	if (tauxInteret < 0.1 || tauxInteret > 3.5){
		QString message("Le taux d'interet doit etre compris entre 0.1 et 3.5");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}else{
		accept();
	}
}
