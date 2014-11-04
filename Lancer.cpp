#include "Lancer.h"
using std::cout;
using std::cin;

Lancer::Lancer(const string& modelo, float velocidadeMaxima, int marchaTotal, int quantidadePortaTreco, const Data& dataFabricacao,const Pessoa& dono) : Carro(modelo,velocidadeMaxima,marchaTotal,quantidadePortaTreco,dataFabricacao,dono)
{
	setControleDrift(false);
}

Lancer::Lancer(const Lancer& lancer) : Carro(lancer)
{
	this->controleDrift = lancer.controleDrift;
}

Lancer::Lancer(bool isModelo) : Carro()
{
	if (isModelo) {
		setModelo("Modelo");
		setVelocidadeMaxima(260);
		setMarchaTotal(6);		
	}
	
	setControleDrift(false);
}

void Lancer::operator =(const Lancer &right) {
	this->Automovel::operator=(right);
	controleDrift = right.controleDrift;
}

void Lancer::acelerar(float quantidade)
{
	setVelocidadeAtual(velocidadeAtual+quantidade);
}

void Lancer::desacelerar()
{
	float quantidade = 30;
	if (controleDrift)	quantidade *= 2.0f;
	setVelocidadeAtual(velocidadeAtual-quantidade);
}

void Lancer::setControleDrift(bool controleDrift) {
	this->controleDrift = controleDrift;
}

bool Lancer::isControleDrift() const {
	return controleDrift;
}

ostream &operator<< (ostream &output, const Lancer &lancer) {
	//output << "Lancer:" << static_cast<Automovel>(lancer);
	return output;
}