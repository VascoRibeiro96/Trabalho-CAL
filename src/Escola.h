/*
 * Escola.h
 *
 *  Created on: 19/04/2016
 *      Author: ASUS
 */
#ifndef SRC_ESCOLA_H_
#define SRC_ESCOLA_H_

#include <string>

using namespace std;


class Escola{
private:
	string nome;
	static unsigned int nextId;
	unsigned int id;
	string rua;
public:
	Escola();
	Escola(string nome, unsigned int id, string rua);
	string getNome() const;
	void setNome(string nome);
	unsigned int getId() const;
	void setId(unsigned int id);
	static unsigned int getNextId();
	static void setNextId(unsigned int nextId);
	string getRua() const;
	void setRua(string rua);


	bool operator==(const Escola &c1) const;
};



#endif /* SRC_CRIANÇA_H_ */
