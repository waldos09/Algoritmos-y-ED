/*Carmona Bartolome Aldo Armando*/
#include <stdio.h>
#include <math.h>
#include <malloc.h>

int cant = 1500;
int array[1500];
int array2[7000];
//int *array= malloc(sizeof(array));
float k=11, p=2;
int n=0;
float xo = 23;
float xo2 = 83;
int main(){
    n = (int)(pow(2,64)-1);
    int xn1 = (int)(pow(k,p)*(pow(xo,11)+pow(xo,2)+1))%n;
    for (int i = 0; i < cant; i++)
    {
        xn1=(int)(pow(k,p)*(pow(xn1,11)+pow(xn1,2)+1))%n;
        array[i] = abs(xn1);
    }
    for (int i = 0; i < cant; i++)
    {
        printf("%d - " ,array[i]);
    }
    printf("\n---------------------------\n");
    int xn12 = (int)(pow(k,p)*(pow(xo2,11)+pow(xo2,2)+1))%n;
    for (int i = 0; i < 7000; i++)
    {
        xn12=(int)(pow(k,p)*(pow(xn12,11)+pow(xn12,2)+1))%n;
        array2[i] = abs(xn12);
    }
    for (int i = 0; i < cant; i++)
    {
        printf("%d - " ,array2[i]);
    }
    
    return 0;
}

