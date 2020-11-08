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
void insertarNodo(sLista<T> *lista, T valor)
{
  sNodo<T> *nodo = crearNodo(valor);
  sNodo<T> *p = NULL;
  if (listaVacia(lista) == true)
  {
    lista->cab = nodo;
    lista->cola = nodo;
    nodo->atrs = NULL;
  }
  else
  {
    p = lista->cab;
    while (p->sig != NULL)
      p = p->sig;
    p->sig = nodo;
    nodo->atrs = p;
    /*if (nodo != NULL)
    {
      lista->cola->sig = nodo;
    }
    nodo->sig = nodo;
    lista->cab->sig = nodo;
    lista->cab = nodo;*/
    lista->cola->atrs = nodo;
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
  sNodo<T> *aux = lista->cola;
  while (aux != NULL)
  {
    cout << " 222 " << aux->dato->nombre << " " << aux->dato->apellido << "" << endl;
    aux = aux->atrs;
  }
}

template <typename X>
void insertarNodoInicio(sLista<X> *lista, X persona)
{
  sNodo<X> *nodo = crearNodo<X>(persona);
  if (listaVacia<X>(lista) == true)
  {
    lista->cab = nodo;
    lista->cola = nodo;
  }
  else
  {
    nodo->sig = lista->cab;
    lista->cab = nodo;
    nodo->atrs = lista->cola;
    lista->cola = nodo;
  }
  lista->tam++;
}