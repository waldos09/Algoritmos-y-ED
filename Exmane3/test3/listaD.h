#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "stdbool.h"

/*
    |Variable   | Estado    | Significado 
        error       0           Sin errores (todo resultado es exitoso)
        error      -1           Error, Lista llena
        error      -2           LIsta vacia
        error      -3           Inexistencia de dato en la estructura 
        error      -4           Nodo inicial nulo
        error      -5           Ruta del archivo no encontrada
*/

typedef struct{
    int frecuencia;
    char caracter;
}Dato;

typedef struct nodo{
    Dato info;
    struct nodo *izq,*der;
}Elemento_De_Arbol_Binario;

typedef Elemento_De_Arbol_Binario* Arbol;


struct Nodo{
	struct Nodo*sig;
    Arbol raiz;
	int pos;
};

typedef struct{
	struct Nodo*cab;
	int cursor;
}Elemento_Lista;



typedef Elemento_Lista*Lista; 



Lista crearLista();
bool isEmpty(Lista lista);
void agregarDer(Lista*lista , Dato datoInfo);
void agregarIzq(Lista*lista , Dato datoInfo);
void agregarPosN(Lista*lista , Dato datoInfo, int pos);
void extraerIzq(Lista*lista,Dato* datoE);
void recorrerLista(Lista lista );
void borrarLista(Lista* lista );

Arbol crearNodo(Dato valor); //Genera al nodo raiz de un árbol
void nuevoArbol(Arbol* raiz,Arbol Hizq, Arbol Hder, Dato valor);
int profundidadArbol(Arbol raiz);
void contarHojas(Arbol raiz, int* contadorHojas);
void preOrden(Arbol raiz);
void posOrden(Arbol raiz); 
void inOrden(Arbol raiz);
void eliminarArbol(Arbol* raiz);
void buscarNodo(Arbol raiz, Dato valor, Arbol* nodoEncontrado);
void eliminarNodo(Arbol* raiz, Dato valor);
void ingresarNodo(Arbol* raiz, Dato valor);
void reemplazar(Arbol* nodo);
Arbol nodoMinimo(Arbol node);
Arbol deleteNodeBST(Arbol raiz, Dato valor);
void iniciaOperacion(int argc, char** argv);
void asignaCodigo(Arbol r, int c[], int n, FILE*);
void ordenar(Lista* );




