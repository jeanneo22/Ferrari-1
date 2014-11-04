#ifndef LANCER_H
#define LANCER_H

#include <string>
using std::string;

#include <iostream>
using std::ostream;

#include "Carro.h"
#include <vector>
using std::vector;

class Lancer : public Carro
{
	friend ostream &operator<<( ostream &, const Lancer &);
private:
	bool controleDrift;
public:
	void operator= (const Lancer &);

	Lancer(const string&  = "", float  = 300, int  = 6, int = 5, const Data& = Data(25,9,2014), const Pessoa& = Pessoa());
	Lancer(const Lancer& );
	Lancer(bool);
	
	static void updateSoftware(string );	
	inline void toggleControleDrift() { setControleDrift(!controleDrift); };
	
	void acelerar(float );
	void desacelerar();
	
	void setControleDrift(bool ) ;
	bool isControleDrift() const ;
};

#endif // LANCER_H
