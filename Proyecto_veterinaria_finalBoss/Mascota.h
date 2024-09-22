#pragma once
#include "Propietario.h"

class Propietario; 

class Mascota
{
private: 
	string* nombre; 
	string* animal; 
	Propietario* duennio;

public: 
	Mascota();
	Mascota(string*, string*, Propietario*);
	void setNombre(string *);
	void setAnimal(string*);
	void setDuennio(Propietario*); 
	string* getNombre();
	string* getAnimal();
	Propietario* getPropietario();
	string* toString();
	virtual ~Mascota();
};

