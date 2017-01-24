#include "Vidas.h"

//Constructor para inicializar atributos
Vidas::Vidas() {
	isActive = true;
	imagen.objectID = ObjectID::S_08;
	imagen.transform.w = 40;
	imagen.transform.h = 40;
}

//Destructor de la clase
Vidas::~Vidas() {

}


//Método que cambia los valores transform.x y transform.y del sprite
//imagen en función de los parametros que recibe
void Vidas::SetPos(int anX, int anY) {
	imagen.transform.x = anX;
	imagen.transform.y = anY;
}


//Método que pinta el sprite Imagen siempre y cuando el booleano 
//isActive sea true
void Vidas::Draw() {
	if (isActive) {
		imagen.Draw();
	}
}