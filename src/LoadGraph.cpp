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


bool LoadGraph::loadLocalizacaos(Graph<Localizacao> &grafo) {
	ifstream fLocalizacaos;
	fLocalizacaos.open("resources/Localizacaos.txt");
	if (!fLocalizacaos.is_open()) {
		cerr << "Erro abrir ficheiro Localizacaos";
		return false;
 	}
unsigned int id;
string s, rua, nome;
	stringstream ss;
	getline(fLocalizacaos, s);
	ss << s;
	ss >> id;
 	Localizacao::setNextId(id);


	while (!fLocalizacaos.eof()) {
		getline(fLocalizacaos, s, ',');
		stringstream(s) >> id;


		getline(fLocalizacaos, nome, ',');
		getline(fLocalizacaos, rua);


	grafo.addVertex(
			*new Localizacao(nome, id, rua));

  	}


	return true;


}


bool LoadGraph::loadAdjacentes(Graph<Localizacao> &grafo) {
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


 		grafo.addEdge(Localizacao("tempName1",idV1, "tempVertex1"),
				Localizacao("tempName2",idV2, "tempVertex2"), peso,0);


 	}
	return true;
}
