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