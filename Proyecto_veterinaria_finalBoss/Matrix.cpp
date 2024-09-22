#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

Matrix::Matrix() {
    columnas = new int(6);
    filas = new int(12);
    horasOcupadas = new int(0);
    matriz = new std::string * *[*columnas];
    for (int i = 0; i < *columnas; i++) {
        matriz[i] = new std::string * [*filas];
        for (int j = 0; j < *filas; j++) {
            matriz[i][j] = new std::string("Disponible");
        }
    }
}

void Matrix::ingresarCita(int vec[], std::string paciente) {
    int dia = vec[1];
    int hora = vec[0];
    if (hora < 8 || hora > 19 || dia < 0 || dia >= *columnas) {
        std::cout << "Curso no pudo ser ingresado. Dia o hora incorrectos.....\n";
    }
    else if (*matriz[dia][hora - 8] != "Disponible") {
        std::cout << "Cita no pudo ser ingresada. Hora ya ocupada......\n";
    }
    else {
        *matriz[dia][hora - 8] = paciente;
        (*horasOcupadas)++;
        std::cout << "Cita ingresada exitosamente. \n";
    }
}

void Matrix::eliminarCita(std::string paciente) {
    for (int i = 0; i < *columnas; i++) {
        for (int j = 0; j < *filas; j++) {
            if (*matriz[i][j] == paciente) {
                *matriz[i][j] = "Disponible";
            }
        }
    }
}

std::string* Matrix::buscarHoraEspecifica(int hora, int dia) {
    return matriz[dia][hora - 8];
}

std::string* Matrix::buscarNombreEspecifico(std::string nombre, int& count) {
    count = 0;
    std::string* citas = new std::string[*columnas * *filas];
    std::string dias[] = { "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };

    for (int i = 0; i < *columnas; i++) {
        for (int j = 0; j < *filas; j++) {
            if (*matriz[i][j] == nombre) {
                int horaReal = j + 8;
                citas[count] = dias[i] + " a las " + std::to_string(horaReal) + ":00";
                count++;
            }
        }
    }
    return citas;
}

std::string* Matrix::pintarMatriz() {
    std::stringstream t;
    std::string dias[] = { "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
    int ancho_columnas = 12; // Ancho fijo cada columna es decir de 8 a 19
    int longitud_total = (ancho_columnas * *columnas) + (*columnas + 18);
    t << " Hora  |  " << std::setw(ancho_columnas) << std::left << dias[0]
        << "|  " << std::setw(ancho_columnas) << std::left << dias[1]
        << "|  " << std::setw(ancho_columnas) << std::left << dias[2]
        << "|  " << std::setw(ancho_columnas) << std::left << dias[3]
        << "|  " << std::setw(ancho_columnas) << std::left << dias[4]
        << "|  " << std::setw(ancho_columnas) << std::left << dias[5] << "|\n";

    t << std::string(longitud_total, '-') << std::endl;

    for (int hora = 0; hora < *filas; hora++) {
        int horaReal = hora + 8;
        t << (horaReal < 10 ? " " : "") << horaReal << ":00  |";

        for (int dia = 0; dia < *columnas; dia++) {
            t << "  " << std::setw(ancho_columnas) << std::left << *matriz[dia][hora] << "|";
        }
        t << std::endl;
        t << std::string(longitud_total, '-') << std::endl;
    }
    return new std::string(t.str());
}

Matrix::~Matrix() {
    for (int i = 0; i < *columnas; i++) {
        for (int j = 0; j < *filas; j++) {
            delete matriz[i][j];
        }
        delete[] matriz[i];
    }
    delete[] matriz;
    delete columnas;
    delete filas;
    delete horasOcupadas;
}
