#pragma once
#include "Propietario.h"
class PropietarioLista
{
private: 
	int* cantidad; 
	int* tamano; 
	Propietario** vector; 
	void inicializarVector() {
		for (int i = 0; i < *tamano; i++) {
			vector[i] = new Propietario();
		}
	}
public: 
	PropietarioLista(); 
	PropietarioLista(int*);
	Propietario* BuscarPropietario(string* id); 
	bool* AgregarPropietario(Propietario* nuevo);
	string* RetornoListaPropietario();
	virtual ~PropietarioLista(); 
};

