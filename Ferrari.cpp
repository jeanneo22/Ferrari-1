
#include <vector>
#include <iostream>
#include <assert.h>
#include <stdlib.h>

#include <string>
using std::cout;
using std::cin;

#include "Ferrari.h"

string Ferrari::versaoSoftware = "1.0.02";

ostream &operator<< (ostream &output, const Ferrari &ferrari) {
	output << "FERRARI:" << ((Carro)(ferrari));
	return output;
}

void Ferrari::operator =(const Ferrari &right) {
	this->Carro::operator=(right);
	motorTurbo = right.motorTurbo;
}

Ferrari::Ferrari(const string& modelo, float velocidadeMaxima, int marchaTotal, int quantidadePortaTreco, const Data& dataFabricacao,const Pessoa& dono) : Carro(modelo,velocidadeMaxima,marchaTotal,quantidadePortaTreco,dataFabricacao,dono)
{
	setMotorTurbo(false);
}

Ferrari::Ferrari(const Ferrari& ferrari) : Carro(ferrari)
{
	this->motorTurbo = ferrari.motorTurbo;
}

Ferrari::Ferrari(const Data& dataFabricacao, const Pessoa& dono, bool isF599XX) : Carro(dataFabricacao,dono)
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

void Ferrari::acelerar(float quantidade)
{
	if(motorTurbo) {
		quantidade *= 1.5f;
	}
	this->Carro::acelerar(quantidade);
}

void Ferrari::setMotorTurbo(bool motorTurbo) {
	this->motorTurbo = motorTurbo;
}

bool Ferrari::isMotorTurbo() const {
	return motorTurbo;
}
