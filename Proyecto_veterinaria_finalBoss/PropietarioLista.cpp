#include "PropietarioLista.h"
PropietarioLista::PropietarioLista() {
	this->cantidadDoctores = new int(0);
	this->cantidad = new int(0);
	this->tamano = new int(10);
	this->tamanoDoctores = new int(10);
	this->vectorDoc = new Doctor * [*tamanoDoctores];
	this->vector = new Propietario * [*tamano];
	for (int i = 0; i < *cantidadDoctores; i++) {
		vectorDoc[i] = new Doctor();
	}
	inicializarVector(); 
}
PropietarioLista::PropietarioLista(int* tamano, int* tamanodoc) {
	this->cantidad = new int(0); 
	this->cantidadDoctores = new int(0);
	this->tamano = tamano;
	this->tamanoDoctores = tamanodoc;
	this->vector = new Propietario * [*tamano];
	this->vectorDoc = new Doctor * [*tamanoDoctores];
	for (int i = 0; i < *cantidadDoctores; i++) {
		vectorDoc[i] = new Doctor();
	}
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
string* PropietarioLista::DocCitasPorId(Propietario* nuevo) {
	for (int i = 0; i < *cantidad; i++) {
		if (*(vector[i]->getID()) == *(nuevo->getID())) {
			return vector[i]->getDoc()->toString();
		}
	}
}
void PropietarioLista::AgregarDoctorAPropietario(Doctor* doctor) {
	if(*cantidadDoctores < *tamanoDoctores){
		vectorDoc[*cantidad] = doctor;
		(*cantidad)++;
}
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