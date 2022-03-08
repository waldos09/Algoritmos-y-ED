#include <stdio.h>
#include <stdio.h>

typedef struct libro{
  char* titulo;
  char* tFuente;
  float alto;
  float ancho;
}Libro;

Libro database[] = {
  [0] = {"Anecdota de un dia", "Tiahoma Black", 8.5, 3.18},
  [1] = {"Burros Blancos", "Agency", 7.5, 0.74},
  [2] = {"Cien años y uno mas", "Abscissa", 6.5, 0.3},
  [3] = {"Diamantes y dados", "HP Simplified", 5.5, 0.14},
  [4] = {"EL Avestrus", "Arial", 4.5, 0.58},
  [5] = {"El Cuento", "Calibri", 3.5, 0.46},
  [6] = {"Elefantes", "Impact", 2.5, 1.46},
  [7] = {"Fiestas", "Alanis  Hand", 1.5, 1.9},
  [8] = {"Gatoman", "Jasmine UPC", 0.5, 2.34},
  [9] = {"Hipopotamos en su habitat", "Latha", 0.5, 2.78},
  [10] = {"Italia, un nuevo mundo", "Kaiti", 1.5, 3.22},
  [11] = {"Juanacatlan", "Nyala", 2.5, 3.66},
  [12] = {"Kids, where are them?", "Verdana", 3.5, 4.1},
  [13] = {"La niña", "Tahoma", 4.5, 4.54},
  [14] = {"Metafisica", "Modern", 5.5, 4.98},
  [15] = {"Nuevos horizontes", "Univers", 6.5, 5.42},
  [16] = {"Osos Polares", "Yu Gotic", 7.5, 5.86},
  [17] = {"Pato Hood", "Ravie", 8.5, 6.3},
  [18] = {"Poblaciones vulnerables", "OCRB", 9.5, 6.75},
  [19] = {"Quo duo", "Selawik", 10.5, 7.18},
  [20] = {"Robin Hood", "Perpetua", 11.5, 7.62},
  [21] = {"Significado de la vida", "Times", 12.5, 8.06},
  [22] = {"Soberanos", "Webdings", 13.5, 8.5},
  [23] = {"Trasatlantico", "Sweer Pea", 14.5, 8.94},
  [24] = {"Transportes en el futuro", "Bell MT", 15.5, 9.38},
  [25] = {"Trotamundos", "Ebrima", 16.5, 9.82},
  [26] = {"Uvas para el vino", "Mangal", 17.5, 10.26},
  [27] = {"Verduras y frutas", "Cambria", 18.5, 10.7},
  [28] = {"Viajando ando", "Dotum", 19.5, 11.14},
  [29] = {"Walter Cross, ¿Quien fue?", "Papyrus", 20.5, 11.58},
  [30] = {"Xcaret, un lugar magico", "Arial Black", 21.5, 12.02},
  [31] = {"Yardas", "Georgia", 22.5, 12.46},
  [32] = {"Zapato Viejo", "French Script",23.5, 12.9},
};

void alto(int tam, Libro database[], int op){
    if (op == 1)
    {
        for (int i = 0; i < tam; i++)
        {
            for (int j = i+1; i < tam; i++)
            {
                if (database[j].alto < database[i].alto)
                {
                    Libro lib = database[i];
                    database[i] = database[i];
                    database[j] = lib;
                }
                
            }
            
        }
        
    }else
    {
        for (int i = 0; i < tam; i++)
        {
            for (int j = i+1; i < tam; i++)
            {
                if (database[j].alto > database[i].alto)
                {
                    Libro lib = database[i];
                    database[i] = database[i];
                    database[j] = lib;
                }
                
            }
            
        }
    }
    
    
}

void titulo(int tam, Libro database[], int op){
    if (op == 1)
    {
        for (int i = 0; i < tam; i++)
        {
            for (int j = i+1; i < tam; i++)
            {
                if (database[j].titulo[0] < database[i].titulo[0])
                {
                    Libro lib = database[i];
                    database[j] = lib;
                }
                
            }
            
        }
        
    }else
    {
        for (int i = 0; i < tam; i++)
        {
            for (int j = i+1; i < tam; i++)
            {
                if (database[j].titulo[0] > database[i].titulo[0])
                {
                    Libro lib = database[i];
                    database[j] = lib;
                }
                
            }
            
        }
    }
    
    
}

void Anch(int tam, Libro bd[], int op){
    if (op == 1)
    {
        for (int i = 0; i < tam; i++)
        {
            for (int j = i+1; i < tam; i++)
            {
                if (database[j].ancho < database[i].ancho)
                {
                    Libro lib = database[i];
                    database[j] = lib;
                }
                
            }
            
        }
        
    }else
    {
        for (int i = 0; i < tam; i++)
        {
            for (int j = i+1; i < tam; i++)
            {
                if (database[j].ancho > database[i].ancho)
                {
                    Libro lib = database[i];
                    database[j] = lib;
                }
                
            }
            
        }
    }
}

void fuente(int tam, Libro bd[], int op){
    if (op == 1)
    {
        for (int i = 0; i < tam; i++)
        {
            for (int j = i+1; i < tam; i++)
            {
                if (database[j].tFuente[0] < database[i].tFuente[0])
                {
                    Libro lib = database[i];
                    database[j] = lib;
                }
                
            }
            
        }
        
    }else
    {
        for (int i = 0; i < tam; i++)
        {
            for (int j = i+1; i < tam; i++)
            {
                if (database[j].tFuente[0] > database[i].tFuente[0])
                {
                    Libro lib = database[i];
                    database[j] = lib;
                }
                
            }
            
        }
    }
}

void imprimirTDA(int tam, Libro database[]){
  for(int i=0; i<tam; i++){
    printf("%s --- %s --- %f --- %f \n",database[i].titulo, database[i].tFuente, database[i].alto, database[i].ancho);
  }
}

int main (){

    int option = 0;
    while (option != 5)
    {
        printf("Elija la opcion para ordenar\n");
        printf("1. Alto\n");
        printf("2. Ancho\n");
        printf("3. Titulo\n");
        printf("4. Fuente\n");
        printf("5. Salir\n");
        scanf("%d",&option);
        int op= 0;
        switch (option)
        {
            case 1:
                printf("Ordenar por altura \n");
                printf("1. Ascendente \n");
                printf("2. Descendente \n");
                scanf("%d", &op);
                alto(32, database, op);
                imprimirTDA(32, database);
            break;
            case 2:
                printf("Ordenar por ancho \n");
                printf("1. Ascendente \n");
                printf("2. Descendente \n");
                scanf("%d", &op);
                Anch(32, database, op);
                imprimirTDA(32, database);
            break;
            case 3:
                printf("Ordenar por titulo \n");
                printf("1. Ascendente \n");
                printf("2. Descendente \n");
                scanf("%d", &op);
                titulo(32, database, op);
                imprimirTDA(32, database);
            break;
            case 4:
                printf("Ordenar por fuente \n");
                printf("1. Ascendente \n");
                printf("2. Descendente \n");
                scanf("%d", &op);
                fuente(32, database, op);
                imprimirTDA(32, database);
            break;
        
            default:
            break;
        }

    }
    
    return 0 ;
}

