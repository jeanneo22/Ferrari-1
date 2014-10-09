#include <stdlib.h>
#include <iostream>
#include "Ferrari.h"
#include <string>
using std::string;

int main(int argc, char **argv)
{
	Ferrari f1;
	Ferrari::fabricar(&f1);
	std::cout << f1;
	
	f1.adicionarDono("Felipe");
	f1.adicionarDono("Bill Gates");

	f1.imprimirDonos();

	system("pause");
	return 0;
}