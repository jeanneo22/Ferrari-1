#include <stdlib.h>
#include <iostream>
#include "Ferrari.h"

int main(int argc, char **argv)
{
	Ferrari f1;
	Ferrari::fabricar(&f1);
	f1.imprimirDados();

	system("pause");
	return 0;
}