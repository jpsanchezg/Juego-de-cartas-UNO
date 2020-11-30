#include <iostream>
#include <string>
#include <string.h>
#include "carta.h"
//#include "lista.cpp"
#include <stack>

using namespace std;

void llenarListaCartas(sLista<sCarta *> *baraja, int i, int u)
{

    if (i == 76)
    {
        return;
    }
    else
    {
        if (i < 72)
        {
            int f = i / 18;
            int v = (i % 9);
            string s;
            sCarta *carta = new sCarta;
            carta->color = new char[15];
            carta->valor = new char[2];

            switch (f)
            {
            case 0:
                strcpy(carta->color, "Azul");
                break;
            case 1:
                strcpy(carta->color, "Rojo");

                break;
            case 2:
                strcpy(carta->color, "Amarillo");

                break;
            case 3:
                strcpy(carta->color, "Verde");

                break;
            default:
                break;
            };
            s = to_string(v + 1);
            strcpy(carta->valor, s.c_str());
            carta->numero = i;

            insertarNodoCartas<sCarta *>(baraja, carta);
            llenarListaCartas(baraja, i + 1, u);
        }
        else
        {

            int v = 0;
            //int g = u/19;
            string s;
            sCarta *carta = new sCarta;
            carta->color = new char[15];
            carta->valor = new char[2];
            switch (u)
            {
            case 0:
                strcpy(carta->color, "Azul");
                break;
            case 1:
                strcpy(carta->color, "Rojo");

                break;
            case 2:
                strcpy(carta->color, "Amarillo");

                break;
            case 3:
                strcpy(carta->color, "Verde");
                break;
            default:
                break;
            };
            s = to_string(v);
            strcpy(carta->valor, s.c_str());
            carta->numero = i;

            insertarNodoCartas<sCarta *>(baraja, carta);
            llenarListaCartas(baraja, i + 1, u + 1);
        }
    }
    return;
}

//llena las cartas especiales a la baraja
void llenarListaCartasEspeciales(sLista<sCarta *> *baraja, int i, int u)
{
    if (i == 32)
    {
        return;
    }
    else
    {
        if (i >= 24)
        {
            int y = i;
            string s;
            sCarta *carta = new sCarta;
            carta->color = new char[15];
            carta->valor = new char[3];
            if (y >= 24 && y < 28)
            {
                strcpy(carta->color, "CambColor");
                strcpy(carta->valor, "CC");
            }
            else if (y >= 28 && y < 32)
            {
                strcpy(carta->color, "mas 4");
                strcpy(carta->valor, "M4");
            }
            carta->numero = i + 76;
            insertarNodoCartas<sCarta *>(baraja, carta);
            llenarListaCartasEspeciales(baraja, i + 1, u);
        }
        else
        {
            int o = i;
            int f = i / 6;
            int v = 0;
            string s;
            sCarta *carta = new sCarta;
            carta->color = new char[15];
            carta->valor = new char[3];
            switch (f)
            {
            case 0:
                strcpy(carta->color, "Azul");
                break;
            case 1:
                strcpy(carta->color, "Rojo");

                break;
            case 2:
                strcpy(carta->color, "Amarillo");

                break;
            case 3:
                strcpy(carta->color, "Verde");

                break;
            default:
                break;
            };
            if (u % 3 == 0)
            {
                strcpy(carta->valor, "M2");
            }
            else if (u % 3 == 1)
            {
                strcpy(carta->valor, "RT");
            }
            else if (u % 3 == 2)
            {
                strcpy(carta->valor, "BQ");
            }
            carta->numero = i + 76;
            insertarNodoCartas<sCarta *>(baraja, carta);
            llenarListaCartasEspeciales(baraja, i + 1, u + 1);
        }
    }
    return;
}

void barajarMasoCartas(sLista<sCarta *> *baraja, stack<sCarta *> &pila)
{
    cout << "                                             BARAJANDO LAS CARTAS PARA EL JUEGO" << endl;
    cout << endl;
    cout << "                                             REPARTIENDO CARTAS A LOS JUGADORES" << endl;
    cout << endl;
    bool final = false;
    sNodo<sCarta *> *auxi;
    auxi = baraja->cab;
    int numeros[108];
    int num;
    srand(time(NULL));
    int insertados = 0;
    bool repetido;
    int cartastot = 108;

    while (insertados != 108)
    {
        num = rand() % 108;
        repetido = numerosRepetidos(numeros, num, insertados);
        if (repetido == false)
        {
            numeros[insertados] = num;
            insertados++;
        }
    }
    int agregado = 0;
    while (agregado != 108)
    {
        if (numeros[agregado] == auxi->dato->numero)
        {
            pila.push(auxi->dato);
            agregado++;
            auxi = baraja->cab;
        }
        else
        {
            auxi = auxi->sig;
        }
    }
}

//Funcion que mira los numeros repetidos que saca el numero random
bool numerosRepetidos(int *arreglo, int num, int tam)
{
    if (tam == 0)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < tam; i++)
        {
            if (num == arreglo[i])
            {
                return true;
            }
        }
        return false;
    }
}

//Funcion de repartir cartas
void repartir_cartas(sLista<sJugador *> *jugadores, stack<sCarta *> &pila)
{
    int i = 0;
    sNodo<sJugador *> *jugador = jugadores->cab;
    sCarta *carta;
    while (jugador != NULL)
    {
        while (jugador->dato->cartas->tam < 7)
        {

            carta = pila.top();
            if (jugador->dato->cartas->cab == NULL)
            {
                insertarNodoCartas<sCarta *>(jugador->dato->cartas, carta);
                pila.pop();
            }
            else
            {
                insertarNodoCartas<sCarta *>(jugador->dato->cartas, carta);
                pila.pop();
            }
        }
        jugador = jugador->sig;
    }
}
