/**
 * \file validationFormat.h
 * \brief Fichier qui contient l'interface du fichier validationFormat.cpp qui contient des fonctions de validations.
 * \author Pakendam Bigou-Laré
 * \version 0.3
 * \date 1er mars 2018
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_

namespace util
{

bool validerFormatNom(const std::string& p_nom);
bool validerTelephone(const std::string& p_telephone);
bool validerFormatFichier(std::istream& p_is);

} // namespace util

#endif /* VALIDATIONFORMAT_H_ */
