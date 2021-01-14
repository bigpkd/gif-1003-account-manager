/**
 * \file Compte.cpp
 * \brief Implantation de la classe Compte qui sert à la création et à la manipulation d'un objet Compte.
 * \author Pakendam Bigou-Laré
 * \version 0.4
 * \date 2 avril 2018
 */

#include "Compte.h"
#include <sstream>

using namespace std;

namespace banque
{

/**
 * \brief Constructeur avec paramètres
 * 		  On construit un objet Compte à partir de valeurs passées en paramètres.
 * \param[in] p_noCompte est un nombre entier positif correspondant au numéro du compte
 * \param[in] p_tauxInteret est un nombre à virgule flottante correspondant au taux d'intérêt(en pourcentage) du compte
 * \param[in] p_solde est un nombre à virgule flottante correspondant au solde du compte
 * \param[in] p_description est une chaîne de caractères correspondant à la description du compte
 * \pre p_noCompte doit être positif
 * \pre p_description ne doit pas être vide
 * \post m_noCompte prend la valeur de p_noCompte
 * \post m_tauxInteret prend la valeur de p_tauxInteret
 * \post m_solde prend la valeur de p_solde
 * \post m_description prend la valeur de p_description
 * \post m_dateOuverture doit être la date au moment de la création du compte
 *
 */
Compte::Compte(int p_noCompte, double p_tauxInteret, double p_solde,
		const std::string& p_description) :
		m_noCompte(p_noCompte), m_tauxInteret(p_tauxInteret), m_solde(p_solde), m_description(
				p_description)
{
	PRECONDITION(p_noCompte >= 0);
	PRECONDITION(p_tauxInteret >= 0.0);
	PRECONDITION(!(p_description.empty()));

	POSTCONDITION(m_noCompte == p_noCompte);
	POSTCONDITION(m_tauxInteret == p_tauxInteret);
	POSTCONDITION(m_solde == p_solde);
	POSTCONDITION(m_description == p_description);

	INVARIANTS();
}

/**
 * \brief retourne un résumé des informations relatives au compte correspondant à l'objet courant
 * \return une chaîne de caractères (string) qui représente les informations relatives à ce compte
 */
std::string Compte::reqCompteFormate() const
{
	ostringstream os;
	os << "\t numero " << "\t\t : " << m_noCompte << endl << "\t Description "
			<< "\t\t : " << m_description << endl << "\t Date d'ouverture "
			<< "\t : " << m_dateOuverture.reqDateFormatee() << endl
			<< "\t Taux d'interet " << "\t : " << m_tauxInteret << endl
			<< "\t Solde " << "\t\t\t : " << m_solde << " $" << endl;
	return os.str();
}

/**
 * \brief retourne le taux d'intérêt du compte correspondant à l'objet courant
 * \return un nombre entier positif (int) qui représente le taux d'intérêt de ce compte
 */
int Compte::reqNoCompte() const
{
	return m_noCompte;
}

/**
 * \brief retourne le taux d'intérêt du compte correspondant à l'objet courant
 * \return un nombre à virgule flottante (double) qui représente le taux d'intérêt de ce compte
 */
double Compte::reqTauxInteret() const
{
	return m_tauxInteret;
}

/**
 * \brief retourne le solde du compte correspondant à l'objet courant
 * \return un nombre à virgule flottante (double) qui représente le solde de ce compte
 */
double Compte::reqSolde() const
{
	return m_solde;
}

/**
 * \brief retourne la description du compte correspondant à l'objet courant
 * \return une chaîne de caractères (string) qui représente la description de ce compte
 */
const std::string& Compte::reqDescription() const
{
	return m_description;
}

/**
 * \brief retourne la date d'ouverture du compte correspondant à l'objet courant
 * \return une date (Date) qui représente la date d'ouverture du compte
 */
const util::Date& Compte::reqDateOuverture() const
{
	return m_dateOuverture;
}

/**
 * \brief assigne un nouveau taux d'intérêt à un compte
 * \param[in] p_tauxInteret est un nombre à virgule flottante (double) indiquant le nouveau taux d'intérêt du compte
 * \post m_tauxInteret prend la valeur de p_tauxInteret
 */
void Compte::asgTauxInteret(double p_tauxInteret)
{
	m_tauxInteret = p_tauxInteret;
	POSTCONDITION(m_tauxInteret == p_tauxInteret);
	INVARIANTS();
}

/**
 * \brief assigne un nouveau solde à un compte
 * \param[in] p_solde est un nombre à virgule flottante (double) indiquant le nouveau solde du compte
 * \post m_solde prend la valeur de p_solde
 */
void Compte::asgSolde(double p_solde)
{
	m_solde = p_solde;
	POSTCONDITION(m_solde == p_solde);
	INVARIANTS();
}

/**
 * \brief assigne une nouvelle description à un compte
 * \param[in] p_description est une chaîne de caractères (string) représentant la nouvelle description du compte
 * \pre p_description ne doit pas être vide
 * \post m_description prend la valeur de p_description
 */
void Compte::asgDescription(const std::string& p_description)
{
	PRECONDITION(!(m_description.empty()));
	m_description = p_description;
	POSTCONDITION(m_description == p_description);
	INVARIANTS();
}

/**
 * \brief Teste les invariants de la classe Compte
 */
void Compte::verifieInvariant() const
{
	INVARIANT(m_noCompte >= 0);
	INVARIANT(m_tauxInteret >= 0.0);
	INVARIANT(!(m_description.empty()));
	util::Date p_date;
	INVARIANT(m_dateOuverture == p_date);
}

} /*namespace banque*/
