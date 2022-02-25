#include "Estadisticas.h"
#include <iostream>
using namespace std;

void Estadisticas::setChoques(int c)
{
	choques = c;
}

int Estadisticas::getChoques()
{
	return choques;
}

bool Estadisticas::leerDeDisco()
{
	f = fopen("archivos/estadisticas.dat", "rb");
	if (f == NULL) { cout << "Error de apertura" << endl; return false; }
	fread(&choques, sizeof(choques), 1, f);
	fclose(f);

}

//
//cout << "choques: "<< choques <<endl;

bool Estadisticas::GrabarEnDisco()
{
	f = fopen("archivos/estadisticas.txt", "ab");
	if (f == NULL) { cout << "Error de apertura" << endl; return false; }
	fwrite(&choques, sizeof(int), 1, f);
	fclose(f);
}
