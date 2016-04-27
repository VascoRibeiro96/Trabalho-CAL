/*
 * Empresa.h
 *
 *  Created on: 25/04/2016
 *      Author: ASUS
 */

#ifndef SRC_EMPRESA_H_
#define SRC_EMPRESA_H_

#include "Autocarro.h"
#include "Crianca.h"
#include "Graph.h"
#include "GraphViewer.h"

class Empresa
{
private:
	GraphViewer *gv;
	Graph<int> graph;
	vector<Autocarro *> autocarros;
	vector<Escola *> escolas;
public:
	Empresa();
	Empresa(const Graph<int> &graph);
	vector<Autocarro *> getAutocarros() const;
	void addAutocarro(Autocarro * a1);
	void removeAutocarro(Autocarro * a1);
	Autocarro* getAutocarroById(int id)const;
	vector<Escola *> getEscolas() const;
	Escola* getEscolaByName(string nomeEscola)const;
	void addEscola(Escola *e1);
	void removeEscola(string nomeEsc);
	Graph<int> getGraph() const;
};



#endif /* SRC_EMPRESA_H_ */
