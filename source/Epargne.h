/**
 * \file Epargne.h
 * \brief Fichier qui contient l'interface de la classe Epargne qui sert à la création et à la manipulation d'un objet Epargne.
 * \author Pakendam Bigou-Laré
 * \version 0.1
 * \date 2 avril 2018
 */

#ifndef EPARGNE_H_
#define EPARGNE_H_

#include "Compte.h"
#include "ContratException.h"

namespace banque
{
/**
 * \class Epargne
 * \brief Cette classe dérivée sert à la création et la manipulation d'objets Epargne.
 * 		Elle permet également de:
 * 			- obtenir toutes les informations relatives à ces comptes	(reqCompteFormate())
 * 			- modifier leurs taux d'intérêts, leurs soldes ou leurs descriptions correspondants	(asgTauxInteret, asgSolde, asgDescription)
 *
 * 		Attributs: <br>
 * 			- int m_noCompte : numéro du compte <br>
 * 			- double m_tauxInteret : taux d'intérêt du compte <br>
 * 			- double m_solde : solde du compte <br>
 * 			- std::string m_description : description du compte <br>
 * 			- util::Date m_dateOuverture : date d'ouverture du compte <br>
 *
 * 	\invariant taux d'intérêt compris entre 0.1% et 3.5%
 * 	\invariant solde positif
 *
 * Note:
 *
 * révisions :
 * …
 */
class Epargne: public Compte
{
public:
	Epargne(int p_noCompte, double p_tauxInteret, double p_solde,
			const std::string& p_description = "Epargne");

	virtual Compte* clone() const;

	std::string reqCompteFormate() const;

	virtual double calculerInteret() const;

private:
	void verifieInvariant() const;
};

} /* namespace banque */

#endif /* EPARGNE_H_ */
