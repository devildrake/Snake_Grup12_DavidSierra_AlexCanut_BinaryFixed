#pragma once
#include "ID.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
#include "Logger.h"
#include "Assert.h"
#include "Resource.h"
#include <XML/rapidxml_utils.hpp>

using namespace Logger;
using namespace rapidxml;

static vector <int> xmlValues; //Vector para guardar los datos leidos desde el XML

static void XML(std::string dificultad) {
	if (xmlValues.size()>0)
	xmlValues.erase(xmlValues.begin(), xmlValues.end());
	rapidxml::xml_document<> doc;
	std::ifstream file("XMLFile.xml");

	//Se crea un buffer
	std::stringstream buffer; 

	//Se hace al buffer leer el contenido del fichero .xml
	buffer << file.rdbuf(); 

	//se cierra el fichero XML que se ha acabado de leer.
	file.close(); 

	//se asigna a la variable content la información del buffer en string
	std::string content(buffer.str()); 
	
	//se transforma lo guardado en la variable contenido a codigo entendible y accesible
	doc.parse<0>(&content[0]); 

	//Puntero a un nodo del fichero XML
	rapidxml::xml_node<> *pRoot; 

	//se asigna a esa variable puntero el primer nodo del fichero xml(gameScene)
	pRoot = doc.first_node(); 

	//se crea otro puntero de tipo nodo xml
	rapidxml::xml_node<> *pNode; 

	//En función de la variable dificultad, se itera el nodo correspondiente para guardar los valores
	if (dificultad == "easy") {
		pNode = pRoot->first_node("Easy"); //asigno al puntero pNode el nodo con nombre "Easy".
		int i = 0;
		for (rapidxml::xml_node<> *pAttr = pNode->first_node(); pAttr; pAttr = pAttr->next_sibling()) {
			xmlValues.push_back(stoi(pAttr->value()));
			i++;
		}
	}
	else if (dificultad == "medium") {
		pNode = pRoot->first_node("Medium"); //asigno al puntero pNode el nodo con nombre "Medium".
		for (rapidxml::xml_node<> *pAttr = pNode->first_node(); pAttr; pAttr = pAttr->next_sibling()) {
			xmlValues.push_back(stoi(pAttr->value()));
		}
	}
	else if (dificultad == "hard") {
		pNode = pRoot->first_node("Hard"); //asigno al puntero pNode el nodo con nombre "Hard".
		for (rapidxml::xml_node<> *pAttr = pNode->first_node(); pAttr; pAttr = pAttr->next_sibling()) {
			xmlValues.push_back(stoi(pAttr->value()));
		}
	}
}
