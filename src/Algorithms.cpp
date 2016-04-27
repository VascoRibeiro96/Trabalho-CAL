/*
 * Algorithms.cpp
 *
 *  Created on: 27/04/2016
 *      Author: Tiago
 */

#include "Algorithms.h"
#include <vector>


/**
 * Sets all paths to null and resets vertex visits
 * @param grafo Graph to be reseted
 */

void prepareGraph(Graph<Crianca> &grafo)
{

	for (unsigned int i = 0; i < grafo.getNumVertex(); i++) {
		grafo.getVertexSet()[i]->path = NULL;
	}

	for (unsigned int i = 0; i < grafo.getNumVertex(); i++) {
		grafo.getVertexSet()[i]->setVisited(false);
	}

}

void nearestNeighbourBus(Graph<Crianca> &grafo, Autocarro &b)
{

	Vertex<Crianca>* actual = grafo.getVertexSet()[0];


	Vertex<Crianca>* proximo;
	actual->setVisited(true);
	int pesoMin = -1;

	for(int i = 1; i < grafo.getNumVertex()-1; ++i)
	{
		for(int j = 0; j < actual->getAdj().size(); ++j)
		{
			if(!actual->getAdj()[j].getDest()->isVisited())
			{
				if(pesoMin == -1 || actual->getAdj()[j].getWeight() < pesoMin)
				{
					pesoMin = actual->getAdj()[j].getWeight();
					proximo = actual->getAdj()[j].getDest();
				}
			}
		}


		//------------  Checks if all possible kids have been collected  ----------------//

		if (actual->getInfo() == proximo->getInfo() || b.getCapAtual() == b.getCapMax()){
				actual->path = grafo.getVertexSet()[grafo.getNumVertex() - 1];
				return;
			}

			//-------------------------------------------------------------------------------//

			//Add kid to the bus and readies next iteration

			b.addCrianca(proximo->getInfo());

			actual->path = proximo;

			actual = proximo;
			actual->setVisited(true);

			pesoMin = -1;
	}
}

void nearestNeighbourSuperBus(Graph<Crianca> &grafo, Autocarro &b)
{

	Vertex<Crianca>* actual = grafo.getVertexSet()[0];


	Vertex<Crianca>* proximo;
	actual->setVisited(true);
	int pesoMin = -1;

	for(int i = 1; i < grafo.getNumVertex()-1; ++i)
	{
		for(int j = 0; j < actual->getAdj().size(); ++j)
		{
			if(!actual->getAdj()[j].getDest()->isVisited())
			{
				if(pesoMin == -1 || actual->getAdj()[j].getWeight() < pesoMin)
				{
					pesoMin = actual->getAdj()[j].getWeight();
					proximo = actual->getAdj()[j].getDest();
				}
			}
		}


		//------------  Checks if all kids have been collected  ----------------//

		if (actual->getInfo() == proximo->getInfo()){
				actual->path = grafo.getVertexSet()[grafo.getNumVertex() - 1];
				return;
			}

			//-------------------------------------------------------------------------------//

			//Add kid to the bus and readies next iteration

			b.addCrianca(proximo->getInfo());

			actual->path = proximo;

			actual = proximo;
			actual->setVisited(true);

			pesoMin = -1;
	}

}


