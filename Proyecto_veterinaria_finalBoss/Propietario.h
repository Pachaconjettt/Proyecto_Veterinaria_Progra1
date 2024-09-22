#pragma once
#include "Doctor.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std; 
class Doctor; 

class Propietario
{
private: 
	string* id; 
	string* nombre;
	Doctor* doc;
public: 
	Propietario();
	Propietario(string*, string*, Doctor*); 
	void setID(string*);
	void setNombre(string*);
	void setDoctor(Doctor*);
	Doctor* getDoc();
	string* getID();
	string* getNombre();
	string* toString();
	virtual ~Propietario();
};

