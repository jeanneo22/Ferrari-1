#include <iostream>
using std::cin;
using std::cout;

#include <string>
using std::string;

#include <stdlib.h>

#include "Ferrari.h"
#include "Pessoa.h"

int main(int argc, char **argv)
{
	Ferrari f1;
	string modelo;
	float velocidadeMaxima;
	int totalMarchas;
	string resp;
	int dia,mes,ano;
	
	cout << "Voce deseja fabricar uma F599XX? <s/n>";
	cin >> resp;
	
	cout << "Insira o dia de fabricacao:";
	cin >> dia;
	cout << "Insira o dia de fabricacao:";
	cin >> mes;
	cout << "Insira o dia de fabricacao:";
	cin >> ano;
	
	if (resp == "s") {
		f1 = Ferrari(Data(dia,mes,ano),Pessoa("Felipe"), true);
	}
	else {
		cout << "Insira o modelo:";
		cin >> modelo;
		cout << "Insira a velocidade maxima:";
		cin >> velocidadeMaxima;
		cout << "Insira o total de marchas:";
		cin >> totalMarchas;
		f1 = Ferrari(modelo,velocidadeMaxima,totalMarchas,Data(dia,mes,ano), Pessoa("Felipe"));
	}	
	
	
	std::cout << f1;
	

	system("pause");
	return 0;
}