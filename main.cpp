#include <iostream>
#include <string.h>
using namespace std;

template <class T>
struct sNodo{
    T dato;
    sNodo<T>* sig;
};

template <class T>
struct sLista{
  sNodo<T>* cab;
  sNodo<T>* cola;
  int tam;
};

struct sCarta{
    char* figura;
    int valor;
};

struct sJugador{
    char* nombre;
    char* apellido;
    sLista< sCarta * >* cartas;
};

template <class T>
sLista<T>* crearLista(){
  sLista<T>* lista = new sLista<T>;
  lista -> cab = NULL;
  lista -> tam = 0;
  return lista;
}

template <class T>
bool listaVacia(sLista<T>* lista){
  if (lista->tam==0){
     return true;
  }
  else{
    return false;
  }
}

template <class T>
sNodo<T>* crearNodo(T dato){
    sNodo<T>* nodo= new sNodo<T>;
    nodo -> dato = dato;
    nodo -> sig = NULL;
    return nodo;
}

template <class T>
void insertarNodo(sLista<T>* lista, T valor){
  sNodo<T>* nodo=crearNodo(valor);
  if (listaVacia(lista)==true){
    lista->cab=nodo;
    lista->cola=nodo;
  }
  else{
    lista->cola->sig=nodo;
    lista->cola=nodo;
  }
  lista->tam++;
}

template <class T>
void  imprimirListaCartas(sLista<T>* lista){
  sNodo<T>* aux= lista -> cab;
  while(aux!= NULL){
    cout << aux -> dato -> valor << " " << aux -> dato -> figura << endl;
    aux = aux -> sig;
  }
}

template<typename X>
void insertarNodoInicio(sLista<X>* lista, X persona){
	sNodo<X>* nodo = crearNodo<X>(persona);
	if(listaVacia<X>(lista)==true){
		lista -> cab = nodo;
	}
	else{
		nodo -> sig = lista -> cab;
		lista -> cab = nodo;
	}
	lista->tam++;
}

void llenarListaCartas(sLista<sCarta*>* baraja, int i){
    if (i == 40){
        return;
    }
    else{
        int f = i / 10; 
        int v = (i % 10) + 1;
        sCarta* carta = new sCarta;
        carta -> figura = new char[15];
        switch (f)
        {
        case 0:strcpy(carta -> figura, "Azul");
            break;
        case 1:strcpy(carta -> figura, "Verde");
            break;
        case 2:strcpy(carta -> figura, "Rojo");
            break;
        case 3:strcpy(carta -> figura, "Amarillo");
            break;
        default:
            break;
        };
        carta -> valor = v;   
        insertarNodo<sCarta *>(baraja,carta);
        llenarListaCartas(baraja,i + 1);
    }
    return;
}

int main(){
    sLista< sJugador * >* jugadores = crearLista< sJugador * >();
    sLista< sCarta * >* baraja = crearLista< sCarta * >();
    llenarListaCartas(baraja,0);
    imprimirListaCartas<sCarta*>(baraja);
    
    
    //Crear jugador 
    sJugador* jugador = new sJugador;
    jugador -> nombre = new char[10];
    strcpy (jugador -> nombre, "Andres");
    jugador -> apellido = new char[10];
    strcpy (jugador -> apellido, "Garcia");
    jugador -> cartas = crearLista< sCarta *>();
    sCarta * cartaJugador = new sCarta;
    cartaJugador -> figura = new char[10];
    strcpy (cartaJugador -> figura, "Picas");
    cartaJugador -> valor = 8;
}