#pragma once
#include <string>
#include <iostream>
#include "Colisiones.h"

using namespace std;

class DNI {

public:

	string key;
	string nombre_;
	string apellidos_;
	


	static int comparaciones_;

	DNI(string nombre, string apellidos, string dni);

	DNI();

	~DNI();

	DNI(string dni);

	string get_key()const;

	string get_nom();

	string get_ape();

	operator unsigned long() const;

	friend std::ostream& operator<<(std::ostream& os, DNI& M);

	ostream& write(ostream& os)const;

	int operator<(const DNI& M);

	int operator>(const DNI& M);

	int operator<=(const DNI& M);

	bool operator==(DNI &d);

};
