#include <iostream>
#include <string>
#include <string.h>
#include "lista.h"
#include <stack>

using namespace std;

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
  nodo->atrs = NULL;
  return nodo;
}

template <class T>
void insertarNodoCartas(sLista<T> *lista, T valor)
{
  sNodo<T> *nodo = crearNodo(valor);
  if (listaVacia(lista) == true)
  {
    lista->cab = nodo;
    lista->cola = nodo;
    nodo->atrs = NULL;
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
    cout << aux->dato->valor << " " << aux->dato->color << aux->dato->numero << endl;
    aux = aux->sig;
  }
}

template <class I>
void imprimirListaJugadoresCabezas(sLista<I> *lista)
{
  sNodo<I> *aux = lista->cab;
  while (aux != NULL)
  {
    cout << aux->dato->nombre << " " << aux->dato->apellido << "" << endl;
    aux = aux->sig;
  }
}

template <class I, class J>
void imprimirListaJugadoresCarta(sLista<I> *lista)
{
  sNodo<I> *aux = lista->cab;
  while (aux != NULL)
  {
    cout << aux->dato->nombre << " " << aux->dato->apellido << "" << endl;
    sNodo<J> *auxcarta = aux->dato->cartas->cab;
    while (auxcarta != NULL)
    {
      cout << auxcarta->dato->numero << endl;
      auxcarta = auxcarta->sig;
    }
    aux = aux->sig;
  }
}
template <class T>
void imprimirListaJugadoresColas(sLista<T> *lista)
{
  sNodo<T> *aux;
  sNodo<T> *aux2 = lista->cab;
  while (aux2 != NULL)
  {
    aux = aux2;
    aux2 = aux2->sig;
  }
  while (aux != NULL)
  {
    cout << " 222 " << aux->dato->nombre << " " << aux->dato->apellido << "" << endl;
    aux = aux->atrs;
  }
}
template <typename V>
void insertarNodojugador(sLista<V> *lista, V valor)
{

  sNodo<V> *new_node = crearNodo(valor);

  new_node->sig = lista->cab;
  new_node->atrs = NULL;
  if (lista->cab != NULL)
    lista->cab->atrs = new_node;
  lista->cab = new_node;
  lista->cola = new_node;
}

template <typename X>
void insertarNodoFinal(sLista<X> *lista, X valor)
{
  sNodo<X> *nodo = crearNodo(valor);
  sNodo<X> *aux = lista->cab;
}

template <typename T>
void imprimirCartasJugador(sLista<T> *auxi2)
{
  sNodo<T> *cartas;
  cartas = auxi2->cab;
  while (cartas != NULL)
  {
    cout << "                                               Carta: " << cartas->dato->color << "     Valor: " << cartas->dato->valor << " Numero: " << cartas->dato->numero << endl;
    cartas = cartas->sig;
  }
}

