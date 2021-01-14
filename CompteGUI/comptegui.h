#ifndef COMPTEGUI_H
#define COMPTEGUI_H

#include <QtGui/QMainWindow>
#include "ui_comptegui.h"
#include "Date.h"
#include "Client.h"
#include <vector>

class CompteGUI : public QMainWindow
{
    Q_OBJECT

public:
    CompteGUI(QWidget *parent = 0);
    ~CompteGUI();
    void ajoutCheque(int p_noCompte, double p_tauxInteret, double p_solde,
		int p_nombreTransactions, double p_tauxInteretMinimum = 0.1,
		const std::string& p_description = "Cheque");
    void ajoutEpargne(int p_noCompte,
    		double p_tauxInteret,
    		double p_solde,
    		const std::string& p_description = "Epargne");
  void SuppressionCompte(int p_noCompte);

public slots:
	void dialogAjoutCheque();
	void dialogAjoutEpargne();
	void dialogSuppressionCompte();

private:
    Ui::CompteGUIClass ui;
    std::vector<banque::Compte*>m_vComptes2;
    banque::Client client;
	int numeroDeLigne;
};

#endif // COMPTEGUI_H
