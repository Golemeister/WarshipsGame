#ifndef _polje_h_
#define _polje_h_

#include <string>
#include <iostream>
#include<exception>

using namespace std;

class Greska :public exception {
public:
	Greska() :exception("Van opsega!") {}
};

enum Kolone { A, B, C, D, E, F, G, H, I, J};

class Polje {
	Kolone kol;
	int red;
	static string str_kolone[];
	
	void kopiraj(const Polje& p);
	void premesti(Polje& p);
	void brisi();
public:

	Polje() = delete;
	Polje(Kolone kol,int red){
		if (kol < A || kol > J || red < 1 || red > 10) throw Greska();
			this->kol = kol;
			this->red = red;
	}
	Polje(const Polje& p){
		red = p.red;
		kol = p.kol;
	}
	/*Polje(const Polje& p)
	{
		kopiraj(p);
	}
	Polje(Polje&& p);
	Polje& operator=(const Polje& p);
	Polje& operator=(Polje&& p);*/
	
	Kolone dohvatiKolonu() const {
		return kol;
	}
	int dohvatiRed() const {
		return red;
	}

	Polje& dohvatiPolje(int parKol,int parRed);
	bool operator==(const Polje& p) const;

	friend ostream& operator<< (ostream& os, const Polje& p) {
		return os << str_kolone[p.kol] << p.dohvatiRed() << endl;
	}

};

//void Polje::kopiraj(const Polje& p) {
//	red = p.red;
//	kol = p.kol;
//}
#endif

