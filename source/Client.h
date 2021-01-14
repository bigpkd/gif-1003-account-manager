/**
 * \file Client.h
 * \brief Fichier qui contient l'interface de la classe Client qui sert à la création et à la manipulation d'un objet Client.
 * \author Pakendam Bigou-Laré
 * \version 0.4
 * \date 1er avril 2018
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "Date.h"
#include "ContratException.h"
#include "validationFormat.h"
#include "Compte.h"
#include <vector>

namespace banque
{
/**
 * \class Client
 * \brief Cette classe sert à la création et la manipulation d'objets clients.
 * 		Elle permet également de:
 * 			- retourner toutes les informations relatives à ces clients	(reqClientFormate())
 * 			- comparer deux objets clients							(operator==(objet Client))
 * 			- évaluer l'ordonnancement d'un objet Client par rapport à un autre	(operator<(objet Client))
 * 			- modifier leurs numéros de téléphones correspondants	(asgTelephone(numéro de téléphone))
 *
 * 		Attributs: <br>
 * 			- int m_noFolio : numéro de folio concernant le client <br>
 * 			- std::string m_nom : nom du client <br>
 * 			- std::string m_prenom : prénom du client <br>
 * 			- std::string m_telephone : numéro de téléphone du client <br>
 * 			- util::Date m_dateNaissance : date d'ouverture du dossier du client <br>
 *
 * \invariant numéro de folio >= 1000 et < 10000
 * \invariant nom ne contenant que des lettres et des espaces
 * \invariant prénom ne contenant que des lettres et des espaces
 * \invariant numéro de téléphone au format national canadien
 *
 * Note:
 *
 * révisions :
 * …
 */
class Client
{
public:

	Client(int p_noFolio, const std::string& p_nom, const std::string& p_prenom,
			const std::string& p_telephone, const util::Date& p_dateNaissance);

	~Client();//responsable de désallouer tous les comptes du client dans le vecteur

	int reqNoFolio() const;
	const std::string& reqNom() const;
	const std::string& reqPrenom() const;
	const std::string& reqTelephone() const;
	const util::Date& reqDateDeNaissance() const;
	std::string reqClientFormate() const;

	std::string reqReleves() const;

	void asgTelephone(const std::string& p_telephone);

	bool operator==(const Client& p_client) const;
	bool operator<(const Client& p_client) const;
	void ajouterCompte(const Compte& p_nouveauCompte);
	void supprimerCompte(const int& p_noCompte);

private:

	bool compteEstDejaPresent(int p_noCompte) const;
	Client(const Client& p_client); 					// Constructeur copie
	const Client& operator=(const Client& p_client); // opérateur d'assignation

	int m_noFolio;
	std::string m_nom;
	std::string m_prenom;
	std::string m_telephone;
	util::Date m_dateNaissance;

	std::vector<Compte*> m_vComptes;

	void verifieInvariant() const;
};

} /*namespace banque*/

#endif /* CLIENT_H_ */
