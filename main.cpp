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
cout<<"                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<"                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  ......     %%%%%%%%%"<<endl;
cout<<"                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%...     ,/*        %%%%%%"<<endl;
cout<<"                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%/%%%%%%%.    *%%%%%###%/  ... %%%%"<<endl;
cout<<"                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%(,.... %%%%&,    ,&%%%%&&&@##%/.... %%%"<<endl;
cout<<"                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&((,     %%&&*   .%%%%%%%%%%&%&/,.,, %%%"<<endl;
cout<<"                  %%%%%%%%%%%%%%%%%%%%%%%%%%%,....   %%%%%&&##,     %%%*    .%%%%%%%%%%&&&,,,,.%%%"<<endl;
cout<<"                  %%%%%%%%%%%%%%%%%%%..... &((,          %%%&%%*    .@%(/.... %%%%%%%%%&&.,,,,,%%%"<<endl;
cout<<"                  %%%%%%%%%%%%%%%%%%((,     &((,    ,       .&%%*.....#/(*,,*,,  %%%%%  ,,,,,,%%%%"<<endl;
cout<<"                  %%%%%%  ..,%%%%%%%&((,     &((,    .(**  .... (*,,,,.&////*,,,,*,,,,,,,,,/&%%%%%"<<endl;
cout<<"                  %%%%#*,   .,%%%%%%%&##,     &##,  .,.(((#/*,,,,,,,,,,.&&(###(((/,,,*//#&&%%%%%%%"<<endl;
cout<<"                  %%%&%#,,   ,/%%%%%%&&##,     &#%,..., &&###%#/,,,,,*,*.%&&&&%%%%%&&&&&%%%%%%%%%%"<<endl;
cout<<"                  %%%%&##,..  ,(%%%%%%&&%%*. ,..&%%,,,,, %%&&&%%%%//,,,,,,%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<"                  %%%%%&##,..  .(%%%%%%&&%&/,,,,/&%%,,,,, %%%%&&&&%%%%%#%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<"                  %%%%%%&##*,....%%%%%%%&&%,,,,,*&&%%*,,,,.%%%%%%%&&&&%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<"                  %%%%%%%&#//,,,,, %%%%%  ,,,,,,%%&&%%/(%%&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<"                  %%%%%%%%&/((/,,,,,,,,,,,,,,*&%%%%&&&&&&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<"                  %%%%%%%%%&&##%///,,,,*///&&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<"                  %%%%%%%%%%%&&&&%&&%&&&&&&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<"                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<endl;
  cout << "                                             MENU DE JUEGO UNO" << endl;
  cout << "                                             [1] Jugar" << endl;
  cout << "                                             [2] Ver instrucciones de juego" << endl;
  cout << "                                             [3] Imprimir lista de jugadores" << endl;
  cout << "                                             [4] Imprimir lista de cartas" << endl;
  cout << "                                             [5] salir" << endl;
}

//funciones
void llenarListaCartas(sLista<sCarta *> *baraja, int i, int u);
void llenarListaCartasEspeciales(sLista<sCarta *> *baraja, int i, int u);

void comenzarJuego(sLista<sCarta *> *baraja, sLista<sJugador *> *jugadores, int numjug);
void barajarMasoCartas(sLista<sCarta *> *baraja);

void llenarJugadores(sLista<sJugador *> *jugadores);
void advertencia();
bool numerosRepetidos(int num, int repetidos[108], int tam);

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
    cout<<"                                             OPCION:  ";cin >> op;
    
    if (op == 1)
    {

      advertencia();
      do
      {
        //lenar jugadores
        opi = 0;
        numjug++;
        llenarJugadores(jugadores);

        cout << "                                             VAS A INGRESAR OTRO JUGADOR?" << endl;
        cout << "                                             1. si" << endl;
        cout << "                                             2. no" << endl;
        cout<<"                                             ";cin >> opi;
        if (opi == 1)
        {

          cout << numjug << endl;
        }
        if (opi == 2)
        {
          cout << "                                             QUIERES COMENZAR A JUGAR?" << endl;
          cout << "                                             1. si" << endl;
          cout << "                                             2. no" << endl;
          cout<<"                                             ";cin >> opi;
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
      cout << "                                             IMPRIMIENDO LISTA DE JUGADORES QUE VAN A ESTAR EN EN EL JUEGO " << endl;
      imprimirListaJugadores<sJugador *>(jugadores);
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

      insertarNodo<sCarta *>(baraja, carta);
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

      insertarNodo<sCarta *>(baraja, carta);
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
      insertarNodo<sCarta *>(baraja, carta);
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
      insertarNodo<sCarta *>(baraja, carta);
      llenarListaCartasEspeciales(baraja, i + 1, u + 1);
    }
  }
  return;
}

//Funcion llenar jugadores
void llenarJugadores(sLista<sJugador *> *jugadores)
{
  sJugador *jugador = new sJugador;
  jugador->nombre = new char();
  jugador->apellido = new char();
  cout << "                                             cual es el nombre del jugador" << endl;
  cout<<"                                             ";cin >> jugador->nombre;
  cout << "                                             cual es el apellido de: " << jugador->nombre << endl;
  cout<<"                                             ";cin >> jugador->apellido;
  insertarNodo<sJugador *>(jugadores, jugador);
}
void advertencia()
{
  cout << "                                             Antes de jugar tienes que ingresar minimo 2 jugadores" << endl;
}

void comenzarJuego(sLista<sCarta *> *baraja, sLista<sJugador *> *jugadores, int numjug)
{
  cout << "                                             VA A COMENZAR EL JUEGO PREPARENCE JUGADORES" << endl;

  cout << "                                             SE VAN A REPARTIR LAS CARTAS" << endl;

  bool ganador = false;
  /*
  cartas que van a ir poniendo los jugadores cada ves que les toque y 
  si pasa una ronda se debe volver a barajar dicho mazo
  */
  stack<char> cartasDelCentro;

  barajarMasoCartas(baraja); //esta es la baraja del juego la que vamos a usar para los jugadores y juego en si
  do
  {
    /* code */
  } while (ganador == false);
}

void barajarMasoCartas(sLista<sCarta *> *baraja)
{
  cout << "                                             BARAJANDO LAS CARTAS PARA EL JUEGO" << endl;
  cout << endl;
  cout << "                                             REPARTIENDO CARTAS A LOS JUGADORES" << endl;
  cout << endl;
  bool final = false;
  bool repetido = true;
  int repetidos[108];
  //pilas simples nodos
  stack<sCarta *> pila;
  int cartastot = 109;
  int num = 0, i = 0;
  sNodo<sCarta *> *auxi = new sNodo<sCarta *>;
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
          num = rand() % 109;
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
    cout << "Nuestro numero random es: " << num << "       cartas tot= " << cartastot << "        tam pila =" << pila.size() << endl;

    if (cartastot == 0)
    {
      final = true;
    }
    else
    {
      auxi = baraja->cab;
      cartastot = cartastot - 1;
      repetido = true;
    }
  } while (final == false);
}
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