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
	Pessoa p1 = Pessoa("Pessoa", 43);
	p1.adicionarMotivo("Gosta de Velocidade");
	p1.adicionarMotivo("Acha a marca atrativa");
	Automovel *f1 = new Ferrari(true);
	
	f1->acelerar(60);
	f1->acelerar(130);
	f1->desacelerar();
	cout<<"Velocidade Atual\n";
	f1->imprimirVelocidade();

	cout << "Porque o dono comprou a ferrari\n";
	f1->getDono().imprimirMotivos();

	Ferrari::updateSoftware("1.1.00");

	system("pause");
	return 0;
}