#ifndef __ABB__
#define __ABB__

#include "NodoBB.h"

#include <iostream>
#include <utility>      // std::pair, std::make_pair
#include <queue>        // std::queue

using namespace std;


template <class T>
class ABB
{
private:
	NodoBB<T>*      raiz_;

public:

	ABB(void)
	{
		raiz_ = NULL;
	}

	~ABB(void)
	{
		podar(raiz_);
	}

	NodoBB<T>* buscar(T dato){
		return buscarRama(raiz_, dato);
	}

	void insertar(T dato){
		insertarRama(raiz_, dato);
	}

	void eliminar(T dato){
		eliminarRama(raiz_, dato);
	}

	friend ostream& operator<<(ostream& os, const ABB<T>& arbol){
		queue<pair<NodoBB<T>*, int> > Q;
		NodoBB<T>* nodo;
		int nivel, nivel_actual = 0;

		Q.push(make_pair(arbol.raiz_, nivel_actual));

		os << '\n' << nivel_actual << ": ";
		while (!Q.empty()){
			pair<NodoBB<T>*, int> tmp = Q.front();
			Q.pop();

			nivel = get<1>(tmp);

			if (nivel > nivel_actual){
				nivel_actual = nivel;  //Incremento de nivel
				os << '\n' << nivel_actual << ": ";
			}

			NodoBB<T>* nodo_tmp = get<0>(tmp);

			if (nodo_tmp != NULL){
				os << *nodo_tmp << " ";

				Q.push(make_pair(nodo_tmp->get_izq(), nivel_actual + 1));
				Q.push(make_pair(nodo_tmp->get_der(), nivel_actual + 1));
			}

			else{
				os << "[.] ";
			}

		}

		return os;
	}


private:

	void podar(NodoBB<T>* nodo){
		if (nodo == NULL) return;
		podar(nodo->get_izq());
		podar(nodo->get_der());
		delete nodo;
		nodo = NULL;
	}

	NodoBB<T>* buscarRama(NodoBB<T>* nodo, T dato){
		if (nodo == NULL)
			return NULL;

		if (dato == nodo->get_dato())
			return nodo;

		if (dato < nodo->get_dato())
			return buscarRama(nodo->get_izq(), dato);
		else
			return buscarRama(nodo->get_der(), dato);
	}

	void insertarRama(NodoBB<T>* &nodo, T dato){
		if (nodo == NULL)
			nodo = new NodoBB<T>(dato);


		else if (dato < nodo->get_dato())
			insertarRama(nodo->get_izq(), dato);



		else if (nodo->get_dato() < dato)
			insertarRama(nodo->get_der(), dato);

		else if (nodo->get_dato() == dato) {
			nodo->masUno();
		}


	}

	void eliminarRama(NodoBB<T>* &nodo, T dato){
		if (nodo == NULL) return;

		if (dato < nodo->get_dato())
			eliminarRama(nodo->get_izq(), dato);


		else if (nodo->get_dato() < dato)
			eliminarRama(nodo->get_der(), dato);

		else
		{
			NodoBB<T>* eliminado = nodo;

			if (nodo->get_der() == NULL)
				nodo = nodo->get_izq();

			else if (nodo->get_izq() == NULL)
				nodo = nodo->get_der();

			else
				sustituye(eliminado, nodo->get_izq());

			delete eliminado;


		}

	}

	void sustituye(NodoBB<T>* &eliminado, NodoBB<T>* &sust)
	{
		if (sust->get_der() != NULL)
			sustituye(eliminado, sust->get_der());

		else
		{
			eliminado->set_dato(sust->get_dato());
			eliminado = sust;
			sust = sust->get_izq();
		}
	}

};

#endif