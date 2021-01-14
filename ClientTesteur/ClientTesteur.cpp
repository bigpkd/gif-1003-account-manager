/**
 * \file ClientTesteur.cpp
 * \brief Fichier implémentant les tests de la classe Client
 * \author: Pakendam Bigou-Laré
 * \version 0.1
 * \date 31 mars 2018
 */

#include <gtest/gtest.h>
#include "Client.h"
#include "Cheque.h"
#include "Epargne.h"
#include "CompteException.h"
#include <sstream>			// pour ostringstream

using namespace std;
using namespace banque;

/**
 * \test Test du Constructeur Client::Client(int , const std::string& ,
 const std::string& , const std::string& , const util::Date& )

 * 		Cas valides :
 * 				Création d'un objet Client et vérification de l'assignation de tous les attributs
 * 				Numéro de folio inclus dans l'intervalle [1000, 10000[
 * 				Nom constitué de lettres de l'alphabet et/ou d'espaces
 * 				Prénom constitué de lettres de l'alphabet et/ou d'espaces
 * 				Numéro de téléphone au format national canadien
 * 				Date de naissance située entre 1970 et 2037
 */

TEST(Client, Constructeur)
{
	Client unClient(5000, "Shakur", "Amaru", "418 222-2222",
			util::Date(16, 6, 1971));
	ASSERT_EQ(5000, unClient.reqNoFolio());
	ASSERT_EQ("Shakur", unClient.reqNom());
	ASSERT_EQ("Amaru", unClient.reqPrenom());
	ASSERT_EQ("418 222-2222", unClient.reqTelephone());
	ASSERT_EQ(util::Date(16, 6, 1971), unClient.reqDateDeNaissance());
}

/**
 * \test Test du Constructeur Client::Client(int , const std::string& ,
 const std::string& , const std::string& , const util::Date& )
 *
 * 		Cas invalide : Numéro de folio hors de l'intervalle [1000, 10000[
 */
TEST(Client, ConstructeurNumeroFolioInvalide)
{
	ASSERT_THROW(
			Client unClient(10000, "Shakur", "Amaru", "418 222-2222", util::Date(16,6,1971)),
			PreconditionException);
}

/**
 * \test Test du Constructeur Client::Client(int , const std::string& ,
 const std::string& , const std::string& , const util::Date& )
 *
 * 		Cas invalide : Nom incluant au moins un caractère qui n'est ni de l'alphabet, ni un espace
 */
TEST(Client, ConstructeurNomInvalide)
{
	ASSERT_THROW(
			Client unClient(5000, "-", "Amaru", "418 222-2222", util::Date(16,6,1971)),
			PreconditionException);
}

/**
 * \test Test du Constructeur Client::Client(int , const std::string& ,
 const std::string& , const std::string& , const util::Date& )
 *
 * 		Cas invalide : Prénom incluant au moins un caractère qui n'est ni de l'alphabet, ni un espace
 */
TEST(Client, ConstructeurPrenomInvalide)
{
	ASSERT_THROW(
			Client unClient(5000, "Shakur", "Am&ru", "418 222-2222", util::Date(16,6,1971)),
			PreconditionException);
}

/**
 * \test Test du Constructeur Client::Client(int , const std::string& ,
 const std::string& , const std::string& , const util::Date& )
 *
 * 		Cas invalide : Numero de téléphone invalide
 */
TEST(Client, ConstructeurTelephoneInvalide)
{
	ASSERT_THROW(
			Client unClient(5000, "Shakur", "Amaru", "418-222-2222", util::Date(16,6,1971)),
			PreconditionException);
}

/**
 * \test Test du Constructeur Client::Client(int , const std::string& ,
 const std::string& , const std::string& , const util::Date& )
 *
 * 		Cas invalide : Date de naissance antérieure à l'an 1970
 */
TEST(Client, ConstructeurDateDeNaissanceInvalide)
{
	ASSERT_THROW(
			Client unClient(5000, "Shakur", "Amaru", "418 222-2222", util::Date(16,6,1969)),
			ContratException);
}

/**
 * \class unClient
 * \brief Fixture pour la création d'un objet Client à utiliser pour tester les méthodes publiques de la classe Client <br>
 */
class unClient: public ::testing::Test
{
public:
	unClient() :
			client(5000, "Shakur", "Amaru", "418 222-2222",
					util::Date(16, 6, 1971))
	{
	}
	Client client;
};

/**
 * \test Test de la méthode reqNoFolio() <br>
 * 			Cas valide : Construction, vérifier le retour du numéro de folio du client <br>
 * 			Cas invalide : aucun
 */
TEST_F(unClient, reqNoFolio)
{
	ASSERT_EQ(5000, client.reqNoFolio());
}

/**
 * \test Test de la méthode reqNom() <br>
 * 		Cas valide : Construction, vérifier le retour du nom de famille du client <br>
 * 		Cas invalide : aucun
 */
TEST_F(unClient, reqNom)
{
	ASSERT_EQ("Shakur", client.reqNom());
}

/**
 * \test Test de la méthode reqPrenom() <br>
 * 		Cas valide : Construction, vérifier le retour du prénom du client <br>
 * 		Cas invalide : aucun
 */
TEST_F(unClient, reqPrenom)
{
	ASSERT_EQ("Amaru", client.reqPrenom());
}

/**
 * \test Test de la méthode reqTelephone() <br>
 * 		Cas valide : Construction, vérifier le retour du numéro de téléphone du client <br>
 * 		Cas invalide : aucun
 */
TEST_F(unClient, reqTelephone)
{
	ASSERT_EQ("418 222-2222", client.reqTelephone());
}

/**
 * \test Test de la méthode reqDateDeNaissance() <br>
 * 		Cas valide : Construction, vérifier le retour de la date de naissance du client <br>
 * 		Cas invalide : aucun
 */
TEST_F(unClient, reqDateDeNaissance)
{
	ASSERT_EQ(util::Date(16, 6, 1971), client.reqDateDeNaissance());
}

/**
 * \test Test de la méthode reqClientFormate() <br>
 * 		Cas valide : Construction, vérifier le retour des informations sur le client <br>
 * 		Cas invalide : aucun
 */
TEST_F(unClient, reqClientFormate)
{
	ostringstream os;
	os << "\t Client no : " << 5000 << endl << "\t " << "Amaru" << " "
			<< "Shakur" << endl << "\t " << "Date de naissance : "
			<< util::Date(16, 6, 1971).reqDateFormatee() << endl << "\t "
			<< "418 222-2222" << endl;
	ASSERT_EQ(os.str(), client.reqClientFormate());
}

/**
 * \test Test de la méthode reqReleves() <br>
 * 		Cas valide : Construction, vérifier le retour des relevés des comptes du client <br>
 * 		Cas invalide : aucun
 */
TEST_F(unClient, reqReleves)
{
	Cheque unCompteCheque(10001, 1.2, 500, 4, 0.3, "courant");
	Epargne unCompteEpargne(10007, 1.25, 500, "voyage");
	client.ajouterCompte(unCompteCheque);
	client.ajouterCompte(unCompteEpargne);
	ostringstream os;
	os << client.reqClientFormate() << unCompteCheque.reqCompteFormate()
			<< unCompteEpargne.reqCompteFormate();
	ASSERT_EQ(os.str(), client.reqReleves());
}

/**
 * \test Test de la méthode asgTelephone() <br>
 * 		Cas valide : Construction, vérifier l'assignation d'un nouveau numéro de téléphone à un objet Client <br>
 * 		Cas invalide : aucun
 */
TEST_F(unClient, asgTelephone)
{
	ASSERT_EQ("418 222-2222", client.reqTelephone());
	client.asgTelephone("581 333-3333");	// Après assignation
	ASSERT_EQ("581 333-3333", client.reqTelephone());
}

/**
 * \test Test de l'opérateur == surchargé <br>
 * 		Cas valide :
 * 			ComparateurEgaliteClientsIdentiques : Construction, les clients sont identiques <br>
 * 		Cas invalide :
 * 			Aucun
 */
TEST_F(unClient, ComparateurEgaliteClientsIdentiques)
{
	Client clientIdentique(5000, "Shakur", "Amaru", "418 222-2222",
			util::Date(16, 6, 1971));
	ASSERT_TRUE(client == clientIdentique);
}
/**
 * \test Test de l'opérateur == surchargé <br>
 * 		Cas valide :
 * 			ComparateurEgaliteClientsDistincts : Construction, les clients ne sont pas identiques <br>
 * 		Cas invalide :
 * 			Aucun
 */
TEST_F(unClient, ComparateurEgaliteClientsDistincts)
{
	Client clientDistinct(9999, "Shakur", "Amaru", "418 222-2222",
			util::Date(16, 6, 1971));
	ASSERT_FALSE(client == clientDistinct);
}

/**
 * \test Test de l'opérateur < surchargé <br>
 * 		Cas valide :
 * 			ComparateurInferioriteStricteClientSuperieurAuClientCourant : Construction, le client passé en paramètre a un numéro de folio superieur à celui du client courant <br>
 * 			ComparateurInferioriteStricteClientInferieurAuClientCourant : Construction, le client passé en paramètre a un numéro de folio inférieur à celui du client courant <br>
 * 			ComparateurInferioriteStricteNumerosDeFolioEgaux : Construction, les clients sont identiques <br>
 * 			Cas invalide :
 * 			Aucun
 */
TEST_F(unClient, ComparateurInferioriteStricte)
{
	Client autreClientSuperieur(6000, "Shakur", "Amaru", "418 222-2222",
			util::Date(16, 6, 1971));
	ASSERT_TRUE(client < autreClientSuperieur);
	Client autreClientInferieur(1000, "Shakur", "Amaru", "418 222-2222",
			util::Date(16, 6, 1971));
	ASSERT_FALSE(client < autreClientInferieur);
	Client autreClientEgal(5000, "Shakur", "Amaru", "418 222-2222",
			util::Date(16, 6, 1971));
	ASSERT_FALSE(client < autreClientEgal);
}

/**
 * \test Test de la méthode ajouterCompte <br>
 * 		Cas valide : Construction, vérifier l'ajout d'un compte à un client <br>
 * 		Cas invalide : Construction, compte déjà existant
 */
TEST_F(unClient, ajouterCompte)
{
	ostringstream os;
	ASSERT_EQ(client.reqClientFormate(), client.reqReleves());
	Cheque unCompteCheque(10001, 1.2, 500, 4, 0.3, "courant");
	client.ajouterCompte(unCompteCheque);	// Après ajout de compte
	os << client.reqClientFormate() << unCompteCheque.reqCompteFormate();
	ASSERT_EQ(os.str(), client.reqReleves());
	Epargne unCompteEpargne(10007, 1.25, 500, "voyage");
	client.ajouterCompte(unCompteEpargne);
	os << unCompteEpargne.reqCompteFormate();	// Après ajout de compte
	ASSERT_EQ(os.str(), client.reqReleves());
}

TEST_F(unClient, ajouterCompteDejaExistant)
{
	Cheque unCompteCheque(10001, 1.2, 500, 4, 0.3, "courant");
	client.ajouterCompte(unCompteCheque);
	ASSERT_THROW(client.ajouterCompte(unCompteCheque),
			CompteDejaPresentException);
}

/**
 * \test Test de la méthode supprimerCompte <br>
 * 		Cas valide : Construction, vérifier la suppression du compte d'un client <br>
 * 		Cas invalide : Construction, compte non existant
 */
//TEST_F(unClient, supprimerCompte)
//{
//	ostringstream os;
//	Epargne unCompteEpargne(10007, 1.25, 500, "voyage");
//	client.ajouterCompte(unCompteEpargne);
//			;	// Après ajout de compte
//	os << client.reqClientFormate() << unCompteEpargne.reqCompteFormate()
//			;	// talon de test par formatage
//	ASSERT_EQ(os.str(), client.reqReleves())
//			;	// comparaison
//	client.supprimerCompte(10007);
//	os.clear();
//	os << client.reqClientFormate();
//	ASSERT_EQ(os.str(), client.reqReleves())
//			;	// comparaison
//}
TEST_F(unClient, supprimerCompteInexistant)
{
	ASSERT_THROW(client.supprimerCompte(100), CompteAbsentException);
}
