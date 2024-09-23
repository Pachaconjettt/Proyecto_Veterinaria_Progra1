#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "Mascota.h"
using namespace std; 

class Mascota;

class Matrix
{
private:
	int * filas; 
	int * columnas; 
	int * horasOcupadas; 
	Mascota*** matriz;
public:
	Matrix(); 
	string * ingresarCita(int vec[], string*); 
	 string * eliminarCita(int dia, int hora,string*);
	bool * BuscarPropietarioXMascota(string*); 
	string* buscarNombreEspecifico(string *);
	string * pintarMatriz();
	virtual ~Matrix(); 
};

