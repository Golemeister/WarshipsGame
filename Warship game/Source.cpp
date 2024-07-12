#include <iostream>
#include "figura.h"
#include "polje.h"
#include "Lista.h"
#include "jedrilica.h"

using namespace std;

int main() {

	try {
		Polje p1(G, 4);
		Polje p2(G, 6);
		Polje p4(B, 2);
		cout << p1 << p2;

		cout << (p1 == p2) << endl;

		Polje p3 = p2.dohvatiPolje(2, 3);

		cout << p2 <<p3;
		Lista < Polje> l1;
		Jedrilica j1(p1);
		Jedrilica j2(p2);
		Jedrilica j3(p4);
		cout << j1 << j2;
		/*cout << (j1&j2);
		cout << (j1&j3);*/
		cout << j1.pogodiPolje(Polje(F, 3)) << endl;
		cout << j1.pogodiPolje(Polje(F, 4)) << endl;
		cout << j1.pogodiPolje(Polje(F, 5)) << endl;
		cout << j1.pogodiPolje(Polje(G, 4)) << endl;
		cout << j1.pogodiPolje(Polje(H, 3)) << endl;
		cout << j1.pogodiPolje(Polje(H, 4)) << endl;
		//cout << j1.pogodiPolje(Polje(H, 5)) << endl;
		cout << j1.pogodjenaFigura();

		cout << (j1 == j2);

		j1 = j2;

		cout << j2;

		l1.dodaj(p1);
	}
	catch (exception e) {
		cout << e.what() << endl;
	}

	return 0;
}