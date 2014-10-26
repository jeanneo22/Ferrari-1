#include "Multa.h"
#include <iostream>

const float Multa::valorMaximo = 517.55f;
const int Multa::tamanhoAlocacao = 10;

ostream &operator<< (ostream &output, const Multa &multa) {
	output << multa.razao ;
	return output;
}

bool Multa::operator ==(const Multa &right) {
	for (int i = 0; i < tamanhoAlocacao; i++) {
		if (this->alocacaoDinamica[i] != right.alocacaoDinamica[i]) {
			return false;
		}
	}
	
	return (this->razao == right.razao) && (this->pontos == right.pontos) && (this->valor == right.valor);
}

void Multa::operator =(const Multa &right) {
	this->razao = right.razao;
	this->pontos = right.pontos;
	this->valor = right.valor;
	
	for (int i = 0; i < tamanhoAlocacao; i++) {
		this->alocacaoDinamica[i] = right.alocacaoDinamica[i];
	}
}

Multa::Multa(const string & razao, float valor, int pontos)
{
	this->razao = razao;
	setValor(valor);
	this->pontos = pontos;
	
	this->alocacaoDinamica = new int[tamanhoAlocacao];
	for (int i = 0; i < tamanhoAlocacao;i++) {
		this->alocacaoDinamica[i] = 0;
	}
	
}

Multa::Multa(const Multa & multa)
{
	this->razao = multa.razao;
	this->pontos = multa.pontos;
	this->valor = multa.valor;
	
	this->alocacaoDinamica = new int[tamanhoAlocacao];
	for (int i = 0; i < tamanhoAlocacao;i++) {
		this->alocacaoDinamica[i] = multa.alocacaoDinamica[i];
	}
}


Multa::~Multa()
{
	delete [] alocacaoDinamica;
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