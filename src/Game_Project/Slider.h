#pragma once
#include "TimeManager.h"
#include "Sprites.h"
#include "ID.h"
#include <iostream>
#include <math.h>

class Slider {
public:

	//Constructor de la clase para inicializar valores
	Slider();

	//Destructor de la clase
	~Slider();

	//Método que actualiza el transform.w del sprite imagen
	//En función de los dos Uint64 recibidos
	void Update(Uint64,Uint64);

	//Método que cambia los valores de posición y anchura original
	//a los parametros recibidos
	void StartSlider(int, int,int);

	//Método que pinta el sprite imagen
	void Draw();
private:
	//Sprite que se alargará o acortará
	Sprite imagen;

	//Atributo que contiene la información del tamaño original (máximo de la imagen)
	float originalSize;

};