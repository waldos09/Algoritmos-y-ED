#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
typedef struct{
  char* pais;
  char* nombre;
  float alto;
  int  tel;
}Dato;

typedef struct{
	Dato Datos;
}database;

database bd[]={
[0]={"Espa�a", "ESTEFANIA", 1.62, 558205580 },
[1]={"Venezuela", "QUERALT", 1.55, 556545115 },
[2]={"Peru", "JOAN", 1.6, 558202768 },
[3]={"Ecuador", "JOAN", 1.8, 558727844 },
[4]={"Guatemala", "MARC", 1.81, 558350521 },
[5]={"Cuba", "JOSEP", 1.57, 558755645 },
[6]={"Republica Dominicana", "ESTHER", 1.57, 556520547 },
[7]={"Honduras", "LAURA", 1.72, 556565656 },
[8]={"Bolivia", "RAQUEL", 1.81, 556752156 },
[9]={"El Salvador", "JOAN", 1.62, 558300025 },
[10]={"Nicaragua", "MARIA ISABEL", 1.56, 558385567 },
[11]={"Paraguay", "ADRIA", 1.6, 557809812 },
[12]={"Costa Rica", "GERARD", 1.87, 556520741 },
[13]={"Panama", "ELIOT", 1.82, 558202456 },
[14]={"Guinea Ecuatorial", "JORDI", 1.6, 558754554 },
[15]={"Barbados", "LUIS", 1.67, 556875544 },
[16]={"Belice", "LAURA", 1.87, 555880712 },
[17]={"Botsuana", "JORDI", 1.75, 556875255 },
[18]={"Camerun", "DOUNYA", 1.73, 556542775 },
[19]={"Canada", "JULIO", 1.86, 558773545 },
[20]={"Dominica", "ANDREU", 1.79, 558200022 },
[21]={"Eritrea", "RAMON", 1.81, 556512545 },
[22]={"Filipinas", "DAVID-JESE", 1.57, 557785655 },
[23]={"Gambia", "ARAN", 1.64, 558300385 },
[24]={"Ghana", "GEMMA", 1.69, 556520471 },
[25]={"Granada", "IVAN", 1.56, 556012445 },
[26]={"Guyana", "DAVID", 1.57, 554500611 },
[27]={"India", "XAVIER", 1.73, 557885544 },
[28]={"Irlanda", "MARIO", 1.75, 556512105 },
[29]={"Jamaica", "JESUS", 1.82, 558202200 },
[30]={"Francia", "GEMMA", 1.81, 559965585 },
[31]={"Canada", "SILVIA", 1.62, 556541235 },
[32]={"Madagascar", "ALBERT", 1.71, 558204054 },
[33]={"Camerun", "MARIA", 1.73, 556584541 },
[34]={"Ruanda", "BERTA", 1.71, 554111475 },
[35]={"Belgica", "BERTA", 1.9, 555687444 },
[36]={"Guinea", "MIREIA", 1.87, 556658711 },
[37]={"Hait�", "GEMMA", 1.89, 558773941 },
[38]={"Botsuana", "MARIA ISABEL", 1.83, 558305295 },
[39]={"Camerun", "TONI", 1.59, 556524446 },
[40]={"Canada", "ALEJANDRO", 1.78, 558305551 },
[41]={"Dominica", "JOAN MARTI", 1.72, 558206097 },
[42]={"Eritrea", "INGRID", 1.89, 554500644 },
[43]={"Filipinas", "OLIVER", 1.66, 558305594 },
[44]={"Gambia", "SANDRA", 1.6, 558300422 },
[45]={"Guyana", "JORDI", 1.74, 558350511 },
[46]={"India", "MARC", 1.7, 558727589 },
[47]={"Irlanda", "JORDINA", 1.59, 558208488 },
[48]={"Jamaica", "MARIA JOSE", 1.87, 558320587 },
[49]={"Francia", "RAQUEL", 1.78, 558203095 },
[50]={"Canada", "ENRIC", 1.86, 554555455 },
[51]={"Madagascar", "MARTA", 1.65, 558208502 },
[52]={"Camerun", "CARLA", 1.73, 558205245 },
[53]={"Ruanda", "MARIA NOELIA", 1.56, 558300374 },
[54]={"Belgica", "CRISTINA", 1.67, 558305576 },
[55]={"Canada", "CARLOS", 1.82, 558208614 },
[56]={"Dominica", "DAVID", 1.7, 558770077 },
[57]={"Eritrea", "CRISTIAN", 1.7, 558200713 },
[58]={"Filipinas", "JULIO ALBERTO", 1.65, 558270685 },
[59]={"Gambia", "SERGI", 1.79, 556021048 },
[60]={"Guyana", "ALEIX", 1.7, 558773553 },
[61]={"India", "VERONICA", 1.84, 558206766 },
[62]={"Irlanda", "MARIONA", 1.81, 558305223 },
[63]={"Jamaica", "MARC", 1.81, 558325565 },
[64]={"Guatemala", "GEMMA", 1.56, 556565448 },
[65]={"Cuba", "RICARD", 1.74, 558208360 },
[66]={"Republica Dominicana", "JUAN", 1.6, 556549889 },
[67]={"Honduras", "MARTA", 1.73, 558208677 },
[68]={"Bolivia", "NAT�LIA", 1.86, 558325558 },
[69]={"El Salvador", "MARTA", 1.88, 558360281 },
[70]={"Nicaragua", "LAURA", 1.89, 558208380 },
[71]={"Paraguay", "JOAN", 1.83, 558770878 },
[72]={"Costa Rica", "ALEXIA", 1.67, 556874511 },
[73]={"Panama", "FERRAN", 1.81, 556548745 },
[74]={"Guinea Ecuatorial", "CRISTINA", 1.74, 558755512 },
[75]={"Guyana", "JOSE ANTONIO", 1.59, 558722096 },
[76]={"India", "JORDI", 1.85, 554512544 },
[77]={"Irlanda", "BEGONYA", 1.8, 558205011 },
[78]={"Jamaica", "INGRID", 1.82, 558300864 },
[79]={"Guatemala", "MIQUEL", 1.64, 553256844 },
[80]={"Cuba", "AGUSTI", 1.59, 556528779 },
[81]={"Republica Dominicana", "ANTONI", 1.84, 551021886 },
[82]={"Honduras", "JOAN", 1.71, 556201457 },
[83]={"Bolivia", "MONICA", 1.86, 558207515 },
[84]={"Jamaica", "GERARD", 1.84, 558208558 },
[85]={"Francia", "GEMMA", 1.76, 558300496 },
[86]={"Canada", "MARIA", 1.77, 550120545 },
[87]={"Madagascar", "ORIOL", 1.7, 558207095 },
[88]={"Camerun", "VIRGINIA", 1.82, 558300214 },
[89]={"Ruanda", "DAMIA", 1.64, 558727244 },
[90]={"Belgica", "VALENTI", 1.65, 556565874 },
[91]={"Guinea", "AINA", 1.75, 558205782 },
[92]={"Haiti", "DAVID", 1.73, 558305551 },
[93]={"Botsuana", "GERARD", 1.72, 556577225 },
[94]={"Camerun", "MARTA", 1.72, 558773647 },
[95]={"Canada", "MIREIA", 1.57, 558208054 },
[96]={"Dominica", "ELOI", 1.61, 558208054 },
[97]={"Jamaica", "ANNA", 1.84, 550712563 },
[98]={"Guatemala", "ALBA", 1.57, 558204078 },
[99]={"Cuba", "SANDRA", 1.61, 556871045 },
[100]={"Republica Dominicana", "ERIC", 1.68, 558745211 },
[101]={"Honduras", "LUIS", 1.75, 558300065 },
[102]={"Bolivia", "CRISTIAN", 1.63, 558208674 },
[103]={"Jamaica", "GUILLEM", 1.87, 550214054 },
[104]={"Francia", "DIMAS", 1.61, 556521404 },
[105]={"Canada", "ANA INES", 1.82, 558350555 },
[106]={"Madagascar", "IVET", 1.55, 559962045 },
[107]={"Camerun", "JULIA", 1.59, 558755603 },
[108]={"Madagascar", "DANIEL", 1.6, 558305524 },
[109]={"Camerun", "ABEL", 1.89, 556571974 },
[110]={"Ruanda", "IRENE", 1.66, 558300036 },
[111]={"Belgica", "ADRIA", 1.84, 556505455 },
[112]={"Guinea", "JAIRO", 1.78, 556587454 },
[113]={"Haiti", "CRISTINA", 1.86, 558725845 },
[114]={"Botsuana", "DAVID", 1.83, 558205730 },
[115]={"Camerun", "ADRIA", 1.71, 556828258 },
[116]={"Canada", "LUCIA", 1.58, 558300045 },
[117]={"Dominica", "CARLA", 1.55, 556521452 },
[118]={"Guinea", "ADRI�", 1.58, 558725885 },
[119]={"Haiti", "MARTA", 1.77, 558208303 },
[120]={"Botsuana", "MARC", 1.58, 558360213 },
[121]={"Camerun", "ALEX", 1.65, 558320537 }

};
//Generamos los prototipos
void ordalto(int tam, database bd[]);
void printArray(database *arreglo, int tam);
void merge(database *arregloIzq, database *arregloDer, int tamIzq, int tamDer, database*arregloFinal, int tamArrFinal);
void sort(database *arreglo, int tam);
void inicioOperacion(int argc, char** argv);
void ordCell( int tam, database bd[]);
void ordpais(int tam, database bd[]);
void imprimirAlturaTDA(int tam, database bd[]);
void imprimirNumeroTDA(int tam, database bd[]);
void imprimirPaisTDA(int tam, database bd[]);
void imprimirTDA(int tam, database bd[]);

int main(int argc, char** argv){
 int option = 0;
  while(option != 6){
    printf("Elija como deseaa ordenar los datos: \n");
    printf("1-Imprimir en desorden\n");
    printf("2-Altura\n");
    printf("3-Nombre (segunda letra)\n");
    printf("4-Numero telefonico:\n");
    printf("5-Ordenar por pais de origen\n");
    printf("6-Salir \n");
    scanf("%d", &option);
  
    switch(option) {
    	
     case 1:
    	printf("Imprimir en desorden:\n");
        imprimirTDA(122, bd);
        break;
      case 2: 
        printf("Ordenar personas por altura:\n");
        ordalto(122, bd);
        imprimirAlturaTDA(122, bd);
        break;
      
      case 3: 
        printf("Ordenar personar por la segunda letra del nombre:\n");
        void printArray(database *arreglo, int tam);
        void merge(database *arregloIzq, database *arregloDer, int tamIzq, int tamDer, database *arregloFinal, int tamArrFinal);
        void sort(database *arreglo, int tam);
        void inicioOperacion(int argc, char** argv);
        inicioOperacion(argc,argv);
        break;
      
      case 4: 
        printf("Ordenar por numero telefonico: \n");
        ordCell(122,bd);
        imprimirNumeroTDA(122, bd);
        break;
      
      case 5: 
        printf("Ordenar por pais de origen:\n");
        ordpais(122, bd);
        imprimirPaisTDA(122, bd);
        break;
      default:
       break; 
    }
  }
}
//Seleccion:
void ordalto(int tam, database bd[]){
	int i,j ;
    for(i = 0; i < tam; i++){
        for(j = i+1; j < tam; j++){
            if(bd[j].Datos.alto < bd[i].Datos.alto){
                database cont = bd[i];
                bd[i] = bd[j];
                bd[j] = cont;
            }
        }
    }
}

//Merge Sort
void printArray(database *arreglo, int tam){
	int i=0;
    for( i=0; i<tam; i++)
        printf("%s || %f || %d || %s \n",bd[i].Datos.nombre, bd[i].Datos.alto, bd[i].Datos.tel, bd[i].Datos.pais);
}

void merge(database *arregloIzq, database *arregloDer, int tamIzq, int tamDer, database*arregloFinal, int tamArrFinal){
    int i=0,j=0,k=0;
    while(i<tamIzq && j<tamDer){
        //iniciamos en la 1 pos para aordenar por alfbeto desde el 2 dato en el array   
        if(arregloIzq[i].Datos.nombre[1]<arregloDer[j].Datos.nombre[1]){
            arregloFinal[k]=arregloIzq[i];
            i++;
        }
        else{
            arregloFinal[k]=arregloDer[j];
            j++;
        }
        k++;
    }
    while(i<tamIzq){
        arregloFinal[k]=arregloIzq[i];
        i++;
        k++;
    }
    while(j<tamDer){
        arregloFinal[k]=arregloDer[j];
        j++;
        k++;
    }
}

void sort(database *arreglo, int tam){
    if(tam>1){
        int posMedia=tam/2;
        int i=0,j=0;
        database arregloIzq[posMedia]; 
        database arregloDer[tam-posMedia]; 
        for(i=0; i<posMedia; i++)
            arregloIzq[i]=arreglo[i];
        for(i=posMedia; i<tam; i++){
            arregloDer[j]=arreglo[i];
            j++;
        }
        sort(arregloIzq,posMedia);
        sort(arregloDer,tam-posMedia);
        merge(arregloIzq,arregloDer,posMedia,tam-posMedia,arreglo,tam);
    }
}

void inicioOperacion(int argc, char** argv){
 
    sort(bd,121);
    puts("Arreglo ordenado:");
    printArray(bd,121);
}
//Algoritmo Burbuja:
void ordCell(int tam, database bd[])
{
int i=0;
int ordenado = 0;
while ( !ordenado )
    {
    ordenado=1;
   for(i = 0; i<tam-1; i++)
      {
     if(bd[i].Datos.tel>bd[i+1].Datos.tel)
            {
                database aux = bd[i];
                bd[i] = bd[i+1];
                bd[i+1] = aux;
                ordenado = 0;
            }   
    }
   }
}
//Insercion
void ordpais(int tam, database bd[]){
  database pivote; 
  int i, j;
  for (i=1; i<tam; i++){
    pivote=bd[i]; j=i-1;
    //igual q en merge
      while(j>=0 && bd[j].Datos.pais[0]>pivote.Datos.pais[0]){
       bd[j+1] = bd[j];     
        j=j-1;
      }
        bd[j+1]=pivote;
  }
}

//imprimir altura
void imprimirAlturaTDA(int tam, database bd[]){
	int i, j; 
  for( i=0; i<tam; i++){
    printf("%f || %s || %d || %s \n", bd[i].Datos.alto , bd[i].Datos.nombre, bd[i].Datos.tel, bd[i].Datos.pais);
  }
}
//imprimir no
void imprimirNumeroTDA(int tam, database bd[]){
	int i, j; 
  for( i=0; i<tam; i++){
    printf("%d || %f || %s || %s \n", bd[i].Datos.tel, bd[i].Datos.alto, bd[i].Datos.nombre, bd[i].Datos.pais);
  }	
}
//por pais
void imprimirPaisTDA(int tam, database bd[]){
	int i, j; 
  for( i=0; i<tam; i++){
    printf("%s || %s || %f || %d \n", bd[i].Datos.pais, bd[i].Datos.nombre, bd[i].Datos.alto, bd[i].Datos.tel);
  }
}
//random
void imprimirTDA(int tam, database bd[]){
	int i, j; 
  for( i=0; i<tam; i++){
    printf("[%d] || %s || %f || %d || %s \n", i, bd[i].Datos.nombre, bd[i].Datos.alto, bd[i].Datos.tel, bd[i].Datos.pais);
  }
}



