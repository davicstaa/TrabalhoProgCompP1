#include <iostream>
#include <cstdlib>
#include "Colors.h"
#include "Drawing.h"
#include "Network.h"
#include "Binary.h"
using namespace std;

//personagens
#define LIVE 0
#define ALICE 1
#define BOB 2
#define JOHNNY 3

//passando as funções
void Alice();
void Bob();
void Johnny();
void Live();



int main() {
    bool liveIsOn = true;   
    do {
        //limpa tela
        Clear();

        // desenha interface
        DrawComputer(3, 10, YELLOW);
        MoveTo(10, 15); Color(YELLOW); cout << "ALICE";
        DrawComputer(3, 55, GREEN);
        MoveTo(10, 60); Color(GREEN); cout << "@LIVE";
        DrawComputer(3, 100, ORANGE);
        MoveTo(10, 106); Color(ORANGE); cout << "BOB";  
        DrawHacker(14, 36, BLUE);
        MoveTo(25, 57); Color(BLUE); cout << "JOHNNY BOY";
        DrawNetwork(11, 16);
        DrawFrame();

        //realiza simulação
        Alice();
        Johnny();
        Live();
        Bob();
        Johnny();
        Live();

        //finaliza o programa
        MoveTo(31, 52); 
        Colors(WHITE, DARKGRAY, true);
        cout << "  Sair (s/n)? [_]\b\b";
        char choice;
        cin >> choice;
        ResetColor();
        if (choice == 's')
        {
            liveIsOn = false;
            
        }

    } while (liveIsOn);

    
    Clear();
    return 0;
}

void Alice() {
    // Limpa apenas as perguntas 
    MoveTo(28, 2); cout << "                                                                             ";
    MoveTo(29, 2); cout << "                                                                             ";
    //Criando as variáveis dos 5 caracteres e o valor do pix
    char c1, c2, c3, c4, c5;
    int valor;
    //Passando os 5 caracteres digitados 
    MoveTo(28, 2); Color(YELLOW);
    cout << "ALICE - Digite 5 caracteres sem espacos: ";
    cin >> c1 >> c2 >> c3 >> c4 >> c5;
    //Passando o valor do pix
    MoveTo(29, 2); Color(YELLOW);
    cout << "ALICE - Digite o valor do Pix (ate 10000): ";
    cin >> valor;
    //Exibindo na tela do computador de alice o que foi digitado pelo usuário
    MoveTo(4, 11); Color(YELLOW); cout << " > " << c1 << c2 << c3 << c4 << c5 << "      "; MoveTo(4, 24); cout << "\xBA";
    MoveTo(5, 11); cout << " > R$" << valor << "        "; MoveTo(5, 24); cout << "\xBA";
    MoveTo(6, 11); cout << " > Enviado    "; MoveTo(6, 24); cout << "\xBA";
    ResetColor();
    //Empacotando os dados digitados
    unsigned long long pacote = Empacotar(ALICE, LIVE, c1, c2, c3, c4, c5, valor);
    //Passando para função transmitir
    Transmitir(pacote);

    OcultarCursor();
    AnimarAlice(9, 16); // Função da amimação da rede de Alice
    MostrarCursor();
}

void Bob() {

    DrawNetwork(11, 16);
    // Limpa apenas as perguntas lá em baixo
    MoveTo(28, 2); cout << "                                                                             ";
    MoveTo(29, 2); cout << "                                                                             ";

    //Criando as variáveis dos 5 caracteres e o valor do pix
    char c1, c2, c3, c4, c5;
    int valor;
    //Passando os 5 caracteres
    MoveTo(28, 2); Color(ORANGE);
    cout << "BOB - Digite 5 caracteres sem espacos:     ";
    cin >> c1 >> c2 >> c3 >> c4 >> c5;
    //Passando o valor do pix
    MoveTo(29, 2); Color(ORANGE);
    cout << "BOB - Digite o valor do Pix (ate 10000):   ";
    cin >> valor;

    
    //Exibindo na tela do computador de Bob o que foi digitado pelo usuário
    MoveTo(4, 101); Color(ORANGE); cout << " > " << c1 << c2 << c3 << c4 << c5 << "      "; MoveTo(4, 114); cout << "\xBA";
    MoveTo(5, 101); cout << " > R$" << valor << "        "; MoveTo(5, 114); cout << "\xBA";
    MoveTo(6, 101); cout << " > Enviado    "; MoveTo(6, 114); cout << "\xBA";
    ResetColor();
    //Empacotando os dados digitados
    unsigned long long pacote = Empacotar(BOB, LIVE, c1, c2, c3, c4, c5, valor);
    //Passando para função transmitir
    Transmitir(pacote);

    OcultarCursor();
    AnimarBob(9, 106); // Função de animação rede de Bob
    MostrarCursor();
}

void Johnny() {
    //Criando a variavél pacote que vai receber a função Receber()
    unsigned long long pacote = Receber();
    //Criando as variavéis origem, destino e valor para ser atribuida as suas funções respectivas
    int origem = Origem(pacote);
    int destino = Destino(pacote);
    int valor = Valor(pacote);

    //Criando as variavéis dos caracteres para ser atribuida as suas funções respectivas
    char m1 = Mensagem1(pacote);
    char m2 = Mensagem2(pacote);
    char m3 = Mensagem3(pacote);
    char m4 = Mensagem4(pacote);
    char m5 = Mensagem5(pacote);

    //Exibindo na 1° tela de Johnny algumas informações
    Color(BLUE);
    MoveTo(16, 38); cout << "Sender:   " << origem << "  ";     
    MoveTo(17, 38); cout << "Receiver: " << destino << "  ";   
    MoveTo(18, 38); cout << "Msg:      " << m1 << m2 << m3 << m4 << m5;
    MoveTo(19, 38); cout << "Pix:      " << valor << "       ";

    Mostrar(pacote); // Mostra os bits na 2° tela de Johnny

    int corAtual = origem;

    // Logíca da interceptação de Johnny
    int sorteio = rand() % 2;

    if (sorteio == 1) {
        valor = valor / 2; // 50% do valor fica no bolso de Johny 
        pacote = Empacotar(JOHNNY, LIVE, m1, m2, m3, m4, m5, valor);
        Transmitir(pacote);
        corAtual = JOHNNY;
    }

    OcultarCursor();
    AnimarJohnny(corAtual, 13, 61); // Animação rede de Johnny
    MostrarCursor();
}

void Live() {
    // Simula a receção do pacote de dados no destino final
    unsigned long long pacote = Receber();
    int origem = Origem(pacote);
    int valor = Valor(pacote);

    char m1 = Mensagem1(pacote);
    char m2 = Mensagem2(pacote);
    char m3 = Mensagem3(pacote);
    char m4 = Mensagem4(pacote);
    char m5 = Mensagem5(pacote);

    Color(GREEN);
    MoveTo(4, 56); cout << " > " << m1 << m2 << m3 << m4 << m5 << "      "; MoveTo(4, 69); cout << "\xBA";

    MoveTo(5, 56);
    //Exibe os nomes de acordo com a origem
    if (origem == 1) {
        cout << " > Alice ";
    }
    else if (origem == 2) {
        cout << " > Bob   ";
    } 
    else {
        cout << " > Johnny ";
    }
    MoveTo(5, 69); cout << "\xBA";

    MoveTo(6, 56); cout << " > R$" << valor << "        "; MoveTo(6, 69); cout << "\xBA";
    ResetColor();
}
