#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <map>

#include "Menu.h"

struct Zamowienie {
	int id;
	int numerStolika;
	bool isVip;
	vector<PozycjaMenu*> listaPozycji;

	Zamowienie();
	bool operator<(const Zamowienie &other) const;
	
};

class BistroManager {
	map<int, PozycjaMenu*> menu;
	bool sala[5][5];
	queue<Zamowienie> normalneZamowienie;
	priority_queue<Zamowienie> vipZamowienie;

	map<int, Zamowienie> gotoweZamowienia;
	
public:
	void pokazSale();
	void dodaZamowienie();
	void panelKuchni();
	void wystawRachunek();

	BistroManager();
	~BistroManager();
};