#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
using namespace std;

// Estructura para representar a un paciente
struct Paciente {
    string nombre;
    int tiempoDeEspera; // El tiempo que lleva esperando
    Paciente* siguiente;
};

#endif // PACIENTE_H
