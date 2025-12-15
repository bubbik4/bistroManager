#pragma once
#define _CRT_SECURE_NO_WARNINGS // ctime robi³o jakis dziwny blad
// a to go podobno ucisza, dziala prawidlowo nie usuwac
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <stack>
#include <chrono>
#include <thread>
#include <fstream>
#include <iomanip>

#include "Menu.h"
using namespace std;
using namespace std::chrono;

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

	//prywatna metody pomocnicze
	long long silnia(int n);
	void zaladujMenu();

public:
	void pokazSale();
	void dodaZamowienie();
	void panelKuchni();
	void wystawRachunek();

	BistroManager();
	~BistroManager();
};