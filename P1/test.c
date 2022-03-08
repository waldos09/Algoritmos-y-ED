#include <stdio.h>
#define tam 1
struct nivel{
    char mapa[20]; //ob 1
    char dificultad[20]; //ob 2
    char boss[20]; //ob 3
};

struct personaje{
    int lvl; // ob 4
    char tipo[10]; // ob 5
    char name[10]; // ob 6
};

struct juego{
    struct personaje p1; // ob 7
    struct nivel n1; // ob 8
    char nombre[20]; // ob 9
};

void alta(struct juego *);
void consulta(struct juego *);
void baja(struct juego *);
void copiar(struct juego *);

int main(){

    struct juego arr[tam]; // ob 10
    printf("---------------ALTA DE DATOS---------------\n");
    alta(arr);
    printf("---------------CONSULTA---------------\n");
    consulta(arr);
    printf("---------------COPIAR---------------\n");
    copiar(arr);
    printf("---------------BAJA---------------\n");
    baja(arr);
    printf("---------------CONSUTLAR DATOS BORRADOS---------------\n");
    consulta(arr);
    return 0;
}

void alta(struct juego arr[tam]){
    int i; // ob 11
    for ( i = 0; i < tam; i++){ // ob 13
        struct juego game; // ob 14
        printf("---Juego %d---\n",i+1); // ob 15
        printf("Ingresa el Nombre: ");
        setbuf(stdin,NULL); // ob 16
        scanf("%s", game.nombre); // ob 17
        printf("---Nivel de %s---\n",game.nombre); // ob 18
        printf("Ingresa el mapa: \n");
        setbuf(stdin,NULL); // ob 19
        scanf("%s", game.n1.mapa); // ob 20
        printf("Ingresa la dificultad: \n");
        setbuf(stdin,NULL); // ob 21
        scanf("%s", game.n1.dificultad); // ob 21
        printf("Ingresa el boss: ");
        setbuf(stdin,NULL); // ob 22
        scanf("%s", game.n1.boss); // ob 23
        printf("---Personaje de %s---\n",game.nombre); // ob 24
        printf("Ingresa el nombre del personaje: ");
        setbuf(stdin,NULL); // ob  25
        scanf("%s", game.p1.name); // ob 26
        printf("Ingresa el lvl: ");
        setbuf(stdin,NULL); // ob 27
        scanf("%d", &game.p1.lvl); // ob 28
        printf("Ingresa el tipo de personaje: ");
        setbuf(stdin,NULL); // ob 29
        scanf("%s", game.p1.tipo); // ob 30
        arr[i] = game;
    }
    
};

void baja(struct juego arr[tam]){
    int i; // ob 31
    for ( i = 0; i < tam; i++) // ob 33
    {
        struct juego game; // ob 34
        strcpy(arr[i].nombre,""); // ob 35
        strcpy(arr[i].n1.mapa,""); // ob 36
        strcpy(arr[i].n1.dificultad,""); // ob 37
        strcpy(arr[i].n1.boss,""); // ob 38
        strcpy(arr[i].p1.name,""); // ob 39
        strcpy(arr[i].p1.tipo,""); // ob 40
        arr[i].p1.lvl = NULL; // ob 41
    }
    
};

void consulta(struct juego arr[tam]){

    int i; // ob 42
    printf("---Datos del juego---\n");
    for ( i = tam-1; i >= 0; i--) // ob 44
    {
        printf("---Juego %d---\n",i+1); // ob 45
        printf("Nombre: %s\n",arr[i].nombre); // ob 46
        printf("---Nivel---\n");
        printf("mapa: %s\n",arr[i].n1.mapa); // ob 47
        printf("dificultad: %s\n",arr[i].n1.dificultad); // ob 48
        printf("boss: %s\n",arr[i].n1.boss); // ob 49
        printf("---Personaje---\n");
        printf("nombre: %s\n",arr[i].p1.name); // ob 50
        printf("tipo: %s\n",arr[i].p1.tipo); // ob 51
        printf("lvl: %d\n",arr[i].p1.lvl); // ob 52 
    }
    
};

void copiar(struct juego arr[tam]){
    int i; // ob 53
    struct juego arrcopy[tam]; // ob 54
    for ( i = 0; i < tam; i++) // ob 56
    {
        struct juego game; // ob 57
        strcpy(arrcopy[i].nombre, arr[i].nombre); // ob 58
        strcpy(arrcopy[i].n1.mapa, arr[i].n1.mapa); // ob 59
        strcpy(arrcopy[i].n1.dificultad, arr[i].n1.mapa); // ob 60
        strcpy(arrcopy[i].n1.boss, arr[i].n1.mapa); // ob 61
        strcpy(arrcopy[i].p1.name, arr[i].n1.mapa); // ob 62
        strcpy(arrcopy[i].p1.tipo, arr[i].n1.mapa); // ob 63
        arrcopy[i].p1.lvl = arr[i].p1.lvl; // ob 64
        printf("Nombre: %s\n",arrcopy[i].nombre); // ob 65
        printf("lvl: %d\n",arrcopy[i].p1.lvl); // ob 66
    }

};
//66n