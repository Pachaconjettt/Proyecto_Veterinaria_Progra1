#include "Especialidad.h"

Especialidad::Especialidad() {
	nombre = new string("indef"); 
	id = new string("indef");
}
Especialidad::Especialidad(string* nombre, string* id) {
	this->setNombre(nombre);
	this->setID(id);
}
void Especialidad::setNombre(string* nombre) { 
	if (this->nombre) {
	delete this->nombre; 
	}
	this->nombre = nombre;
}
void Especialidad::setID(string* id) { 
	if (this->id) {
		delete this->id; 
	}
	this->id = id; }
string* Especialidad::getNombre() { return this->nombre; }
string* Especialidad::getID() { return this->id; }
string* Especialidad::toString(){
	stringstream s; 
	s << "Especialidad :" <<" "<< *nombre << endl;
	s << "Id de la especialidad :" <<" "<< *id << endl;
	return new string(s.str());
}
Especialidad::~Especialidad(){
	delete nombre;
	delete id; 
}