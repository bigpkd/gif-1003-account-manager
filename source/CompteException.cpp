/**
 * \file CompteException.cpp
 * \brief Implantation des classes de gestion d'exceptions CompteException, CompteDejaPresentException, CompteAbsentException.
 * \author Pakendam Bigou-Laré, Marco André Eccheveria
 * \version 0.1
 * \date 18 avril 2018
 */

#include "CompteException.h"

using namespace std;
namespace banque {
/**
 * \brief Constructeur de la classe de base CompteException.
 * \param[in] p_raison est une chaîne de caractères donnant l'origine de l'exception.
 */
CompteException::CompteException(const string& p_raison):
		runtime_error(p_raison), m_raison(p_raison)
{
	PRECONDITION(!(p_raison.empty()));
	POSTCONDITION(m_raison == p_raison);
	INVARIANTS();
}
/**
 * \brief Constructeur de la classe CompteException.
 * \param[in] p_raison Message d'erreur signalant l'absence du compte.
 */
CompteAbsentException::CompteAbsentException(const string& p_raison):
		CompteException(p_raison)
{

}
/**
 * \brief Constructeur de la classe CompteDejaPresentException.
 * \param[in] p_raison Message d'erreur signalant un doublon.
 */
CompteDejaPresentException::CompteDejaPresentException(const string& p_raison):
		CompteException(p_raison)
{

}
/**
 * \brief vérifie les invariants de la classe de base CompteException
 */
void CompteException::verifieInvariant() const
{
	INVARIANT(!(m_raison.empty()));
}

} /* namespace banque*/
