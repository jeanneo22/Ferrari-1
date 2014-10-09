#include <stdlib.h>
#include <iostream>
#include "Ferrari.h"

int main(int argc, char **argv)
{
	Ferrari f1;
	Ferrari::fabricar(&f1);
	std::cout << f1;

	system("pause");
	return 0;
}