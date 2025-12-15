#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <stack>

#include "Menu.h"
using namespace std;

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
	queue<Zamowienie> normalneZamowienia;
	priority_queue<Zamowienie> vipZamowienia;

	map<int, Zamowienie> gotoweZamowienia;
	int licznikZamowien;

public:
	void pokazSale();
	void dodaZamowienie();
	//void panelKuchni();
	//void wystawRachunek();

	BistroManager();
	~BistroManager();
};