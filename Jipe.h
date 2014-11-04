#ifndef JIPI_H
#define JIPI_H

#include <string>
using std::string;

#include <iostream>
using std::ostream;

#include "Carro.h"
#include <vector>
using std::vector;

class Jipe : public Carro
{
	friend ostream &operator<<( ostream &, const Jipe &);
private:
	static string versaoSoftware;
	bool tracaoQuatroRodas;
public:
	void operator= (const Jipe &);

	Jipe(const string&  = "", float  = 300, int  = 6, int = 5, const Data& = Data(25,9,2014), const Pessoa& = Pessoa());
	Jipe(const Jipe& );
	Jipe(bool);
	
	static void updateSoftware(string );	
	inline void toggleTracaoQuatroRodas() { setTracaoQuatroRodas(!tracaoQuatroRodas); };
	
	void acelerar(float );
	void desacelerar();
	
	void setTracaoQuatroRodas(bool ) ;
	bool isTracaoQuatroRodas() const ;
};
#endif
