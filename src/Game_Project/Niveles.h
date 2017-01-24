#pragma once
#include "Scene.h"
#include "Sprites.h"
#include <vector>

//Escena que controla la dificultad leída a través de XML de los niveles del juego
class Niveles : public Scene 
{
public:
	//Constructor
	explicit Niveles(); 
	//Destructor
	~Niveles() override;

	//Función ejecutada al cambiar el estado de la escena a RUNNING
	void OnEntry(void) override;

	//Función ejecutada al cambiar el estado de la escena a SLEEPING
	void OnExit(void) override;

	//Función ejecutada en el Update General de escenas de GameEngine
	void Update(void) override;

	//Función ejecutada en el Draw General de escenas de Renderer
	void Draw(void) override;

	//Función que retorna datos del vector xmlVal en función del valor pedido
	int static GetValue(std::string valor);


private:
	//Sprite del fondo
	Sprite background;

	//Sprite del título
	Sprite title;

	//Sprite del botón Facil
	Sprite easy;

	//Sprite del botón Medio
	Sprite med;

	//Sprite del botón Difícil
	Sprite hard;

	//Sprite del botón Back
	Sprite backButton;

};