#include "Carro.h"

const int Carro::quantidadeRodas = 4;

Carro::Carro(const string& modelo, float velocidadeMaxima, int marchaTotal, int quantidadePortaTreco, const Data& dataFabricacao,const Pessoa& dono) : Automovel(modelo,velocidadeMaxima,quantidadePortaTreco,dataFabricacao,dono)
{
	setMarchaTotal(marchaTotal);
	marchaAtiva = 0;
	this->multas = vector<Multa>();
}

Carro::Carro(const Carro& carro) : Automovel(carro)
{
	marchaTotal = carro.marchaTotal;
	marchaAtiva = carro.marchaAtiva;

	this->multas = vector<Multa>();
	for (size_t i = 0; i < carro.multas.size();i++) {
		this->multas.push_back(carro.multas[i]);
	}
}

Carro::Carro() : Automovel()
{
	marchaTotal = 5;
	marchaAtiva = 0;
	this->multas = vector<Multa>();
}

void Carro::operator =(const Carro &right) {
	dataFabricacao = right.dataFabricacao;
	modelo = right.modelo;
	marchaTotal = right.marchaTotal;
	velocidadeMaxima = right.velocidadeMaxima;
	marchaAtiva = right.marchaAtiva;
	velocidadeAtual = right.velocidadeAtual;
	quantidadePortaTreco = right.quantidadePortaTreco;
	delete [] dinheiroPortaTreco;
	dinheiroPortaTreco = new int[quantidadePortaTreco];
	for (int i = 0; i < quantidadePortaTreco;i++) {
		this->dinheiroPortaTreco[i] = right.dinheiroPortaTreco[i];
	}
	
	this->dono = right.dono;
	this->multas = vector<Multa>();
	for (size_t i = 0; i < right.multas.size();i++) {
		this->multas.push_back(right.multas[i]);
	}
}

Carro::~Carro()
{
	delete [] dinheiroPortaTreco;
}

void Carro::adicionarMulta(const Multa &multa) {
	multas.push_back(multa);
}

void Carro::imprimirMultas() const {
	for (unsigned int i = 0; i < multas.size(); i++) {
		cout << ((Multa)multas[i]).getRazao() << " Pontos: " << ((Multa)multas[i]).getPontos() << " Valor: " << ((Multa)multas[i]).getValor();
	}
	cout << std::endl;
}

void Carro::mudarMarcha(int marcha)
{
	setMarchaAtiva(marcha);
}

void Carro::acelerar(float quantidade)
{
	setVelocidadeAtual(velocidadeAtual+quantidade);
}

void Carro::desacelerar()
{
	setVelocidadeAtual(velocidadeAtual-30);
}

void Carro::imprimirDados() const{
	cout << "Carro: \n";
	Automovel::imprimirDados();
}

void Carro::imprimirVelocidade() const{
	cout << "Velocidade:" << velocidadeAtual << "/" << velocidadeMaxima;
	cout << " Marcha: " << marchaAtiva << "/" << marchaTotal;
	cout << std::endl;
}

void Carro::setMarchaTotal(int marchaTotal) {
	if (marchaTotal < 4) {
		this->marchaTotal = marchaTotal;		
	}
	else {
		this->marchaTotal = marchaTotal;
	}
}


int Carro::getMarchaAtiva() const {
	return marchaAtiva;
}
int Carro::getMarchaTotal() const {
	return marchaTotal;
}

void Carro::setMarchaAtiva(int marcha)
{
	this->marchaAtiva = std::min(std::max(0,marcha), marchaTotal);
}

ostream &operator<< (ostream &output, const Carro &carro) {
	output << "Carro:" << static_cast<const Automovel&>(carro);
	return output;
}