#include <iostream>
using namespace std;

int factorial(int n) {
    if (n <= 1)  
        return 1;
    else 
        return n * factorial(n - 1);
}

void consultarSaldo(int saldo) {
    cout << "Tu saldo actual es: $" << saldo << endl;
}

int retirarEfectivo(int saldo) {
    int cantidad;
    cout << "Ingresa la cantidad que deseas retirar: $";
    cin >> cantidad;
    
    if (cantidad > saldo) {
        cout << "Fondos insuficientes." << endl;
    } else {
        saldo -= cantidad;
        cout << "Has retirado: $" << cantidad << endl;
        cout << "Saldo restante: $" << saldo << endl;
    }
    return saldo;
}

int main() {
    int opcion;
    int saldo = 20000;  

    do {
        cout << "\n===== Menu Principal =====" << endl;
        cout << "1. Calcular Factorial" << endl;
        cout << "2. Usar Cajero Automatico" << endl;
        cout << "3. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int numero;
                cout << "Ingresa un numero para calcular su factorial: ";
                cin >> numero;

                if (numero < 0) {
                    cout << "El factorial no está definido para numeros negativos." << endl;
                } else {
                    cout << "El factorial de " << numero << " es: " << factorial(numero) << endl;
                }
                break;
            }
            case 2: {
                int opcionCajero;
                do {
                    cout << "\n===== Cajero Automatico =====" << endl;
                    cout << "1. Consultar saldo" << endl;
                    cout << "2. Retirar efectivo" << endl;
                    cout << "3. Salir del Cajero" << endl;
                    cout << "Elige una opcion: ";
                    cin >> opcionCajero;

                    switch (opcionCajero) {
                        case 1:
                            consultarSaldo(saldo);
                            break;
                        case 2:
                            saldo = retirarEfectivo(saldo);
                            break;
                        case 3:
                            cout << "Saliendo del cajero automatico." << endl;
                            break;
                        default:
                            cout << "Opcion invalida. Intentalo de nuevo." << endl;
                    }
                } while (opcionCajero != 3);
                break;
            }
            case 3:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion invalida. Intentalo de nuevo." << endl;
        }
    } while (opcion != 3);

    return 0;
}
