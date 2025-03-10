#include <iostream>

using namespace std;
int main() {
    int cantidad; // Cantidad de n�meros a verificar
    bool primo; // Variable para determinar si un n�mero es primo

    // Solicita al usuario la cantidad de n�meros a verificar
    cout << "Ingrese cuantos numeros desea verificar: ";
    cin >> cantidad;

    // Se crea un arreglo din�mico para almacenar los n�meros ingresados
    int* numeros = new int[cantidad];

    // Se solicita al usuario que ingrese los n�meros
    for (int i = 0; i < cantidad; i++) {
        cout << "Ingrese el numero " << i + 1 << ": ";
        cin >> numeros[i];
    }
    // Se verifica si cada n�mero ingresado es primo
    for (int i = 0; i < cantidad; i++) {
        int numero = numeros[i]; // Se obtiene el n�mero actual
        primo = true; // Se asume que el n�mero es primo

        // Un n�mero menor o igual a 1 no es primo
        if (numero <= 1) {
            primo = false;
        }
        // Verifica si el n�mero tiene divisores adem�s de 1 y s� mismo
        for (int j = 2; j < numero; j++) {
            if (numero % j == 0) { // Si es divisible por otro n�mero, no es primo
                primo = false;
                break; // Se detiene el bucle ya que ya se comprob� que no es primo
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
    // Se libera la memoria asignada din�micamente
    delete[] numeros;

    return 0;
}