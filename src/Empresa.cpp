/*
 * Empresa.cpp
 *
 *  Created on: 25/04/2016
 *      Author: ASUS
 */

#include "Empresa.h"

Empresa::Empresa()
{

}

Empresa::Empresa(const Graph<int> &graph)
{
	this->graph = graph;
}

vector<Autocarro *> Empresa::getAutocarros() const
{
	return autocarros;
}

void Empresa::addAutocarro(Autocarro * a1)
{
	this->autocarros.push_back(a1);
}


Autocarro* Empresa::getAutocarroById(int id)const
{
	for(int i = 0; i < autocarros.size(); i++)
	{
		if(autocarros[i]->getId() == id)
			return autocarros[i];
	}
	return NULL;
}

Graph<int> Empresa::getGraph() const
{
	return graph;
}

void Empresa::removeAutocarro(Autocarro * a1)
{
	for(int i = 0; i < autocarros.size(); i++)
		{
			if(autocarros[i] == a1)
				autocarros.erase(autocarros.begin() + i);
		}
}

