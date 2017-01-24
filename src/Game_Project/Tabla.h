#pragma once
#include "Sprites.h"
#include "ID.h"


//Clase tabla, la cual contiene un Array2D de sprites generado 
//de forma dinámica, las coordenadas del cual se usan como 
//referencia para mover y colocar el resto de elementos del juego
//Así como un método para crear la tabla

class Tabla {
public:
	//Constructor de la tabla para incializar valores
	Tabla();

	//Destructor de la tabla para liberar la memoria del array 2D
	~Tabla();

	//Método Draw llamado desde el .Draw de la escena en la que se encuentre
	//una instancia de esta clase, el cual pinta toda la tabla, con celdas vacías 
	//y bordes
	void Draw(void);

	//Método que reserva memoria para un array2D de sprites en función de los dos
	//parametros integer que se le pasan
	void CrearTabla(int,int);

	//Puntero doble que luego se utilizará como Array2D
	Sprite** sprites;

	//Atributos en los que se guardarán el númeor de filas y columnas asignados
	//Al llamar a CrearTabla
	int numC, numR;

	//Booleano que se asegura que la tabla no se cree más de una vez cada vez
	//que sea necesario 
	bool wasMade;

private:

};
