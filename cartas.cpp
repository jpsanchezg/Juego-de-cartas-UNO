#include <iostream>
#include <string>
#include <string.h>
#include <main.cpp>

using namespace std;

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
                cout<<"hola como estas"<<endl;
            }
            insertarNodo<sCarta *>(baraja, carta);
            llenarListaCartasEspeciales(baraja, i + 1, u);
        }
        else
        {
            int o = i;
            cout << "hola  " << o << endl;
            int f = i / 6;
            cout << f << endl;
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