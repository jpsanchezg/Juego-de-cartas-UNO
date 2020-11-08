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
#include "lista.cpp"
#include <stack>
#include <queue>

using namespace std;

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
  sLista<sCarta *> *cartas;
};

//menu
void menu()
{
  cout << "                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  cout << "                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  ......     %%%%%%%%%" << endl;
  cout << "                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%...     ,/*        %%%%%%" << endl;
  cout << "                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%/%%%%%%%.    *%%%%%###%/  ... %%%%" << endl;
  cout << "                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%(,.... %%%%&,    ,&%%%%&&&@##%/.... %%%" << endl;
  cout << "                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&((,     %%&&*   .%%%%%%%%%%&%&/,.,, %%%" << endl;
  cout << "                  %%%%%%%%%%%%%%%%%%%%%%%%%%%,....   %%%%%&&##,     %%%*    .%%%%%%%%%%&&&,,,,.%%%" << endl;
  cout << "                  %%%%%%%%%%%%%%%%%%%..... &((,          %%%&%%*    .@%(/.... %%%%%%%%%&&.,,,,,%%%" << endl;
  cout << "                  %%%%%%%%%%%%%%%%%%((,     &((,    ,       .&%%*.....#/(*,,*,,  %%%%%  ,,,,,,%%%%" << endl;
  cout << "                  %%%%%%  ..,%%%%%%%&((,     &((,    .(**  .... (*,,,,.&////*,,,,*,,,,,,,,,/&%%%%%" << endl;
  cout << "                  %%%%#*,   .,%%%%%%%&##,     &##,  .,.(((#/*,,,,,,,,,,.&&(###(((/,,,*//#&&%%%%%%%" << endl;
  cout << "                  %%%&%#,,   ,/%%%%%%&&##,     &#%,..., &&###%#/,,,,,*,*.%&&&&%%%%%&&&&&%%%%%%%%%%" << endl;
  cout << "                  %%%%&##,..  ,(%%%%%%&&%%*. ,..&%%,,,,, %%&&&%%%%//,,,,,,%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  cout << "                  %%%%%&##,..  .(%%%%%%&&%&/,,,,/&%%,,,,, %%%%&&&&%%%%%#%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  cout << "                  %%%%%%&##*,....%%%%%%%&&%,,,,,*&&%%*,,,,.%%%%%%%&&&&%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  cout << "                  %%%%%%%&#//,,,,, %%%%%  ,,,,,,%%&&%%/(%%&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  cout << "                  %%%%%%%%&/((/,,,,,,,,,,,,,,*&%%%%&&&&&&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  cout << "                  %%%%%%%%%&&##%///,,,,*///&&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  cout << "                  %%%%%%%%%%%&&&&%&&%&&&&&&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  cout << "                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  cout << endl;
  cout << "                                             MENU DE JUEGO UNO" << endl;
  cout << "                                             [1] Jugar" << endl;
  cout << "                                             [2] Ver instrucciones de juego" << endl;
  cout << "                                             [3] Imprimir lista de jugadores" << endl;
  cout << "                                             [4] Imprimir lista de cartas" << endl;
  cout << "                                             [5] salir" << endl;
}

//FUNCIONES

//Funciones de llenado de cartas y jugadores
void llenarListaCartas(sLista<sCarta *> *baraja, int i, int u);
void llenarListaCartasEspeciales(sLista<sCarta *> *baraja, int i, int u);

//Funciones de logica de juego
void comenzarJuego(sLista<sCarta *> *baraja, sLista<sJugador *> *jugadores, int numjug);
void barajarMasoCartas(sLista<sCarta *> *baraja, stack<sCarta *> &pila);
void repartir_cartas(sLista<sJugador *> *jugadores, stack<sCarta *> &pila);
void llenarJugadores(sLista<sJugador *> *jugadores, int numjug);

//Validacion de numeros repetidos
bool numerosRepetidos(int num, int repetidos[108], int tam);

//Estetica
void advertencia();

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
      //if (numjug == 0)
      //{
        do
        {
          //lenar jugadores
          opi = 0;
          numjug++;
          llenarJugadores(jugadores, numjug);

          cout << "                                             VAS A INGRESAR OTRO JUGADOR?" << endl;
          cout << "                                             1. si" << endl;
          cout << "                                             2. no" << endl;
          cout << "                                             ";
          cin >> opi;
          if (opi == 1)
          {
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
                comenzarJuego(baraja, jugadores, numjug);
              }
              else
              {
                cout << "                                             NO PUEDES JUGAR, TIENES QUE SER 2 O MAS PERSONAS PARA PODER JUGAR" << endl;
              }
            }
            else
            {
              nojug = true;
            }
          }
        } while (nojug == false);
      //}
      /*if (numjug > 0 )
      {
        cout << "                                             QUIERES COMENZAR A JUGAR?" << endl;
        cout << "                                             1. si" << endl;
        cout << "                                             2. no" << endl;
        cout << "                                             ";
        cin >> opi;
        if (opi == 1)
        {
          comenzarJuego(baraja, jugadores, numjug);
        }
      }*/
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

//Llenar cartas normales del 1 al 9
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
      //cout<<y<<endl;
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
  jugador->cartas = crearLista<sCarta *>();
  /*if (numjug == 1)
  {
    insertarNodo<sJugador *>(jugadores, jugador);
  }
  else
  {
    insertarNodoFinal<sJugador *>(jugadores, jugador);
  }*/
  insertarNodojugador<sJugador *>(jugadores, jugador);
}
void advertencia()
{
  cout << "                                             Antes de jugar tienes que ingresar minimo 2 jugadores" << endl;
}

//Funcion principal del juego aca esta toda la logica del juego
void comenzarJuego(sLista<sCarta *> *baraja, sLista<sJugador *> *jugadores, int numjug)
{
  cout << "                                             VA A COMENZAR EL JUEGO PREPARENCE JUGADORES" << endl;

  cout << "                                             SE VAN A REPARTIR LAS CARTAS" << endl;

  bool ganador = false;
  bool sentido = false; // si el sentido es FALSE va a la derecha si es TRUE va a la izquierda
  /*
  cartas que van a ir poniendo los jugadores cada ves que les toque y 
  si pasa una ronda se debe volver a barajar dicho mazo
  */
  stack<sCarta *> cartasDelCentro;
  stack<sCarta *> pila;
  barajarMasoCartas(baraja, pila);
  repartir_cartas(jugadores, pila);
  cout << "                                             JUGADORES PREPARENCE QUE EL JUEGO VA A COMENZAR" << endl;
  //imprimirListaJugadoresCarta<sJugador *, sCarta *>(jugadores);
  /*do
  {
    if (sentido == false)
    {
      while(jugadores != NULL){

      }
    }
    if (sentido == true)
    {
    }
  } while (ganador == false);*/

  imprimirListaJugadoresCarta<sJugador *, sCarta *>(jugadores);
}

//Funcion barajar cartastot
/*
En esta funcion hay un pequeño bug de repetidos con el numero 108
toca mirarlo super bien el por que repite el numero 108 4 veces 

*/
void barajarMasoCartas(sLista<sCarta *> *baraja, stack<sCarta *> &pila)
{
  cout << "                                             BARAJANDO LAS CARTAS PARA EL JUEGO" << endl;
  cout << endl;
  cout << "                                             REPARTIENDO CARTAS A LOS JUGADORES" << endl;
  cout << endl;
  bool final = false;
  bool repetido = true;
  int repetidos[108];
  int cartastot = 108;
  int num = 0, i = 0;
  sNodo<sCarta *> *auxi;
  auxi = baraja->cab;
  do
  {
    if (i != 0)
    {
      num = rand() % cartastot;
      while (repetido == true)
      {
        repetido = numerosRepetidos(num, repetidos, i);
        if (repetido == true)
        {
          num = rand() % 108;
        }
      }
    }
    if (i == 0)
    {
      num = rand() % cartastot;
    }

    while (auxi != NULL)
    {
      if (num == auxi->dato->numero)
      {
        repetidos[i];

        pila.push(auxi->dato);
        repetidos[i] = num;
        i++;
      }
      auxi = auxi->sig;
    }

    auxi = baraja->cab;
    cartastot = cartastot - 1;
    repetido = true;
    if (cartastot == 0)
    {
      final = true;
    }
  } while (final == false);
}

//Funcion que mira los numeros repetidos que saca el numero random
bool numerosRepetidos(int num, int repetidos[108], int tam)
{
  int op = 2;
  for (int i = 0; i < tam; i++)
  {
    if (num == repetidos[i])
    {
      return true;
    }
  }
  return false;
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