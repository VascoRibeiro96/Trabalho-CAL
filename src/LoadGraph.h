/*
 * LoadGraph.h
 *
 *  Created on: 26/04/2016
 *      Author: Asus
 */


#ifndef LOADGRAPH_H_
#define LOADGRAPH_H_

#include <vector>
#include "Graph.h"
#include "Autocarro.h"
#include "Localizacao.h"


using namespace std;


class LoadGraph {
public:

	/**
	 * Loads Vertices from text file to the graph
	 * \param grafo Graph to be altered
	 */

 bool loadLocalizacaos(Graph<Localizacao> &grafo);

 /**
 	 * Loads Edges from text file to the graph
 	 * \param grafo Graph to be altered
 	 */

 bool loadAdjacentes(Graph<Localizacao> &grafo);




};


#endif /* LOADGRAPH_H_ */
