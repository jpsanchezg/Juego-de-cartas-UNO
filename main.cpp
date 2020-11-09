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
void comerCartasJugador(sLista<sJugador *> *jugadores, stack<sCarta *> &pila, int cartasAcomer);

//Validacion de numeros repetidos
bool numerosRepetidos(int *arreglo, int num, int tam);

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
  char *color;
  stack<sCarta *> cartasDelCentro;
  stack<sCarta *> pila;
  sLista<sJugador *> *auxi1;
  sLista<sJugador *> *auxi2;
  barajarMasoCartas(baraja, pila);
  repartir_cartas(jugadores, pila);
  int numcarta = 0, cartasCentro = 0, comecartas = 0;
  bool bloqueo = false;
  bool aceptada = false;
  int opcc = 0;
  cout << "                                                JUGADORES PREPARENCE QUE EL JUEGO VA A COMENZAR" << endl;
  //imprimirListaJugadoresCarta<sJugador *, sCarta *>(jugadores);
  auxi2 = jugadores;
  do
  {
    bloqueo = false;
    aceptada = false;
    do
    {
      aceptada = false;
      while (auxi2->cab != NULL)
      {
        cout << "                                               JUGADOR " << auxi2->cab->dato->nombre << " ES SU TURNO " << endl;
        cout << "                                               QUE CARTA QUIERE SACAR" << endl;
        cout << "                                               RECUERDA... SACAS CON EL NUMERO DE LA CARTA" << endl;
        do
        {
          while (auxi2->cab->dato->cartas->cab != NULL)
          {
            cout << "                                               Carta: " << auxi2->cab->dato->cartas->cab->dato->color << "     Valor: " << auxi2->cab->dato->cartas->cab->dato->valor << " Numero: " << auxi2->cab->dato->cartas->cab->dato->numero << endl;
            auxi2->cab->dato->cartas->cab = auxi2->cab->dato->cartas->cab->sig;
          }
          cout << "                                                  CARTA QUE VAS A SACAR ES: ";
          cin >> numcarta;

          while (auxi2->cab->dato->cartas->cab != NULL)
          {
            if (numcarta == auxi2->cab->dato->cartas->cab->dato->numero)
            {
              if (cartasCentro == 0)
              {
                color = auxi2->cab->dato->cartas->cab->dato->color;
              }
              if (auxi2->cab->dato->cartas->cab->dato->valor == "CC")
              {
                cout << "                                               A QUE COLOR QUIERES CAMBIAR...." << endl;
                cout << "                                               [1] ROJO" << endl;
                cout << "                                               [2] AMARILLO" << endl;
                cout << "                                               [3] AZUL" << endl;
                cout << "                                               [4] VERDE" << endl;
                cout << "                                               ESCOGE UNA OPCION:";
                cin >> opcc;
                if (opcc == 1)
                {
                  strcpy(color,"Rojo");
                }
                if (opcc == 2)
                {
                  strcpy(color,"Amarillo");
                }
                if (opcc == 3)
                {
                  strcpy(color,"Azul");
                }
                if (opcc == 4)
                {
                  strcpy(color,"Verde");
                }
              }
              if (auxi2->cab->dato->cartas->cab->dato->color == color)
              {
                if (auxi2->cab->dato->cartas->cab->dato->valor == "M2")
                {
                  comecartas = comecartas + 2;
                  comerCartasJugador(jugadores, pila,comecartas);
                }
              }
              if (auxi2->cab->dato->cartas->cab->dato->valor == "M4")
              {
                comecartas = comecartas + 4;
                comerCartasJugador(jugadores, pila,comecartas);
              }
              if (auxi2->cab->dato->cartas->cab->dato->color == color)
              {
                cartasDelCentro.push(auxi2->cab->dato->cartas->cab->dato);
                delete auxi2->cab->dato->cartas->cab->dato;
                aceptada = true;
              }
              if (auxi2->cab->dato->cartas->cab->dato->color != color)
              {
                cout << "                                               NO PUEDES PONER ESTA CARTA YA QUE NO ES DEL MISMO COLOR ESCOGE OTRA" << endl;
              }
              if (auxi2->cab->dato->cartas->cab->dato->valor == "RT")
              {
                if (sentido == false)
                {
                  cartasDelCentro.push(auxi2->cab->dato->cartas->cab->dato);
                  delete auxi2->cab->dato->cartas->cab->dato;
                  sentido = true;
                  aceptada = true;
                }
                if (sentido == true)
                {
                  cartasDelCentro.push(auxi2->cab->dato->cartas->cab->dato);
                  delete auxi2->cab->dato->cartas->cab->dato;
                  sentido = false;
                  aceptada = true;
                }
              }
            }
          }
        }while (aceptada == false);
        auxi2->cab = auxi2->cab->sig;
      }
    } while (sentido == false);
    cout<<"LA CARTA QUE ESTA EN EL CENTRO ES: "<<" COLOR: "<<cartasDelCentro.top()->color<<"VALOR: "<<cartasDelCentro.top()->valor<<endl;

  } while (ganador != true);
}

//Funcion de comer cartas
void comerCartasJugador(sLista<sJugador *> *jugadores, stack<sCarta *> &pila, int cartasAcomer)
{
}

//Funcion barajar cartastot
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
      //cout<<num<<endl;
    }
  }
  int agregado = 0;
  while (agregado != 108)
  {
    if (numeros[agregado] == auxi->dato->numero)
    {
      pila.push(auxi->dato);
      //cout  << "        cont pila = " << pila.top()->numero<< "        tam pila = " << pila.size() << endl;
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