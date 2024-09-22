#pragma once
#include "Mascota.h"
class MascotaLista
{
private:
	int* cantidad;
	int* tamano;
	Mascota** vector;
	void inicializarVector() {
		for (int i = 0; i < *cantidad; i++) {
			vector[i] = new Mascota();
		}
	}
public:
	MascotaLista();
	MascotaLista(int*); 
	Mascota* buscarMascota(string *);
	string* ListasDeMascotaDe(Propietario*); 
	bool* AgregarMascota(Mascota* nuevo);
	//string* ListaDoctoresPorId(Doctor * hola);
	string* RetornoMascotas(); 
	virtual ~MascotaLista();
};

