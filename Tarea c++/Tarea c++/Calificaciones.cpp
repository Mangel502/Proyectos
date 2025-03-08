#include <iostream>
#include <vector>

using namespace std;

void Menu() {

}

int main() {
	int n, suma = 0;
	float promedio;

	cout << "Ingrese la cantidad de alumnos para evaluar: " << endl;
	cin >> n;
	cout << endl;
	vector<int> cal(n);
	vector<string> resultado(n);

	for (int i = 0; i < n; i++) {
		cout << "Ingrese la calificacion del alumno " << i + 1 << ": ";
		cin >> cal[i];
		
		if (cal[i] >= 60) {
			resultado[i] = "Aprobado";
		}
		else {
			resultado[i] = "Reprobado";
		}
	}

	cout << endl;
	cout << "Las calificaiones son: " << endl;
	for (int i = 0; i < n;i++) {
		cout << "Alumno " << i + 1 << ": " << cal[i] << " " << resultado[i] << endl;
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		suma += cal[i];
	}

	promedio = static_cast<float>(suma) / n;
	cout << "El promedio es igual a :" << promedio;

	for (int i = 0; i < n; i++) {
		;
	}


	return 0;
}
