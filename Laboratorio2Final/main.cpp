#include <iostream>
#include "Problemas1.h"
#include "Problemas2.h"

using namespace std;

int main() {
    int opcion, n;
    char cadena1[100], cadena2[100];

    do {
        cout << "\nMENU LABORATORIO 2" << endl;
        cout << "1. Problema 1 (Billetes)" << endl;
        cout << "2. Problema 3 (Comparar Cadenas)" << endl;
        cout << "3. Problema 5 (Int a Cadena)" << endl;
        cout << "4. Problema 7 (Eliminar Repetidos)" << endl;
        cout << "5. Problema 9 (Suma de n cifras)" << endl;
        cout << "6. Problema 11 (Sala de cine)" << endl;
        cout << "7. Problema 13 (Estrellas galaxia)" << endl;
        cout << "8. Problema 15 (Interseccion rectangulos)" << endl;
        cout << "9. Problema 17 (Numeros amigables)" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese cantidad: ";
            cin >> n;
            desglosarDinero(n);
            break;

        case 2:
            cout << "Cadena 1: ";
            cin >> cadena1;
            cout << "Cadena 2: ";
            cin >> cadena2;
            cout << (compararCadenas(cadena1, cadena2) ? "Verdadero" : "Falso") << endl;
            break;

        case 3:
            cout << "Ingrese entero: ";
            cin >> n;
            enteroACadena(n, cadena1);
            cout << "Resultado: " << cadena1 << endl;
            break;

        case 4:
            cout << "Ingrese cadena: ";
            cin >> cadena1;
            eliminarRepetidos(cadena1);
            cout << "Resultado: " << cadena1 << endl;
            break;

        case 5:
            cout << "Ingrese n: ";
            cin >> n;
            cout << "Ingrese numeros: ";
            cin >> cadena1;
            cout << "Suma: " << sumarFragmentos(cadena1, n) << endl;
            break;

        case 6:
            sistemaCine();
            break;

        case 7:
            pruebaGalaxia();
            break;

        case 8:
            pruebaRectangulos();
            break;

        case 9:
            cout << "Ingrese limite: ";
            cin >> n;
            cout << "Suma amigables: " << sumaAmigables(n) << endl;
            break;
        }

    } while (opcion != 0);

    return 0;
}