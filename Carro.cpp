#include <vector>
#include <iostream>
#include <assert.h>
#include <stdlib.h>

#include <string>
using std::cout;
using std::cin;

#include "Carro.h"

const int Carro::quantidadeRodas = 4;

void Carro::operator =(const Carro &right) {
	dataFabricacao = right.dataFabricacao;
	modelo = right.modelo;
	marchaTotal = right.marchaTotal;
	velocidadeMaxima = right.velocidadeMaxima;
	marchaAtiva = right.marchaAtiva;
	velocidadeAtual = right.velocidadeAtual;
	quantidadePortaTreco = right.quantidadePortaTreco;
	delete [] dinheiroPortaTreco;
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

Carro::Carro(const string& modelo, float velocidadeMaxima, int marchaTotal, int quantidadePortaTreco, const Data& dataFabricacao,const Pessoa& dono)
{
	setDataFabricacao(dataFabricacao);
	setModelo(modelo);
	setMarchaTotal(marchaTotal);
	setVelocidadeMaxima(velocidadeMaxima);
	
	this->quantidadePortaTreco = std::max(0,quantidadePortaTreco);
	
	marchaAtiva = 0;
	velocidadeAtual = 0;
	dinheiroPortaTreco = new int[quantidadePortaTreco];
	for (int i = 0; i < quantidadePortaTreco;i++) {
		this->dinheiroPortaTreco[i] = 0;
	}
	
	this->dono = dono;
	this->multas = vector<Multa>();
}

Carro::Carro(const Carro& carro) 
{
	dataFabricacao = carro.dataFabricacao;
	modelo = carro.modelo;
	marchaTotal = carro.marchaTotal;
	velocidadeMaxima = carro.velocidadeMaxima;
	marchaAtiva = carro.marchaAtiva;
	velocidadeAtual = carro.velocidadeAtual;
	quantidadePortaTreco = carro.quantidadePortaTreco;
	delete [] dinheiroPortaTreco;
	dinheiroPortaTreco = new int[quantidadePortaTreco];
	for (int i = 0; i < quantidadePortaTreco;i++) {
		this->dinheiroPortaTreco[i] = carro.dinheiroPortaTreco[i];
	}
	
	this->dono = carro.dono;
	this->multas = vector<Multa>();
	for (int i = 0; i < carro.multas.size();i++) {
		this->multas.push_back(carro.multas[i]);
	}
}

Carro::Carro(const Data& dataFabricacao,const Pessoa& dono)
{
	setDataFabricacao(dataFabricacao);
	setDono(dono);
	setModelo("");
	setMarchaTotal(6);
	setVelocidadeMaxima(300);
	marchaAtiva = 0;
	velocidadeAtual = 0;
	quantidadePortaTreco = 5;	
	dinheiroPortaTreco = new int[quantidadePortaTreco];
	for (int i = 0; i < quantidadePortaTreco;i++) {
		this->dinheiroPortaTreco[i] = 0;
	}
	this->multas = vector<Multa>();
}

void Carro::trocarDonos(Carro * c1, Carro * c2)
{
	Pessoa aux = c1->dono;
	c1->dono = c2->dono;
	c1->dono = aux;
}

Carro::~Carro()
{
	delete [] dinheiroPortaTreco;
}

void Carro::adicionarMulta(const Multa &multa) {
	multas.push_back(multa);
}

void Carro::imprimirMultas() const {
	for (unsigned int i = 0; i < multas.size(); i++) {
		cout << ((Multa)multas[i]).getRazao() << " Pontos: " << ((Multa)multas[i]).getPontos() << " Valor: " << ((Multa)multas[i]).getValor();
	}
	cout << std::endl;
}

void Carro::mudarMarcha(int marcha)
{
	this->marchaAtiva = std::min(std::max(0,marcha), marchaTotal);
}

void Carro::acelerar(float quantidade)
{
	setVelocidadeAtual(velocidadeAtual+quantidade);
//	velocidadeAtual = std::min(velocidadeMaxima,velocidadeAtual+quantidade);
}

void Carro::desacelerar()
{
	velocidadeAtual = std::max((float)0,velocidadeAtual-30);
}

void Carro::imprimirDados() const{
	cout << "Modelo: " << modelo << std::endl;
	cout << "Velocidade Maxima: " << velocidadeMaxima << std::endl;
	cout << "Total de Marchas: " << marchaTotal << std::endl;
	cout << "Data fabricacao: " << dataFabricacao.getDia() << "/" << dataFabricacao.getMes() << "/" << dataFabricacao.getAno() << std::endl;
	cout << "Dono: " << dono.getNome() << std::endl;
	cout <<  std::endl;
}

void Carro::imprimirVelocidade() const{
	cout << "Velocidade:" << velocidadeAtual << "/" << velocidadeMaxima;
	cout << "Marcha: " << marchaAtiva << "/" << marchaTotal;
	cout << std::endl;
}

void Carro::setDono(const Pessoa& dono) {
	this->dono = dono;
}

Pessoa Carro::getDono() const {
	return dono;
}

void Carro::setDataFabricacao(const Data& dataFabricacao) {
	this->dataFabricacao = dataFabricacao;
}

void Carro::setMarchaTotal(int marchaTotal) {
	if (marchaTotal < 4) {
		this->marchaTotal = marchaTotal;		
	}
	else {
		this->marchaTotal = marchaTotal;
	}
}

void Carro::setModelo(const string& modelo) {
	this->modelo = modelo;
}

int Carro::getDinheiroPortaTreco(int indice) const {
	return dinheiroPortaTreco[indice];
}

void Carro::setDinheiroPortaTreco(int valor, int indice){
	dinheiroPortaTreco[indice] = valor;
}

void Carro::setVelocidadeMaxima(float velocidadeMaxima) {
	if (velocidadeMaxima < 200) {
		this->velocidadeMaxima = 200;
	}
	else {
		this->velocidadeMaxima = velocidadeMaxima;
	}	
}
const Data& Carro::getDataFabricacao() const {
	return dataFabricacao;
}
int Carro::getMarchaAtiva() const {
	return marchaAtiva;
}
int Carro::getMarchaTotal() const {
	return marchaTotal;
}
const string& Carro::getModelo() const {
	return modelo;
}
float Carro::getVelocidadeAtual() const {
	return velocidadeAtual;
}
float Carro::getVelocidadeMaxima() const {
	return velocidadeMaxima;
}
int Carro::getQuantidadePortaTreco() const {
	return quantidadePortaTreco;
}
int Carro::getQuantidadeRodas() const {
	return quantidadeRodas;
}

ostream &operator<< (ostream &output, const Carro &carro) {
	output << carro.modelo << " (" << carro.dataFabricacao.getDia() << "/" << carro.dataFabricacao.getMes() << "/" << carro.dataFabricacao.getAno() << ")";
	return output;
}
