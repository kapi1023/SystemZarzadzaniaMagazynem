#pragma once
#include "Produkt.h"
using namespace std;
class But : public Produkt {
    public:
        But(const string& nazwa, double cena, int ilosc, int rozmiar) :
            Produkt(nazwa, cena, ilosc), rozmiar_(rozmiar) {}

        string info() const override {
            return "Buty " + nazwa() + ", rozmiar: " + to_string(rozmiar_) + ", cena: " + to_string(cena()) + " zl, ilosc: " + to_string(ilosc());
        }

    private:
        int rozmiar_;
};
