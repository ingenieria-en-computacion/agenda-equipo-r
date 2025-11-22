#ifndef __AGENDA_H__
#define __AGENDA_H__

#define MAX_CONTACTOS 100

enum TipoTelefono {
    CASA,
    MOVIL,
    OFICINA,
    OTRO
};

enum Mes {
    ENERO, FEBRERO, MARZO, ABRIL,
    MAYO, JUNIO, JULIO, AGOSTO,
    SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE
};

struct Persona {
    char nombre[30];
    char apellido[30];
    enum Mes mes_nacimiento;
    int dia_nacimiento;
    char tipo_contacto[20];
    char telefono[20];
    enum TipoTelefono tipo_tel;
};

typedef struct Persona Contacto;

typedef struct Agenda {
    Contacto contactos[MAX_CONTACTOS];
    int num_contactos;
} Agenda;


void agregar_contacto();
void mostrar_agenda();
void ordenalfa();
void buscarnom();
void buscarnum();
void ponernum();
void quitar_numeros();


#endif // __AGENDA_H__

