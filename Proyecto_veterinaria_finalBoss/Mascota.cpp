#include "Mascota.h"
Mascota::Mascota(){
	this->nombre = new string("indef");
	this->animal = new string("indef");
	this->duennio = new Propietario();
}
Mascota::Mascota(string* nombre, string* animal, Propietario* nuevo/*, Doctor * doc*/){
	this->setNombre(nombre); 
	this->setAnimal(animal);
	this->setDuennio(nuevo);
	//this->setDoctor(doc);
}
void Mascota::setNombre(string* nombre){
	if (this->nombre) {
		delete this->nombre;
	}
	this->nombre = nombre;
}
void Mascota::setAnimal(string* animal){
	if (this->animal) {
		delete this->animal;
}
	this->animal = animal;
}
void Mascota::setDuennio(Propietario* propietario){
	if (this->duennio) {
		delete this->duennio;
}
	this->duennio = propietario;
}
//void Mascota::setDoctor(Doctor* doc) {
//	if (this->doc) {
//		delete this->doc;
//	}
//	this->doc = doc;
//}
//Doctor* Mascota::getDoctor() { return this->doc; }
string* Mascota::getNombre() { return this->nombre; }
string* Mascota::getAnimal() { return this->animal; }
Propietario* Mascota::getPropietario() { return this->duennio; }
string* Mascota::toString(){
	stringstream s; 
	s << "------ Mascota ------" << endl;
	s << "Nombre :" << " " << *nombre << endl;
	s << "Que animal es ?" << " " << *animal << endl;
	if (duennio != nullptr) {
		s << *(duennio->toString()) << endl;
	}
	else {
		s << "No existe propietario" << endl; 
	}
	return new string(s.str());
}
Mascota::~Mascota(){
	delete nombre;
	delete animal;
	delete duennio;
}