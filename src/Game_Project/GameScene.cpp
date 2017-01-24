#include "GameScene.h"

using namespace Logger;
  
GameScene::GameScene() { //constructor, se inicializa la posicion de cada uno de los sprites mencionados y le asignamos su imagen

	fondo = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::S_07 };
	hasStarted = false;
	posAX = 0;
	posAY = 0;
	ended = false;
}

//Método que dibuja todos los sprites que conforman el obstaculo actual
void GameScene::DrawObstacle() {
	for (int i = 0; i < obstaculo.size(); i++) {
		obstaculo[i].Draw();
	}
}


//Método que borra el obstaculo previo (si lo hay) y establece uno nuevo en función de la dificultad
//en una posicion aleatoria teniendo en cuenta las dimensiones del nivel y en funcion de un numero random

void GameScene::SetObstacle() {
	int nR = rand() % 3; //Numero aleatorio generado cada vez que se llama a esta funcion (hay 3 obstaculos por dificultad)
	
	switch (dificultad) {
#pragma region Facil
	case 0: //Dificultad Facil
		if (nR == 0) {
	//Obstaculo cuadrado

			//Primero se borra el obstaculo previo (si lo habia)
			if(obstaculo.size()>0)
				obstaculo.erase(obstaculo.begin(), obstaculo.end());

			int xI = 1+ rand() % (numC - 4);
			int yI = 1+ rand() % (numR - 4);
			for (int i = 0; i <= 2; i++){
				for (int j = 0; j <= 2; j++) {
					Sprite pared;
					pared.objectID = ObjectID::S_11;
					pared.transform.w = 20;
					pared.transform.h = 20;
					pared.transform.x = grid.sprites[xI + i][yI + j].transform.x;
					pared.transform.y = grid.sprites[xI + i][yI + j].transform.y;
					obstaculo.push_back(pared);

				}
			}
		}

		else if (nR == 1) {
			//No hay obstaculo
			if (obstaculo.size()>0)
				obstaculo.erase(obstaculo.begin(), obstaculo.end());
		}

		else if (nR == 2) {
			//Obstaculo forma U
			int xI = 1+ rand() % (numC - 7);
			int yI = 1+ rand() % (numR - 3);
			if (obstaculo.size()>0)
				obstaculo.erase(obstaculo.begin(), obstaculo.end());
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 2; j++) {
					Sprite pared;
					pared.objectID = ObjectID::S_11;
					pared.transform.w = 20;
					pared.transform.h = 20;
					pared.transform.x = grid.sprites[xI + i][yI + j].transform.x;
					pared.transform.y = grid.sprites[xI + i][yI + j].transform.y;
					obstaculo.push_back(pared);

				}
			}
		}
		break;
#pragma endregion
#pragma region Medio
	case 1: //Dificultad Media
		if (obstaculo.size()>0)
			obstaculo.erase(obstaculo.begin(), obstaculo.end());
		if (nR == 0) {
			//Obstaculo 
			int xI = 2 + rand() % (numC - 10);
			int yI = 2 + rand() % (numR - 9);
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 7; j++) {
				
					if ((j==6)&&(i==0||i==1)||(j==5&&i==2)||(j==4&&i==3)||(j==3&&i==4)||(j==2&&i==5)||(j==1&&i==6)||(j==0&&i==7)) {
						Sprite pared;
						pared.objectID = ObjectID::S_11;
						pared.transform.w = 20;
						pared.transform.h = 20;
						pared.transform.x = grid.sprites[xI + i][yI + j].transform.x;
						pared.transform.y = grid.sprites[xI + i][yI + j].transform.y;
						obstaculo.push_back(pared);
					}

				}
			}
		}
		

		else if (nR == 1) {
			//Obstaculo con forma de cruz 
			int xI = 2 + rand() % (numC - 11);
			int yI = 2 + rand() % (numR - 11);
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {

					if(i==4||j==4){
						Sprite pared;
						pared.objectID = ObjectID::S_11;
						pared.transform.w = 20;
						pared.transform.h = 20;
						pared.transform.x = grid.sprites[xI + i][yI + j].transform.x;
						pared.transform.y = grid.sprites[xI + i][yI + j].transform.y;
						obstaculo.push_back(pared);
					}

				}
			}
		}

		else if (nR == 2) {
			//Obstaculo 
			int xI = 2 + rand() % (numC - 7);
			int yI = 2 + rand() % (numR - 8);
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 6; j++) {

					if(j==0||j==5||i==2){
						Sprite pared;
						pared.objectID = ObjectID::S_11;
						pared.transform.w = 20;
						pared.transform.h = 20;
						pared.transform.x = grid.sprites[xI + i][yI + j].transform.x;
						pared.transform.y = grid.sprites[xI + i][yI + j].transform.y;
						obstaculo.push_back(pared);
					}
				}
			}
		}

		break;
#pragma endregion
#pragma region Dificil
	case 2: //Dificultad Dificil
		if (obstaculo.size()>0)
			obstaculo.erase(obstaculo.begin(), obstaculo.end());
		if (nR == 0) {
			int xI = 1 + rand() % (numC - 9);
			int yI = 1 + rand() % (numR - 6);

			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 5; j++) {
					if ((j == 0) || (j == 1 && i == 0) || (j == 1 && i == 7) || (j == 2 && i == 0) || (j == 2 && i == 7) || (j == 3 && i == 0) || (j == 3 && i == 7) || (j == 4 && i == 0) || (j == 4 && i == 7)) {
						Sprite pared;
						pared.objectID = ObjectID::S_11;
						pared.transform.w = 20;
						pared.transform.h = 20;
						pared.transform.x = grid.sprites[xI + i][yI + j].transform.x;
						pared.transform.y = grid.sprites[xI + i][yI + j].transform.y;
						obstaculo.push_back(pared);
					}
				}
			}
		}
		else if (nR == 1) {
			int xI = 1 + rand() % (numC - 6);
			int yI = 1 + rand() % (numR - 6);
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {

					if ((j == 4 && i == 0) || (j == 4 && i== 1) || (i == 2) || (j== 0 && i == 3) || j == 0 && i == 4) {

					Sprite pared;
						pared.objectID = ObjectID::S_11;
						pared.transform.w = 20;
						pared.transform.h = 20;
						pared.transform.x = grid.sprites[xI + i][yI + j].transform.x;
						pared.transform.y = grid.sprites[xI + i][yI + j].transform.y;
						obstaculo.push_back(pared);
					
					}

				}
			}
		}

		else if (nR == 2) {
			int xI = 2 + rand() % (numC - 8);
			int yI = 2 + rand() % (numR - 7);

			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 5; j++) {

					if ((i==0)||(i==5)||(i==1&&j==4)||(i==2&&j==4)||(i==3&&(j==0||j==4))||(i==4&&(j==0||j==4))) {
						Sprite pared;
						pared.objectID = ObjectID::S_11;
						pared.transform.w = 20;
						pared.transform.h = 20;
						pared.transform.x = grid.sprites[xI + i][yI + j].transform.x;
						pared.transform.y = grid.sprites[xI + i][yI + j].transform.y;
						obstaculo.push_back(pared);
					}
				}
			}
		}
			break;	
#pragma endregion
	}
}


//Método que cambia el "nivel" en el que se encuentra el jugador y actualiza los contadores temporales
//de manzanas consecutivas sin perder vidas,longitud de la serpiente y puntuación en función de los valores que estos
//tienen al empezar el nivel, tambien reinicia a 0 las manzanas comidas en el nivel actual.
void GameScene::ChangeLevel() { 
	snake.longSerpN = snake.conjuntoSerp.size();
	applesComidasNivel = 0;
	numapples += applIncrease;
	realTiempoLevel = TM.GetCurTime() + tiempoLevel;
	SetObstacle();
	prevScore = score;
}

//Método que comprueba las colisiones con la manzana y en caso de haberla
//Actua en consecuencia
void GameScene::CheckManzana() {

	if(snake.posX==posAX&&snake.posY==posAY){
		
		//Aumenta la puntuación, el numero de manzanas comidas
		//en el nivel actual, el numero de manzanas comidas 
		//consecutivamente sin perder vidas, cambia la posición
		//de la manzana y hace una llamada al metodo de la serpiente
		//que aumenta su tamaño

		score += 100 * (1+applesComidas);

		ChangeManPos();
		applesComidas++;
		applesComidasNivel++;
		snake.AñadirTrozo();

		//Comprueba si el numero de manzanas comidas en el nivel actual
		//se corresponde con el numero de manzanas a comer en ese nivel
		//para pasar al siguiente y en caso de ser así hace una llamada
		//al metodo changeLevel

		if (applesComidasNivel >= numapples) {
			lvl++;
			
			ChangeLevel();
		}

		//Se aumenta la velocidad de la serpiente con al función
		//Establecida en las especificaciones
		snake.vel += score / 10000;

	}

	//Se crea un booleano local que, mientras es true, obliga a la manzana
	//a cambiar de posición en caso de encontrarse en la misma posición que
	//alguno de los sprites de los obstáculos

	bool colisiona = true;
	while (colisiona) {
		bool collided = false;
		for (int i = 0; i < obstaculo.size(); i++) {
			if (manzana.transform.x == obstaculo[i].transform.x&&manzana.transform.y == obstaculo[i].transform.y) {
				ChangeManPos();
				collided = true;
			}
			
		}
		if (!collided) {
			colisiona = false;
		}
	}
}

//Método que coloca la serpiente en su posición original y reinicia los atributos de 
//puntuación, manzanas comidas consecutivamente sin perder vidas, manzanas comidas 
//consecutivamente en el nivel actual, las variables de control de movimiento de la serpiente
//así como su variable de vida. Además realiza llamadas a las funciones de reaparición de serpiente
//así como de cambio de posición de manzana.

void GameScene::Restart() {
	snake.conjuntoSerp[0].transform.w = snake.conjuntoSerp[1].transform.w;
	snake.conjuntoSerp[0].transform.h = snake.conjuntoSerp[1].transform.h;
	score = prevScore;
	snake.vel = Niveles::GetValue("V");
	numapples = Niveles::GetValue("Food");
	applesComidas = 0;
	applesComidasNivel = 0;
	SnakeSpawn();
	hasStarted = true;
	prevTime = TM.GetCurTime();
	realTiempoLevel = TM.GetCurTime() + tiempoLevel;
	snake.isAlive = true;
	snake.isBlocked = false;
	ChangeManPos();
}

//Destructor de la clase

GameScene::~GameScene() {

}

//Método llamado cuando el estado de la escena cambia a RUNNING
//Que inicializa hasStarted y grid.wasMade en false para poder 
//Volver a crear un grid y llamar a la función Start

void GameScene::OnEntry(void) {
	hasStarted = false;
	grid.wasMade = false;
}

//Método llamado cuando el estado de la escena cambia a SLEEPING

void GameScene::OnExit(void) {

}

//Método que comprueba las colisiones de la cabeza con todas las paredes de la tabla 
//Y con los obstáculos en caso de que los haya y pone en false el booleano snake.isAlive
//en caso de detectar colision

void GameScene::CheckHit() {
	if ((snake.conjuntoSerp[0].transform.x >= grid.sprites[0][0].transform.x && snake.conjuntoSerp[0].transform.x <= grid.sprites[0][numC - 1].transform.x
		&& snake.conjuntoSerp[0].transform.y <= grid.sprites[0][0].transform.y
		|| snake.conjuntoSerp[0].transform.y >= grid.sprites[0][numC - 1].transform.y)
		|| (snake.conjuntoSerp[0].transform.x <= grid.sprites[0][0].transform.x
			|| snake.conjuntoSerp[0].transform.x >= grid.sprites[0][numC - 1].transform.x && snake.conjuntoSerp[0].transform.y <= grid.sprites[0][0].transform.y
			&& snake.conjuntoSerp[0].transform.y >= grid.sprites[0][numC - 1].transform.y)
		|| (snake.conjuntoSerp[0].transform.x >= grid.sprites[numR - 1][0].transform.x && snake.conjuntoSerp[0].transform.y >= grid.sprites[0][0].transform.y
			&& snake.conjuntoSerp[0].transform.y <= grid.sprites[0][numC - 1].transform.y)
		|| (snake.conjuntoSerp[0].transform.x >= grid.sprites[0][0].transform.x &&
			snake.conjuntoSerp[0].transform.x <= grid.sprites[numR - 1][0].transform.x &&
			snake.conjuntoSerp[0].transform.y <= grid.sprites[0][0].transform.y))
	{	
		snake.isAlive = false;
	}
	
	if (obstaculo.size() != 0) 
	{
		for (int i = 0; i < obstaculo.size(); i++) 
		{
			if (snake.conjuntoSerp[0].transform.x == obstaculo[i].transform.x && snake.conjuntoSerp[0].transform.y == obstaculo[i].transform.y)
			{
				snake.isAlive = false;
			}
		}
	}
}

//Método que cambia la posición de la manzana a una aleatoria dentro de las dimensiones de la tabla 
void GameScene::ChangeManPos() {
	//Se cambian las variables de la posicion en tabla
	posAX = 1+rand() % (numC-2);
	posAY = 1+rand() % (numR-2);

	//Se utilizan estas variables de posicion en tabla para cambiar 
	//Los transforms (.x y .y)
	manzana.transform.x = grid.sprites[posAX][0].transform.x;
	manzana.transform.y = grid.sprites[0][posAY].transform.y;

}



//Método que comprueba si las vidas de la serpiente son 0, y de serlo 
//pone en true el booleano gameOver
void GameScene::GameOverCheck() {
	if (snake.vidas <= 0) {
		gameOver = true;
	}
}


//Método que cambia la posición de la Snake a su posición original en tabla
//Cambia su dirección a 0(nula) y borra todos los trozos de serpiente adicionales
//en comparación con los que tenía al empezar el nivel en el que se encuentra

void GameScene::SnakeSpawn() {

	snake.dir = 0;

	snake.posX = snake.iPosX;
	snake.posY = snake.iPosY;

	snake.conjuntoSerp[0].transform.x = grid.sprites[snake.iPosX][snake.iPosY].transform.x;
	snake.conjuntoSerp[0].transform.y = grid.sprites[snake.iPosX][snake.iPosY].transform.y;

	snake.conjuntoSerp[1].transform.x = snake.conjuntoSerp[0].transform.x;
	snake.conjuntoSerp[1].transform.y = grid.sprites[snake.iPosX][snake.iPosY - 1].transform.y;

	snake.conjuntoSerp[2].transform.x = snake.conjuntoSerp[0].transform.x;
	snake.conjuntoSerp[2].transform.y = grid.sprites[snake.iPosX][snake.iPosY - 2].transform.y;

	if (snake.conjuntoSerp.size() > 3) {
		snake.conjuntoSerp.erase(snake.conjuntoSerp.begin() + snake.longSerpN, snake.conjuntoSerp.end());
	}

	if (snake.longSerpN > 3) {
		for (int i = 3; i < snake.conjuntoSerp.size(); i++) {
			snake.conjuntoSerp[i].transform.x = snake.conjuntoSerp[2].transform.x;
			snake.conjuntoSerp[i].transform.y = snake.conjuntoSerp[2].transform.y;
		}
	}
}

//Método que actualiza la posición en pantalla de la cabeza de la serpiente en función
//De su posición en tabla y borra el último sprite del vector además de introducir un 
//nuevo sprite en la segunda posición para generar la sensación de que la serpiente se está 
//moviendo
void GameScene::ActualizarSnake() {

	snake.conjuntoSerp[0].transform.x = grid.sprites[snake.posX][0].transform.x;
	snake.conjuntoSerp[0].transform.y = grid.sprites[0][snake.posY].transform.y;

	Sprite newNode;
	newNode.objectID = ObjectID::S_09;
	newNode.transform = grid.sprites[snake.prevPosX][snake.prevPosY].transform;

	snake.conjuntoSerp.insert(snake.conjuntoSerp.begin()+1, newNode);
	snake.conjuntoSerp.pop_back();

	}

//Método que se llama en el Draw general de GameEngine.h y que pinta todos los
//elementos que forman parte de GameScene y deben ser pintados
void GameScene::Draw(void) {
	fondo.Draw();
	grid.Draw();
	manzana.Draw();
	snake.Draw();
	timeS.Draw();
	DrawObstacle();
	scoreDisplay.Draw();
	lasVidas[0].Draw();
	lasVidas[1].Draw();
	lasVidas[2].Draw();
}

//Método al que se llama en caso de que el booleano hasStarted sea false 
//cada vez que se llama al método Update() y que se dedica a incializar
//todos los elementos que considera necesarios para comenzar sin problemas
//una partida
void GameScene::Start() {

	if (!hasStarted) {
		prevScore = score = 0;
		lvl = 1;
		numC = 5;
		numR = 5;
		numC *= Niveles::GetValue("Columns");
		numR *= Niveles::GetValue("Rows");
		snake.vel = Niveles::GetValue("V");
		tiempoLevel = Niveles::GetValue("Time");
		applIncrease = Niveles::GetValue("IncrementoFood");
		numapples = Niveles::GetValue("Food");
		dificultad = Niveles::GetValue("Dificultad");
		sliderSize = Niveles::GetValue("SliderSize");
		ended = false;
		snake.vidas = 3;
		snake.isAlive = true;
		grid.CrearTabla(numC, numR);
		manzana.objectID = ObjectID::S_10;
		manzana.transform.w = 20;
		manzana.transform.h = 20;
		ChangeManPos();
		snake.iPosX = round(numC / 2);
		snake.iPosY = round(numR / 2);
		hasStarted = true;
		prevTime = TM.GetCurTime();
		tiempoLevel *= 3000000;
		realTiempoLevel = TM.GetCurTime() + tiempoLevel;
		SetObstacle();
		gameOver = false;
		snake.longSerpN = 3;
		SnakeSpawn();
		timeS.StartSlider(grid.sprites[0][0].transform.x, grid.sprites[0][numR - 1].transform.y + 20, sliderSize);
		scoreDisplay.MakeTexture(grid.sprites[numC / 2 - 5][0].transform.x, grid.sprites[0][0].transform.y - 80);

		for (int i = 0; i < 3; i++) {
			lasVidas[i].SetPos(grid.sprites[numC / 2 - 5][0].transform.x + 350 + 80 * i, grid.sprites[0][0].transform.y - 50);
		}
	}
}


//Método que se llama cada vez que se llama al Update general, el cual
//Hace llamadas a todos los métodos que son necesarios para actualizar
//el mundo de juego
void GameScene::Update(void) {
	//Se llama a Start, aunque solo ejecute si hasStarted es false
	Start();

	//Se comprueba que gameOver es false
	GameOverCheck();
	if (!gameOver) {

		//Se comprueban las colisiones con la manzana, se actualiza la 
		//posición en tabla de la serpiente, se buscan colisiones con obstáculos
		//y paredes.
		CheckManzana();
		snake.Update();
		CheckHit();

		//Se comprueba que el tiempo limite no haya sido alcanzado
		//En cuyo caso, el jugador pierde una vida
		if (TM.GetCurTime() > realTiempoLevel) {
			snake.isAlive = false;
		}

		//Se actualiza la verdadera posición del snake en la pantalla
		//se actualiza la variable remainingTime y se reinician los booleanos
		//de control de movimiento de la serpiente
		if (snake.dir != 0 && snake.hasMoved&&snake.isAlive) {
			ActualizarSnake();
			remainingTime = realTiempoLevel - TM.GetCurTime();
			snake.hasMoved = false;
			snake.isBlocked = false;
		}

		//En caso de que snake.isAlive no sea cierto se resta una vida y se llama al metodo restart
		if (!snake.isAlive) {

			snake.vidas--;
			Restart();
		}

		//Se actualiza la instancia de la clase Slider
		timeS.Update(realTiempoLevel - TM.GetCurTime(), tiempoLevel);

		//Se actualiza la instancia de la clase Score
		scoreDisplay.Update(score);

		//Se comprueba que las vidas no hayan cambiado
		//En caso de haberlo hecho se pone en false un isActive
		if (snake.vidasChanged) {
			snake.vidasChanged = false;
			lasVidas[snake.vidas].isActive = false;
		}
	}

	//En caso de que gameOver sea true
	else {
		//Se comprueba que endede no sea true
		if (!ended) {

			//Se pone en true y se crean tres structs jugador 
			//locales 
			ended = true;

			Ranking::jugador aPlayer;
			Ranking::jugador temporal;
			Ranking::jugador temporal2;

			//Se le pide al jugador que introduzca su nombre 
			cout << "Game Over!" << endl;

			cout << endl << endl;
			cout << "Enter your name: " << endl;
			cin >> aPlayer.name;

			//Si se quisiera reiniciar los rankings bastaría con descomentar la linea bajo esta
			//instanciaRank.EscribirBinario(dificultad);

			//Se hace una lectura del fichero binario en función de la dificultad de leída del archivo XML

			instanciaRank.LeerBinario(dificultad);

			//Al struct jugador aPlayer se le asigna la highscore

			aPlayer.highScore = score;

			//Se comprueba si alguna puntuación del ranking es inferior a la 
			//Que ha hecho el jugador y en caso de serlo se sobreescribe y se
			//Ordena el array para posteriormente sobreescribir el archivo binario

			bool found = false;

			for (int i = 0; i < 10; i++) {
				if (instanciaRank.ranking[i].highScore < aPlayer.highScore && !found) {
					temporal = instanciaRank.ranking[i];
					instanciaRank.ranking[i] = aPlayer;
					found = true;
					i++;
				}
				else if (found) {
					temporal2 = instanciaRank.ranking[i];
					instanciaRank.ranking[i] = temporal;
					temporal = temporal2;
				}
			}
			instanciaRank.OrdenarArray(instanciaRank.ranking, 10);
			instanciaRank.EscribirBinario(dificultad);


			ended = true;
		}

		//En caso de haber terminado los actos finales
		if (ended) {
			//Se hace una llamada al método que varia el atributo que determina si se 
			//va a rankingscene desde la escena de juego o no
			RankingScene::SetFrom(true);

			//Se cambia la escena actual a RankingScene
			SM.SetCurScene<RankingScene>();
		}
	}
}