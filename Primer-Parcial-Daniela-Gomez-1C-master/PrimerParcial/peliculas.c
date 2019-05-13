#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validaciones.h"
#include "peliculas.h"
#define CANTPELICULAS 1000
#define CANTACTORES 50
#define LIBRE 1
#define OCUPADO 0
// GENERO NUEVO ID AUTOMATICO A PARTIR DE 1000

static int generarIdNuevo()
{
    static int idPelicula = 999;
    idPelicula++;
    return idPelicula;
}



int initePeliculas(ePeliculas lista[], int tam)
{
    int i;
    int retorno = -1;

    for(i=0; i<tam; i++)
    {
        lista[i].isEmpty = LIBRE; //LIBRE DEFINIDO COMO ENTERO 1 OCUPADO DEFINIDO COMO ENTERO 0
        retorno = 0;
    }

    return retorno;
}

int buscarLugarLibre(ePeliculas lista[], int tam)
{
    int i;
    int retorno = -1;

    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty == LIBRE)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

int buscarExisteId(ePeliculas lista[], int tam, int id)
{
    int i;

    int retorno = -1;

    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty == OCUPADO && (lista[i].idPelicula== id))
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}



int anadirPeliculaaut(ePeliculas lista[], int tam, eGeneros listaG[],int tamG,eActores listaA[],int tamA)
{

    int hayLugar;
    int idAnterior;
    int retorno = -1;
    int dia;
    int mes;
    int anio;
    char titulo[71];
    char actor[71];
    char paisOrigen[71];
    int genero;


    hayLugar = buscarLugarLibre(lista,tam);

    if(hayLugar == -1)
    {
        printf("\nNo hay lugar!!");

    }
    else
    {

        //harcodearData(lista[i],CANTPELICULAS);
        idAnterior = generarIdNuevo(lista[hayLugar], tam);
        lista[hayLugar].idPelicula = idAnterior++;

        getValidString("Ingrese el titulo: ","Debe ser un nombre de solo letras", titulo);
        strcpy(lista[hayLugar].titulo,titulo);

        getValidString("Ingrese el actor: ", "Debe ser un apellido solo letras", actor);
        strcpy(lista[hayLugar].actor.nombre,actor);

        dia= getValidInt("\nIngrese el nueva fecha (1 a 31): ", "\nDebe ser un numero entero (0 a 50)",0,51);
        lista[hayLugar].fecha.dia = dia;
        mes = getValidInt("\nIngrese el nueva mes (1 a 12): ", "\nDebe ser un numero entero (0 a 50)",0,51);
        lista[hayLugar].fecha.mes= mes;

        anio = getValidInt("\nIngrese el nueva año (1900 a 2020): ", "\nDebe ser un numero entero (0 a......)",0,2020);
        lista[hayLugar].fecha.anio = anio;

        getValidString("\nIngrese el pais de Origen:","Error",paisOrigen);
        strcpy(lista[hayLugar].actor.paisOrigen,paisOrigen);


        lista[hayLugar].isEmpty = OCUPADO;

        retorno = 0;

    }

    return retorno;
}


int mostrarUnElemento(ePeliculas unElemento)
{
    printf("------------------------------------------------------------------------------------------------");
    printf("\nID: %d\tTITULO: %s\t\t ACTOR: %s \t PAIS %s \t FECHA DE ESTRENO: %d - %d -%d\n",unElemento.idPelicula,unElemento.titulo,unElemento.actor.nombre,unElemento.actor.paisOrigen, unElemento.generoPeli.descripcion, unElemento.fecha.dia,unElemento.fecha.mes, unElemento.fecha.anio);
    printf("\n---------------------------------------------------------------------------------------------");
    return 0;
}

int mostrarListaElementos(ePeliculas lista[], int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        if(lista[i].isEmpty==OCUPADO)
        {

             printf("ID: %d\tTITULO: %s\tACTOR: %s \tFECHA DE ESTRENO: %d - %d -%d\n",lista[i].idPelicula,lista[i].titulo,lista[i].actor.nombre,lista[i].fecha.dia,lista[i].fecha.mes,lista[i].fecha.anio);
        }

    }

    return 0;
}


int bajaElemento(ePeliculas lista[], int tam, int id)
{
    char respuesta;
    int existeId;
    int retorno = -1;

    id = getValidInt("\nIngrese el id a buscar\n", "\ndebe ingresar un nuero de id",1000,2000);
    existeId = buscarExisteId(lista,tam,id);


            if(existeId != -1)
            {
               mostrarUnElemento(lista[existeId]);
                respuesta = getChar("\nEsta seguro que desea eliminar el elemento?: (s/n)\n");

                if(respuesta == 's' || respuesta == 'S')
                {
                    lista[existeId].isEmpty = LIBRE;
                    retorno =  0;
                    printf("\nElemento eliminado!\n");
                }
                else
                {
                    printf("\nSe cancelo la baja\n");
                }

            }

            else
            { printf("\nEl id ingresado no existe\n");

            }

    return retorno;
}

//FUNCION PARA MODIFICAR LOS DATOS DE UN ELEMENTO

int modificarElemento(ePeliculas lista[], int tam, int id)
{
    char respuesta;
    int existeId;
    int retorno = -1;
    int opcionMenuModificar;
    char nuevoNombre[51];
    char nuevoApellido[51];
    int nuevoSector;

    //danielagomez

    id = getValidInt("\nIngrese el id a modificar\n", "\ndebe ingresar un numero de id",1000,2000);
    existeId = buscarExisteId(lista,tam,id);


            if(existeId != -1 && lista[existeId].isEmpty != LIBRE)
            {
                mostrarUnElemento(lista[existeId]);
                respuesta = getChar("\nEsta seguro que desea modificar el elemento: (s/n)\n");

                if(respuesta == 's' || respuesta == 'S')
                {
                    printf("\t\t\t\tSUBMENU DE MODIFICACIONES");

                    do
                    {
                        opcionMenuModificar = mostrarMenu("\nDigite una opcion:\n1-Modificar titulo: \n2-Modificar actor: \n3-Modificar fecha: \n4-Modificar genero\n5-Salir del Submenu","Debe ingresar un numero",0,6);

                        switch(opcionMenuModificar)
                        {
                            case 1:
                                getValidString("\nIngrese el nuevo titulo: ","\nDebe contener solo letras\n",nuevoNombre);
                                strcpy(lista[existeId].titulo, nuevoNombre);
                                break;
                            case 2:
                                getValidString("\nIngrese el nuevo actor: ","\nDebe contener solo letras", nuevoApellido);
                                strcpy(lista[existeId].actor.nombre , nuevoApellido);
                                break;
                            case 3:
                                nuevoSector = getValidInt("\nIngrese el nueva fecha: ", "\nDebe ser un numero entero (0 a 50)",1900,2019);
                                lista[existeId].fecha.dia = nuevoSector;
                                nuevoSector = getValidInt("\nIngrese el nueva mes: ", "\nDebe ser un numero entero (0 a 50)",1900,2019);
                                lista[existeId].fecha.mes= nuevoSector;

                                nuevoSector = getValidInt("\nIngrese el nueva año: ", "\nDebe ser un numero entero (0 a 50)",1900,2019);
                                lista[existeId].fecha.anio = nuevoSector;
                                break;
                            case 4:

                                printf("\nVolviendo al menu principal...\n");

                                break;


                        }

                    }while(opcionMenuModificar != 4);

                    retorno = 0;
                }

                else
                {
                    printf("Se cancelo la modificacion!");
                }

            }

            else
            {
                printf("\nEl id ingresado no existe\n");

            }

            return retorno;
}

int harcodearData(ePeliculas lista[] ,int tam)
{

    int i;
    char titulo[][50]= {"Avengers EndGame","Thor","Cellular","Men in Black", "4IronMan","13  Going on 30","Lucy","Nace una estrella","¿Dime con cuantos?","Guardianes de la galaxia","A perfect murder","La isla","Que paso ayer","Home Alone" ,"3Deadpool","Sherlock Holmes","Men in Black 3","Avengers infinity" ,"warGrandes esperanzas","SWAT","XxX"};

    char actor[][50] = {"Scarlett Johansson","Rober Downey Jr","Mark Ruffalo","Chris Evans"	,"Chris Hemsworth	","Samuel Jackson"	,"Gwyneth Paltrow	","Paul Rudd"	,"Bradley Cooper"	,"Josh Brolin"};
    char pais[][50] = {"Argentina","EEUU","Canada","EEUU","Argentina","EEUU","Canada","Argentina","EEUU","Canada"};
    int idGenero;
    int genero[]= {1,1,1,1,1,4,1,4,4,1,3,3,2,2,1,1,1,1,4,1,1};


    for(i=0;i<tam;i++)
    {

        strcpy(lista[i].titulo,titulo[i]);
        strcpy(lista[i].actor.nombre,actor[i]);
        strcpy(lista[i].actor.paisOrigen,pais[i]);

        lista[i].isEmpty = OCUPADO;

    }

 return 0;

}

