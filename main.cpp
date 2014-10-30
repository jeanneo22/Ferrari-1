#include <iostream>
using std::cin;
using std::cout;

#include <string>
using std::string;

#include <stdlib.h>

#include "Ferrari.h"
#include "Pessoa.h"

int main(int argc, char **argv)
{
	Carro *f1 = new Ferrari(Data(21,07,1999),Pessoa("Felipe Eliasquevici",19),true);
	
	f1->mudarMarcha(1);
	f1->acelerar(60);
	f1->mudarMarcha(2);
	f1->acelerar(130);
	f1->mudarMarcha(3);
	f1->desacelerar();
	f1->imprimirVelocidade();
	f1->adicionarMulta(Multa("Excesso de velocidade",350,7));
	f1->imprimirMultas();

	Ferrari::updateSoftware("1.1.00");

	system("pause");
	return 0;
}