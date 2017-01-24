#include "RankingScene.h"



//Booleano estatico inicializado en false que gestiona 
//el desde que escena se accede a la escena RankingScene
static bool deGame = false;


//Constructor que inicializa drawn en false
RankingScene::RankingScene() {
	drawn = false;

}

//Destructor
RankingScene::~RankingScene() {

}

void RankingScene::SetFrom(bool uh) {
	if (uh) {
		deGame = true;
	}
	else {
		deGame = false;
	}
}

//Función ejecutada al cambiar el estado de la escena a RUNNING
void RankingScene::OnEntry(void) {
	for (int i = 0; i < 10; i++) {
		texturaScore[i] = NULL;
		texturaNombres[i] = NULL;
	}
	background.objectID = ObjectID::S_00;
	background.transform = {0,0,W.GetWidth(),W.GetHeight()};
	backButton.objectID = ObjectID::S_14;
	backButton.transform = { W.GetWidth() / 8 , W.GetHeight()/8*5,200,200};
	difficulty.transform.w = 0;
	difficulty.transform.h = 0;
	
	set = false;
}

//Función ejecutada al cambiar el estado de la escena a SLEEPING
void RankingScene::OnExit(void) {
}

//Función ejecutada en el Update General de escenas de GameEngine
void RankingScene::Update(void) {
	static MouseCoords mouseCoords(0, 0); //variable q recoje la coordenadas del puntero del mouse al darle click

	if (IM.IsMouseDown<MOUSE_BUTTON_LEFT>()) { //si hace click izquierdo con el raton
		mouseCoords = IM.GetMouseCoords();
		if ((mouseCoords.x >= backButton.transform.x && mouseCoords.x <= backButton.transform.x+backButton.transform.w) && (mouseCoords.y >= backButton.transform.y && mouseCoords.y <= backButton.transform.y+backButton.transform.h)) {
			SM.SetCurScene<MainMenu>();
		}
	}

	if (!set) {
		//Se comprueba de donde viene el jugador, si de el menú o del juego, en caso de venir del menu debe 
		//Escribir por consola 0,1 o 2 para mostrar uno de los rankings.
		//En caso de venir del juego, se consigue de forma automatica la dificultad desde el XML
		if (!deGame) {
			cout << "En que dificultad quieres ver el ranking?" << endl;
			cout << "0: Fácil" << endl;
			cout << "1: Medio" << endl;
			cout << "2: Dificil" << endl;

			bool finished = false;


			while (!finished) {
				cin >> dif;
				if (dif == 0 || dif == 1 || dif == 2) {
					finished = true;
					system("cls");
				}
				else {
					cout << "Invalid Number" << endl;
				}

			}
		}
		else {
			dif = Niveles::GetValue("Dificultad");
		}

		//Se leen los archivos binarios en función de la dificultad
		instanciaRank.LeerBinario(dif);

		set = true;

		SetScores();

		MakeTextures();
		set = true;
		difficulty.transform = { W.GetWidth() / 8 * 6,0,200,200 };

		//Este switch cambia la imagen del Sprite que representa la dificultad que se esta mostrando en el ranking en este momento
		switch (dif) {
		case 0:
			difficulty.objectID = ObjectID::S_03;
			break;
		case 1:
			difficulty.objectID = ObjectID::S_04;
			break;
		case 2:
			difficulty.objectID = ObjectID::S_05;
			break;
		}
	}

	
}


//Función ejecutada en el Draw General de escenas de Renderer
void RankingScene::Draw(void) {

	background.Draw();
	backButton.Draw();
	difficulty.Draw();
	int startX = 0;
		int startY = W.GetHeight()/13;

		SDL_RenderCopy(R.m_SDLRenderer, ftexture, NULL, &dst); // renderer is a variable of the type `SDL_Renderer*
		for (int i = 0; i < 10; i++) {
			SDL_Rect rectaScore = { startX + W.GetWidth() / 8 * 5, startY*(i+2), t_width/2, t_height/2 };
			SDL_Rect rectaText = { startX + W.GetWidth() / 8 * 3, startY*(i + 2), t_width/2, t_height/2 };

			SDL_RenderCopy(R.m_SDLRenderer, texturaScore[i], NULL, &rectaScore); // renderer is a variable of the type `SDL_Renderer*
			SDL_RenderCopy(R.m_SDLRenderer, texturaNombres[i], NULL, &rectaText); // renderer is a variable of the type `SDL_Renderer*
			//cout<<startY*(i + 1)<<endl;
		}
	
}

//Función que, una vez leídos los archivos desde el binario, establece los valores en los arrays declarados arriba
void RankingScene::SetScores() {

	for (int i = 0; i < 10; i++) {
		puntuacionesAImprimir[i] = instanciaRank.ranking[i].highScore;
		names[i] = instanciaRank.ranking[i].name+"------------------";
		scores[i] = to_string(puntuacionesAImprimir[i]);
	}

}

//Función que hace una textura por cada texto declarado y las asigna a los arrays de texturas declarados arriba
void RankingScene::MakeTextures() {
	SDL_Surface* title_surface = TTF_RenderText_Solid(font, iText.c_str(), text_color);
	ftexture = SDL_CreateTextureFromSurface(R.m_SDLRenderer, title_surface);
	SDL_FreeSurface(title_surface);

	SDL_Surface* superficiesPuntos[10];
	SDL_Surface* superficiesNombres[10];

	for (int i = 0; i < 10; i++) {
		superficiesPuntos[i] = TTF_RenderText_Solid(font, scores[i].c_str(), text_color);
		superficiesNombres[i] = TTF_RenderText_Solid(font, names[i].c_str(), text_color);
		texturaNombres[i] = SDL_CreateTextureFromSurface(R.m_SDLRenderer, superficiesNombres[i]);
		texturaScore[i] = SDL_CreateTextureFromSurface(R.m_SDLRenderer, superficiesPuntos[i]);
		SDL_FreeSurface(superficiesNombres[i]);
		SDL_FreeSurface(superficiesPuntos[i]);
	}
}
