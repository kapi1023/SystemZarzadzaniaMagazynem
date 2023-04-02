#include "Magazyn.h"
#include "Produkt.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <mutex>
#include <thread>
#include <iomanip>

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
void Magazyn::zapisz_do_pliku_csv(const string& nazwa_pliku) {
    ofstream plik(nazwa_pliku + ".csv");
    if (!plik.is_open()) {
        cerr << "B³¹d: nie mo¿na otworzyæ pliku " << nazwa_pliku << endl;
        return;
    }

    plik << "Nazwa,Cena,Iloœæ\n";
    mutex mtx;
    vector<thread> watki;

    for (const auto& produkt : produkty_) {
        watki.emplace_back([&plik, &mtx, produkt]() {
            lock_guard<mutex> lock(mtx);
            plik << produkt->nazwa() << "," << fixed << setprecision(2) << produkt->cena() << ","
                << produkt->ilosc() << "\n";
            });
    }

    for (auto& watek : watki) {
        watek.join();
    }

    plik.close();
    cout << "Zapisano dane do pliku " << nazwa_pliku << endl;
}
