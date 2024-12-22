#include "Doctor.h"
Doctor::Doctor() {
	this->nombre = new string("indef");
	this->id = new string("indef"); 
	this->especi = new Especialidad();
	this->horario = new Matrix(); 
}
Doctor::Doctor(string* nombre, string* id, Especialidad* especi, Matrix * horario){
	this->setNombre(nombre);
	this->setId(id); 
	this->setEspecialidad(especi);
	this->horario = horario;
}
void Doctor::setNombre(string* nombre) { 
	if (this->nombre) {
		delete this->nombre;
	}
	this->nombre = nombre; 
}
void Doctor::setId(string* id) { 
	if (this->id) {
	delete this->id;
	}	
	this->id = id;
}
void Doctor::setEspecialidad(Especialidad* especi) { 
	if (this->especi) {
		delete this->especi;
	}
	this->especi = especi; 
}
Matrix * Doctor::getMatrix(){return this->horario;}
string* Doctor::getNombre() { return this->nombre; }
string* Doctor::getID() { return this->id; }
Especialidad* Doctor::getEspecialidad() { return this->especi; }
void Doctor::ingresarCita(int vec[], Mascota * paciente) {
	if (horario) {
	horario->ingresarCita(vec, paciente);
	}
}
void Doctor::eliminarCita(int dia, int hora,string * paciente) {
	this->horario->eliminarCita(dia,hora,paciente);
}
string * Doctor::BuscarNombreEspecifico(string* nombre) {
	return horario->buscarNombreEspecifico(nombre); 
}
string* Doctor::pintarMatrizDoctor() {
	return this->horario->pintarMatriz();
}
string * Doctor::toString(){
	stringstream s; 
	s << "-----------------Doctor-----------------" << endl; 
	s << "Nombre :" <<" "<< *nombre << endl;
	s << "Id :" <<" "<< *id << endl;
	if (especi != nullptr) {
		s << *(especi->toString()) << endl; 
	}
	else {
		s << "No existe especialidad" << endl; 
	}
	return new string(s.str());
}
Doctor::~Doctor(){
	delete nombre;
	delete id;
	delete especi;
	delete horario;
}