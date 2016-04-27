/*
 * main.cpp
 *
 *  Created on: 25/04/2016
 *      Author: Vasco
 */



#include "LoadGraph.h"
#include "windows.h"
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "Autocarro.h"
#include "Algorithms.h"
#include "Graph.h"
#include "EdgeType.h"
#include "GraphViewer.h"

using namespace std;




/**
 *  \brief Prints the given graph
 *  \param grafo Graph to be printed
 */
void showGraph(Graph<Localizacao> &grafo)
{
 	GraphViewer *gv = new GraphViewer(800, 800, true);

 	gv->createWindow(800, 800);


 	gv->defineVertexColor("blue");
 	gv->defineEdgeColor("black");


	unsigned int id1, id2;
 	string s;
 	stringstream ss;


 	for (unsigned int i = 0; i < grafo.getVertexSet().size(); i++) {
 		id1 = grafo.getVertexSet()[i]->getInfo().getId();
 		s = grafo.getVertexSet()[i]->getInfo().getRua();
 		ss << 1;
 		gv->addNode(id1);
 		gv->setVertexLabel(id1, s + " " + ss.str());

 		if(grafo.getVertexSet()[i]->getInfo().getNome() == "Garagem")
 			gv->setVertexColor(id1,"red");
 		else if(grafo.getVertexSet()[i]->getInfo().getNome() == "Escola")
 			gv->setVertexColor(id1,"green");


 		ss.str("");
 	}
 	gv->rearrange();

 	for (unsigned int vert = 0; vert < grafo.getVertexSet().size(); vert++) {
 		for (unsigned int edge = 0; edge < grafo.getVertexSet()[vert]->getAdj().size(); edge++) {
 			id1 = grafo.getVertexSet()[vert]->getInfo().getId();
 			id2 = grafo.getVertexSet()[vert]->getAdj()[edge].getDest()->getInfo().getId();


 			if (grafo.getVertexSet()[vert]->path != NULL && grafo.getVertexSet()[vert]->path->getInfo().getId() == id2) {
 				gv->setEdgeColor(id1*1000 + id2, "green");
 				gv->setEdgeThickness(id1*1000 + id2, 5);
			}


 			gv->addEdge(id1 * 1000 + id2, id1, id2, EdgeType::DIRECTED);

 			gv->setEdgeWeight(id1 * 1000 + id2, grafo.getVertexSet()[vert]->getAdj()[edge].getWeight());
 			ss.str("");
 		}
 	}

 	gv->rearrange();

 #ifdef __linux__
 	sleep(1);
 #else
 	Sleep(100); // use sleep(1) in linux ; Sleep(100) on Windows
 #endif

}

/**
 *  \brief Runs the algorithm in an ilimited bus that carries all the children
 *  \param g Graph where the resulting path is shown
 */
void ilimitado(Graph<Localizacao> &g)
{
	int option2;
	Autocarro a;
	Localizacao c("Garagem",0,"Garagem");
	do{
				cout << "1 - Mostrar Mapa" << endl;
				cout << "2 - Mostrar Caminho" << endl;
				cout << "0 - Return" << endl;

				cin >> option2;

				if(option2 > 2 || option2 < 0){
					cout << "Not a Valid Choice. \n"
							<< "Choose again.\n";
				}

				switch(option2)
				{
				case 1:
					a.setCapMax(INT_MAX);
					a.calcRotaAutocarro(g);
					a.print();
					cout << flush;
					showGraph(g);
					break;
				case 2:
					a.setCapMax(INT_MAX);
					nearestNeighbourSuperBus(g,a);
					a.calcRotaAutocarro(g);
					a.print();
					cout << flush;
					showGraph(g);
					break;
				case 0:
					cout << "End" << endl;
					break;
				}



			}while (option2 !=0);

}

/**
 *  \brief Runs the algorithm in an limited bus that carries a maximum number of children (not working properly due to algorithm problems)
 *  \param g Graph where the resulting path is shown
 */
void limitado(Graph<Localizacao> &g)
{
	int option3;
		Autocarro a;
		do{
					cout << "1 - Mostrar Mapa" << endl;
					cout << "2 - Mostrar Caminho" << endl;
					cout << "0 - Return" << endl;

					cin >> option3;

					if(option3 > 2 || option3 < 0){
						cout << "Not a Valid Choice. \n"
								<< "Choose again.\n";
					}

					switch(option3)
					{
					case 1:
						a.setCapMax(INT_MAX);
						a.calcRotaAutocarro(g);
						a.print();
						cout << flush;
						showGraph(g);
						break;
					case 2:
						a.setCapMax(INT_MAX);
						//nearestNeighbourAutocarro(g,a);
						a.calcRotaAutocarro(g);
						a.print();
						cout << flush;
						showGraph(g);
						break;
					case 0:
						cout << "End" << endl;
						break;
					}



				}while (option3 !=0);
}

/**
 *  \brief User Interface used to choose amongst the two options
 *  \param g Graph where the result is shown
 */
void mainMenu(Graph<Localizacao> &g)
{
	int option;
		do{
			cout << "Bem vindo aos Transportes BOSS" << endl << endl;
			cout << "1 - Autocarro com Capacidade Ilimitada" << endl;
			cout << "2 - Autocarro com Capacidade Limitada" << endl;
			cout << "0 - Exit" << endl;

			cin >> option;

			if(option > 2 || option < 0){
				cout << "Not a Valid Choice. \n"
						<< "Choose again.\n";
			}

			switch(option)
			{
			case 1:
				ilimitado(g);
				break;
			case 2:
				limitado(g);
				break;
			case 0:
				cout << "End" << endl;
				break;
			}



		}while (option !=0);


}

/**
 *  \brief Base of the program where the graph is loaded and the interface called
 */
int main(){

	Graph<Localizacao> g;
	LoadGraph lg;

	lg.loadLocalizacaos(g);
	lg.loadAdjacentes(g);


	g.floydWarshallShortestPath();

	mainMenu(g);

	return 0;
}

