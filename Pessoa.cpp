#include "Pessoa.h"
#include <iostream>

Pessoa::Pessoa(const string & nome, int idade)
{
	this->nome = nome;
	this->idade = idade;
}

Pessoa::~Pessoa()
{
}

void Pessoa::setIdade(int idade) {
		this->idade = idade;
	}
	void Pessoa::setNome(const string& nome) {
		this->nome = nome;
	}
	int Pessoa::getIdade() const {
		return idade;
	}
	const string& Pessoa::getNome() const {
		return nome;
	}