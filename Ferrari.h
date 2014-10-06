#ifndef FERRARI_H
#define FERRARI_H

#include <string>
using std::string;

#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Data.h"

#include <vector>
using std::vector;

class Ferrari
{
private:
	string modelo;
	float velocidadeMaxima;
	int marchaTotal;
	Data dataFabricacao;
	static int qtdFabricada;
	const static Ferrari F599XX;
	bool motorTurbo;
	int marchaAtiva;
	float velocidadeAtual;
public:
	Ferrari(string modelo = "", float velocidadeMaxima = 300, int marchaTotal = 6, const Data& dataFabricacao = Data(25,9,2014));
	Ferrari(const Ferrari& copia);
	Ferrari(const Data& dataFabricacao, bool isF599XX = false);
	static void fabricar(Ferrari * fabricar);
	void mudarMarcha(int marcha);
	void acelerar(float quantidade);
	void desacelerar();
	inline void toggleMotorTurbo();
	
	void imprimirVelocidade() const;
	void imprimirDados() const;	
	
	void setDataFabricacao(const Data& dataFabricacao);
	void setMarchaAtiva(int marchaAtiva) ;
	void setMarchaTotal(int marchaTotal) ;
	void setModelo(const string& modelo) ;
	void setMotorTurbo(bool motorTurbo) ;
	void setNumeroChassi() ;
	void setQuantidadeFabricada(int quantidadeFabricada) ;
	void setVelocidadeAtual(float velocidadeAtual) ;
	void setVelocidadeMaxima(float velocidadeMaxima) ;
	
	const Data& getDataFabricacao() const ;
	int getMarchaAtiva() const ;
	int getMarchaTotal() const ;
	const string& getModelo() const ;
	bool isMotorTurbo() const ;
	const string& getNumeroChassi() const ;
	int getQuantidadeFabricada() const ;
	float getVelocidadeAtual() const ;
	float getVelocidadeMaxima() const ;

};
#endif
