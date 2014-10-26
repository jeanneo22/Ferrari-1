#ifndef CARRO_H
#define CARRO_H

#include <string>
using std::string;

#include <vector>
#include <list>
#include <iostream>
using std::ostream;
//#include <assert.h>

#include "Data.h"
#include "Pessoa.h"
#include "Multa.h"

#include <vector>
using std::vector;


class Carro
{
	friend ostream &operator<<( ostream &, const Carro &);
private:
	const static int quantidadePortaTreco;
	
	string modelo;
	float velocidadeMaxima;
	int marchaTotal;
	Data dataFabricacao;
	
	int marchaAtiva;
	float velocidadeAtual;
	int* dinheiroPortaTreco;
	Pessoa dono;
	vector<Multa> multas;
public:
	bool operator== (const Carro &);
	void operator= (const Carro &);


	Carro(const string&  = "", float  = 300, int  = 6, const Data& = Data(25,9,2014), const Pessoa& = Pessoa());
	Carro(const Carro& );
	Carro(const Data& ,const Pessoa& );
	virtual ~Carro();

	void mudarMarcha(int );
	void acelerar(float );
	void desacelerar();
	
	void adicionarMulta(const Multa &);
	static void trocarDonos(Carro * , Carro * );

	void imprimirVelocidade() const;
	void imprimirDados() const;	
	void imprimirMultas() const;
	
	void setDataFabricacao(const Data&);
	void setMarchaAtiva(int) ;
	void setMarchaTotal(int) ;
	void setModelo(const string& ) ;
	void setQuantidadeFabricada(int) ;
	void setVelocidadeAtual(float) ;
	void setVelocidadeMaxima(float) ;
	void setDono(const Pessoa&) ;
	
	const Data& getDataFabricacao() const ;
	int getMarchaAtiva() const ;
	int getMarchaTotal() const ;
	const string& getModelo() const ;
	int getQuantidadeFabricada() const ;
	float getVelocidadeAtual() const ;
	float getVelocidadeMaxima() const ;
	int getQuantidadePortaTreco() const ;
	Pessoa getDono() const;

	int getDinheiroPortaTreco(int ) const;
	void setDinheiroPortaTreco(int , int );
};

#endif // CARRO_H