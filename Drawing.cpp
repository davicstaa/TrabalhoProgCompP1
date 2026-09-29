#include <iostream>
#include "Colors.h"
#include "Drawing.h"
#include <thread>
#include <chrono>
using namespace std::this_thread;
using namespace std::chrono;    
using namespace std;

void Clear() {
    //Função Limpar
	system("cls");
}

void OcultarCursor() {
    //Função responsavél por ocultar o cursor
 cout << "\033[?25l";
}

void MostrarCursor(){
    //Função responsavél por mostrar o cursor
 cout << "\033[?25h";
 
}

void MoveTo(int linha, int coluna) {
    //Move o cursor do terminal para uma coordenada especifica.
 cout << "\033[" << linha << ";" << coluna << "H";
}
void DrawComputer(int linha, int coluna, int cor) {
    Color(cor);

    // 1. Monitor 
    MoveTo(linha, coluna); cout << "\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB"; // Borda de cima
    MoveTo(linha + 1, coluna); cout << "\xBA             \xBA";// Paredes laterais 
    MoveTo(linha + 2, coluna); cout << "\xBA             \xBA";// Paredes laterais 
    MoveTo(linha + 3, coluna); cout << "\xBA             \xBA";// Paredes laterais 
    MoveTo(linha + 4, coluna); cout << "\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC";// Borda de baixo

    // 2. Os pezinhos de ligação 
    MoveTo(linha + 5, coluna + 6); cout << "\xBA\xBA";

    // 3. A caixa inferior
    MoveTo(linha + 6, coluna + 2); cout << "\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB"; // Borda de cima
    MoveTo(linha + 7, coluna + 2); cout << "\xBA         \xBA"; // Parede lateral 
    MoveTo(linha + 8, coluna + 2); cout << "\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC"; // Borda de baixo

    ResetColor();
}
    void DrawHacker(int linha, int coluna, int cor) {
        MoveTo(linha, coluna);
        Color(cor);
        //Linha superior
        cout << "\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB"
            << "    "
            << "\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB";

        MoveTo(linha + 1, coluna);
        cout << "\xBA Packet Content       \xBA"
            << "    "
            << "\xBA Packet Bits          \xBA";

        // Espaço dos monitores 
        MoveTo(linha + 2, coluna); cout << "\xBA                      \xBA    \xBA                      \xBA";
        MoveTo(linha + 3, coluna); cout << "\xBA                      \xBA    \xBA                      \xBA";
        MoveTo(linha + 4, coluna); cout << "\xBA                      \xBA    \xBA                      \xBA";
        MoveTo(linha + 5, coluna); cout << "\xBA                      \xBA    \xBA                      \xBA";
        MoveTo(linha + 6, coluna); cout << "\xBA                      \xBA    \xBA                      \xBA";

        // Fecho dos monitores
        MoveTo(linha + 7, coluna);

        cout << "\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC"
            << "    "
            << "\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC";

        // Pezinhos de suporte de cada monitor
        MoveTo(linha + 8, coluna + 18); cout << "\xBA\xBA";
        MoveTo(linha + 8, coluna + 32); cout << "\xBA\xBA";

        // Base de servidor do Johnny Boy (com as divisórias horizontais)
        MoveTo(linha + 9, coluna + 4);
        cout << "\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB";

        MoveTo(linha + 10, coluna + 4); // Divisória de cima
        cout << "\xCC\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xB9";

        MoveTo(linha + 11, coluna + 4); // Parede central 
        cout << "\xBA                                          \xBA";

        MoveTo(linha + 12, coluna + 4); // Divisória de baixo
        cout << "\xCC\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xB9";

        MoveTo(linha + 13, coluna + 4);
        cout << "\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC";

        ResetColor();
    }
    

void DrawNetwork(int linha , int coluna) {
    //Função responsável pelo desenho da cor cinza 
    Color(DARKGRAY);
  // Parte responsável pela linha cinza de ALice até Johnny.
    MoveTo(linha + 1, coluna); cout << "\xDB\xDB"; 
    MoveTo(linha + 2, coluna); cout << "\xDB\xDB"; 
    MoveTo(linha + 3, coluna); cout << "\xDB\xDB"; 
    MoveTo(linha + 4, coluna); cout << "\xDB\xDB"; 
    MoveTo(linha + 5, coluna); cout << "\xDB\xDB"; 
    MoveTo(linha + 6, coluna); cout << "\xDB\xDB"; 
    MoveTo(linha + 7, coluna); cout << "\xDB\xDB"; 
    MoveTo(linha + 8, coluna); cout << "\xDB\xDB"; 
    MoveTo(linha + 9, coluna); cout << "\xDB\xDB"; 
    MoveTo(linha + 10, coluna); cout << "\xDB\xDB"; 
    MoveTo(linha + 11, coluna); cout << "\xDB\xDB"; 
    MoveTo(linha + 12, coluna); cout << "\xDB\xDB"; 
    MoveTo(linha + 13, coluna); cout << "\xDB\xDB"; 
    MoveTo(linha + 14, coluna); cout << "\xDB\xDB"; 
    MoveTo(linha + 15, coluna); cout << "\xDB\xDB";
    //Virada a direita para chegar ao computador de Johnny.
    MoveTo(linha + 15, coluna + 2); cout << "\xDB\xDB"; 
    MoveTo(linha + 15, coluna + 4); cout << "\xDB\xDB"; 
    MoveTo(linha + 15, coluna + 6); cout << "\xDB\xDB"; 
    MoveTo(linha + 15, coluna + 8); cout << "\xDB\xDB"; 
    MoveTo(linha + 15, coluna + 10); cout << "\xDB\xDB"; 
    MoveTo(linha + 15, coluna + 12); cout << "\xDB\xDB"; 
    MoveTo(linha + 15, coluna + 14); cout << "\xDB\xDB"; 
    MoveTo(linha + 15, coluna + 16); cout << "\xDB\xDB"; 
    MoveTo(linha + 15, coluna + 18); cout << "\xDB\xDB"; 
    MoveTo(linha + 15, coluna + 20); cout << "\xDB\xDB";
    MoveTo(linha + 15, coluna + 22); cout << "\xDB\xDB";

    //Parte Responsavél pelo rede de Bob até Johnny.
    int cBob = coluna + 90;
    MoveTo(linha + 1, cBob); cout << "\xDB\xDB";
    MoveTo(linha + 2, cBob); cout << "\xDB\xDB";
    MoveTo(linha + 3, cBob); cout << "\xDB\xDB";
    MoveTo(linha + 4, cBob); cout << "\xDB\xDB";
    MoveTo(linha + 5, cBob); cout << "\xDB\xDB";
    MoveTo(linha + 6, cBob); cout << "\xDB\xDB";
    MoveTo(linha + 7, cBob); cout << "\xDB\xDB";
    MoveTo(linha + 8, cBob); cout << "\xDB\xDB";
    MoveTo(linha + 9, cBob); cout << "\xDB\xDB";
    MoveTo(linha + 10, cBob); cout << "\xDB\xDB";
    MoveTo(linha + 11, cBob); cout << "\xDB\xDB";
    MoveTo(linha + 12, cBob); cout << "\xDB\xDB";
    MoveTo(linha + 13, cBob); cout << "\xDB\xDB";
    MoveTo(linha + 14, cBob); cout << "\xDB\xDB";
    MoveTo(linha + 15, cBob); cout << "\xDB\xDB";

    //Virada a Esquerda para chegar ao computador de Johnny.
    MoveTo(linha + 15, cBob - 2); cout << "\xDB\xDB";
    MoveTo(linha + 15, cBob - 4); cout << "\xDB\xDB";
    MoveTo(linha + 15, cBob - 6); cout << "\xDB\xDB";
    MoveTo(linha + 15, cBob - 8); cout << "\xDB\xDB";
    MoveTo(linha + 15, cBob - 10); cout << "\xDB\xDB";
    MoveTo(linha + 15, cBob - 12); cout << "\xDB\xDB";
    MoveTo(linha + 15, cBob - 14); cout << "\xDB\xDB";
    MoveTo(linha + 15, cBob - 16); cout << "\xDB\xDB";
    MoveTo(linha + 15, cBob - 18); cout << "\xDB\xDB";
    MoveTo(linha + 15, cBob - 20); cout << "\xDB\xDB";
    MoveTo(linha + 15, cBob - 22); cout << "\xDB\xDB";

    //Linha da rede de Johnny ao computador da live
    int cLive = coluna + 45; 
    MoveTo(linha + 11, cLive); cout << "\xDB\xDB";
    MoveTo(linha + 10, cLive); cout << "\xDB\xDB";
    MoveTo(linha + 9, cLive); cout << "\xDB\xDB"; 
    MoveTo(linha + 8, cLive); cout << "\xDB\xDB";
    MoveTo(linha + 7, cLive); cout << "\xDB\xDB";
    MoveTo(linha + 6, cLive); cout << "\xDB\xDB";
    MoveTo(linha + 5, cLive); cout << "\xDB\xDB";
    MoveTo(linha + 4, cLive); cout << "\xDB\xDB";
    MoveTo(linha + 3, cLive); cout << "\xDB\xDB";
    MoveTo(linha + 2, cLive); cout << "\xDB\xDB";
    MoveTo(linha + 1, cLive); cout << "\xDB\xDB";
   

}void DrawFrame() {

     //função que desenha as bordas cinzas 

    MoveTo(1, 1);
    Color(DARKGRAY);
    
    //Linha Superior da borda
    cout << "\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB";

    
    Colors(WHITE, DARKGRAY, true);
    cout << " LIVE PiX ";

    
    ResetColor();
    Color(DARKGRAY);
    cout << "\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB";
    cout << "";
    ResetColor(); 
   
    //Linha esquerda da borda
    MoveTo(2, 1);
    Color(DARKGRAY);
    cout << "\xDB";
    
    MoveTo(3, 1);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(4, 1);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(5, 1);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(6, 1);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(7, 1);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(8, 1);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(9, 1);
    Color(DARKGRAY);
    cout << "\xDB";
   
    MoveTo(10, 1);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(11, 1);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(12, 1);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(13, 1);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(14, 1);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(15, 1);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(16, 1);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(17, 1);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(18, 1);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(19, 1);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(20, 1);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(21, 1);
    Color(DARKGRAY);
    cout << "\xDB";


    MoveTo(22, 1);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(23, 1);
    Color(DARKGRAY);
    cout << "\xDB";
    
    MoveTo(24, 1);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(25, 1);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(26, 1);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(27, 1);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(28, 1);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(29, 1);
    Color(DARKGRAY);
    cout << "\xDB";
    
    MoveTo(30, 1);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(31, 1);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(32, 1);
    Color(DARKGRAY);
    cout << "\xDB";

    ResetColor();
    
    // Linha inferior
    MoveTo(32, 1);
    Color(DARKGRAY);

    cout << "\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB";

    //Linha do lado direito da borda
    MoveTo(2, 120);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(3, 120);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(4, 120);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(5, 120);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(6, 120);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(7, 120);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(8, 120);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(9, 120);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(10, 120);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(11, 120);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(12, 120);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(13, 120);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(14, 120);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(15, 120);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(16, 120);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(17, 120);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(18, 120);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(19, 120);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(20, 120);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(21, 120);
    Color(DARKGRAY);
    cout << "\xDB";


    MoveTo(22, 120);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(23, 120);
    Color(DARKGRAY);
    cout << "\xDB";
    MoveTo(24, 120);

    Color(DARKGRAY);

    cout << "\xDB";

    MoveTo(25, 120);
    Color(DARKGRAY);

    cout << "\xDB";

    MoveTo(26, 120);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(27, 120);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(28, 120);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(29, 120);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(30, 120);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(31, 120);
    Color(DARKGRAY);
    cout << "\xDB";

    MoveTo(32, 120);
    Color(DARKGRAY);
    cout << "\xDB";

    ResetColor();  

}


void AnimarAlice(int linha, int coluna) {
    
        Color(YELLOW);
        // 1. Descendo da Alice 
        MoveTo(linha+ 3 ,coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 4, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 5, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 6, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 7, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 8, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 9, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 10, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 11, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 12, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 13, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 14, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 15, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 16, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 17, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        // 2. Virando à direita em direção à lateral do Johnny.
        MoveTo(linha + 17, coluna + 2); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 17, coluna + 4); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 17, coluna + 6); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 17, coluna + 8); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 17, coluna + 10); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 17, coluna + 12); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 17, coluna + 14); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 17, coluna + 16); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 17, coluna + 18); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 17, coluna + 20); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 17, coluna + 22); cout << "\xDB\xDB"; sleep_for(50ms);
        ResetColor();

}
void AnimarBob(int linha, int coluna) {
    
        Color(ORANGE);
        // Descendo do Bob
        MoveTo(linha + 3, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 4, coluna); cout << "\xDB\xDB"; sleep_for(50ms); 
        MoveTo(linha + 5, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 6, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 7, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 8, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 9, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 10, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 11, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 12, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 13, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 14, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 15, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 16, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 17, coluna); cout << "\xDB\xDB"; sleep_for(50ms);

        // Virando à esquerda em direção ao Johnny Boy
        MoveTo(linha + 17, coluna - 2); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 17, coluna - 4); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 17, coluna - 6); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 17, coluna - 8); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 17, coluna - 10); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 17, coluna - 12); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 17, coluna - 14); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 17, coluna - 16); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 17, coluna - 18); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 17, coluna - 20); cout << "\xDB\xDB"; sleep_for(50ms);
        MoveTo(linha + 17, coluna - 22); cout << "\xDB\xDB"; sleep_for(50ms);
        ResetColor();

}
void AnimarJohnny(int origem, int linha, int coluna) {
    // Escolhe a cor baseada em quem enviou a mensagem original

    if (origem == 1) {
       Color(YELLOW);
    }
    else if (origem == 2) {
      Color(ORANGE);
    }
    else {
      Color(BLUE);
    }
      
    // Subindo em direção em direção ao computador da live
    MoveTo(linha + 9, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
    MoveTo(linha + 8, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
    MoveTo(linha + 7, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
    MoveTo(linha + 6, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
    MoveTo(linha + 5, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
    MoveTo(linha + 4, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
    MoveTo(linha + 3, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
    MoveTo(linha + 2, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
    MoveTo(linha + 1 , coluna); cout << "\xDB\xDB"; sleep_for(50ms);
    MoveTo(linha - 0, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
    MoveTo(linha - 1, coluna); cout << "\xDB\xDB"; sleep_for(50ms);
    
    ResetColor();
}
