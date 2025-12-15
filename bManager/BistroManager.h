#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include "Menu.h"

struct Zamowienie {
	int id;
	int numerStolika;
	bool isVip;
	vector<PozycjaMenu> listaPozycji;

	Zamowienie();
	bool operator<(const Zamowienie &other) const;
	
};