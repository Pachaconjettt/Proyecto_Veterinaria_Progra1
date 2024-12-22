#include "DoctorLista.h"
#include <sstream>

DoctorLista::DoctorLista() {
    this->cantidad = new int(0);
    this->tamano = new int(10);
    this->vector = new Doctor*[*tamano];
    inicializarVector();
}

DoctorLista::DoctorLista(int* tamano) {
    this->cantidad = new int(0);
    this->tamano = tamano;
    this->vector = new Doctor*[*this->tamano];
    inicializarVector();
}

Doctor* DoctorLista::buscarDoctor(string* id) {
    for (int i = 0; i < *cantidad; i++) {
        if (*(vector[i]->getID()) == *id) {
            return vector[i];
        }
    }
    return nullptr;
}

bool DoctorLista::AgregarDoctor(Doctor* nuevo) {
    if (buscarDoctor(nuevo->getID()) == nullptr && *cantidad < *tamano) {
        vector[*cantidad] = nuevo;
        (*cantidad)++;
        return true;
    }
    return false;
}

string* DoctorLista::ListaDoctoresEspecialidad(Especialidad* nuevo) {
    stringstream s;
    bool found = false;
    for (int i = 0; i < *cantidad; i++) {
        if (*(vector[i]->getEspecialidad()->getNombre()) == *(nuevo->getNombre())) {
            s << *(vector[i]->toString()) << endl;
            found = true;
        }
    }
    if (!found) {
        s << "Especialidad no encontrada..." << endl;
    }
    return new string(s.str());
}

string* DoctorLista::HorarioDeDoctor(Doctor* nuevo) {
    stringstream s;
    for (int i = 0; i < *cantidad; i++) {
        if (*(vector[i]->getID()) == *(nuevo->getID())) {
            return vector[i]->pintarMatrizDoctor();
        }
    }
    s << "No existe horario..." << endl;
    return new string(s.str());
}

void DoctorLista::ingresarHoraCita(int vec[], Mascota * nombre, Doctor* nuevo) {
    for (int i = 0; i < *cantidad; i++) {
        if (*(vector[i]->getID()) == *(nuevo->getID())) {
            vector[i]->ingresarCita(vec, nombre);
        }
    }
}
void DoctorLista::eliminarCita(int dia, int hora, string* nombre,  Doctor* nuevo) {
    for (int i = 0; i < *cantidad; i++) {
        if (*(vector[i]->getID()) == *(nuevo->getID())) {
            vector[i]->eliminarCita(dia, hora, nombre); 
        }
        }
}
string *DoctorLista::BuscarNombreEspecifico(string* nombre) {
        stringstream s;
        for (int i = 0; i <*cantidad; i++) {
            s << *vector[i]->BuscarNombreEspecifico(nombre) << endl;
        }
        return new string(s.str());
    }
string* DoctorLista::ListaDoctoresXIdCita(string* pepe) {
    stringstream s; 
    for (int i = 0; i < *cantidad; i++) {
        if (vector[i]->getMatrix()->BuscarPropietarioXMascota(pepe) != nullptr) {
            s << *(vector[i]->toString()) << endl; 
        }
        }
    return new string(s.str());
}
string* DoctorLista::RetornoDoctor() {
    stringstream s;
    for (int i = 0; i < *cantidad; i++) {
        s << " -" << " " << i + 1 << "\n" << *(vector[i]->toString()) << endl;
    }
    return new string(s.str());
}
DoctorLista::~DoctorLista() {
    for (int i = 0; i < *cantidad; i++) {
        delete vector[i];
    }
    delete[] vector;
    delete cantidad;
    delete tamano;
}
