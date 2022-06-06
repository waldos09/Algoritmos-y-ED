#include "listaD.h"


Arbol crearNodo(Dato valor){
    Arbol arbol=(Arbol)malloc(sizeof(Elemento_De_Arbol_Binario));
    if(arbol==NULL){
        perror("No hay memoria para tu nodo");
    } else{
        arbol->izq=arbol->der=NULL;
        arbol->info=valor;
    }
    return arbol;
}


//Funcion devuelve la raiz del arbol creado
/**
 * @param raiz Nueva raiz con Hijo izquierdo e hijo derecho, con valorRaiz como clave
 * @param Hizq  Nodo que se coloca a la izquierda del nuevo nodo raiz, previamente creado o NULL
 * @param Hder Nodo ue se coloca a la derecha del nuevo nodo raiz, previamente creado o NULL
 */
void nuevoArbol(Arbol* raiz, Arbol Hizq, Arbol Hder, Dato valorRaiz){ 
    (*raiz)=crearNodo(valorRaiz);
    (*raiz)->der=Hder;
    (*raiz)->izq=Hizq;
}

/**
* @param raiz Raiz del subarbol donde se contara la profundidad
*/
int profundidadArbol(Arbol raiz){ 
    if(!raiz){
        return 0;
    } else{
        int profundidadIzq, profundidadDerecha;
        profundidadIzq=profundidadArbol(raiz->izq);
        profundidadDerecha=profundidadArbol(raiz->der);
        if(profundidadIzq>profundidadDerecha)
            return profundidadIzq+1;
        else 
            return profundidadDerecha+1;
    }
}

void contarHojas(Arbol raiz, int* contadorHojas){
    if(raiz){
        contarHojas(raiz->izq,contadorHojas);
        contarHojas(raiz->der, contadorHojas);
        if(raiz->izq==NULL && raiz->der==NULL)
            (*contadorHojas)++;
    }
}

void preOrden(Arbol raiz){ 
    if(raiz){
		printf("letra:%c-frec:%d,",raiz->info.caracter, raiz->info.frecuencia);
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}

void posOrden(Arbol raiz){ 
	if(raiz){
		posOrden(raiz->izq);
		posOrden(raiz->der);
		printf("letra:%c-frec:%d,",raiz->info.caracter, raiz->info.frecuencia);
	}
}

void inOrden(Arbol raiz){ 
	if(raiz){
		inOrden(raiz->izq);
		printf("letra:%c-frec:%d,",raiz->info.caracter, raiz->info.frecuencia);
		inOrden(raiz->der);
	}
}

void eliminarArbol(Arbol* raiz){ 
    if(*raiz){
        eliminarArbol(&((*raiz)->izq));
        eliminarArbol(&((*raiz)->der));
        free(*raiz);
		*raiz=NULL;
    }
}

void buscarNodo(Arbol raiz, Dato valor, Arbol* nodoEncontrado){ 
    if(raiz){
        if(raiz->info.frecuencia==valor.frecuencia){
            *nodoEncontrado=raiz;       //Aqui se sobre escribe el valor nulo, por el valor encontrado.
        } else if(valor.frecuencia>raiz->info.frecuencia){
            buscarNodo(raiz->der, valor, nodoEncontrado);
        } else{
            buscarNodo(raiz->izq, valor, nodoEncontrado);
        }
    } 
}


void ingresarNodo(Arbol* raiz, Dato valor){ 
    if(!(*raiz)){
        (*raiz)=crearNodo(valor);
    } else if(valor.frecuencia<(*raiz)->info.frecuencia){
        ingresarNodo(&((*raiz)->izq),valor);
    } else if(valor.frecuencia>=(*raiz)->info.frecuencia){
        ingresarNodo(&((*raiz)->der),valor);
    }
}


void eliminarNodo(Arbol* raiz, Dato valor){ 
    if((*raiz)){
		Arbol aux=(*raiz);
		if(valor.frecuencia==(*raiz)->info.frecuencia){
			printf("\nSe encontro el nodo con el valor %d\n", (*raiz)->info);
			if(aux->izq==NULL){
				*raiz=aux->der;
			} else if (aux->der==NULL){
				*raiz=aux->izq;
			} else{
				reemplazar(&aux);
			}
			free(aux);
			aux=NULL;
		}else if(valor.frecuencia<(*raiz)->info.frecuencia)
			eliminarNodo(&((*raiz)->izq),valor);
		else if(valor.frecuencia>(*raiz)->info.frecuencia)
			eliminarNodo(&((*raiz)->der),valor);
	}
}


//Nodo será en un principio el nodo a eliminar (solicitado por el usuario),
//Despues se convertira en el nodo más pequeño, para que este sea quien se elimine.
void reemplazar(Arbol* nodo){ 
    Arbol nodoMinimo, nodoAnterior;
    nodoAnterior=*nodo;
    //Se busca el valor más pequeño en el sub arbol derecho
    nodoMinimo=(*nodo)->der;
    while(nodoMinimo->izq!=NULL){ 
        nodoAnterior=nodoMinimo;
        nodoMinimo=nodoMinimo->izq;
    }
	//Se respalda el valor pequeño para despues asignarse al nodo raiz
    Dato aux=nodoMinimo->info;
	//Se asigna un valor muy pequeño provisional, ya que en cualquier caso de que 
	//el valor más pequeño resulte ser el mismo valor que el que se desea eliminar esto provocará un 
	//bucle infinito
	(*nodo)->info.frecuencia=0;
    //Se borra el nodo minimo
    eliminarNodo(nodo,nodoMinimo->info);
	 //Se reemplaza el nodo a eliminar por el nodo con valor más pequeño
	(*nodo)->info=aux;
    //Se marca el nodominimo para eliminación    
    *nodo=nodoMinimo;
}



Arbol deleteNodeBST(Arbol raiz, Dato valor) {
  // Return el mismo arbol si es que esta vacio
  if (raiz == NULL) 
	  return raiz;

  // Encontrando el nodo para eliminarse 
  if (valor.frecuencia < raiz->info.frecuencia)
    raiz->izq = deleteNodeBST(raiz->izq, valor);
  else if (valor.frecuencia > raiz->info.frecuencia)
    raiz->der = deleteNodeBST(raiz->der, valor);
  else {
	  //Se evalua caso de que el nodo a eliminar tenga un hijo o 0 hijos
    if (raiz->izq == NULL) {
      Arbol temp = raiz->der;
      free(raiz);
      return temp;
    } else if (raiz->der == NULL) {
      Arbol temp = raiz->izq;
      free(raiz);
      return temp;
    }
    // En caso de que se tengan dos hijos
    Arbol temp = nodoMinimo(raiz->der);
    // Reemplaza el nodo solicitado por el usuario por el más pequeño del subarbol derecho
    raiz->info = temp->info;
    // Elimina el nodo más pequeño del sub-arbol derecho, utilizado para remplazar al nodo eliminado por el usuario
    raiz->der = deleteNodeBST(raiz->der, temp->info);
  }
  return raiz;
}


// Funcion para encontrar el valor más pequeño de un arbol
Arbol nodoMinimo(Arbol nodo) {
  Arbol actual = nodo;
  // Buscamos en todos los subarboles izquierdos
  while (actual && actual->izq != NULL)
    actual = actual->izq;
  return actual;
}

//Funciones Huffman

void ordenar(Lista* l){
    struct Nodo*aux=(*l)->cab;
    Dato pivote;
    if(aux->sig==NULL){
        puts("\nNo hay otro dato a comparar");
    }
    else{
        while(aux->sig!=NULL){
            pivote=aux->sig->raiz->info;
            struct Nodo* aux2=(*l)->cab;
            while(aux2!=NULL){
                if(aux2->raiz->info.frecuencia>aux->sig->raiz->info.frecuencia){
                    pivote=aux->raiz->info;
                    aux->raiz->info=aux->sig->raiz->info;
                    aux->sig->raiz->info=pivote;
                }
                aux2=aux2->sig;
            }
           aux=aux->sig; 
        }
    }
}

char conversor(int codigo){
    char caracter;
    if(codigo==0)
        caracter='0';
    else if(codigo==1)  
        caracter='1';
    return caracter;
}

void asignaCodigo(Arbol r, int codigo[], int n, FILE* pf){
    int i;
    char c;
    
    if((r->izq==NULL) && (r->der==NULL)){
        printf("\n\t%c Codigo: ",r->info.caracter);
        for(i=0; i< n; i++){
            c=conversor(codigo[i]);
            fwrite(&c,sizeof(char),1,pf);
            printf("%d", codigo[i]);
        }
        c=' ';
        fwrite(&c,sizeof(char),1,pf);
        c=' ';
        fwrite(&c,sizeof(char),1,pf);
            
    } else{
        codigo[n]=0; //Suponemos que siempre ira por la izquierda
        n++;
        asignaCodigo(r->izq,codigo,n,pf);
        codigo[n-1]=1; //Por si el recorrido tuvo que ser por la derecha
        asignaCodigo(r->der,codigo,n,pf);
    }

}

int buscar(FILE* pf,char indice){
    char letra;
    int frecuencia;
    while(!feof(pf)){
        letra=getc(pf);
        if(indice==letra){
            frecuencia++;
        }
    }
    return frecuencia;
}

void iniciaOperacion(int argc, char** argv){
    Arbol* raiz;
    Lista l=crearLista();
    FILE* pf=fopen("C:\\Users\\waldo\\OneDrive\\Escritorio\\LCD_2\\AED\\Exmane3\\test3TextoPlano.txt","r");
    int i,j,n,sumaFrecuencias,codigo[20];
    char letra;
    //Arreglo de arboles
    /*Arbol* arreglo=(Arbol*) malloc(sizeof(Arbol)*20);//Hasta 20 subarboles
    if(arreglo==NULL){
        perror("Se acabo la memoria para el arreglo de arboles");
        exit(1);
    }*/
    int frecuencia;
    printf("Codigo de Huffman");
    //La tabla de frecuencias la proporcionará el usuario, caracter por caracter

        /*printf("\nIngresa el caracter y su frecuencia:");
        fflush(stdin);
        letra=getchar();*/
        //scanf("%d", &frecuencia);
        //printf("valores leidos: ca=%c, f=%d",dato,frecuencia);
        
        while(!feof(pf))
        {
            letra=getc(pf);
            puts("\nLectura caracter");
            printf("hola");
            frecuencia=buscar(pf,letra);
            
            Dato nuevoCar={frecuencia,letra};
            puts("\nCaracter obtenido");
            (*raiz)=crearNodo(nuevoCar);
            puts("\nNodo creado");
            agregarIzq(&l,(*raiz)->info); //Ingresa el arreglo con los datos al arreglo
            puts("\nNodo ingresado a la lista");
        }
        
        
    fclose(pf);
    struct Nodo*aux=(*l).cab;
    while(aux->sig!=NULL){
        ordenar(&l);
        sumaFrecuencias=aux->raiz->info.frecuencia+aux->sig->raiz->info.frecuencia;
        letra=aux->sig->raiz->info.caracter;
        Dato nuevaRaiz={sumaFrecuencias,letra}; //Construcción del nuevo subárbol
        nuevoArbol(raiz, aux->raiz, aux->sig->raiz,nuevaRaiz);
        printf("se crea raiz: c=%c, frecSuma=%d\n", (*raiz)->info.caracter,(*raiz)->info.frecuencia);
        extraerIzq(&l, NULL);
        extraerIzq(&l,NULL);
        aux->raiz=*raiz;
        
        agregarDer(&l,aux->raiz->info);
    }
    FILE* p=fopen("D:\\OneDrive\\Documentos\\ESCOM Bv\\2AM1\\Algoritmia_y_Estructura_de_Datos\\Programas_Windows\\ExamenFinal\\CodigoHuff.txt","w");
    //Se le asigna el código a cada caracter que hay en el árbol de Huffman
    asignaCodigo(l->cab->raiz,codigo,0,pf);
    fclose(pf);
    FILE* f=fopen("D:\\OneDrive\\Documentos\\ESCOM Bv\\2AM1\\Algoritmia_y_Estructura_de_Datos\\Programas_Windows\\ExamenFinal\\CodigoHuff.txt","r");
    while(!feof(pf)){
        letra=getc(pf);
        printf("%c",letra);
    }
    //Eliminación de árbol y liberación de memoria.
    eliminarArbol(&l->cab->raiz);
    borrarLista(&l);
}
