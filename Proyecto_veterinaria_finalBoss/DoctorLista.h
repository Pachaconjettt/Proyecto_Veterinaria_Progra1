#pragma once
#include "Doctor.h"
class DoctorLista
{
private:
	int* cantidad; 
	int* tamano; 
	Doctor** vector; 
	void inicializarVector() {
		for (int i = 0; i < *cantidad; i++) {
			vector[i] = new Doctor();
	}
	}
public:
	DoctorLista();
	DoctorLista(int*); 
	Doctor* buscarDoctor(string*);
	bool AgregarDoctor(Doctor* );
	void ingresarHoraCita(int vec[], string * , Doctor *);
	string* ListaDoctoresEspecialidad(Especialidad*); 
	string* RetornoDoctor();
	string* HorarioDeDoctor(Doctor *); 
	virtual ~DoctorLista();
};

