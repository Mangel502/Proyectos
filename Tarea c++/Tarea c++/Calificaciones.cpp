#include <iostream> //para declarar la entrada y salida
#include <vector>  //sirve para trabajar con arreglos dinamicos

using namespace std;


void calificaciones() {
	int n, suma = 0; // declaramos variables de tipo entero para guardar la seleccion del usuario
	float promedio; // declaramos una variable de tipo float para poder calcular el promedio

	cout << "Ingrese la cantidad de alumnos para evaluar: " << endl; // mostramos el mensaje de inicio para que el usuario pueda ingresar la cantidad de alumnas a evaluar
	cin >> n; // guardamos la cantidad del usuario en la variable n
	cout << endl; // mostramos un salto de linea
	vector<int> cal(n); // declaramos un vector o arreglo para almacenar las notas de los alumnos
	vector<string> resultado(n); // declaramos el segundo vector para almacenar el resultado de las notas de los alumnos

	for (int i = 0; i < n; i++) { // iniciamos un bucle for para que el usuario pueda ingresar las notas finales de los alumnos
		cout << "Ingrese la calificacion del alumno " << i + 1 << ": "; // mostramos el mensaje para cada alumno 
		cin >> cal[i]; // almacenamos en el vector las notas de los alumnos

		if (cal[i] >= 60) { // iniciamos una condicional para poder evaluar las notas y asi comprobar si aprobo la clase
			resultado[i] = "Aprobado"; // si las notas son mayor a 60 entonces se guardara en el vector "aprobado" para cada alumno
		}
		else { // de lo contrario
			resultado[i] = "Reprobado"; // guardaremos la palabra reprobado si las notas del alumno es menor a 60
		}
	}
	// una vez terminemos de ingresar las notas

	cout << endl; // damos un salto de linea 
	cout << "Las calificaiones son: " << endl; // mostramos el mensaje para empezar a mostrar el resultado de las notas
	for (int i = 0; i < n; i++) { // empezamos un bucle en el cual empezara de 0 hasta la cantidad de alumnos que haya ingresado el usuario
		cout << "Alumno " << i + 1 << ": " << cal[i] << " " << resultado[i] << endl; // mostramos "Alumno 1" y dependiendo de la variable i buscamos en el vector cal las calificaiones y en el vector resultado si aprobo o reprobo la clase
	} // esto lo hacemos con cada alumno
	cout << endl;  // al terminar damos un salto de linea

	for (int i = 0; i < n; i++) { // iniciamos un bucle para poder sumar todas las notas de los alumnos 
		suma += cal[i]; // y almacenamos el resultado en la variable suma 
	}

	promedio = static_cast<float>(suma) / n; // en la variable promedio guardaremos el promedio de las notas que consiste en convertir la suma total de las notas en float y asi divirlas por el numero de estudiantes
	cout << "El promedio es igual a :" << promedio; // para ultimo mostrar el promedio de todas las notas.
	system("pause");
}

int main() { //funcion principal del programa
	int opcion; //para declarar la variable 
	do { //un bucle do/while  para mostrar la repeticion
		cout << "\n_________Menu Principal_________\n"; //el titulo del menu
		cout << "1.___Ingresa las Calificaciones___\n"; //Imprime la opcion1
		cout << "2._______Salir del programa_______\n"; //Imprime la opcion 2
		cout << "Seleccione su opcion:"; //para seleccionar una opcion
		cin >> opcion; //lee la opcion del usuario

		switch (opcion) { // para manejar la estructura del menu
		case 1: calificaciones(); 
				break; //si elije la 1 va a la funcion de calificaciones
		case 2: cout << "Cerrando Programa\n";
			break; // si elije 2 imprime una salida para salir del bucle
		default: cout << "No funciono\n"; //si ninguno es correcto parca error


		}
	} while (opcion != 2); //el bucle se repite
	return 0; //el programa termine bien
}