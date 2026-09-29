#include "Network.h"

static unsigned long long rede = 0; //Variável Global


unsigned long long Empacotar(int origem, int destino, char c1, char c2, char c3, char c4, char c5, int pix) {
	
	// função responsável pela operação de empacotar os bits usando operação bit a bit

	unsigned long long pacote = 0;
	
	pacote = pacote | (origem & 3ULL)  << 62;
	pacote = pacote | (destino & 3ULL) << 60;
	pacote = pacote | (c1 & 255ULL )   << 52;
	pacote = pacote | ( c2 & 255ULL)   << 44;
	pacote = pacote | (c3 & 255ULL)    << 36;
	pacote = pacote | (c4 & 255ULL)    << 28;
	pacote = pacote | (c5 & 255ULL)    << 20;
	pacote = pacote |(pix & 1048575ULL) << 0;

	return pacote;

}
void Transmitir(unsigned long long pacote) {
	// Atribui o pacote de 64 bits a variavél global, simulando a colocacão dos dados na rede.
	rede = pacote;

}
unsigned long long Receber() {
	// Lê e retorna o pacote de dados que esta armazenado na variavel global da rede.
	return rede;

}
int Origem(unsigned long long pacote) {
	// Extrai os 2 bits das posicões 62 a 63
	return(int(pacote >> 62) & 3ULL);

}
int Destino(unsigned long long pacote) {
	// Extrai os 2 bits das posicões 60 a 61
	return (int(pacote >> 60) & 3ULL);

}
int Valor(unsigned long long pacote) {
	// Extrai os 20 bits menos significativos das posicões 0 a 19
	return(int(pacote & 1048575ULL));
}
char Mensagem1(unsigned long long pacote) {
	// Extrai o 1° caractere da mensagem utilizando uma mascara de 8 bits
	return (char)((pacote >> 52) & 255ULL);
}
char Mensagem2(unsigned long long pacote) {
	// Extrai o 2° caractere da mensagem 
	return (char)((pacote >> 44) & 255ULL);
}
char Mensagem3(unsigned long long pacote) {
	// Extrai o 3° caractere da mensagem 
	return (char)((pacote >> 36) & 255ULL);
}
char Mensagem4(unsigned long long pacote) {
	// Extrai o 4° caractere da mensagem 
	return (char)((pacote >> 28) & 255ULL);
}
char Mensagem5(unsigned long long pacote) {
	// Extrai o 5° caractere da mensagem 
	return (char)((pacote >> 20) & 255ULL);

}