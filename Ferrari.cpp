#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <stdlib.h>

using std::cout;
using std::cin;

#include "Ferrari.h"

const Ferrari Ferrari::F599XX = Ferrari("F599XX",330,8,Data());
int Ferrari::qtdFabricada = 0;

Ferrari::Ferrari(string modelo, float velocidadeMaxima, int marchaTotal, const Data& dataFabricacao)
{
	setModelo(modelo);
	
	setVelocidadeMaxima(velocidadeMaxima);
	this->velocidadeAtual = 0;
	
	setMarchaTotal(marchaTotal);
	this->marchaAtiva = 0;
	
	setDataFabricacao(dataFabricacao);
	
	setMotorTurbo(false);
}

Ferrari::Ferrari(const Ferrari& ferrari)
{
	dataFabricacao = ferrari.dataFabricacao;
	modelo = ferrari.modelo;
	marchaTotal = ferrari.marchaTotal;
	velocidadeMaxima = ferrari.velocidadeMaxima;
	marchaAtiva = ferrari.marchaAtiva;
	velocidadeAtual = ferrari.velocidadeAtual;
	motorTurbo = ferrari.motorTurbo;
}

Ferrari::Ferrari(const Data& dataFabricacao, bool isF599XX)
{
	if (isF599XX) {
		setModelo(Ferrari::F599XX.getModelo());
		setVelocidadeMaxima(Ferrari::F599XX.getVelocidadeMaxima());
		this->velocidadeAtual = 0;
		setMarchaTotal(Ferrari::F599XX.getMarchaTotal());
		this->marchaAtiva = 0;
		setDataFabricacao(dataFabricacao);
	}
	else {
		setModelo("");
		setVelocidadeMaxima(300);
		this->velocidadeAtual = 0;
		setMarchaTotal(6);
		this->marchaAtiva = 0;
		setDataFabricacao(dataFabricacao);
	}	
}

void Ferrari::fabricar(Ferrari *fabricar)
{
	string modelo;
	float velocidadeMaxima;
	int totalMarchas;
	
	char resp;
	
	int dia,mes,ano;
	
	do {
	cout << "Voce deseja fabricar uma F599XX? <s/n>";
	cin >> resp;
	} while (resp != 'n' && resp != 's');
	
	cout << "Insira o dia de fabricacao:";
	cin >> dia;
	cout << "Insira o dia de fabricacao:";
	cin >> mes;
	cout << "Insira o dia de fabricacao:";
	cin >> ano;
	
	if (resp == 's') {
		fabricar = new Ferrari(Data(dia,mes,ano),true);
	}
	else {
		cout << "Insira o modelo:";
		cin >> modelo;
		cout << "Insira a velocidade maxima:";
		cin >> velocidadeMaxima;
		cout << "Insira o total de marchas:";
		cin >> totalMarchas;
		fabricar = new Ferrari(modelo,velocidadeMaxima,totalMarchas,Data(dia,mes,ano));
	}	
	
	Ferrari::qtdFabricada++;
}

void Ferrari::mudarMarcha(int marcha)
{
	this->marchaAtiva = std::min(std::max(0,marcha), marchaTotal);
}

void Ferrari::acelerar(float quantidade)
{
	if (motorTurbo) {
		quantidade += 30;
	}
	velocidadeAtual = std::min(velocidadeMaxima,velocidadeAtual+quantidade);
}

void Ferrari::desacelerar()
{
	velocidadeAtual = std::max((float)0,velocidadeAtual-30);
}

void Ferrari::toggleMotorTurbo()
{
	motorTurbo = !motorTurbo;
}

void Ferrari::imprimirDados() const{
	cout << "Modelo: " << modelo;
	cout << "Velocidade Maxima: " << velocidadeMaxima;
	cout << "Total de Marchas: " << marchaTotal;
	cout << "Data fabricacao: " << dataFabricacao.getDia() << "/" << dataFabricacao.getMes() << "/" << dataFabricacao.getAno();
}

void Ferrari::imprimirVelocidade() const{
	cout << "Velocidade:" << velocidadeAtual << "/" << velocidadeMaxima;
	cout << "Marcha: " << marchaAtiva << "/" << marchaTotal;
}

void Ferrari::setDataFabricacao(const Data& dataFabricacao) {
	this->dataFabricacao = dataFabricacao;
}

void Ferrari::setMarchaTotal(int marchaTotal) {
	if (marchaTotal < 4) {
		this->marchaTotal = marchaTotal;		
	}
	else {
		this->marchaTotal = marchaTotal;
	}
}

void Ferrari::setModelo(const string& modelo) {
	this->modelo = modelo;
}

void Ferrari::setVelocidadeMaxima(float velocidadeMaxima) {
	if (velocidadeMaxima < 200) {
		this->velocidadeMaxima = 200;
	}
	else {
		this->velocidadeMaxima = velocidadeMaxima;
	}	
}
void Ferrari::setMotorTurbo(bool motorTurbo) {
	this->motorTurbo = motorTurbo;
}
const Data& Ferrari::getDataFabricacao() const {
	return dataFabricacao;
}
int Ferrari::getMarchaAtiva() const {
	return marchaAtiva;
}
int Ferrari::getMarchaTotal() const {
	return marchaTotal;
}
const string& Ferrari::getModelo() const {
	return modelo;
}
bool Ferrari::isMotorTurbo() const {
	return motorTurbo;
}
float Ferrari::getVelocidadeAtual() const {
	return velocidadeAtual;
}
float Ferrari::getVelocidadeMaxima() const {
	return velocidadeMaxima;
}
