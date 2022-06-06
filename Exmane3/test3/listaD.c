#include "listaD.h"

Lista crearLista(){
	Lista l=(Lista)malloc(sizeof(Elemento_Lista));
	if(l==NULL){
		perror("No hay memoria para la lista");
       // *e=-1; 
	}
	else{
		l->cab=NULL;
		//*e=0;
	}
	return l;
}

bool isEmpty(Lista lista){
    if(lista->cab==NULL && lista->cab->sig==NULL){
        //*e=-2;
        return true;
    } else{
        //*e=0;
        return false;
    } 
}

void agregarDer(Lista*lista , Dato datoInfo){
    struct Nodo* temp=(struct Nodo*)malloc(sizeof(struct Nodo));
    struct Nodo* aux;
    if(temp==NULL){
        puts("La estructura no se creo correctamente");
        //*e=-3;
    }
    else if((*lista)->cab==NULL){
        temp->raiz->info=datoInfo;
        temp->sig=NULL;
        temp->pos=0;
        (*lista)->cab=temp;
        //*e=0;
    }
    else{
        temp->raiz->info=datoInfo;
        temp->sig=NULL;
        temp=(*lista)->cab;
        if(aux->sig==NULL){
            temp->pos=1;
        }
        else{
            while(aux->sig!=NULL){
                aux=aux->sig;
            }
            temp->pos=aux->pos+1;
        }
        aux->sig=temp;
        //*e=0;
    }

    struct Nodo* nodoaux=(*lista)->cab;
    while(nodoaux->sig!=NULL){
        nodoaux=nodoaux->sig;
        nodoaux->pos++;
    }
}

void agregarIzq(Lista*lista , Dato datoInfo){
    struct Nodo* aux=(struct Nodo*)malloc(sizeof(struct Nodo));
    if(aux==NULL){
        puts("La estructura no se creo correctamente");
        //*e=-3;
    }
    else if((*lista)->cab==NULL){
        aux->raiz->info=datoInfo;
        aux->sig=(*lista)->cab;
        (*lista)->cab=aux;
    }
    else{
        aux->raiz->info=datoInfo;
        aux->sig=(*lista)->cab;
        (*lista)->cab=aux;
    }
    struct Nodo* nodoaux=(*lista)->cab;
    while(nodoaux->sig!=NULL){
        nodoaux=nodoaux->sig;
        nodoaux->pos++;
    }
}

void agregarPosN(Lista*lista , Dato datoInfo, int pos){
    struct Nodo* aux=(struct Nodo*)malloc(sizeof(struct Nodo));
    struct Nodo *anterior,*nuevo;
    anterior=NULL;
    nuevo=(*lista)->cab;
    aux->raiz->info=datoInfo;
    if(aux==NULL){
        puts("La lista esta vacia");
        //*e=-1;
    }
    else if(!isEmpty(*lista)){
        while(nuevo->pos!=pos){
            anterior=nuevo;
            nuevo=nuevo->sig;

        }
        aux->sig=nuevo;
        anterior->sig=aux;
        struct Nodo*cursor=nuevo;
        while(cursor!=NULL){
            cursor->pos++;
            cursor=cursor->sig;

        }
        //*e=0;
    }
    else if(isEmpty(*lista)){
        aux->raiz->info=datoInfo;
        aux->sig=NULL;
        aux->pos=0;
        (*lista)->cab=aux;
        //*e=0;
    }
}

void extraerIzq(Lista*lista,Dato* datoE){
    struct Nodo*aux=NULL;
    if(isEmpty(*lista)){
        puts("La lista esta vacia\nNada que extraer");
    }
    else if((*lista)->cursor==1){
        *datoE=(*lista)->cab->raiz->info;
        free((*lista)->cab);
        (*lista)->cursor=0;
    }
    else if((*lista)->cursor>1){
        aux=(*lista)->cab;
        *datoE=(*lista)->cab->raiz->info;
        (*lista)->cab=aux->sig;
        (*lista)->cursor--;
        while(aux->sig!=NULL){
            aux=aux->sig;
            aux->pos--;
        }
        free(aux);
        //*e=0;
    }
}

void recorrerLista(Lista lista ){
    struct Nodo* aux=lista->cab;
    while(aux!=NULL){
        printf("\nElemento actual es %c en la posicion %d",aux->raiz->info.caracter,aux->pos);
        aux=aux->sig;
    }
    //*e=0;
}

void borrarLista(Lista* lista ){
    if((*lista)->cab==NULL){
        puts("Lista vacia");
    }
    else{
        struct Nodo* aux=(*lista)->cab->sig;
        struct Nodo* aux2=(*lista)->cab;
        while(aux!=NULL){
            free(aux2);
            aux2=aux;
            aux=aux->sig;

        }
        free(aux2);

    }
    free(lista);
}

