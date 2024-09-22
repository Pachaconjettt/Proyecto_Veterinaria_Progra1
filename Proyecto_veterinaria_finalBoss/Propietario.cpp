#include "Propietario.h"

Propietario::Propietario(){
	this->nombre = new string("indef");		
	this->id = new string("indef");
	this->doc = new Doctor();
}
Propietario::Propietario(string* nombre, string* id,Doctor* doc){
	this->setNombre(nombre);
	this->setID(id);
	this->setDoctor(doc);
}
void Propietario::setID(string* id) {
	if (this->id) {
		delete this->id;
	}
	this->id = id; 
}
void Propietario::setNombre(string* nombre){
	if (this->nombre) {
		delete this->nombre;
}
	this->nombre = nombre;
}
void Propietario::setDoctor(Doctor* doctorc) {
	if (this->doc) {
		delete this->doc; 
}
	this->doc = doctorc;
}
Doctor* Propietario::getDoc() { return this->doc; }
string* Propietario::getID() { return this->id; }
string* Propietario::getNombre() { return this->nombre; }
string* Propietario::toString(){
	stringstream s; 
	s << "Nombre del duenno :" <<" "<< *nombre << endl;  
	s << "id del duenno :" <<" "<< *id << endl; 
	return new string(s.str()); 
}
Propietario::~Propietario(){
	delete nombre;
	delete id;
}