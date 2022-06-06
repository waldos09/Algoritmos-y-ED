#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_MAX 1000
#define CODEMAX 80
void codifica(char *caracteres, char **codigos, int total, char *texto)
{
    int indice = 0;
    int error = 0;
    int aux = 0;
    char archivo[50];
    char opc[NUM_MAX];
    FILE *f;
    char cadena[NUM_MAX][NUM_MAX];
    while (texto[aux] != '\0')
    {
        for (indice = 0; indice < total; indice++)
        {
            if (caracteres[indice] == texto[aux])
            {
                strcpy(cadena[aux], codigos[indice]);
                aux += 1;
                break;
            }
        }
        if (indice == total)
        {
            error = 1;
            break;
        }
    }
    cadena[aux][0] = '\0';
    aux = 0;
    if (error == 1)
    {
        if (cadena[0][0] == '\0')
            printf("Error: El texto introducido no es parte del codigo introducido\n");
    }
    else
    {
        printf("El texto codificado es:");
        while (cadena[aux][0] != '\0')
        {
            printf("%s", cadena[aux]);
            aux += 1;
        }
        printf("\n");
    }
    if (error != 1)
    {
        printf("¿Quieres guardar el texto codificado (S/N)?:");
        scanf("%s", opc);
        while (opc[0] != 'S' && opc[0] != 'N')
        {
            printf("Opcion no valida\n");
            printf("Elija su opcion (S/N):");
            scanf("%s", opc);
        }
        if (opc[0] == 'S')
        {
            printf("Introduzca el nombre de archivo con su extension:");
            scanf("%s", &archivo);
            f = fopen(archivo, "w+");
            aux = 0;
            while (cadena[aux][0] != '\0')
            {
                fprintf(f, "%s", cadena[aux]);
                aux += 1;
            }
            fclose(f);
            printf("Archivo creado: %s\n", archivo);
        }
    }
}

void decodifica(char *caracteres, char **codigos, int total, char *texto)
{
    char decod[NUM_MAX];
    char decoder = 'A';
    int indicedecod = 0;
    int cambio = 0;
    int indice = 0;
    int indicetotal = 0;
    int aux;
    int error = 0;
    char cadena[NUM_MAX];
    char archivo[50];
    char opc[NUM_MAX];
    FILE *f;
    while (decoder != '\0')
    {
        decoder = texto[indicetotal];
        if (decoder == '\0')
        {
            texto[indicetotal] = '\0';
            break;
        }
        cadena[indice] = decoder;
        cadena[indice + 1] = '\0';

        for (aux = 0; aux < total; aux++)
        {
            if (strcmp(cadena, codigos[aux]) == 0)

            {
                decod[indicedecod] = caracteres[aux];
                indicedecod += 1;
                cambio = 1;
                break;
            }
        }

        if (cambio == 1)
        {
            indice = 0;
            cambio = 0;
        }
        else
        {
            indice += 1;
        }
        indicetotal += 1;
    }
    if (indice != 0)
    {
        decod[indicedecod] = '\0';
        if (decod[0] == '\0')
        {
            printf("Error: El texto introducido no es parte del codigo introducido\n");
            error = 1;
        }
        else
        {
            printf("El texto introducido contiene errores, la parte que se pudo traducir dice:\n%s\nFavor de verificarlo bien\n", decod);
        }
    }
    else
    {
        decod[indicedecod] = '\0';
        printf("El texto decodificado es:\n%s\n", decod);
    }
    if (error != 1)
    {
        printf("¿Quieres guardar el texto decodificado (S/N)?:");
        scanf("%s", opc);
        while (opc[0] != 'S' && opc[0] != 'N')
        {
            printf("Opcion no valida\n");
            printf("Elija su opcion (S/N):");
            scanf("%s", opc);
        }
        if (opc[0] == 'S')
        {
            printf("Introduzca el nombre de archivo para guardar:");
            scanf("%s", &archivo);
            f = fopen(archivo, "w+");
            fprintf(f, "%s", decod);
            fclose(f);
            printf("Archivo creado: %s\n", archivo);
        }
    }
}


int main(int argc, char *argv[])
{
    int opc;
    int total;
    int total2;
    int tam = 0;
    int aux = 0, aux2 = 0;
    int ultimo = 0;
    int s = 0;
    int yaexiste = 0;
    int codigo_agregado = 0;
    char *caracteres;
    char **codigos;
    char archivo[50];
    char cadena[NUM_MAX];
    char opcG[NUM_MAX];
    FILE *f, *p;
    aux = 0;
    printf("Introduzca el nombre de archivo de la tabla de codificacion: ");
    scanf("%s", &archivo);
    p = fopen(archivo, "r");
    if (p == NULL)
    {
        printf("\nError al abrir el archivo \n\n");
    }
    else if (yaexiste == 1)
    {
        if (ultimo == 1)
        {
            for (aux = 0; aux < total; aux++)
            {
                free(codigos[aux]);
            }
            free(codigos);
            free(caracteres);
        }
        if (ultimo == 2)
        {
            for (aux = 0; aux < total2; aux++)
            {
                free(codigos[aux]);
            }
            free(codigos);
            free(caracteres);
        }
    }
    fgets(cadena, NUM_MAX, p);
    total2 = atoi(cadena);
    caracteres = (char *)malloc(total2 * sizeof(char));
    codigos = (char **)malloc(total2 * sizeof(char *));
    for (aux = 0; aux < total2; aux++)
    {
        codigos[aux] = (char *)malloc(CODEMAX * sizeof(char));
    }
    aux = 0;
    aux2 = 0;
    s = 0;
    while (!feof(p))
    {
        if (s == 0)
        {
            fgets(cadena, NUM_MAX, p);
            caracteres[aux] = cadena[0];
            s = 1;
        }
        else
        {
            fgets(cadena, NUM_MAX, p);
            while (cadena[aux2] != '\0')
            {
                aux2 += 1;
            }
            cadena[aux2 - 1] = '\0';
            aux2 = 0;
            strcpy(codigos[aux], cadena);
            s = 0;
            aux += 1;
        }
    }
    fclose(p);
    aux = 0;
    printf("(Letra | Codigo)\n");
    while (aux < total2)
    {
        printf("%c | %s\n", caracteres[aux], codigos[aux]);
        aux += 1;
    }
    while (1)
    {
        printf("1 Decodificacion de texto por archivo \n");
        printf("2 Codificacion de texto por archivo \n");
        printf("0 Salir\n");
        printf("Elija su opcion:");
        scanf("%d", &opc);

        switch (opc)
        {

        case 1:
            if (ultimo == 1)
            {
                tam = total;
            }
            else
            {
                tam = total2;
            }
            printf("Introduzca el nombre de archivo a decodificar: ");
            scanf("%s", &archivo);
            p = fopen(archivo, "r");
            if (p == NULL)
            {
                printf("\nError al abrir el archivo.");
            }
            else
            {
                fscanf(p, "%s", cadena);
                fclose(p);
                decodifica(caracteres, codigos, tam, cadena);
            }

            break;

        case 2:
            if (ultimo == 1)
            {
                tam = total;
            }
            else
            {
                tam = total2;
            }
            printf("Introduzca el nombre de archivo a codificar: ");
            scanf("%s", &archivo);
            p = fopen(archivo, "r");
            if (p == NULL)
            {
                printf("\nError al abrir el archivo.");
            }
            else
            {
                fscanf(p, "%s", cadena);
                fclose(p);
                codifica(caracteres, codigos, tam, cadena);
            }

            break;

        case 0:
            return 0;
        }
    }
}