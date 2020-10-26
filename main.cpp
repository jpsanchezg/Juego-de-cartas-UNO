#include <iostream>
#include <string.h>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <windows.h>
#include <cstdlib>
#include "lista.cpp"


using namespace std;


struct sCarta
{
    char *figura;
    char *valor;
};
struct sJugador
{
  char *nombre;
  char *apellido;
  sLista<sCarta *> *cartas;
};


void llenarJugadores(sLista<sJugador *> *jugadores);
void advertencia();


void menu()
{
  cout << "MENU DE JUEGO UNO" << endl;
  cout << "1. Jugar" << endl;
  cout << "2. Ver instrucciones de juego" << endl;
  cout << "3. Imprimir lista de jugadores" << endl;
  cout << "4. Imprimir lista de cartas" << endl;
  cout << "5. salir" << endl;
}
void llenarListaCartas(sLista<sCarta *> *baraja, int i, int u);
void llenarListaCartasEspeciales(sLista<sCarta *> *baraja, int i, int u);
void comenzarJuego (){
  cout<<"VA A COMENZAR EL JUEGO PREPARENCE JUGADORES"<<endl;
  cout<<"SE VAN A REPARTIR LAS CARTAS"<<endl;
  //repartirCartas();
}

int main()
{

  sLista<sJugador *> *jugadores = crearLista<sJugador *>();
  sLista<sCarta *> *baraja = crearLista<sCarta *>();
  bool salir = false;
  bool nojug = false;
  int op = 0, numjug = 0, opi = 0;
  ifstream archi;
  string texto;
  llenarListaCartas(baraja, 0, 0);
  llenarListaCartasEspeciales(baraja, 0, 0);
  do
  {
    menu();
    cin >> op;
    if (op == 1)
    {

      advertencia();
      do
      {
        //lenar jugadores
        opi=0;
        llenarJugadores(jugadores);

        cout << "VAS A INGRESAR OTRO JUGADOR?" << endl;
        cout << "1. si" << endl;
        cout << "2. no" << endl;
        cin >> opi;
        if (opi == 1)
        {
          numjug++;
        }
        if (opi == 2)
        {
          if (numjug < 2)
          {
            cout << "NO PUEDES JUGAR CON LA CANTIDAD DE JUGADORES QUE TIENES" << endl;
          }
          else if (numjug >=2)
          {
            cout << "QUIERES COMENZAR A JUGAR?" << endl;
            cout << "1. si" << endl;
            cout << "2. no" << endl;
            cin >> opi;
            if (opi == 1)
            {
              comenzarJuego();
            }else{
              nojug = true;
            }
            
          }else{
            nojug = true;
          }
        }
      } while (nojug == false);
    }
    if (op == 2)
    {
      archi.open("reglas.txt", ios::in);
      while (!archi.eof())
      {
        getline(archi, texto);
        cout << texto << endl;
      }
      archi.close();
      Sleep(5000);
      system("cls");
    }
    if (op == 3)
    {
      cout << "IMPRIMIENDO LISTA DE JUGADORES QUE VAN A ESTAR EN EN EL JUEGO " << endl;
      imprimirListaJugadores<sJugador *>(jugadores);
    }
    if (op == 4)
    {
      cout << "IMPRIMIENDO LISTA DE CARTAS QUE VAN A ESTAR EN EN EL JUEGO " << endl;
      imprimirListaCartas<sCarta *>(baraja);
    }
    if (op == 5)
    {
      salir = true;
    }
  } while (salir == false);
  cout << "JUEGO FINALIZADO EXITOSAMENTE" << endl;
}

//Llenar cartas normales del 1 al 9
void llenarListaCartas(sLista<sCarta *> *baraja, int i, int u)
{

    if (i == 76)
    {
        return;
    }
    else
    {
        if (i < 72)
        {
            int f = i / 18;
            int v = (i % 9);
            string s;
            sCarta *carta = new sCarta;
            carta->figura = new char[15];
            carta->valor = new char[2];
            switch (f)
            {
            case 0:
                strcpy(carta->figura, "Azul");
                break;
            case 1:
                strcpy(carta->figura, "Rojo");

                break;
            case 2:
                strcpy(carta->figura, "Amarillo");

                break;
            case 3:
                strcpy(carta->figura, "Verde");

                break;
            default:
                break;
            };
            s = to_string(v + 1);
            strcpy(carta->valor, s.c_str());

            insertarNodo<sCarta *>(baraja, carta);
            llenarListaCartas(baraja, i + 1, u);
        }
        else
        {

            int v = 0;
            //int g = u/19;
            string s;
            sCarta *carta = new sCarta;
            carta->figura = new char[15];
            carta->valor = new char[2];
            switch (u)
            {
            case 0:
                strcpy(carta->figura, "Azul");
                break;
            case 1:
                strcpy(carta->figura, "Rojo");

                break;
            case 2:
                strcpy(carta->figura, "Amarillo");

                break;
            case 3:
                strcpy(carta->figura, "Verde");
                break;
            default:
                break;
            };

            s = to_string(v);
            strcpy(carta->valor, s.c_str());

            insertarNodo<sCarta *>(baraja, carta);
            llenarListaCartas(baraja, i + 1, u + 1);
        }
    }
    return;
}
void llenarListaCartasEspeciales(sLista<sCarta *> *baraja, int i, int u)
{
    if (i == 32)
    {
        return;
    }
    else
    {
        cout << i << endl;
        if (i >= 24)
        {
            int y = i;
            string s;
            sCarta *carta = new sCarta;
            carta->figura = new char[15];
            carta->valor = new char[3];
            //cout<<y<<endl;
            if (y >= 24 && y < 28)
            {

                strcpy(carta->figura, "CambColor");
                strcpy(carta->valor, "CC");
            }
            else if (y >= 28 && y < 32)
            {
                strcpy(carta->figura, "mas 4");
                strcpy(carta->valor, "M4");
                cout << "hola como estas" << endl;
            }
            insertarNodo<sCarta *>(baraja, carta);
            llenarListaCartasEspeciales(baraja, i + 1, u);
        }
        else
        {
            int o = i;
            int f = i / 6;
            int v = 0;
            string s;
            sCarta *carta = new sCarta;
            carta->figura = new char[15];
            carta->valor = new char[3];
            switch (f)
            {
            case 0:
                strcpy(carta->figura, "Azul");
                break;
            case 1:
                strcpy(carta->figura, "Rojo");

                break;
            case 2:
                strcpy(carta->figura, "Amarillo");

                break;
            case 3:
                strcpy(carta->figura, "Verde");

                break;
            default:
                break;
            };
            if (u % 3 == 0)
            {
                strcpy(carta->valor, "M2");
            }
            else if (u % 3 == 1)
            {
                strcpy(carta->valor, "RT");
            }
            else if (u % 3 == 2)
            {
                strcpy(carta->valor, "BQ");
            }
            insertarNodo<sCarta *>(baraja, carta);
            llenarListaCartasEspeciales(baraja, i + 1, u + 1);
        }
    }
    return;
}

//Funcion llenar jugadores
void llenarJugadores(sLista<sJugador *> *jugadores)
{
  sJugador *jugador = new sJugador;
  jugador->nombre = new char();
  jugador->apellido = new char();
  cout << "cual es el nombre del jugador" << endl;
  cin >> jugador->nombre;
  cout << "cual es el apellido de: " << jugador->nombre << endl;
  cin >> jugador->apellido;
  insertarNodo<sJugador *>(jugadores, jugador);
}
void advertencia()
{
  cout << "Antes de jugar tienes que ingresar minimo 2 jugadores" << endl;
}
