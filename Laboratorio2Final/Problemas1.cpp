#include <iostream>
#include "Problemas1.h"

using namespace std;

// PROBLEMA 1//
void desglosarDinero(int cantidad) {
    int denominaciones[] = {
        0b11000011001010000,
        0b1001110001000000,
        0b10011100010000,
        0b1001110001000,
        0b1111101000,
        0b111110100,
        0b1111100,
        0b11001000,
        0b1100100,
        0b110010
    };

    int *p = denominaciones;

    for (int i = 0; i < 10; i++) {
        int valor = *(p + i);
        cout << valor << " : " << (cantidad / valor) << endl;
        cantidad %= valor;
    }
    cout << "Faltante: " << cantidad << endl;
}

// PROBLEMA 3//
bool compararCadenas(char *Cadena1, char *Cadena2) {
    while (*Cadena1 != '\0' && *Cadena2 != '\0') {
        if (*Cadena1 != *Cadena2) return false;
        Cadena1++;
        Cadena2++;
    }
    return (*Cadena1 == *Cadena2);
}

// PROBLEMA 5//
void enteroACadena(int n, char *str) {
    int temp = n, len = 0;
    while (temp > 0) { temp /= 10; len++; }

    *(str + len) = '\0';
    for (int i = len - 1; i >= 0; i--) {
        *(str + i) = (n % 10) + 0x30;
        n /= 10;
    }
}

// PROBLEMA 7//
void eliminarRepetidos(char *str) {
    char *p1 = str;
    while (*p1 != '\0') {
        char *p2 = p1 + 1;
        while (*p2 != '\0') {
            if (*p2 == *p1) {
                char *p3 = p2;
                while (*p3 != '\0') {
                    *p3 = *(p3 + 1);
                    p3++;
                }
            } else p2++;
        }
        p1++;
    }
}

// PROBLEMA 9//
int sumarFragmentos(char *cadena, int n) {
    int lon = 0;
    char *t = cadena;
    while (*t++) lon++;

    int suma = 0;
    for (int i = lon; i > 0; i -= n) {
        int num = 0, mult = 1;
        for (int j = 0; j < n && (i - 1 - j) >= 0; j++) {
            num += (*(cadena + (i - 1 - j)) - 0x30) * mult;
            mult *= 10;
        }
        suma += num;
    }
    return suma;
}