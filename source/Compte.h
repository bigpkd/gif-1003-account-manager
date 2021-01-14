/**
 * \file Compte.h
 * \brief Fichier qui contient l'interface de la classe Compte qui sert à la création et à la manipulation d'un objet Compte.
 * \author Pakendam Bigou-Laré
 * \version 0.1
 * \date 1er avril 2018
 */

#ifndef COMPTE_H_
#define COMPTE_H_

#include "Date.h"
#include "ContratException.h"

namespace banque
{
/**
 * \class Compte
 * \brief Cette classe abstraite sert à la création et la manipulation d'objets Compte.
 * 		Elle permet également de: <br>
 * 			- obtenir toutes les informations relatives à ces comptes	(reqCompteFormate())
 * 			- modifier leurs taux d'intérêts, leurs soldes ou leurs descriptions correspondants	(asgTauxInteret, asgSolde, asgDescription)
 * 			- un traitement polymorphe dans les classes qui lui sont dérivées	(~Compte(), clone(), reqCompteFormate(), calculerInteret())
 *
 * 		Attributs: <br>
 * 			- int m_noCompte : numéro du compte
 * 			- double m_tauxInteret : taux d'intérêt du compte
 * 			- double m_solde : solde du compte
 * 			- std::string m_description : description du compte
 * 			- util::Date m_dateOuverture : date d'ouverture du compte
 *
 * \invariant numéro de compte positif
 * \invariant taux d'intérêt positif
 * \invariant description non vide
 * \invariant date d'ouverture correspondant au jour actuel(jour de la création de l'objet)
 *
 * Note:
 *
 * révisions :
 * …
 */
class Compte
{
public:
	Compte(int p_noCompte, double p_tauxInteret, double p_solde,
			const std::string& p_description);
	virtual ~Compte()
	{
	}
	;
	virtual Compte* clone() const = 0;
	/*Cette déclaration doit imposer l’implémentation de cette
	 *  méthode dans toute classe dérivée. Il n’y a rien à
	 *  définir dans la classe Compte pour cette méthode
	 *  (voir classes dérivées).*/
	virtual std::string reqCompteFormate() const;
	virtual double calculerInteret() const = 0;
	/*Au niveau de la classe Compte, il n’est pas nécessaire
	 * de la définir, sa déclaration doit imposer son
	 * implémentation dans toute classe dérivée; cette méthode
	 * est purement virtuelle.*/

	int reqNoCompte() const;
	double reqTauxInteret() const;
	double reqSolde() const;
	const std::string& reqDescription() const;
	const util::Date& reqDateOuverture() const;
	void asgTauxInteret(double p_tauxInteret);
	void asgSolde(double p_solde);
	void asgDescription(const std::string& p_description);

private:
	int m_noCompte;		// (doit être positif)
	double m_tauxInteret;
	double m_solde;
	std::string m_description; // (doit être non vide)
	util::Date m_dateOuverture;	// (date à la création du compte)
	void verifieInvariant() const;
};

} /*namespace banque*/

#endif /* COMPTE_H_ */
