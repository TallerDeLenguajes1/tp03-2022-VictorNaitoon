#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define CANTIDADCLIENTES 5
#define CANTIDADPRODUCTOS 10

char *TiposProductos[] = {"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct Producto {
    int productoID; 
    int cantidadDeProductos;
    char *tipoProducto;
    float precioUnitario;
}PRODUCTO;

typedef struct Cliente {
    int clienteID;
    char *nombreCliente;
    int cantidadProductosAPedir;
    PRODUCTO *productos;
}CLIENTE;

void cargarClientes(CLIENTE *punteroACliente, int numeroDeClientes);
void mostrarClientes(CLIENTE *punteroACliente, int numeroDeClientes);
void cargarProductos(PRODUCTO *punteroAProductos, int cantidadDeProductos);
void mostrarProductos(PRODUCTO *punteroAProductos, int cantidadDeProductos);
float precioTotal(int cantidadDeProductos, float precioDelProducto);

int main(){

    srand(time(NULL));

    int cantidadClientes;
    CLIENTE *punteroCliente;
    do
    {
        printf("Ingrese la cantidad de clientes: ");
        scanf("%d",&cantidadClientes);
    } while (cantidadClientes < 1 || cantidadClientes > CANTIDADCLIENTES);

    fflush(stdin);

    punteroCliente = (CLIENTE *)malloc(cantidadClientes*sizeof(CLIENTE));
    
    cargarClientes(punteroCliente, cantidadClientes);
    mostrarClientes(punteroCliente, cantidadClientes);

    getchar();
    return 0;
}

void cargarClientes(CLIENTE* punteroACliente, int numeroDeClientes){
    int numeroRandom;
    for (int i = 0; i < numeroDeClientes; i++){
        punteroACliente[i].clienteID = i + 2;
        punteroACliente[i].nombreCliente = (char *)malloc(punteroACliente[i].cantidadProductosAPedir*sizeof(CLIENTE));
        numeroRandom = rand()%3;
        switch (numeroRandom){
        case 0:
            strcpy(punteroACliente[i].nombreCliente,"Victor");
            break;
        case 1:
            strcpy(punteroACliente[i].nombreCliente,"Agustina");
            break;
        case 2:
            strcpy(punteroACliente[i].nombreCliente,"Pepito");
            break;
        }
        punteroACliente[i].cantidadProductosAPedir = rand() % 6 + 1;
        punteroACliente[i].productos = (PRODUCTO*)malloc(sizeof(PRODUCTO)*punteroACliente[i].cantidadProductosAPedir);
        cargarProductos(punteroACliente[i].productos, punteroACliente[i].cantidadProductosAPedir);
    }   
}

void cargarProductos(PRODUCTO *punteroAProductos, int cantidadDeProductos){
    for (int i = 0; i < cantidadDeProductos; i++){
        punteroAProductos[i].productoID = i + 1;
        punteroAProductos[i].cantidadDeProductos = rand() % 11 + 1;
        punteroAProductos[i].tipoProducto = TiposProductos[rand()%5];
        punteroAProductos[i].precioUnitario = rand() % 1000 + 1;
    }
}

float precioTotal(int cantidadDeProductos, float precioDelProducto){
    float total;
    total = cantidadDeProductos * precioDelProducto;
    return total;
}

void mostrarClientes(CLIENTE *punteroACliente, int numeroDeClientes){
    for (int i = 0; i < numeroDeClientes; i++){
        printf("------ Cliente nro %d ------",i+1);
        printf("\nID del cliente: %d",punteroACliente[i].clienteID);
        printf("\nNombre del cliente: %s",punteroACliente[i].nombreCliente);
        printf("\nCantidad de productos que encargo el cliente: %d",punteroACliente[i].cantidadProductosAPedir);
        mostrarProductos(punteroACliente[i].productos, punteroACliente[i].cantidadProductosAPedir);
    }
}

void mostrarProductos(PRODUCTO *punteroAProductos, int cantidadDeProductos){
    float total = 0;
    for (int i = 0; i < cantidadDeProductos; i++){
        printf("\n------ Producto nro %d ------",i+1);
        printf("\nID del producto: %d",punteroAProductos[i].productoID);
        printf("\nCantidad de producto encargado: %d",punteroAProductos[i].cantidadDeProductos);
        printf("\nTipo de producto que encargo el cliente: %s",punteroAProductos[i].tipoProducto);
        printf("\nPrecio del producto: %.2f",punteroAProductos[i].precioUnitario);
        total += precioTotal(punteroAProductos[i].cantidadDeProductos, punteroAProductos[i].precioUnitario);
    }
    printf("\n\nTotal a abonar: %.2f\n\n",total);
}