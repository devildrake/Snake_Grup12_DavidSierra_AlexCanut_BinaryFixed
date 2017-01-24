#include "MainMenu.h"
#include "Niveles.h"
#include "ID.h"
#include "InputManager.h"
#include "Logger.h"
#include "SceneManager.h"
#include <iostream>
#include "RankingScene.h"
using namespace std;
using namespace Logger;


MainMenu::MainMenu() { //constructor, inicializamos la posicion de cada uno de los sprites mencionados y le asignamos su imagen
	posX = 362;
	posPlayY = 350;
	posRankY = 450;
	posExitY = 550;
	generalW = 340;


	background = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::S_00 };
	title = { { 250, 0, W.GetWidth()/2, W.GetHeight()/2 }, ObjectID::S_01 };
	play = { { posX, posPlayY, W.GetWidth()/3, W.GetHeight()/3 }, ObjectID::S_02 };
	exit = { { posX,posExitY,W.GetWidth()/3, W.GetHeight()/3 }, ObjectID::S_06 };
	Sranking = { {posX,posRankY,W.GetWidth()/3, W.GetHeight()/3},ObjectID::S_13 };
}
MainMenu::~MainMenu() {
}
void MainMenu::OnEntry(void) {
	system("cls");
}
void MainMenu::OnExit(void) {
}

//Metodo ejecutado en el Update General de escenas de GameEngine
//En este caso comprueba si hay input de click izquierdo de ratón, y en
//caso de haberla, guarda las coordenadas y las compara con los botones que estos hagan lo que deban
void MainMenu::Update(void) {
	static MouseCoords mouseCoords(0, 0); //variable que se guardara las coordenadas del puntero del raton al hacer click, inizializadas a 0

	if (IM.IsMouseDown<MOUSE_BUTTON_LEFT>()) { //si hace click izquierdo
		mouseCoords = IM.GetMouseCoords();  //se guardan estas coordenadas
		if ((mouseCoords.x >= posX && mouseCoords.x <= posX+generalW) && (mouseCoords.y >= 438 && mouseCoords.y <= 533)) {		//si el click esta entre estas coordenadas, carga escena Niveles
			SM.SetCurScene<Niveles>();		//tenemos intencion de cambiar esto por coord x = -sprite.width/2 y coord y = -sprite.height/2 
		}
		else if ((mouseCoords.x >= posX && mouseCoords.x <= posX+generalW) && (mouseCoords.y >= 638 && mouseCoords.y <= 733)) {
			SetState<SceneState::EXIT>(); //si se clica entre estas coordenadas, sale del juego.
		}
		else if ((mouseCoords.x >= posX&&mouseCoords.x <= posX + generalW) && (mouseCoords.y>=566&&mouseCoords.y<=618)) {
			//Se establece que se viene desde el menú con esta llamada
			RankingScene::SetFrom(false);
			//Se cambia de escena a la escena RankingScene
			SM.SetCurScene<RankingScene>();
		}
	}

}
//Metodo ejecutado en el Draw General de escenas de Renderer que pinta todos los sprites de la escena
void MainMenu::Draw(void) { 
	background.Draw();
	title.Draw();
	play.Draw();
	exit.Draw();
	Sranking.Draw();
}