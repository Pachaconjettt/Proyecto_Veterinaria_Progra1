#include "DoctorLista.h"
DoctorLista::DoctorLista(){
	this->cantidad = new int(0);
	this->tamano = new int(10);
	this->vector = new Doctor * [*tamano];
	inicializarVector();
}
DoctorLista::DoctorLista(int* tamano){
	this->cantidad = new int(0);
	this->tamano = tamano;
	this->vector = new Doctor * [*this->tamano];
	inicializarVector();
}
Doctor* DoctorLista::buscarDoctor(string* id){
	for (int i = 0; i < *cantidad; i++) {
		if (*(vector[i]->getID()) == *id) {
			return vector[i];
	}
	}
	return nullptr;
}
bool DoctorLista::AgregarDoctor(Doctor* nuevo){
	if (buscarDoctor(nuevo->getID()) == nullptr && *cantidad < *tamano) {
		vector[*cantidad] = nuevo;
		(*cantidad)++;
	return new bool(true);
}
	return new bool(false);
}
string* DoctorLista::ListaDoctoresEspecialidad(Especialidad * nuevo) {
	stringstream s; 
	for (int i = 0; i < *cantidad; i++) {
		if (*(vector[i]->getEspecialidad()->getNombre())  == *(nuevo->getNombre())) {
			s << *(vector[i]->toString()) << endl; 
		}
		else 
		{
			s << "Especialidad no encontrada..." << endl;
		}
	}
	return new string(s.str());
}
string* DoctorLista::HorarioDeDoctor(Doctor* nuevo) {
	stringstream s; 
	for (int i = 0; i < *cantidad; i++) {
	if (vector[i]->getID() == nuevo->getID()) {
		return vector[i]->pintarMatrizDoctor() ;
	}
	else
	{
		s << "No existe horario..." << endl;
	}	
}
	return new string(s.str());
}
void DoctorLista::ingresarHoraCita(int vec[], string* nombre, Doctor * nuevo) {
	for (int i = 0; i < *cantidad; i++) {
	if (*(vector[i]->getID()) == *(nuevo->getID())){
		vector[i]->ingresarCita(vec, *nombre);
	}
	}
}
string* DoctorLista::RetornoDoctor(){
	stringstream s; 
	for (int i = 0; i < *cantidad; i++) {
		s << " -" << " " << i + 1 << "\n" << *(vector[i]->toString()) << endl;
	}
	return new string(s.str());
}
DoctorLista::~DoctorLista(){
	for (int i = 0; i < *cantidad; i++) {
		delete vector[i];
}
	delete[] vector;
	delete cantidad; 
	delete tamano;
}