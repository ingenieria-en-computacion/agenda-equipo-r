#include "agenda.h"
#include <stdio.h>
#include <string.h>

#define MAX_LINEAS 200
#define MAX_TEXTO 256

// Este lo agregamos después de ver el error de sobreescritura
void quitar_numeros() {
    FILE *f = fopen("dataagenda.txt", "r");
    if (!f) return;

    char lineas[MAX_LINEAS][MAX_TEXTO];
    int total = 0;

    while (fgets(lineas[total], MAX_TEXTO, f)) {
        lineas[total][strcspn(lineas[total], "\n")] = 0;

        int numero;
        char datos[MAX_TEXTO];

        if (sscanf(lineas[total], "%d. %[^\n]", &numero, datos) == 2) {
            strcpy(lineas[total], datos);
        }

        total++;
        if (total >= MAX_LINEAS) break;
    }
    fclose(f);

    f = fopen("dataagenda.txt", "w");
    if (!f) return;

    for (int i = 0; i < total; i++) {
        fprintf(f, "%s\n", lineas[i]);
    }

    fclose(f);
}
//Esta función abre el archivo y agrega un contacto
void agregar_contacto() {
    FILE *agenda;

    char nombre[50];
    char apellido[50];
    char telefono[20];
    char tipo[20];
    char dia[5];
    char mes[5];

    printf("Ingrese el nombre: ");
    fgets(nombre, 50, stdin);
    nombre[strcspn(nombre, "\n")] = 0;

    printf("Ingrese apellido: ");
    fgets(apellido, 50, stdin);
    apellido[strcspn(apellido, "\n")] = 0;

    printf("Ingrese telefono: ");
    fgets(telefono, 20, stdin);
    telefono[strcspn(telefono, "\n")] = 0;

    printf("Ingrese dia de cumpleaños: ");
    fgets(dia, 5, stdin);
    dia[strcspn(dia, "\n")] = 0;

    printf("Ingrese mes de cumpleaños (numero de mes): ");
    fgets(mes, 5, stdin);
    mes[strcspn(mes, "\n")] = 0;

    printf("Tipo de telefono (movil/casa/trabajo): ");
    fgets(tipo, 20, stdin);
    tipo[strcspn(tipo, "\n")] = 0;

    
    quitar_numeros();


    agenda = fopen("dataagenda.txt", "a");
    if (!agenda) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    fprintf(agenda, "%s %s %s %s %s %s\n",
            nombre, apellido, telefono, dia, mes, tipo);

    fclose(agenda);

    
    ordenalfa();


    ponernum();

    printf("Contacto guardado.\n");
}
//Esta funcion muestra el contenido del archivo
void mostrar_agenda() {
    FILE *agenda;
    char line[256];

    agenda = fopen("dataagenda.txt", "r");
    if (!agenda) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    printf("Toda tu agenda es esta:\n");

    while (fgets(line, sizeof(line), agenda)) {
        printf("%s", line);
    }

    fclose(agenda);
}
//Esta función ordena en orden alfabético
void ordenalfa() {
    FILE *agenda;
    char contactos[MAX_LINEAS][MAX_TEXTO];
    int n = 0;

    agenda = fopen("dataagenda.txt", "r");
    if (!agenda) {
        printf("No se pudo abrir dataagenda.txt\n");
        return;
    }

    while (fgets(contactos[n], MAX_TEXTO, agenda)) {
        contactos[n][strcspn(contactos[n], "\n")] = 0;  // Quitar salto de línea
        n++;
        if (n >= MAX_LINEAS) break;
    }
    fclose(agenda);

    // Ordenamiento Burbuja
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(contactos[j], contactos[j + 1]) > 0) {
                char temp[MAX_TEXTO];
                strcpy(temp, contactos[j]);
                strcpy(contactos[j], contactos[j + 1]);
                strcpy(contactos[j + 1], temp);
            }
        }
    }

    agenda = fopen("dataagenda.txt", "w");
    if (!agenda) {
        printf("No se pudo escribir en dataagenda.txt\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(agenda, "%s\n", contactos[i]);
    }

    fclose(agenda);
}
//Esta función enumera los contactos
void ponernum() {
    char lineas[MAX_LINEAS][MAX_TEXTO];
    int total = 0;

    FILE *f = fopen("dataagenda.txt", "r");
    if (!f) return;

    while (fgets(lineas[total], MAX_TEXTO, f)) {
        lineas[total][strcspn(lineas[total], "\n")] = 0;
        total++;
        if (total >= MAX_LINEAS) break;
    }
    fclose(f);

    f = fopen("dataagenda.txt", "w");
    if (!f) return;

    for (int i = 0; i < total; i++) {
        fprintf(f, "%d. %s\n", i + 1, lineas[i]);
    }

    fclose(f);
}
//Esta función busca por números
void buscarnum() {
    FILE *f;
    char linea[MAX_TEXTO];
    char telefonoBuscado[30];
    int numeroContacto;
    char datos[MAX_TEXTO];
    int encontrado = 0;

    printf("Número de teléfono a buscar: ");
    fgets(telefonoBuscado, sizeof(telefonoBuscado), stdin);
    telefonoBuscado[strcspn(telefonoBuscado, "\n")] = 0;

    f = fopen("dataagenda.txt", "r");
    if (!f) {
        printf("No se pudo abrir dataagenda.txt\n");
        return;
    }

    while (fgets(linea, sizeof(linea), f)) {
        if (sscanf(linea, "%d. %[^\n]", &numeroContacto, datos) == 2) {
            if (strstr(datos, telefonoBuscado) != NULL) {
                printf("Contacto #%d: %s\n", numeroContacto, datos);
                encontrado = 1;
            }
        }
    }

    fclose(f);

    if (!encontrado) {
        printf("No se encontró el teléfono: %s\n", telefonoBuscado);
    }
}

// Buscar por nombre y mostrar número de contactos y datos
void buscarnom() {
    FILE *f;
    char linea[MAX_TEXTO];
    char nombre[50];
    int num_linea;
    char datos[MAX_TEXTO];
    int encontrado = 0;

    printf("Nombre a buscar (tal cual lo registró): ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = 0;

    f = fopen("dataagenda.txt", "r");
    if (!f) {
        printf("No se pudo abrir dataagenda.txt\n");
        return;
    }

    while (fgets(linea, sizeof(linea), f)) {
        if (sscanf(linea, "%d. %[^\n]", &num_linea, datos) == 2) {
            if (strstr(datos, nombre) != NULL) {
                printf("Contacto #%d: %s\n", num_linea, datos);
                encontrado = 1;
            }
        }
    }

    fclose(f);

    if (!encontrado) {
        printf("No se encontraron contactos con el nombre: %s\n", nombre);
    }
}


