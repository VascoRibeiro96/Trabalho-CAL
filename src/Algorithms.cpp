/*
 * Algorithms.cpp
 *
 *  Created on: 27/04/2016
 *      Author: Tiago
 */

#include "Algorithms.h"
#include <vector>


#include "LoadGraph.h"
#include "windows.h"
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "Autocarro.h"

#include "Graph.h"



void prepareGraph(Graph<Localizacao> &grafo)
{

	for (unsigned int i = 0; i < grafo.getNumVertex(); i++) {
		grafo.getVertexSet()[i]->path = NULL;
	}

	for (unsigned int i = 0; i < grafo.getNumVertex(); i++) {
		grafo.getVertexSet()[i]->setVisited(false);
	}

}

void nearestNeighbourBus(Graph<Localizacao> &grafo, Autocarro &b)
{

	Vertex<Localizacao>* actual = grafo.getVertexSet()[0];


	Vertex<Localizacao>* proximo;
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

			b.addLocalizacao(proximo->getInfo());

			actual->path = proximo;

			actual = proximo;
			actual->setVisited(true);

			pesoMin = -1;
	}
}

bool allVisited(Graph<Localizacao> &grafo){
	for (unsigned int i = 0; i < grafo.getNumVertex(); i++) {
				if(grafo.getVertexSet()[i]->getVisited() == false)
					return false;
			}
	return true;
}

void nearestNeighbourSuperBus(Graph<Localizacao> &grafo, Autocarro &b)
{

	for (unsigned int i = 0; i < grafo.getNumVertex(); i++) {
			grafo.getVertexSet()[i]->setVisited(false);
		}

	Vertex<Localizacao>* actual = grafo.getVertexSet()[0];
	Vertex<Localizacao>* proximo;
	actual->setVisited(true);
	int pesoMin = INT_INFINITY;

	for(int i = 1; i < grafo.getNumVertex(); i++)
	{
		for(int j = 0; j < actual->getAdj().size(); j++)
		{
			if(!actual->getAdj()[j].getDest()->isVisited())
			{
				if(/*pesoMin == INT_INFINITY ||*/actual->getAdj()[j].getWeight() < pesoMin)
				{
					if((actual->getAdj()[j].getDest()->getInfo().getNome() == "Escola") && allVisited(grafo))
					{
					pesoMin = actual->getAdj()[j].getWeight();
					proximo = actual->getAdj()[j].getDest();
					continue;
					}
					pesoMin = actual->getAdj()[j].getWeight();
					proximo = actual->getAdj()[j].getDest();

				}
			}

		}
		//------------  Checks if all kids have been collected  ----------------//
		if (!(actual->getInfo() == proximo->getInfo())){
				//actual->path = grafo.getVertexSet()[grafo.getNumVertex() - 1];
				actual->path = proximo;
				if(!(actual->getInfo().getNome() == "Escola"))
				b.addLocalizacao(proximo->getInfo());
			}
			//-------------------------------------------------------------------------------//
			//Add kid to the bus and readies next iteration

			actual = proximo;
			actual->setVisited(true);
			pesoMin = INT_INFINITY;
	}
}


