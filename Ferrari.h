#ifndef FERRARI_H
#define FERRARI_H


/*
Comando: Dentre outras funcionalidades propospostas por você, deve ter armazenado o codigo do modelo e sua velocidade maxima.
 Deve tambem armazenar se o motor turbo está ligado, marcha ativa e velocidade atual.

Requisitos funcionais: Todos os atributos e funções membros devem estar relacionados a classe 
 * 1. Pelo menos 4 atributos. OK
 * 2. pelo menos 4 funções membros sem incluir get e set  OK
 * 3. todos os atributos devem ser inicializados  OK
 * 4. tres construtores, incluindo um construtor de copia e construtor com paramentros default  OK
 * 5. deve ter um atributo string  OK
 * 6. um atributo static  OK
 * 7. um atributo const static OK
 * 8. dois metodos constante OK
 * 9. um array OK
 * 10. uma função inline OK
 * 11. metodo com passagem por referencia usando ponteiro  OK
 * 12. metodo static - deve ser chamado no main  OK
 * 13. composição com a classe data. OK

 * Usar a classe vetor OK
 * Alocação dinamica de memoria OK
 * sobrecarga do operador == OK
 * sobrecarga do operador << OK
 
 * Composição com mais duas classes OK
*/
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
	/*
	 * Sobrecarga dos operadores.
	 */ 
	bool operator== (const Ferrari &right);
	void operator= (const Ferrari &right);

	~Ferrari();

	/* 
	 * Construtores
	 */ 
	Ferrari(const string& modelo = "", float velocidadeMaxima = 300, int marchaTotal = 6, const Data& dataFabricacao = Data(25,9,2014), const Pessoa& dono = Pessoa());
	Ferrari(const Ferrari& copia);
	Ferrari(const Data& dataFabricacao,const Pessoa& dono, bool isF599XX = false);
	
	/*
	 * Fazer o update do software das ferraris. 
	 */
	static void updateSoftware(string versao);
	
	/*
	 * Trocar marcha
	 */ 
	void mudarMarcha(int marcha);
	
	/*
	 * Acelerar o carro.
	 */ 
	void acelerar(float quantidade);
	
	/*
	 * Desacelerar o carro.
	 */ 
	void desacelerar();
	
	/*
	 * Setar motor turbo para o valor oposto.
	 */ 
	inline void toggleMotorTurbo();
	
	/*
	 * Botar uma multa no carro.
	 */ 
	void adicionarMulta(const Multa &multa);
	
	/*
	 * Trocar dois carros de dono.
	 */ 
	static void trocarDonos(Ferrari * f1, Ferrari * f2);

	/*
	 * Funções para imprimir dados diversos.
	 */ 
	void imprimirVelocidade() const;
	void imprimirDados() const;	
	void imprimirMultas() const;

	/*
	 * Sets
	 */ 
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
	void setDinheiroPortaTreco(int valor, int indice);

	/*
	 * Gets
	 */ 
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


};
#endif
