#include <iostream>
#include "Problemas2.h"

using namespace std;

//PROBLEMA 11//
void inicializarSala(char *sala, int filas, int cols) {
    for (int i = 0; i < filas * cols; i++)
        *(sala + i) = '-';
}

void mostrarSala(char *sala, int filas, int cols) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++)
            cout << *(sala + i * cols + j) << " ";
        cout << endl;
    }
}

void reservarAsiento(char *sala, int fila, int asiento, int cols) {
    *(sala + fila * cols + asiento) = '+';
}

void cancelarAsiento(char *sala, int fila, int asiento, int cols) {
    *(sala + fila * cols + asiento) = '-';
}

void sistemaCine() {
    char sala[15][20];
    inicializarSala(&sala[0][0], 15, 20);

    char fila;
    int asiento, op;

    do {
        mostrarSala(&sala[0][0], 15, 20);
        cout << "1 Reservar, 2 Cancelar, 0 Salir: ";
        cin >> op;

        if (op == 1) {
            cout << "Fila (A-O): ";
            cin >> fila;
            cout << "Asiento (0-19): ";
            cin >> asiento;
            reservarAsiento(&sala[0][0], fila - 'A', asiento, 20);
        }

        if (op == 2) {
            cout << "Fila (A-O): ";
            cin >> fila;
            cout << "Asiento (0-19): ";
            cin >> asiento;
            cancelarAsiento(&sala[0][0], fila - 'A', asiento, 20);
        }

    } while (op != 0);
}

//PROBLEMA 13//
int contarEstrellas(int *mat, int filas, int cols) {
    int estrellas = 0;

    for (int i = 1; i < filas - 1; i++) {
        for (int j = 1; j < cols - 1; j++) {
            int suma =
                *(mat + i * cols + j) +
                *(mat + i * cols + j - 1) +
                *(mat + i * cols + j + 1) +
                *(mat + (i - 1) * cols + j) +
                *(mat + (i + 1) * cols + j);

            if ((suma / 5) > 6)
                estrellas++;
        }
    }
    return estrellas;
}

void pruebaGalaxia() {
    int galaxia[6][8] = {
        {0,3,4,0,0,0,6,8},
        {5,13,6,0,0,0,2,3},
        {2,6,2,7,3,0,10,0},
        {0,0,4,15,4,1,6,0},
        {0,0,7,12,6,9,10,4},
        {5,0,6,10,6,4,8,0}
    };

    cout << "Estrellas: "
         << contarEstrellas(&galaxia[0][0], 6, 8)
         << endl;
}

//PROBLEMA 15//

int maximo(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int minimo(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}

void interseccionRect(int *A, int *B, int *C) {
    int x1 = maximo(*A, *B);
    int y1 = maximo(*(A + 1), *(B + 1));

    int x2 = minimo(*A + *(A + 2), *B + *(B + 2));
    int y2 = minimo(*(A + 1) + *(A + 3), *(B + 1) + *(B + 3));

    if (x2 > x1 && y2 > y1) {
        *C = x1;
        *(C + 1) = y1;
        *(C + 2) = x2 - x1;
        *(C + 3) = y2 - y1;
    } else {
        *C = *(C + 1) = *(C + 2) = *(C + 3) = 0;
    }
}

void pruebaRectangulos() {
    int A[4];
    int B[4];
    int C[4];

    cout << "Rectangulo A (x y ancho alto): ";
    for (int i = 0; i < 4; i++)
        cin >> *(A + i);

    cout << "Rectangulo B (x y ancho alto): ";
    for (int i = 0; i < 4; i++)
        cin >> *(B + i);

    interseccionRect(A, B, C);

    cout << "Interseccion C: ";
    for (int i = 0; i < 4; i++)
        cout << *(C + i) << " ";
    cout << endl;
}


//PROBLEMA 17//
int sumaDivisores(int n) {
    int suma = 0;
    for (int i = 1; i < n; i++)
        if (n % i == 0)
            suma += i;
    return suma;
}

int sumaAmigables(int limite) {
    int suma = 0;
    for (int i = 1; i < limite; i++) {
        int a = sumaDivisores(i);
        int b = sumaDivisores(a);
        if (b == i && a != i)
            suma += i;
    }
    return suma;
}