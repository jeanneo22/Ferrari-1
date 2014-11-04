#ifndef FERRARI_H
#define FERRARI_H

#include <string>
using std::string;

#include <iostream>
using std::ostream;

#include "Carro.h"
#include <vector>
using std::vector;

class Ferrari : public Carro
{
	friend ostream &operator<<( ostream &, const Ferrari &);
private:
	static string versaoSoftware;
	bool motorTurbo;
public:
	void operator= (const Ferrari &);

	Ferrari(const string&  = "", float  = 300, int  = 6, int = 5, const Data& = Data(25,9,2014), const Pessoa& = Pessoa());
	Ferrari(const Ferrari& );
	Ferrari(bool);
	
	static void updateSoftware(string );	
	inline void toggleMotorTurbo() { setMotorTurbo(!motorTurbo); };
	
	void acelerar(float );
	void desacelerar();
	
	void setMotorTurbo(bool ) ;
	bool isMotorTurbo() const ;
};
#endif
