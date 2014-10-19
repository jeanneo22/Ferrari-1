#ifndef FERRARI_H
#define FERRARI_H

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

class Ferrari
{
	friend ostream &operator<<( ostream &, const Ferrari &);
private:
	static string versaoSoftware;
	const static Ferrari F599XX;
	const static int quantidadePortaTreco;
	
	string modelo;
	float velocidadeMaxima;
	int marchaTotal;
	Data dataFabricacao;
	bool motorTurbo;
	int marchaAtiva;
	float velocidadeAtual;
	int* dinheiroPortaTreco;
	Pessoa dono;
	vector<Multa> multas;
public:
	bool operator== (const Ferrari &right);
	void operator= (const Ferrari &right);

	~Ferrari();

	Ferrari(const string& modelo = "", float velocidadeMaxima = 300, int marchaTotal = 6, const Data& dataFabricacao = Data(25,9,2014), const Pessoa& dono = Pessoa());
	Ferrari(const Ferrari& copia);
	Ferrari(const Data& dataFabricacao,const Pessoa& dono, bool isF599XX = false);
	
	static void updateSoftware(string versao);
	
	void mudarMarcha(int marcha);
	void acelerar(float quantidade);
	void desacelerar();
	inline void toggleMotorTurbo();
	void adicionarMulta(const Multa &multa);
	static void trocarDonos(Ferrari * f1, Ferrari * f2);

	void imprimirVelocidade() const;
	void imprimirDados() const;	
	void imprimirMultas() const;

	void setDataFabricacao(const Data& dataFabricacao);
	void setMarchaAtiva(int marchaAtiva) ;
	void setMarchaTotal(int marchaTotal) ;
	void setModelo(const string& modelo) ;
	void setMotorTurbo(bool motorTurbo) ;
	void setNumeroChassi() ;
	void setQuantidadeFabricada(int quantidadeFabricada) ;
	void setVelocidadeAtual(float velocidadeAtual) ;
	void setVelocidadeMaxima(float velocidadeMaxima) ;
	void setDono(const Pessoa& dono) ;

	const Data& getDataFabricacao() const ;
	int getMarchaAtiva() const ;
	int getMarchaTotal() const ;
	const string& getModelo() const ;
	bool isMotorTurbo() const ;
	const string& getNumeroChassi() const ;
	int getQuantidadeFabricada() const ;
	float getVelocidadeAtual() const ;
	float getVelocidadeMaxima() const ;
	int getQuantidadePortaTreco() const ;
	Pessoa getDono() const;

	int getDinheiroPortaTreco(int indice) const;
	void setDinheiroPortaTreco(int valor, int indice);

};
#endif
