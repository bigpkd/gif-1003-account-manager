/**
 * \file CompteChequeTesteur.cpp
 * \brief Fichier implémentant les tests de la classe Chèque dérivée de la classe Compte
 * \author: Pakendam Bigou-Laré
 * \version 0.1
 * \date 31 mars 2018
 */

#include <gtest/gtest.h>
#include "Cheque.h"
#include <sstream>

using namespace std;
using namespace banque;


/**
 * \test Test du constructeur Cheque(int , double , double ,
			int , double ,
			const std::string& )
		Cas valides : <br>
 *			Création d'un objet Cheque et test des assignations de deux attributs(les autres sont testées par le contrat de la classe Compte)
 *			Nombre de transactions positif et inférieur à 40
 *			Taux d'intérêt minimum inférieur au taux d'intérêt passé en paramètre
 */
TEST(Cheque, Constructeur)
{
	Cheque cheque0(12345, 1.2, -3000, 25, 0.3, "Mon compte courant");
	ASSERT_EQ(25, cheque0.reqNombreTransactions());
	ASSERT_EQ(1.2, cheque0.reqTauxInteret());
}

/**
 * \test Test du constructeur Cheque(int , double , double ,
			int , double ,
			const std::string& )
 *
 *		Cas invalide : Nombre de transactions supérieur à 40
 */
TEST(Cheque, ConstructeurNombreDeTransactionsInvalide){
	ASSERT_THROW(Cheque cheque1(12345, 1.2, -3000, 45, 0.3, "Mon compte courant"), PreconditionException);
}

/**
 * \test Test du constructeur Cheque(int , double , double ,
			int , double ,
			const std::string& )
 *
 *		Cas invalide : Taux d'intérêt minimum supérieur au taux d'intérêt passé en paramètre
 */
TEST(Cheque, ConstructeurTauxInteretMinimumInvalide){
	ASSERT_THROW(Cheque cheque2(12345, 0.01, -3000, 4, 0.1, "Mon compte courant"), PreconditionException);
}

/**
 * \class unCheque
 * \brief Fixture pour la création d'un objet Cheque à utiliser
 */
class unCheque: public ::testing::Test
{
public:
	unCheque() :
			cheque(12345, 1.2, -3000, 4, 0.3, "Mon compte courant")
	{
	}
	Cheque cheque;
	util::Date dateTest;
};

/**
 * \test Test de la méthode clone() <br>
 * 		Cas valide : Construction, vérifier la conformité de la copie de l'objet Cheque retournée <br>
 * 		Cas invalide : aucun
 */
TEST_F(unCheque, clone)
{
	ASSERT_EQ(cheque.reqNoCompte() , cheque.clone()->reqNoCompte());
	ASSERT_EQ(cheque.reqDescription() , cheque.clone()->reqDescription());
	ASSERT_EQ(cheque.reqSolde() , cheque.clone()->reqSolde());
	ASSERT_EQ(cheque.reqTauxInteret() , cheque.clone()->reqTauxInteret());
	ASSERT_EQ(cheque.reqDateOuverture() , cheque.clone()->reqDateOuverture());
//	ASSERT_EQ(cheque.reqNombreTransactions() , cheque.clone()->reqNombreTransactions());		//NE MARCHE PAS, clone retourne une adresse, un pointeur
	ASSERT_EQ(cheque.reqNombreTransactions(), ((Cheque *)cheque.clone())->reqNombreTransactions());
	ASSERT_EQ(cheque.reqTauxInteretMinimum() , ((Cheque *)cheque.clone())->reqTauxInteretMinimum());
	ASSERT_FALSE(&cheque == cheque.clone());
}

/**
 * \test Test de la méthode reqCompteFormate() <br>
 * 		Cas valide : Construction, vérifier le retour des informations du compte(objet Cheque) <br>
 * 		Cas invalide : aucun
 */
TEST_F(unCheque, reqCompteFormate){
	ostringstream os;
	os << "\t Compte Cheque" << endl;
	os << "\t numero " << "\t\t : " << 12345 << endl
		<< "\t Description " << "\t\t : " << "Mon compte courant" << endl
		<< "\t Date d'ouverture " << "\t : " << dateTest.reqDateFormatee() << endl
		<< "\t Taux d'interet " << "\t : " << 1.2 << endl
		<< "\t Solde " << "\t\t\t : " << -3000 << " $" << endl;
	os << "\t nombre de transactions" << "\t : " << 4 << endl
		<< "\t Taux d'interet minimum" << "\t : " << 0.3 << endl;
	os << "\t Interet" << "\t\t : " << 9.0 << " $" << endl;
	ASSERT_EQ(os.str() , cheque.reqCompteFormate());
}

/**
 * \test Test de la méthode calculerInteret() <br>
 * 		Cas valide : Construction, vérifier le retour du calcul de l'intérêt du compte(objet Cheque) <br>
 * 		Cas invalide : aucun
 */
TEST_F(unCheque, calculerInteret){
	ASSERT_EQ(9, cheque.calculerInteret());
}

/**
 * \test Test de la méthode reqTauxInteretMinimum() <br>
 * 		Cas valide : Construction, vérifier le retour des informations du compte(objet Cheque) <br>
 * 		Cas invalide : aucun
 */
TEST_F(unCheque, reqTauxInteretMinimum){
	ASSERT_EQ(0.3 , cheque.reqTauxInteretMinimum());
}

/**
 * \test Test de la méthode reqNombreTransactions() <br>
 * 		Cas valide : Construction, vérifier le retour du nombre de transactions du compte(objet Cheque) <br>
 * 		Cas invalide : aucun
 */
TEST_F(unCheque, reqNombreTransactions){
	ASSERT_EQ(4 , cheque.reqNombreTransactions());
}

/**
 * \test Test de la méthode asgNombreTransactions() <br>
 * 		Cas valide : Construction, vérifier l'assignation d'un nouveau nombre de transaction à un compte(objet Cheque) <br>
 * 		Cas invalide : aucun
 */
TEST_F(unCheque, asgNombreTransactions){
	ASSERT_EQ(4 , cheque.reqNombreTransactions())
			;
	cheque.asgNombreTransactions(19)
			;	//	Après assignation
	ASSERT_EQ(19, cheque.reqNombreTransactions())
			;
}
