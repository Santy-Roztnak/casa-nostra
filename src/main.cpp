#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "arbol.h"
#include "integrantes.h"

using namespace std;

int main() {
    arbolFamilia<miembros> familia;
    ifstream archivo("bin/datos.csv");
    if (!archivo.is_open()) {
    	archivo.clear();
    	archivo.is_open("datos.csv");
	}
	
	if (archivo.is_open()) {
		string linea;
		getline(archivo, linea);
		
		int cargados = 0;
		while (getline(archivo, linea)) {
			if (linea.empty()) continue;
			
			stringstream ss(linea);
			string campo, nombre, apellido, generoStr;
			int id, edad, id_boss, dead, jail, was_b, is_b;
			
			getline(ss, campo, ','); id = stoi(campo);
			getline(ss, nombre, ',');
			getline(ss, apellido, ',');
			getline(ss, generoStr, ',');
			getline(ss, campo, ','); edad = stoi(campo);
			getline(ss, campo, ','); id_boss = stoi(campo);
			getline(ss, campo, ','); dead = stoi(campo);
			getline(ss, campo, ','); jail = stoi(campo);
			getline(ss, campo, ','); was_b = stoi(campo);
			getline(ss, campo, ','); is_b = stoi(campo);
			
			char gen = generoStr.empty() ? 'H' : generoStr[0];
			miembros m(id, nombre, apellido, gen, edad, id_boss,
						dead == 1, jail == 1, was_b == 1, is_b == 1);
			damilia.InsertarMiembros(m);
			cargados++;
		}
		archivo.close();
		cout << "CSV cargado desde main (" << cargados << " registros)." << endl;		
	} else {
		cout << "No se encontro CSV. Cargando respaldo inicial..." << endl;
		familia.InsertarMiembros(miembros(1, "Vito", "Corleone", 'H', 68, -1, false, false, true, true));
		familia.InsertarMiembros(miembros(1, "Santino", "Corleone", 'H', 40, 1, false, false, false, false));
		familia.InsertarMiembros(miembros(1, "Michael", "Corleone", 'H', 38, 1, false, false, false, false));
		familia.InsertarMiembros(miembros(1, "Fredo", "Corleone", 'H', 42, 2, false, false, false, false));
		familia.InsertarMiembros(miembros(1, "Vincent", "Mancini", 'H', 25, 3, false, false, false, false));
	}
	
    familia.mostrarLineaSucesion();

    int opcion = 0;
    while (true) {
        cout << "\n================ MENU FAMILIA ================" << endl;
        cout << "1. Mostrar linea de sucesion (vivos, padre e hijos)" << endl;
        cout << "2. Modificar datos de un miembro" << endl;
        cout << "3. Verificar y asignar sucesion del jefe" << endl;
        cout << "4. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            familia.mostrarLineaSucesion();
        } else if (opcion == 2) {
            int id;
            cout << "Ingresa el ID del miembro a editar: ";
            cin >> id;
            familia.modificaDato(id);
            familia.actualizarSucesionJefe();
        } else if (opcion == 3) {
            familia.actualizarSucesionJefe();
        } else if (opcion == 4) {
            cout << "Cerrando sistema..." << endl;
            break;
        } else {
            cout << "Opcion no valida." << endl;
        }
    }

    return 0;
}
