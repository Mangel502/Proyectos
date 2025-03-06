#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    int cantidad;
    bool primo;

    cout << "Ingrese cuantos numeros desea verificar: ";
    cin >> cantidad;

    int* numeros = new int[cantidad];

    for (int i = 0; i < cantidad; i++) {
        cout << "Ingrese el numero " << i + 1 << ": ";
        cin >> numeros[i];
    }

    for (int i = 0; i < cantidad; i++) {
        int numero = numeros[i];
        primo = true;

        if (numero <= 1) {
            primo = false;
        }
        for (int j = 2; j < numero; j++) {
            if (numero % j == 0) {
                primo = false;
                break;
            }
        }
        if (primo) {
            cout << "El numero " << numero << " es Primo" << endl;
        }
        else {
            cout << "El numero " << numero << " no es Primo" << endl;
        }
    }
    delete[] numeros;

    return 0;
}