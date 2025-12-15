#include "BistroManager.h"

Zamowienie::Zamowienie() {
	id = 0;
	numerStolika = 0;
	isVip = false;
}

bool Zamowienie::operator<(const Zamowienie& other) const {
	// Zwraca true je¿eli 'this' jest mniej wa¿ne ni¿ 'other;
	return isVip < other.isVip;
}