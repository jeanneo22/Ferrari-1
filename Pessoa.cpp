#include "Pessoa.h"
#include <iostream>

const int Pessoa::tamanhoDna = 10;

ostream &operator<< (ostream &output, const Pessoa &pessoa) {
	output << pessoa.nome ;
	return output;
}

void Pessoa::operator =(const Pessoa &right) {
	this->nome = right.nome;
	this->idade = right.idade;
	this->cpf = right.cpf;
	for (int i = 0; i < tamanhoDna;i++) {
		this->dna[i] = right.dna[i];
	}
}

Pessoa::Pessoa(const string & nome, int idade, int cpf)
{
	this->nome = nome;
	this->idade = idade;
	this->cpf = cpf;
	this->dna = new char[tamanhoDna];
	for (int i = 0; i < tamanhoDna;i++) {
		this->dna[i] = 'A';
	}
}

Pessoa::Pessoa(const Pessoa & pessoa)
{
	this->nome = pessoa.nome;
	this->idade = pessoa.idade;
	this->cpf = pessoa.cpf;
	this->dna = new char[tamanhoDna];
	for (int i = 0; i < tamanhoDna;i++) {
		this->dna[i] = pessoa.dna[i];
	}
}

Pessoa::~Pessoa()
{
	delete [] dna;
}

const string& Pessoa::getNome() const {
	return nome;
}

void Pessoa::setNome(const string& nome) {
	this->nome = nome;
}

void Pessoa::setIdade(int idade) {
	this->idade = idade;
}
int Pessoa::getIdade() const {
	return idade;
}

void Pessoa::setCpf(int cpf) {
	this->cpf = cpf;
}
int Pessoa::getCpf() const {
	return cpf;
}

void Pessoa::setDnaNoIndice(char baseNitrogenada, int indice) 
{
	if (indice < 0 || indice >= tamanhoDna)
		return;
	
	if	(baseNitrogenada != 'A' && baseNitrogenada != 'T' && baseNitrogenada != 'G' && baseNitrogenada != 'C')
		baseNitrogenada = 'A';
		
	this->dna[indice] = baseNitrogenada;
}

char Pessoa::getDnaNoIndice(int indice) 
{
	if (indice >= 0 && indice < tamanhoDna)
		return dna[indice];
	return 0;
}