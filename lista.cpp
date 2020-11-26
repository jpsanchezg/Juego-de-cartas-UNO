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
  }
  else
  {
    lista->cola->sig = nodo;
    lista->cola = nodo;
  }
  lista->tam++;
}

template <class H>
bool insertarNodoCartasaJugador(sLista<H> *lista, H valor)
{
  sNodo<H> *nodo = crearNodo(valor);
  cout << "estoy daentro del insertart broaso   " << nodo->dato->color << endl;
  if (listaVacia(lista) == true)
  {
    lista->cab = nodo;
    lista->cola = nodo;
    lista->tam++;
    return true;
  }
  else
  {

    lista->cola->sig = nodo;
    lista->cola = nodo;
    cout << "color de la carta en la lista" << lista->cola->dato->color << endl;
    lista->tam++;
    return true;
  }

  return false;
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
  int i = 0;
  sNodo<T> *node = lista->cola;
/*
  if (lista)
    if (lista->cab)
      node = lista->cola;
    else
      return;
  else
    return;
*/
  while (node != NULL)
  {
    cout << "222  " << node->dato->nombre << node->dato->apellido << endl;
    node = node->atrs;
  }
}
template <typename V>
void insertarNodojugador(sLista<V> *lista, V valor)
{

  /*sNodo<V> *new_node = crearNodo(valor);

  new_node->sig = lista->cab;
  new_node->atrs = NULL;
  if (lista->cab != NULL)
    lista->cab->atrs = new_node;
  lista->cab = new_node;
  lista->cola = new_node;

  sNodo<V> *node = crearNodo(valor);
  sNodo<V> *tmp;

  if (lista->cab == NULL)
  {
    lista->cab = node;
    lista->cola = node;
  }
  else
  {
    tmp = lista->cola;
    lista->cola = node;
    node->sig = NULL;
    node->atrs = tmp;
    tmp->sig = node;
  }*/

  sNodo<V> *newNode  = crearNodo(valor);
    //If list is empty  
    if(lista->cab == NULL) {  
        //Both head and tail will point to newNode  
        lista->cab = lista->cola = newNode;  
        //head's previous will point to NULL  
        lista->cab->sig = NULL;  
        //tail's next will point to NULL, as it is the last node of the list  
        lista->cola->sig = NULL;  
    }  
    else {  
        //newNode will be added after tail such that tail's next will point to newNode  
        lista->cola->sig = newNode;  
        //newNode's previous will point to tail  
        newNode->atrs = lista->cola;  
        //newNode will become new tail  
        lista->cola = newNode;  
        //As it is last node, tail's next will point to NULL  
        lista->cola->sig = NULL;  
    }  
}

/*template <typename V>
void insertarPrimerjugador(sLista<V> *lista, V valor){
  	sNodo<V>* temp = crearNodo(valor);
    lista->cab = nodo;
    lista->cola = nodo;
    lista->tam++;
    return true;
}*/

template <typename T>
void imprimirCartasJugador(sLista<T> *auxi2)
{
  sNodo<T> *cartas;
  cartas = auxi2->cab;
  while (cartas != NULL)
  {
    cout << "                                               Carta: " << cartas->dato->color << "          Valor: " << cartas->dato->valor << " Numero: " << cartas->dato->numero << endl;
    cartas = cartas->sig;
  }
}
