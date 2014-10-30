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
	Carro *f1 = new Ferrari(Data(21,07,1999),Pessoa("Felipe Eliasquevici",19),true);
	

	Ferrari::updateSoftware("1.1.00");
	


	system("pause");
	return 0;
}