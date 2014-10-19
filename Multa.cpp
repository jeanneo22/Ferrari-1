#include "Multa.h"
#include <iostream>

const float Multa::valorMaximo = 517.55f;


ostream &operator<< (ostream &output, const Multa &multa) {
	output << multa.razao ;
	return output;
}

bool Multa::operator ==(const Multa &right) {
	return (this->razao == right.razao) && (this->pontos == right.pontos) && (this->valor == right.valor);
}

void Multa::operator =(const Multa &right) {
	this->razao = right.razao;
	this->pontos = right.pontos;
	this->valor = right.valor;
}

Multa::Multa(const string & razao, float valor, int pontos)
{
	this->razao = razao;
	this->valor = setValor(valor);
	this->pontos = pontos;
}

Multa::Multa(const Multa & multa)
{
	this->razao = multa.razao;
	this->pontos = multa.pontos;
	this->valor = multa.valor;
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
	if (valor < 0)
		valor = 0;
	else if (valor > valorMaximo) 
		valor = valorMaximo;
		
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