#include "Jipe.h"
using std::cout;
using std::cin;

Jipe::Jipe(const string& modelo, float velocidadeMaxima, int marchaTotal, int quantidadePortaTreco, const Data& dataFabricacao,const Pessoa& dono) : Carro(modelo,velocidadeMaxima,marchaTotal,quantidadePortaTreco,dataFabricacao,dono)
{
	setTracaoQuatroRodas(false);
}

Jipe::Jipe(const Jipe& jipe) : Carro(jipe)
{
	this->tracaoQuatroRodas = jipe.tracaoQuatroRodas;
}

Jipe::Jipe(bool isModelo) : Carro()
{
	if (isModelo) {
		setModelo("Modelo");
		setVelocidadeMaxima(260);
		setMarchaTotal(6);		
	}
	
	setTracaoQuatroRodas(false);
}

void Jipe::operator =(const Jipe &right) {
	this->Automovel::operator=(right);
	tracaoQuatroRodas = right.tracaoQuatroRodas;
}

void Jipe::acelerar(float quantidade)
{
	if (tracaoQuatroRodas)	quantidade *= 1.2f;
	setVelocidadeAtual(velocidadeAtual+quantidade);
}

void Jipe::desacelerar()
{
	setVelocidadeAtual(velocidadeAtual-50);
}

void Jipe::setTracaoQuatroRodas(bool tracaoQuatroRodas) {
	this->tracaoQuatroRodas = tracaoQuatroRodas;
}

bool Jipe::isTracaoQuatroRodas() const {
	return tracaoQuatroRodas;
}

ostream &operator<< (ostream &output, const Jipe &jipe) {
	//output << "Jipe:" << static_cast<Automovel>(jipe);
	return output;
}
