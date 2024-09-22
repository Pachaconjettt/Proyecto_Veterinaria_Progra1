#pragma once
#include "Propietario.h"

class PropietarioLista
{
private: 
	int* cantidad; 
	int* tamano; 
	int* cantidadDoctores;
	int* tamanoDoctores;
	Propietario** vector; 
	Doctor** vectorDoc; 
	void inicializarVector() {
		for (int i = 0; i < *tamano; i++) {
			vector[i] = new Propietario();
		}
	}
public: 
	PropietarioLista(); 
	PropietarioLista(int*, int*);
	Propietario* BuscarPropietario(string* id); 
	string* DocCitasPorId(Propietario*);
	void AgregarDoctorAPropietario(Doctor* doctor);
	bool* AgregarPropietario(Propietario* nuevo);
	string* RetornoListaPropietario();
	virtual ~PropietarioLista(); 
};

