#include "ColaPacientes.hpp"
#include <iostream>

using namespace std;

void mostrarMenu() {
    cout << "\n--- Menu ---" << endl;
    cout << "1. Registrar Paciente" << endl;
    cout << "2. Atender Paciente" << endl;
    cout << "3. Mostrar Paciente al Frente" << endl;
    cout << "0. Salir" << endl;
    cout << "Ingrese una opción: ";
}

int main() {
    ColaPacientes& cola = ColaPacientes::getInstancia(); // Obtiene la instancia única de ColaPacientes

    int opcion;
    string nombre;
    int tiempoDeEspera;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: // Registrar Paciente
                cout << "Ingrese el nombre del paciente: ";
                cin >> nombre;
                cout << "Ingrese el tiempo de espera: ";
                cin >> tiempoDeEspera;
                cola.registrarPaciente(nombre, tiempoDeEspera);
                break;

            case 2: // Atender Paciente
                cola.atenderPaciente();
                break;

            case 3: // Mostrar Paciente al Frente
                cola.mostrarFrente();
                break;

            case 0: // Salir
                cout << "Saliendo del programa." << endl;
                break;

            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 0);

    return 0;
}
