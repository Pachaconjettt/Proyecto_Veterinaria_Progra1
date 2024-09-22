#include "EspecialidadLista.h"

EspecialidadLista::EspecialidadLista() {
	this->cantidad = new int(0);
	this->tamano = new int(10);
	this->vector = new Especialidad * [*tamano];
	inicializarEspecialidad();
}
EspecialidadLista::EspecialidadLista(int * tamano){
	this->cantidad = new int(0);
	this->tamano = tamano;
	this->vector = new Especialidad * [*this->tamano];
	inicializarEspecialidad();
}
Especialidad* EspecialidadLista::buscarEspecialidad(string * nombre) {
	for (int i = 0; i < *cantidad; i++) {
		if (*(vector[i]->getNombre()) == *(nombre)) {
			return vector[i];
	}
	}
	return nullptr;
}
bool* EspecialidadLista::AgregarEspecialidad(Especialidad* nuevo) {
	if (buscarEspecialidad(nuevo->getNombre()) == nullptr && *cantidad < *tamano) {
		vector[*cantidad] = nuevo;
		(*cantidad)++;
		return new bool(true);
	}
	return new bool(false); 
}
string* EspecialidadLista::RetornoEspecialidad() {
	stringstream s; 
	for (int i = 0; i < *cantidad; i++) {
		s << "- " <<" "<< i + 1 << "\n" << *(vector[i]->toString()) << endl;
	}
	return new string(s.str());
}
EspecialidadLista::~EspecialidadLista() {
	for (int i = 0; i < *cantidad; i++) {
		delete vector[i];
	}
	delete[] vector; 
	delete cantidad;
	delete tamano; 
}