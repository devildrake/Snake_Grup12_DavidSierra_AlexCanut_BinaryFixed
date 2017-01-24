#include "Snake.h"
#include "GameScene.h"
#include "Niveles.h"
#include "ID.h"
#include "InputManager.h"
#include "TimeManager.h"
#include <time.h>
#include "Logger.h"
#include "SceneManager.h"

using namespace Logger;


//Constructor de la clase, inicializa los atributos necesarios
Snake::Snake() {

	//Se inicializan los atributos vidas y prevVidas en 3
	prevVidas = vidas = 3;

	//vidasChanged tambien se inicializa como false
	vidasChanged = false;

	//Se definen transforms para los tres primeros sprites que formarán parte del vector
	//Así como sus Object IDs
	head.transform = { W.GetWidth()/2, W.GetHeight() / 2, W.GetWidth() / 40, W.GetHeight() / 40 };
	head.objectID = ObjectID::S_08;

	body.transform = { head.transform.x- head.transform.w , head.transform.y, W.GetWidth() / 40, W.GetHeight() / 40 };
	body.objectID = ObjectID::S_09;

	tail.transform = { body.transform.x- body.transform.w , body.transform.y , W.GetWidth() / 40, W.GetHeight() / 40 };
	tail.objectID = ObjectID::S_09;

	//Se pone en true el boolean de vida
	isAlive = true;

	//Se meten los primeros 3 sprites en el vector de sprites
	conjuntoSerp.push_back(head);
	conjuntoSerp.push_back(body);
	conjuntoSerp.push_back(tail);


	//Se establece el contador en función del cual se moverá la serpiente (le influye la velocidad de esta)
	timer = 6000000;

	//Se incializa la Variable que guarda el tiempo de forma temporal para comparar con el actual
	prevTime = TM.GetCurTime();

	//Comienza los booleanos de control de movimiento en false
	hasMoved = false;
	isBlocked = false;

	//Se da una semilla nula para los randoms que se usaran luego.
	srand(time(NULL));

}

void Snake::AñadirTrozo() {
	//Nuevo Trozo que se añadirá
	Sprite newNode;

	newNode.objectID = ObjectID::S_09;
	//Sustituye la posición del último trozo
	newNode.transform = conjuntoSerp[conjuntoSerp.size() - 1].transform;
	
	//Se coloca en el ultimo puesto
	conjuntoSerp.push_back(newNode);
}

//Destructor de la serpiente, hace un erase de todos los sprites contenidos en el 
//vector <Sprite>conjuntoserp
Snake::~Snake() {
	conjuntoSerp.erase(conjuntoSerp.begin(),conjuntoSerp.end());
}

//Método que detecta las inputs de flechas, funciona en función de isBlocked e isAlive y cambia la variable dir 
void Snake::Mov() {

	if (!isBlocked&&isAlive) {

		if (IM.IsKeyDown<KEY_BUTTON_DOWN>() && dir != 3) {
			isBlocked = true;
			dir = 4;
		}
		else if (IM.IsKeyDown<KEY_BUTTON_UP>() && dir != 4&&dir!=0) {
			isBlocked = true;
			dir = 3;
		}
		else if (IM.IsKeyDown<KEY_BUTTON_RIGHT>() && dir != 2) {
			isBlocked = true;
			dir = 1;
		}
		else if (IM.IsKeyDown<KEY_BUTTON_LEFT>() && dir != 1) {
			isBlocked = true;
			dir = 2;
		}
	}
	

	if ((TM.GetCurTime() - prevTime) > timer/vel) {
		if (isAlive) {
			switch (dir) {
			case 0: //None
				prevPosX = posX;
				prevPosY = posY;
				break;
			case 1: //Derecha
				prevPosX = posX;
				prevPosY = posY;
				posX += 1;
				hasMoved = true;
				break;
			case 2: //Izquierda
				prevPosX = posX;
				prevPosY = posY;
				posX -= 1;
				hasMoved = true;
				break;
			case 3: //Arriba
				prevPosX = posX;
				prevPosY = posY;
				posY -= 1;
				hasMoved = true;
				break;
			case 4: //Abajo
				prevPosX = posX;
				prevPosY = posY;
				posY += 1;
				hasMoved = true;
				break;

			}
			prevTime = TM.GetCurTime();
		}
		CheckCol();
	}
}


//Método que comprueba las colisiones de la serpiente consigo misma
void Snake::CheckCol() {
	for (int i = 2; i < conjuntoSerp.size(); i++) {
		if ((conjuntoSerp[0].transform.x == conjuntoSerp[i].transform.x) && conjuntoSerp[0].transform.y == conjuntoSerp[i].transform.y) {
			isAlive = false;
		}
	}
}

//Método que actualiza la posición "virtual" de la serpiente en la tabla
void Snake::Update() {
	if (isAlive) {
		Mov();
	}
	if (vidas != prevVidas) {
		vidasChanged = true;
	}
}

//Método que pinta todos los sprites del vector<Sprite> conjuntoSerp
void Snake::Draw(void) {
	if (isAlive) {
		for (int i = 0; i < conjuntoSerp.size(); i++) {
			conjuntoSerp[i].Draw();
		}
	}
}