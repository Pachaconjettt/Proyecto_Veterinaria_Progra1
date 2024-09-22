#pragma once
#include "Propietario.h"
#include "Doctor.h"
class Mascota
{
private: 
	string* nombre; 
	string* animal; 
	Propietario* duennio; 
	//Doctor* doc;

public: 
	Mascota();
	Mascota(string*, string*, Propietario*/*, Doctor **/);
	void setNombre(string *);
	void setAnimal(string*);
	void setDuennio(Propietario*); 
	/*void setDoctor(Doctor *);	
	Doctor * getDoctor(); */
	string* getNombre();
	string* getAnimal();
	Propietario* getPropietario();
	string* toString();
	virtual ~Mascota();
};

