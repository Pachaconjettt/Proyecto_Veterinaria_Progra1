#pragma once
#include "Especialidad.h"
#include "Matrix.h"
#include "Mascota.h"
class Doctor
{
private: 
	string* nombre; 
	string* id; 
	Especialidad* especi; 
	Matrix* horario;
public: 
	Doctor();
	Doctor(string*, string*, Especialidad*, Matrix*);
	void setNombre(string*);
	void setId(string*);
	void setEspecialidad(Especialidad*); 
	string* getNombre(); 
	string* getID();
	Especialidad* getEspecialidad();
	void ingresarCita(int vec[], string paciente); 
	void eliminarCita(string paciente);
	string* pintarMatrizDoctor(); 
	string * toString(); 
	virtual ~Doctor();
};

