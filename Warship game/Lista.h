#ifndef _lista_h_
#define _lista_h_
#include<iostream>
#include<exception>

using namespace std;

class GNepostoji :public exception {
public:
	GNepostoji() :exception("Ne postoji dati element!") {}
};

template<typename T>
class Lista {
	struct Elem {
		T info;
		Elem* sled;
		Elem(const T& t, Elem* sl = nullptr) : info(t), sled(sl) {}
	};
	Elem* prvi, * posl;
	int br;
	void kopiraj(const Lista& l);
	void premesti(Lista& l);
	void brisi();
public:
	Lista() {
		prvi = posl = nullptr;
		br = 0;
	}
	Lista(const Lista& l)
	{
		kopiraj(l);
	}
	Lista(Lista&& l)
	{
		premesti(l);
	}
	Lista& operator=(const Lista& l)
	{
		if (this != &l)
		{
			brisi();
			kopiraj(l);
		}
		return *this;
	}
	Lista& operator=(Lista&& l)
	{
		if (this != &l)
		{
			brisi();
			premesti(l);
		}
		return *this;
	}
	~Lista()
	{
		brisi();
	}
	Lista& operator+=(const T& t)
	{
		posl = (!prvi ? prvi : posl->sled) = new Elem(t);
		br++;
		return *this;
	}


	Lista& dodaj(const T& t) {
		posl = (!prvi ? prvi : posl->sled) = new Elem(t);
		br++;
		return *this;
	}

	Lista& izbaci(int i) {
		if (i >= br || i < 0 || br < 1) throw GNepostoji();
		else
		{
			Elem* tek = prvi;
			Elem* pret = nullptr;
			int j;
			for (j = 0; j < i; j++) {
				pret = tek;
				tek = tek->sled;
			}
			if (prvi == posl) {
				delete prvi;
				prvi = posl = nullptr;
			}
			else if (pret == nullptr) {
				tek = tek->sled;
				delete prvi;
				this->prvi = tek;
			}
			else if (tek == this->posl) {
				delete posl;
				posl = pret;
				pret->sled = nullptr;
			}
			else {
				pret->sled = tek->sled;
				delete tek;
			}
			br--;
		}
	}

	Lista& izmeni(int i, const T& t) {
		if (i >= br || i < 0 || br < 1) throw GNepostoji();
		else
		{
			Elem* tek = prvi;
			for (int j = 0; j < i; j++) {

				tek = tek->sled;
			}
			tek->info = t;
		}
	}

	T& operator[](int i)
	{
		if (i >= br || i < 0 || br < 1) throw GNepostoji();
		else {
			Elem* tek = prvi;
			for (int j = 0; j < i; j++)
				tek = tek->sled;
			return tek->info;
		}
	}
	const T& operator[](int i) const
	{
		if (i >= br || i < 0 || br < 1) throw GNepostoji();
		else {
			Elem* tek = prvi;
			for (int j = 0; j < i; j++)
				tek = tek->sled;
			return tek->info;
		}
	}

	bool operator()(int i) const
	{
		if (i >= br || i < 0 || br < 1) throw GNepostoji();
		else {
			Elem* tek = prvi;
			for (int j = 0; j < i; j++)
				tek = tek->sled;
			return tek->info != nullptr;
		}
	}

	bool operator()(const T& t) const //Ubacena i ova varijanta operatora jer mi u daljem toku zadatka delovalo da ima vise smisla
	{
		Elem* tek = prvi;
		for (int i = 0; i < br; i++) {
			if (tek->info == t) return true;
			tek = tek->sled;
		}
		return false;
	}

	int kap() const { return br; }
};

template<typename T>
void Lista<T>::kopiraj(const Lista& l) {
	for (Elem* tek = l.prvi; tek; tek = tek->sled)
		posl = (!prvi ? prvi : posl->sled) = new Elem(tek->info);
}

template<typename T>
void Lista<T>::premesti(Lista& l)
{
	prvi = l.prvi;
	posl = l.posl;
	l.posl = l.prvi = nullptr;
}

template<typename T>
void Lista<T>::brisi()
{
	while (prvi)
	{
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
	prvi = posl = nullptr;
}

#endif


