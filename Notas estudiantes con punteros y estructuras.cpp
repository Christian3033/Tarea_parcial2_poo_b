#include <iostream>
using namespace std;

// Definición de la estructura Estudiante
struct Estudiante {
    int id;
    string nombre;
    string apellido;
    float nota1;
    float nota2;
    float nota3;
    float nota4;
};

// Función para calcular el promedio de un estudiante
float calcularPromedio(const Estudiante* estudiante) {
    return (estudiante->nota1 + estudiante->nota2 + estudiante->nota3 + estudiante->nota4) / 4.0;
}

// Función para determinar si un estudiante aprobó o no
bool aprobo(const Estudiante* estudiante) {
    return calcularPromedio(estudiante) > 60.0;
}

int main() {
    int n;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    // Crear un array dinámico de estudiantes
    Estudiante* estudiantes = new Estudiante[n];

    // Pedir datos de cada estudiante y almacenarlos en el array
    for (int i = 0; i < n; ++i) {
        cout << "\nIngrese datos del estudiante " << i + 1 << "..." << endl;
        cout << "ID: ";
        cin >> estudiantes[i].id;
        cout << "\nNombre: ";
        cin >> estudiantes[i].nombre;
        cout << "Apellido: ";
        cin >> estudiantes[i].apellido;
        cout << "\nNota 1: ";
        cin >> estudiantes[i].nota1;
        cout << "\nNota 2: ";
        cin >> estudiantes[i].nota2;
        cout << "\nNota 3: ";
        cin >> estudiantes[i].nota3;
        cout << "\nNota 4: ";
        cin >> estudiantes[i].nota4;
    }

    // Mostrar resultados
    cout << "\nResultados:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Estudiante " << i + 1 << ": " << estudiantes[i].nombre << " " << estudiantes[i].apellido;
        cout << " (ID: " << estudiantes[i].id << ")" << endl;
        cout << "Promedio: " << calcularPromedio(&estudiantes[i]) << endl;
        if (aprobo(&estudiantes[i])) {
            cout << "Estado: Aprobado" << endl;
        } else {
            cout << "Estado: Reprobado" << endl;
        }
        cout << endl;
    }

    // Liberar la memoria asignada al array dinámico
    delete[] estudiantes;

    return 0;
}

