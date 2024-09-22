#pragma once
#include "DoctorLista.h"
#include "MascotaLista.h"
class Cita
{
private: 
	DoctorLista* docCita; 
	MascotaLista* MascotaCita; 
	Doctor* doc; 
	Mascota* mascota;
public: 
	Cita();
	Cita(Doctor *, Mascota*,DoctorLista*, MascotaLista *); 
	/*string* SacarCita(Propietario*);
	string* MostarCitaDeDoctor();*/
	/*bool* CancelarCita();
	string* MostrarLasCitasDeMasc(Propietario *);
	virtual ~Cita();*/
};

