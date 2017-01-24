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
#include "Scene.h"
#include "Ranking.h"
#include "Sprites.h"
#include "ID.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Niveles.h"
#include "MainMenu.h"
using namespace std;

//Escena que muestra
class RankingScene : public Scene
{
public: //decalaracion de variables y metodos publicos

	//Constructor
	explicit RankingScene();

	//Destructor
	~RankingScene() override;

	//Método ejecutado al cambiar el estado de la escena a RUNNING
	void OnEntry(void) override;
	
	//Método ejecutado al cambiar el estado de la escena a SLEEPING
	void OnExit(void) override;

	//Método ejecutado en el Update General de escenas de GameEngine
	void Update(void) override;

	//Método ejecutado en el Draw General de escenas de Renderer
	void Draw(void) override;

	//Método que, una vez leídos los archivos desde el binario, establece los valores en los arrays declarados arriba
	void SetScores();

	//Método que hace una textura por cada texto declarado y las asigna a los arrays de texturas declarados arriba
	void MakeTextures();

	//Método que establece si se accede a la escena desde GameScene o desde el Menú principal
	void static SetFrom(bool);

private:

	//Tamaño base de la fuente (píxeles)
	int fontsize = 80;

	//Anchura texto 
	int t_width = 250;

	//Altura Texto
	int t_height = 100; // height of the loaded font-texture

	//Posición Titulo
	int transformX = 0;
	int transformY = 0;
	int dif;

	//Booleanos para que solo se ejecute una vez el código de lectura y creación de texturas
	bool set;
	bool drawn;

	//Array preexistente al que asignarle los datos del array guardado en el archivo binario
	int puntuacionesAImprimir[10];

	//Color del texto
	SDL_Color text_color = { 0,0,0 };

	//camino a la fuente del texto
	string fontpath = "../../res/fnt/arial.ttf";

	//Texto del Título
	string iText = "HighScores";

	//Imagen de fondo
	Sprite background;

	//Imagen de la dificultad
	Sprite difficulty;

	//Botón Back
	Sprite backButton;

	//Array que contendrá las puntuaciones pasadas a string para poderlas poner en pantalla
	string scores[10];

	//Array que contendrá los nombres de los jugadores del ranking
	string names[10];

	//Variable Fuente
	TTF_Font* font = TTF_OpenFont(fontpath.c_str(), fontsize);

	//Puntero a textura para el titulo
	SDL_Texture* ftexture = NULL;

	//Punteros a texturas de las puntuaciones
	SDL_Texture* texturaScore[10] = { NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL };

	//Punteros a texturas de los nombres
	SDL_Texture* texturaNombres[10] = { NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL };

	//Instancia de la clase Ranking
	Ranking instanciaRank;

	//Rectangulo SDL sobre el que se imprimirá el textos iText
	SDL_Rect dst = { transformX + W.GetWidth() / 3, transformY, t_width, t_height };

	//Rectangulos SDL sobre los que se imprimirán las texturas de la puntuación y nombres
	SDL_Rect scoresRect[10];
	SDL_Rect namesRect[10];
	

};