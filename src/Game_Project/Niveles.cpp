#include "Niveles.h"
#include "GameScene.h"
#include "ID.h"
#include "XML.h"
#include "InputManager.h"
#include "Logger.h"
#include "SceneManager.h"
#include <XML/rapidxml_utils.hpp>
using namespace Logger;

//Vector estático de ints al que se accederá desde las escenas que lo necesiten
static vector <int> xmlVal;

//constructor, inicializamos la posicion de cada uno de los sprites mencionados y le asignamos su imagen
Niveles::Niveles() {
	background = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::S_00 };
	title = { { 250, 0, W.GetWidth() / 2, W.GetHeight() / 2 }, ObjectID::S_01 };
	easy = { { 400,300,W.GetWidth() / 4, W.GetHeight() / 4 }, ObjectID:: S_03 };
	med = { { 400,400,W.GetWidth() / 4, W.GetHeight() / 4 }, ObjectID:: S_04 };
	hard = { { 400,500,W.GetWidth() / 4, W.GetHeight() / 4 }, ObjectID::S_05 };
	backButton.objectID = ObjectID::S_14;
	backButton.transform = { W.GetWidth() / 8 , W.GetHeight() / 8 * 5,200,200 };
//	cout<<"notOutOfRange " << xmlVal[0];
}
Niveles::~Niveles() { //destructor
}

//Función que retorna datos del vector xmlVal en función del valor pedido
int Niveles::GetValue(std::string valor) {
	if (xmlVal.size() > 0) {
		if (valor == "Columns") return xmlVal[0];
		else if (valor == "Rows") return xmlVal[1];
		else if (valor == "Time") return xmlVal[2];
		else if (valor == "V") return xmlVal[3];
		else if (valor == "Food") return xmlVal[4];
		else if (valor == "IncrementoFood") return xmlVal[5];
		else if (valor == "Dificultad") return xmlVal[6];
		else if (valor == "SliderSize") return xmlVal[7];
		else return NULL;
	}
	else return NULL;
}

//Función ejecutada al cambiar el estado de la escena a RUNNING
void Niveles::OnEntry(void) {

}

//Función ejecutada al cambiar el estado de la escena a SLEEPING
void Niveles::OnExit(void) {

}

//Función ejecutada en el Update General de escenas de GameEngine
//En este caso detecta cicks izquierdos de ratón y guarda las coordenadas
//de este para comprobar si ha sido sobre los botones para cambiar de escena
//y leer los valores de XML que pertocan a la dificultad seleccionada
void Niveles::Update(void) {
	static MouseCoords mouseCoords(0, 0); //variable q recoje la coordenadas del puntero del mouse al darle click
	
	if (IM.IsMouseDown<MOUSE_BUTTON_LEFT>()) {
		mouseCoords = IM.GetMouseCoords(); 
		if ((mouseCoords.x >= easy.transform.x && mouseCoords.x <= easy.transform.x+W.GetWidth()/4) && (mouseCoords.y >= 366 && mouseCoords.y <= 438)) {
			XML("easy");
			xmlVal = xmlValues;
			SM.SetCurScene<GameScene>(); 
		}
		else if ((mouseCoords.x >= med.transform.x && mouseCoords.x <= med.transform.x+ med.transform.w) && (mouseCoords.y >= 466 && mouseCoords.y <= 538)){
		XML("medium");
			xmlVal = xmlValues;
			SM.SetCurScene<GameScene>();
		}
	else if ((mouseCoords.x >= hard.transform.x && mouseCoords.x <= hard.transform.x+hard.transform.w) && (mouseCoords.y >= 566 && mouseCoords.y <= 638)){
	XML("hard");
			xmlVal = xmlValues;
			SM.SetCurScene<GameScene>();

		}
	else if ((mouseCoords.x >= backButton.transform.x && mouseCoords.x <= backButton.transform.x + backButton.transform.w) && (mouseCoords.y >= backButton.transform.y+60 && mouseCoords.y <= backButton.transform.y+ backButton.transform.h-60)) {
		SM.SetCurScene<MainMenu>();
	}
	}

}

//Función ejecutada en el Draw General de escenas de Renderer
//En este caso hace una llamada al método .Draw() de cada sprite incluído en el header
void Niveles::Draw(void) {
	background.Draw();
	title.Draw();
	easy.Draw();
	med.Draw();
	hard.Draw();
	backButton.Draw();
}

