/**
 * \file validationFormat.cpp
 * \brief Fichier qui contient des fonctions de validations de nom, de numéro de téléphone et de fichier.
 * \author Pakendam Bigou-Laré
 * \version 0.3
 * \date 1er mars 2018
 * */

#include <iostream>
#include <sstream>
#include <fstream>
#include "validationFormat.h"

using namespace std;

namespace util
{
/**
 * \brief retourne un booléen (bool) qui confirme ou infirme que la chaîne de caractères (string) passée en paramètre est un nom valide
 * \param[in] p_nom est un chaîne de caractères (string)
 * \return un booléen (bool) indiquant si la chaîne de caractères (string) passée en paramètre est un nom valide
 */
bool validerFormatNom(const std::string& p_nom)
{
	string test = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int longueurTest = test.length();
	int longueurNom = p_nom.length();
	int valeurTest = 0;

	for (int i = 0; i < longueurNom; i++)
	{
		for (int j = 0; j < longueurTest; j++)
		{
			if (p_nom[i] == test[j])
			{
				valeurTest += 1; //la valeur test est incrémentée si une lettre ou un espace est rencontré
			}
		}
	}

	return (valeurTest == longueurNom); //retourne 1 = (1==0) = false si le nom ne contient aucun chiffre
}

/**
 * \brief retourne un booléen (bool) qui confirme ou infirme que la chaîne de caractères (string) passée en paramètre est un numéro de téléphone canadien valide
 * \param[in] p_telephone est un chaîne de caractères (string)
 * \return un booléen (bool) indiquant si la chaîne de caractères (string) passée en paramètre est un numéro de téléphone canadien valide
 */
bool validerTelephone(const std::string& p_telephone)
{
	string formatNational = "XXX CCC-CCCC";
	const int LONGUEURFORMAT = formatNational.length();

	string test = "0123456789 -";
	const int LONGUEURTEST = test.length();

	const int NOMBRECODESVALIDES = 32;
	int codesRegionaux[NOMBRECODESVALIDES] =
	{ 403, 780, 604, 236, 250, 778, 902, 204, 506, 905, 519, 289, 705, 613, 807,
			416, 647, 438, 514, 450, 579, 418, 581, 819, 306, 709, 867, 800,
			866, 877, 888, 855 };

	int longueurNumero = p_telephone.length();
	bool valeurTest;

	if (!(longueurNumero == LONGUEURFORMAT)
			|| !(p_telephone.substr(3, 1) == " ")
			|| !(p_telephone.substr(7, 1) == "-"))
	{
		valeurTest = false;
	}
	else
	{
		int count = 0;
		int testCodes = 0;

		for (int i = 0; i < longueurNumero; i++)
		{
			for (int j = 0; j < LONGUEURTEST; j++)
			{
				if ((p_telephone[i] == test[j]))
				{
					count += 1;
				}
			}
		}
		valeurTest = (count == longueurNumero);

		if (valeurTest == true)
		{
			for (int i = 0; i < NOMBRECODESVALIDES; i++)
			{
				stringstream ss;
				ss << codesRegionaux[i];
				if ((ss.str() == p_telephone.substr(0, 3))
						|| (p_telephone.substr(0, 1) == "9"))
				{
					testCodes = 1;
				}
			}
			valeurTest = (testCodes == 1);
		}
	}

	return valeurTest;
}

/**
 * \brief retourne un booléen (bool) qui confirme ou infirme que le fichier (ifstream) passé en paramètre est un fichier valide selon certains critères
 * \param[in] p_is est un fichier (ifstream)
 * \return un booléen (bool) indiquant si fichier (ifstream) passé en paramètre est un fichier valide selon certains critères
 */
bool validerFormatFichier(std::istream& p_is)
{
	string chaine = "";
	char buffer[256];
	while (p_is.getline(buffer, 255))
	{
		chaine.append(buffer);
		chaine.append(" ");
	}

	istringstream is_chaine(chaine);
	string nom = "";
	is_chaine >> nom;

	string prenom = "";
	is_chaine >> prenom;

	string dateNaissance = "";
	int jour = 0;
	int mois = 0;
	int annee = 0;
	bool validationDate = true;
	is_chaine >> jour >> mois >> annee;
	if (jour == 0 || mois == 0 || annee == 0)
	{
		validationDate &= false;
	}
	else
	{
		validationDate &= true;
		stringstream ss;
		ss << jour << " " << mois << " " << annee;
		dateNaissance = ss.str();
	}

	string telephone = "";
	string codeRegion = "";
	string numLocal = "";
	is_chaine >> codeRegion;
	is_chaine >> numLocal;
	telephone.append(codeRegion);
	telephone.append(" ");
	telephone.append(numLocal);

	int numeroFolio = 0;
	is_chaine >> numeroFolio;

	string typeCompte = "";
	string donneeTypeCompte = "";
	bool validationTypeCompte = true;

	int nombreTransactions = 0;
	float tauxInteretMinimum = 0.0;
	string dateEcheance = "";

	while (validationTypeCompte == true)
	{
		donneeTypeCompte = "";
		is_chaine >> donneeTypeCompte;
		if (!(donneeTypeCompte == "cheque") && !(donneeTypeCompte == "epargne")
				&& !(donneeTypeCompte == ""))
		{
			validationTypeCompte &= false;
		}
		else
		{
			if (donneeTypeCompte == "")
			{
				//validationTypeCompte = true;
				break;
			}
			validationTypeCompte &= true;
			typeCompte = donneeTypeCompte;

			int numeroCompte = 0;
			is_chaine >> numeroCompte;

			float tauxInteret = 0.0;
			is_chaine >> tauxInteret;

			float solde = 0.0;
			is_chaine >> solde;

			string description = "";
			is_chaine >> description;

			if (validationTypeCompte)
			{
				if (donneeTypeCompte == "cheque")
				{
					is_chaine >> nombreTransactions;
					is_chaine >> tauxInteretMinimum;
				}
				if (donneeTypeCompte == "epargne")
				{
					string jour = "";
					string mois = "";
					string annee = "";
					is_chaine >> jour >> mois >> annee;
					dateEcheance.append(jour);
					dateEcheance.append(" ");
					dateEcheance.append(mois);
					dateEcheance.append(" ");
					dateEcheance.append(annee);
				}

			}
		}
	}

	return validerFormatNom(nom) && validerFormatNom(prenom) && validationDate
			&& validerTelephone(telephone) && validationTypeCompte;

}	// namespace util

}
