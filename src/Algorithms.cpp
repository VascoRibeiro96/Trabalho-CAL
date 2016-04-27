/*
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

	Vertex<Crianca>* actual;

	for(int i = 1; i < grafo.getNumVertex()-1; ++i)
		if(!grafo.getVertexSet()[i]->isVisited())
		{
			actual = grafo.getVertexSet()[i];
			break;
		}

	if(actual == NULL)
		return;

	grafo.getVertexSet()[0]->path = actual;


	Vertex<Crianca>* proximo;
	actual->setVisited(true);
	int pesoMin = -1;

	for(int i = 1; i < grafo.getNumVertex()-1; ++i)
	{
		for(int j = 0; j < actual->getAdj().size(); ++j)
		{
			Edge<Crianca> edge = actual->getAdj()[j];
			if(!edge.getDest()->isVisited())
			{
				if(pesoMin == -1 || edge.getWeight() < pesoMin)
				{
					pesoMin = edge.getWeight();
					proximo = grafo.getVertexSet()[i]->getAdj()[j].getDest();
				}
			}
		}


		//------------  Checks if all possible kids have been collected  ----------------//

		if (actual->getInfo() == proximo->getInfo() || b.getCapAtual() == b.getCapMax()){
			{
				actual->path = grafo.getVertexSet()[grafo.getNumVertex() - 1];
				return;
			}
			//-------------------------------------------------------------------------------//

			//Add kid to the bus and readies next iteration

			b.addCrianca(proximo->getInfo());
			actual->setVisited(true);

			actual->path = proximo;

			actual = proximo;
			pesoMin = -1;
		}
	}
}

void nearestNeighbourSuperBus(Graph<Crianca> &grafo, Autocarro &b)
{

	Vertex<Crianca>* actual;

	for(int i = 1; i < grafo.getNumVertex()-1; ++i)
		if(!grafo.getVertexSet()[i]->isVisited())
		{
			actual = grafo.getVertexSet()[i];
			break;
		}

	if(actual == NULL)
		return;

	grafo.getVertexSet()[0]->path = actual;



	Vertex<Crianca>* proximo;
	actual->setVisited(true);
	int pesoMin = -1;

	for(int i = 1; i < grafo.getNumVertex()-1; ++i)
	{
		for(int j = 0; j < actual->getAdj().size(); ++j)
		{
			Edge<Crianca> edge = actual->getAdj()[j];
			if(!edge.getDest()->isVisited())
			{
				if(pesoMin == -1 || edge.getWeight() < pesoMin)
				{
					pesoMin = edge.getWeight();
					proximo = grafo.getVertexSet()[i]->getAdj()[j].getDest();
				}
			}
		}


		//------------  Checks if all kids have been collected  ----------------//

		if (actual->getInfo() == proximo->getInfo()){
			{
				actual->path = grafo.getVertexSet()[grafo.getNumVertex() - 1];
				return;
			}
			//-------------------------------------------------------------------------------//

			//Add kid to the bus and readies next iteration

			b.addCrianca(proximo->getInfo());
			actual->setVisited(true);

			actual->path = proximo;

			actual = proximo;
			pesoMin = -1;
		}
	}

}
