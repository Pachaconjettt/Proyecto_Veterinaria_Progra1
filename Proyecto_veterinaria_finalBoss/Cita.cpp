#include "Cita.h"
Cita::Cita() {
	docCita = new DoctorLista(); 
	MascotaCita = new MascotaLista();
	doc = new Doctor();
	mascota = new Mascota();
}
Cita::Cita(Doctor* doc, Mascota* masc, DoctorLista* Doctor, MascotaLista* Mascota) {
	this->docCita = Doctor;
	this->MascotaCita = Mascota;
	this->doc = doc;
	this->mascota = masc;
}
//string* Cita::SacarCita(Propietario* propietario) {
//	stringstream s;
//	if (mascota->getPropietario()->getID() == propietario->getID()) {
//		s << doc[i]->toString() << endl;
//	}
//}
//string* Cita::MostarCitaDeDoctor();
//bool* Cita::CancelarCita();
//string* Cita::MostrarLasCitasDeMasc(Propietario*);
//virtual ~Cita();