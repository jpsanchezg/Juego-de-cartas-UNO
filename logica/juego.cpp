#include <iostream>
#include <string.h>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <stack>

#include "juego.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

using namespace std;

void comenzarJuego(sLista<sCarta *> *baraja, sLista<sJugador *> *jugadores, ofstream &jugadas)
{
    system("cls");
    cout << "                                             VA A COMENZAR EL JUEGO PREPARENCE JUGADORES" << endl;
    Sleep(2000);
    jugadas << "Jugador" << '\t' << '\t' << "Jugada" << endl;
    ifstream grito;
    bool ganador = false;
    bool cartavalidada;
    bool sentido = false; // si el sentido es FALSE va a la derecha si es TRUE va a la izquierda
    char *color;
    stack<sCarta *> cartasDelCentro;
    stack<sCarta *> barajaEnJuego;
    sNodo<sJugador *> *normalJugadores;
    sNodo<sJugador *> *sentidojugadores;
    sLista<sCarta *> *auxi2;
    int dev = 0;
    sNodo<sCarta *> *cartajug;
    sNodo<sCarta *> *cartajugs;

    if (barajaEnJuego.empty())
    {
        cout << "la baraja esta vasia" << endl;
        system("pause");
    }

    barajarMasoCartas(baraja, barajaEnJuego);
    cout << "                                             SE VAN A REPARTIR LAS CARTAS" << endl;
    repartir_cartas(jugadores, barajaEnJuego);
    Beep(1000, 10);

    Sleep(2500);
    system("cls");

    int numcarta = 0, cartasCentro = 0, comecartas = 0, sentidoint = 0;
    bool bloqueo = false;
    bool aceptada = false;
    bool saco = false;
    bool sacocarta = false;
    bool sentidonuevo;
    bool puntos;
    bool cabeza = false;
    bool cambio = false;
    int opcc = 0;
    char *colordelacartajugador;
    int opcart = 0;
    int indi = 0;
    //normalJugadores = jugadores->cab;
    cout << "                                                JUGADORES PREPARENCE QUE EL JUEGO VA A COMENZAR" << endl;

    do
    {
        aceptada = false;
        if (!sentido)
        {
            normalJugadores = jugadores->cab;
        }
        if (sentido)
        {
            normalJugadores = jugadores->cola;
        }
        while (normalJugadores != NULL)
        {

            if (cartasDelCentro.empty())
            {
                sCarta *primcarta = barajaEnJuego.top();
                if (strcmp(primcarta->color, "CambColor") == 0)
                {
                    strcpy(primcarta->color, "Rojo");
                }
                if (strcmp(primcarta->color, "mas 4") == 0)
                {
                    strcpy(primcarta->color, "Verde");
                }
                cartasDelCentro.push(primcarta);
                barajaEnJuego.pop();
                cout << "                                               LA CARTA QUE ESTA EN EL CENTRO ES: "
                     << " COLOR: " << cartasDelCentro.top()->color << " VALOR: " << cartasDelCentro.top()->valor << " taman: " << cartasDelCentro.size() << endl;
                cout << endl;
            }
            cout << "                                               JUGADOR " << normalJugadores->dato->nombre << " ES SU TURNO " << endl;
            cout << "                                               QUE CARTA QUIERE SACAR" << endl;
            cout << "                                               RECUERDA... SACAS CON EL NUMERO DE LA CARTA" << endl;
            cout << endl;
            cout << "                                                SI NO TIENES CARTAS PON EL 109 PARA SACAR UNA CARTA DE LA BARAJA DE CARTAS" << endl;
            cout << endl;
            do
            {
                if (!ganador)
                {

                    sNodo<sJugador *> *Nodojugador;
                    imprimirCartasJugador<sCarta *>(normalJugadores->dato->cartas);
                    cout << endl;
                    cout << endl;
                    cout << "                                                  CARTA QUE VAS A SACAR ES: ";
                    cin >> numcarta;
                    if (numcarta == 200)
                    {
                        cout << "prueba" << endl;
                        normalJugadores = jugadores->cab;
                        limpiarJugadores(normalJugadores);
                        system("pause");
                        cout << "hello there" << endl;
                        comenzarJuego(baraja, jugadores, jugadas);
                    }
                    else if (numcarta == 109)
                    {
                        //system("cls");
                        if (!barajaEnJuego.empty())
                        {
                            cout << "heloooo" << endl;
                            sacarUnaCarta(normalJugadores->dato->cartas, barajaEnJuego, sentido);
                            sacocarta = true;
                        }
                        else
                        {
                            cout << "                                                  YA SE ACABARON LAS CARTAS PARA TOMAR" << endl;
                            cout << "                                                  SE VAN A TOMAR LAS CARTAS DEL CENTRO" << endl;
                        }
                        cout << "como" << endl;
                        aceptada = true; //esto significa que ya el jugador no puede seguir sacando cartas no hay necesidad de bloquear al siguiente jugador cada vez que saca un jugador una carta
                    }
                    else
                    {
                        cartajug = BuscarCartas(normalJugadores->dato->cartas, numcarta);
                        colordelacartajugador = cartajug->dato->color;
                        if (cartasCentro == 0 && !aceptada)
                        {
                            cout << "VALOR:  " << cartajug->dato->valor << endl;
                            if (strcmp(cartajug->dato->valor, "CC") == 0)
                            {
                                cartajug = CambioDeColor(cartajug);
                                color = cartajug->dato->color;
                                cartasDelCentro.push(cartajug->dato);
                                eliminarCarta(normalJugadores->dato->cartas, numcarta);
                                aceptada = true;
                            }
                            if (strcmp(cartajug->dato->valor, "BQ") == 0)
                            {
                                cartasDelCentro.push(cartajug->dato);
                                color = cartajug->dato->color;
                                eliminarCarta(normalJugadores->dato->cartas, numcarta);
                                aceptada = true;
                                bloqueo = true;
                            }
                            if (strcmp(cartajug->dato->valor, "M2") == 0)
                            {
                                color = cartajug->dato->color;
                                cartasDelCentro.push(cartajug->dato);
                                eliminarCarta(normalJugadores->dato->cartas, numcarta);
                                comecartas = 2;
                                Nodojugador = BuscarSiguienteJugador(normalJugadores, jugadores, sentido);
                                comerCartasJugador(Nodojugador, barajaEnJuego, comecartas);
                                bloqueo = true;
                                aceptada = true;
                            }
                            if (strcmp(cartajug->dato->valor, "M4") == 0)
                            {
                                cartajug = CambioDeColor(cartajug);
                                color = cartajug->dato->color;
                                cartasDelCentro.push(cartajug->dato);
                                eliminarCarta(normalJugadores->dato->cartas, numcarta);
                                comecartas = 4;
                                Nodojugador = BuscarSiguienteJugador(normalJugadores, jugadores, sentido);
                                comerCartasJugador(Nodojugador, barajaEnJuego, comecartas);
                                bloqueo = true;
                                aceptada = true;
                            }
                            if (strcmp(cartajug->dato->valor, "RT") == 0)
                            {
                                cartasDelCentro.push(cartajug->dato);
                                color = cartajug->dato->color;
                                eliminarCarta(normalJugadores->dato->cartas, numcarta);
                                sentidoint = 1;
                                sentido = true;
                                aceptada = true;
                            }
                            cartavalidada = validarjugadas(cartajug, cartasDelCentro);
                            if (cartavalidada)
                            {
                                if (!aceptada)
                                {
                                    cartasDelCentro.push(cartajug->dato);
                                    eliminarCarta(normalJugadores->dato->cartas, numcarta);
                                    color = cartajug->dato->color;
                                    aceptada = true;
                                }
                            }
                            if (!cartavalidada && !aceptada)
                            {
                                cout << "la carta es invalida por el color que tomaste escoge otra...." << endl;
                                cout << "                                               LA CARTA QUE ESTA EN EL CENTRO ES: "
                                     << " COLOR: " << cartasDelCentro.top()->color << " VALOR: " << cartasDelCentro.top()->valor << " taman: " << cartasDelCentro.size() << endl;
                                cout << endl;
                            }
                        }
                        if (cartasCentro > 0)
                        {
                            cartavalidada = validarjugadas(cartajug, cartasDelCentro);
                            if (cartavalidada)
                            {
                                if (strcmp(cartajug->dato->valor, "RT") == 0)
                                {
                                    if (!sentido)
                                    {
                                        cartasDelCentro.push(cartajug->dato);
                                        eliminarCarta(normalJugadores->dato->cartas, numcarta);
                                        sentidonuevo = true;
                                        aceptada = true;
                                    }
                                    if (sentido)
                                    {
                                        cartasDelCentro.push(cartajug->dato);
                                        eliminarCarta(normalJugadores->dato->cartas, numcarta);
                                        sentidonuevo = false;
                                        aceptada = true;
                                    }
                                    if (sentidonuevo)
                                    {
                                        sentido = true;
                                    }
                                    if (!sentidonuevo)
                                    {
                                        sentido = false;
                                    }
                                }
                                if (strcmp(cartajug->dato->valor, "BQ") == 0)
                                {
                                    cartasDelCentro.push(cartajug->dato);
                                    color = cartajug->dato->color;
                                    eliminarCarta(normalJugadores->dato->cartas, numcarta);
                                    aceptada = true;
                                    bloqueo = true;
                                }
                                if (strcmp(cartajug->dato->valor, "M2") == 0)
                                {
                                    cartasDelCentro.push(cartajug->dato);
                                    eliminarCarta(normalJugadores->dato->cartas, numcarta);
                                    bloqueo = true;
                                    comecartas = 2;
                                    Nodojugador = BuscarSiguienteJugador(normalJugadores, jugadores, sentido);
                                    comerCartasJugador(Nodojugador, barajaEnJuego, comecartas);
                                    aceptada = true;
                                }
                                if (!aceptada)
                                {

                                    cartasDelCentro.push(cartajug->dato);
                                    eliminarCarta(normalJugadores->dato->cartas, numcarta);
                                    aceptada = true;
                                }
                            }
                            if (!cartavalidada)
                            {
                                if (strcmp(cartajug->dato->valor, "CC") == 0)
                                {
                                    cartajug = CambioDeColor(cartajug);
                                    strcpy(color, cartajug->dato->color);
                                    cartasDelCentro.push(cartajug->dato);
                                    eliminarCarta(normalJugadores->dato->cartas, numcarta);
                                    aceptada = true;
                                }

                                if (strcmp(cartajug->dato->valor, "M4") == 0)
                                {
                                    cartajug = CambioDeColor(cartajug);
                                    color = cartajug->dato->color;
                                    cartasDelCentro.push(cartajug->dato);
                                    eliminarCarta(normalJugadores->dato->cartas, numcarta);
                                    bloqueo = true;
                                    comecartas = 4;
                                    Nodojugador = BuscarSiguienteJugador(normalJugadores, jugadores, sentido);
                                    comerCartasJugador(Nodojugador, barajaEnJuego, comecartas);
                                    aceptada = true;
                                }
                            }
                            if (!cartavalidada && !aceptada)
                            {
                                cout << "                                               la carta es invalida por el color que tomaste escoge otra...." << endl;
                                cout << "                                               LA CARTA QUE ESTA EN EL CENTRO ES: "
                                     << " COLOR: " << cartasDelCentro.top()->color << " VALOR: " << cartasDelCentro.top()->valor << " taman: " << cartasDelCentro.size() << endl;
                                cout << endl;
                            }
                        }
                        if (normalJugadores->dato->cartas->tam == 1)
                        {
                            string opc;
                            char *linea;
                            grito.open("archivos/grita.txt", ios::out);
                            while (grito.eof())
                            {
                                grito.getline(linea, 500);
                                cout << linea << endl;
                            }
                            grito.close();
                            cin >> opc;
                            if (opc == "uno" || opc == "UNO")
                            {
                                grito.open("archivos/UNO.txt", ios::out);
                                while (grito.eof())
                                {
                                    grito.getline(linea, 500);
                                    cout << linea << endl;
                                }
                                grito.close();
                                aceptada = true;
                            }
                            Sleep(1000);
                            if (!aceptada)
                            {
                                cout << "                                               NO GRITASTE UNO ASI QUE VAS A COMER 2 CARTAS" << endl;
                                comerCartasJugador(Nodojugador, barajaEnJuego, 2);
                            }
                            //recordar si no grita uno se tiene que comer dos cartas
                        }
                        if (normalJugadores->dato->cartas->tam == 0)
                        {
                            //Diseño aparece el logo uno en ascci todo bonito
                            puntos = contarPuntos(jugadores, normalJugadores);
                            if (puntos == true)
                            {
                                char *linea;

                                cout << endl;
                                cout << "                                               EL GANADOR DE ESTA PARTIDA UNO ES: " << normalJugadores->dato->nombre << endl;
                                cout << endl;
                                grito.open("archivos/ganador.txt", ios::out);
                                while (grito.eof())
                                {
                                    grito.getline(linea, 500);
                                    cout << linea << endl;
                                }
                                grito.close();
                                crearArchivoBinario(jugadores);
                                crearArchivoHtml();
                            }
                            else
                            {
                                cout << "                                               SE VA A JUGAR OTRA RONDA ASI QUE SE VA A REINICIAR TODO" << endl;
                                normalJugadores = jugadores->cab;
                                limpiarJugadores(normalJugadores);
                                comenzarJuego(baraja, jugadores, jugadas);
                            }
                            aceptada = true;
                            ganador = true;
                        }
                    }
                }
                if (sacocarta)
                {
                    cout << "hola?" << endl;
                    //cuando el compilador esta bobo hay que quitar esto y si se mata igual
                    /*sCarta *dat;
                    dat->color = "SacoCarta";
                    dat->valor = "SC";
                    dat->numero = 109;*/
                    sCarta *dat = new sCarta;
                    dat->color = new char[20];
                    dat->valor = new char[20];
                    strcpy(dat->color, "SacoCarta");
                    strcpy(dat->valor, "SC");
                    dat->numero = 109;
                    cartajug = crearNodo<sCarta *>(dat);
                }
                if (aceptada && !sacocarta)
                {
                    cartasCentro++;
                }
            } while (aceptada == false);

            llenarArchivoJugadas(jugadas, normalJugadores, cartajug);
            sacocarta = false;
            cout << "                                               LA CARTA QUE ESTA EN EL CENTRO ES: "
                 << " COLOR: " << cartasDelCentro.top()->color << " VALOR: " << cartasDelCentro.top()->valor << " taman: " << cartasDelCentro.size() << endl;
            cout << endl;
            if (!ganador)
            {
                if (bloqueo && !sentido)
                {
                    sNodo<sJugador *> *Nodojugador;
                    Nodojugador = BuscarSiguienteJugador(normalJugadores, jugadores, sentido);
                    cout << "                                               JUGADOR BLOQUEADO ES: " << Nodojugador->dato->nombre << endl;
                    cout << endl;
                    normalJugadores->sig = Nodojugador;
                    normalJugadores = normalJugadores->sig;
                    bloqueo = false;
                    aceptada = false;
                }
                if (!bloqueo && !sentido)
                {
                    normalJugadores = normalJugadores->sig;
                    aceptada = false;
                }
                if (bloqueo && sentido)
                {
                    sNodo<sJugador *> *Nodojugador;
                    Nodojugador = BuscarSiguienteJugador(normalJugadores, jugadores, sentido);
                    cout << "                                               JUGADOR BLOQUEADO ES: " << Nodojugador->dato->nombre << endl;
                    cout << endl;
                    normalJugadores->atrs = Nodojugador;

                    normalJugadores = normalJugadores->atrs;
                    aceptada = false;
                    bloqueo = false;
                }
                if (!bloqueo && sentido)
                {

                    if (sentidoint == 1)
                    {
                        normalJugadores = jugadores->cola;
                        sentidoint = 0;
                        cambio = true;
                    }
                    if (!cambio)
                    {
                        normalJugadores = normalJugadores->atrs;
                    }
                    cambio = false;
                    aceptada = false;
                }
                bloqueo = false;
            }
        }
    } while (ganador != true);
}

//Funcion validar jugadas
bool validarjugadas(sNodo<sCarta *> *cartaJugadores, stack<sCarta *> cartasDelCentro)
{
    if (strcmp(cartaJugadores->dato->color, cartasDelCentro.top()->color) == 0)
    {
        return true;
    }
    else if (strcmp(cartasDelCentro.top()->valor, cartaJugadores->dato->valor) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    //return false;
}

//Funcion de eliminar carta del jugador
void eliminarCarta(sLista<sCarta *> *&cartasJug, int numcarta)
{
    sNodo<sCarta *> *temp;
    temp = cartasJug->cab;
    if (cartasJug->cab->dato->numero == numcarta)
    {
        cartasJug->cab = cartasJug->cab->sig;
        delete (temp);
    }
    else
    {
        while ((temp->sig)->dato->numero != numcarta)
        {
            temp = temp->sig;
        }
        delete (temp->sig);
        temp->sig = (temp->sig)->sig;
    }
    cartasJug->tam--;
}

//Funcion barajar cartastot

//funcion que busca la carta corresponiente al numero que se le puso
sNodo<sCarta *> *BuscarCartas(sLista<sCarta *> *auxi2, int numcarta)
{
    sNodo<sCarta *> *cartas;
    cartas = auxi2->cab;
    while (cartas != NULL)
    {
        if (cartas->dato->numero == numcarta)
        {
            return cartas;
        }
        cartas = cartas->sig;
    }
    return NULL;
}

//Funcion que cambia de color cuando toca la carta mas 4 y cambio de color
sNodo<sCarta *> *CambioDeColor(sNodo<sCarta *> *&cartaJug)
{
    int op = 0;
    cout << "                                               A QUE COLOR QUIERES CAMBIAR...." << endl;
    cout << "                                               " << ANSI_COLOR_RED << "      [1] ROJO" << ANSI_COLOR_RESET << endl;
    cout << "                                               " << ANSI_COLOR_YELLOW << "      [2] AMARILLO" << ANSI_COLOR_RESET << endl;
    cout << "                                               " << ANSI_COLOR_BLUE << "      [3] AZUL" << ANSI_COLOR_RESET << endl;
    cout << "                                               " << ANSI_COLOR_GREEN << "      [4] VERDE" << ANSI_COLOR_RESET << endl;
    cout << "                                               ESCOGE UNA OPCION:";
    cin >> op;
    switch (op)
    {
    case 1:
        strcpy(cartaJug->dato->color, "Rojo");
        return cartaJug;
        break;
    case 2:
        strcpy(cartaJug->dato->color, "Amarillo");

        return cartaJug;
        break;
    case 3:
        strcpy(cartaJug->dato->color, "Azul");
        return cartaJug;
        break;
    case 4:
        strcpy(cartaJug->dato->color, "Verde");
        return cartaJug;
        break;
    }
    return NULL;
}

//Funcion crear archivo binario
void crearArchivoBinario(sLista<sJugador *> *jugadores)
{
    sNodo<sJugador *> *nodoJugador = jugadores->cab;
    ofstream puntuacion("Datos jugadores.bin", ios::app | ios::binary);
    for (int i = 0; i < jugadores->tam; i++)
    {
        puntuacion.seekp(0, ios::end);
        puntuacion.write((char *)nodoJugador, sizeof(sJugador));
        nodoJugador = nodoJugador->sig;
        puntuacion.close();
    }
}

//fuincion crea el archivo html
void crearArchivoHtml()
{
    ifstream binario("Datos jugadores.bin", ios::in | ios::binary);
    ofstream html("Resultados.html", ios::out | ios::app | ios::binary);
    sJugador dato;
    char titulo[250];
    strcpy(titulo, "Resultados del juego");

    binario.seekg(0, ios::end);
    int nr = binario.tellg() / sizeof(sJugador);
    html << "<html>";
    html << "<title>" << titulo << "</title>";
    html << "</html>";
    html << "<body>";
    html << "<table style="
            "width:100%"
            ">";
    html << "<tr> <th>"
         << "Nombre"
         << "</th><th> "
         << "Apellido"
         << "</th> <th> "
         << "Puntos"
         << "</th> </tr>";
    for (int i = 0; i < nr; i++)
    {
        binario.seekg(i * sizeof(sJugador), ios::beg);
        binario.read((char *)&dato, sizeof(sJugador));
        html << "<tr> <th>" << dato.nombre << "</th> <th> " << dato.apellido << "</th> <th> " << dato.puntos << "</th> </tr>";
    }
    html << "</table></body>";
    html.close();
}

//funcion contar puntos de los jugadores
bool contarPuntos(sLista<sJugador *> *jugadores, sNodo<sJugador *> *ganador)
{
    sNodo<sJugador *> *nodoJugador = jugadores->cab;
    int numcart = 0;
    for (int i = 0; i < (jugadores->tam) - 1; i++)
    {
        if (nodoJugador != ganador)
        {
            sNodo<sCarta *> *nodoCartas = nodoJugador->dato->cartas->cab;
            while (nodoCartas != NULL || ganador->dato->puntos < 500)
            {
                if (!strcmp(nodoCartas->dato->valor, "M2"))
                {
                    ganador->dato->puntos += 20;
                }
                else if (!strcmp(nodoCartas->dato->valor, "RT"))
                {
                    ganador->dato->puntos += 20;
                }
                else if (!strcmp(nodoCartas->dato->valor, "BQ"))
                {
                    ganador->dato->puntos += 20;
                }
                else if (!strcmp(nodoCartas->dato->valor, "CC"))
                {
                    ganador->dato->puntos += 50;
                }
                else if (!strcmp(nodoCartas->dato->valor, "M4"))
                {
                    ganador->dato->puntos += 50;
                }
                else
                {
                    numcart = atoi(nodoCartas->dato->valor);
                    ganador->dato->puntos += numcart;
                }
                nodoCartas = nodoCartas->sig;
            }
            if (ganador->dato->puntos >= 500)
            {
                return true;
            }
        }
        nodoJugador = nodoJugador->sig;
    }
    return false;
}
