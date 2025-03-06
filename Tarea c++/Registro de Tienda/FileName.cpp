#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int numero;
	bool primo = true;

	cout << "Ingrese un numero Positivo: ";
	cin >> numero;

	for (int i = 2; i < numero; i++) {
		if (numero % 2 == 0) {
			primo = false;
		}
	}
	if (primo == true) {
		cout << "El numero es Primo";
	}
	else {
		cout << "El numero no es Primo";
	}

	return 0;
}