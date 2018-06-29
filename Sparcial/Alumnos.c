#include <stdio.h>
#include <stdlib.h>
#include "Alumnos.h"
#include "ArrayList.h"
#define HOMBRE 0
#define MUJER 1
eAlumno* new_eAlumno(eAlumno* this)
{

  this=(eAlumno*)malloc(sizeof(eAlumno));
  return this;
}
void creaArchivo()
{
    FILE * fp;
    eAlumno* Alumno;
    fp=fopen("Alumnos.csv","wb");
    char nombres[11][11]={"Juan","Facundo","Luis","Roberto","Mariano","Gonzalo","Santiago","Patricio","Mercedes","Marina"};
    int edad[11]={10,35,23,33,33,44,56,42,4,54};
    int sexo[11]={0,0,0,0,0,0,0,0,1,1};
    int legajo[11];
    for (int i =0;i<10;i++)
    {
        legajo[i]=i+1;
        Alumno= new_eAlumno(Alumno);
        Alumno->edad=edad[i];
        Alumno->sexo=sexo[i];
        Alumno->legajo=legajo[i];
        strcpy(Alumno->nombre,nombres[i]);
        fwrite(Alumno,sizeof(eAlumno),1,fp);
    }
    system("pause");
    fclose(fp);


}
int leeArchivo(ArrayList* this)
{
    FILE * fp;
    eAlumno* Alumno;
    fp = fopen("Alumnos.csv", "rb");
    fseek(fp,0,SEEK_END);
    int  end=ftell(fp);
    fseek(fp,0,SEEK_SET);
    if(fp!=NULL)
    {
        while(ftell(fp)<end)
        {

        Alumno=(eAlumno*)malloc(sizeof(eAlumno));
        fread(Alumno,sizeof(eAlumno),1,fp);
        al_add(this,Alumno);

        }

    }
    return 0;
}

/*int alta(void*this,void*this2)
{
    eAlumno * tramite=NULL;
    tramite=new_eAlumno(tramite);
    printf("Ingrese el legajo de edad:\n");
    scanf("%d",&(tramite->edad));
    tramite->legajo=proximoTurno(this,this2);
    printf("\nSu legajo de turno es %d\n",tramite->legajo);
    system("pause");
    if(this!=NULL&&tramite!=NULL)
    {
        al_add(this,tramite);
    }

}

int proximoTurno(void*this,void*this2)
{   int i;

    eAlumno * tramite;
    int aux=0;
    tramite=new_eAlumno(tramite);

    if(this!=NULL&&this2!=NULL)
    {   if (al_len(this)!=0||al_len(this2)!=0)
        {

            for (i=0;i<al_len(this2);i++)
            {
                tramite=al_get(this2,i);
                if(tramite->legajo > aux)
                {
                    aux=tramite->legajo;

                }

            }
            for (i=0;i<al_len(this);i++)
            {
                tramite=al_get(this,i);
                if(tramite->legajo > aux)
                {
                    aux=tramite->legajo;

                }

            }
        }
    }
    return aux+1;
}


int proximoCliente(void* regularesNoat,void*regularesAt,void*urgentesAt,void*urgentesNoat)
{

    eAlumno * tramite;
    int opcion=0;
    tramite=al_get(urgentesNoat,0);
    if(tramite==NULL)
    {
        tramite=al_get(regularesNoat,0);
        if(tramite==NULL)
        {
            printf("NO HAY CLIENTES");
            system("pause");
        }
        else
        {
           printf("El proximo cliente es el legajo: %d. edad: %d\nDesea Atenderlo?\1-Si\n2-No",tramite->legajo,tramite->edad);
        scanf("%d",&opcion);
        while(opcion!=1&&opcion!=2)
        {
            printf("El proximo cliente es el legajo: %d. edad: %d\nDesea Atenderlo?\1-Si\n2-No",tramite->legajo,tramite->edad);
            scanf("%d",&opcion);
        }
        if(opcion==1)
        {
        tramite=al_pop(regularesNoat,0);
        al_add(regularesAt,tramite);
        }
        }
    }
    else
    {
        printf("El proximo cliente es el legajo: %d. edad: %d\nDesea Atenderlo?\1-Si\n2-No",tramite->legajo,tramite->edad);
        scanf("%d",&opcion);
        while(opcion!=1&&opcion!=2)
        {
            printf("El proximo cliente es el legajo: %d. edad: %d\nDesea Atenderlo?\1-Si\n2-No",tramite->legajo,tramite->edad);
            scanf("%d",&opcion);
        }
        if(opcion==1)
        {
        tramite=al_pop(urgentesNoat,0);
        al_add(urgentesAt,tramite);
        }
    }

}



void listaAtender(void*this,void*this2)
{   eAlumno *tramite=NULL;
    int i;
    system("cls");
    if(al_len(this)>0)
    {
    printf("Clientes urgentes\n\n");
    for( i=0;i<al_len(this);i++)
    {
        tramite=al_get(this,i);
        listaUno(tramite);
    }
    }
    if(al_len(this2)!=0)
    {
    printf("\n\nClientes regulares\n\n");
    for( i=0;i<al_len(this2);i++)
    {
        tramite=al_get(this2,i);
        listaUno(tramite);
    }
    }
    printf("\n\n");

}
*/
void listaUno(eAlumno*this)
{
    printf("Legajo:%d   edad: %d Nombre:%s",this->legajo,this->edad,this->nombre);
    if(this->sexo==0)
    {
        printf("  Sexo:%s","Masculino\n");
    }else{

    printf("  Sexo:%s","Femenino\n");

    }

}
void imprimirxEdad(ArrayList*this)
{
    int i;
    i=al_sort(this,comparacionedad,1);
    printf("%d\n",i);
    eAlumno*Alumno;
    system("pause");
    system("cls");


    if(al_len(this)>0)
    {

        printf("ALUMNOS\n\n");
        for( i=0;i<al_len(this);i++)
        {
            Alumno=al_get(this,i);
            listaUno(Alumno);
        }
    }
    system("pause");
    printf("\n\n");



}
void imprimirTodo(ArrayList*this)
{
    int i;


    eAlumno*Alumno;

    system("cls");


    if(al_len(this)>0)
    {

        printf("ALUMNOS\n\n");
        for( i=0;i<al_len(this);i++)
        {
            Alumno=al_get(this,i);
            listaUno(Alumno);
        }
    }
    system("pause");
    printf("\n\n");



}
int comparacionedad(void* this,void* this2)
{
    eAlumno *Alumno1=(eAlumno*)this;
    eAlumno *Alumno2=(eAlumno*)this2;
    if(Alumno1->edad>Alumno2->edad)
    {
        return 1;
    }
    else if(Alumno1->edad<Alumno2->edad)
    {
        return -1;
    }

    return 0;


}

int Masde30(void* this)
{
    eAlumno *Alumno1=(eAlumno*)this;

    if(Alumno1->edad>30)
    {
        return 1;
    }

    return 0;


}

void nuevo_archivo(ArrayList *this)
{
    FILE * fp;
    eAlumno* Alumno;
    fp=fopen("out.csv","w");
    for (int i =0;i<al_len(this);i++)
    {   Alumno=(eAlumno*)al_get(this,i);

        fprintf(fp,"%s,%d,%d",Alumno->nombre ,Alumno->edad,Alumno->legajo);
        if(Alumno->sexo==1)
        {
            fprintf(fp,"Femenino\n");
        }
        else
        {
            fprintf(fp,"Masculino\n");
        }
    }
    system("pause");
    fclose(fp);


}
