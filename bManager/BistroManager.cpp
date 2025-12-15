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
	licznikZamowien = 1;
}

BistroManager::~BistroManager() {
	for (auto const& item : menu) {
		delete item.second;
	}
}

void BistroManager::pokazSale() {
	cout << "Sala:\n";
	cout << "  1  2  3  4  5\n";
	for (int i = 0; i < 5; i++) {
		cout << i + 1;
		for (int j = 0; j < 5; j++) {
			cout << (sala[i][j] ? "[X]" : "[ ]");
		}
		cout << endl;
	}

}


void BistroManager::dodaZamowienie() {
	int r, k;
	cout << "Podaj numer stolika\nRzad: ";
	cin >> r;
	cout << "\nKolumna: ";
	cin >> k;

	if (sala[r-1][k-1]) {
		cout << "Miejsce jest zajete!\n";
		return;
	} else if (r >= 6 || r < 1 || k >= 6 || k < 1) {
		cout << "Miejsce poza zakresem (1-5).\n";
		return;
	}
	
	Zamowienie nowe;
	nowe.id = licznikZamowien++;
	nowe.numerStolika = r * 10 + k;

	stack<PozycjaMenu*> stosWyboru;

	for (auto const& item : menu) {
		cout << item.first << ". ";
		item.second->wyswietl();
		cout << endl;
	}

	int wybor;
	while (true) {
		cout << "Podaj ID (0 - konczy wybor, -1 cofa): ";
		cin >> wybor;
		if (wybor == 0) break;
		if (wybor == -1) {
			if (!stosWyboru.empty()) {
				cout << "Cofnieto: " << stosWyboru.top()->getNazwa() << endl;
				stosWyboru.pop();
				continue;
			}
		}
		if (menu.find(wybor) != menu.end()) {
			stosWyboru.push(menu[wybor]);
			cout << "Dodano " << menu[wybor]->getNazwa() << endl;
		}
		else cout << "Nieprawidlowe ID.\n";
	}

	while (!stosWyboru.empty()) {
		nowe.listaPozycji.push_back(stosWyboru.top());
		stosWyboru.pop();
	}

	if (nowe.listaPozycji.empty()) {
		cout << "Puste zamowienie; anulowane.\n";
		return;
	}

	char vip;
	cout << "Czy jest to zamowienie VIP? [t/n]";
	cin >> vip;
	nowe.isVip = (vip == 't' || vip == 'T');

	// zajmujemy stolik
	sala[r - 1][k - 1] = true;

	if (nowe.isVip) {
		vipZamowienia.push(nowe);
		cout << "Zamowienie " << nowe.id << " przyjete (kolejka VIP)";
	}
	else {
		normalneZamowienia.push(nowe);
		cout << "Zamowienie " << nowe.id << " przyjete.";
	}
}

//void BistroManager::panelKuchni() {
//	if (!vipZamowienia.empty()) {
//		Zamowienie doRealizacji = vipZamowienia.top();
//		vipZamowienia.pop();
//	}
//	
//	if (!normalneZamowienia.empty()) {
//		Zamowienie doRealizacji = normalneZamowienia.top();
//		normalneZamowienia.pop();
//	}
//}