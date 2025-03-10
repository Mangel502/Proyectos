#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void Registrar();
void VerVentas();
void menu();

string dia, diaMayor, diaMenor;
int cantidad, precioU;
float MayorVenta, MenorVenta, total, Gtotal;

int main() {
	system("cls");
	menu();
	return 0;
}

void menu() {
	int opcion = 0;
	do {
		system("cls");
		cout << "\tRegistro de Ventas" << endl;
		cout << "1. Registrar Venta" << endl;
		cout << "2. Ver Registro" << endl;
		cout << "3. Salir" << endl;
		cout << "Que desea hcer?" << endl;
		cin >> opcion;

		if (cin.fail() || opcion < 1 || opcion > 3) {
			cin.clear();
			cin.ignore(10000, '\n');

		}
		else {
			switch (opcion) {
			case 1:
				system("cls");
				Registrar();
				system("PAUSE");
				break;

			case 2:
				system("cls");
				VerVentas();
				system("PAUSE");
				break;

			case 3:
				exit(0);
			}
		}
	} while (opcion != 3);
}

void Registrar() {
	ofstream escritura;
	ifstream consulta;
	bool repetido = false;

	escritura.open("ventas.txt", ios::out | ios::app);
	consulta.open("ventas.txt", ios::in);

	if (escritura.is_open() && consulta.is_open()) {
		cout << "\tIngrese los datos" << endl;

		cout << "Ingrse el dia de la semana: ";
		cin >> dia;
		cout << "Ingrese la cantidad de ventas: ";
		cin >> cantidad;
		cout << "Ingrese el monto de cada unidad: Q.";
		cin >> precioU;

		total = cantidad * precioU;
		Gtotal += total;

		escritura << dia << "\t" << cantidad << "\t\t" << precioU << "\t\t" << total << endl;
		cout << "Agregado Correctamente" << endl;
	}
	else {
		cout << "Error: El archivo no se pudo abrir o no se ha sido creado." << endl;
	}
	escritura.close();
	consulta.close();
}

void VerVentas() {
	ifstream lectura("ventas.txt", ios::in);

	if (lectura.is_open()) {
		cout << "\t\t\t*Datos de Ventas*" << endl;
		cout << "Dia\tCantidad\t\tPrecio U\tTotal" << endl;
		cout << "================================================================" << endl;

		// Variables para almacenar la venta ma?s alta y la ma?s baja
		float MayorVenta = 0;
		float MenorVenta = 9999999;

		while (lectura >> dia >> cantidad >> precioU >> total) {
			cout << dia << "\t\t" << cantidad << "\t\tQ." << precioU << "\t\tQ." << total << endl;

			// Verificamos si esta venta es la mayor
			if (total > MayorVenta) {
				MayorVenta = total;
				diaMayor = dia;
			}

			// Verificamos si esta venta es la menor
			if (total < MenorVenta) {
				MenorVenta = total;
				diaMenor = dia;
			}
		}

		cout << "=================================================================" << endl;

		// Mostramos la venta ma?s alta y la ma?s baja
		if (MayorVenta > 0) { // Verificamos si hubo al menos una venta
			cout << "La venta mas alta fue de Q." << MayorVenta << " el dia " << diaMayor << endl;
			cout << "La venta mas baja fue de Q." << MenorVenta << " el dia " << diaMenor << endl;
		}
		else {
			cout << "No hay ventas registradas au?n." << endl;
		}

	}
	else {
		cout << "Error: El Archivo no se pudo abrir o no ha sido creado" << endl;
	}
	lectura.close();
}