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

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"

#define ANSI_COLOR_RESET "\x1b[0m"
//#include "cartas.cpp"

#include <stack>

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
  int puntos;
  int numjug;
  sLista<sCarta *> *cartas;
};

//menu
void menu()
{

  cout << ANSI_COLOR_RED << "                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << ANSI_COLOR_RESET << endl;
  cout << ANSI_COLOR_RED << "                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << ANSI_COLOR_YELLOW << "ooooooooooooo" << ANSI_COLOR_RED << "%%%%%%%%%" << ANSI_COLOR_RESET << endl;
  cout << ANSI_COLOR_RED << "                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << ANSI_COLOR_YELLOW << "%ooooooooooooooooooo" << ANSI_COLOR_RED << "%%%%%%" << endl;
  cout << ANSI_COLOR_RED << "                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%/%%%%%%" << ANSI_COLOR_YELLOW << "%.oooo*" << ANSI_COLOR_RED << "%%%%%###%" << ANSI_COLOR_YELLOW << "ooooooo" << ANSI_COLOR_RED << "%%%%" << endl;
  cout << ANSI_COLOR_RED << "                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << ANSI_COLOR_BLUE << "%NNNNNNN" << ANSI_COLOR_RED << "%%%%" << ANSI_COLOR_YELLOW << "&oooooo&" << ANSI_COLOR_RED << "%%%%&&&@##%" << ANSI_COLOR_YELLOW << "oooooo" << ANSI_COLOR_RED << "%%%" << endl;
  cout << ANSI_COLOR_RED << "                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << ANSI_COLOR_BLUE << "&&NNNNNNN" << ANSI_COLOR_RED << "%%&&" << ANSI_COLOR_YELLOW << "ooooo" << ANSI_COLOR_RED << "%%%%%%%%%%&%&" << ANSI_COLOR_YELLOW << "/ooooo" << ANSI_COLOR_RED << "%%%" << endl;
  cout << ANSI_COLOR_RED << "                  %%%%%%%%%%%%%%%%%%%%%%%%%%" << ANSI_COLOR_BLUE << "%NNNNNNNN" << ANSI_COLOR_RED << "%%%%%&&" << ANSI_COLOR_BLUE << "##NNNNNN" << ANSI_COLOR_RED << "%%%" << ANSI_COLOR_YELLOW << "oooooo" << ANSI_COLOR_RED << "%%%%%%%%%%&&&" << ANSI_COLOR_YELLOW << "ooooo" << ANSI_COLOR_RED << "%%%" << endl;
  cout << ANSI_COLOR_RED << "                  %%%%%%%%%%%%%%%%%%%" << ANSI_COLOR_GREEN << "UUUUUU&" << ANSI_COLOR_RED << "((" << ANSI_COLOR_BLUE << "NNNNNNNNNNN" << ANSI_COLOR_RED << "%%%&%%" << ANSI_COLOR_BLUE << "NNNNNN" << ANSI_COLOR_RED << "@%(" << ANSI_COLOR_YELLOW << "oooooo" << ANSI_COLOR_RED << "%%%%%%%%%&&" << ANSI_COLOR_YELLOW << "oooooo" << ANSI_COLOR_RED << "%%%" << endl;
  cout << ANSI_COLOR_RED << "                  %%%%%%%%%%%%%%%%%%" << ANSI_COLOR_GREEN << "(UUUUUUU" << ANSI_COLOR_RED << "&(" << ANSI_COLOR_BLUE << "NNNNNNNNNNNNNNN&" << ANSI_COLOR_RED << "%%" << ANSI_COLOR_BLUE << "NNNNNN" << ANSI_COLOR_RED << "#/(" << ANSI_COLOR_YELLOW << "oooooooo" << ANSI_COLOR_RED << "%%%%%" << ANSI_COLOR_YELLOW << "oooooooo" << ANSI_COLOR_RED << "%%%%" << endl;
  cout << ANSI_COLOR_RED << "                  %%%%%%" << ANSI_COLOR_GREEN << "UUUUU" << ANSI_COLOR_RED << "%%%%%%%%%" << ANSI_COLOR_GREEN << "UUUUUUU" << ANSI_COLOR_RED << "&((" << ANSI_COLOR_BLUE << "NNNNNNNNNNNNNNNNNNNNNNN" << ANSI_COLOR_RED << "&////" << ANSI_COLOR_YELLOW << "oooooooooooooooo" << ANSI_COLOR_RED << "&%%%%%" << ANSI_COLOR_RESET << endl;
  cout << ANSI_COLOR_RED << "                  %%%%" << ANSI_COLOR_GREEN << "#UUUUUUU" << ANSI_COLOR_RED << "%%%%%%%&" << ANSI_COLOR_GREEN << "#UUUUUUU" << ANSI_COLOR_RED << "&##" << ANSI_COLOR_BLUE << "NNNNNN" << ANSI_COLOR_RED << "(((#/" << ANSI_COLOR_BLUE << "NNNNNNNNNNNN" << ANSI_COLOR_RED << "&&(##" << ANSI_COLOR_YELLOW << "oooooooooooooo" << ANSI_COLOR_RED << "%%%%%%%" << endl;
  cout << ANSI_COLOR_RED << "                  %%" << ANSI_COLOR_CYAN << "%&%#" << ANSI_COLOR_GREEN << "UUUUUUU" << ANSI_COLOR_RED << "%%%%%%" << ANSI_COLOR_CYAN << "&&##" << ANSI_COLOR_GREEN << "UUUUUU" << ANSI_COLOR_RED << "&#%" << ANSI_COLOR_BLUE << "NNNNNN" << ANSI_COLOR_RED << "&&###%#" << ANSI_COLOR_BLUE << "NNNNNNNNNN" << ANSI_COLOR_RED << "%&&&&%%%%" << ANSI_COLOR_YELLOW << "oooooo" << ANSI_COLOR_RED << "%%%%%%%%%%" << endl;
  cout << ANSI_COLOR_RED << "                  %%%%" << ANSI_COLOR_CYAN << "&##," << ANSI_COLOR_GREEN << "UUUUUU" << ANSI_COLOR_RED << "%%%%%%%%%%" << ANSI_COLOR_GREEN << "UUUUUU" << ANSI_COLOR_CYAN << "&%%" << ANSI_COLOR_BLUE << "NNNNNN" << ANSI_COLOR_RED << "%%%%%%%%%%" << ANSI_COLOR_BLUE << "NNNNNNN" << ANSI_COLOR_RED << "%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  cout << ANSI_COLOR_RED << "                  %%%%" << ANSI_COLOR_CYAN << "%&##," << ANSI_COLOR_GREEN << "UUUUUU" << ANSI_COLOR_RED << "%%%%%%%%%" << ANSI_COLOR_GREEN << "&UUUUUU" << ANSI_COLOR_CYAN << "&" << ANSI_COLOR_RED << "%%" << ANSI_COLOR_BLUE << "NNNNNN" << ANSI_COLOR_RED << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  cout << ANSI_COLOR_RED << "                  %%%%%%" << ANSI_COLOR_CYAN << "&##*" << ANSI_COLOR_GREEN << "UUUUU" << ANSI_COLOR_RED << "%%%%%%%&&" << ANSI_COLOR_GREEN << "UUUUUUU" << ANSI_COLOR_CYAN << "&&" << ANSI_COLOR_RED << "%%" << ANSI_COLOR_BLUE << "NNNNNN" << ANSI_COLOR_RED << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  cout << ANSI_COLOR_RED << "                  %%%%%%" << ANSI_COLOR_CYAN << "%&#/" << ANSI_COLOR_GREEN << "UUUUUUU" << ANSI_COLOR_RED << "%%%%%" << ANSI_COLOR_GREEN << "UUUUUUUU" << ANSI_COLOR_RED << "%%&&%%/(%%&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  cout << ANSI_COLOR_RED << "                  %%%%%%%%" << ANSI_COLOR_CYAN << "&/(" << ANSI_COLOR_GREEN << "UUUUUUUUUUUUUUUUUU" << ANSI_COLOR_RED << "%%%%" << ANSI_COLOR_CYAN << "&&&&&&" << ANSI_COLOR_RED << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  cout << ANSI_COLOR_RED << "                  %%%%%%%%%" << ANSI_COLOR_CYAN << "&&#" << ANSI_COLOR_GREEN << "UUUUUUUUUUUUUU" << ANSI_COLOR_RED << "&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  cout << ANSI_COLOR_RED << "                  %%%%%%%%%%%" << ANSI_COLOR_CYAN << "&&&&%&&%&&&&&&" << ANSI_COLOR_RED << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  cout << ANSI_COLOR_RED << "                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << ANSI_COLOR_RESET << endl;
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
void comenzarJuego(sLista<sCarta *> *baraja, sLista<sJugador *> *jugadores);
void barajarMasoCartas(sLista<sCarta *> *baraja, stack<sCarta *> &pila);
void repartir_cartas(sLista<sJugador *> *jugadores, stack<sCarta *> &pila);
void llenarJugadores(sLista<sJugador *> *jugadores, int numjug);
void comerCartasJugador(sNodo<sJugador *> *jugadoresCartas, stack<sCarta *> &pila, int cartasAcomer);
bool validarjugadas(sNodo<sCarta *> *cartaJugadores, char *color);
void eliminarCarta(sLista<sCarta *> *&cartasJug, int numcarta);
sNodo<sCarta *> *CambioDeColor(sNodo<sCarta *> *&cartaJug);
sNodo<sCarta *> *BuscarCartas(sLista<sCarta *> *auxi2, int numcarta);
sNodo<sJugador *> *BuscarSiguienteJugador(sNodo<sJugador *> *&jugadores, sLista<sJugador *> *auxi2, bool sentido);
void llenarArchivoJugadas(ofstream &jugadas, sNodo<sJugador *> *jugador, sNodo<sCarta *> *jugada);
bool contarPuntos(sLista<sJugador *> *jugadores, sNodo<sJugador *> *ganador);
void crearArchivoHtml();
void crearArchivoBinario(sLista<sJugador *> *jugadores);
void limpiarJugadores(sLista<sJugador *> *&jugadores);

//funciones prototipo
void imprimirCartasJugadors(sLista<sCarta *> *auxi2);
void cambiarposiz(sLista<sJugador *> *&auxi2, int numjug);
void cambiarposder(sLista<sJugador *> *&auxi2, int numjug);

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
              comenzarJuego(baraja, jugadores);
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
void advertencia()
{
  cout << "                                             Antes de jugar tienes que ingresar minimo 2 jugadores" << endl;
}

//Funcion principal del juego aca esta toda la logica del juego
void comenzarJuego(sLista<sCarta *> *baraja, sLista<sJugador *> *jugadores)
{
  system("cls");
  cout << "                                             VA A COMENZAR EL JUEGO PREPARENCE JUGADORES" << endl;
  Sleep(2000);

  ofstream jugadas("Jugadas.txt", ios::app);
  ifstream grito;
  jugadas << "Jugador" << '\t' << '\t' << "Jugada" << endl;
  bool ganador = false;
  bool cartavalidada;
  bool sentido = false; // si el sentido es FALSE va a la derecha si es TRUE va a la izquierda
  char *color;
  stack<sCarta *> cartasDelCentro;
  stack<sCarta *> barajaEnJuego;
  sNodo<sJugador *> *normalJugadores;
  sNodo<sJugador *> *sentidojugadores;
  sLista<sCarta *> *auxi2;
  sLista<sJugador *> *listajugadores;
  sLista<sJugador *> *copiasegura;
  copiasegura = jugadores;
  listajugadores = jugadores;
  sNodo<sCarta *> *cartajug;
  barajarMasoCartas(baraja, barajaEnJuego);
  cout << "                                             SE VAN A REPARTIR LAS CARTAS" << endl;
  repartir_cartas(jugadores, barajaEnJuego);
  Beep(1000, 10);

  Sleep(2500);
  system("cls");

  int numcarta = 0, cartasCentro = 0, comecartas = 0, sentidoint = 0;
  bool bloqueo = false;
  bool aceptada = false;
  bool sentidonuevo;
  bool puntos;
  bool cabeza = false;
  bool cambio = false;
  int opcc = 0;
  char *colordelacartajugador;
  int opcart = 0;
  int indi = 0;
  normalJugadores = jugadores->cab;
  cout << "                                                JUGADORES PREPARENCE QUE EL JUEGO VA A COMENZAR" << endl;
  do
  {

    aceptada = false;
    if (!sentido)
    {
      normalJugadores = listajugadores->cab;
    }
    if (sentido)
    {
      normalJugadores = listajugadores->cola;
    }
    while (normalJugadores != NULL)
    {
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
          if (numcarta == 109)
          {
            //system("cls");
            if (!barajaEnJuego.empty())
            {
              comerCartasJugador(normalJugadores, barajaEnJuego, 1);
            }
            else
            {
              cout << "                                                  YA SE ACABARON LAS CARTAS PARA TOMAR";
              cout << "                                                  SE VAN A TOMAR LAS CARTAS DEL CENTRO";
            }
            aceptada = false;
          }
          else
          {
            cartajug = BuscarCartas(normalJugadores->dato->cartas, numcarta);
            colordelacartajugador = cartajug->dato->color;
            if (cartasCentro == 0)
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
              if (!aceptada)
              {
                cartasDelCentro.push(cartajug->dato);
                eliminarCarta(normalJugadores->dato->cartas, numcarta);
                cout << "TAM DE LAS CARTAS DE ESTE JUGADOR : " << normalJugadores->dato->cartas->tam << endl;
                color = cartajug->dato->color;
                aceptada = true;
              }
            }
            if (cartasCentro > 0)
            {
              cartavalidada = validarjugadas(cartajug, color);
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
                  color = cartajug->dato->color;
                  cartasDelCentro.push(cartajug->dato);
                  eliminarCarta(normalJugadores->dato->cartas, numcarta);
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
                  comecartas = 4;
                  Nodojugador = BuscarSiguienteJugador(normalJugadores, jugadores, sentido);
                  comerCartasJugador(Nodojugador, barajaEnJuego, comecartas);
                  aceptada = true;
                }
              }
              if (!cartavalidada && !aceptada)
              {
                cout << "la carta es invalida por el color que tomaste escoge otra...." << endl;
              }
            }
            if (normalJugadores->dato->cartas->tam == 1)
            {
              string opc;
              char *linea;
              grito.open("grita.txt", ios::out);
              while (grito.eof())
              {
                grito.getline(linea, 500);
                cout << linea << endl;
              }
              grito.close();

              cin >> opc;
              if (opc == "uno" || opc == "UNO")
              {
                aceptada = true;
              } //recordar si no grita uno se tiene que comer dos cartas
            }
            if (normalJugadores->dato->cartas->tam == 0)
            {
              //Diseño aparece el logo uno en ascci todo bonito
              puntos = contarPuntos(jugadores, normalJugadores);
              if (puntos == true)
              {
                cout << "el ganador de esta partida es: " << normalJugadores->dato->nombre << endl;
                crearArchivoBinario(jugadores);
                crearArchivoHtml();
              }
              else
              {
                cout << " SE VA A JUGAR OTRA RONDA ASI QUE SE VA A REINICIAR TODO" << endl;
                comenzarJuego(baraja, jugadores);
                limpiarJugadores(jugadores);
              }
              //se reinicia la ronda?
              aceptada = true;
              ganador = true;
            }
          }
        }
      } while (aceptada == false);

      llenarArchivoJugadas(jugadas, normalJugadores, cartajug);
      cout << "                                               LA CARTA QUE ESTA EN EL CENTRO ES: "
           << " COLOR: " << cartasDelCentro.top()->color << " VALOR: " << cartasDelCentro.top()->valor << " taman: " << cartasDelCentro.size() << endl;
      cout << endl;
      if (!ganador)
      {
        if (bloqueo && !sentido)
        {
          sNodo<sJugador *> *Nodojugador;
          Nodojugador = BuscarSiguienteJugador(normalJugadores, listajugadores, sentido);
          cout << "                                               JUGADOR BLOQUEADO ES: " << Nodojugador->dato->nombre << endl;
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
          Nodojugador = BuscarSiguienteJugador(normalJugadores, listajugadores, sentido);
          cout << "                                               JUGADOR BLOQUEADO ES: " << Nodojugador->dato->nombre << endl;
          normalJugadores->atrs = Nodojugador;

          normalJugadores = normalJugadores->atrs;
          aceptada = false;
          bloqueo = false;
        }
        if (!bloqueo && sentido)
        {

          if (sentidoint == 1)
          {
            normalJugadores = listajugadores->cola;
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
        cartasCentro++;
      }
    }

  } while (ganador != true);
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
      verificador = insertarNodoCartasaJugador<sCarta *>(jugadoresCartas->dato->cartas, carta);
      pila.pop();
    }
    else
    {
      verificador = insertarNodoCartasaJugador<sCarta *>(jugadoresCartas->dato->cartas, carta);
      pila.pop();
    }
  }
}

//Funcion validar jugadas
bool validarjugadas(sNodo<sCarta *> *cartaJugadores, char *color)
{
  if (strcmp(cartaJugadores->dato->color, color) == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
  return false;
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
      cout << endl;
      cout << endl;
      cout << "                                               Nombre del siguiente jugador al que se va a comer las cartas es: " << jugadores->sig->dato->nombre << endl;
      cout << endl;
      cout << endl;
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
      cout << endl;
      cout << endl;
      cout << "                                               Nombre del siguiente jugador al que se va a comer las cartas es: " << jugadores->atrs->dato->nombre << endl;
      cout << endl;
      cout << endl;
      return jugadores->atrs;
    }
  }

  return NULL;
}

//funcion agregar jugada al archivo texto
void llenarArchivoJugadas(ofstream &jugadas, sNodo<sJugador *> *jugador, sNodo<sCarta *> *jugada)
{
  jugadas << jugador->dato->nombre << " " << jugador->dato->apellido << " \t\t" << jugada->dato->color << ", " << jugada->dato->valor << endl;
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
void limpiarJugadores(sLista<sJugador *> *&jugadores)
{
  while (jugadores != NULL)
  {
    jugadores->cab->dato->cartas = crearLista<sCarta *>();
    jugadores->cab = jugadores->cab->sig;
  }
}