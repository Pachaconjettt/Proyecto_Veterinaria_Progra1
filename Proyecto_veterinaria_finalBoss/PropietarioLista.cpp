#include "PropietarioLista.h"
PropietarioLista::PropietarioLista() {
	this->cantidad = new int(0);
	this->tamano = new int(10);
	this->vector = new Propietario * [*tamano];
	inicializarVector(); 
}
PropietarioLista::PropietarioLista(int* tamano) {
	this->cantidad = new int(0); 
	this->tamano = tamano; 
	this->vector = new Propietario * [*tamano];
	inicializarVector();
}
Propietario* PropietarioLista::BuscarPropietario(string* id) {
	for (int i = 0; i < *cantidad; i++) {
		if (*(vector[i]->getID()) == *id) {
			return vector[i];
	}
	}
	return nullptr; 
}
bool* PropietarioLista::AgregarPropietario(Propietario* nuevo) {
	if (BuscarPropietario(nuevo->getID()) == nullptr && *cantidad < *tamano) {
		vector[*cantidad] = nuevo; 
		(*cantidad)++;
		return new bool(true);
	}
	return new bool(false);
}
string* PropietarioLista::RetornoListaPropietario() {
	stringstream s; 
	for (int i = 0; i < *cantidad; i++) {
		s << "- " << " " << i+1 <<"\n"<< *(vector[i]->toString()) << endl;
	}
	return new string(s.str());
}
PropietarioLista::~PropietarioLista() {
	for (int i = 0; i < *cantidad; i++) {
		delete vector[i];
	}
	delete[] vector;
	delete cantidad;
	delete tamano;
}