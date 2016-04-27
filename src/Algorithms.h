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

/**
 * Sets all paths to null and resets vertex visits
 * @param grafo Graph to be reseted
 */

void prepareGraph(Graph<Localizacao> &grafo);

/**
 * Applies nearestNeighbour algorithm to a bus
 * \param grafo Grafo to have it's paths set
 * \param bus Bus to run through the path
 */

void nearestNeighbourBus(Graph<Localizacao> &grafo, Autocarro &b);

/**
 * Applies nearestNeighbour algorithm but uses a bus with infinity capacity
 * \param grafo Grafo to have it's paths set
 * \param bus Bus to run through the path
 */

void nearestNeighbourSuperBus(Graph<Localizacao> &grafo, Autocarro &b);

#endif /* SRC_ALGORITHMS_H_ */
