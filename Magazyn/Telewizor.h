#pragma once
#include "Produkt.h"
using namespace std;
class Telewizor : public Produkt {
    public:
        Telewizor(const string& nazwa, double cena, int ilosc, double przekatna) :
            Produkt(nazwa, cena, ilosc), przekatna_(przekatna) {}

        string info() const override {
            return "Telewizor " + nazwa() + ", przekatna: " + to_string(przekatna_) + " cali " + ", cena: " + to_string(cena()) + " zl, ilosc: " + to_string(ilosc());
        }

    private:
        double przekatna_;
        string rozdzielczosc_;
};