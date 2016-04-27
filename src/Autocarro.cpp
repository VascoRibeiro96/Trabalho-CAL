/*
 * Autocarro.cpp
 *
 *  Created on: 19/04/2016
 *      Author: ASUS
 */

#include "Autocarro.h"

unsigned int Autocarro::nextId = 1;

int Autocarro::capMax = 15;

Autocarro::Autocarro()
{
	this->id = nextId;
	nextId++;
	this->distanciaPercorrida=0;

}

Autocarro::Autocarro(unsigned int id)
{
	this->id = id;
	this->distanciaPercorrida = 0;
}

unsigned int Autocarro::getId() const
{
	return id;
}

void Autocarro::setId(unsigned int id)
{
	this->id = id;
}

unsigned int Autocarro::getCapAtual() const
{
	return criancas.size();
}

unsigned int Autocarro::getCapMax() const
{
	return capMax;
}

void Autocarro::setCapMax(unsigned int capMax)
{
	this->capMax = capMax;
}

vector<Crianca> Autocarro::getCriancas() const
{
	return criancas;
}

void Autocarro::addCrianca(Crianca c1)
{
	this->criancas.push_back(c1);
}

void Autocarro::removeCrianca(Crianca c1)
{
	for(unsigned int i = 0; i < criancas.size(); i++)
	{
		if(criancas[i] == c1)
			criancas.erase(criancas.begin() + i);
	}
}
bool Autocarro::operator==(const Autocarro a1) const
{
	if(this->id == a1.getId())
			return true;
		else
			return false;
}

unsigned int Autocarro::getNextId() {
 	return nextId;
}

void Autocarro::setNextId(unsigned int nextId) {
 	Autocarro::nextId = nextId;
}

unsigned int Autocarro::getDist() const {
 	return distanciaPercorrida;
}

void Autocarro::addDist(unsigned int d) {
	this->distanciaPercorrida += d;
}


void Autocarro::calcRotaAutocarro(Graph<Crianca> &grafo) {


 	Vertex<Crianca>* actual = grafo.getVertexSet()[0];


	while (actual->path != NULL) {


 		for (unsigned int i = 0; i < actual->getAdj().size(); i++) {
			if (actual->path->getInfo().getId() == actual->getAdj()[i].getDest()->getInfo().getId()) {
 				this->addDist(actual->getAdj()[i].getWeight());
 				break;
			}
		}  		actual = actual->path;
}
}

void Autocarro::print(){
 	cout<<"Distancia percorrida:"<<this->distanciaPercorrida<<"\tQuantidade Criancas:"<<criancas.size()<<endl;
 	cout<<"Rota:";
 	for(int i =0;i<criancas.size();i++){
 		cout<<criancas[i].getId()<<" ";
}
 	cout<<endl;
}

