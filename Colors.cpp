#include <iostream>
#include "Colors.h"
using namespace std;


void Color(int corTexto){
    // Altera a cor do texto impresso no terminal usando codificacão ANSI 0 a 255
    cout << "\033[38;5;" << corTexto << "m";
}

void Colors(int corTexto, int corFundo, bool negrito){
    // Define simultaneamente a cor do texto, a cor do fundo e aplica formatacao em negrito no terminal

    if (negrito)
        cout << "\033[1m";

    cout << "\033[38;5;" << corTexto << "m";
    cout << "\033[48;5;" << corFundo << "m";
}


void ResetColor(){
 //  [0m reseta completamente cor de texto, cor de fundo e negrito 
    cout << "\033[0m";
}
