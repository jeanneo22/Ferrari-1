#include <iostream>
using std::cin;
using std::cout;

#include <string>
using std::string;

#include <stdlib.h>

#include <typeinfo>
using std::type_info;

#include "Ferrari.h"
#include "Jipe.h"
#include "Lancer.h"
#include "Pessoa.h"

void imprimirTudo(Automovel*);

int main(int argc, char **argv)
{
	Pessoa p1 = Pessoa("Pessoa", 43);
	p1.adicionarMotivo("Gosta de Velocidade");
	p1.adicionarMotivo("Acha a marca atrativa");
	Automovel *f1 = new Lancer(true);
	f1->setDono(p1);

	imprimirTudo(f1);


	Ferrari::updateSoftware("1.1.00");

	system("pause");
	return 0;
}

void imprimirTudo(Automovel* automovel) 
{
	automovel->acelerar(70);

	bool isCarro = false;
	string tipo = typeid(*automovel).name();
	if(tipo == "7Ferrari") 
	{
		dynamic_cast<Ferrari*>(automovel)->setMotorTurbo(true);
		isCarro = true;
	}
	else if (tipo == "4Jipe")
	{
		dynamic_cast<Jipe*>(automovel)->setTracaoQuatroRodas(true);
		isCarro = true;
	}
	else if (tipo == "6Lancer")
	{
		dynamic_cast<Lancer*>(automovel)->setControleDrift(true);
		isCarro = true;
	}
	
	if (isCarro)
	{
		dynamic_cast<Carro*>(automovel)->mudarMarcha(3);
	}
	
	automovel->acelerar(50);
	automovel->desacelerar();
	
	cout<<"Velocidade Atual\n";
	automovel->imprimirVelocidade();
	
	cout << "Porque o dono comprou o " << tipo << "\n";
	automovel->getDono().imprimirMotivos();
	
}