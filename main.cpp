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
	Carro *f1 = new Ferrari(Data(21,07,1999),p1,true);
	
	f1->mudarMarcha(1);
	f1->acelerar(60);
	f1->mudarMarcha(2);
	f1->acelerar(130);
	f1->mudarMarcha(3);
	f1->desacelerar();
	cout<<"Velocidade Atual\n";
	f1->imprimirVelocidade();
	f1->adicionarMulta(Multa("Excesso de velocidade",350,7));
	cout << "Multas:\n";
	f1->imprimirMultas();

	cout << "Porque o dono comprou a ferrari\n";
	f1->getDono().imprimirMotivos();

	Ferrari::updateSoftware("1.1.00");

	system("pause");
	return 0;
}