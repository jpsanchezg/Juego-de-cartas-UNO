#include <iostream>
#include <string.h>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <windows.h>
using namespace std;

template <class T>
struct sNodo
{
  T dato;
  sNodo<T> *sig;
};

template <class T>
struct sLista
{
  sNodo<T> *cab;
  sNodo<T> *cola;
  int tam;
};

struct sCarta
{
  char *figura;
  int valor;
};

struct sJugador
{
  char *nombre;
  char *apellido;
  sLista<sCarta *> *cartas;
};

template <class T>
sLista<T> *crearLista()
{
  sLista<T> *lista = new sLista<T>;
  lista->cab = NULL;
  lista->tam = 0;
  return lista;
}

template <class T>
bool listaVacia(sLista<T> *lista)
{
  if (lista->tam == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template <class T>
sNodo<T> *crearNodo(T dato)
{
  sNodo<T> *nodo = new sNodo<T>;
  nodo->dato = dato;
  nodo->sig = NULL;
  return nodo;
}

template <class T>
void insertarNodo(sLista<T> *lista, T valor)
{
  sNodo<T> *nodo = crearNodo(valor);
  if (listaVacia(lista) == true)
  {
    lista->cab = nodo;
    lista->cola = nodo;
  }
  else
  {
    lista->cola->sig = nodo;
    lista->cola = nodo;
  }
  lista->tam++;
}

template <class T>
void imprimirListaCartas(sLista<T> *lista)
{
  sNodo<T> *aux = lista->cab;
  while (aux != NULL)
  {
    cout << aux->dato->valor << " " << aux->dato->figura << endl;
    aux = aux->sig;
  }
}

template <typename X>
void insertarNodoInicio(sLista<X> *lista, X persona)
{
  sNodo<X> *nodo = crearNodo<X>(persona);
  if (listaVacia<X>(lista) == true)
  {
    lista->cab = nodo;
  }
  else
  {
    nodo->sig = lista->cab;
    lista->cab = nodo;
  }
  lista->tam++;
}

void llenarListaCartas(sLista<sCarta *> *baraja, int i)
{
  if (i == 80)
  {
    return;
  }
  else
  {
    int f = i / 20;
    int v = (i % 9);
    int y = (i % 10);
    sCarta *carta = new sCarta;
    carta->figura = new char[15];
    switch (f)
    {
    case 0:
      strcpy(carta->figura, "Azul");
      break;
    case 1:
      strcpy(carta->figura, "Rojo");
      break;
    case 2:
      strcpy(carta->figura, "Amarillo");
      break;
    case 3:
      strcpy(carta->figura, "Verde");
      break;
    default:
      break;
    };
    if (f >= 10)
    {
      carta->valor = y;
    }else{
      carta->valor = v+1;
    }
    

    insertarNodo<sCarta *>(baraja, carta);
    llenarListaCartas(baraja, i + 1);
  }
  return;
}
void llenarJugadores(sLista<sJugador *> *jugadores)
{
  sJugador *jugador = new sJugador;
  cout << "cual es el nombre del jugador" << endl;
  cin >> jugador->nombre;
  cout << "cual es el apellido de: " << jugador->nombre << endl;
  cin >> jugador->apellido;
  insertarNodo<sJugador *>(jugadores, jugador);
}
void advertencia()
{
  cout << "Antes de jugar tienes que ingresar minimo 2 jugadores" << endl;
}

void menu()
{
  cout << "MENE DE JUEGO UNO" << endl;
  cout << "1. Jugar" << endl;
  cout << "2. Ver instrucciones de juego" << endl;
  cout << "3. Imprimir lista de jugadores" << endl;
  cout << "4. Imprimir lista de cartas" << endl;
  cout << "5. salir" << endl;
}

int main()
{

  sLista<sJugador *> *jugadores = crearLista<sJugador *>();
  sLista<sCarta *> *baraja = crearLista<sCarta *>();
  bool salir = false;
  int op = 0, numjug = 0;
  ifstream archi;
  string texto;
  llenarListaCartas(baraja, 0);
  do
  {
    menu();
    cin >> op;
    if (op == 1)
    {

      advertencia();
      do
      {
        //lenar jugadores
        llenarJugadores(jugadores);
        numjug++;
      } while (numjug > 2);
    }
    if (op == 2)
    {
      archi.open("reglas.txt", ios::in);
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
    }
    if (op == 4)
    {
      cout << "IMPRIMIENDO LISTA DE CARTAS QUE VAN A ESTAR EN EN EL JUEGO " << endl;
      imprimirListaCartas<sCarta *>(baraja);
    }
    if (op == 5)
    {
      salir = true;
    }
  } while (salir == false);
  cout << "JUEGO FINALIZADO EXITOSAMENTE" << endl;
}