/*
 * Criança.cpp
 *
 *  Created on: 19/04/2016
 *      Author: ASUS
 */

#include "Crianca.h"
unsigned int Crianca::nextId=1;

Crianca::Crianca()
{
	this->id=nextId;
	nextId++;
	this->rua="Rua XPTO";
	this->nome="Nome XPTO";

}

Crianca::Crianca(string nome, unsigned int id, string rua)
{
	this->nome = nome;
	this->rua = rua;
	this->id=id;
}

string Crianca::getNome() const
{
	return nome;
}

void Crianca::setNome(string nome)
{
	this->nome = nome;
}

unsigned int Crianca::getId() const {
	return id;
}


void Crianca::setId(unsigned int id) {
	this->id = id;
}

unsigned int Crianca::getNextId() {
 	return nextId;
}

void Crianca::setNextId(unsigned int nextId) {
 	Crianca::nextId = nextId;
}


bool Crianca::operator==(const Crianca &c1) const
{
	if(this->id == c1.id)
		return true;
	else
		return false;
}

string Crianca::getRua() const {
	return rua;
}

void Crianca::setRua(string rua) {
	this->rua = rua;
}


