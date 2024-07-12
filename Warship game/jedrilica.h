#ifndef _jedrilica_h_
#define _jedrilica_h_

#include "figura.h"
#include "polje.h"
#include <string>
#include <iostream>

using namespace std;

class Jedrilica : public Figura{

	char oznaka;

public:

	Jedrilica(Polje& p): Figura(p),oznaka('H') {
		for (int i = -1; i < 2; i++) {

			Polje* novi = &p.dohvatiPolje(-1,i);
			polja.dodaj(*novi);
			listaPogodaka.dodaj(false);
		}
		for (int i = -1; i < 2; i++) {

			Polje* novi = &p.dohvatiPolje(1, i);
			polja.dodaj(*novi);
			listaPogodaka.dodaj(false);
		}
	}
	char dohvatiOznaku() const override { return oznaka; }

	friend ostream& operator<< (ostream& os, const Jedrilica& j) {
		for (int i = 0; i < j.polja.kap(); i++){
			os << j.polja[i] << " ";
		}
		return os << endl;
	}

	~Jedrilica() {};
};

#endif
