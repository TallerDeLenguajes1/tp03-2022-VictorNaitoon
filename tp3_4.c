#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int cantidadDeNombre;
    char **nombres, *Buff;

    Buff = (char *)malloc(100*sizeof(char));

    printf("Ingrese la cantidad de nombres que desea agregar: \n");
    scanf("%d",&cantidadDeNombre);

    nombres = (char **)malloc(cantidadDeNombre*sizeof(char *));

    //Cargamos los nombres
    for (int i = 0; i < cantidadDeNombre; i++){
        printf("\nIngrese el (%d) nombre: ",i+1);
        fflush(stdin);
        gets(Buff);
        nombres[i] = (char *)malloc((strlen(Buff)+1)*sizeof(char));
        strcpy(nombres[i],Buff);
    }

    //Mostramos los nombres
    for (int i = 0; i < cantidadDeNombre; i++){
        printf("\nNombre (%d) : %s",i+1,nombres[i]);
        free(nombres[i]);
    }
    
    free(Buff);
    free(nombres);

    getchar();
    return 0;
}