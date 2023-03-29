#pragma once
#include <string>
using namespace std;
class Produkt {
    public:
        Produkt(const string& nazwa, double cena, int ilosc) :
            nazwa_(nazwa), cena_(cena), ilosc_(ilosc) {}

        virtual ~Produkt() {}

        virtual string info() const;

        string nazwa() const { return nazwa_; }
        double cena() const { return cena_; }
        int ilosc() const { return ilosc_; }

    protected:
        string nazwa_;
        double cena_;
        int ilosc_;
};

