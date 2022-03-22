/*Carmona Bartolome Aldo Armando*/
#include <stdio.h>
#define tam 1
struct material
{
    int radio;
    char nombreDelMaterial[20];
    char color[10];
};
struct marca
{
    char NombreMarca[20];
    char PaisOrigen[20];
};

struct Pelota
{
    struct material m1;
    struct marca mc1;

};

void alta(struct Pelota *);
void consulta(struct Pelota *);
void baja(struct Pelota *);
void copiar(struct Pelota *);

int main(){
    struct Pelota arr[tam];
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
    return 0 ;

}
void alta(struct Pelota arr[tam]){
    int i; // ob 11
    for ( i = 0; i < tam; i++){ // ob 13
        struct Pelota ball; // ob 14
        printf("---Matetial ---\n"); // ob 15
        printf("Ingresa el Color: ");
        setbuf(stdin,NULL);
        scanf("%s",ball.m1.color);
        printf("Ingresa el Nombre del Material: ");
        setbuf(stdin,NULL);
        scanf("%s",ball.m1.nombreDelMaterial);
        printf("Ingresa el : Radio");
        setbuf(stdin,NULL);
        scanf("%d",&ball.m1.radio);
        printf("---Marca ---\n");
        printf("Ingresa el Nombre de la marca \n");
        setbuf(stdin,NULL); // ob 19
        scanf("%s", ball.mc1.NombreMarca); // ob 20
        printf("Ingresa el Pais de Origen: \n");
        setbuf(stdin,NULL); // ob 21
        scanf("%s", ball.mc1.PaisOrigen); // ob 21
        arr[i] = ball;
    }
    
};

void baja(struct Pelota arr[tam]){
    int i; // ob 31
    for ( i = 0; i < tam; i++) // ob 33
    {
        struct Pelota ball; // ob 34
        strcpy(arr[i].m1.color,""); // ob 35
        strcpy(arr[i].m1.nombreDelMaterial,""); // ob 36
        strcpy(arr[i].mc1.NombreMarca,""); // ob 38
        strcpy(arr[i].mc1.PaisOrigen,""); // ob 39
        arr[i].m1.radio = NULL; // ob 41
    }
    
};

void consulta(struct Pelota arr[tam]){

    int i; // ob 42
    printf("---Datos del Pelota---\n");
    for ( i = tam-1; i >= 0; i--) // ob 44
    {
        printf("---Material---\n"); // ob 45
        printf("Color:\n",arr[i].m1.color); // ob 46
        printf("Nombre: %s\n",arr[i].m1.nombreDelMaterial); // ob 47
        printf("Radio: %d\n",arr[i].m1.radio); // ob 48
        printf("---Marca---\n");
        printf("Nombre: %s\n",arr[i].mc1.NombreMarca); // ob 49
        printf("Pais: %s\n",arr[i].mc1.PaisOrigen); // ob 50

    }
    
};

void copiar(struct Pelota arr[tam]){
    int i; // ob 53
    struct Pelota arrcopy[tam]; // ob 54
    for ( i = 0; i < tam; i++) // ob 56
    {
        struct Pelota game; // ob 57
        strcpy(arrcopy[i].m1.color, arr[i].m1.color); // ob 58
        strcpy(arrcopy[i].m1.nombreDelMaterial, arr[i].m1.nombreDelMaterial); // ob 59
        strcpy(arrcopy[i].mc1.PaisOrigen, arr[i].mc1.PaisOrigen); // ob 60
        arrcopy[i].m1.radio = arr[i].m1.radio; // ob 64
        printf("Nombre: %s\n",arrcopy[i].m1.nombreDelMaterial); // ob 65
        printf("radio: %d\n",arrcopy[i].m1.radio);
        printf("color: %s\n",arrcopy[i].m1.color);
        printf("Nombre: %s\n",arrcopy[i].mc1.NombreMarca); // ob 49
        printf("Pais: %s\n",arrcopy[i].mc1.PaisOrigen);
    }

};