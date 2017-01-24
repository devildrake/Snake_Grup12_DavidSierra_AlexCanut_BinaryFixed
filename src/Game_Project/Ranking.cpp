#include "Ranking.h"
/*
//Método que lee los datos del archivo binario y los escribe en la variable ranking
void Ranking::LeerBinario(int n) {

		if (n == 0) {

			ifstream fentrada("rankingEasy.dat", ios::in | ios::binary);
			fentrada.read(reinterpret_cast<char *>(&ranking), sizeof(ranking));
			fentrada.close();
		}
		else if (n == 1) {
			ifstream fentrada("rankingMedium.dat", ios::in | ios::binary);
			fentrada.read(reinterpret_cast<char *>(&ranking), sizeof(ranking));
			fentrada.close();
		}
		else if (n == 2) {
			ifstream fentrada("rankingHard.dat", ios::in | ios::binary);
			fentrada.read(reinterpret_cast<char *>(&ranking), sizeof(ranking));
			fentrada.close();
		}

		else {
		}
}
*/
void Ranking::EscribirBinario(int n) {

	if (n == 0) {
		ofstream fSalida("rankingEasy.dat", ios::out | ios::binary);

		for (int i = 0; i < 10; i++) {
			size_t size2Write = ranking[i].nameSize;
			fSalida.write(reinterpret_cast<char*>(&size2Write), sizeof(size_t));
			fSalida.write(ranking[i].name.data(), size2Write);
			fSalida.write(reinterpret_cast<char*>(&ranking[i].highScore), sizeof(int));
		}
		fSalida.close();
	}
	else if (n == 1) {
		ofstream fSalida("rankingMed.dat", ios::out | ios::binary);

		for (int i = 0; i < 10; i++) {
			size_t size2Write = ranking[i].nameSize;
			fSalida.write(reinterpret_cast<char*>(&size2Write), sizeof(size_t));
			fSalida.write(ranking[i].name.data(), size2Write);
			fSalida.write(reinterpret_cast<char*>(&ranking[i].highScore), sizeof(int));
		}
		fSalida.close();
	
	}
	else if (n == 2) {
		ofstream fSalida("rankingHard.dat", ios::out | ios::binary);

		for (int i = 0; i < 10; i++) {
			size_t size2Write = ranking[i].nameSize;
			fSalida.write(reinterpret_cast<char*>(&size2Write), sizeof(size_t));
			fSalida.write(ranking[i].name.data(), size2Write);
			fSalida.write(reinterpret_cast<char*>(&ranking[i].highScore), sizeof(int));
		}
		fSalida.close();
	
	}
}

inline bool exist(string fileName) {
	ifstream file(fileName);
	if (!file) {
		return false;
	}
	else {
		return true;
	}
}

void Ranking::LeerBinario(int n) {

	if (n == 0) {


		if (!exist("rankingEasy.dat")) {
			ofstream fSalida("rankingEasy.dat", ios::out | ios::binary);
			for (int i = 0; i < 10; i++) {
				size_t size2Write = ranking[i].nameSize;
				fSalida.write(reinterpret_cast<char*>(&size2Write), sizeof(size_t));
				fSalida.write(ranking[i].name.data(), size2Write);
				fSalida.write(reinterpret_cast<char*>(&ranking[i].highScore), sizeof(int));
			}
			fSalida.close();
		}

		ifstream fEntrada("rankingEasy.dat", ios::in | ios::binary);

		for (int i = 0; i < 10; i++) {
			size_t size2Read = ranking[i].nameSize;
			fEntrada.read(reinterpret_cast<char*>(&size2Read), sizeof(size_t));
			ranking[i].name = std::string("", size2Read);
			fEntrada.read(&*ranking[i].name.begin(), size2Read);
			fEntrada.read(reinterpret_cast<char*>(&ranking[i].highScore), sizeof(int));
		}
		fEntrada.close();
	}
	else if (n == 1) {

		if (!exist("rankingMed.dat")) {
			ofstream fSalida("rankingMed.dat", ios::out | ios::binary);
			for (int i = 0; i < 10; i++) {
				size_t size2Write = ranking[i].nameSize;
				fSalida.write(reinterpret_cast<char*>(&size2Write), sizeof(size_t));
				fSalida.write(ranking[i].name.data(), size2Write);
				fSalida.write(reinterpret_cast<char*>(&ranking[i].highScore), sizeof(int));
			}
			fSalida.close();
		}


		ifstream fEntrada("rankingMed.dat", ios::in | ios::binary);

		for (int i = 0; i < 10; i++) {
			size_t size2Read = ranking[i].nameSize;
			fEntrada.read(reinterpret_cast<char*>(&size2Read), sizeof(size_t));
			ranking[i].name = std::string("", size2Read);
			fEntrada.read(&*ranking[i].name.begin(), size2Read);
			fEntrada.read(reinterpret_cast<char*>(&ranking[i].highScore), sizeof(int));
		}
		fEntrada.close();
	
	}
	else if (n == 2) {
		if (!exist("rankingHard.dat")) {
			ofstream fSalida("rankingHard.dat", ios::out | ios::binary);
			for (int i = 0; i < 10; i++) {
				size_t size2Write = ranking[i].nameSize;
				fSalida.write(reinterpret_cast<char*>(&size2Write), sizeof(size_t));
				fSalida.write(ranking[i].name.data(), size2Write);
				fSalida.write(reinterpret_cast<char*>(&ranking[i].highScore), sizeof(int));
			}
			fSalida.close();
		}

		ifstream fEntrada("rankingHard.dat", ios::in | ios::binary);

		for (int i = 0; i < 10; i++) {
			size_t size2Read = ranking[i].nameSize;
			fEntrada.read(reinterpret_cast<char*>(&size2Read), sizeof(size_t));
			ranking[i].name = string("", size2Read);
			fEntrada.read(&*ranking[i].name.begin(), size2Read);
			fEntrada.read(reinterpret_cast<char*>(&ranking[i].highScore), sizeof(int));
		}
		fEntrada.close();
	
	}
}


/*
//Método que escribe los datos de la variable ranking en el archivo binario
void Ranking::EscribirBinario(int n) {
	if (n == 0) {
		ofstream fsalida("rankingEasy.dat", ios::out | ios::binary);
		fsalida.write(reinterpret_cast<char *>(&ranking), sizeof(ranking));
		fsalida.close();
	}
	else if (n == 1) {
		ofstream fsalida("rankingMedium.dat", ios::out | ios::binary);
		fsalida.write(reinterpret_cast<char *>(&ranking), sizeof(ranking));
		fsalida.close();
	}
	else if (n == 2) {
		ofstream fsalida("rankingHard.dat", ios::out | ios::binary);
		fsalida.write(reinterpret_cast<char *>(&ranking), sizeof(ranking));
		fsalida.close();
	}
}
*/
//Método que ordena el array ranking, recibe el array a ordenar y su longitud
void Ranking::OrdenarArray(jugador arr[],int length) {
		jugador temp;
		int i, j;
		for (i = 0; i < (length); i++)
		{
			for (j = (i + 1); j < length; j++)
			{
				if (arr[i].highScore < arr[j].highScore)
				{
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
}

//Constructor 
Ranking::Ranking() {
	for (int i = 0; i < 10; i++) {
		ranking[i] = p1;
	}
}

/*
//Destructor
Ranking::~Ranking() {
	//delete[] ranking;
}*/