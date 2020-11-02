#ifndef CARTAS_H_INCLUDED
#define CARTAS_H_INCLUDED

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
    int tam;
};


template <class T>
sLista<T> *crearLista();

template <class T>
bool listaVacia(sLista<T> *lista);

template <class T>
sNodo<T> *crearNodo(T dato);

template <class T>
void insertarNodo(sLista<T> *lista, T valor);

template <class T>
void imprimirListaCartas(sLista<T> *lista);

template <class I>
void imprimirListaJugadores(sLista<I> *lista);

template <typename X>
void insertarNodoInicio(sLista<X> *lista, X persona);

template <typename T>
void crearPilas (sNodo<T> nodo);

#endif // CARTAS_H_INCLUDED