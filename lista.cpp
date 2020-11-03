#include <iostream>
#include <string>
#include <string.h>
#include "lista.h"
#include <stack>

using namespace std;


template <class T>
bool listaVacia(sLista<T> *lista);
/*Función encargada de definir si una lista está vacía. Para esto, la función recibe una lista.
La función retorna una variable de tipo bool; true si está vacía y false si no está vacía.*/
template <class T>
void insertarNodo(sLista<T> *lista, T valor);
/*Función encargada de insertar un nodo en la lista dada. Para esto, la función recibe una lista y 
y el dato que contendrá el nodo. La función no retorna ningún elemento.*/
template <class T>
void imprimirListaCartas(sLista<T> *lista);
/*Función que imprime la lista dada. Para esto, la función recibe una lista. 
La función no retorna ningún elemento.*/
template <class I>
void imprimirListaJugadores(sLista<I> *lista);
/*Función que imprime la lista dada. Para esto, la función recibe una lista. 
La función no retorna ningún elemento.*/
template <class X>
void insertarNodoInicio(sLista<X> *lista, X persona);
/*Función encargada de insertar un nodo al inicio de la lista dada. Para esto, la función recibe una lista y 
y el dato que contendrá el nodo. La función no retorna ningún elemento.*/

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
  }

  lista->tam++;
}

template <class T>
void imprimirListaCartas(sLista<T> *lista)
{
  sNodo<T> *aux = lista->cab;
  while (aux != NULL)
  {
    cout << aux->dato->valor << " " << aux->dato->color << endl;
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