#include "Automovel.h"

Automovel::Automovel()
{
	dataFabricacao = Data(20,2,2014);
	modelo = "";
	velocidadeMaxima = 260;
	velocidadeAtual = 0;
	
	this->quantidadePortaTreco = 5;
	dinheiroPortaTreco = new int[quantidadePortaTreco];
	for (int i = 0; i < quantidadePortaTreco;i++) {
		this->dinheiroPortaTreco[i] = 0;
	}
	
	this->dono = dono;
}

Automovel::Automovel(const string& modelo, float velocidadeMaxima, int quantidadePortaTreco, const Data& dataFabricacao,const Pessoa& dono) 
{
	setDataFabricacao(dataFabricacao);
	setModelo(modelo);
	setVelocidadeMaxima(velocidadeMaxima);
	velocidadeAtual = 0;
	
	this->quantidadePortaTreco = std::max(0,quantidadePortaTreco);	
	dinheiroPortaTreco = new int[quantidadePortaTreco];
	for (int i = 0; i < quantidadePortaTreco;i++) {
		this->dinheiroPortaTreco[i] = 0;
	}
	
	this->dono = dono;
}

Automovel::Automovel(const Automovel& automovel) 
{
	dataFabricacao = automovel.dataFabricacao;
	modelo = automovel.modelo;
	velocidadeMaxima = automovel.velocidadeMaxima;
	velocidadeAtual = automovel.velocidadeAtual;
	quantidadePortaTreco = automovel.quantidadePortaTreco;
	dinheiroPortaTreco = new int[quantidadePortaTreco];
	for (int i = 0; i < quantidadePortaTreco;i++) {
		this->dinheiroPortaTreco[i] = automovel.dinheiroPortaTreco[i];
	}
	
	this->dono = automovel.dono;
}

Automovel::~Automovel()
{
	delete [] dinheiroPortaTreco;
}

void Automovel::trocarDonos(Automovel * c1, Automovel * c2)
{
	Pessoa aux = c1->dono;
	c1->dono = c2->dono;
	c1->dono = aux;
}

void Automovel::operator =(const Automovel &right) {
	dataFabricacao = right.dataFabricacao;
	modelo = right.modelo;
	velocidadeMaxima = right.velocidadeMaxima;
	velocidadeAtual = right.velocidadeAtual;
	quantidadePortaTreco = right.quantidadePortaTreco;
	delete [] dinheiroPortaTreco;
	dinheiroPortaTreco = new int[quantidadePortaTreco];
	for (int i = 0; i < quantidadePortaTreco;i++) {
		this->dinheiroPortaTreco[i] = right.dinheiroPortaTreco[i];
	}
	
	this->dono = right.dono;
}

void Automovel::imprimirDados() const{
	cout << "Modelo: " << modelo << std::endl;
	cout << "Velocidade Maxima: " << velocidadeMaxima << std::endl;
	cout << "Data fabricacao: " << dataFabricacao.getDia() << "/" << dataFabricacao.getMes() << "/" << dataFabricacao.getAno() << std::endl;
	cout << "Dono: " << dono.getNome() << std::endl;
	cout <<  std::endl;
}

void Automovel::imprimirVelocidade() const{
	cout << "Velocidade:" << velocidadeAtual << "/" << velocidadeMaxima;
	cout << std::endl;
}

void Automovel::setDono(const Pessoa& dono) {
	this->dono = dono;
}



const Pessoa& Automovel::getDono() const {
	return dono;
}

void Automovel::setDataFabricacao(const Data& dataFabricacao) {
	this->dataFabricacao = dataFabricacao;
}

const string& Automovel::getModelo() const {
	return modelo;
}
float Automovel::getVelocidadeAtual() const {
	return velocidadeAtual;
}
float Automovel::getVelocidadeMaxima() const {
	return velocidadeMaxima;
}
int Automovel::getQuantidadePortaTreco() const {
	return quantidadePortaTreco;
}

void Automovel::setVelocidadeMaxima(float velocidadeMaxima) {
	this->velocidadeMaxima = std::min(std::max(60.0f,velocidadeMaxima), 500.0f);
}

void Automovel::setModelo(const string& modelo) 
{
	this->modelo = modelo;
}

void Automovel::setVelocidadeAtual(float velocidade) {
	this->velocidadeAtual = std::min(std::max(velocidade,0.0f), velocidadeMaxima);
}
ostream &operator<< (ostream &output, const Automovel &carro) {
	output << carro.modelo << " (" << carro.dataFabricacao.getDia() << "/" << carro.dataFabricacao.getMes() << "/" << carro.dataFabricacao.getAno() << ")";
	return output;
}