/*
 * LoadGraph.cpp
 *
 *  Created on: 26/04/2016
 *      Author: Vasco
 */



#include "LoadGraph.h"
#include <sstream>
#include <fstream>
#include <string>


bool LoadGraph::loadCriancas(Graph<Crianca> &grafo) {
	ifstream fcriancas;
	fcriancas.open("resources/criancas.txt");
	if (!fcriancas.is_open()) {
		cerr << "Erro abrir ficheiro Criancas";
		return false;
 	}
unsigned int id;
string s, rua, nome;
	stringstream ss;
	getline(fcriancas, s);
	ss << s;
	ss >> id;
 	Crianca::setNextId(id);


	while (!fcriancas.eof()) {
		getline(fcriancas, s, ',');
		stringstream(s) >> id;


		getline(fcriancas, nome, ',');
		getline(fcriancas, rua);


	grafo.addVertex(
			*new Crianca(nome, id, rua));

  	}


	return true;


}


bool LoadGraph::loadAdjacentes(Graph<Crianca> &grafo) {
	ifstream fadj;
	fadj.open("resources/adj.txt");
if (!fadj.is_open()) {
	cerr << "Erro abrir ficheiro Adjacentes";
		return false;
	}
	unsigned int idV1, idV2, peso;
	string s;


	while (!fadj.eof()) {
		getline(fadj, s, ',');
		stringstream(s) >> idV1;


		getline(fadj, s, ',');
		stringstream(s) >> idV2;


	getline(fadj, s);
	stringstream(s) >> peso;


 		grafo.addEdge(Crianca("tempName1",idV1, "tempVertex1"),
				Crianca("tempName2",idV2, "tempVertex2"), peso,0);


 	}
	return true;
}
