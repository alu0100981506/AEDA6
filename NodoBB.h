#ifndef __NODOBB__
#define __NODOBB__

#include <iostream>
#include "Colisiones.h"
using namespace std;

template <class T>
class NodoBB {
public:
	T               dato_;
	NodoBB<T>*      izq_;
	NodoBB<T>*      der_;
	Colisiones colisiones;


	NodoBB(T dato)
	{
		dato_ = dato;
		izq_ = NULL;
		der_ = NULL;
	}

	~NodoBB(void)
	{
	}


	void set_dato(T dato)
	{
		dato_ = dato;
	}

	T get_dato(void) const
	{
		return dato_;
	}

	NodoBB<T>*& get_izq(void)
	{
		return izq_;
	}

	NodoBB<T>*& get_der(void)
	{
		return der_;
	}



	void insertar_izq(NodoBB<T> dato)
	{
		*izq_ = dato;
	}

	void insertar_der(NodoBB<T> dato)
	{
		*der_ = dato;
	}

	friend std::ostream& operator<<(std::ostream& os, const NodoBB<T>& nodo)
	{
		os << nodo.get_dato();
		return os;
	}

	void masUno() {

		colisiones.masUno();
		
	}

};

#endif