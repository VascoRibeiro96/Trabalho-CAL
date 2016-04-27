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
#include "Crianca.h"


using namespace std;


class LoadGraph {
public:
 bool loadCriancas(Graph<Crianca> &grafo);
 bool loadAdjacentes(Graph<Crianca> &grafo);




};


#endif /* LOADGRAPH_H_ */
