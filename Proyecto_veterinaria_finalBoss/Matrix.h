#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std; 
class Matrix
{
private:
	int * filas; 
	int * columnas; 
	int * horasOcupadas; 
	string*** matriz;
public:
	Matrix(); 
	void ingresarCita(int vec[], string); 
	void eliminarCita(string);
	string * buscarHoraEspecifica(int, int); 
	string* buscarNombreEspecifico(string,int &count);
	string * pintarMatriz();
	virtual ~Matrix(); 
};

