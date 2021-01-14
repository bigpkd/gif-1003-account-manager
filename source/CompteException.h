/**
 * \file CompteException.h
 * \brief Fichier qui contient les interfaces des classes de gestion d'exceptions CompteException, CompteDejaPresentException, CompteAbsentException.
 * \author Pakendam Bigou-Laré, Marco André Eccheveria
 * \version 0.1
 * \date 18 avril 2018
 */

#ifndef COMPTEEXCEPTION_H_
#define COMPTEEXCEPTION_H_

#include <stdexcept>
#include "ContratException.h"

namespace banque {
/**
 * \class CompteException
 * \brief Classe de base des exceptions de compte.
 */
class CompteException: public std::runtime_error
{
public:
	CompteException(const std::string& p_raison);
	~CompteException() throw ()
	{
	}
private:
	std::string m_raison;
	void verifieInvariant() const;
};

/**
 * \class CompteDejaPresentException
 * \brief Classe de gestion des exceptions de comptes déjà présents.
 */
class CompteDejaPresentException: public CompteException
{
public:
	CompteDejaPresentException(const std::string& p_raison);
};

/**
 * \class CompteAbsentException
 * \brief Classe de gestion des exceptions de comptes absents.
 */
class CompteAbsentException: public CompteException
{
public:
	CompteAbsentException(const std::string& p_raison);
};

} /* namespace banque*/

#endif /* COMPTEEXCEPTION_H_ */
