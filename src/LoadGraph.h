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
 bool loadLocalizacaos(Graph<Localizacao> &grafo);
 bool loadAdjacentes(Graph<Localizacao> &grafo);




};


#endif /* LOADGRAPH_H_ */
