
#include <vector>
#include <iostream>
#include <assert.h>
#include <stdlib.h>

#include <string>
using std::cout;
using std::cin;

#include "Ferrari.h"

const Ferrari Ferrari::F599XX = Ferrari("F599XX",330,8,Data());

string Ferrari::versaoSoftware = "1.0.02";

void Ferrari::operator =(const Ferrari &right) {
//	((Carro)this) = ((Carro)right);
	motorTurbo = right.motorTurbo;
}

Ferrari::~Ferrari()
{
	
}

Ferrari::Ferrari(const string& modelo, float velocidadeMaxima, int marchaTotal, const Data& dataFabricacao,const Pessoa& dono) : Carro(modelo,velocidadeMaxima,marchaTotal,dataFabricacao,dono)
{
}

Ferrari::Ferrari(const Ferrari& ferrari) : Carro(ferrari)
{
	this->motorTurbo = ferrari.motorTurbo;
}

Ferrari::Ferrari(const Data& dataFabricacao, const Pessoa& dono, bool isF599XX) : Carro(dataFabricacao,dono)
{
	if (isF599XX) {
		setModelo(Ferrari::F599XX.getModelo());
		setVelocidadeMaxima(Ferrari::F599XX.getVelocidadeMaxima());
		setMarchaTotal(Ferrari::F599XX.getMarchaTotal());		
	}
	
	setMotorTurbo(false);
}

void Ferrari::updateSoftware(string versao) {
	versaoSoftware = versao;
}


void Ferrari::toggleMotorTurbo()
{
	motorTurbo = !motorTurbo;
}

void Ferrari::setMotorTurbo(bool motorTurbo) {
	this->motorTurbo = motorTurbo;
}

bool Ferrari::isMotorTurbo() const {
	return motorTurbo;
}
