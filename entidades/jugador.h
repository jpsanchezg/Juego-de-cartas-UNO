


void llenarJugadores(sLista<sJugador *> *jugadores, int numjug);

void comerCartasJugador(sNodo<sJugador *> *jugadoresCartas, stack<sCarta *> &pila, int cartasAcomer);

sNodo<sJugador *> *BuscarSiguienteJugador(sNodo<sJugador *> *&jugadores, sLista<sJugador *> *auxi2, bool sentido);

void limpiarJugadores(sNodo<sJugador *> *&jugadores);

void sacarUnaCarta(sLista<sCarta *> *jugadoresCartas, stack<sCarta *> &pila, bool sentido);