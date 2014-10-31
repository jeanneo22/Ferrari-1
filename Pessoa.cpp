
#include "Pessoa.h"
#include <iostream>

const int Pessoa::maximoMotivos = 6;

Pessoa::Pessoa(const string & nome, int idade, int cpf)
{
	this->nome = nome;
	this->idade = idade;
	this->cpf = cpf;
	this->quantidadeMotivos = 0;
	this->motivosParaComprar = 0;
}

Pessoa::Pessoa(const Pessoa & pessoa)
{
	this->nome = pessoa.nome;
	this->idade = pessoa.idade;
	this->cpf = pessoa.cpf;
	this->quantidadeMotivos = pessoa.quantidadeMotivos;
	this->motivosParaComprar = new string[quantidadeMotivos];
	for (int i = 0; i < quantidadeMotivos;i++) {
		this->motivosParaComprar[i] = pessoa.motivosParaComprar[i];
	}
}

Pessoa::~Pessoa()
{
	delete [] motivosParaComprar;
}

void Pessoa::operator =(const Pessoa &right) {
	this->nome = right.nome;
	this->idade = right.idade;
	this->cpf = right.cpf;
	delete [] this->motivosParaComprar;
	this->quantidadeMotivos = right.quantidadeMotivos;
	this->motivosParaComprar = new string[quantidadeMotivos];
	for (int i = 0; i < quantidadeMotivos;i++) {
		this->motivosParaComprar[i] = right.motivosParaComprar[i];
	}
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

void Pessoa::adicionarMotivo(const string& motivo) {
	if (quantidadeMotivos >= maximoMotivos) return;
	
	string* temporario = new string[++quantidadeMotivos];
	for (int i = 0; i < quantidadeMotivos-1; i++) {
		temporario[i] = motivosParaComprar[i];
	}
	temporario[quantidadeMotivos-1] = motivo;
	delete [] motivosParaComprar;

	motivosParaComprar = temporario;
}


string Pessoa::getMotivoNoIndice(int indice) {
	if (indice >= 0 && indice < quantidadeMotivos) {
		return motivosParaComprar[indice];
	}
	return "";
}

void Pessoa::imprimirMotivos() {
	for (int i = 0; i < quantidadeMotivos; i++) {
		std::cout << motivosParaComprar[i] << "\n";
	}
}


ostream &operator<< (ostream &output, const Pessoa &pessoa) {
	output << pessoa.nome ;
	return output;
}
