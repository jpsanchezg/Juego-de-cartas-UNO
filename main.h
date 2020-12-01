#include "logica/lista.cpp"
#include "stack"

//estructuras del juego 
struct sCarta
{
    char *color;
    char *valor;
    int numero;
};
struct sJugador
{
    char *nombre;
    char *apellido;
    int puntos;
    int numjug;
    sLista<sCarta *> *cartas;
};



