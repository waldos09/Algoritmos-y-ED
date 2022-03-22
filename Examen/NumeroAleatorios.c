
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int arreglo[10], numgen;

    srand(time(NULL));
    for(int i=0;i<10;i++){
        numgen=10+rand()%(30+1-10);
        /*Para generar un número pseudoaleatorio se requiere la función rand
        la fórmula sería la siguiente:
        limite Inferior + rand() % (limite superior + 1 - limite inferior) */
        arreglo[i]=numgen;
        printf("%d ",arreglo[i]);
    }
    return 0;
}