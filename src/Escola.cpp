/*
 * Escola.cpp
 *
 *  Created on: 19/04/2016
 *      Author: ASUS
 */

#include "Escola.h"
unsigned int Escola::nextId=1;

Escola::Escola()
{
	this->id=nextId;
	nextId++;
	this->rua="Rua XPTO";
	this->nome="Nome XPTO";

}

Escola::Escola(string nome, unsigned int id, string rua)
{
	this->nome = nome;
	this->rua = rua;
	this->id=id;
}

string Escola::getNome() const
{
	return nome;
}

void Escola::setNome(string nome)
{
	this->nome = nome;
}

unsigned int Escola::getId() const {
	return id;
}


void Escola::setId(unsigned int id) {
	this->id = id;
}

unsigned int Escola::getNextId() {
 	return nextId;
}

void Escola::setNextId(unsigned int nextId) {
 	Escola::nextId = nextId;
}


bool Escola::operator==(const Escola &c1) const
{
	if(this->id == c1.id)
		return true;
	else
		return false;
}

string Escola::getRua() const {
	return rua;
}

void Escola::setRua(string rua) {
	this->rua = rua;
}

