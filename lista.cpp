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

template <class I,class J>
void imprimirListaJugadoresCarta(sLista<I> *lista)
{
  sNodo<I> *aux = lista->cab;
  while (aux != NULL)
  {
    cout << aux->dato->nombre << " " << aux->dato->apellido << "" << endl;
    sNodo<J> *auxcarta = aux->dato->cartas->cab;
    while(auxcarta != NULL){
      cout << auxcarta->dato->numero<<endl;
      auxcarta= auxcarta->sig;
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
    cout << aux->dato->nombre << " " << aux->dato->apellido << "" << endl;
    aux = aux->atrs;

  }
}

/*template <class U>
void imprimirListaJugadoresDeCartas(sLista<U> *lista)
{
  sNodo<U> *aux = lista->cab;
  while (aux != NULL)
  {
    cout << aux->dato->nombre << " " << aux->dato->apellido << "" << endl;
    while(aux->dato->cartas->cab != NULL){
      cout << aux->dato->cartas->cab->dato->numero<<endl;
    }
    aux = aux->sig;
  }
}*/

template <typename X>
void insertarNodoInicio(sLista<X> *lista, X persona)
{
  sNodo<X> *nodo = crearNodo<X>(persona);
  if (listaVacia<X>(lista) == true)
  {
    lista->cab= nodo;
    lista->cola = nodo;
  }
  else
  {
    /*nodo->atrs = nodo;
    nodo->sig = lista->cab;
    lista->cab->sig->atrs = nodo;    
    lista->cab->sig = nodo;*/
    nodo->sig= lista->cab;
    nodo->atrs= lista->cab->atrs;
    lista->cab->atrs->sig
  }
  lista->tam++;
}