/**
 * \file CompteTesteur.cpp
 * \brief Fichier implémentant les tests de la classe Compte
 * \author: Pakendam Bigou-Laré
 * \version 0.1
 * \date 31 mars 2018
 */

#include <gtest/gtest.h>
#include "Compte.h"
#include <sstream>

using namespace std;
using namespace banque;

/**
 * \class CompteDeTest
 * \brief Classe dérivée permettant d'instancier un objet concret de la classe abstraite Compte
 */
class CompteDeTest: public Compte
{
public:
	CompteDeTest(int p_noCompte, double p_tauxInteret, double p_solde,
			const std::string& p_description) :
			Compte(p_noCompte, p_tauxInteret, p_solde, p_description)
	{
	};
	virtual double calculerInteret() const
	{
		return (double)0.0;
	};
	virtual Compte* clone() const
	{
		return new CompteDeTest(*this);
	};
};

/**
 * \class unCompte
 * \brief Fixture pour la création d'un objet Compte à utiliser pour tester les méthodes publiques de la classe Compte
 */
class unCompte: public ::testing::Test
{
public:
	unCompte() :
			compte(12345, 0.2, 3000, "compte courant")
	{
	}
	CompteDeTest compte;
	util::Date dateTest;
};

/**
 * \test Test du constructeur Compte::Compte(int , double , double ,
 const std::string& )
 *
 * 		Cas valides :
 * 			Création d'un objet Compte et test de l'assignation de tous les attributs
 * 			Numéro de compte entier et positif
 * 			Description non vide
 * 			Date d'ouverture correspondant à la date de création du compte
 */
TEST_F(unCompte, Constructeur)
{
	ASSERT_EQ(12345, compte.reqNoCompte());
	ASSERT_EQ(0.2, compte.reqTauxInteret());
	ASSERT_EQ(3000, compte.reqSolde());
	ASSERT_EQ("compte courant", compte.reqDescription());
	ASSERT_EQ(dateTest, compte.reqDateOuverture());
}

/**
 * \test Test du constructeur Compte::Compte(int , double , double ,
 const std::string& )

 * 		Cas invalide : Numéro de compte entier mais négatif
 */
TEST(CompteDeTest, ConstructeurAvecNombreDeCompteNegatif)
{
	ASSERT_THROW(CompteDeTest compte(-1, 0.2, 3000, "compte courant"), PreconditionException);
}

/**
 * \test Test du constructeur Compte::Compte(int , double , double ,
 const std::string& )

 * 		Cas invalide : Taux d'intérêt négatif
 */
TEST(CompteDeTest, ConstructeurAvecTauxdInteretNegatif)
{
	ASSERT_THROW(CompteDeTest compte(12345, -0.2, 3000, "compte courant"), PreconditionException);
}

/**
 * \test Test du constructeur Compte::Compte(int , double , double ,
 const std::string& )

 * 		Cas invalide : Description vide
 */
TEST(CompteDeTest, ConstructeurAvecDescriptionVide)
{
	ASSERT_THROW(CompteDeTest compte(12345, 0.2, 3000, ""), PreconditionException);
}


/**
 * \test Test de la méthode clone() <br>
 * 		Cas valide : Construction, vérifier le retour d'une copie de l'objet Compte courant <br>
 * 		Cas invalide : aucun
 */
TEST_F(unCompte, clone)
{
	ASSERT_EQ(compte.reqNoCompte(), compte.clone()->reqNoCompte());
	ASSERT_EQ(compte.reqDescription(), compte.clone()->reqDescription());
	ASSERT_EQ(compte.reqSolde(), compte.clone()->reqSolde());
	ASSERT_EQ(compte.reqTauxInteret(), compte.clone()->reqTauxInteret());
	ASSERT_EQ(compte.reqDateOuverture(), compte.clone()->reqDateOuverture());
	ASSERT_FALSE(&compte == compte.clone());

}

/**
 * \test Test de la méthode reqCompteFormate() <br>
 * 		Cas valide : Construction, vérifier le retour des informations formatées d'un objet Compte <br>
 * 		Cas invalide : aucun
 */
TEST_F(unCompte, reqCompteFormate)
{
	util::Date dateTest;
	ostringstream os;
	os << "\t numero " << "\t\t : " << 12345 << endl
			<< "\t Description " << "\t\t : " << "compte courant" << endl
			<< "\t Date d'ouverture " << "\t : " << dateTest.reqDateFormatee()
			<< endl << "\t Taux d'interet " << "\t : " << 0.2 << endl << "\t Solde "
			<< "\t\t\t : " << 3000 << " $" << endl;
	ASSERT_EQ(os.str(), compte.reqCompteFormate());
}

/**
 * \test Test de la méthode calculerInteret() <br>
 * 		Cas valide : Construction, vérifier le retour de l'intérêt calculé(aucun calcul n'est ici effectué, la méthode n'est en réalité pas implémentée dans la classe Compte) <br>
 * 		Cas invalide : aucun
 */
TEST_F(unCompte, calculerInteret)
{
	ASSERT_EQ(0.0, compte.calculerInteret());
}

/**
 * \test Test de la méthode reqNoCompte() <br>
 * 		Cas valide : Construction, vérifier le retour du numéro de compte d'un objet Compte <br>
 * 		Cas invalide : aucun
 */
TEST_F(unCompte, reqNoCompte)
{
	ASSERT_EQ(12345, compte.reqNoCompte());
}

/**
 * \test Test de la méthode reqTauxInteret() <br>
 * 		Cas valide : Construction, vérifier le retour du taux d'intérêt d'un objet Compte <br>
 * 		Cas invalide : aucun
 */
TEST_F(unCompte, reqTauxInteret)
{
	ASSERT_EQ(0.2, compte.reqTauxInteret());
}

/**
 * \test Test de la méthode reqSolde() <br>
 * 		Cas valide : Construction, vérifier le retour du solde d'un objet Compte <br>
 * 		Cas invalide : aucun
 */
TEST_F(unCompte, reqSolde)
{
	ASSERT_EQ(3000, compte.reqSolde());
}

/**
 * \test Test de la méthode reqDescription() <br>
 * 		Cas valide : Construction, vérifier le retour de la description d'un objet Compte <br>
 * 		Cas invalide : aucun
 */
TEST_F(unCompte, reqDescription)
{
	ASSERT_EQ("compte courant", compte.reqDescription());
}

/**
 * \test Test de la méthode reqDateOuverture() <br>
 * 		Cas valide : Construction, vérifier le retour de la date d'ouverture d'un objet Compte <br>
 * 		Cas invalide : aucun
 */
TEST_F(unCompte, reqDateOuverture)
{
	ASSERT_EQ(dateTest, compte.reqDateOuverture());
}

/**
 * \test Test de la méthode asgTauxInteret() <br>
 * 		Cas valide : Construction, vérifier l'assignation d'un nouveau taux d'intérêt à un objet Compte <br>
 * 		Cas invalide : aucun
 */
TEST_F(unCompte, asgTauxInteret)
{
	ASSERT_EQ(0.2, compte.reqTauxInteret());
	compte.asgTauxInteret(3.5)
	;		// Après assignation
	ASSERT_EQ(3.5, compte.reqTauxInteret())
	;
}

/**
 * \test Test de la méthode asgSolde() <br>
 * 		Cas valide : Construction, vérifier l'assignation d'un nouveau solde à un objet Compte <br>
 * 		Cas invalide : aucun
 */
TEST_F(unCompte, asgSolde)
{
	ASSERT_EQ(3000, compte.reqSolde())
	;
	compte.asgSolde(1111)
	;		// Après assignation
	ASSERT_EQ(1111, compte.reqSolde())
	;
}

/**
 * \test Test de la méthode asgDescription() <br>
 * 		Cas valide : Construction, vérifier l'assignation d'une nouvelle description à un objet Compte <br>
 * 		Cas invalide : aucun
 */
TEST_F(unCompte, asgDescription)
{
	ASSERT_EQ("compte courant", compte.reqDescription())
	;
	compte.asgDescription("compte indivis")
	;		// Après assignation
	ASSERT_EQ("compte indivis", compte.reqDescription())
	;
}
