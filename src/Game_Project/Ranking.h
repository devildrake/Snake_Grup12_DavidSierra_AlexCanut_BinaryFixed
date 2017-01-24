#pragma once
#include <fstream>
#include <string>
#include <iostream>


using namespace std;

class Ranking {
public:
	//Struct jugador para guardar Puntuaciones y nombres
	typedef struct jugador {
		string name;
		int highScore;
		size_t nameSize;
		jugador(std::string name = "---", int score = 0) : name(name), highScore(score), nameSize(name.size()) { };
	}jugador;

	Ranking();
	
	//~Ranking();
	~Ranking() = default;

	 //Inicialización del array
	 jugador ranking[10] = { p1,p2,p3,p4,p5,p6,p7,p8,p9,p10 };

	 //Método que lee de un archivo binario los valores del array ranking en función del integer que se pasa como parametro
	void LeerBinario(int);

	//Método que escribe en un archivo binario los valores del array ranking en función del integer que se pasa como parametro
	void EscribirBinario(int);

	//Método que ordena el array ranking, recibe el array a ordenar y su longitud
	void OrdenarArray(jugador[],int);
private:
	//Diez variables Sample que se utilizan para inicializar el array ranking[10]
	jugador p1 = jugador();
	jugador p2 = jugador();
	jugador p3 = jugador();
	jugador p4 = jugador();
	jugador p5 = jugador();
	jugador p6 = jugador();
	jugador p7 = jugador();
	jugador p8 = jugador();
	jugador p9 = jugador();
	jugador p10 = jugador();
};