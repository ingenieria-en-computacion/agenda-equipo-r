#include <stdio.h>
#include "agenda.h"

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int opcion;

    do {
        printf("\n AGENDA TELEFONICA\n");
        printf("1. Agregar contacto\n");
        printf("2. Mostrar agenda\n");
        printf("3. Buscar contacto por nombre\n");
        printf("4. Buscar contacto por numero de telefono\n");
        printf("5. Salir\n");
        printf("¿Qué quiere hacer hoy?: ");
        if (scanf("%d", &opcion) != 1) {
            printf("Entrada invalida.\n");
            return 1;
        }
        limpiarBuffer(); //Limpiamos para que no sobreescriba

        switch (opcion) {
            case 1:
                agregar_contacto();
                break;


            case 2:
            mostrar_agenda();
            break;


            case 3:
                buscarnom();
                break;

            case 4:
                buscarnum();
                break;

            case 5:
                printf("Saliste de tu agenda...\n");
                break;

            default:
                printf("Opcion no valida, intente de nuevo.\n");
        }

    } while (opcion != 5);

    return 0;
}
