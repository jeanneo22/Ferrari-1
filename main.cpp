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
	Ferrari f1 = Ferrari(Data(21,07,1999),Pessoa("Felipe Eliasquevici",19),true);
	Ferrari f2 = Ferrari("Formula 1", 500, 9, Data(20,12,2013),Pessoa("Felipe Massa",89));


	f1.imprimirDados();
	f2.imprimirDados();

	Ferrari::updateSoftware("1.1.00");
	Ferrari::trocarDonos(&f1,&f2);

	f1.imprimirDados();
	f2.imprimirDados();

	system("pause");
	return 0;
}