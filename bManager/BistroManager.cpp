#include "BistroManager.h"

Zamowienie::Zamowienie() { //ctor
	id = 0;
	numerStolika = 0;
	isVip = false;
}

bool Zamowienie::operator<(const Zamowienie& other) const {
	// Zwraca true je¿eli 'this' jest mniej wa¿ne ni¿ 'other;
	return isVip < other.isVip;
}

BistroManager::BistroManager() { //ctor
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			sala[i][j] = false;
		}
	}
	licznikZamowien = 1;
}

BistroManager::~BistroManager() { //dtor
	for (auto const& item : menu) {
		delete item.second;
	}
}

void BistroManager::pokazSale() {
	cout << "Sala:\n";
	cout << "  1  2  3  4  5\n";
	for (int i = 0; i < 5; i++) { // iteracja po ca³ej tablicy
		cout << i + 1;
		for (int j = 0; j < 5; j++) {
			cout << (sala[i][j] ? "[X]" : "[ ]");
		}
		cout << endl;
	}

}


void BistroManager::dodaZamowienie() { 
	int r, k; // rz¹d, kolumna
	cout << "Podaj numer stolika\nRzad: ";
	cin >> r;
	cout << "\nKolumna: ";
	cin >> k;

	if (sala[r-1][k-1]) { // r-1 i k-1, dlatego, ¿e user podaje zakres 1-5, 
						  // a tablica ma zakres 0-4
		cout << "Miejsce jest zajete!\n";
		return;
	} else if (r >= 6 || r < 1 || k >= 6 || k < 1) {
		cout << "Miejsce poza zakresem (1-5).\n";
		return;
	}
	
	Zamowienie nowe; 
	nowe.id = licznikZamowien++;	// to gwarantuje unikalne ID dla ka¿dego zamówienia

	nowe.numerStolika = r * 10 + k; // estetycznie wygladaj¹cy numer stolika:
									// dla r = 3, k = 2, numerStolika == 32

	stack<PozycjaMenu*> stosWyboru; // stack, aby daæ mo¿liwoœæ cofania wyboru

	for (auto const& item : menu) { 
		cout << item.first << ". ";
		item.second->wyswietl(); // dziêki polimorfizmowi, mo¿na wyœwietliæ ca³e menu
		cout << endl;
	}

	int wybor;  //usr in
	while (true) {
		cout << "Podaj ID (0 - konczy wybor, -1 cofa): ";
		cin >> wybor;
		if (wybor == 0) break;
		if (wybor == -1) {
			if (!stosWyboru.empty()) { // walidacja - nie mo¿na usun¹æ 'niczego;
				cout << "Cofnieto: " << stosWyboru.top()->getNazwa() << endl;
				stosWyboru.pop();
				continue;
			}
		}
		if (menu.find(wybor) != menu.end()) { // sprawdzenie czy adres w ogole istnieje
			stosWyboru.push(menu[wybor]);
			cout << "Dodano " << menu[wybor]->getNazwa() << endl;
		} else cout << "Nieprawidlowe ID.\n";
	}

	// Przerzucanie ze stacka do klasy
	while (!stosWyboru.empty()) { // je¿eli cokolwiek jest w stacku
		nowe.listaPozycji.push_back(stosWyboru.top());  // przypisz iloœæ pozycji do zamowienia
		stosWyboru.pop(); // usun je ze stacka
	}

	if (nowe.listaPozycji.empty()) {
		cout << "Puste zamowienie; anulowane.\n"; // a jak jest puste to nic nie rob
		return;
	}

	char vip;
	cout << "Czy jest to zamowienie VIP? [t/n]";
	cin >> vip;
	nowe.isVip = (vip == 't' || vip == 'T'); // zwraca true jezeli wpiszesz t albo T

	// zajmij stolik
	sala[r - 1][k - 1] = true;

	if (nowe.isVip) {  // dodaje do priority_queue
		vipZamowienia.push(nowe);
		cout << "Zamowienie " << nowe.id << " przyjete (kolejka VIP)"; 
	}
	else { // dodaje do zwyk³ego queue
		normalneZamowienia.push(nowe);
		cout << "Zamowienie " << nowe.id << " przyjete.";
	}
}

void BistroManager::panelKuchni() {
	Zamowienie doRealizacji; // nowy obiekt klasy Zamowienie
	if (!vipZamowienia.empty()) { // sprawdza czy periority_queue jest puste
		doRealizacji = vipZamowienia.top();
		vipZamowienia.pop();
	}
	else if (!normalneZamowienia.empty()) { // i sprawdza czy normalne jest puste
		doRealizacji = normalneZamowienia.front();
		normalneZamowienia.pop();
	}
	else {cout << "Brak zamowien dla kuchni.\n"; return;}
	
	int calkowityCzas = 0;
	for (auto* pos : doRealizacji.listaPozycji) {
		cout << pos->getNazwa() << " (" << pos->getCzas() << "s)\n";
		calkowityCzas += pos->getCzas();
	}

	cout << "Przygotowywanie... Laczny czas: " << calkowityCzas << "s.\n";
	std::this_thread::sleep_for(std::chrono::seconds(calkowityCzas)); // symulacja czasu
		
	gotoweZamowienia[doRealizacji.numerStolika] = doRealizacji;
	cout << "Zamowienie dla stolika " << doRealizacji.numerStolika << " jest gotowe!";

}