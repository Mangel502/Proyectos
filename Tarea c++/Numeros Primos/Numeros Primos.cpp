#include <iostream>

using namespace std;
int main() {
    int cantidad; // Cantidad de números a verificar
    bool primo; // Variable para determinar si un número es primo

    // Solicita al usuario la cantidad de números a verificar
    cout << "Ingrese cuantos numeros desea verificar: ";
    cin >> cantidad;

    // Se crea un arreglo dinámico para almacenar los números ingresados
    int* numeros = new int[cantidad];

    // Se solicita al usuario que ingrese los números
    for (int i = 0; i < cantidad; i++) {
        cout << "Ingrese el numero " << i + 1 << ": ";
        cin >> numeros[i];
    }
    // Se verifica si cada número ingresado es primo
    for (int i = 0; i < cantidad; i++) {
        int numero = numeros[i]; // Se obtiene el número actual
        primo = true; // Se asume que el número es primo

        // Un número menor o igual a 1 no es primo
        if (numero <= 1) {
            primo = false;
        }
        // Verifica si el número tiene divisores además de 1 y sí mismo
        for (int j = 2; j < numero; j++) {
            if (numero % j == 0) { // Si es divisible por otro número, no es primo
                primo = false;
                break; // Se detiene el bucle ya que ya se comprobó que no es primo
            }
        }
        // Se muestra el resultado en pantalla
        if (primo) {
            cout << "El numero " << numero << " es Primo" << endl;
        }
        else {
            cout << "El numero " << numero << " no es Primo" << endl;
        }
    }
    // Se libera la memoria asignada dinámicamente
    delete[] numeros;

    return 0;
}