#include "exa2.h"

int main(int argc, char** argv){
    int error, numgen, lim;
    Dato persona;
    Cola cola=crearCola(&error);
    
    printf("Ingrese el no de personas");
    scanf("%s", &lim);    
    //iniciar lista

    /// SE LLENA LA COLA
    for(int i=0;i<atoi(argv[1]);i++){
        printf("\n\n\t: : PERSONA %d : :",i);

        fflush(stdin);

        printf("\nIngresa el nombre de la persona: ");
        scanf("%s",persona.nombre);

        printf("\n\nIngresa la edad de la persona: ");
        scanf("%d",&persona.edad);

        persona.altura=numAle();
        printf("\n Altura de la persona: %d",persona.altura);
        scanf("%d",&persona.altura);

        printf("\n: : : : : : : : : : : : : : : : : : : :");

        encolar(&cola,&error,persona);
    }

    ///DECLARACION DE JUEGOS Y LLENADO DE LAS LISTAS DE LOS JUEGOS
    Lista *juego1, *juego2, *juego3, *juego4, *juego5;

    if ((juego1 = (Lista *) malloc (sizeof (Lista))) == NULL){
        puts("\nNo se pudo crear juego 1");
    }

    if ((juego2 = (Lista *) malloc (sizeof (Lista))) == NULL){
        puts("\nNo se pudo crear juego 2");
    }

    if ((juego3 = (Lista *) malloc (sizeof (Lista))) == NULL){
        puts("\nNo se pudo crear juego 3");
    }

    if ((juego4 = (Lista *) malloc (sizeof (Lista))) == NULL){
        puts("\nNo se pudo crear juego 4");
    }

    if ((juego5 = (Lista *) malloc (sizeof (Lista))) == NULL){
        puts("\nNo se pudo crear juego 5");
    }

    inicializar(juego1);
    inicializar(juego2);
    inicializar(juego3);
    inicializar(juego4);
    inicializar(juego5);

    //Aqui se distribuyen en las listas
    borraCola(&cola,&error,juego1,juego2,juego3,juego4,juego5);
    Atender(juego1,juego2,juego3,juego4,juego5);
    return 0;
}