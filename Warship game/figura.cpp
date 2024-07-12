#include "figura.h"


bool Figura::pogodiPolje(const Polje& p)
{
	for (int i = 0; i < polja.kap(); i++){
		if (polja[i] == p && listaPogodaka[i] == false) {
			listaPogodaka.izmeni(i, true);
			return true;
		}
	}
	return false;
}

bool Figura::pogodjenaFigura()
{
	for (int i = 0; i < polja.kap(); i++) {
		if (listaPogodaka[i] == false) return false;
	}
	return true;
}

bool Figura::operator&(const Figura& f) const
{
	for (int i = 0; i < f.polja.kap(); i++) {
		if (polja(f.polja[i])) return true;
	}
	return false;
}

bool Figura::operator==(const Figura& f) const
{
	
	return this->dohvatiOznaku() == f.dohvatiOznaku();;
}
