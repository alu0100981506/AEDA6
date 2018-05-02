#include "Colisiones.h"



Colisiones::Colisiones(){
	colisiones = 0;
}


Colisiones::~Colisiones()
{
}

void Colisiones::masUno(){
	colisiones++;
	
	cout << colisiones << "º Colision" << endl;
	Sleep(1000);
}

