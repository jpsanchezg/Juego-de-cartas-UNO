#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

template <class T>
struct sNodo
{
    T dato;
    sNodo<T> *sig;
    sNodo<T> *atrs;
};

template <class T>
struct sLista
{
    sNodo<T> *cab;
    sNodo<T> *cola;
    int tam;
};


template <class T>
sLista<T> *crearLista();

template <class T>
bool listaVacia(sLista<T> *lista);

template <class T>
sNodo<T> *crearNodo(T dato);

template <class T>
void insertarNodoCartas(sLista<T> *lista, T valor);

template <class T>
void imprimirListaCartas(sLista<T> *lista);

template <class I>
void imprimirListaJugadoresCabezas(sLista<I> *lista);

template <class I,class J>
void imprimirListaJugadoresCarta(sLista<I> *lista);

template <class T>
void imprimirListaJugadoresColas(sLista<T> *lista);

template <typename V>
void insertarNodojugador(sLista<V> *lista, V valor);

template <typename X>
void insertarNodoFinal(sLista<X> *lista, X valor);

template <typename T>
void crearPilas (sNodo<T> nodo);

template<typename T>
void imprimirCartasJugador(sLista<T> *auxi2);

template <class H>
bool insertarNodoCartasaJugador(sLista<H> *lista, H valor);

#endif // CARTAS_H_INCLUDED