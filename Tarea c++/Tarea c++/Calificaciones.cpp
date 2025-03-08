#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, suma = 0;
	float promedio;

	cout << "Ingrese la cantidad de alumnos para evaluar: " << endl;
	cin >> n;
	cout << endl;
	vector<int> cal(n);

	for (int i = 0; i < n; i++) {
		cout << "Ingrese la calificacion del alumno " << i + 1 << ": ";
		cin >> cal[i];
	}
	cout << endl;
	cout << "Las calificaiones son: " << endl;
	for (int i = 0; i < n;i++) {
		cout << "Alumno " << i + 1 << ": " << cal[i] << endl;
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
