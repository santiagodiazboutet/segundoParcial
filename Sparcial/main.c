#include <stdio.h>
#include <stdlib.h>
#include "Alumnos.h"
#include "ArrayList.h"
/*
1. Crear el archivo Alumnos.csv, que va a contener la informacion de 10 alumnos(nombre , edad, legajo, sexo), los cuales deben ser creados de
manera dinamica y almacenados en un ArrayList.
2.Listar los alumnos del ArrayList ordenados por edad.
*/
int main()
{
    int opcion=0;
    int retorno=0;
    ArrayList* Alumnos=NULL;
    ArrayList* AlumnosMas30=NULL;
    AlumnosMas30=al_newArrayList();
    Alumnos=al_newArrayList();
    if (Alumnos!=NULL)
    {
        while(opcion!=6)
        {   system("cls");
            printf("\t MENU\n1.Crear archivo\n2.Leer archivo alumno.csv y guardar\n3.Listar ordenados por edad\n4.Listar sin ordenar\n5.Crear lista mayores 30\n6.Crear archivo mayores 30\n");
            scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:

               creaArchivo();

                break;
           case 2:

                retorno=leeArchivo(Alumnos);
                break;
           case 3:

                imprimirxEdad(Alumnos);
                break;

            case 4:
                imprimirTodo(Alumnos);

                break;
            case 5:
                AlumnosMas30=al_filter(Alumnos,Masde30);
                imprimirTodo(AlumnosMas30);
                break;
            case 6:
                nuevo_archivo(AlumnosMas30);
                break;

            }

        }
    }
    else
    {
        printf("Algo ha salido mal.");
    }





}
