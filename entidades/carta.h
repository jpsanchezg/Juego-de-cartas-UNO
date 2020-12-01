
//Funciones de llenado de cartas y jugadores
void llenarListaCartas(sLista<sCarta *> *baraja, int i, int u);

void llenarListaCartasEspeciales(sLista<sCarta *> *baraja, int i, int u);

void barajarMasoCartas(sLista<sCarta *> *baraja, stack<sCarta *> &pila);

void repartir_cartas(sLista<sJugador *> *jugadores, stack<sCarta *> &pila);

//Validacion de numeros repetidos
bool numerosRepetidos(int *arreglo, int num, int tam);

void llenarArchivoJugadas(ofstream &jugadas, sNodo<sJugador *> *jugador, sNodo<sCarta *> *jugada);

