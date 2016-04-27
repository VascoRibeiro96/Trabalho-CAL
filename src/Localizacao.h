/*
 * Localizacao.h
 *
 *  Created on: 19/04/2016
 *      Author: ASUS
 */
#ifndef SRC_LOCALIZACAO_H_
#define SRC_LOCALIZACAO_H_

#include <string>

using namespace std;

/**
 * Class where the Localizacao that is set in the Graph.
 */
class Localizacao{
private:
	string nome;
	static unsigned int nextId;
	unsigned int id;
	string rua;
public:
	/**
	 * \brief Default Constructor with no arguments
	 */
	Localizacao();
	/**
	 * 	\brief Default Constructor for Localizacao
	 *  \param nome Localizacao's nome
	 *  \param id Localizacao's id
	 *  \param rua Localizacao's rua
	 */
	Localizacao(string nome, unsigned int id, string rua);
	/**
	 * \return Localizacao's nome
	 */
	string getNome() const;
	/**
	 *  \brief Change the Localizacao's nome
	 *  \param id New nome
	*/
	void setNome(string nome);
	/**
	*  \return Localizacao's ID
	*
	*/
	unsigned int getId() const;
	/**
	*  \brief Change the Localizacao's ID
	*  \param id New ID
	*/
	void setId(unsigned int id);
	/**
	*  \return Localizacao's next ID
	*/
	static unsigned int getNextId();
	/**
	*  \brief Change the Localizacao's next ID
	*  \param nextId New next ID
	*/
	static void setNextId(unsigned int nextId);
	/**
	 *  \return Localizacao's rua
	 */
	string getRua() const;
	/**
	 * \brief Change the Localizacao's rua
	 * \param rua New rua
	 */
	void setRua(string rua);


	bool operator==(const Localizacao &c1) const;
};



#endif /* SRC_LOCALIZACAO_H_ */
