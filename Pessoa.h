#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using std::string;

class Pessoa
{
private:
	string nome;
	int idade;

public:
	Pessoa(const string& nome = "", int idade = 0);
	~Pessoa();
	static Pessoa cadastrar();
	
	void setIdade(int idade);
	void setNome(const string& nome);
	int getIdade() const ;
	const string& getNome() const ;
};

#endif // PESSOA_H
