#include "Tabla.h"

//Constructor de la tabla para incializar valores
Tabla::Tabla() {
	wasMade = false;
	numC = 0;
	numR = 0;
}

//Destructor de la tabla para liberar la memoria del array 2D
Tabla::~Tabla() {
		delete[]sprites;
}

//Método Draw llamado desde el .Draw de la escena en la que se encuentre
//una instancia de esta clase, el cual pinta toda la tabla, con celdas vacías 
//y bordes
void Tabla::Draw() {
	for (int i = 0; i < numR; i++) {
		for (int j = 0; j < numC; j++) {
			sprites[i][j].Draw();
		}
	}
}


//Método que reserva memoria para un array2D de sprites en función de los dos
//parametros integer que se le pasan
void Tabla::CrearTabla(int AnumR, int AnumC) {
	if (!wasMade) {

		numC = AnumC;
		numR = AnumR;

		//sprites = new Sprite*();

		sprites = new Sprite*[numR];

		//por cada numero de filas se añaden el numero de columnas
		for (int i = 0; i < numR; i++) sprites[i] = new Sprite[numC];
		
		int x = W.GetWidth()/5;
		for (int i = 0; i < numR; i++) { 
			int y = W.GetHeight()/12;
			for (int j = 0; j < numC; j++) {
				
				sprites[i][j].transform.x = x;

				sprites[i][j].transform.y = y;

				sprites[i][j].transform.w = 20;
				sprites[i][j].transform.h = 20;

				if (i == 0 || j == 0||i==numR-1||j==numC-1) {
					sprites[i][j].objectID = ObjectID::S_11;
				}
				else {
					sprites[i][j].objectID = ObjectID::S_12;
				}		
				y += 20;
			}
			x += 20;
		}

		
		wasMade = true;
	}
}

