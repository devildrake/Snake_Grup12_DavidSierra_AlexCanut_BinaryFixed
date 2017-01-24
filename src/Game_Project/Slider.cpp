#include "Slider.h"

using namespace std;

//Constructor de la clase para inicializar valores
Slider::Slider() {
	imagen.objectID = ObjectID::S_15;
	imagen.transform.x = 0;
	imagen.transform.y = 0;
	imagen.transform.h = 0;
	imagen.transform.w = 0;
	originalSize = 0;
}

//Destructor de la clase
Slider::~Slider() {

}

//Método que actualiza el transform.w del sprite imagen
//En función de los dos Uint64 recibidos
void Slider::StartSlider(int aX, int aY,int size) {
	imagen.transform.x = aX;
	imagen.transform.y = aY;
	imagen.transform.h = 20;
	imagen.transform.w = 20;
	originalSize = size;
}

//Método que cambia los valores de posición y anchura original
//a los parametros recibidos
void Slider::Update(Uint64 remainingTime,Uint64 totalTime) {

	//Se crean variables locales igualadas a los parámetros y se 
	//crea otra variable local que es la división de estos dos
	//la cual se multiplica por el tamaño original (máximo del sprite
	//y lo acorta/alarga en consecuencia


	float remainTemp = (float)remainingTime;
	float totalTemp = (float)totalTime;
	float temp = (remainTemp / totalTemp) ;
	imagen.transform.w = originalSize*temp;

}

//Método que pinta el sprite imagen
void Slider::Draw() {
	imagen.Draw();
}