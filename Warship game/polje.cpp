#include "polje.h"

string Polje::str_kolone[] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J" };

Polje& Polje::dohvatiPolje(int parKol,int parRed)
{
	Kolone k;
	int r;
	int temp = static_cast<int>(kol) + parKol;
	if (temp <= J) {
		k = static_cast<Kolone>(temp);
	}
	if (red+parRed <= 10) {
		 r= red + parRed;
	}
	Polje* novo = new Polje(k, r);
	return *novo;
}

bool Polje::operator==(const Polje& p) const
{
	return (p.kol == kol && p.red == red);
}

