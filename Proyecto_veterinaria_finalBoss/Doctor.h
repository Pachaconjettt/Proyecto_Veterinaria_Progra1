#pragma once
#include "Especialidad.h"
#include "Matrix.h"
#include "Mascota.h"

class Mascota;	
class Matrix;

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
	Matrix* getMatrix();
	void ingresarCita(int vec[], Mascota *);
	void eliminarCita(int dia, int hora, string * paciente);
	string* BuscarNombreEspecifico(string*);
	string* pintarMatrizDoctor(); 
	string * toString(); 
	virtual ~Doctor();
};

