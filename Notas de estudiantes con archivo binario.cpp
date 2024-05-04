#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// Definición de la estructura Estudiante
struct Estudiante {
    int id;
    char nombre[50];
    char apellido[50];
    float notas[4];
    float promedio;
    char resultado[15];
};

// Función para calcular el promedio de un estudiante
float calcularPromedio(const float* notas) {
    float suma = 0.0;
    for (int i = 0; i < 4; ++i) {
        suma += notas[i];
    }
    return suma / 4.0;
}

// Función para determinar si un estudiante aprobó o no
const char* determinarResultado(float promedio) {
    return promedio > 60.0 ? "Aprobado" : "Reprobado";
}

// Función para crear un nuevo registro de estudiante
void crearEstudiante() {
    Estudiante estudiante;
    cout << "Ingrese ID: ";
    cin >> estudiante.id;
    cout << "Ingrese nombres: ";
    cin.ignore();
    cin.getline(estudiante.nombre, 50);
    cout << "Ingrese apellidos: ";
    cin.getline(estudiante.apellido, 50);
    cout << "Ingrese las notas (separadas por espacios): ";
    for (int i = 0; i < 4; ++i) {
        cin >> estudiante.notas[i];
    }
    estudiante.promedio = calcularPromedio(estudiante.notas);
    strcpy(estudiante.resultado, determinarResultado(estudiante.promedio));

    ofstream archivo("notas.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante));
    archivo.close();
}

// Función para mostrar todos los registros de estudiantes
void mostrarEstudiantes() {
    ifstream archivo("notas.dat", ios::binary);
    if (!archivo) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    Estudiante estudiante;
    while (archivo.read(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante))) {
        cout << "ID: " << estudiante.id << endl;
        cout << "Nombres: " << estudiante.nombre << endl;
        cout << "Apellidos: " << estudiante.apellido << endl;
        cout << "Notas: ";
        for (int i = 0; i < 4; ++i) {
            cout << estudiante.notas[i] << " ";
        }
        cout << endl;
        cout << "Promedio: " << estudiante.promedio << endl;
        cout << "Resultado: " << estudiante.resultado << endl;
        cout << endl;
    }

    archivo.close();
}

int main() {
    char opcion;
    do {
        cout << "Menu:" << endl;
        cout << "1. Crear estudiante" << endl;
        cout << "2. Mostrar estudiantes" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case '1':
                crearEstudiante();
                break;
            case '2':
                mostrarEstudiantes();
                break;
            case '3':
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion no válida. Por favor, ingrese una opcion valida." << endl;
        }
    } while (opcion != '3');

    return 0;
}

