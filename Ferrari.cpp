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
const int Ferrari::quantidadePortaTreco = 5;

ostream &operator<< (ostream &output, const Ferrari &ferrari) {
	output << ferrari.modelo << " (" << ferrari.dataFabricacao.getDia() << "/" << ferrari.dataFabricacao.getMes() << "/" << ferrari.dataFabricacao.getAno() << ")";
	return output;
}

Ferrari::Ferrari(const string& modelo, float velocidadeMaxima, int marchaTotal, const Data& dataFabricacao)
{
	setModelo(modelo);
	
	setVelocidadeMaxima(velocidadeMaxima);
	this->velocidadeAtual = 0;
	
	setMarchaTotal(marchaTotal);
	this->marchaAtiva = 0;
	
	setDataFabricacao(dataFabricacao);
	
	setMotorTurbo(false);
	
	this->dinheiroPortaTreco = new int[quantidadePortaTreco];
	for (int i = 0; i < quantidadePortaTreco;i++) {
		this->dinheiroPortaTreco[i] = 0;
	}
	
	this->nomeTodosDonos = vector<Pessoa>();
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
	dinheiroPortaTreco = new int[quantidadePortaTreco];
	for (int i = 0; i < quantidadePortaTreco;i++) {
		this->dinheiroPortaTreco[i] = ferrari.dinheiroPortaTreco[i];
	}
	
	this->nomeTodosDonos = vector<Pessoa>();
}

Ferrari::Ferrari(const Data& dataFabricacao, bool isF599XX)
{
	if (isF599XX) {
		setModelo(Ferrari::F599XX.getModelo());
		setVelocidadeMaxima(Ferrari::F599XX.getVelocidadeMaxima());
		setMarchaTotal(Ferrari::F599XX.getMarchaTotal());		
	}
	else {
		setModelo("");
		setVelocidadeMaxima(300);
		setMarchaTotal(6);
	}
	
	this->dinheiroPortaTreco = new int[quantidadePortaTreco];
	for (int i = 0; i < quantidadePortaTreco;i++) {
		this->dinheiroPortaTreco[i] = 0;
	}
	
	this->velocidadeAtual = 0;
	this->marchaAtiva = 0;
	setDataFabricacao(dataFabricacao);
	
	this->nomeTodosDonos = vector<Pessoa>();	
}

void Ferrari::fabricar(Ferrari *fabricar)
{
	delete fabricar;
	
	string modelo;
	float velocidadeMaxima;
	int totalMarchas;
	string resp;
	int dia,mes,ano;
	
	cout << "Voce deseja fabricar uma F599XX? <s/n>";
	cin >> resp;
	
	cout << "Insira o dia de fabricacao:";
	cin >> dia;
	cout << "Insira o dia de fabricacao:";
	cin >> mes;
	cout << "Insira o dia de fabricacao:";
	cin >> ano;
	
	if (resp == "s") {
		*fabricar = Ferrari(Data(dia,mes,ano),true);
	}
	else {
		cout << "Insira o modelo:";
		cin >> modelo;
		cout << "Insira a velocidade maxima:";
		cin >> velocidadeMaxima;
		cout << "Insira o total de marchas:";
		cin >> totalMarchas;
		*fabricar = Ferrari(modelo,velocidadeMaxima,totalMarchas,Data(dia,mes,ano));
	}	
	
	Ferrari::qtdFabricada++;
}

bool Ferrari::operator ==(const Ferrari &right) {
	return (this->modelo == right.modelo) && (this->velocidadeMaxima == right.velocidadeMaxima) && (this->marchaTotal == right.marchaTotal);
}

void Ferrari::adicionarDono(const string &nome) {
	nomeTodosDonos.push_back(nome);
}

void Ferrari::imprimirDonos() const {
	for (int i = 0; i < nomeTodosDonos.size(); i++) {
		
		cout << ((Pessoa)nomeTodosDonos[i]).getNome() << " ";
	}
	cout << std::endl;
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
	cout << "Modelo: " << modelo << std::endl;
	cout << "Velocidade Maxima: " << velocidadeMaxima << std::endl;
	cout << "Total de Marchas: " << marchaTotal << std::endl;
	cout << "Data fabricacao: " << dataFabricacao.getDia() << "/" << dataFabricacao.getMes() << "/" << dataFabricacao.getAno() << std::endl;
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

int Ferrari::getDinheiroPortaTreco(int indice) const {
	return dinheiroPortaTreco[indice];
}

void Ferrari::setDinheiroPortaTreco(int valor, int indice){
	dinheiroPortaTreco[indice] = valor;
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
int Ferrari::getQuantidadePortaTreco() const {
	return quantidadePortaTreco;
}