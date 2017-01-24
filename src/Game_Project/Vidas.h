#pragma once
#include "Sprites.h"
#include "ID.h"
class Vidas {
public:

	//Booleano que controla si se pinta o no el sprite
	bool isActive;

	//Constructor para inicializar atributos
	Vidas();

	//Destructor de la clase
	~Vidas();

	//Método que pinta el sprite Imagen siempre y cuando el booleano 
	//isActive sea true
	void Draw();

	//Método que cambia los valores transform.x y transform.y del sprite
	//imagen en función de los parametros que recibe
	void SetPos(int, int);
private:
	//Sprite de vida
	Sprite imagen;

};