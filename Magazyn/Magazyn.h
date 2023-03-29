#pragma once
#include <vector>
#include <mutex>
#include "Produkt.h"
using namespace std;
class Magazyn {
    public:
        void dodaj_produkt(Produkt* produkt);
        void usun_produkt(const string& nazwa);
        Produkt* wyszukaj_produkt(const string& nazwa);
        void wyswietl_produkty();
        void aktualizuj_stan();

    private:
        vector<Produkt*> produkty_;
        mutex mutex_;
};