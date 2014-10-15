#include <iostream>
#include "Ferrari.h"
#include <string>
using std::string;
#include "Pessoa.h"

int main(int argc, char **argv)
{
	Ferrari f1;
	Ferrari::fabricar(&f1);
	std::cout << f1;
	
	f1.adicionarDono(Pessoa("Felipe"));

	f1.imprimirDonos();

	int esperar;
	std::cin >> esperar;
	return 0;
}