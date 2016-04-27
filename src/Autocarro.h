/*
 * Autocarro.h
 *
 *  Created on: 19/04/2016
 *      Author: ASUS
 */

#ifndef SRC_AUTOCARRO_H_
#define SRC_AUTOCARRO_H_

#include <vector>
#include "Crianca.h"
#include "Graph.h"


using namespace std;

/**
 * Class where the Autocarro that travels across the graph and carries the children is defined.
 */
class Autocarro{
private:
	static int capMax;
	static unsigned int nextId;
	unsigned int id;
	unsigned int distanciaPercorrida;
	vector<Crianca> criancas;
public:
	/**
	 * \brief Default Constructor with no arguments
	 */
	Autocarro();
	/**
	 *  \brief Default Constructor for Autocarro
	 *  \param id Autocarro's ID
	 */
	Autocarro(unsigned int id);
	/**
	 *  \return Autocarro's ID
	 *
	 */
	unsigned int getId() const;
	/**
	 *  \brief Change the Autocarro's ID
	 *  \param id New ID
	 */
	void setId(unsigned int id);
	/**
	 *  \return Autocarro's current number of children
	 */
	unsigned int getCapAtual() const;
	/**
	 *  \return Autocarro's maximum capacity
	 */
	unsigned int getCapMax() const;
	/**
	 * 	\brief Change the Autocarro's maximum capacity
	 *  \param capMax New maximum capacity
	 */
	void setCapMax(unsigned int capMax);
	/**
	 *  \return Autocarro's next ID
	 */
	static unsigned int getNextId();
	/**
	 *  \brief Change the Autocarro's next ID
	 *  \param nextId New next ID
	 */
	static void setNextId(unsigned int nextId);
	/**
	 *  \return The vector where all the children in the Autocarro are stored
	 */
	vector<Crianca> getCriancas() const;
	/**
	 *  \brief Adds a child to the Autocarro's vector
	 *  \c1 Child to be added
	 */
	void addCrianca(Crianca c1);
	/**
	 *  \brief Removes a child to the Autocarro's vector
	*  \c1 Child to be removed
	*/
	void removeCrianca(Crianca c1);
	/**
	 *  \brief Adds a certain value to the travelled distance
	 *  \d Value to add
	 */
	void addDist(unsigned int d);
	/**
	 *  \return The value of the travelled distance
	 */
	unsigned int getDist() const;
	/**
	 * \brief Calculates the path the Autocarro takes in the given Graph
	 * \param Graph where the path is executed
	 */
	void calcRotaAutocarro(Graph<Crianca> &grafo);
	/**
	 * \brief Prints the travelled distance, the amount of carried children and the path
	 */
	void print();
	bool operator==(const Autocarro a1) const;
};


#endif /* SRC_AUTOCARRO_H_ */
