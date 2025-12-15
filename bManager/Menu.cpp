#include "Menu.h"

PozycjaMenu::PozycjaMenu(string n, double c, int t) {
	nazwa = n;
	cena = c;
	czasPrzygotowania = t;
}

DanieGlowne::DanieGlowne(string n, double c, int t)
	: PozycjaMenu(n, c, t) {}

void DanieGlowne::wyswietl() const {
	cout << "[DANIE] " << nazwa << " " << cena << " PLN\n";
}

Napoj::Napoj(string n, double c, int t, bool i)
	: PozycjaMenu(n, c, t), zLodem(i) {}

void Napoj::wyswietl() const {
	cout << "[NAPOJ]" << nazwa << " " << cena << " PLN" << (zLodem ? " z lodem" : "") << endl;
}