#ifndef MULTA_H
#define MULTA_H

/*
    Operator = OK
    Alocação dinâmica - se houver vazamento de memória a classe toda é desconsiderada
    Usar o destrutor
    Construtor de cópia OK
    Operator << friend OK
    Um const static OK
 * */


#include <string>
using std::string;

#include <iostream>
using std::ostream;

class Multa
{
	friend ostream &operator<<( ostream &, const Multa &);
private:
	string razao;
	float valor;
	int pontos;
	
	// Falta de criatividade 1
	int* alocacaoDinamica;
<<<<<<< HEAD
	// Falta de criatividade 2
	const static int tamanhoAlocacao;
=======
	int tamanhoAlocacao;
>>>>>>> origin/Herança
	
	const static float valorMaximo;
	
public:
<<<<<<< HEAD
	/* 
	 * Sobrecarga de operadores.
	 */ 
	bool operator== (const Multa &right);
	void operator= (const Multa &right);

	/*
	 * Construtores
	 */ 
	Multa(const string & razao = "", float valor = 100, int pontos = 3);
=======
	void operator= (const Multa &right);

	Multa(const string &  = "", float  = 100, int  = 3, int = 5);
>>>>>>> origin/Herança
	Multa(const Multa& multa);
	~Multa();

	/*
	 * gets e sets.
	 */ 
	void setPontos(int pontos) ;
	int getPontos() const;
	
	void setRazao(const string& razao);
	const string& getRazao() const;
	
	void setValor(float valor);
	float getValor() const;
};

#endif // MULTA_H
