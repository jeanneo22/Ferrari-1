#ifndef CARRO_H
#define CARRO_H

#include "Automovel.h"

class Carro : public Automovel
{
	friend ostream &operator<<( ostream &, const Carro &);
private:
	const static int quantidadeRodas;
	int marchaAtiva;
	int marchaTotal;
	
public:
	virtual void operator= (const Carro &);

	Carro(const string&, float  = 300, int  = 6, int = 5,const Data& = Data(25,9,2014), const Pessoa& = Pessoa());
	Carro(const Carro& );
	Carro();
	virtual ~Carro();

	void mudarMarcha(int );
	
	virtual void acelerar(float ) = 0;
	virtual void desacelerar() = 0;
	
	virtual void imprimirVelocidade() const;
	virtual void imprimirDados() const;	
	
	void adicionarMulta(const Multa &);
	void imprimirMultas() const;
	
	void setMarchaTotal(int) ;
	
	int getMarchaAtiva() const ;
	int getMarchaTotal() const ;	
protected:
	
	
	void setMarchaAtiva(int) ;
};

#endif // CARRO_H
