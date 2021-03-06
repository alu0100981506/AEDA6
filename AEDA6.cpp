#include <iostream>
#include <vector>

#include "ABB.h"
#include "DNI.h"

int DNI::comparaciones_ = 0;

void update_data(int comparaciones, int& min, int& max, int& med);

void result(int min, int max, int med, int p);
int main(void)
{
	srand(99989984546);

	// Menu principal

	int opcion = 0;
	do
	{
		system("@cls");
		std::cout << "0 - Salir" << std::endl;
		std::cout << "1 - Modo desmostracion" << std::endl;
		std::cout << "2 - Modo estadistica" << std::endl;
		std::cout << std::endl << ">> ";
		std::cin >> opcion;

	} while ((opcion != 1) && (opcion != 2) && (opcion != 0));

	switch (opcion)
	{
		// Salir
	case 0:
		break;

		// Modo demostración
	case 1:
	{

		system("@cls");
		std::cout << "~ Modo demostracion ~" << std::endl << std::endl;

		ABB<int> arbol;

		do
		{
			system("@cls");

			std::cout << arbol;
			std::cout << "\n\n\n";

			std::cout << "0 - Salir" << std::endl;
			std::cout << "1 - Insertar clave" << std::endl;
			std::cout << "2 - Eliminar clave" << std::endl;
			std::cout << std::endl << ">> ";
			std::cin >> opcion;


			if (opcion == 1 || opcion == 2){
				int dato;
				std::cout << ">> ";
				std::cin >> dato;

				if (opcion == 1)
					arbol.insertar(dato);

				else
					arbol.eliminar(dato);

				opcion = -1;
			}

		} while (opcion != 0);
		break;
	}
	case 2:
		// Modo estadística
	{
		system("@cls");
		std::cout << "~ Modo estadistica ~" << std::endl << std::endl;


		// Pedir datos
		int n, nPruebas;
		std::cout << "Tamaño del arbol (numero de nodos del arbol) >> ";
		std::cin >> n;
		std::cout << "Numero de repeticiones de insercion/busqueda que se realiza en el experimento >> ";
		std::cin >> nPruebas;
		std::cout << std::endl << std::endl;


		// Crear banco e insertar la mitad a un ABB
		std::vector<DNI> banco(2 * n);

		ABB<DNI>  arbol;
		for (int i = 0; i<n; i++)
			arbol.insertar(banco[i]);


		// BUSQUEDA
		DNI::comparaciones_ = 0;
		int min = 0;
		int acumulado = 0;
		int maximo = 0;


		for (int i = 0; i < nPruebas; i++)
		{
			DNI::comparaciones_ = 0;

			NodoBB<DNI>* tmp = arbol.buscar(banco[i]);

			if (i == 0)
			{
				min = DNI::comparaciones_;
				maximo = DNI::comparaciones_;
			}

			update_data(DNI::comparaciones_, min, maximo, acumulado);

		}

		std::cout << "Busqueda:     " << std::endl;
		result(min, maximo, acumulado, nPruebas);


		// INSERCIÓN
		DNI::comparaciones_ = 0;
		min = 0;
		acumulado = 0;
		maximo = 0;

		for (int i = n; i < (n + nPruebas); i++)
		{
			DNI::comparaciones_ = 0;
			NodoBB<DNI>* tmp = arbol.buscar(banco[i]);

			if (i == n)
			{
				min = DNI::comparaciones_;
				maximo = DNI::comparaciones_;
			}

			update_data(DNI::comparaciones_, min, maximo, acumulado);

		}

		std::cout << "Insercion:    " << std::endl;
		result(min, maximo, acumulado, nPruebas);



		break;
	}
	}
}



void update_data(int comparaciones, int& min, int& max, int& med)
{
	if (min == -1) min = comparaciones;
	else if (comparaciones < min) min = comparaciones;

	if (max == -1) max = comparaciones;
	else if (comparaciones > max) max = comparaciones;

	med += comparaciones;

}


void result(int min, int max, int med, int p)
{
	std::cout << "min " << min << ", max " << max << ", media " << (float)med / (float)p << std::endl;
}