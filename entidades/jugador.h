


void llenarJugadores(sLista<sJugador *> *jugadores, int numjug);

void comerCartasJugador(sNodo<sJugador *> *jugadoresCartas, stack<sCarta *> &pila, int cartasAcomer);

sNodo<sJugador *> *BuscarSiguienteJugador(sNodo<sJugador *> *&jugadores, sLista<sJugador *> *auxi2, bool sentido);

void limpiarJugadores(sLista<sJugador *> *&jugadores);