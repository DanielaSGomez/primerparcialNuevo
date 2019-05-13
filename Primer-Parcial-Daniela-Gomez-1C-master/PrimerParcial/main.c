#include <stdio.h>
#include <stdlib.h>

#include "peliculas.h"
#include "validaciones.h"
#define CANTPELICULAS 1000
#define CANTACTORES 50

int main()
{
    ePeliculas listap[CANTPELICULAS];
    eGeneros listaG[5];
    eActores listaA[CANTACTORES];
    int flag = 0;
    int opcionMenu;
    char actor[50];
    char genero[50];
    char paisOrigen;
    char titulo[100];



    int idP;
   // char genero[50];
    initePeliculas(listap,CANTPELICULAS);
  //  harcodearData(listap,21);



    do{

        opcionMenu = mostrarMenu("Digite una opcion: \n1-ALTA PELICULAS \n2-MODIFICAR DATOS DE LA PELICULA \n3-BAJA PELICULA\n4-LISTAR\n5-SALIR","Error: opcion invalida",0,6);

        switch(opcionMenu)
        {
        case 1:
            anadirPeliculaaut(listap,CANTPELICULAS,listaG,5,listaA,CANTACTORES);
            flag = 1;
            break;
        case 2:
            if(flag == 0)
            {
                printf("debe ingresar un alta primero");
            }
            else
            {
                modificarElemento(listap, CANTPELICULAS, idP);
            }
            break;
        case 3:
             if(flag == 0)
            {
                printf("debe ingresar un alta primero");
            }
            else
            {
                 bajaElemento(listap, CANTPELICULAS, idP);
            }
            break;
        case 4:
            mostrarListaElementos(listap,CANTPELICULAS);
            break;
        case 5:
            break;
        default:
            printf("opcion invalida");
            break;


        }



    }while(opcionMenu != 5);

    system("pause");
    system("cls");

    return 0;
}
