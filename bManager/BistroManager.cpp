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

BistroManager::BistroManager() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			sala[i][j] = false;
		}
	}
}

BistroManager::~BistroManager() {
	for (auto const& item : menu) {
		delete item.second;
	}
}
