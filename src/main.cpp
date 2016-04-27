/*
 * main.cpp
 *
 *  Created on: 25/04/2016
 *      Author: Vasco
 */

#include "Interface.h"
#include "Empresa.h"
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

using namespace std;


void showGraph(Graph<Crianca> &grafo) {
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

void ilimitado(Graph<Crianca> &g)
{
	int option2;
	Autocarro a;
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

void limitado(Graph<Crianca> &g)
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
						nearestNeighbourBus(g,a);
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

void mainMenu(Graph<Crianca> &g)
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


int main(){

	//
	//
	//	Empresa* empresa = new Empresa();
	//	Rua ruaE("Rua das Pombinhas", 21.1231521, -41.8798798);
	//	Rua ruaC1("Rua 25 de Abril", 21.2345234, -41.1235245);
	//	Rua ruaC2("Rua Luis de Camoes", 22.903765871, -41.213141);
	//	Rua ruaC3("Rua Fernando Pessoa", 21.018374, -41.26478237);
	//	Rua ruaC4("Rua Eugenio de Andrade", 21.2345213,-41.14352345);
	//	Crianca* cr1 = new Crianca("Joao",ruaC1);
	//	Crianca* cr2 = new Crianca("Manel",ruaC1);
	//	Crianca* cr3 = new Crianca("Nuno",ruaC2);
	//	Crianca* cr4 = new Crianca("Miguel",ruaC3);
	//	Crianca* cr5 = new Crianca("Pedro",ruaC4);
	//	Escola* escola = new Escola("Externato Delfim Ferreira", ruaE);
	//	escola->addCrianca(cr1);
	//	escola->addCrianca(cr2);
	//	escola->addCrianca(cr3);
	//	escola->addCrianca(cr4);
	//	escola->addCrianca(cr5);
	//	Autocarro* autocarro = new Autocarro(1,10);
	//	empresa->addEscola(escola);
	//	empresa->addAutocarro(autocarro);
	//	cout << "Nome: " << empresa->getEscolaByName("Externato Delfim Ferreira")->getNome() << endl;


	Graph<Crianca> g;
	LoadGraph lg;

	lg.loadCriancas(g);
	lg.loadAdjacentes(g);

	g.floydWarshallShortestPath();
	
	prepareGraph(g);
	mainMenu(g);



	return 0;
}

