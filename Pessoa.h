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
<<<<<<< HEAD
	char* dna; //Excesso de criatividade.

	const static int tamanhoDna;
public:
	/*
	 * Sobrecarga de operadores
	 */ 
	bool operator== (const Pessoa &right);
	void operator= (const Pessoa &right);

	/*
	 * Construtores
	 */ 
	Pessoa(const string& nome = "", int idade = 0, int cpf = 0);
	Pessoa(const Pessoa& pessoa);
	~Pessoa();


	/*
	 * Gets e Sets
	 */ 
=======
	
	string* motivosParaComprar;
	int quantidadeMotivos;
	const static int maximoMotivos;
public:
	void operator= (const Pessoa &right);

	Pessoa(const string& = "", int = 0, int = 0);
	Pessoa(const Pessoa& );
	~Pessoa();

	void adicionarMotivo(const string& );
	string getMotivoNoIndice(int indice);
	void imprimirMotivos();

>>>>>>> origin/Herança
	void setIdade(int idade);
	int getIdade() const ;

	void setNome(const string& nome);
	const string& getNome() const ;

	void setCpf(int cpf);
	int getCpf() const ;
	
};

#endif // PESSOA_H
