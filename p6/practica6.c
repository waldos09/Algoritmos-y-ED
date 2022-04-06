#include "pilaD.h"


int main(int argc, char** argv){
    int error;
    //int cantidadDatos;
    Pila *p=crearPila(&error);
    struct Nodo dato;
    get_data();
    printf("Esta es la exprecion postfija del archivo : %s\n",data);
    printf("Cant de valores para la pila:%d \n",cant_datos);
    //puts("Cuantos valores quieres agregar a la pila?");
    //fflush(stdin);
    //scanf("%d",&cantidadDatos);
    for(int i=0; i<cant_datos; i++){
        //puts("Ingresa un valor:");
        //fflush(stdin);
        //scanf("%d",&dato.valor);
        dato.valor = data[i];
        apilar(p,&error,dato);
    }
    consultarCima(*p,&error);
    vaciarPila(p,&error);
    return error;
}



void evaluacion(){

}

/*
gcc Archivo1.c Arcihvo2.c Archivo3.c Main.c -o Nombre

SÓLO incluyendo los archivos .c, no las cabeceras (.h)

Donde Nombre es el nombre que quieres que tenga el ejecutable.

Para ejecutarlo simplemente haces un ./Nombre y voila.*/