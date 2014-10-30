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
	
	f1->toggleMotorTurbo();
	//Ferrari f2 = f1;

	Ferrari::updateSoftware("1.1.00");
	
	//cout << ((Ferrari)(*f1));// << std::endl << f2;
	
	//f1.setDinheiroPortaTreco(4,3);
	//cout << f1.getDinheiroPortaTreco(3) << " " << f2.getDinheiroPortaTreco(3) << "\n";

	system("pause");
	return 0;
}