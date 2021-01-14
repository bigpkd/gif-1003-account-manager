/**
 * \file CompteEpargneTesteur.cpp
 * \brief Fichier implémentant les tests de la classe Epargne dérivée de la classe Compte
 * \author: Pakendam Bigou-Laré
 * \version 0.1
 * \date 31 mars 2018
 */

#include <gtest/gtest.h>
#include "Epargne.h"
#include <sstream>

using namespace std;
using namespace banque;


/**
 * \test Test du constructeur Epargne::Epargne(int , double , double ,
 const std::string& )
 *
 * 		Cas valides : testés par le contrat de la classe compte
 */

/**
 * \test Test du constructeur Epargne::Epargne(int , double , double ,
 const std::string& )
 *
 * 		Cas invalide : Construction, taux d'intérêt strictement inférieur à 0.1 ou strictement supérieur 3.5
 */
TEST(Epargne, ConstructeurAvecTauxdInteretInvalide)
{
	ASSERT_THROW(Epargne uneEpargne(1235, 0.05, 200, "Etudes"), PreconditionException);
	ASSERT_THROW(Epargne uneEpargne(1235, -2.5, 200, "Etudes"), PreconditionException);
	ASSERT_THROW(Epargne uneEpargne(1235, 4, 200, "Etudes"), PreconditionException);
}

/**
 * \test Test du constructeur Epargne::Epargne(int , double , double ,
 const std::string& )
 *
 * 		Cas invalide : Construction, solde négatif
 */
TEST(Epargne, ConstructeurAvecSoldeInvalide)
{
	ASSERT_THROW(Epargne uneEpargne(1235, 0.2, -200, "Etudes"), PreconditionException);
}

/**
 * \class uneEpargne
 * \brief Fixture pour la création d'un objet Epargne à utiliser pour tester les méthodes publiques de la classe Epargne
 */
class uneEpargne: public ::testing::Test
{
public:
	uneEpargne() :
		epargne(12345, 0.3, 3000, "Etudes")
	{}
	Epargne epargne;
};

/**
 * \test Test de la méthode clone() <br>
 * 		Cas valide : Construction, vérifier la conformité de la copie de l'objet Epargne retournée <br>
 * 		Cas invalide : aucun
 */
TEST_F(uneEpargne, clone)
{
	ASSERT_EQ(epargne.reqNoCompte() , epargne.clone()->reqNoCompte());
	ASSERT_EQ(epargne.reqDescription() , epargne.clone()->reqDescription());
	ASSERT_EQ(epargne.reqSolde() , epargne.clone()->reqSolde());
	ASSERT_EQ(epargne.reqTauxInteret() , epargne.clone()->reqTauxInteret());
	ASSERT_EQ(epargne.reqDateOuverture() , epargne.clone()->reqDateOuverture());
	ASSERT_FALSE(&epargne == epargne.clone());
}

/**
 * \test Test de la méthode reqCompteFormate() <br>
 * 		Cas valide : Construction, vérifier le retour des informations formatées d'un objet Cheque <br>
 * 		Cas invalide : aucun
 */
TEST_F(uneEpargne, reqCompteFormate)
{
	util::Date dateTest;
	ostringstream os;
		os << "\t Compte Epargne" << endl;
		os << "\t numero " << "\t\t : " << 12345 << endl
			<< "\t Description " << "\t\t : " << "Etudes" << endl
			<< "\t Date d'ouverture " << "\t : " << dateTest.reqDateFormatee() << endl
			<< "\t Taux d'interet " << "\t : " << 0.3 << endl
			<< "\t Solde " << "\t\t\t : " << 3000 << " $" << endl;
		os << "\t Interet" << "\t\t : " << 9.0 << "$" << endl;
		ASSERT_EQ(os.str(), epargne.reqCompteFormate());
}

/**
 * \test Test de la méthode calculerInteret() <br>
 * 		Cas valide : Construction, vérifier le retour du calcul de l'intérêt d'un objet Cheque <br>
 * 		Cas invalide : aucun
 */
TEST_F(uneEpargne, calculerInteret)
{
	ASSERT_EQ(9.0, epargne.calculerInteret());
}
