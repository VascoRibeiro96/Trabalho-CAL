/*
 * algorithms.h
 *
 *  Created on: 27/04/2016
 *      Author: Tiago
 */

#ifndef SRC_ALGORITHMS_H_
#define SRC_ALGORITHMS_H_

#include "Graph.h"
#include "Autocarro.h"

void prepareGraph(Graph<Localizacao> &grafo);
void nearestNeighbourBus(Graph<Localizacao> &grafo, Autocarro &b);
void nearestNeighbourSuperBus(Graph<Localizacao> &grafo, Autocarro &b);

#endif /* SRC_ALGORITHMS_H_ */
