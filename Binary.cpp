#include <iostream>
#include "Binary.h"
#include "Drawing.h" 
#include "Colors.h"
using namespace std;

bool Testar(int posicao, unsigned long long pacote) {
    // Desloca o pacote para a direita até o bit desejado e mascara com 1
    return (pacote >> posicao) & 1ULL;
}

// Exibir os bits
void Mostrar(unsigned long long pacote) {
    //Linha  1
    MoveTo(16, 66);
    Color(LILAC); cout << Testar(63, pacote) << Testar(62, pacote);
    Color(CYANO); cout << Testar(61, pacote) << Testar(60, pacote);
    Color(LILAC); cout << Testar(59, pacote) << Testar(58, pacote) << Testar(57, pacote) << Testar(56, pacote) << Testar(55, pacote) << Testar(54, pacote) << Testar(53, pacote) << Testar(52, pacote);
    Color(MEDIUMBLUE); cout << Testar(51, pacote) << Testar(50, pacote) << Testar(49, pacote) << Testar(48, pacote);

    // Linha 2
    MoveTo(17, 66);
    Color(MEDIUMBLUE); cout << Testar(47, pacote) << Testar(46, pacote) << Testar(45, pacote) << Testar(44, pacote);
    Color(LILAC); cout << Testar(43, pacote) << Testar(42, pacote) << Testar(41, pacote) << Testar(40, pacote) << Testar(39, pacote) << Testar(38, pacote) << Testar(37, pacote) << Testar(36, pacote);
    Color(MEDIUMBLUE); cout << Testar(35, pacote) << Testar(34, pacote) << Testar(33, pacote) << Testar(32, pacote);

    // Linha 3 
    MoveTo(18, 66);
    Color(MEDIUMBLUE); cout << Testar(31, pacote) << Testar(30, pacote) << Testar(29, pacote) << Testar(28, pacote);
    Color(LILAC); cout << Testar(27, pacote) << Testar(26, pacote) << Testar(25, pacote) << Testar(24, pacote) << Testar(23, pacote) << Testar(22, pacote) << Testar(21, pacote) << Testar(20, pacote);
    Color(CYANO); cout << Testar(19, pacote) << Testar(18, pacote) << Testar(17, pacote) << Testar(16, pacote);

    // Linha 4 
    MoveTo(19, 66);
    Color(CYANO); cout << Testar(15, pacote) << Testar(14, pacote) << Testar(13, pacote) << Testar(12, pacote) << Testar(11, pacote) << Testar(10, pacote) << Testar(9, pacote) << Testar(8, pacote) << Testar(7, pacote) << Testar(6, pacote) << Testar(5, pacote) << Testar(4, pacote) << Testar(3, pacote) << Testar(2, pacote) << Testar(1, pacote) << Testar(0, pacote);
    ResetColor();
}