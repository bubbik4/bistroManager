#include "Menu.h"

PozycjaMenu::PozycjaMenu(string n, double c, int t) {
	nazwa = n;
	cena = c;
	czasPrzygotowania = t;
}

PozycjaMenu::DanieGlowne(string n, double c, int t)
	: PozycjaMenu(n, c, t) {}

PozycjaMenu::Napoj(string n, double c, int t, bool i)
	: PozycjaMenu(n, c, t), zLodem(i); {}