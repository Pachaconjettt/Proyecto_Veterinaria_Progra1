#include "Matrix.h"

Matrix::Matrix(){
	columnas = new int(6); 
	filas = new int(12); 
	horasOcupadas = new int(0); 
	matriz = new string * *[*columnas];
	matriz = new string * *[*columnas];
	for (int i = 0; i < *columnas; i++) {
		matriz[i] = new string * [*filas];
		for (int j = 0; j < *filas; j++) {
			matriz[i][j] = new string("Disponible");
		}
	}
}
void Matrix::ingresarCita(int vec[], string paciente){
	int dia = vec[1]; 
	int hora = vec[0]; 
	if (hora < 8 || hora > 19 || dia < 0 || dia >= *columnas) {
		cout << "Curso no pudo ser ingresado. Dia o hora incorrectos.....\n";
}
	else if (*matriz[dia][hora - 8] != "Disponible") {
		cout << "Cita no pudo ser ingresada. Hora ya ocupada......\n"; 
	}
	else
	{
		*matriz[dia][hora - 8] = paciente; 
		(*horasOcupadas)++;
		cout << "Cita ingresada exitosamente. \n"; 
	}
}
void Matrix::eliminarCita(string paciente){
	for (int i = 0; i < *columnas; i++) {
		for (int j = 0 ; j < *filas; j++) {
			if (*matriz[i][j] == paciente) {
				*matriz[i][j] = "Disponible";
			}
		}
	}
}
string* Matrix::buscarHoraEspecifica(int hora, int dia) {
	return matriz[dia][hora - 8]; 
}
string* Matrix::buscarNombreEspecifico(string nombre, int& count) {
    count = 0;
    string* citas = new string[*columnas * *filas];
    string dias[] = { "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };

    for (int i = 0; i < *columnas; i++) {
        for (int j = 0; j < *filas; j++) {
            if (*matriz[i][j] == nombre) {
                int horaReal = j + 8;
                citas[count] = dias[i] + " a las " + to_string(horaReal) + ":00";
                count++;
            }
        }
    }
    return citas;
}

string * Matrix::pintarMatriz(){
	stringstream t; 
	string dias[] = { "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
	int ancho_columnas = 12; //Ancho fijo cada columna es decir de 8 a 19 
	int columnas = 6; 
	int longitud_total = (ancho_columnas * columnas) + (columnas + 18);
	t << " Hora  |  " << setw(ancho_columnas) << left << dias[0]
		<< "|  " << setw(ancho_columnas) << left << dias[1]
		<< "|  " << setw(ancho_columnas) << left << dias[2]
		<< "|  " << setw(ancho_columnas) << left << dias[3]
		<< "|  " << setw(ancho_columnas) << left << dias[4]
		<< "|  " << setw(ancho_columnas) << left << dias[5] << "|\n"; 

	t << string(longitud_total, '-') << endl;

	for (int hora = 0; hora < *filas; hora++) {
		int horaReal = hora + 8; 
		t << (horaReal < 10 ? " " : "") << horaReal << ":00  |";

		for (int dia = 0; dia < columnas; dia++) {
			t << "  " << setw(ancho_columnas) << left << *matriz[dia][hora] << "|"; 
	}
		t << endl;
		t << string(longitud_total, '-') << endl;
	}
	return new string(t.str());
}
Matrix::~Matrix(){
	for (int i = 0; i < *columnas; i++) {
		for (int j = 0; j < *filas; j++) {
			delete matriz[i][j];
		}
		delete matriz[i];
}
	delete [] matriz;
	delete columnas;
	delete filas; 
	delete horasOcupadas;
}