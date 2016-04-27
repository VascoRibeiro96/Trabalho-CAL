/*
 * Interface.h
 *
 *  Created on: 25/04/2016
 *      Author: Vasco
 */

#ifndef SRC_INTERFACE_H_
#define SRC_INTERFACE_H_

#include <vector>
#include "Empresa.h"
#include "Escola.h"


class Interface{

	Empresa empresa;

public:
	Interface();

	int displayMainMenu();
	int displayGestorCrianca();
	int displayGestorEscola();
	int displayGestorAutocarro();


};



#endif /* SRC_INTERFACE_H_ */
