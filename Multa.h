#ifndef MULTA_H
#define MULTA_H

#include <string>
using std::string;

class Multa
{
private:
	string razao;
	float valor;
	int pontos;
public:
	Multa(const string & razao = "", float valor = 100, int pontos = 3);
	~Multa();

	void setPontos(int pontos) ;
	void setRazao(const string& razao);
	void setValor(float valor);
	int getPontos() const;
	const string& getRazao() const;
	float getValor() const;

};

#endif // MULTA_H
