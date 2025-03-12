#include <iostream> //para la entrada y salida
#include <fstream>  //para trabajar con archivos
#include <string> //para trabajar con cadenas

using namespace std; //usa un nombre estandar

//Se declaran las funciones que tendra el programa
void Registrar(); //declarar las funciones registrar
void VerVentas(); //declarar las funcionas verventas
void menu();

//Se declaran las vaiables para el programa
string dia, diaMayor, diaMenor; //declara variebles de cadena
int cantidad, precioU; //declara variebles enteras
float MayorVenta, MenorVenta, total, Gtotal; //declara variebles de puntos flotantes

//Se hace el llamado al menu
int main() { //funcion principal de programa
	system("cls"); //limpia la pantalla consola
	menu(); //llama a la funcion de menu
	return 0; //indica que termino correcto
}

//Funciones para el munu
void menu() { //Definicion de la funcion menu
	int opcion = 0; //declara una variebles  para almacenar la opcion de menu
	do {
		system("cls"); //limpia la pantalla dr consola
		cout << "\tRegistro de Ventas" << endl; 
		//Se crean las opciones para el menu
		cout << "1. Registrar Venta" << endl;//imprime la opcion 1
		cout << "2. Ver Registro" << endl; //imrpime la opcion 2
		cout << "3. Salir" << endl; //imprimo la opcion 3
		cout << "Que desea hcer?" << endl; //pide al usuario selecionar una opcion
		cin >> opcion;
		//Se crea una verificacion para que el usuario solo coloque las opciones validas
		if (cin.fail() || opcion < 1 || opcion > 3) {
			cin.clear();
			cin.ignore(10000, '\n');// Ignora la entrada no válida

		}
		else {
			switch (opcion) {
			case 1:
				system("cls");//limpia la pantalla
				Registrar();
				system("PAUSE");//espera la respuesta del usuario
				break;

			case 2:
				system("cls");
				VerVentas();
				system("PAUSE");
				break;

			case 3:
				exit(0);//Salir del programa
			}
		}
	} while (opcion != 3);
}

//Funcion para la opcion "Registrar"
void Registrar() {
	ofstream escritura;//Se crea una variable en modo de escritura
	ifstream consulta;//Se crea una variable en modo de lectura
	bool repetido = false;

	//Se crea un archivo de texto en modo de lectura y escritura
	escritura.open("ventas.txt", ios::out | ios::app);
	consulta.open("ventas.txt", ios::in);

	//Verifica si el archivo se abrio correctamente
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
	else {//Si el archivo no se abre saldra un error
		cout << "Error: El archivo no se pudo abrir o no se ha sido creado." << endl;
	}
	//Se cierra el archivo de texto
	escritura.close();
	consulta.close();
}

//Funcion para la opcion "Ver Ventas"
void VerVentas() {
	ifstream lectura("ventas.txt", ios::in);//Se crea una variable en modo de lectura

	if (lectura.is_open()) {//Si se abre se muetsra un menu y los datos
		cout << "\t\t\t*Datos de Ventas*" << endl;
		cout << "Dia\tCantidad\t\tPrecio U\tTotal" << endl;
		cout << "================================================================" << endl;

		// Variables para almacenar la venta mas alta y la mas baja
		float MayorVenta = 0; // Se inicializa con 0 para que cualquier venta real lo supere y se actualice correctamente
		float MenorVenta = 9999999; // Se inicializa con un número muy alto para que cualquier venta real sea menor y lo reemplace

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

		// Mostramos la venta mas alta y la mas baja
		if (MayorVenta > 0) { // Verificamos si hubo al menos una venta
			cout << "La venta mas alta fue de Q." << MayorVenta << " el dia " << diaMayor << endl;
			cout << "La venta mas baja fue de Q." << MenorVenta << " el dia " << diaMenor << endl;
		}
		else {//Si no hay ventas saldra un error
			cout << "No hay ventas registradas aun." << endl;
		}

	}
	else {//Si el archivo no se abre saldra un error
		cout << "Error: El Archivo no se pudo abrir o no ha sido creado" << endl;
	}
	lectura.close();//Se cierra el archivo de texto
}