#include "Ferrari.h"
using std::cout;
using std::cin;

string Ferrari::versaoSoftware = "1.0.02";

Ferrari::Ferrari(const string& modelo, float velocidadeMaxima, int marchaTotal, int quantidadePortaTreco, const Data& dataFabricacao,const Pessoa& dono) : Carro(modelo,velocidadeMaxima,marchaTotal,quantidadePortaTreco,dataFabricacao,dono)
{
	setMotorTurbo(false);
}

Ferrari::Ferrari(const Ferrari& ferrari) : Carro(ferrari)
{
	this->motorTurbo = ferrari.motorTurbo;
}

Ferrari::Ferrari(bool isF599XX) : Carro()
{
	if (isF599XX) {
		setModelo("F599XX");
		setVelocidadeMaxima(330);
		setMarchaTotal(8);		
	}
	
	setMotorTurbo(false);
}

void Ferrari::updateSoftware(string versao) {
	versaoSoftware = versao;
}

void Ferrari::operator =(const Ferrari &right) {
	this->Automovel::operator=(right);
	motorTurbo = right.motorTurbo;
}

void Ferrari::acelerar(float quantidade)
{
	if (motorTurbo)	quantidade *= 1.5f;
	setVelocidadeAtual(velocidadeAtual+quantidade);
}

void Ferrari::desacelerar()
{
	setVelocidadeAtual(velocidadeAtual-20);
}

void Ferrari::setMotorTurbo(bool motorTurbo) {
	this->motorTurbo = motorTurbo;
}

bool Ferrari::isMotorTurbo() const {
	return motorTurbo;
}

ostream &operator<< (ostream &output, const Ferrari &ferrari) {
	output << "Ferrari:" << static_cast<const Carro&>(ferrari);
	return output;
}
