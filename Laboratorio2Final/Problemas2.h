#ifndef PROBLEMAS2_H
#define PROBLEMAS2_H

// Problema 11: Sala de cine//
void inicializarSala(char *sala, int filas, int cols);
void mostrarSala(char *sala, int filas, int cols);
void reservarAsiento(char *sala, int fila, int asiento, int cols);
void cancelarAsiento(char *sala, int fila, int asiento, int cols);
void sistemaCine();

// Problema 13: Estrellas galaxia//
int contarEstrellas(int *mat, int filas, int cols);
void pruebaGalaxia();

// Problema 15 Interseccion Triangulo//
void interseccionRect(int *A, int *B, int *C);
void pruebaRectangulos();

// Problema 17 Numeros Amigables//
int sumaDivisores(int n);
int sumaAmigables(int limite);

#endif
