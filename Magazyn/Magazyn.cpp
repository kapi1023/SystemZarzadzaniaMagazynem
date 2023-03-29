#include "Magazyn.h"
#include "Produkt.h"
#include <algorithm>
#include <iostream>

using namespace std;

void Magazyn::dodaj_produkt(Produkt* produkt) {
    produkty_.push_back(produkt);
}

void Magazyn::usun_produkt(const string& nazwa) {
    for (auto it = produkty_.begin(); it != produkty_.end(); ++it) {
        if ((*it)->nazwa() == nazwa) {
            delete* it;
            produkty_.erase(it);
            cout << "Produkt usuniety\n";
            return;
        }
    }
    cout << "Nie znaleziono produktu o podanej nazwie\n";
}

Produkt* Magazyn::wyszukaj_produkt(const string& nazwa) {
    for (auto it = produkty_.begin(); it != produkty_.end(); ++it) {
        if ((*it)->nazwa() == nazwa) {
            return *it;
        }
    }
    return nullptr;
}

void Magazyn::wyswietl_produkty(){
    for (const auto& produkt : produkty_) {
        cout << produkt->info() << endl;
    }
}
