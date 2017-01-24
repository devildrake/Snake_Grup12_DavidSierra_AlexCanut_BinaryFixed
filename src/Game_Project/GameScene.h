#pragma once
#include "Scene.h"
#include "Sprites.h"
#include "Snake.h"
#include "Slider.h"
#include <fstream>
#include <stdio.h>
#include <strstream>
#include "Niveles.h"
#include "MainMenu.h"
#include "InputManager.h"
#include "Logger.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include <time.h>
#include "XML.h"
#include <math.h>
#include <utility>
#include "Ranking.h"
#include "Score.h"
#include "RankingScene.h"
#include "Vidas.h"
#include "Tabla.h"

//Clase GameScene que conglomera la mayoría de los demás elemento del juego y gestiona algunas
//de sus interacciónes

class GameScene : public Scene
{
public: 

	//Variable que guarda el numero de columnas y filas
	static int columnaFila;

	//Constructor, se inicializa la posicion de cada uno de los sprites mencionados y le asignamos su imagen
	explicit GameScene();

	//Destructor de la clase
	~GameScene() override;
	
	//Método llamado cuando el estado de la escena cambia a RUNNING
	//Que inicializa hasStarted y grid.wasMade en false para poder 
	//Volver a crear un grid y llamar a la función Start
	void OnEntry(void) override;

	//Método llamado cuando el estado de la escena cambia a SLEEPING
	void OnExit(void) override;

	//Método que se llama cada vez que se llama al Update general, el cual
	//Hace llamadas a todos los métodos que son necesarios para actualizar
	//el mundo de juego
	void Update(void) override;

	//Método que se llama en el Draw general de GameEngine.h y que pinta todos los
	//elementos que forman parte de GameScene y deben ser pintados
	void Draw(void) override;

	//Método que comprueba las colisiones de la cabeza con todas las paredes de la tabla 
	//Y con los obstáculos en caso de que los haya y pone en false el booleano snake.isAlive
	//en caso de detectar colision
	void CheckHit();

	//Método que actualiza la posición en pantalla de la cabeza de la serpiente en función
	//De su posición en tabla y borra el último sprite del vector además de introducir un 
	//nuevo sprite en la segunda posición para generar la sensación de que la serpiente se está 
	//moviendo
	void ActualizarSnake();


	//Método que comprueba las colisiones con la manzana y en caso de haberla
	//Actua en consecuencia
	void CheckManzana();

	//Método que cambia la posición de la Snake a su posición original en tabla
	//Cambia su dirección a 0(nula) y borra todos los trozos de serpiente adicionales
	//en comparación con los que tenía al empezar el nivel en el que se encuentra
	void SnakeSpawn();

	//Método que cambia el "nivel" en el que se encuentra el jugador y actualiza los contadores temporales
	//de manzanas consecutivas sin perder vidas,longitud de la serpiente y puntuación en función de los valores que estos
	//tienen al empezar el nivel, tambien reinicia a 0 las manzanas comidas en el nivel actual.
	void ChangeLevel();


	//Método que coloca la serpiente en su posición original y reinicia los atributos de 
	//puntuación, manzanas comidas consecutivamente sin perder vidas, manzanas comidas 
	//consecutivamente en el nivel actual, las variables de control de movimiento de la serpiente
	//así como su variable de vida. Además realiza llamadas a las funciones de reaparición de serpiente
	//así como de cambio de posición de manzana.
	void Restart();


	//Método que borra el obstaculo previo (si lo hay) y establece uno nuevo en función de la dificultad
	//en una posicion aleatoria teniendo en cuenta las dimensiones del nivel y en funcion de un numero random
	void SetObstacle();

	//Método que dibuja todos los sprites que conforman el obstaculo actual
	void DrawObstacle();

	//Método que comprueba si las vidas de la serpiente son 0, y de serlo 
	//pone en true el booleano gameOver
	void GameOverCheck();

	//Método al que se llama en caso de que el booleano hasStarted sea false 
	//cada vez que se llama al método Update() y que se dedica a incializar
	//todos los elementos que considera necesarios para comenzar sin problemas
	//una partida
	void Start();

	//Método que cambia la posición de la manzana a una aleatoria dentro de las dimensiones de la tabla 
	void ChangeManPos(void);

	//Instancia de la clase Slider que representará el tiempo restante del nivel actual al jugador
	Slider timeS;

	//Array de instancias de la clase Vidas que representarán las vidas restantes del jugador
	Vidas lasVidas[3];

	//Instancia de la clase Score que representará la puntuación del jugador en pantalla
	Score scoreDisplay;

	//Instancia de la clase Ranking que se usará para leer y escribir los archivos binarios
	Ranking instanciaRank;

	//Variable que guarda el tiempo por nivel en función de XML
	Uint64 tiempoLevel;

	//Variable que guarda el tiempo por nivel en función de XML pero teniendo en cuenta CurrentTime
	Uint64 realTiempoLevel;

	//Varpiable que guarda el tiempo previo para hacer calculos 
	Uint64 prevTime;

	int dificultad; //0 es easy, 1 es medium 2 es hard

	//Incremento de manzana obtenido por XML
	int applIncrease;

	//Nivel en el que se encuentra el jugador
	int lvl;
	
	//numero de manzanas a comer para pasar al siguiente nivel
	int numapples;

	//Manzanas comidas seguidas sin perder vidas
	int applesComidas;

	//manzanas comidas de forma consecutiva en lo que va de nivel
	int applesComidasNivel;

	//Tamaño orignial del Slider, se lee desed XML
	int sliderSize;

	//booleano que gestiona el fin del juego
	bool gameOver;

	//booleano que gestiona el comienzo del juego
	bool hasStarted;

	//booleano que gestiona la finalización del fin del juego
	bool ended;

	//Variable que guarda la puntuaciónS
	float score;

	//Vector de sprites que forman el obstáculo
	vector <Sprite> obstaculo;

	//Atributo que guarda el numero de columnas
	int numC;

	//Atributo que guarda el numero de filas
	int numR;

	//Sprite de la manzana
	Sprite unaManzana;



private:
	//Atributo que guarda el tiempo restante teniendo en cuenta CurrentTime
	Uint64 remainingTime;

	//Instancia de la clase grid que se usará para representar la tabla y mover 
	//y colocar el resto de elementos de juego
	Tabla grid;

	//Sprite del fondo
	Sprite fondo;
	//Sprite de pared;
	Sprite pared;

	//Sprite de la cabeza del snake
	Snake snake;

	//Sprite de la manzana
	Sprite manzana;

	//Variable de puntuación previa
	int prevScore;

	//Posición Y en tabla de manzana
	int posAY;

	//Posición X en tabla de manzana
	int posAX;

};