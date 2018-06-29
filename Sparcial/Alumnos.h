#ifndef Alumnos_H_INCLUDED
#define Alumnos_H_INCLUDED
#include "ArrayList.h"
typedef struct{
    int edad;
    int legajo;
    char nombre[10];
    int sexo;
} eAlumno;
void creaArchivo();
int leeArchivo(ArrayList*);
int alta(ArrayList*,ArrayList*);

eAlumno* new_eAlumno(eAlumno*);

void listaUno(eAlumno*this);
void informeAtendidos(ArrayList*this,ArrayList*this2);
int comparacionedad(void* this,void* this2);
void imprimirxEdad(ArrayList*);
void imprimirTodo(ArrayList*this);
int Masde30(void* this);
void nuevo_archivo(ArrayList*);
#endif // TRAMITE_H_INCLUDED
