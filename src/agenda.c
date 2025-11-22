#include "agenda.h"
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTOS 100
#define LONG_NOMBRE 50
#define LONG_TEL 20
#define NOMBRE_ARCHIVO "agenda.txt"

typedef struct{
char nombre[LONG_NOMBRE];
char telefono[LONG_TEL];
}Contacto;
Contacto agenda[MAX_CONTACTOS];
int numContactos=0;

void cargarContactos();
void guardarContactos();
void agregarContactos();
void mostrarContactos();
void ordenarContactos();
void buscarContactos();
void crearContactos();
void limpiarBuffer();

int main(){
int opcion;
cargar contactos();
if (numContactos==0){
crearDatosPrueba();
}
do{
printf("\n Agenda telefonica\n");
printf("1.Agregar contacto\n");
printf("2.Mostrar todos los contactos\n");
printf("3.Ordenar alfabeticamente\n");
printf("4.Buscar contacto\n");
printf("5.Salir\n");
printf("\n");
scanf("\n10");
limpiarBuffer();
inputs
switch(opcion){}
case 1:
    agregarContacto();
    break;
    
/**
*Esta función se encarga de iniciar el número de contactos a cero
*/
void iniciar_agenda(Agenda *agenda){

}



// Varible que lleva la cuenta de cuantos contactos hay en la agenda
int num_contactos;

/**
 * Esta función sirve para agregar un contacto nuevo en la agenda
 */
void agregar_contacto(Agenda *agenda, Contacto c){

}


/**
 * Esta función sirve para buscar un contacto por nombre en la agenda y retorna la posición del contacto si exisite
 * En caso contrario retorna -1
 */
int buscar_contacto(Agenda *agenda, char *nombre){

}


/**
 * Esta función  sirve para buscar un contacto por su número de telefono en la agenda
 */
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]){

}


/**
 * Esta función sirve para ordenar los contactos por nombres de forma ascendente
 */
void ordenar_contactos(Agenda *a){
    int i, j;
    Contacto temp;
    for(i = 0; i < a->num_contactos; i++){
        for(j=0; j < a->num_contactos-i-1; j++){
            if(strcmp(a->contactos[j].nombre, a->contactos[j+1].nombre)>0){
                temp = a->contactos[j];
                a->contactos[j] = a->contactos[j+1];
                a->contactos[j+1] = temp;
            }
        }
    }
}

/**
 * Esta función sirve para ordenar los contactos por nombres de forma descendente
 */
void ordenar_contactos_inv(Agenda *a){
    int i, j;
    Contacto temp;
    for(i = 0; i < a->num_contactos; i++){
        for(j=0; j < a->num_contactos-i-1; j++){
            //Completar basandose en la función anterior
        }
    }
}


/**
 * Función auxiliar para imprimir un contacto
 */
void mostrar_contacto(Contacto){

}


/**
 * Función auxiliar para leer un contacto
 */
void leer_contacto(Contacto *c){

}

/**
 * Función que imprime todos los contactos de la agenda en pantalla
 */
void imprimir_agenda(Agenda agenda){

}

/**
 * Función que sirve para cargar contactos escritos en un archivo a la agenda
 */
void cargar_contactos(char *filename, Agenda *agenda){

}


/**
 * Función que sirve para guardar todos los contactos de la agenda en un archivo
 */
void guardar_contactos(char *filename, Agenda agenda){

}
