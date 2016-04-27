/*
 * Autocarro.h
 *
 *  Created on: 19/04/2016
 *      Author: ASUS
 */

#ifndef SRC_AUTOCARRO_H_
#define SRC_AUTOCARRO_H_

#include <vector>
#include "Crianca.h"
#include "Graph.h"
#include "Escola.h"

using namespace std;

class Autocarro{
private:
	static int capMax;
	static unsigned int nextId;
	unsigned int id;
	unsigned int distanciaPercorrida;
	vector<Crianca> criancas;
	Escola * escola;
public:
	Autocarro();
	Autocarro(unsigned int id);
	unsigned int getId() const;
	void setId(unsigned int id);
	unsigned int getCapAtual() const;
	unsigned int getCapMax() const;
	void setCapMax(unsigned int capMax);
	static unsigned int getNextId();
	static void setNextId(unsigned int nextId);
	vector<Crianca> getCriancas() const;
	void addCrianca(Crianca c1);
	void removeCrianca(Crianca c1);
	void addDist(unsigned int d);
	unsigned int getDist() const;
	void calcRotaAutocarro(Graph<Crianca> &grafo);
	void print();
	bool operator==(const Autocarro a1) const;
};


#endif /* SRC_AUTOCARRO_H_ */
