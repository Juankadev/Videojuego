#pragma once
#include <stdio.h>

class Estadisticas
{
private:
	int choques;
	FILE* f;
public:
	void setChoques(int c);
	int getChoques();
	bool leerDeDisco();
	bool GrabarEnDisco();
};

