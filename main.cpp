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
#include "main.h"
#include "logica/lista.h"
#include "entidades/carta.cpp"
#include "entidades/jugador.cpp"
#include "logica/juego.cpp"
#include "vista/estetica.cpp"

using namespace std;

//Main....

int main()
{

  sLista<sJugador *> *jugadores = crearLista<sJugador *>();
  sLista<sCarta *> *baraja = crearLista<sCarta *>();

  bool salir = false;
  bool nojug = false;
  int op = 0, numjug = 0, opi = 0;
  ifstream archi;
  string texto;
  llenarListaCartas(baraja, 0, 0);
  llenarListaCartasEspeciales(baraja, 0, 0);
  do
  {
    menu();
    cout << "                                             OPCION:  ";
    cin >> op;

    if (op == 1)
    {

      advertencia();
      do
      {
        //lenar jugadores
        opi = 1;

        while (opi == 1)
        {
          numjug++;
          llenarJugadores(jugadores, numjug);

          cout << "                                             VAS A INGRESAR OTRO JUGADOR?" << endl;
          cout << "                                             1. si" << endl;
          cout << "                                             2. no" << endl;
          cout << "                                             ";
          cin >> opi;
        }
        if (opi == 2)
        {
          cout << "                                             QUIERES COMENZAR A JUGAR?" << endl;
          cout << "                                             1. si" << endl;
          cout << "                                             2. no" << endl;
          cout << "                                             ";
          cin >> opi;
          if (opi == 1)
          {
            if (numjug >= 2)
            {
              comenzarJuego(baraja, jugadores);
            }
            else
            {
              cout << "                                             NO PUEDES JUGAR, TIENE QUE HABER 2 O MAS PERSONAS PARA PODER JUGAR" << endl;
            }
          }
          else if (opi == 1)
          {
            nojug = true;
          }
          else
          {
            cout << "Comando inválido\n"
                 << endl;
            cout << "                                             QUIERES COMENZAR A JUGAR?" << endl;
            cout << "                                             1. si" << endl;
            cout << "                                             2. no" << endl;
            cout << "                                             ";
            cin >> opi;
          }
        }
        else
        {
          cout << "Comando inválido\n"
               << endl;
          opi = 1;
        }
      } while (nojug == false);
    }
    if (op == 2)
    {
      archi.open("archivos/reglas.txt", ios::in);
      while (!archi.eof())
      {
        getline(archi, texto);
        cout << texto << endl;
      }
      archi.close();
      Sleep(5000);
      system("cls");
    }
    if (op == 3)
    {
      cout << "                                             IMPRIMIENDO LISTA DE JUGADORES QUE VAN A ESTAR EN EN EL JUEGO HACIA ATRAS " << endl;
      imprimirListaJugadoresColas<sJugador *>(jugadores);
      cout << endl;
      cout << "                                             IMPRIMIENDO LISTA DE JUGADORES QUE VAN A ESTAR EN EN EL JUEGO HACIA ADELANTE " << endl;
      imprimirListaJugadoresCabezas<sJugador *>(jugadores);
    }
    if (op == 4)
    {
      cout << "                                             IMPRIMIENDO LISTA DE CARTAS QUE VAN A ESTAR EN EN EL JUEGO " << endl;
      imprimirListaCartas<sCarta *>(baraja);
    }
    if (op == 5)
    {
      salir = true;
    }
  } while (salir == false);
  cout << "                                             JUEGO FINALIZADO EXITOSAMENTE" << endl;
}

//Funcion principal del juego aca esta toda la logica del juego

void imprimirCartasJugadors(sLista<sCarta *> *auxi2)
{
  sNodo<sCarta *> *cartas;
  cartas = auxi2->cab;
  while (cartas != NULL)
  {
    cout << "                                               Carta: " << cartas->dato->color << "          Valor: " << cartas->dato->valor << " Numero: " << cartas->dato->numero << endl;
    cartas = cartas->sig;
  }
}
