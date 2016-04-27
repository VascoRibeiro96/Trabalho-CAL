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

void prepareGraph(Graph<Crianca> &grafo);
void nearestNeighbourBus(Graph<Crianca> &grafo, Autocarro &b);
void nearestNeighbourSuperBus(Graph<Crianca> &grafo, Autocarro &b);

#endif /* SRC_ALGORITHMS_H_ */
