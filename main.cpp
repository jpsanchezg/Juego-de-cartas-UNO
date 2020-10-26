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
#include "cartas.cpp"


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
  char *valor;
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

template <class I>
void imprimirListaJugadores(sLista<I> *lista)
{
  sNodo<I> *aux = lista->cab;
  while (aux != NULL)
  {
    cout << aux->dato->nombre << " " << aux->dato->apellido << endl;
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


void llenarJugadores(sLista<sJugador *> *jugadores)
{
  sJugador *jugador = new sJugador;
  jugador->nombre = new char();
  jugador->apellido = new char();
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
  cout << "MENU DE JUEGO UNO" << endl;
  cout << "1. Jugar" << endl;
  cout << "2. Ver instrucciones de juego" << endl;
  cout << "3. Imprimir lista de jugadores" << endl;
  cout << "4. Imprimir lista de cartas" << endl;
  cout << "5. salir" << endl;
}

void comenzarJuego (){
  cout<<"VA A COMENZAR EL JUEGO PREPARENCE JUGADORES"<<endl;
  cout<<"SE VAN A REPARTIR LAS CARTAS"<<endl;
  repartirCartas();
}

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
    cin >> op;
    if (op == 1)
    {

      advertencia();
      do
      {
        //lenar jugadores
        llenarJugadores(jugadores);

        cout << "VAS A INGRESAR OTRO JUGADOR?" << endl;
        cout << "1. si" << endl;
        cout << "2. no" << endl;
        cin >> opi;
        if (opi == 1)
        {
          numjug++;
        }
        if (opi == 2)
        {
          if (numjug < 2)
          {
            cout << "NO PUEDES JUGAR CON LA CANTIDAD DE JUGADORES QUE TIENES" << endl;
          }
          else if (numjug >=2)
          {
            cout << "QUIERES COMENZAR A JUGAR?" << endl;
            cout << "1. si" << endl;
            cout << "2. no" << endl;
            cin >> opi;
            if (opi == 1)
            {
              comenzarJuego();
            }else{
              nojug = true;
            }
            
          }else{
            nojug = true;
          }
        }
      } while (nojug == false);
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
      cout << "IMPRIMIENDO LISTA DE JUGADORES QUE VAN A ESTAR EN EN EL JUEGO " << endl;
      imprimirListaJugadores<sJugador *>(jugadores);
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