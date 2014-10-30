#ifndef PESSOA_H
#define PESSOA_H

/*
    Operator = OK
    Alocação dinâmica - se houver vazamento de memória a classe toda é desconsiderada OK
    Usar o destrutor OK
    Construtor de cópia OK
    Operator << friend OK
    Um const static OK
 * */

#include <string>
using std::string;

#include <iostream>
using std::ostream;

class Pessoa
{
	friend ostream &operator<<( ostream &, const Pessoa &);
private:
	string nome;
	int idade;
	int cpf;
	char* dna;

	const static int tamanhoDna;
public:
	void operator= (const Pessoa &right);

	Pessoa(const string& nome = "", int idade = 0, int cpf = 0);
	Pessoa(const Pessoa& pessoa);
	~Pessoa();

	void setIdade(int idade);
	int getIdade() const ;

	void setNome(const string& nome);
	const string& getNome() const ;

	void setCpf(int cpf);
	int getCpf() const ;

	void setDnaNoIndice(char baseNitrogenada, int indice);
	char getDnaNoIndice(int indice) ;
	
};

#endif // PESSOA_H
