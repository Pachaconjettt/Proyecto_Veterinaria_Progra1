#include "MascotaLista.h"
MascotaLista::MascotaLista(){
	this->cantidad = new int(0);
	this->tamano = new int(10);
	this->vector = new Mascota * [*tamano];
	inicializarVector();
}
MascotaLista::MascotaLista(int* tamano){
	this->cantidad = new int(0);
	this->tamano = tamano;
	this->vector = new Mascota * [*this->tamano];
	inicializarVector();
}
Mascota* MascotaLista::buscarMascota(string* nombre) {
	for (int i = 0; i < *cantidad; i++) {
		if (*(vector[i]->getNombre()) == *nombre) {
			return vector[i];
	}
	}
	return nullptr;
}
string* MascotaLista::ListasDeMascotaDe(Propietario* duennio){
	if (duennio == nullptr || duennio->getID() == nullptr) {
		return new string("Propietario no válido.");
	}
	stringstream s;
	bool found = false;
	for (int i = 0; i < *cantidad; i++) {
		if (vector[i] != nullptr && vector[i]->getPropietario() != nullptr && vector[i]->getPropietario()->getID() != nullptr) {
			if (*(vector[i]->getPropietario()->getID()) == *(duennio->getID())) {
				s << *(vector[i]->toString()) << endl;
				found = true;
			}	
		}
	}
	if (!found) {
		s << "Ningun animal registrado bajo el ID de este propietario.." << endl;
	}
	return new string(s.str());
}
bool* MascotaLista::AgregarMascota(Mascota* nuevo){
	if (buscarMascota(nuevo->getNombre()) == nullptr && *cantidad < *tamano) {
		vector[*cantidad] = nuevo;
		(*cantidad)++;
		return new bool(true);
}
	return new bool(false);
}
string* MascotaLista::RetornoMascotas(){
	stringstream s; 
	for (int i = 0; i < *cantidad; i++) {
		s << "- " << " " << i + 1 << "\n" << *(vector[i]->toString()) << endl;
	}
	return new string(s.str());
}
MascotaLista::~MascotaLista(){
	for (int i = 0; i < *cantidad; i++) {
		delete vector[i];
}
	delete[] vector;
	delete cantidad; 
	delete tamano; 
}