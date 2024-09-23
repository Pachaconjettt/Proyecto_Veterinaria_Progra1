#include "Propietario.h"

Propietario::Propietario(){
	this->nombre = new string("indef");		
	this->id = new string("indef");
}
Propietario::Propietario(string* nombre, string* id){
	this->setNombre(nombre);
	this->setID(id);
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