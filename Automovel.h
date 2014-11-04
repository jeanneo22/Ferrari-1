#ifndef AUTOMOVEL_H
#define AUTOMOVEL_H

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::ostream;

#include "Data.h"
#include "Pessoa.h"
#include "Multa.h"

#include <vector>
using std::vector;


class Automovel
{
	friend ostream &operator<<( ostream &, const Automovel &);
protected:


	string modelo;
	
	float velocidadeMaxima;
	float velocidadeAtual;
	
	Data dataFabricacao;
	
	int quantidadePortaTreco;
	int* dinheiroPortaTreco;
	
	Pessoa dono;
	
	vector<Multa> multas;
	
	void setVelocidadeAtual(float) ;
	
public:
	virtual void operator= (const Automovel &);

	Automovel(const string&, float  = 300, int = 5,const Data& = Data(25,9,2014), const Pessoa& = Pessoa());
	Automovel(const Automovel& );
	Automovel();

	virtual ~Automovel();
	
	static void trocarDonos(Automovel * , Automovel * );
	
	virtual void acelerar(float ) = 0;
	virtual void desacelerar() = 0;
	
	virtual void imprimirVelocidade() const;
	virtual void imprimirDados() const;	
	
	void setDataFabricacao(const Data&);
	void setModelo(const string& ) ;
	void setVelocidadeMaxima(float);
	void setDono(const Pessoa&) ;
	void setDinheiroPortaTreco(int , int );
	
	const Data& getDataFabricacao() const ;
	const string& getModelo() const ;
	float getVelocidadeAtual() const ;
	float getVelocidadeMaxima() const ;
	int getQuantidadePortaTreco() const ;
	int getQuantidadeRodas() const;
	Pessoa getDono() const;
	int getDinheiroPortaTreco(int ) const;	

};

#endif // AUTOMOVEL_H
