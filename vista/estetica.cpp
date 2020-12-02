#include <iostream>
#include <iomanip>
#include "estetica.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

using namespace std;

void menu()
{

    cout << ANSI_COLOR_RED << "                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << ANSI_COLOR_RESET << endl;
    cout << ANSI_COLOR_RED << "                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << ANSI_COLOR_YELLOW << "ooooooooooooo" << ANSI_COLOR_RED << "%%%%%%%%%" << ANSI_COLOR_RESET << endl;
    cout << ANSI_COLOR_RED << "                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << ANSI_COLOR_YELLOW << "%ooooooooooooooooooo" << ANSI_COLOR_RED << "%%%%%%" << endl;
    cout << ANSI_COLOR_RED << "                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%/%%%%%%" << ANSI_COLOR_YELLOW << "%.oooo*" << ANSI_COLOR_RED << "%%%%%###%" << ANSI_COLOR_YELLOW << "ooooooo" << ANSI_COLOR_RED << "%%%%" << endl;
    cout << ANSI_COLOR_RED << "                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << ANSI_COLOR_BLUE << "%NNNNNNN" << ANSI_COLOR_RED << "%%%%" << ANSI_COLOR_YELLOW << "&oooooo&" << ANSI_COLOR_RED << "%%%%&&&@##%" << ANSI_COLOR_YELLOW << "oooooo" << ANSI_COLOR_RED << "%%%" << endl;
    cout << ANSI_COLOR_RED << "                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << ANSI_COLOR_BLUE << "&&NNNNNNN" << ANSI_COLOR_RED << "%%&&" << ANSI_COLOR_YELLOW << "ooooo" << ANSI_COLOR_RED << "%%%%%%%%%%&%&" << ANSI_COLOR_YELLOW << "/ooooo" << ANSI_COLOR_RED << "%%%" << endl;
    cout << ANSI_COLOR_RED << "                  %%%%%%%%%%%%%%%%%%%%%%%%%%" << ANSI_COLOR_BLUE << "%NNNNNNNN" << ANSI_COLOR_RED << "%%%%%&&" << ANSI_COLOR_BLUE << "##NNNNNN" << ANSI_COLOR_RED << "%%%" << ANSI_COLOR_YELLOW << "oooooo" << ANSI_COLOR_RED << "%%%%%%%%%%&&&" << ANSI_COLOR_YELLOW << "ooooo" << ANSI_COLOR_RED << "%%%" << endl;
    cout << ANSI_COLOR_RED << "                  %%%%%%%%%%%%%%%%%%%" << ANSI_COLOR_GREEN << "UUUUUU&" << ANSI_COLOR_RED << "((" << ANSI_COLOR_BLUE << "NNNNNNNNNNN" << ANSI_COLOR_RED << "%%%&%%" << ANSI_COLOR_BLUE << "NNNNNN" << ANSI_COLOR_RED << "@%(" << ANSI_COLOR_YELLOW << "oooooo" << ANSI_COLOR_RED << "%%%%%%%%%&&" << ANSI_COLOR_YELLOW << "oooooo" << ANSI_COLOR_RED << "%%%" << endl;
    cout << ANSI_COLOR_RED << "                  %%%%%%%%%%%%%%%%%%" << ANSI_COLOR_GREEN << "(UUUUUUU" << ANSI_COLOR_RED << "&(" << ANSI_COLOR_BLUE << "NNNNNNNNNNNNNNN&" << ANSI_COLOR_RED << "%%" << ANSI_COLOR_BLUE << "NNNNNN" << ANSI_COLOR_RED << "#/(" << ANSI_COLOR_YELLOW << "oooooooo" << ANSI_COLOR_RED << "%%%%%" << ANSI_COLOR_YELLOW << "oooooooo" << ANSI_COLOR_RED << "%%%%" << endl;
    cout << ANSI_COLOR_RED << "                  %%%%%%" << ANSI_COLOR_GREEN << "UUUUU" << ANSI_COLOR_RED << "%%%%%%%%%" << ANSI_COLOR_GREEN << "UUUUUUU" << ANSI_COLOR_RED << "&((" << ANSI_COLOR_BLUE << "NNNNNNNNNNNNNNNNNNNNNNN" << ANSI_COLOR_RED << "&////" << ANSI_COLOR_YELLOW << "oooooooooooooooo" << ANSI_COLOR_RED << "&%%%%%" << ANSI_COLOR_RESET << endl;
    cout << ANSI_COLOR_RED << "                  %%%%" << ANSI_COLOR_GREEN << "#UUUUUUU" << ANSI_COLOR_RED << "%%%%%%%&" << ANSI_COLOR_GREEN << "#UUUUUUU" << ANSI_COLOR_RED << "&##" << ANSI_COLOR_BLUE << "NNNNNN" << ANSI_COLOR_RED << "(((#/" << ANSI_COLOR_BLUE << "NNNNNNNNNNNN" << ANSI_COLOR_RED << "&&(##" << ANSI_COLOR_YELLOW << "oooooooooooooo" << ANSI_COLOR_RED << "%%%%%%%" << endl;
    cout << ANSI_COLOR_RED << "                  %%" << ANSI_COLOR_CYAN << "%&%#" << ANSI_COLOR_GREEN << "UUUUUUU" << ANSI_COLOR_RED << "%%%%%%" << ANSI_COLOR_CYAN << "&&##" << ANSI_COLOR_GREEN << "UUUUUU" << ANSI_COLOR_RED << "&#%" << ANSI_COLOR_BLUE << "NNNNNN" << ANSI_COLOR_RED << "&&###%#" << ANSI_COLOR_BLUE << "NNNNNNNNNN" << ANSI_COLOR_RED << "%&&&&%%%%" << ANSI_COLOR_YELLOW << "oooooo" << ANSI_COLOR_RED << "%%%%%%%%%%" << endl;
    cout << ANSI_COLOR_RED << "                  %%%%" << ANSI_COLOR_CYAN << "&##," << ANSI_COLOR_GREEN << "UUUUUU" << ANSI_COLOR_RED << "%%%%%%%%%%" << ANSI_COLOR_GREEN << "UUUUUU" << ANSI_COLOR_CYAN << "&%%" << ANSI_COLOR_BLUE << "NNNNNN" << ANSI_COLOR_RED << "%%%%%%%%%%" << ANSI_COLOR_BLUE << "NNNNNNN" << ANSI_COLOR_RED << "%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << ANSI_COLOR_RED << "                  %%%%" << ANSI_COLOR_CYAN << "%&##," << ANSI_COLOR_GREEN << "UUUUUU" << ANSI_COLOR_RED << "%%%%%%%%%" << ANSI_COLOR_GREEN << "&UUUUUU" << ANSI_COLOR_CYAN << "&" << ANSI_COLOR_RED << "%%" << ANSI_COLOR_BLUE << "NNNNNN" << ANSI_COLOR_RED << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << ANSI_COLOR_RED << "                  %%%%%%" << ANSI_COLOR_CYAN << "&##*" << ANSI_COLOR_GREEN << "UUUUU" << ANSI_COLOR_RED << "%%%%%%%&&" << ANSI_COLOR_GREEN << "UUUUUUU" << ANSI_COLOR_CYAN << "&&" << ANSI_COLOR_RED << "%%" << ANSI_COLOR_BLUE << "NNNNNN" << ANSI_COLOR_RED << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << ANSI_COLOR_RED << "                  %%%%%%" << ANSI_COLOR_CYAN << "%&#/" << ANSI_COLOR_GREEN << "UUUUUUU" << ANSI_COLOR_RED << "%%%%%" << ANSI_COLOR_GREEN << "UUUUUUUU" << ANSI_COLOR_RED << "%%&&%%/(%%&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << ANSI_COLOR_RED << "                  %%%%%%%%" << ANSI_COLOR_CYAN << "&/(" << ANSI_COLOR_GREEN << "UUUUUUUUUUUUUUUUUU" << ANSI_COLOR_RED << "%%%%" << ANSI_COLOR_CYAN << "&&&&&&" << ANSI_COLOR_RED << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << ANSI_COLOR_RED << "                  %%%%%%%%%" << ANSI_COLOR_CYAN << "&&#" << ANSI_COLOR_GREEN << "UUUUUUUUUUUUUU" << ANSI_COLOR_RED << "&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << ANSI_COLOR_RED << "                  %%%%%%%%%%%" << ANSI_COLOR_CYAN << "&&&&%&&%&&&&&&" << ANSI_COLOR_RED << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << ANSI_COLOR_RED << "                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << ANSI_COLOR_RESET << endl;
    cout << endl;
    cout << setw(65) << "MENU DE JUEGO UNO" << endl;
    cout << setfill(' ') << setw(60) << "[1] Jugar" << endl;
    cout << setfill(' ') << setw(81) << "[2] Ver instrucciones de juego"  << endl;
    cout << setfill(' ') << setw(82) << "[3] Imprimir lista de jugadores"  << endl;
    cout << setfill(' ') << setw(79) << "[4] Imprimir lista de cartas" << endl;
    cout << setfill(' ') << setw(60) << "[5] salir" << endl;
}

void advertencia()
{
    cout << "                                             Antes de jugar tienes que ingresar minimo 2 jugadores" << endl;
}