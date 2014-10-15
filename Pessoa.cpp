#include "Pessoa.h"
#include <iostream>

Pessoa::Pessoa(const string & nome, int idade)
{
	this->nome = nome;
	this->idade = idade;
}

Pessoa Pessoa::cadastrar() {
	string nome;
	int idade;
	std::cout << "Insira o nome";
	std::cin >> nome;
	std::cout << "Insira a idade";
	std::cin >> idade;
	Pessoa p = Pessoa(nome,idade);
	return p;
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