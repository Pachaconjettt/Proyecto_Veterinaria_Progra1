#include "Interfaz.h"
Interfaz::Interfaz(){
	this->PropiLista = new PropietarioLista();
	this->DocLista = new DoctorLista();
	this->MascLista = new MascotaLista();
	this->EspeciLista = new EspecialidadLista();
}

void Interfaz::Menu() {
	cout << "**********************************************" << endl;
	cout << "* Bienvenido a la Interfaz de la Veterinaria *" << endl;
	cout << "**********************************************" << endl;
	cout << "Presione enter para empezar......." << endl;
	cin.get();
	system("cls");
	int opcion = 1;
	while (opcion != 0) {
		cout << "*********************************************" << endl;
		cout << "*               MENU PRINCIPAL              *" << endl;
		cout << "*********************************************" << endl;
		cout << "* (1) Submenu Administracion                *" << endl;
		cout << "* (2) Submenu Control de Citas              *" << endl;
		cout << "* (3) Submenu Busquedas y Listados          *" << endl;
		cout << "* (0) Salir                                 *" << endl;
		cout << "*********************************************" << endl;
		cout << "Digite una opcion del menu: ";
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
	cout << "Nombre del doctor :" << endl;
	cin >> *nombre;
	cout << "ID del doctor :" << endl;
	cin >> *id;
	cout << "Especialidades disponibles : \n";
	cout << *EspeciLista->RetornoEspecialidad() << endl;
	cout << endl;
	Especialidad* especialidad = nullptr;
	while (especialidad == nullptr) {
		cout << "Ingresa nombre de especialidad :" << endl;
		cin >> *Idirector;
		especialidad = EspeciLista->buscarEspecialidad(Idirector);
		if(especialidad == nullptr)
			cout << "Especialidad no encontrada. Por favor, intente de nuevo." << endl;
		else
			cout << "Especialidad ingresada correctamente...." << endl;
		cin.get();
		cin.get();
	}
	Matrix* horario = new Matrix();
	Doctor* doctorUI = new Doctor(new string(*nombre), new string(*id), especialidad, horario);
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
	Propietario* due = new Propietario(new string(*nombre), new string(*id));
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
	cout << endl;
	cout << *PropiLista->RetornoListaPropietario() << endl;
	Propietario* propietario = nullptr;
	while (propietario == nullptr) {
		cout << "Ingresa el id del duennio de la mascota :" << endl;
		cin >> *idPropietario;
		propietario = PropiLista->BuscarPropietario(idPropietario);
		if (propietario == nullptr)
			cout << "Propietario no encontrado. Por favor,intenta de nuevo..." << endl;
		else
			cout << "Propietario encontrado con exito..." << endl;
		cin.get();
		cin.get();
	}
	Mascota* MascotaUI = new Mascota(new string(*nombre), new string(*animal), propietario);
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
	//Preguntar por el propietario....
	cout << "\n" << *PropiLista->RetornoListaPropietario() << endl;
	Propietario* propietario = nullptr;
	while (propietario == nullptr) {
		cout << "Ingrese el id del duennio de la/s mascota/s :" << endl; 
		cin >> *id;
		propietario = PropiLista->BuscarPropietario(id); 
		if (propietario == nullptr)
		{
			cout << "Propietario no encontrado. Por favor, intente de nuevo...." << endl;
		}
		else
			cout << "Propietario encontrado con exito!!!" << endl; 
		cin.get();
	}
//Preguntar sobre que mascota escoger....
	cout << *(MascLista->ListasDeMascotaDe(propietario)) << endl;
	Mascota* mascota = nullptr; 
	while (mascota == nullptr) {
		cout << "¿Cual mascota quiere elegir? " << endl; 
		cin >> *nombre;
		mascota = MascLista->buscarMascota(nombre);
		if (mascota == nullptr) {
			cout << "Mascota no encontrada. Por favor, intente de nuevo...." << endl;
		}
		else
			cout << "Mascota encontrada con exito!!! " << endl <<endl; 
		cin.get();
	}
	Especialidad* especialidad = nullptr;
	while (especialidad == nullptr) {
		cout << *EspeciLista->RetornoEspecialidad() << endl;
		cout << endl << "Ingrese el nombre de la especialidad deseada :" << endl; 
		cin >> *nombreEspeci;
		especialidad = EspeciLista->buscarEspecialidad(nombreEspeci); 
		if (especialidad == nullptr) {
			cout << "Especialidad no encontrada. Por favor, intente de nuevo...." << endl;
		}
		else
			cout << "Especialidad encontrada con exito !!!" << endl;
		cin.get(); 
	}
//Preguntar sobre el doctor....
	Doctor* doctor = nullptr; 
	while (doctor == nullptr) {
		cout << *(DocLista->ListaDoctoresEspecialidad(especialidad)) << endl;
		cout << "Ingrese el id del doctor al que le gustaria que fuera atendido : " << endl; 
		cin >> *IdDoctor; 
		doctor = DocLista->buscarDoctor(IdDoctor); 
		if (doctor == nullptr) {
			cout << "El id del doctor que ingreso es invalido. Por favor ingrese uno correcto..." << endl;
		}
		else
			cout << "Se ha ingresado correctamente el id del doctor..." << endl;
		cin.get();
	}
// Horario del doctor y otras cosas....
	cout << "HORARIO DEL DOCTOR SELECCIONADO :" << endl;
	cout << endl;
	cout << *(DocLista->HorarioDeDoctor(DocLista->buscarDoctor(IdDoctor))) << endl;
	cout << "ELIGA UNA HORA Y UN DIA DISPONIBLE PARA LA CITA :" << endl;
	cout << endl; 
	cout << "Ingrese la hora (8-19 , formato 24hrs ): " << endl;
	cin >> vec[0];
	cout << "Ingrese el dia (0-5, donde 0 es Lunes y 5 es sabado) :" << endl;
	cin >> vec[1];
	DocLista->ingresarHoraCita(vec, mascota, doctor);
	cout << endl;
	cout << *(DocLista->HorarioDeDoctor(doctor)) << endl;
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
	string* masct = new string(" ");
	int dia;
	int hora;
	cout << "-------------------CANCELAR CITA----------------------" << endl;
	// Preguntar acerca de que propietario quiere que cancele la cita...
	cout << "Duennios guardados en el sistema :" << endl; 
	cout << *PropiLista->RetornoListaPropietario() << endl;
	Propietario* propietario = nullptr;
	while (propietario == nullptr) {
		cout << "Ingrese el id del duennio que tiene la cita :" << endl; 
		cin >> *idDuennio;
		propietario = PropiLista->BuscarPropietario(idDuennio);
		if (propietario == nullptr)
			cout << "Propietario no encontrado en el sistema. Por favor ingrese uno valido...." << endl;
		else
			cout << "Propietario ingresado correctamente...." << endl; 
		cin.get();
	}
	// Validar el id del mr doctor
	Doctor* doc = nullptr; 
	while (doc == nullptr) {
		cout << " Marque el doctor con el que tiene cita :" << endl;
		cout << *(DocLista->ListaDoctoresXIdCita(idDuennio)) << endl;
		cout << "Ingrese el id del doctor con el que quiere cancelar cita..." << endl; 
		cin >> *idDoctor; 
		doc = DocLista->buscarDoctor(idDoctor);
		if (doc == nullptr)
			cout << "Doctor no encontrado. Ingrese uno valido...." << endl;
		else
			cout << "Doctor encontrado con exito!!!" << endl; 
		cin.get();
	}
	Mascota* mascota = nullptr; 
	while (mascota == nullptr) {
		cout << *MascLista->ListasDeMascotaDe(propietario) << endl;
		cout << "Digite el nombre de la mascota que quiere cancelar la cita :" << endl; 
		cin >> *masct; 
		mascota = MascLista->buscarMascota(masct); 
		if (mascota == nullptr)
			cout << "Mascota no encontrada con exito. Por favor digite uno valido..." << endl;
		else
			cout << "Mascota encontrada con exito!!!" << endl; 
		cin.get(); 
	}
	cout << *(DocLista->HorarioDeDoctor(doc)) << endl;
	cout << "Ingrese el dia que quiere quitar la mascota(Recordar que Lunes es 0 y Domingo es 5) :" << endl;
	cin >> dia; 
	cout << "Ingrese la hora del dia que quiere quitar (Formato 24hrs ): " << endl;
	cin >> hora; 
	DocLista->eliminarCita(dia, hora, masct, doc);
	cout << "Horario actualizado del doctor :" << endl; 
	cout << endl;
	cout << *(DocLista->HorarioDeDoctor(doc)) << endl;
	cin.get();
	cin.get();
}

void Interfaz::opcion3_2() {
	string* nombre = new string(" ");
	cout << "---------------- MOSTRAR CALENDARIO DE CITAS POR DOCTOR -------------------" << endl;
	Doctor* doctor = nullptr; 
	cout << *DocLista->RetornoDoctor() << endl; 
	while (doctor == nullptr) {
		cout << "Ingrese el id del doctor para saber el calendario de este mismo :" << endl;
		cin >> *nombre;
		doctor = DocLista->buscarDoctor(nombre);
		if (doctor == nullptr) {
			cout << "Doctor no encontrado. Por favor ingrese uno valido...." << endl;
		}
		else
			cout << "Doctor encontrado con exito!!!" << endl; 
		cin.get();
	}
	cout << "Horario del doctor seleccionado durante la semana...." << endl;
	cout << *(DocLista->HorarioDeDoctor(DocLista->buscarDoctor(nombre))) << endl;
	cin.get();	
}
void Interfaz::opcion4_2() {
	string* nombre = new string(" ");
	string* mascotaName = new string(" ");
	cout << "----------------- MOSTRAR CITAS POR PROPIETARIO ---------------" << endl;
	cout << *PropiLista->RetornoListaPropietario() << endl;
	Propietario* propietario = nullptr;
	while (propietario == nullptr) {
		cout << "Ingrese el id del propietario que desea ver las citas que tiene :" << endl;
		cin >> *nombre; 
		propietario = PropiLista->BuscarPropietario(nombre);
		if (propietario == nullptr)
			cout << "Propietario no encontrado. Por favor ingrese uno valido..." << endl;
		else
			cout << "Propietario encontrado con exito..." << endl;
		cin.get();
	}
	cout << "Lista de mascotas del propietario :" << endl;
	cout << endl;
	Mascota* mascota = nullptr; 
	cout << *MascLista->ListasDeMascotaDe(PropiLista->BuscarPropietario(nombre)) << endl;
	while (mascota == nullptr) {
		cout << "Escriba el nombre de la mascota( A como esta en el sistema es decir sin agregar mayusculas o algun cambio pequenio) :" << endl;
		cin >> *mascotaName;
		mascota = MascLista->buscarMascota(mascotaName);
	}
	cout << "Citas que tiene la mascota :" << endl;
	cout << endl; 
	cout << *DocLista->BuscarNombreEspecifico(mascotaName) << endl; 

	delete nombre;
	delete mascotaName;
	cin.get();
	cin.get();
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
	if (*EspeciLista->RetornoEspecialidad() == "") {
		cout << "No se ha encontrado especialidades....." << endl;
	}
	else 
	{
		cout << *EspeciLista->RetornoEspecialidad() << endl;
	}
	cin.get(); 
	cin.get();
}
void Interfaz::opcion2_3() {
	cout << "----------------------------- Mostrar Doctores Por Especialidad  -------------------------------" << endl << endl; 
	if (*EspeciLista->RetornoEspecialidad() == "")
	{
		cout << "No hay especialidades registradas." << endl;
	}
	else
	{
		string* aux_especialidad = new string(" ");
		Especialidad* especialidadUI = nullptr; 
		cout << *EspeciLista->RetornoEspecialidad() << endl;
		cout << "Digite el nombre de una especialidad para ver sus doctores: " << endl;
		cin >> *aux_especialidad; 

		especialidadUI = EspeciLista->buscarEspecialidad(aux_especialidad);

		while (especialidadUI == nullptr) { 
			cout << "Ingrese una especialidad valida: " << endl;
			cin >> *aux_especialidad; 
			especialidadUI = EspeciLista->buscarEspecialidad(aux_especialidad); 
		}
		cout << "Doctores de la especialidad " << *aux_especialidad << ": " << endl; 
		cout << *DocLista->ListaDoctoresEspecialidad(especialidadUI) << endl;

		delete aux_especialidad; 
	}
	cin.get(); 
	cin.get();
}
void Interfaz::opcion3_3() {
	cout << "----------------------------- Mostar Duennios con sus Mascotas  ---------------------------------" << endl << endl;
	if (*PropiLista->RetornoListaPropietario() == "") {
		cout << "No hay duennios existentes " << endl; 
	}
	string* id = new string(" ");
	Propietario* duenioUi = nullptr;
	cout << "Digite el id del duenio del cual quiera ver sus mascotas : " << endl;
	cout << *PropiLista->RetornoListaPropietario() << endl; 
	cin >> *id; 

	duenioUi = PropiLista->BuscarPropietario(id);

	while (duenioUi == nullptr) {
		system("cls"); 
		cout << "Id invalido. Intente de nuevo." << endl; 
		cin >> *id; 
		duenioUi = PropiLista->BuscarPropietario(id);
	}
	system("cls"); 
	if (*MascLista->ListasDeMascotaDe(duenioUi) == "") {
		cout << "El duenio no tiene mascotas registradas." << endl; 
	}
	else
	{
		cout << *MascLista->ListasDeMascotaDe(duenioUi) << endl; 
	}
	cin.get();
	cin.get();
}
void Interfaz::opcion4_3() {
	cout << "----------------------------- Mostrar Pacientes por Doctor ----------------------------------" << endl << endl;
	if (*DocLista->RetornoDoctor() == "") {
		cout << "No hay doctores registrados." << endl; 
	}
	else {
		string * id = new string("");
		Doctor* aux = nullptr; 
		cout << *DocLista->RetornoDoctor() << endl;  
		cout << "Digite el id del doctor del cual quiera ver sus pacientes: " << endl; 
		cin >> *id; 

		aux = DocLista->buscarDoctor(id);
		while (aux == nullptr) {
			system("cls"); 
			cout << "Id invalido. Intente de nuevo..." << endl; 
			cin >> *id; 
			aux = DocLista->buscarDoctor(id); 
		}
		system("cls"); 
		if (*aux->getMatrix()->imprimirPropietariosXDoctor() == "") {
			cout << "El doctor no tiene pacientes." << endl; 
		}
		else {
			cout << "Pacientes registrados (Mascotas que tiene el doctor) : " << endl; 
			cout << *aux->getMatrix()->imprimirPropietariosXDoctor() << endl;
		}
		delete aux;
	}
	cin.get();
	cin.get();
}