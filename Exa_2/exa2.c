#include "exa2.h"

Cola crearCola(int* e){
    Cola cola=(Cola) malloc(sizeof(Elemento_de_Cola));
    if(cola==NULL){
        *e=-4;
        puts("No se logro obtener memoria para una estructura COLA");
    }
    cola->cabecera=NULL;
    cola->final=NULL;
    cola->cursor=0;
    return cola;
}

// Inserta cola por el final
void encolar(Cola* cola, int* e, Dato datoIngreso){
    struct Nodo* nodoUsuario=(struct Nodo*) malloc(sizeof(struct Nodo));
    if(nodoUsuario==NULL){
        *e=-6;
        puts("La estructura del nuevo nodo no se creo correctamente, favor de liberar datos de la cola");
    }
    else if(estaVacia(*cola, e)){
        (*nodoUsuario).dato=datoIngreso;
        (*nodoUsuario).siguiente=NULL;
        (*cola)->cabecera=nodoUsuario;
        (*cola)->final=nodoUsuario;
    } else{
        (*nodoUsuario).dato=datoIngreso;
        (*nodoUsuario).siguiente=NULL;
        (*cola)->final->siguiente=nodoUsuario;
        (*cola)->final=nodoUsuario;
    }
    (*cola)->cursor++;
    *e=0;
}

//Eliminar dato por la cabecera
void desencolar(Cola* cola, int* e, Dato *datoExtraido){
    struct Nodo* aux=NULL;
    if(estaVacia(*cola,e)){
        puts("Cola vacia, no hay elementos que extraer");
        *e=-3;
    } else if((*cola)->cursor==1){
        *datoExtraido=(*cola)->cabecera->dato;
        (*cola)->cabecera=NULL;
        (*cola)->final=NULL;
        *e=-3;
        (*cola)->cursor=0;
    } else if((*cola)->cursor>1){
        aux=(*cola)->cabecera;
        *datoExtraido=(*cola)->cabecera->dato;
        (*cola)->cabecera=(*cola)->cabecera->siguiente; //(*cola)->cabecera=aux->siguiente; 
        (*cola)->cursor--;
        aux->siguiente=NULL;
        free(aux);
        *e=0;
    }
}

// Devuelve un true o un false si la cola contiene o no Nodos:
bool estaVacia(Cola cola,int *e){
    if(cola->cabecera==NULL && cola->final==NULL && cola->cursor==0){
        *e=-3;
        return true;
    } else{
        *e=0;
        return false;
    }
}

// Libera la memoria RAM usada por la cola:
void borraCola(Cola* cola, int *e,Lista* juego1,Lista* juego2,Lista* juego3,Lista* juego4, Lista* juego5){
    Dato aux;
    while(!estaVacia(*cola,e)){

        printf("\nEdad: %d",(*cola)->cabecera->dato.edad);

        if((*cola)->cabecera->dato.edad>18 && (*cola)->cabecera->dato.edad<22){
            if (juego1->tamano == 0){
                    ins_en_lista_vacia (juego1, (*cola)->cabecera->dato);
                }
                else{
                    ins_fin_lista(juego1,juego1->fin, (*cola)->cabecera->dato);
                } 
            puts("\n: : Persona en fila de juego 1 : : ");
        }

        if((*cola)->cabecera->dato.edad==18){
             if (juego2->tamano == 0){
                    ins_en_lista_vacia (juego2, (*cola)->cabecera->dato);
                }
                else{
                    ins_fin_lista(juego2,juego2->fin, (*cola)->cabecera->dato);
                } 
            puts("\n: : Persona en fila de juego 2 : : ");
        }

        if((*cola)->cabecera->dato.edad>22 && (*cola)->cabecera->dato.edad<44){
                 if (juego3->tamano == 0){
                    ins_en_lista_vacia (juego3, (*cola)->cabecera->dato);
                }
                else{
                    ins_fin_lista(juego3,juego3->fin, (*cola)->cabecera->dato);
                } 
            puts("\n: : Persona en fila de juego 3 : : ");
        }

        if((*cola)->cabecera->dato.edad==22 || (*cola)->cabecera->dato.edad==44){
                 if (juego4->tamano == 0){
                    ins_en_lista_vacia (juego4, (*cola)->cabecera->dato);
                }
                else{
                    ins_fin_lista(juego4,juego4->fin, (*cola)->cabecera->dato);
                }
            puts("\n: : Persona en fila de juego 4 : : ");
        }

        if((*cola)->cabecera->dato.edad>44 && (*cola)->cabecera->dato.edad<=60){
                 if (juego5->tamano == 0){
                    ins_en_lista_vacia (juego5, (*cola)->cabecera->dato);
                }
                else{
                    ins_fin_lista(juego5,juego5->fin, (*cola)->cabecera->dato);
                } 
            puts("\n: : Persona en fila de juego 5 : : ");
        }

        desencolar(cola,e,&aux);
    }
    puts("\n: : Se termino de vaciar la cola : : ");
    *e=0;
   //*cola=crearCola();
   //cola

   /*Borrar cola 2da forma*/
   /* struct Nodo* aux1, *auxResp;
    aux1=(*cola)->cabecera;
    while(aux1!=NULL){
        auxResp=aux1->siguiente;
        aux1->siguiente=NULL;
        free(aux1);
        aux1=auxResp;
    }
    */
}

void imprimeCola(Cola cola , int* e){
    if(cola==NULL){
        puts("Inexistencia de la cola");
    } else if(estaVacia(cola,e)){
        puts("Cola esta vacia");
        *e=-3;
    } else{
        puts("Imprimiendo contenido:");
       /* struct Nodo datoExt;
        for(int iterador=0; iterador<cola->cursor;iterador++){
            desencolar(&cola,e,&datoExt);
            printf("Valor en el nodo extraido: %d\n",datoExt.dato.valor);
        }*/
        struct Nodo* nodoAux=cola->cabecera;
        while(nodoAux!=NULL){
            printf("Los datos en el nodo extraido: edad: %d nombre: %s altura %.2f\n",nodoAux->dato.edad,nodoAux->dato.nombre,nodoAux->dato.altura);
            nodoAux=nodoAux->siguiente;
        }
    }
}

int numAle(){
    int numgen;
    
    srand(time(NULL));
    
    numgen=2+rand()%(2+1-1);
        /*Para generar un número pseudoaleatorio se requiere la función rand
        la fórmula sería la siguiente:
        limite Inferior + rand() % (limite superior + 1 - limite inferior) */

    return numgen;

}

/* ---------- function.h ----------- */
void inicializar (Lista * lista) { 
lista ->inicio = NULL; 
lista ->fin = NULL; 
lista ->tamano = 0;
}

/* insercion en una lista vacia */
/* inserción en una lista vacía */
int ins_en_lista_vacia (Lista * lista, Dato datoUsuario){

  Elemento *nuevo_elemento=(Elemento*)malloc(sizeof (Elemento));
  if(nuevo_elemento==NULL){
    puts("\nNo se pudo reservar memoria dinamica");
  }
  
 
  nuevo_elemento->datoUsuario=datoUsuario;
  nuevo_elemento->siguiente = NULL;
  lista->inicio = nuevo_elemento;
  lista->fin = nuevo_elemento;
  lista->tamano++;

  return 0;
}

/* inserción al inicio de la lista */
int ins_inicio_lista (Lista * lista, Dato datoUsuario) { 

  Elemento *nuevo_elemento=(Elemento*)malloc(sizeof (Elemento));
  if(nuevo_elemento==NULL){
    puts("\nNo se pudo reservar memoria dinamica");
  }
  
 

  nuevo_elemento->datoUsuario=datoUsuario; 
  nuevo_elemento->siguiente = lista->inicio; 
  lista ->inicio = nuevo_elemento; 
  lista ->tamano++; 
return 0;
}

/*insercion al final de la lista */
int ins_fin_lista (Lista * lista, Elemento * actual, Dato datoUsuario) { 

  Elemento *nuevo_elemento=(Elemento*)malloc(sizeof (Elemento));
  if(nuevo_elemento==NULL){
    puts("\nNo se pudo reservar memoria dinamica");
  }
  
 

  nuevo_elemento->datoUsuario=datoUsuario;
  actual->siguiente = nuevo_elemento; 
  nuevo_elemento->siguiente = NULL; 
  lista ->fin = nuevo_elemento; 
  lista ->tamano++; 
return 0;
}

/* insercion en la posicion solicitada */
int ins_lista (Lista * lista, Dato datoUsuario, int pos) { 

    if (lista ->tamano < 2){
    return -1; 
    }

    if (pos < 1 || pos >= lista ->tamano){
    return -1; 
    } 

    Elemento *actual; 
    Elemento *nuevo_elemento; 
    int i; 

    nuevo_elemento=(Elemento*)malloc(sizeof (Elemento));
    if(nuevo_elemento==NULL){
    puts("\nNo se pudo reservar memoria dinamica");
    return 1;
    }
  

    actual=lista ->inicio; 

    for (i = 1; i < pos; ++i){
        actual = actual->siguiente; 
        if (actual->siguiente == NULL){
            return -1; 
        } 
    
    nuevo_elemento->datoUsuario=datoUsuario; 
    nuevo_elemento->siguiente = actual->siguiente; 
    actual->siguiente = nuevo_elemento; 
    lista ->tamano++; 

    return 0;
    } 

    
}

/* supresión al inicio de la lista */
int sup_inicio (Lista * lista) {

   if (lista ->tamano == 0){
  return -1; 
  } 

  Elemento *sup_elemento=(Elemento*)malloc(sizeof(Elemento));

  sup_elemento = lista ->inicio; 
  lista ->inicio = lista ->inicio->siguiente; 
  if (lista ->tamano == 1){
    lista ->fin = NULL;
  } 

  free (sup_elemento); 
  lista ->tamano--; 
  return 0;
}

/* supresión al final de la lista */
int sup_final (Lista * lista){

  int pos=(lista->tamano)-1;
  sup_en_lista (lista, pos);
  return 0;
}


/* suprimir un elemento después de la posición solicitada */
int sup_en_lista (Lista * lista, int pos) { 
if (lista ->tamano <= 1 || pos < 1 || pos >= lista ->tamano) 
return -1; 
int i; 
Elemento *actual; 
Elemento *sup_elemento; 
actual = lista ->inicio; 
for (i = 1; i < pos; ++i)
actual = actual->siguiente; 
sup_elemento = actual->siguiente; 
actual->siguiente = actual->siguiente->siguiente; 
if(actual->siguiente == NULL) lista ->fin = actual; 
free (sup_elemento);
lista ->tamano--;
return 0;
}

/* visualización de la Lista */
void muestra (Lista * lista){ 

    Elemento *actual=(Elemento*)malloc(sizeof(Elemento)); 
    if(actual==NULL){
    puts("\nNo se pudo crear el nodo Elemento");
    }
    actual = lista ->inicio; 
    while (actual != NULL){ 
    printf ("\n%s | %d", actual->datoUsuario.nombre, actual->datoUsuario.edad); 
    actual = actual->siguiente; 
        }
}

/* destruir la Lista */
void Atender(Lista* juego1,Lista* juego2,Lista* juego3,Lista* juego4, Lista* juego5){
    int turno=0, juego=0;
    printf("\nAtendiendo");
    
    printf("\nJuego 1: %d",juego1->tamano);
    printf("\nJuego 2: %d",juego2->tamano);
    printf("\nJuego 3: %d",juego3->tamano);
    printf("\nJuego 4: %d",juego4->tamano);
    printf("\nJuego 5: %d",juego5->tamano);



 while((juego1->tamano>=0) && (juego2->tamano>=0) && (juego3->tamano>=0) && (juego4->tamano>=0) && (juego5->tamano>=0)){
      turno++;
      juego++;
      printf("\nTurno no. %d - Juego %d",turno,juego);

      switch(juego){
          case 1:
                if(juego1->tamano==0){
                    printf("\nNo hay nadie en la juegos 1");
                }
                else if(juego1->tamano==1){
                    printf("\nAtendiendo a:\n%s | %d",juego1->inicio->datoUsuario.nombre, juego1->inicio->datoUsuario.edad);
                    sup_inicio (juego1);
                }
                else if(juego1->tamano>1){
                    printf("\nAtendiendo a:\n%s | %d",juego1->inicio->datoUsuario.nombre, juego1->inicio->datoUsuario.edad);
                    sup_inicio (juego1);
                    printf(" y a %s | %d",juego1->inicio->datoUsuario.nombre, juego1->inicio->datoUsuario.edad);
                    sup_inicio (juego1);
                }
          break;

          case 2:

           if(juego2->tamano==0){
                    printf("\nNo hay nadie en la juegos 2");
                }
            else if(juego2->tamano==1){
                    printf("\nAtendiendo a:\n%s | %d",juego2->inicio->datoUsuario.nombre, juego2->inicio->datoUsuario.edad);
                    sup_inicio (juego2);
            }
            else if(juego2->tamano>1){
                    printf("\nAtendiendo a:\n%s | %d",juego2->inicio->datoUsuario.nombre, juego2->inicio->datoUsuario.edad);
                    sup_inicio (juego2);
                    printf(" y a %s | %d",juego1->inicio->datoUsuario.nombre, juego1->inicio->datoUsuario.edad);
                    sup_inicio (juego2);  
                }
          break;

          case 3:
          if(juego3->tamano==0){
                    printf("\nNo hay nadie en la juegos 3");
                   
                }
            else if(juego3->tamano==1){
                    printf("\nAtendiendo a:\n%s | %d",juego3->inicio->datoUsuario.nombre, juego3->inicio->datoUsuario.edad);
                    sup_inicio (juego3);
                  
                }
                else if(juego3->tamano>1){
                    printf("\nAtendiendo a:\n%s | %d",juego3->inicio->datoUsuario.nombre, juego3->inicio->datoUsuario.edad);
                    sup_inicio (juego3);
                    printf(" y a %s | %d",juego3->inicio->datoUsuario.nombre, juego3->inicio->datoUsuario.edad);
                    sup_inicio (juego3);
                }
          break;

          case 4:
          if(juego4->tamano==0){
                    printf("\nNo hay nadie en la juegos 4");
                    
                }
            else if(juego4->tamano==1){
                    printf("\nAtendiendo a:\n%s | %d",juego4->inicio->datoUsuario.nombre, juego4->inicio->datoUsuario.edad);
                    sup_inicio (juego4);
                   
                }
               else if(juego4->tamano>1){
                    printf("\nAtendiendo a:\n%s | %d",juego4->inicio->datoUsuario.nombre, juego4->inicio->datoUsuario.edad);
                    sup_inicio (juego4);
                    printf(" y a %s | %d",juego4->inicio->datoUsuario.nombre, juego4->inicio->datoUsuario.edad);
                    sup_inicio (juego4);
                }
          break;

          case 5:
            if(juego5->tamano==0){
                    printf("\nNo hay nadie en la juegos 5");
                }
                else if(juego5->tamano==1){
                    printf("\nAtendiendo a:\n%s | %d",juego5->inicio->datoUsuario.nombre, juego5->inicio->datoUsuario.edad);
                    sup_inicio (juego5);
                
                }
                else if(juego5->tamano>1){
                    printf("\nAtendiendo a:\n%s | %d",juego5->inicio->datoUsuario.nombre, juego5->inicio->datoUsuario.edad);
                    sup_inicio (juego5);
                    printf(" y a %s | %d",juego5->inicio->datoUsuario.nombre, juego5->inicio->datoUsuario.edad);
                    sup_inicio (juego5);
                
                    
                }
          break;
    }

      printf("\nPersonas esperando en este turno: ");
                    printf("\njuegos 1:");
                    muestra(juego1);
                    printf("\njuegos 2:");
                    muestra(juego2);
                    printf("\njuegos 3:");
                    muestra(juego3);
                    printf("\njuegos 4:");
                    muestra(juego4);
                    printf("\njuegos 5:");
                    muestra(juego5);
                    
      if(juego==5){
          juego=0;
    
      }

    if((juego1->tamano==0) && (juego2->tamano==0) && (juego3->tamano==0) && (juego4->tamano==0) && (juego5->tamano==0)){
       printf("\n\t: : YA NO HAY MÁS CLIENTES EN LAS FILAS NI EN LA COLA");
        break;
    
    }
      
  }
    
}