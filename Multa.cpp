#include "Multa.h"
#include <iostream>

Multa::Multa(const string & razao, float valor, int pontos)
{
	this->razao = razao;
	this->valor = valor;
	this->pontos = pontos;
}

Multa::~Multa()
{
}

Multa Multa::cadastrar() 
{
	string razao;
	float valor;
	int pontos;
	
	std::cout << "Insira a razao:";
	std::cin >> razao;
	std::cout << "Insira o valor";
	std::cin >> valor;
	std::cout << "Insira os pontos";
	std::cin >> pontos;
	Multa m = Multa(razao,valor,pontos);
	return m;
}

void Multa::setPontos(int pontos) {
	this->pontos = pontos;
}
void Multa::setRazao(const string& razao) {
	this->razao = razao;
}
void Multa::setValor(float valor) {
	this->valor = valor;
}
int Multa::getPontos() const {
	return pontos;
}
const string& Multa::getRazao() const {
	return razao;
}
float Multa::getValor() const {
	return valor;
}