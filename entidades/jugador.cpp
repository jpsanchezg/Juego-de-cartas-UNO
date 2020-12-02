#include <iostream>
#include <string>
#include <string.h>
#include "jugador.h"
#include <stack>

using namespace std;

//Funcion llenar jugadores
void llenarJugadores(sLista<sJugador *> *jugadores, int numjug)
{
    sJugador *jugador = new sJugador;
    jugador->nombre = new char();
    jugador->apellido = new char();
    cout << "                                             cual es el nombre del jugador" << endl;
    cout << "                                             ";
    cin >> jugador->nombre;
    cout << "                                             cual es el apellido de: " << jugador->nombre << endl;
    cout << "                                             ";
    cin >> jugador->apellido;
    jugador->puntos = 0;
    jugador->numjug = numjug;
    jugador->cartas = crearLista<sCarta *>();
    insertarNodojugador<sJugador *>(jugadores, jugador);
}

//Funcion de comer cartas al jugadores
void comerCartasJugador(sNodo<sJugador *> *jugadoresCartas, stack<sCarta *> &pila, int cartasAcomer)
{
    int i = 0;
    sCarta *carta;
    int newtam = jugadoresCartas->dato->cartas->tam + cartasAcomer;
    bool verificador;
    while (jugadoresCartas->dato->cartas->tam < newtam)
    {
        carta = pila.top();
        if (jugadoresCartas->dato->cartas->cab == NULL)
        {
            insertarNodoCartasaJugador<sCarta *>(jugadoresCartas->dato->cartas, carta);
            pila.pop();
        }
        else
        {
            insertarNodoCartasaJugador<sCarta *>(jugadoresCartas->dato->cartas, carta);
            pila.pop();
        }
    }
}

// Esta funcion busca al siguiente jugador para bloquear o sumar cartas
sNodo<sJugador *> *BuscarSiguienteJugador(sNodo<sJugador *> *&jugadores, sLista<sJugador *> *auxi2, bool sentido)
{
    if (!sentido)
    {
        if (jugadores->sig == NULL)
        {
            return auxi2->cab;
        }
        else
        {
            return jugadores->sig;
        }
    }
    else if (sentido)
    {
        if (jugadores->atrs == NULL)
        {
            return auxi2->cola;
        }
        else
        {
            return jugadores->atrs;
        }
    }
    return NULL;
}

//esta funcion limpia los masos de los jugadores como si no hubiera pasado nada
void limpiarJugadores(sNodo<sJugador *> *&jugadores)
{
    while (jugadores != NULL)
    {
        jugadores->dato->cartas = crearLista<sCarta *>();
        jugadores = jugadores->sig;

    }
}

//funcion para que coma una sola carta cada jugador
void sacarUnaCarta(sNodo<sJugador *> *&jugadoresCartas, stack<sCarta *> &pila, bool sentido)
{
    int i = 0;
    sCarta *carta;
    carta = pila.top();
    insertarNodoCartas<sCarta *>(jugadoresCartas->dato->cartas, carta);
    pila.pop();
}