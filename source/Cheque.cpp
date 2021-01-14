/**
 * \file Cheque.cpp
 * \brief Implantation de la classe Cheque qui sert à la création et à la manipulation d'un objet Cheque.
 * \author Pakendam Bigou-Laré
 * \version 0.4
 * \date 2 avril 2018
 */

#include "Cheque.h"
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
 * \param[in] p_nombreTransactions est un nombre entier (int) positif correspondant au nombre de transactions du compte
 * \param[in] p_tauxInteretMinimum est un nombre à virgule flottante (double) correspondant au taux d'intérêt minimum(en pourcentage) du compte
 * \param[in] p_description est une chaîne de caractères (string) correspondant à la description du compte
 * \pre p_noCompte doit être positif (vérifiée par le contrat de la classe Compte)
 * \pre p_nombreTransactions doit être inférieur ou égal à 40 et positif
 * \pre p_tauxInteretMinimum doit être inférieur ou égal à p_tauxInteret
 * \pre p_description ne doit pas être vide (vérifiée par le contrat de la classe Compte)
 * \post m_noCompte prend la valeur de p_noCompte (vérifiée par le contrat de la classe Compte)
 * \post m_tauxInteret prend la valeur de p_tauxInteret (vérifiée par le contrat de la classe Compte)
 * \post m_solde prend la valeur de p_solde (vérifiée par le contrat de la classe Compte)
 * \post m_description prend la valeur de p_description (vérifiée par le contrat de la classe Compte)
 * \post m_dateOuverture doit être la date au moment de la création d'un objet Epargne (vérifiée par le contrat de la classe Compte)
 * \post m_nombreTransactions prend la valeur de p_nombreTransactions
 * \post m_tauxInteretMinimum prend la valeur de p_tauxInteretMinimum
 *
 */
Cheque::Cheque(int p_noCompte, double p_tauxInteret, double p_solde,
		int p_nombreTransactions, double p_tauxInteretMinimum,
		const std::string& p_description) :
		Compte(p_noCompte, p_tauxInteret, p_solde, p_description), m_nombreTransactions(
				p_nombreTransactions), m_tauxInteretMinimum(
				p_tauxInteretMinimum)
{
	PRECONDITION(p_nombreTransactions >= 0 && p_nombreTransactions <= 40);
	PRECONDITION(p_tauxInteretMinimum <= p_tauxInteret);

	POSTCONDITION(m_nombreTransactions == p_nombreTransactions);
	POSTCONDITION(m_tauxInteretMinimum == p_tauxInteretMinimum);
	INVARIANTS();
}

/**
 * \brief effectue une copie d'un objet Cheque
 * \return une copie de l'objet Cheque courant
 * \post m_noCompte a la même valeur pour les deux objets Cheque
 * \post m_tauxInteret a la même valeur pour les deux objets Cheque
 * \post m_solde a la même valeur pour les deux objets Cheque
 * \post m_description a la même valeur pour les deux objets Cheque
 * \post m_dateOuverture a la même valeur pour les deux objets Cheque
 * \post m_nombreTransactions a la même valeur pour les deux objets Cheque
 * \post m_tauxInteretMinimum a la même valeur pour les deux objets Cheque
 *
 */
Compte* Cheque::clone() const
{
	return new Cheque(*this);
}

/**
 * \brief retourne un résumé des informations du compte(objet Cheque)
 * \return les informations du compte(objet Cheque) formatées dans une chaîne de caractères (string)
 */
std::string Cheque::reqCompteFormate() const
{
	ostringstream os;
	os << "\t Compte Cheque" << endl;
	os << Compte::reqCompteFormate();
	os << "\t nombre de transactions" << "\t : " << m_nombreTransactions << endl
			<< "\t Taux d'interet minimum" << "\t : " << m_tauxInteretMinimum
			<< endl;
	os << "\t Interet" << "\t\t : " << calculerInteret() << " $" << endl;
	return os.str();
}

/**
 * \brief effectue le calcul de l'intérêt total d'un compte(objet Cheque) en fonction du nombre de transactions de ce compte
 * \return un nombre à virgule flottante (double) correspondant à l'intérêt total du compte(objet Cheque)
 */
double Cheque::calculerInteret() const
{
	double interet = 0.0;
	if (Compte::reqSolde() < 0)
	{
		if (m_nombreTransactions >= 0 && m_nombreTransactions <= 10)
		{
			interet = -(double) 0.01 * (double) m_tauxInteretMinimum
					* (double) reqSolde();
		}
		if (m_nombreTransactions >= 11 && m_nombreTransactions <= 25)
		{
			interet = -(double) 0.01 * (double) reqTauxInteret()
					* (double) reqSolde() * (double) 0.04;
		}
		if (m_nombreTransactions >= 26 && m_nombreTransactions <= 35)
		{
			interet = -(double) 0.01 * (double) reqTauxInteret()
					* (double) reqSolde() * (double) 0.08;
		}
		if (m_nombreTransactions > 35)
		{
			interet = -(double) 0.01 * (double) reqTauxInteret()
					* (double) reqSolde();
		}
	}
	return interet;
}

/**
 * \brief retourne le taux d'intérêt minimum d'un compte(objet Cheque)
 * \return un nombre à virgule flottante (double) correspondant au taux d'intérêt minimum(en pourcentage) du compte(objet Cheque)
 */
double Cheque::reqTauxInteretMinimum() const
{
	return m_tauxInteretMinimum;
}

/**
 * \brief retourne le nombre de transactions d'un compte(objet Cheque)
 * \return un nombre entier correspondant au nombre de transactions d'un compte(objet Cheque)
 */
int Cheque::reqNombreTransactions() const
{
	return m_nombreTransactions;
}

/**
 * \brief Assigne une nouvelle valeur au nombre de transactions d'un compte(objet Cheque)
 * \param[in] p_nombreTransactions est un nombre entier correspondant au nombre de transactions d'un compte(objet Cheque)
 * \pre p_nombreTransactions doit être positif
 * \post m_nombreTransactions prend la valeur de p_nombreTransactions
 */
void Cheque::asgNombreTransactions(int p_nombreTransactions)
{
	PRECONDITION(p_nombreTransactions >= 0);
	m_nombreTransactions = p_nombreTransactions;
	POSTCONDITION(m_nombreTransactions == p_nombreTransactions);
	INVARIANTS();
}

/**
 * \brief Teste les invariants de la classe. Ces derniers garantissent que les taux d'intérêt et le nombre de transactions sont valides
 */
void Cheque::verifieInvariant() const
{
	INVARIANT(m_tauxInteretMinimum <= reqTauxInteret());
	INVARIANT(m_nombreTransactions >= 0 && m_nombreTransactions <= 40);
}

}
