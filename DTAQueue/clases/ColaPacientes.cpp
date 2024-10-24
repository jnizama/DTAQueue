#include "ColaPacientes.hpp"
#include <iostream>

// Constructor privado
ColaPacientes::ColaPacientes() : frente(nullptr), atras(nullptr) {}

// Destructor privado
ColaPacientes::~ColaPacientes() {}

// Obtener la única instancia de la clase (Singleton)
ColaPacientes& ColaPacientes::getInstancia() {
    static ColaPacientes instancia;
    return instancia;
}

// Verifica si la cola está vacía
bool ColaPacientes::estaVacia() {
    return frente == nullptr;
}

// Agrega un paciente a la cola
void ColaPacientes::registrarPaciente(const string& nombre, int tiempoDeEspera) {
    Paciente* nuevoPaciente = new Paciente();
    nuevoPaciente->nombre = nombre;
    nuevoPaciente->tiempoDeEspera = tiempoDeEspera;
    nuevoPaciente->siguiente = nullptr;

    // Si la cola está vacía, este será el primer paciente
    if (estaVacia()) {
        frente = nuevoPaciente;
        atras = nuevoPaciente;
    } else {
        // Agregamos el nuevo paciente al final
        atras->siguiente = nuevoPaciente;
        atras = nuevoPaciente;
    }

    std::cout << "Paciente registrado: " << nombre << " (Tiempo de espera: " << tiempoDeEspera << ")" << std::endl;
}

// Atiende al paciente que está al frente de la cola
void ColaPacientes::atenderPaciente() {
    if (estaVacia()) {
        std::cout << "No hay pacientes en la cola para atender." << std::endl;
        return;
    }

    Paciente* temp = frente;
    std::cout << "Atendiendo al paciente: " << temp->nombre << " (Tiempo de espera: " << temp->tiempoDeEspera << ")" << std::endl;
    frente = frente->siguiente;
    delete temp;

    // Si la cola está vacía después de atender
    if (frente == nullptr) {
        atras = nullptr;
    }
}

// Muestra el paciente que está al frente de la cola
void ColaPacientes::mostrarFrente() {
    if (estaVacia()) {
        std::cout << "No hay pacientes en la cola." << std::endl;
    } else {
        std::cout << "Paciente al frente: " << frente->nombre << " (Tiempo de espera: " << frente->tiempoDeEspera << ")" << std::endl;
    }
}
