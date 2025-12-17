#pragma once
#include <iostream>

using namespace std;

// Klasa abstrakcyjna dla menu
class PozycjaMenu {
protected:
	string nazwa;
	double cena;
	int czasPrzygotowania; // s

public:
	PozycjaMenu(string n, double c, int t);
	virtual ~PozycjaMenu() {};

	virtual void wyswietl() const = 0;

	// GETr
	string getNazwa() const { return nazwa; }
	double getCena() const { return cena; }
	int getCzas() const { return czasPrzygotowania; }

};

// -- KLASY POCHODNE -- //

class DanieGlowne : public PozycjaMenu {
public:
	DanieGlowne(string n, double c, int t);
	virtual void wyswietl() const override;
};

class Napoj : public PozycjaMenu {
private:
	bool zLodem;
public:
	Napoj(string n, double c, int t, bool i = false);
	virtual void wyswietl() const override;
};


// dziêki wykorzystaniu polimorfizmu
// mogê dodaæ inne pozycje w menu,
// np. Deser.
//	W³aœnie dziêki temu, 
//	¿e BistroManager operuje na wskaŸnikach 
//	do klasy abstrakcyjnej PozycjaMenu, 
//	dodanie nowej kategorii, takiej jak Deser, 
//	wymaga³o tylko stworzenia nowej klasy.
//	Nie musia³em przepisywaæ logiki w wystawRachunek 
//	ani panelKuchni – one automatycznie obs³u¿y³y nowy typ dania
class Deser : public PozycjaMenu {
public:
	Deser(string n, double c, int t);
	virtual void wyswietl() const override;
};
