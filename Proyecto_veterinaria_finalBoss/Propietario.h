#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std; 

class Propietario
{
private: 
	string* id; 
	string* nombre;
	Doctor* doc; 
public: 
	Propietario();
	Propietario(string*, string*); 
	void setID(string*);
	void setNombre(string*);
	string* getID();
	string* getNombre();
	string* toString();
	virtual ~Propietario();
};

