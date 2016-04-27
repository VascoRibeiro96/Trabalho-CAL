/*
 * Crian�a.h
 *
 *  Created on: 19/04/2016
 *      Author: ASUS
 */
#ifndef SRC_CRIAN�A_H_
#define SRC_CRIAN�A_H_

#include <string>

using namespace std;


class Localizacao{
private:
	string nome;
	static unsigned int nextId;
	unsigned int id;
	string rua;
public:
	Localizacao();
	Localizacao(string nome, unsigned int id, string rua);
	string getNome() const;
	void setNome(string nome);
	unsigned int getId() const;
	void setId(unsigned int id);
	static unsigned int getNextId();
	static void setNextId(unsigned int nextId);
	string getRua() const;
	void setRua(string rua);


	bool operator==(const Localizacao &c1) const;
};



#endif /* SRC_CRIAN�A_H_ */
