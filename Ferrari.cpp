
#include <vector>
#include <iostream>
#include <assert.h>
#include <stdlib.h>

#include <string>
using std::cout;
using std::cin;

#include "Ferrari.h"

const Ferrari Ferrari::F599XX = Ferrari("F599XX",330,8,Data());
const int Ferrari::quantidadePortaTreco = 5;
string Ferrari::versaoSoftware = "1.0.02";

ostream &operator<< (ostream &output, const Ferrari &ferrari) {
	output << ferrari.modelo << " (" << ferrari.dataFabricacao.getDia() << "/" << ferrari.dataFabricacao.getMes() << "/" << ferrari.dataFabricacao.getAno() << ")";
	return output;
}

bool Ferrari::operator ==(const Ferrari &right) {
	return (this->modelo == right.modelo) && (this->velocidadeMaxima == right.velocidadeMaxima) && (this->marchaTotal == right.marchaTotal);
}

void Ferrari::operator =(const Ferrari &right) {
	dataFabricacao = right.dataFabricacao;
	modelo = right.modelo;
	marchaTotal = right.marchaTotal;
	velocidadeMaxima = right.velocidadeMaxima;
	marchaAtiva = right.marchaAtiva;
	velocidadeAtual = right.velocidadeAtual;
	motorTurbo = right.motorTurbo;
	dinheiroPortaTreco = new int[quantidadePortaTreco];
	for (int i = 0; i < quantidadePortaTreco;i++) {
		this->dinheiroPortaTreco[i] = right.dinheiroPortaTreco[i];
	}
	
	this->dono = right.dono;
	this->multas = vector<Multa>();
	for (int i = 0; i < right.multas.size();i++) {
		this->multas.push_back(right.multas[i]);
	}
}

Ferrari::~Ferrari()
{
	delete [] dinheiroPortaTreco;
}

Ferrari::Ferrari(const string& modelo, float velocidadeMaxima, int marchaTotal, const Data& dataFabricacao,const Pessoa& dono)
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
	
	this->dono = dono;
	this->multas = vector<Multa>();
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
	
	this->dono = ferrari.dono;
	this->multas = vector<Multa>();
	for (int i = 0; i < ferrari.multas.size();i++) {
		this->multas.push_back(ferrari.multas[i]);
	}
}

Ferrari::Ferrari(const Data& dataFabricacao, const Pessoa& dono, bool isF599XX)
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
	
	this->dono = dono;	
	this->multas = vector<Multa>();
}

void Ferrari::updateSoftware(string versao) {
	versaoSoftware = versao;
}

void Ferrari::adicionarMulta(const Multa &multa) {
	multas.push_back(multa);
}

void Ferrari::imprimirMultas() const {
	for (unsigned int i = 0; i < multas.size(); i++) {
		cout << ((Multa)multas[i]).getRazao() << " Pontos: " << ((Multa)multas[i]).getPontos() << " Valor: " << ((Multa)multas[i]).getValor();
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

void Ferrari::trocarDonos(Ferrari * f1, Ferrari * f2)
{
	Pessoa aux = f1->dono;
	f1->dono = f2->dono;
	f2->dono = aux;
}

void Ferrari::imprimirDados() const{
	cout << "Modelo: " << modelo << std::endl;
	cout << "Velocidade Maxima: " << velocidadeMaxima << std::endl;
	cout << "Total de Marchas: " << marchaTotal << std::endl;
	cout << "Data fabricacao: " << dataFabricacao.getDia() << "/" << dataFabricacao.getMes() << "/" << dataFabricacao.getAno() << std::endl;
	cout << "Dono: " << dono.getNome() << std::endl;
	cout << "Software: " << versaoSoftware << std::endl;
	cout <<  std::endl;
}

void Ferrari::imprimirVelocidade() const{
	cout << "Velocidade:" << velocidadeAtual << "/" << velocidadeMaxima;
	cout << "Marcha: " << marchaAtiva << "/" << marchaTotal;
	cout << std::endl;
}

void Ferrari::setDono(const Pessoa& dono) {
	this->dono = dono;
}

Pessoa Ferrari::getDono() const {
	return dono;
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