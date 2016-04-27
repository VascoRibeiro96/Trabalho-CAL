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

vector<Escola *> Empresa::getEscolas() const
{
	return escolas;
}

void Empresa::addEscola(Escola *e1)
{
	this->escolas.push_back(e1);
}


Escola* Empresa::getEscolaByName(string nomeEscola)const
{
	for(int i = 0; i < escolas.size(); i++)
	{
		if(escolas[i]->getNome() == nomeEscola)
			return escolas[i];
	}
	return NULL;
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



void Empresa::removeEscola(string nomeEsc)
{
	for(int i = 0; i < escolas.size(); i++)
		{
			if(escolas[i]->getNome() == nomeEsc)
				escolas.erase(escolas.begin() + i);
		}
}