#include <stdio.h>
#include <time.h>
#define data 10 

int array[data];
int count = 0;
int main()
{
    //genrar 10k de no random
    srand((unsigned)time(NULL));
    printf("------------------------------------------------------------\n");
    printf("                    DATOS NO ORDENADOS\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < data; i++)
    {
        array[i] = (rand()%459565+0); // entre 459,565 y 0
        if ((array[i] %2) == 0) {
            count++;
        }
        printf("%d, ",array[i]);//imprime los 10k datos
    }
    //separar pares e impares
    printf("\n------------------------------------------------------------\n");
    printf("                    DATOS PARES\n");
    printf("------------------------------------------------------------\n");
    int par[count];
    printf("cant de pares: %d \n",count);
    for (int i = 0; i < data; i++){
        if (array[i] % 2 == 0){
            par[i] = array[i];
            printf("%d, ", par[i]);
        }       
    }
    printf("\n------------------------------------------------------------\n");
    printf("                    DATOS ORDENADOS PARES\n");
    printf("------------------------------------------------------------\n");
    slect(par, count);
    for (int i = 0; i < count; i++)
    {
        printf("%d, ",par[i]);
    }
    printf("\n------------------------------------------------------------\n");
    printf("                    DATOS IMPARES\n");
    printf("------------------------------------------------------------\n");
    printf("cant de impares: %d \n", (data-count));
    int impar[count];
    for (int i = 0; i < data; i++){
        if (array[i] % 2 != 0){
            impar[i] = array[i];
            printf("%d, ", impar[i]);
        }       
    }
    printf("\n------------------------------------------------------------\n");
    printf("                    DATOS ORDENADOS IMPARES\n");
    printf("------------------------------------------------------------\n");
    insert(impar, (data-count));
    for (int i = 0; i < (data-count); i++)
    {
        printf("%d, ",impar[i]);
    }

    return 0;
}

//intercambiar los datos
void swap(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;
}

void slect(int arr[],int tam){

    for (int i = 0; i < (tam-1); i++)
    {
        for (int j = i+1; j < tam; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(&arr[i],&arr[j]);
            }
            
        }
        
    }
    
}

void insert(int arr2[], int tam2){

    int pos, aux, i;
    for ( i = 0; i < tam2; i++){
        pos = i;
        aux = arr2[i];
        while ((pos>0) && (aux < arr2[pos-1])){
            arr2[pos] = arr2[pos-1];
            pos--;
        }
        arr2[pos] = aux;
    }
    
}

