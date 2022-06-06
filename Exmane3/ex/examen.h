
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
struct INFO
{
 char archivo[50];
 float archivo2;
};
 
struct NODO
{
 struct INFO elemento;
 struct NODO *p_anterior;
 struct NODO *p_siguiente;
};
 
struct COLA
{
 int nodos;
 struct NODO *primero;
 struct NODO *ultimo;
};

void inicializarCola( struct COLA **cola );
void insert( struct COLA **cola, char dato[] );
void insertAltura( struct COLA **cola, float dato);
int tieneNodosLaCola( struct COLA **cola );
void borraLaCola( struct COLA **cola );

void imprimeCola( struct COLA **cola );

void inicionOperacion(int argv, char **argc);
void insertedad(struct COLA **cola, char dato[]);




/*
gcc Archivo1.c Arcihvo2.c Archivo3.c Main.c -o Nombre

SÓLO incluyendo los archivos .c, no las cabeceras (.h)

Donde Nombre es el nombre que quieres que tenga el ejecutable.

Para ejecutarlo simplemente haces un ./Nombre y voila.*/
 