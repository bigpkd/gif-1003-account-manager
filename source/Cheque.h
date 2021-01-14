/**
 * \file Cheque.h
 * \brief Fichier qui contient l'interface de la classe Cheque qui sert à la création et à la manipulation d'un objet Cheque.
 * \author Pakendam Bigou-Laré
 * \version 0.1
 * \date 2 avril 2018
 */
#ifndef CHEQUE_H_
#define CHEQUE_H_

#include "Compte.h"
#include "ContratException.h"

namespace banque
{
/**
 * \class Cheque
 * \brief Cette classe dérivée sert à la création et la manipulation d'objets Cheque.
 * 		Elle permet également de:
 * 			- obtenir toutes les informations relatives à ces comptes	(reqCompteFormate())
 * 			- modifier leurs taux d'intérêts, leurs soldes, leurs descriptions... correspondants	(asgTauxInteret, asgSolde, asgDescription)
 *
 * 		Attributs: <br>
 * 			- int m_noCompte : numéro du compte <br>
 * 			- double m_tauxInteret : taux d'intérêt du compte <br>
 * 			- double m_solde : solde du compte <br>
 * 			- std::string m_description : description du compte <br>
 * 			- util::Date m_dateOuverture : date d'ouverture du compte <br>
 * 			- int m_nombreTransactions: nombre de transactions du compte <br>
 * 			- double m_tauxInteretMinimum: taux d'intérêt minimum du compte <br>
 *
 * \invariant taux d'intérêt minimum <= taux d'intérêt
 * \invariant nombre de transactions compris entre 0 et 40
 *
 * Note:
 *
 * révisions :
 * …
 */
class Cheque: public Compte
{
public:
	Cheque(int p_noCompte, double p_tauxInteret, double p_solde,
			int p_nombreTransactions, double p_tauxInteretMinimum = 0.1,
			const std::string& p_description = "Cheque");

	virtual Compte* clone() const;

	std::string reqCompteFormate() const;

	virtual double calculerInteret() const;

	double reqTauxInteretMinimum() const;
	int reqNombreTransactions() const;

	void asgNombreTransactions(int p_nombreTransactions);

private:
	int m_nombreTransactions;
	double m_tauxInteretMinimum;
	void verifieInvariant() const;
};

} /* namespace banque */

#endif /* CHEQUE_H_ */
