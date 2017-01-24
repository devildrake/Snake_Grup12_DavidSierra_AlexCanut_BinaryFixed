#pragma once
#include "SDL.h"
#include <string.h>
#include <string>
#include <iostream>
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_render.h"
#include "Renderer.h"
#include "Window.h"

using namespace std;


//Clase score, tiene métodos publicos Draw, Update y MakeTexture
class Score {
public:

	//Método que actualiza la puntuación en función de la puntuación en escena
	void Update(int);

	//Método que Pinta la textura sobre el rectángulo a través de la instancia de SDLRenderer
	void Draw();

	//Método que crea la textura en la posición de pantalla indicada
	void MakeTexture(int,int);

private:
	//Tamaño base de la fuente (píxeles)
	int fontsize = 100;

	//Anchura texto 
	int t_width = 250;

	//Altura Texto
	int t_height = 100;

	//Posición del texto (x,y);
	int transformX = 0;
	int transformY = 0;

	//Variable que guarda la puntuación que se debe imprimir por pantalla
	int puntuacionAImprimir;

	//Color del texto
	SDL_Color text_color = { 0,0,0 };

	//camino a la fuente del texto
	string fontpath = "../../res/fnt/arial.ttf";

	//Texto (Conjunto de Puntuación y añadiendole la variable puntuación pasada a string
	string text = "Puntuación: " + to_string(puntuacionAImprimir);

	//Puntero a variable Fuente
	TTF_Font* font = TTF_OpenFont(fontpath.c_str(), fontsize);
	
	//Puntero a textura 
	SDL_Texture* ftexture = NULL; 

	//Rectangulo SDL sobre el que se imprimirá la textura de la puntuación
	SDL_Rect dst = { transformX, transformY, t_width, t_height };

};