#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

int main(){
    char *Vector[N], *punteroVector;

    punteroVector = (char *)malloc(100*sizeof(char));

    for (int i = 0; i < N; i++){
        printf("Ingrese el %d nombre: \n",i+1);
        gets(punteroVector);

        Vector[i]=(char *)malloc(strlen(punteroVector)+1*sizeof(char));
        strcpy(Vector[i],punteroVector);
    }

    for (int i = 0; i < N; i++){
        printf("\nEl %d nombre es: ",i+1);
        puts(Vector[i]);
        free(Vector[i]);
    }
    
    free(punteroVector);

    getchar();
    return 0;
}