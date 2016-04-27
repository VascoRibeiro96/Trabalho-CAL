/*
 * Criança.cpp
 *
 *  Created on: 19/04/2016
 *      Author: ASUS
 */

#include "Localizacao.h"
unsigned int Localizacao::nextId=1;

Localizacao::Localizacao()
{
	this->id=nextId;
	nextId++;
	this->rua="Rua XPTO";
	this->nome="Nome XPTO";

}

Localizacao::Localizacao(string nome, unsigned int id, string rua)
{
	this->nome = nome;
	this->rua = rua;
	this->id=id;
}

string Localizacao::getNome() const
{
	return nome;
}

void Localizacao::setNome(string nome)
{
	this->nome = nome;
}

unsigned int Localizacao::getId() const {
	return id;
}


void Localizacao::setId(unsigned int id) {
	this->id = id;
}

unsigned int Localizacao::getNextId() {
 	return nextId;
}

void Localizacao::setNextId(unsigned int nextId) {
 	Localizacao::nextId = nextId;
}


bool Localizacao::operator==(const Localizacao &c1) const
{
	if(this->id == c1.id)
		return true;
	else
		return false;
}

string Localizacao::getRua() const {
	return rua;
}

void Localizacao::setRua(string rua) {
	this->rua = rua;
}


