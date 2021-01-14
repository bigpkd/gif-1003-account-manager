/**
 * \file Client.cpp
 * \brief Implantation de la classe Client qui sert à la création et à la manipulation d'un objet Client.
 * \author Pakendam Bigou-Laré
 * \version 0.4
 * \date 1er avril 2018
 */

#include "Client.h"
#include <iostream>
#include <sstream>
#include "CompteException.h"
#include <iterator>

using namespace std;

namespace banque
{
/**
 * \brief Constructeur avec paramètres
 * 		  On construit un objet Client à partir de valeurs passées en paramètres.
 * \param[in] p_noFolio est un entier (int) qui représente le numéro de folio d'un client
 * \param[in] p_nom est une chaîne de caractères (string) qui représente le nom du client
 * \param[in] p_prenom est une chaîne de caractères (string) qui représente le prénom du client
 * \param[in] p_telephone est une chaîne de caractères (string) qui représente le numéro de téléphone du client
 * \param[in] p_dateNaissance est une date de la classe (util::Date) qui représente la date de naissance d'un client
 * \pre p_noFolio doit être dans l'intervalle [1000, 10000[
 * \pre p_nom ne doit être composé que de lettres de l'alphabet ou d'espaces
 * \pre p_prenom ne doit être composé que de lettres de l'alphabet ou d'espaces
 * \pre p_telephone doit avoir le format national(sans l'indicatif international) des numeros de telephone canadiens
 * \pre p_dateNaissance doit être une date située entre l'an 1970 inclusivement et l'an 2037 inclusivement
 * \post m_noFolio prend la valeur de p_noFolio
 * \post m_nom prend la valeur de p_nom
 * \post m_prenom prend la valeur de p_prenom
 * \post m_telephone prend la valeur de p_telephone
 * \post m_dateNaissance prend la valeur de p_dateNaissance
 */
Client::Client(int p_noFolio, const std::string& p_nom,
		const std::string& p_prenom, const std::string& p_telephone,
		const util::Date& p_dateNaissance) :
		m_noFolio(p_noFolio), m_nom(p_nom), m_prenom(p_prenom), m_telephone(
				p_telephone), m_dateNaissance(p_dateNaissance)
{
	PRECONDITION(p_noFolio >= 1000 && p_noFolio < 10000);
	PRECONDITION(util::validerFormatNom(p_nom));
	PRECONDITION(util::validerFormatNom(p_prenom));
	PRECONDITION(util::validerTelephone(p_telephone));
	// p_dateNaissance est testée par le contrat de la classe Date

	POSTCONDITION(m_noFolio == p_noFolio);
	POSTCONDITION(m_nom == p_nom);
	POSTCONDITION(m_prenom == p_prenom);
	POSTCONDITION(m_telephone == p_telephone);
	// m_dateNaissance est testée par le contrat de la classe Date
	INVARIANTS();

}

/**
 * \brief Désalloue tout l'espace mémoire attribué à l'ensemble des comptes d'un client
 */
Client::~Client()
{
	std::vector<Compte*>::const_iterator iter;// itérateur sur un vecteur de pointeurs de Comptes
	for (iter = m_vComptes.begin(); iter != m_vComptes.end(); iter++)
	{
		delete *iter;
	}
}

/**
 * \brief retourne le numéro de folio du client correspondant à l'objet courant
 * \return un entier (int) qui représente le numéro de folio d'un client
 */
int Client::reqNoFolio() const
{
	return m_noFolio;
}

/**
 * \brief retourne le nom du client correspondant à l'objet courant
 * \return une chaîne de caractères (string) qui représente le nom d'un client
 */
const std::string& Client::reqNom() const
{
	return m_nom;
}

/**
 * \brief retourne le prénom du client correspondant à l'objet courant
 * \return une chaîne de caractères (string) qui représente le prénom d'un client
 */
const std::string& Client::reqPrenom() const
{
	return m_prenom;
}

/**
 * \brief retourne la date de naissance du client correspondant à l'objet courant
 * \return une date de la classe (util::Date) qui représente la date de naissance d'un client
 */
const util::Date& Client::reqDateDeNaissance() const
{
	return m_dateNaissance;
}

/**
 * \brief retourne le numéro de téléphone du client correspondant à l'objet courant
 * \return une chaîne de caractères (string) qui représente le numéro de téléphone d'un client
 */
const std::string& Client::reqTelephone() const
{
	return m_telephone;
}

/**
 * \brief formate les informations du client dans une une chaîne de caractères (string)
 * \return L'ensemble des informations d'un client formatée dans une chaîne de caractères (string)
 */
std::string Client::reqClientFormate() const
{
	ostringstream os;
	os << "\t Client no : " << m_noFolio << endl << "\t " << m_prenom << " "
			<< m_nom << endl << "\t Date de naissance : "
			<< m_dateNaissance.reqDateFormatee() << endl << "\t " << m_telephone
			<< endl;
	return os.str();
}

/**
 * \brief formate les informations du folio d'un client dans une une chaîne de caractères (string)
 * \return les informations relatives à tous les comptes d'un client formatées dans une une chaîne de caractères (string)
 */
std::string Client::reqReleves() const
{
	ostringstream os;
	os << reqClientFormate();
	std::vector<Compte*>::const_iterator iter;// itérateur sur un vecteur de pointeurs de Comptes
	for (iter = m_vComptes.begin(); iter != m_vComptes.end(); iter++)
	{
		os << (*iter)->reqCompteFormate();
	}
	return os.str();
}

/**
 * \brief Assigne un numéro de téléphone au client correspondant à l'objet courant
 * \param[in] p_telephone est une chaîne de caractères (string) qui représente le numéro de téléphone à assigner au client
 * \pre p_telephone doit avoir le format national(sans l'indicatif international) des numeros de telephone canadiens
 * \post m_telephone prend la valeur de p_telephone
 */
void Client::asgTelephone(const std::string& p_telephone)
{
	PRECONDITION(util::validerTelephone(p_telephone));
	m_telephone = p_telephone;
	POSTCONDITION(m_telephone == p_telephone);
	INVARIANTS();
}

/**
 * \brief retourne un booléen (bool) qui confirme ou infirme que deux objets Clients sont identiques
 * \param[in] p_client est l'objet Client auquel on compare l'objet Client courant
 * \return un booléen (bool) qui confirme ou infirme que l'objet Client passé en paramètre est identique à l'objet Client courant
 */
bool Client::operator ==(const Client& p_client) const
{
	return m_noFolio == p_client.m_noFolio && m_nom == p_client.m_nom
			&& m_prenom == p_client.m_prenom
			&& m_dateNaissance == p_client.m_dateNaissance
			&& m_telephone == p_client.m_telephone;
}

/**
 * \brief retourne un booléen (bool) qui confirme ou infirme qu'un objet Client a un numéro de folio inférieur à un autre
 * \param[in] p_client est l'objet Client dont le numéro de folio est supposément supérieur à celui de l'objet Client courant
 * \return un booléen (bool) qui confirme ou infirme que l'objet Client passé en paramètre a un numéro de folio supérieur à celui de l'objet Client courant
 */
bool Client::operator <(const Client& p_client) const
{
	return m_noFolio < p_client.m_noFolio;
}

/**
 * \brief retourne un booléen (bool) qui confirme ou infirme que le client possede effectivement un certain compte
 * \param[in] p_noCompte est le numero de compte pour lequel on veut vérifier l'appartenance à un client
 * \return un booleen (bool) qui confirme ou infirme que le client possede effectivement le compte dont le numero est p_noCompte
 */
bool Client::compteEstDejaPresent(int p_noCompte) const
{
	//Cette méthode permet de vérifier si le client a déjà ce compte. Si oui, elle retourne true et false sinon
	bool resultat = false;
	std::vector<Compte*>::const_iterator iter;
	for (iter = m_vComptes.begin(); iter != m_vComptes.end(); iter++)
	{
		if ((*iter)->reqNoCompte() == p_noCompte)
		{
			resultat = true;
		}
	}
	return resultat;
}

/**
 * \brief ajoute un nouveau compte à un client
 * \post m_vComptes doit avoir un élément(un objet Compte) en plus
 */
void Client::ajouterCompte(const Compte& p_nouveauCompte)
{
	unsigned int nombreDeComptesAnterieur = m_vComptes.size();
	if ((compteEstDejaPresent(p_nouveauCompte.reqNoCompte())))
	{
		ostringstream os;
		os << "Le client possède déjà ce compte :" << endl;
		os << p_nouveauCompte.reqCompteFormate() << endl;
		throw CompteDejaPresentException(os.str());
	}
	if (!(compteEstDejaPresent(p_nouveauCompte.reqNoCompte())))
	{
		m_vComptes.push_back(p_nouveauCompte.clone());
	}
	POSTCONDITION(m_vComptes.size() == nombreDeComptesAnterieur + 1);
	INVARIANTS();
}

/**
 * \brief supprime un compte d'un client
 * \post m_vComptes doit avoir un élément(un objet Compte) en moins
 */
void Client::supprimerCompte(const int& p_noCompte)
{
	unsigned int nombreDeComptesAnterieur = m_vComptes.size();
	if (!compteEstDejaPresent(p_noCompte))
	{
		ostringstream os;
		os << "Le compte " << p_noCompte << "n'existe pas." << endl;
		throw CompteAbsentException(os.str());
	}
	if ((compteEstDejaPresent(p_noCompte)))
	{
		std::vector<Compte*>::iterator iter;
		for (iter = m_vComptes.begin(); iter != m_vComptes.end(); iter++)
		{
			if ((*iter)->reqNoCompte() == p_noCompte)
			{
				delete (*iter);			// désallocation préalable de la mémoire
				m_vComptes.erase(iter); // suppression du pointeur dans le vecteur
			}
		}
	}
	POSTCONDITION(m_vComptes.size() == nombreDeComptesAnterieur - 1);
	INVARIANTS();
}

/**
 * \brief Vérifie les invariants de la classe Client
 */
void Client::verifieInvariant() const
{
	INVARIANT(m_noFolio >= 1000 && m_noFolio < 10000);
	INVARIANT(util::validerFormatNom(m_nom));
	INVARIANT(util::validerFormatNom(m_prenom));
	INVARIANT(util::validerTelephone(m_telephone));
	// m_dateNaissance est testée par le contrat de la classe Date
}

} /* namespace banque */

