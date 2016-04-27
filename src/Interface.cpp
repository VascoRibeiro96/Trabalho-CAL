///*
// * Interface.cpp
// *
// *  Created on: 25/04/2016
// *      Author: Vasco
// */
//
//#include "Interface.h"
//
//Interface::Interface(){
//
//}
//
//
//int Interface::displayMainMenu(){
//
//	int option;
//do{
//	cout << "Bem vindo aos Transportes BOSS" << endl << endl;
//	cout << "1 - Gestor Escola" << endl;
//	cout << "2 - Gestor Autocarro" << endl;
//	cout << "0 - Exit" << endl;
//
//	cin >> option;
//
//	if(option > 3 || option < 0){
//	cout << "Not a Valid Choice. \n"
//	<< "Choose again.\n";
//	}
//
//	switch(option)
//	{
//	case 1:
//		displayGestorEscola();
//		break;
//	case 2:
//		displayGestorAutocarro();
//		break;
//	case 0:
//		cout << "End" << endl;
//		break;
//	}
//
//
//
//}
//while (option !=0);
//return 0;
//
//}
//
//
//int Interface::displayGestorEscola()
//{
//	cout << "Gestor Escola" << endl << endl;
//
//	cout << "1 - Adicionar Escola" << endl;
//	cout << "2 - Gerir Escola" << endl;
//	cout << "3 - Remover Escola" << endl;
//
//
//	int option;
//
//	cin >> option;
//	string nomeEsc, nomeRua;
//	Escola* escola;
//	Escola es1;
//	Rua rua;
//	switch(option)
//	{
//	case 1:
//		cout << "Nome Escola: " << endl;
//		getline(cin, nomeEsc);
//		cout << "Rua Escola: " << endl;
//		getline(cin, nomeEsc);
//		rua = Rua(nomeRua,0,0);
//		es1 = Escola(nomeEsc,rua);
//		escola = &es1;
//		empresa.addEscola(escola);
//		break;
//	case 2:
//		displayGestorCrianca();
//		break;
//	case 3:
//		cout << "Nome Escola: ";
//		cin >> nomeEsc;
//		empresa.removeEscola(nomeEsc);
//		break;
//	}
//return 0;
//}
//
//int Interface::displayGestorAutocarro()
//{
//	int id, option;
//	Autocarro* a1;
//	Crianca* c1;
//	string nome,nomeRua;
//	Rua rua;
//	cout << "ID autocarro a gerir: " << endl;
//	cin >> id;
//
//	if(empresa.getAutocarroById(id) == NULL)
//	{
//			cout << "Autocarro nao existe" << endl;
//			return 0;
//	}
//	else
//		a1 = empresa.getAutocarroById(id);
//
//	do{
//			cout << "1 - Adicionar Crianca" << endl;
//			cout << "2 - Remover Crianca" << endl;
//			cout << "0 - Exit" << endl;
//
//			cin >> option;
//
//			if(option > 2 || option < 0){
//				cout << "A opcao nao e valida. \n" << "Escolha novamente.\n";
//			}
//
//			if( option == 1){
//				cout << "Nome Crianca :" << endl;
//				cin >> nome;
//				cout << "Morada :" << endl;
//				cin >> nomeRua;
//				rua = Rua(nomeRua,0,0);
//				c1 = new Crianca(nome,rua);
//				a1->addCrianca(c1);}
//			else if(option == 2)
//			{
//				cout << "Nome Crianca :" << endl;
//				cin >> nome;
//				cout << "Morada: " << endl;
//				cin >> nomeRua;
//				rua = Rua(nomeRua,0,0);
//				c1 = new Crianca(nome,rua);
//				a1->removeCrianca(c1);
//
//
//			}
//
//		}
//		while (option !=0);
//		return 0;
//
//}
//
//int Interface::displayGestorCrianca()
//{
//	string nome, nomeRua;
//	Escola* esc1;
//	int option;
//	Rua rua;
//	Crianca* c1;
//
//	cout << "Nome escola a gerir: " << endl;
//	getline(cin, nome);
//	if(empresa.getEscolaByName(nome) == NULL){
//		cout << "Escola nao existe" << endl;
//		return 0;
//	}
//	else
//	esc1 = empresa.getEscolaByName(nome);
//
//	do{
//		cout << "1 - Adicionar Crianca" << endl;
//		cout << "0 - Exit" << endl;
//
//		cin >> option;
//
//		if(option > 1 || option < 0){
//		cout << "A opcao nao e valida. \n" << "Escolha novamente.\n";
//		}
//
//		if(option == 1){
//			cout << "Nome Crianca :" << endl;
//			cin >> nome;
//			cout << "Morada :" << endl;
//			cin >> nomeRua;
//			rua = Rua(nomeRua,0,0);
//			c1 = new Crianca(nome,rua);
//			esc1->addCrianca(c1);
//		}
//
//	}
//	while (option !=0);
//	return 0;
//
//
//return 0;
//}
