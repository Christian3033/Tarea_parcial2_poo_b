#include <iostream>
#include <string>

using namespace std;

const int max_est = 100; // Máximo número de estudiantes

struct Estudiante {
    int id;
    string nombre;
    string apellido;
    float notas[4];
    float promedio;
    bool aprobado;
};

int main() {
    int num_estudiantes;

    cout << "Ingrese el numero de estudiantes: ";
    cin >> num_estudiantes;

    // Validando que el numero de estudiantes sea correcto
    if (num_estudiantes <= 0 || num_estudiantes > max_est) {
        cout << "Numero de estudiantes no válido." << endl;
        return 1;
    }

    Estudiante estudiantes[max_est];

    // solicitamos los datos del estudiante 
    for (int i = 0; i < num_estudiantes; ++i) {
        cout << "Ingrese el ID del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].id;
        cout << "Ingrese el nombre del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].nombre;
        cout << "Ingrese el apellido del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].apellido;
        cout << "Ingrese las notas del estudiante " << i + 1 << " (nota1 nota2 nota3 nota4): ";
        for (int j = 0; j < 4; ++j) {
            cin >> estudiantes[i].notas[j];
        }
        // Calcular el promedio del estudiante
        estudiantes[i].promedio = 0;
        for (int j = 0; j < 4; ++j) {
            estudiantes[i].promedio += estudiantes[i].notas[j];
        }
        estudiantes[i].promedio /= 4.0;

        // Determinar si el estudiante aprobó o reprobó
        estudiantes[i].aprobado = estudiantes[i].promedio >= 60;
    }

    // Mostrar resultados
    cout << "\nResultados:" << endl;
    for (int i = 0; i < num_estudiantes; ++i) {
        cout << "Estudiante ID: " << estudiantes[i].id << ", Nombre: " << estudiantes[i].nombre << " " << estudiantes[i].apellido << endl;
        
        cout<<"\n------------------------------------------------------------------------------\n";
        cout << "  Promedio: " << estudiantes[i].promedio << ", ";
        
        cout<<"\n------------------------------------------------------------------------------\n";
        if (estudiantes[i].aprobado) {
            cout << "\nAprobado...\n" << endl;
            
            cout<<"----------------------------------------------------------------------------\n";
        } else {
            cout << "\nReprobado...\n" << endl;
            
            cout<<"---------------------------------------------------------------------------\n";
        }
        
    }

    return 0;
}

