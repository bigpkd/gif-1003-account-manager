/**
 * \file Epargne.cpp
 * \brief Implantation de la classe Epargne qui sert à la création et à la manipulation d'un objet Epargne.
 * \author Pakendam Bigou-Laré
 * \version 0.4
 * \date 1er avril 2018
 */

#include "Epargne.h"
#include <sstream>

using namespace std;

namespace banque
{
/**
 * \brief Constructeur avec paramètres
 * 			On construit un objet Epargne à partir de valeurs passées en paramètres
 * \param[in] p_noCompte est un nombre entier (int) positif correspondant au numéro du compte
 * \param[in] p_tauxInteret est un nombre à virgule flottante (double) correspondant au taux d'intérêt(en pourcentage) du compte
 * \param[in] p_solde est un nombre à virgule flottante (double) correspondant au solde du compte
 * \param[in] p_description est une chaîne de caractères (string) correspondant à la description du compte
 * \pre p_noCompte doit être positif (vérifiée par le contrat de la classe Compte)
 * \pre p_description ne doit pas être vide (vérifiée par le contrat de la classe Compte)
 * \post m_noCompte prend la valeur de p_noCompte (vérifiée par le contrat de la classe Compte)
 * \post m_tauxInteret prend la valeur de p_tauxInteret (vérifiée par le contrat de la classe Compte)
 * \post m_solde prend la valeur de p_solde (vérifiée par le contrat de la classe Compte)
 * \post m_description prend la valeur de p_description (vérifiée par le contrat de la classe Compte)
 * \post m_dateOuverture doit être la date au moment de la création d'un objet Epargne (vérifiée par le contrat de la classe Compte)
 *
 */
Epargne::Epargne(int p_noCompte, double p_tauxInteret, double p_solde,
		const std::string& p_description) :
		Compte(p_noCompte, p_tauxInteret, p_solde, p_description)
{
	PRECONDITION(p_tauxInteret >= 0.1 && p_tauxInteret <= 3.5);
	PRECONDITION(p_solde >= 0);
	// le constructeur par défaut de la classe Date vérifie la postcondition
	// sur la date d'ouverture
	INVARIANTS();
}

/**
 * \brief effectue une copie d'un objet Epargne
 * \return une copie de l'objet Epargne courant
 * \post m_noCompte a la même valeur pour les deux objets Epargne
 * \post m_tauxInteret a la même valeur pour les deux objets Epargne
 * \post m_solde a la même valeur pour les deux objets Epargne
 * \post m_description a la même valeur pour les deux objets Epargne
 */
Compte* Epargne::clone() const
{
	return new Epargne(*this);
}

/**
 * \brief retourne un résumé des informations du compte(objet Epargne)
 * \return les informations du compte(objet Epargne) formatées dans une chaîne de caractères (string)
 */
std::string Epargne::reqCompteFormate() const
{
	ostringstream os;
	os << "\t Compte Epargne" << endl;
	os << Compte::reqCompteFormate();
	os << "\t Interet" << "\t\t : " << calculerInteret() << "$" << endl;
	return os.str();
}

/**
 * \brief retourne le total des intérêts appliqués au compte(objet Epargne)
 * \return un nombre à virgule floattante correspondant au total des intérêts appliqués au compte(objet Epargne)
 */
double Epargne::calculerInteret() const
{
	return (double) 0.01 * (double) reqTauxInteret() * (double) reqSolde();
}

/**
 * \brief vérifie les invariants de la classe
 */
void Epargne::verifieInvariant() const
{
	INVARIANT(reqTauxInteret() >= 0.1 && reqTauxInteret() <= 3.5);
	INVARIANT(reqSolde() >= 0);
}

} /* namespace banque */
