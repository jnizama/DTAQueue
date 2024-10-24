#ifndef COLAPACIENTES_H
#define COLAPACIENTES_H

#include "Paciente.hpp"

// Clase ColaPacientes implementada como Singleton
class ColaPacientes {
private:
    Paciente* frente;
    Paciente* atras;

    // Constructor privado para el Singleton
    ColaPacientes();

    // Destructor privado
    ~ColaPacientes();

    // Prohibir la copia y asignación
    ColaPacientes(const ColaPacientes&) = delete;
    ColaPacientes& operator=(const ColaPacientes&) = delete;

public:
    // Método estático para obtener la única instancia de la clase (Singleton)
    static ColaPacientes& getInstancia();

    // Verifica si la cola está vacía
    bool estaVacia();

    // Agrega un paciente a la cola
    void registrarPaciente(const string& nombre, int tiempoDeEspera);

    // Atiende al paciente que está al frente de la cola (Desencolar)
    void atenderPaciente();

    // Muestra el paciente que está al frente de la cola
    void mostrarFrente();
};

#endif // COLAPACIENTES_H
