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
#include "Carro.h"
#include <vector>
using std::vector;

class Ferrari : public Carro
{
	friend ostream &operator<<( ostream &, const Ferrari &);
private:
	static string versaoSoftware;
	
	bool motorTurbo;
	int marchaAtiva;
	float velocidadeAtual;
	Pessoa dono;
	vector<Multa> multas;
public:
	/*
	 * Sobrecarga dos operadores.
	 */ 
	bool operator== (const Ferrari &right);
	void operator= (const Ferrari &right);

public:
	void operator= (const Ferrari &);

	Ferrari(const string&  = "", float  = 300, int  = 6, const Data& = Data(25,9,2014), const Pessoa& = Pessoa());
	Ferrari(const Ferrari& );
	Ferrari(const Data& ,const Pessoa& , bool  = false);
	
	static void updateSoftware(string );	
	inline void toggleMotorTurbo();
	void setMotorTurbo(bool ) ;
	bool isMotorTurbo() const ;
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
	 * Acelerar o carro.
	 */ 
	void acelerar(float quantidade);
	
	/*
	 * Setar motor turbo para o valor oposto.
	 */ 
	inline void toggleMotorTurbo();

	/*
	 * Funções para imprimir dados diversos.
	 */ 
	void imprimirVelocidade() const;
	void imprimirDados() const;	
	void imprimirMultas() const;

	/*
	 * Sets
	 */ 
	void setMotorTurbo(bool motorTurbo) ;
	/*
	 * Gets
	 */ 
	bool isMotorTurbo() const ;

	void acelerar(float );
};
#endif
