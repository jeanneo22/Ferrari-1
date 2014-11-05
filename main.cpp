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
//#include "Pessoa.h"

using std::vector;

void imprimirTudo(Automovel*);

int main(int argc, char **argv)
{
	Pessoa p1 = Pessoa("Vin Disel em Velozes e Furiosos", 43);
	p1.adicionarMotivo("Gosta de Velocidade e furia");
	p1.adicionarMotivo("Quer fazer os drifts");
	p1.adicionarMotivo("Acha o carro bonito");
	Automovel *lancer1 = new Lancer(true);
	lancer1->setDono(p1);

	Pessoa p2 = Pessoa("Felipe Massa", 50);
	p2.adicionarMotivo("Ja trabalhou na ferrari");
	p2.adicionarMotivo("Quer ficar na frente do Rubinho");
	Automovel *ferrari1 = new Ferrari("Formula 1",400,8,8,Data(20,05,2013),p2);

	Automovel *ferrari2 = new Ferrari(*(static_cast<Ferrari*>(ferrari1)));

	vector<Automovel*> automoveis = vector<Automovel *>();
	
	automoveis.push_back(lancer1);
	automoveis.push_back(ferrari1);
	automoveis.push_back(ferrari2);
	
	for (size_t i = 0 ; i < automoveis.size(); i++)
	{
		imprimirTudo(automoveis[i]);
	}

	Ferrari::updateSoftware("1.1.00");

	system("pause");
	return 0;
}

void imprimirTudo(Automovel* automovel) 
{
	automovel->acelerar(70);
	string tipo = typeid(*automovel).name();
	bool isCarro = false;
	
	Ferrari* ferrariPtr = dynamic_cast<Ferrari*>(automovel);
	if(ferrariPtr != 0) 
	{
		ferrariPtr->setMotorTurbo(true);
		isCarro = true;
	}
	else
	{
		Jipe* jipePtr = dynamic_cast<Jipe*>(automovel);
		if (jipePtr != 0 )
		{
			dynamic_cast<Jipe*>(automovel)->setTracaoQuatroRodas(true);
			isCarro = true;
		}
		else
		{
			Lancer* lancerPtr = dynamic_cast<Lancer*>(automovel);
			if (lancerPtr != 0 )
			{
				dynamic_cast<Lancer*>(automovel)->setControleDrift(true);
				isCarro = true;
			}
		}
		
	}

	if (isCarro)
	{
		dynamic_cast<Carro*>(automovel)->mudarMarcha(3);
	}
	
	automovel->acelerar(50);
	automovel->desacelerar();
	
	cout <<"Informacoes gerais\n";
	automovel->imprimirDados();
	
	cout<<"\nVelocidade Atual\n";
	automovel->imprimirVelocidade();	
	
	cout << "Porque o dono " << automovel->getDono().getNome() << " comprou " << tipo << "\n";
	automovel->getDono().imprimirMotivos();
	
	cout << "\n";
}