#include "logica/lista.cpp"
#include "stack"

//estructuras
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

//funciones prototipo
void imprimirCartasJugadors(sLista<sCarta *> *auxi2);


