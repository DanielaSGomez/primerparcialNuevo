#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

typedef struct {
    int dia, mes, anio;
}eFecha;

typedef struct {
    int id;
    char descripcion[70];
}eGeneros;


typedef struct{
    int idActor;
    char nombre[71];
    char paisOrigen[71];
    int isEmpty;
}eActores;

typedef struct
{
    int idPelicula;
    char titulo[70];
    eFecha fecha;
    eGeneros generoPeli;
    eActores actor;

    int isEmpty;

}ePeliculas;

int initePeliculas(ePeliculas lista[], int tam);
int buscarLugarLibre(ePeliculas lista[], int tam);
int buscarExisteId(ePeliculas lista[], int tam, int id);
int anadirPeliculaaut(ePeliculas[], int tam, eGeneros[],int tamG,eActores[],int tamA);
int mostrarUnElemento(ePeliculas unElemento);
int mostrarListaElementos(ePeliculas lista[], int tam);
int modificarElemento(ePeliculas lista[], int tam, int id);
int bajaElemento(ePeliculas lista[], int tam, int id);
int harcodearData(ePeliculas lista[], int tam);
//int harcodearData(ePeliculas lista[] int tam);


#endif // PELICULAS_H_INCLUDED
