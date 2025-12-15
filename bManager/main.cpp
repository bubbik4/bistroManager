#include <iostream>
#include "BistroManager.h"

using namespace std;

int main() {
	BistroManager bm;

	int choice;
	
	do {
		cout << "\n--- BISTRO MANAGER ---\n"
		 	 << "1. Pokaz sale,\n"
			 << "2. Dodaj zamowienie,\n"
			 << "3. Przejdz do kuchni,\n"
			 << "4. Wystaw rachunek,\n"
			 << "0. Zakoncz.\n"
			 << "-------------------------\n"
			 << "Wybierz akcje: ";

		// Obs³uga b³êdnego wejœcia (np. litery zamiast cyfry)
		if (!(cin >> choice)) {
			cout << "Blad! Podaj liczbe.\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		switch (choice) {
		case 1:
			bm.pokazSale();
			break;
		case 2:
			bm.dodaZamowienie();
			break;
		case 3:
			bm.panelKuchni();
			break;
		case 4:
			bm.wystawRachunek();
			break;
		case 0:
			cout << "\nKoniec...";
			break;
		default:
			cout << "Nieprawidlowy wybor\n";
		}
	} while (choice!=0);
	return 0;
}