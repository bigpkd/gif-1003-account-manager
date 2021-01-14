#include "comptegui.h"
#include "ajoutchequeinterface.h"
#include "ajoutepargneinterface.h"
#include "suppressioncompteinterface.h"
#include "CompteException.h"
#include <qmessagebox.h>
#include "Client.h"
#include "Compte.h"
#include "Cheque.h"
#include "Epargne.h"
#include <sstream>
#include <iterator>
#include <string>

using namespace banque;
using namespace std;

CompteGUI::CompteGUI(QWidget *parent)
    : QMainWindow(parent), client(1111, "tony", "shack", "581 111-1111", util::Date(11,11,1977)), numeroDeLigne(0)
{
	ui.setupUi(this);

	ui.tableWidgetCompte->setColumnWidth(0, 75);
	ui.tableWidgetCompte->setColumnWidth(1, 100);
	ui.tableWidgetCompte->setColumnWidth(2, 100);
	ui.tableWidgetCompte->setColumnWidth(3, 100);
	ui.tableWidgetCompte->setColumnWidth(4, 100);
	ui.tableWidgetCompte->setColumnWidth(5, 150);
	ui.tableWidgetCompte->setColumnWidth(6, 100);

	QObject::connect(ui.actionAjoutCheque, SIGNAL(triggered()), this, SLOT(dialogAjoutCheque()));
//
	QObject::connect(ui.actionAjoutEpargne, SIGNAL(triggered()), this, SLOT(dialogAjoutEpargne()));
//
	QObject::connect(ui.actionSuppressionCompte, SIGNAL(triggered()), this, SLOT(dialogSuppressionCompte()));
}

CompteGUI::~CompteGUI()
{
	std::vector<banque::Compte*>::iterator iter;
	for (iter = m_vComptes2.begin(); iter != m_vComptes2.end(); iter++){
		delete *iter;
	}
}

void CompteGUI::dialogAjoutCheque(){
	AjoutChequeInterface saisieCheque(this);
	string description = "Cheque";
	if (saisieCheque.exec()){
		if (!(saisieCheque.reqDescription().isEmpty())){
			description = saisieCheque.reqDescription().toStdString();
		}
		ajoutCheque(saisieCheque.reqNoCompte().toInt(), saisieCheque.reqTauxInteret().toDouble(),
				saisieCheque.reqSolde().toDouble(), saisieCheque.reqTransactions().toInt(),
				saisieCheque.reqTauxInteretMinimum().toDouble(), description);
		int nombreDeLignes = ui.tableWidgetCompte->rowCount();
		ui.tableWidgetCompte->setRowCount(nombreDeLignes+1);
		ui.tableWidgetCompte->setItem(nombreDeLignes, 0, new QTableWidgetItem(saisieCheque.reqNoCompte()));
		ui.tableWidgetCompte->setItem(nombreDeLignes, 1, new QTableWidgetItem("Cheque"));
		ui.tableWidgetCompte->setItem(nombreDeLignes, 2, new QTableWidgetItem(saisieCheque.reqDescription()));
		ui.tableWidgetCompte->setItem(nombreDeLignes, 3, new QTableWidgetItem(saisieCheque.reqSolde()));
		ui.tableWidgetCompte->setItem(nombreDeLignes, 4, new QTableWidgetItem(saisieCheque.reqTauxInteret()));
		ui.tableWidgetCompte->setItem(nombreDeLignes, 5, new QTableWidgetItem(saisieCheque.reqTauxInteretMinimum()));
		ui.tableWidgetCompte->setItem(nombreDeLignes, 6, new QTableWidgetItem(saisieCheque.reqTransactions()));
	}
}

void CompteGUI::ajoutCheque(int p_noCompte, double p_tauxInteret, double p_solde,
		int p_nombreTransactions, double p_tauxInteretMinimum,
		const std::string& p_description){
	try{
		Cheque unCheque(p_noCompte, p_tauxInteret, p_solde,
		p_nombreTransactions, p_tauxInteretMinimum,
		p_description);
		client.ajouterCompte(unCheque);
		m_vComptes2.push_back(new Cheque(unCheque));
	} catch(CompteDejaPresentException& e) {
		QString message = e.what();
		QMessageBox::information(this, "ERREUR", message);
	}
}

void CompteGUI::dialogAjoutEpargne(){
	AjoutEpargneInterface saisieEpargne(this);
	string description = "Epargne";
	if (saisieEpargne.exec()){
		if (!(saisieEpargne.reqDescription().isEmpty())){
			description = saisieEpargne.reqDescription().toStdString();
		}
		ajoutEpargne(saisieEpargne.reqNoCompte().toInt(), saisieEpargne.reqTauxInteret().toDouble(),
				saisieEpargne.reqSolde().toDouble(), description);
		int nombreDeLignes = ui.tableWidgetCompte->rowCount();
		ui.tableWidgetCompte->setRowCount(nombreDeLignes+1);
		ui.tableWidgetCompte->setItem(nombreDeLignes, 0, new QTableWidgetItem(saisieEpargne.reqNoCompte()));
		ui.tableWidgetCompte->setItem(nombreDeLignes, 1, new QTableWidgetItem("Epargne"));
		ui.tableWidgetCompte->setItem(nombreDeLignes, 2, new QTableWidgetItem(saisieEpargne.reqDescription()));
		ui.tableWidgetCompte->setItem(nombreDeLignes, 3, new QTableWidgetItem(saisieEpargne.reqSolde()));
		ui.tableWidgetCompte->setItem(nombreDeLignes, 4, new QTableWidgetItem(saisieEpargne.reqTauxInteret()));
		ui.tableWidgetCompte->setItem(nombreDeLignes, 5, new QTableWidgetItem("s.o."));
		ui.tableWidgetCompte->setItem(nombreDeLignes, 6, new QTableWidgetItem("s.o."));
	}
}

void CompteGUI::ajoutEpargne(int p_noCompte,
		double p_tauxInteret,
		double p_solde,
		const std::string& p_description) {
	try{
		Epargne uneEpargne(p_noCompte, p_tauxInteret, p_solde, p_description);
		client.ajouterCompte(uneEpargne);
	} catch(CompteDejaPresentException& e) {
		QString message = e.what();
		QMessageBox::information(this, "ERREUR", message);
	}
}

void CompteGUI::dialogSuppressionCompte(){
	SuppressionCompteInterface suppressionCompte(this);
	if (suppressionCompte.exec()){
		for (unsigned int i = 0; i < m_vComptes2.size(); i++){
			if (m_vComptes2[i]->reqNoCompte() == suppressionCompte.reqNoCompte().toInt()){
				numeroDeLigne = i;
			}
		}
		ui.tableWidgetCompte->removeRow(numeroDeLigne);
	}
}

void CompteGUI::SuppressionCompte(int p_noCompte) {
	try{
			client.supprimerCompte(p_noCompte);
			m_vComptes2.erase(m_vComptes2.begin()+numeroDeLigne);
	} catch(CompteAbsentException& e) {
		QString message = e.what();
		QMessageBox::information(this, "ERREUR", message);
	}
}





