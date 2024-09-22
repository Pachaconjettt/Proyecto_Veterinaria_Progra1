#include "Interfaz.h"
Interfaz::Interfaz(){
	this->PropiLista = new PropietarioLista();
	this->DocLista = new DoctorLista();
	this->MascLista = new MascotaLista();
	this->EspeciLista = new EspecialidadLista();
}

void Interfaz::Menu() {
	int opcion = 1; 
	while (opcion != 0) {
		cout << "---------------MENU PRINICIPAL--------------" << endl; 
		cout << "(1) Submenu Administracion " << endl; 
		cout << "(2) Submenu Control de Citas" << endl;
		cout << "(3) Submenu Busquedas y Listados" << endl;
		cout << "(0) Salir " << endl << endl; 
		cout << "---------------------------------------------" << endl; 
		cout << "Digite una opcion del menu :"; 
		cin >> opcion; 
		switch (opcion) {
		case 1: 
			system("cls");
			SubmenuAdministracion();
			break; 
		case 2: 
			system("cls");
			SubmenuControlCitas();
			break;
		case 3: 
			system("cls"); 
			SubmenuBusqueda();
			break;
		case 0: 
			cout << "Saliendo del programa..." << endl;
			break;
		default: 
			cout << "Opcion incorrecta  ";
			break; 
		}
		system("cls");
	}
	exit(0);
	system("cls");
}
void Interfaz::SubmenuAdministracion() {
	int opcionSubmenu1 = 1;
	while (opcionSubmenu1 != 0) {
		cout << "-------------------SUBMENU ADMINISTRACION-----------------" << endl;
		cout << "(1) Ingresar Especialidades " << endl;
		cout << "(2) Ingresar Doctor(por especialidad) " << endl;
		cout << "(3) Ingresar Duennio " << endl;
		cout << "(4) Ingresar Mascota (por duennio) " << endl;
		cout << "(0) Regresar al menu principal " << endl << endl;
		cout << "------------------------------------------------------------" << endl; 
		cout << "Digite una opcion del submenu :";
		cin >> opcionSubmenu1;
		switch (opcionSubmenu1) {
		case 1: 
			system("cls"); 
			opcion1_1();
			break; 
		case 2: 
			system("cls");
			opcion2_1();
			break;
		case 3:
			system("cls");
			opcion3_1();
			break;
		case 4: 
			system("cls");
			opcion4_1();
			break;
		case 0:
			cout << "Saliendo del submenu ...." << endl;
			break;
			cin.get();
			cin.get();
		default : 
			cout << "Opcion incorrecta ";
			break;
			cin.get();
			cin.get();
		}
		system("cls");
	}
	system("cls");
}
void Interfaz::opcion1_1(){
	string* nombre = new string(" ");
	string* id = new string(" ");
	cout << "-------------------------------(1) Ingresar Especialidad --------------------------" << endl;
	cout << "Ingresa el nombre de la especialidad :" << endl;
	cin >> *nombre; 
	cout << "Ingresa el id de la especialidad :" << endl;
	cin >> *id;
	Especialidad* especi = new Especialidad(new string(*nombre), new string(*id));
	EspeciLista->AgregarEspecialidad(especi);
	delete nombre;
	delete id;
}
void Interfaz::opcion2_1(){
	string* nombre = new string(" ");
	string* id = new string(" ");
	string* Idirector = new string(" ");
	cout << "------------------(2) Ingresar Doctor -----------------------------" << endl;
	cout << "Nombre de doctor" << endl;
	cin >> *nombre;
	cout << "ID del doctor " << endl;
	cin >> *id;
	cout << "Ingresa nombre de especialidad " << endl;
	cin >> *Idirector;
	Matrix* horario = new Matrix();
	Doctor* doctorUI = new Doctor(new string(*nombre), new string(*id), EspeciLista->buscarEspecialidad(Idirector), horario);
	DocLista->AgregarDoctor(doctorUI);
	delete nombre;
	delete id;
	delete Idirector;
	//cout << "---------------------------- MOSTRAR ESPECIALIDADES EXISTENTES ---------------------" << endl << endl;
	//cout << *(vete->RetornoEspecialidades()) << endl; 
	//cin.get(); //Esto es para guardar espacios...
	//cin.get();
}
void Interfaz::opcion3_1(){
	string* nombre = new string(" ");
	string* id = new string(" "); 
	cout << "------------------------------(3) Ingresar Duennio-------------------------" << endl; 
	cout << "Ingrese el nombre del duennio :" << endl;
	cin >> *nombre; 
	cout << "Ingrese el id del duennio :" << endl;
	cin >> *id;
	Propietario* due = new Propietario(new string(*nombre), new string(*id), new Doctor());
	PropiLista->AgregarPropietario(due);
	delete nombre; 
	delete id;
	//string* nombre = new string(" ");
	//string* id = new string(" ");
	//string* Idirector = new string(" ");
	//cout << "------------------(3) Insertar Doctor -----------------------------" << endl;
	//cout << "Nombre de doctor" << endl;
	//cin >> *nombre;
	//cout << "ID del doctor " << endl;
	//cin >> *id; 
	//cout << "Ingresa nombre de especialidad " << endl;
	//cin >> *Idirector;
	//Doctor* doctorUI = new Doctor(new string(*nombre), new string(*id), vete->buscaEspecialidad(Idirector));
	//vete->agregarDoctores(doctorUI);
	//delete nombre; 
	//delete id; 
	//delete Idirector;
}
void Interfaz::opcion4_1(){
	string* nombre = new string(" ");
	string* animal = new string(" "); 
	string* idPropietario = new string(" ");
	cout << "--------------------------------------(4) Ingresar Mascota-----------------------" << endl;
	cout << "Ingrese el nombre de la mascota :" << endl;
	cin >> *nombre; 
	cout << "Ingrese que animal es :" << endl;
	cin >> *animal;
	cout << "Ingrese el id del duennio :" << endl;
	cin >> *idPropietario;
	Mascota* MascotaUI = new Mascota(new string(*nombre), new string(*animal), PropiLista->BuscarPropietario(idPropietario));
	MascLista->AgregarMascota(MascotaUI);
	delete nombre;
	delete animal;
	delete idPropietario;
	//cout << "----------------------------- (4) Mostar Doctores existentes -------------------------------" << endl << endl; 
	//cout << *(vete->retornoDoctores()) << endl;
	//cin.get(); //Esto es para guardar espacios...
	//cin.get();
}
void Interfaz::SubmenuControlCitas() {
	int opcionSubmenu2 = 1;
	while (opcionSubmenu2 != 0) {
		cout << "--------------------------- SUBMENU CONTROL CITAS -------------------------------" << endl;
		cout << "(1) Sacar Cita" << endl;
		cout << "(2) Cancela Cita" << endl;
		cout << "(3) Mostar Calendario de Citas por Doctor" << endl;
		cout << "(4) Mostar Citas por Duennio" << endl;
		cout << "(0) Regresar al menu Principal" << endl << endl;
		cout << "-----------------------------------------------------------------------------------" << endl;
		cout << "Digite una opcion del submenu :";
		cin >> opcionSubmenu2; 
		switch (opcionSubmenu2) {
		case 1: 
			system("cls");
			opcion1_2();
			break;
		case 2: 
			system("cls"); 
			opcion2_2();
			break; 
		case 3: 
			system("cls");
			opcion3_2();
			break; 
		case 4:
			system("cls");
			opcion4_2();
			break; 
		case 0: 
			cout << "Saliendo del submenu...." << endl; 
		default: 
			cout << "Opcion incorrecta  ";
			break; 
		}
		system("cls");
	}
	system("cls");
}
void Interfaz::opcion1_2() {
	string* id = new string(" ");
	string* nombre = new string(" ");
	string* nombreEspeci = new string(" ");
	string* IdDoctor = new string(" ");
	int vec[2];
	cout << "-----------------------SACAR CITA---------------------" << endl;
	cout << "Ingrese el id del duennio de las mascota/s :" << endl;
	cin >> *id;
	Propietario* propietario = PropiLista->BuscarPropietario(id);
	cout << *(MascLista->ListasDeMascotaDe(propietario)) << endl;
	cout << "Cual mascota quiere elegir :" << endl;
	cin >> *nombre;
	cout << "Ingrese el nombre de la especialidad deseada " << endl;
	cin >> *nombreEspeci;
	cout << *(DocLista->ListaDoctoresEspecialidad(EspeciLista->buscarEspecialidad(nombreEspeci))) << endl;
	cout << "Ingrese el id del doctor al que le gustaria ser atendido :" << endl;
	cin >> *IdDoctor;
	cout << "HORARIO DEL DOCTOR SELECCIONADO :" << endl;
	cout << endl;
	cout << *(DocLista->HorarioDeDoctor(DocLista->buscarDoctor(IdDoctor))) << endl;
	cout << "ELIGA UNA HORA Y UN DIA DISPONIBLE PARA LA CITA :" << endl;
	cout << "Ingrese la hora (8-19): " << endl;
	cin >> vec[0];
	cout << "Ingrese el dia (0-5, donde 0 es Lunes y 5 es sabado) :" << endl;
	cin >> vec[1];
	DocLista->ingresarHoraCita(vec, nombre, DocLista->buscarDoctor(IdDoctor));

	// Agregar el doctor al propietario específico
	PropiLista->AgregarDoctorAPropietario(DocLista->buscarDoctor(IdDoctor));

	cout << endl;
	cout << *(DocLista->HorarioDeDoctor(DocLista->buscarDoctor(IdDoctor))) << endl;
	cin.get();
	cin.get();

	delete id;
	delete nombre;
	delete nombreEspeci;
	delete IdDoctor;
}


void Interfaz::opcion2_2() {
	string* idDuennio = new string("indef");
	string* idDoctor = new string(" ");
	cout << "-------------------CANCELAR CITA----------------------" << endl;
	cout << "Ingrese el id del duennio :" << endl;
	cin >> *idDuennio;
	Propietario* propietario = PropiLista->BuscarPropietario(idDuennio);

	if (propietario == nullptr) {
		cout << "Propietario no encontrado." << endl;
		delete idDuennio;
		delete idDoctor;
		return;
	}

	cout << "Doctores con los que tiene cita sus mascotas :" << endl;
	cout << *(PropiLista->DocCitasPorId(propietario));
	cout << "Ingrese el id del doctor con el que desea cancelar la cita:" << endl;
	cin >> *idDoctor;

	Doctor* doctor = DocLista->buscarDoctor(idDoctor);
	if (doctor == nullptr) {
		cout << "Doctor no encontrado." << endl;
		delete idDuennio;
		delete idDoctor;
		return;
	}

	cout << "Ingrese el nombre de la mascota para cancelar la cita:" << endl;
	string* nombreMascota = new string(" ");
	cin >> *nombreMascota;

	doctor->eliminarCita(*nombreMascota);
	cout << "Cita cancelada exitosamente." << endl;

	delete idDuennio;
	delete idDoctor;
	delete nombreMascota;
	cin.get();
	cin.get();
}

void Interfaz::opcion3_2() {
	cout << "En construccion" << endl;
}
void Interfaz::opcion4_2() {
	cout << "Ya le dije! En construccion " << endl;
}
void Interfaz::SubmenuBusqueda() {
	int opcionSubmenu3 = 1; 
	while (opcionSubmenu3 != 0) {
		cout << "-------------------------- SUBMENU BUSQUEDA Y LISTADO ----------------------------" << endl; 
		cout << "(1) Mostrar Listado de Especialidades " << endl;
		cout << "(2) Mostar Lista de Doctores por Especialidad " << endl;
		cout << "(3) Mostar Duennios con sus Mascotas " << endl;
		cout << "(4) Mostrar Pacientes por doctor " << endl;
		cout << "(0) Regresar al Menu Principal " << endl;
		cout << "----------------------------------------------------------------------------------" << endl;
		cout << "Digite una opcion del submenu :";
		cin >> opcionSubmenu3;
		switch (opcionSubmenu3) {
		case 1:
			system("cls");
			opcion1_3();
			break;
		case 2:
			system("cls");
			opcion2_3();
			break;
		case 3: 
			system("cls");
			opcion3_3();
			break;
		case 4:
			system("cls");
			opcion4_3();
			break;
		case 0:
			cout << "Saliendo del submenu ...." << endl;
			break;
		default: 
			cout << "Opcion incorrecta ";
			break;
		}
		system("cls");
	}
	system("cls");
}
void Interfaz::opcion1_3() {
	cout << "---------------------------- Mostrar Especialidades Existentes ---------------------" << endl << endl;
	cout << *(EspeciLista->RetornoEspecialidad()) << endl; 
	cin.get(); 
	cin.get();
}
void Interfaz::opcion2_3() {
	cout << "----------------------------- Mostrar Doctores Existentes -------------------------------" << endl << endl; 
	cout << *(DocLista->RetornoDoctor()) << endl;
	cin.get(); 
	cin.get();
}
void Interfaz::opcion3_3() {
	cout << "----------------------------- Mostrar Duennios Existentes ---------------------------------" << endl << endl;
	cout << *(PropiLista->RetornoListaPropietario()) << endl;
	cin.get();
	cin.get();
}
void Interfaz::opcion4_3() {
	cout << "----------------------------- Mostrar Mascotas existentes ----------------------------------" << endl << endl;
	cout << *(MascLista->RetornoMascotas()) << endl;
	cin.get();
	cin.get();
}