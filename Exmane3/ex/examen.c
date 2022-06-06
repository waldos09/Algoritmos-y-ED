
#include "examen.h"

void inicializarCola(struct COLA **cola)
{

    struct COLA *temp = (struct COLA *)malloc(sizeof(struct COLA));

    temp->nodos = 0;
    temp->primero = NULL;
    temp->ultimo = NULL;

    (*cola) = temp;
};

void insert(struct COLA **cola, char dato[50])
{
    struct NODO *temp = (struct NODO *)malloc(sizeof(struct NODO));
    if ((*cola)->primero == NULL)
    {
        for (int i = 0; i < 50; i++)
        {
            temp->elemento.archivo[i] = dato[i];
        }
        temp->p_anterior = NULL;
        temp->p_siguiente = NULL;
        (*cola)->primero = temp;
        (*cola)->ultimo = temp;
    }
    else
    {
        for (int i = 0; i < 50; i++)
        {
            temp->elemento.archivo[i] = dato[i];
        }
        temp->p_anterior = NULL;
        temp->p_siguiente = (*cola)->primero;
        (*cola)->primero->p_anterior = temp;
        (*cola)->primero = temp;
    };
    (*cola)->nodos += 1;
};
void insertedad(struct COLA **cola, char dato[50])
{
    struct NODO *temp = (struct NODO *)malloc(sizeof(struct NODO));
    if ((*cola)->primero == NULL)
    {
        for (int i = 0; i < 50; i++)
        {
            temp->elemento.archivo[i] = dato[i];
        }
        temp->p_anterior = NULL;
        temp->p_siguiente = NULL;
        (*cola)->primero = temp;
        (*cola)->ultimo = temp;
    }
    else
    {
        for (int i = 0; i < 50; i++)
        {
            temp->elemento.archivo[i] = dato[i];
        }
        temp->p_anterior = NULL;
        temp->p_siguiente = (*cola)->primero;
        (*cola)->primero->p_anterior = temp;
        (*cola)->primero = temp;
    };
    (*cola)->nodos += 1;
};


void insertAltura(struct COLA **cola, float dato)
{

    struct NODO *temp = (struct NODO *)malloc(sizeof(struct NODO));
    if ((*cola)->primero == NULL)
    {
      temp->elemento.archivo2 = dato;
        
        temp->p_anterior = NULL;
        temp->p_siguiente = NULL;

        (*cola)->primero = temp;
        (*cola)->ultimo = temp;
    }
    else
    {

        temp->elemento.archivo2 = dato;
        
        temp->p_anterior = (*cola)->ultimo;
        temp->p_siguiente = NULL;

        (*cola)->ultimo->p_siguiente = temp;
        (*cola)->ultimo = temp;
    };

    (*cola)->nodos += 1;
};



int tieneNodosLaCola(struct COLA **cola)
{
    int resp = 0;

    if ((*cola)->nodos != 0)
        resp = 1;

    return resp;
};

void borraLaCola(struct COLA **cola)
{
    struct NODO *actual, *siguiente;
    actual = (*cola)->primero;

    while (actual != NULL)
    {
        siguiente = actual->p_siguiente;
        free(actual);
        actual = siguiente;
    };

    *cola = NULL;
};
int cuantosNodosTieneLaCola(struct COLA **cola)
{
    return (*cola)->nodos;
};



void imprimeCola(struct COLA **cola)
{
    struct NODO *bic = (*cola)->primero;
    if (bic == NULL)
        printf("La Cola no contiene Nodos.");
    else
    {

        printf("Su Cola contiene: ");

        while (bic != NULL)
        {
            printf("%f%d", bic->elemento.archivo,bic->elemento.archivo2);
         
            bic = bic->p_siguiente;
        };

        printf("\n\n");
    };
};

void inicioOperacion(int argv, char** argc)
{
    enum opciones
    {
        salir,
        insertDatos,
        iniciarJuego,
        borraCola,
    } opc;
    struct COLA *cola1;
    struct COLA *cola2;
    struct COLA *cola3;
    struct COLA *cola4;
    struct COLA *cola5;
    int eleccion; 
    char nuevoDato[50];
    float nuevoDato2;

    inicializarCola(&cola1);
inicializarCola(&cola2);
inicializarCola(&cola3);
inicializarCola(&cola4);
inicializarCola(&cola5);


    do
    {
        printf("\n\n");
        printf("Indique que desea hacer con los Nodos de la Cola:\n\n");
        printf("   1. Inserta datos\n");
        printf("   2. Iniciar Juego\n");
        printf("   3. Borra Cola\n");
        printf("   0. Salir del programa.\n");

        do
        {
            scanf("%i", &eleccion);
        } while (eleccion < 0 && eleccion > 12);
        opc = (enum opciones)(eleccion);

        printf("\n\n");

        switch (opc)
        {
        case insertDatos:

            printf("Introduzca altura: ");
            scanf("%f", &nuevoDato2);
           
            if(nuevoDato2 > 1 && nuevoDato2 < 1.2){
                insertAltura(&cola1, nuevoDato2);
                printf("Has sido agregado a la cola 1\n");
                printf("Introduzca nombre:");
                scanf("%s", &nuevoDato);
                insert(&cola1, nuevoDato);
                printf("Introduzca edad: ");
                scanf("%s", &nuevoDato);
                insertedad(&cola1, nuevoDato);
            }else
                if(nuevoDato2 == 1){
                    insertAltura(&cola2, nuevoDato2);
                    printf("Has sido agregado a la cola 2\n");
                    printf("Introduzca nombre:");
                    scanf("%s", &nuevoDato);
                    insert(&cola2, nuevoDato);
                    printf("Introduzca edad: ");
                    scanf("%s", &nuevoDato);
                    insertedad(&cola2, nuevoDato);
                }else
                    if(nuevoDato2 > 1.2 && nuevoDato2 < 1.7){
                        insertAltura(&cola3, nuevoDato2);
                        printf("Has sido agregado a la cola 3\n");
                        printf("Introduzca nombre:");
                        scanf("%s", &nuevoDato);
                        insert(&cola3, nuevoDato);
                        printf("Introduzca edad: ");
                        scanf("%s", &nuevoDato);
                        insertedad(&cola3, nuevoDato);
                    }else
                        if(nuevoDato2 ==1.2 || nuevoDato2 == 1.7){
                            insertAltura(&cola4, nuevoDato2);
                            printf("Has sido agregado a la cola 4\n");
                            printf("Introduzca nombre:");
                            scanf("%s", &nuevoDato);
                            insert(&cola4, nuevoDato);
                            printf("Introduzca edad: ");
                            scanf("%s", &nuevoDato);
                            insertedad(&cola4, nuevoDato);
                        }else
                            if(nuevoDato2 > 1.7 && nuevoDato2 <= 2){
                                printf("Has sido agregado a la cola 5\n");
                                insertAltura(&cola5, nuevoDato2);
                                printf("Introduzca nombre:");
                                scanf("%s", &nuevoDato);
                                insert(&cola5, nuevoDato);
                                printf("Introduzca edad: ");
                                scanf("%s", &nuevoDato);
                                insertedad(&cola5, nuevoDato);
                            }

            break;
 
        


        case iniciarJuego:
        if(tieneNodosLaCola(&cola1)){
            for(int i = 0; i < cuantosNodosTieneLaCola(&cola1);++i){
                printf("Tu turno es: %d\n", i);
                if(cuantosNodosTieneLaCola(&cola1)<= 2){
                printf("Los jugadores son:\n");
                imprimeCola(&cola1);
                } 
            }
        }

        if(tieneNodosLaCola(&cola2)){
            for(int i = 0; i < cuantosNodosTieneLaCola(&cola2);++i){
                printf("Tu turno es: %d\n", i);
                if(cuantosNodosTieneLaCola(&cola2)<= 2){
                    printf("Los jugadores son:\n");
                    imprimeCola(&cola2);
                } 
            }
        }
        if(tieneNodosLaCola(&cola3)){
            for(int i = 0; i < cuantosNodosTieneLaCola(&cola3);++i){
                printf("Tu turno es: %d\n", i);
                if(cuantosNodosTieneLaCola(&cola3)<= 2){
                    printf("Los jugadores son:\n");
                    imprimeCola(&cola3);
                } 
            }
        }
if(tieneNodosLaCola(&cola4)){
            for(int i = 0; i < cuantosNodosTieneLaCola(&cola4);++i){
                printf("Tu turno es: %d\n", i);
                if(cuantosNodosTieneLaCola(&cola4)<= 2){
                    printf("Los jugadores son:\n");
                    imprimeCola(&cola4);
                } 
            }
        }
        if(tieneNodosLaCola(&cola5)){
            for(int i = 0; i < cuantosNodosTieneLaCola(&cola5);++i){
                printf("Tu turno es: %d\n", i);
                if(cuantosNodosTieneLaCola(&cola5)<= 2){
                    printf("Los jugadores son:\n");
                    imprimeCola(&cola5);
                } 
            }
        }   
            break;
        case borraCola:
            borraLaCola(&cola1);
            inicializarCola(&cola1);
            break;
        case salir:
            puts("Gracias por jugar");
            system("PAUSE");
            break;
        };
    } while (opc != salir);

    // Libera la RAM que pudiera quedar sin liberar:
    borraLaCola(&cola1);
    borraLaCola(&cola2);
    borraLaCola(&cola3);
    borraLaCola(&cola4);
    borraLaCola(&cola5);
    
};
void main(int argc, char **argv)
{
    inicioOperacion(argc, argv);
}