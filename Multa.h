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
	
	int* alocacaoDinamica;
	const static int tamanhoAlocacao;
	
	const static float valorMaximo;
	
public:
	bool operator== (const Multa &right);
	void operator= (const Multa &right);

	Multa(const string & razao = "", float valor = 100, int pontos = 3);
	Multa(const Multa& multa);
	~Multa();

	void setPontos(int pontos) ;
	int getPontos() const;
	
	void setRazao(const string& razao);
	const string& getRazao() const;
	
	void setValor(float valor);
	float getValor() const;
};

#endif // MULTA_H
