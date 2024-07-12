#ifndef _figura_h_
#define _figura_h_

#include "polje.h"
#include "Lista.h"
#include <string>
#include <iostream>

using namespace std;

class Figura {

	Polje* centar = nullptr;

	void kopiraj(const Figura& f);
	void premesti(Figura& f);
	void brisi() { 
		centar = nullptr;
	};
public:

	Figura(Polje& p): centar(&p) {
		polja.dodaj(*centar);
		listaPogodaka.dodaj(false);
	};
	Figura(const Figura& f)
	{
		polja.operator=(f.polja);
		listaPogodaka.operator=(f.listaPogodaka);
		*centar = *f.centar;
	}
	Figura(Figura&& f)
	{
		polja = f.polja;
		listaPogodaka = f.listaPogodaka;
		centar = f.centar;
	}
	Figura& operator=(const Figura& f)
	{
		if (this != &f)
		{
			brisi();
			polja.operator=(f.polja);
			listaPogodaka.operator=(f.listaPogodaka);
			centar = f.centar;
		}
		return *this;
	}
	Figura& operator=(Figura&& f)
	{
		if (this != &f)
		{
			brisi();
			polja = f.polja;
			listaPogodaka = f.listaPogodaka;
			centar = f.centar;
		}
		return *this;
	}


	bool pogodiPolje(const Polje &p);
	bool pogodjenaFigura();
	virtual char dohvatiOznaku() const = 0;

	bool operator&(const Figura& f) const;
	bool operator==(const Figura& f) const;

	//friend ostream& operator<< (ostream& os, const Figura& f);
	virtual ~Figura() {}
protected:
	Lista <Polje> polja;
	Lista <bool> listaPogodaka;
};

#endif


