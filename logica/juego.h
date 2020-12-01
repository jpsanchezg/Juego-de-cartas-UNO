

//Funciones de logica de juego
void comenzarJuego(sLista<sCarta *> *baraja, sLista<sJugador *> *jugadores);

bool validarjugadas(sNodo<sCarta *> *cartaJugadores, stack<sCarta *> cartasDelCentro);

void eliminarCarta(sLista<sCarta *> *&cartasJug, int numcarta);

sNodo<sCarta *> *CambioDeColor(sNodo<sCarta *> *&cartaJug);

sNodo<sCarta *> *BuscarCartas(sLista<sCarta *> *auxi2, int numcarta);

void llenarArchivoJugadas(ofstream &jugadas, sNodo<sJugador *> *jugador, sNodo<sCarta *> *jugada);

bool contarPuntos(sLista<sJugador *> *jugadores, sNodo<sJugador *> *ganador);

void crearArchivoHtml();

void crearArchivoBinario(sLista<sJugador *> *jugadores);

