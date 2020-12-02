#include <iostream>
#include <string.h>
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <windows.h>
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
  ofstream jugadas("Jugadas.txt", ios::app);
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
        opi = 1;
        while (opi == 1)
        {
          numjug++;
          system("cls");
          llenarJugadores(jugadores, numjug); //Aca se llenan los jugadores
          cout << setw(70) << "VAS A INGRESAR OTRO JUGADOR?" << endl;
          cout << setw(60) << "[1] si" << endl;
          cout << setw(60) << "[2] no" << endl;
          cout << setw(72) << "PON EL NUMERO COMO RESPUESTA" << endl;
          cout << "                                             OPCION: ";
          cin >> opi;
        }
        if (opi == 2)
        {
          system("cls");
          cout << "                                             QUIERES COMENZAR A JUGAR?" << endl;
          cout << setw(60) << "[1] si" << endl;
          cout << setw(60) << "[2] no" << endl;
          cout << "                                             OPCION:";
          cin >> opi;
          
          if (opi == 1)
          {
            if (numjug >= 2)
            {
              system("cls");
              comenzarJuego(baraja, jugadores, jugadas);
            }
            else
            {

              cout << "                                             NO PUEDES JUGAR, TIENE QUE HABER 2 O MAS PERSONAS PARA PODER JUGAR" << endl;
              system("pause");
            }
          }
          else if (opi == 1)
          {
            nojug = true;
          }
          else
          {
            cout << "                                             Comando inválido\n"
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
          cout << "                                             Comando inválido\n"
               << endl;
          opi = 1;
        }
      } while (nojug == false);
    }
    if (op == 2)
    {
      archi.open("archivos/grita.txt", ios::in);
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
